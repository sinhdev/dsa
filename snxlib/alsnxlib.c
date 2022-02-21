typedef struct
{
  void *data;
  unsigned int count;
  unsigned int maxElements;
  unsigned int sizeOfElement;
} ArrayList;

ArrayList *alInit(unsigned sizeOfElement, unsigned int maxElements)
{
  if(sizeOfElement <=0){
    return NULL;
  }
  ArrayList *al;
  al = (ArrayList *)malloc(sizeof(ArrayList));
  if (maxElements <= 0)
  {
    al->maxElements = 16;
  }
  else
  {
    al->maxElements = maxElements;
  }
  al->sizeOfElement = sizeOfElement;
  al->count = 0;
  al->data = malloc(sizeOfElement * al->maxElements);
  return al;
}

int alInsert(ArrayList *al, void *newElement)
{
  if (al->count == al->maxElements)
  {
    al->maxElements = al->maxElements + al->maxElements / 2;
    al->data = realloc(al->data, sizeof(al->sizeOfElement) * al->maxElements);
  }
  // al->data[al->count] = *newElement;
  memcpy(al->data + al->count * al->sizeOfElement, newElement, al->sizeOfElement);
  al->count++;
  return 1;
}

int alInsertAt(ArrayList *al, void *newElement, unsigned position)
{
  if (position < 0 || position > al->count)
  {
    return 0;
  }
  if (al->count == al->maxElements)
  {
    al->maxElements = al->maxElements + al->maxElements / 2;
    al->data = realloc(al->data, sizeof(al->sizeOfElement) * al->maxElements);
  }
  for (int i = al->count; i > position; i--)
  {
    // al->data[i] = al->data[i-1];
    memcpy(al->data + i * al->sizeOfElement, al->data + (i - 1) * al->sizeOfElement, al->sizeOfElement);
  }
  // al->data[position] = *newElement;
  memcpy(al->data + position * al->sizeOfElement, newElement, al->sizeOfElement);
  al->count++;
  return 1;
}

void *alGetAt(ArrayList *al, unsigned position)
{
  if (position >= al->count)
  {
    return NULL;
  }
  return al->data + position * al->sizeOfElement;
}
int alRemoveAt(ArrayList *al, unsigned position)
{
  int count = al->count;
  if (position < 0 || position >= count)
  {
    return 0;
  }
  for (int i = position; i < count - 1; i++)
  {
    memcpy(al->data + i * al->sizeOfElement, al->data + (i + 1) * al->sizeOfElement, al->sizeOfElement);
  }
  al->count--;
  return 1;
}
int alIsEmpty(ArrayList *al)
{
  return al->count == 0;
}
void alShowInfo(ArrayList *al)
{
  printf("ArrayList->count = %d\n", al->count);
  printf("ArrayList->maxElements = %d\n", al->maxElements);
  printf("ArrayList->sizeOfElement = %d\n", al->sizeOfElement);
}
void alDestroy(ArrayList *al)
{
  free(al->data);
  free(al);
}
int alSaveToFile(ArrayList *al, const char* path){
  if(al == NULL || al->data == NULL || al->count==0){
    return 0;
  }
  FILE *f;
  f = fopen(path, "wb");
  if(f==NULL){
    return 0;
  }
  fwrite(&(al->count), sizeof(unsigned int), 1, f);
  fwrite(&(al->maxElements), sizeof(unsigned int), 1, f);
  fwrite(&(al->sizeOfElement), sizeof(unsigned int), 1, f);
  fwrite(al->data, al->sizeOfElement, al->count, f);
  fclose(f);
  return 1;
}
ArrayList* alLoadFromFile(const char* path){
  FILE *f;
  f = fopen(path, "rb");
  if(f==NULL){
    return NULL;
  }
  ArrayList *al;
  al = (ArrayList *)malloc(sizeof(ArrayList));
  fread(&(al->count), sizeof(unsigned int), 1, f);
  fread(&(al->maxElements), sizeof(unsigned int), 1, f);
  fread(&(al->sizeOfElement), sizeof(unsigned int), 1, f);
  al->data = malloc(al->sizeOfElement * al->maxElements);
  fread(al->data, al->sizeOfElement, al->count, f);
  fclose(f);
  return al;
}