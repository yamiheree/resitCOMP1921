/**
 * @file user.c
 * @author your name
 * @brief User.c provides a number of utilities for the user of the library, such as being
 * able to view all the books, and being able to borrow or return books.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "libraryStructures.h"
#include "user.h"
#include "utility.h"

/**
 * @brief Lists all books in the bookList which are available to borrow.
 *
 * @param bookList The library bookList.
 * @param numBooks The number of books in bookList
 */
void listAvailableBooks(Book *bookList, int numBooks)
{

  // TO DO :

  // print out available books with format "list number - author - title" on each line

  return;
}

/**
 * @brief Allows the user to borrow a book from the library
 *
 * @param theUser The current user object
 * @param bookList The library book list
 * @param numBooks The number of books in bookList
 * @param maxBorrowed The maximum number of books a user can borrow.
 */
void borrowBook(User *theUser, Book *bookList, int numBooks, int maxBorrowed)
{

  // TO DO :
  // request the choice of book
  // borrow the book, update the data structures

  return;
}

/**
 * @brief Lists all the books which the user has borrowed.
 *
 * @param theUser The current user
 * @param bookList The book list
 * @param maxBorrowed The maximum number of books which a user can borrow
 */
void listMyBooks(User *theUser, Book *bookList, int maxBorrowed)
{

  // TO DO :

  // list books in format "number - author - title"

  return;
}

/**
 * @brief Return a book to the library, making it available for others to borrow.
 *
 * @param theUser The current user
 * @param bookList The list of all books
 * @param numBooks The number of books in bookList
 * @param maxBorrowed The maximum number of books which a user can borrow.
 */
void returnBook(User *theUser, Book *bookList, int numBooks, int maxBorrowed)
{

  // TO DO :
  // check that there are borrowed books
  // request the choice of book
  // return the book and update data structures

  return;
}

// DO NOT ALTER THIS FUNCTION
/**
 * @brief This controls the basic UI for the user section of the library. You should not edit it.
 *
 * @param theLibrary The library object.
 */
void userCLI(Library *theLibrary)
{
  int userLoggedIn = 1;
  int option;

  while (userLoggedIn)
  {
    printf("\n User options\n 1 List available books\n 2 Borrow book\n 3 Return book\n 4 Log out\n Choice:");
    option = optionChoice();

    if (option == 1)
    {
      printf("\nList available books:\n");
      listAvailableBooks(theLibrary->bookList, theLibrary->numBooks);
    }
    else if (option == 2)
    {
      printf("\nBorrow book from library:\n");
      listAvailableBooks(theLibrary->bookList, theLibrary->numBooks);
      borrowBook(&(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed);
    }
    else if (option == 3)
    {
      printf("\nReturn book from my list:\n");
      listMyBooks(&(theLibrary->theUser), theLibrary->bookList, theLibrary->maxBorrowed);
      returnBook(&(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed);
    }
    else if (option == 4)
    {
      userLoggedIn = 0;
      printf("\nLogging out\n");
    }
    else
      printf("\nUnknown option\n");
  }
  return;
}
