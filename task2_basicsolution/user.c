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
  // print out available books with format "list number - author - title" on each line
  for (int i = 0; i < numBooks; i++)
  {
    if (bookList[i].available == 1)
    {
      printf("%d - %s - %s \n", i, bookList[i].author, bookList[i].title);
    }
  }

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
  // request the choice of book
  int toBorrow = optionChoice();

  if (toBorrow == '\0'){
    printf("Returning to previous page \n");
    return;
  }

  if (toBorrow >= numBooks || toBorrow < 0){
    printf("BookID invalid! \n");
    return;
  }

  if (bookList[toBorrow].available == 0){
    printf("Book is unavailable \n");
    return;
  }

  if (theUser->numBorrowed < 0 || theUser->numBorrowed == maxBorrowed){
    printf("You have exceeded the borrowing limit \n");
    return;
  }
  
  // put the book details into the users borrowed books if passed the above parameters
  theUser->borrowed[theUser->numBorrowed] = &(bookList[toBorrow]);

  // updating the data structures
  bookList[toBorrow].available = 0;
  (theUser->numBorrowed)++;
        
  printf("You have successfully borrowed the book!\n");
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
  // list books in format "number - author - title"
  for (int i = 0; i < theUser->numBorrowed; i++)
  {
    printf("%d - %s - %s \n", i, theUser->borrowed[i]->author, theUser->borrowed[i]->title);
  }

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

// TODO:
// 1. If the user has no borrowed books, print out such remind and return
// 2. otherwise ask user to enter the bookID to be returned
// 3. check if the bookID entered is valid
// 4. if yes, set availability of the book to 1, and update the user's borrowed
void returnBook(User *theUser, Book *bookList, int numBooks, int maxBorrowed)
{
  // check that there are borrowed books in theUser
  if (theUser->numBorrowed == 0)
  {
    printf("You have no borrowed books \n");
  }

  else
  {
    // requesting choice of books
    int toReturn = optionChoice();

    if (toReturn == '\0'){
      printf("Returning to previous page \n");
      return;
    }

    if (toReturn >= 0 && toReturn < theUser->numBorrowed)
    {
      // updating book availability
      theUser->borrowed[toReturn]->available = 1;

      // updating data structures of theUser's bookList
      for (int i = toReturn; i < ((theUser->numBorrowed)) - 1; i++)
      {
        theUser->borrowed[i] = theUser->borrowed[i + 1];
      }

      (theUser->numBorrowed)--;

      // find the address of the book to return and using it to change the availability
      printf("Book returned. \n");
    }

    else
    {
      printf("Invalid number, try again. \n");
    }
  }
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
