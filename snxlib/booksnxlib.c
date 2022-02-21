typedef struct
{
  char isbn[15];
  char title[51];
  char author[51];
  float price;
} Book;
Book getBook()
{
  Book book;
  printf("Input Book isbn: ");
  getString(book.isbn, 14);
  printf("Input Book title: ");
  getString(book.title, 50);
  printf("Input Book author: ");
  getString(book.author, 50);
  printf("Input Book price: ");
  scanf("%f", &book.price);
  return book;
}
void printBook(Book book)
{
  printf("| %-14s | %-26s | %-20s | %6.2f |\n",
         book.isbn, book.title, book.author, book.price);
}
void printLine()
{
  printf("+-%-14s-+-%-26s-+-%-20s-+-%-6s-+\n", "--------------",
         "--------------------------", "--------------------", "------");
}
void printTitle()
{
  printLine();
  printf("| %-14s | %-26s | %-20s | %-6s |\n", "ISBN", "Title",
         "Author", "Price");
  printLine();
}