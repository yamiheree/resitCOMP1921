
/**
 * @brief Holds all the data about each book.
 * 
 * title - the name of the book
 * author - the name of the author
 * available - 1 for available, 0 for not available
 * 
 */
typedef struct _book {

  char title[40];
  char author[40];
  int available;

} Book;

/**
 * @brief Holds the data about the library user. The number of books that they have borrowed,
 * and the Book objects which they have borrowed.
 * 
 */
typedef struct _user {

  Book *borrowed[4];
  int numBorrowed;

} User;

/**
 * @brief The library object, which holds the bookList of all the books in the library as
 * well as the current number of books and the maximum number of books.
 * 
 * Also holds the current user and the maximum number of books they are able to borrow.
 * 
 */
typedef struct _library {

  Book *bookList;
  int numBooks;
  int maxBooks;

  User theUser;
  int maxBorrowed;

} Library;

