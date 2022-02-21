void clearKeyboardBuffer()
{
  // clear keyboard buffer on UNIX
  fseek(stdin, 0, SEEK_END);
  // clear keyboard buffer on Windows
  fflush(stdin);
}
void getString(char *str, int length)
{
  clearKeyboardBuffer();
  // input string
  fgets(str, length, stdin);
  str[strlen(str) - 1] = '\0';
  clearKeyboardBuffer();
}
int menu(const char *title, int menuItemCount, char *menuItem[])
{
  int i = 0, choice;
  printf("==============================\n");
  printf(" %s\n", title);
  printf("==============================\n");
  for (; i < menuItemCount; i++)
  {
    printf(" %d. %s \n", i + 1, menuItem[i]);
  }
  printf("==============================\n");
  do
  {
    printf("Your choice: ");
    clearKeyboardBuffer();
    scanf("%d", &choice);
  } while (choice <= 0 || choice > menuItemCount);
  return choice;
}
void waitEnterPress(char* msg){
    printf("%s\n", msg);
    clearKeyboardBuffer();
    getchar();
}