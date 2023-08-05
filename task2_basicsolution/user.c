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
  for (int i = 0; i < numBooks; i++){

    if (bookList[i].available == 1){
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

// TODO:
// 1. check if the user has reached their borrow limit
// 2. ask user to enter the book ID to be borrowed
// 3. check if bookID is valid/book is available
// 4. if none of the above happens - record book into users boroowed books / set availiability of books to -
 
void borrowBook(User *theUser, Book *bookList, int numBooks, int maxBorrowed)
{

  // TO DO :
  // request the choice of book
  // borrow the book, update the data structures
  int toBorrow = optionChoice();
  

  // add 0 < borrow < numBooks
  if (toBorrow < numBooks)
  {
    if (theUser->numBorrowed >= 0 && theUser->numBorrowed < maxBorrowed){
      // numBorrowed should start from 0
      // put the book details into the users borrowed books
      theUser->borrowed[theUser->numBorrowed] = &bookList[toBorrow];
      
      // update the availability of book
      bookList[toBorrow].available = 0;
      
      theUser->numBorrowed++;

      printf("You successfully borrowed the book!\n");
    }

    else{
      printf("You have exceeded the max borrowing limit (%d)\n", maxBorrowed);
    }
  }

  else{
    printf("Invalid number, try again \n");
  }
  
    

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
  for (int i = 0; i < maxBorrowed; i++)
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
  printf("blep\n");
  // TO DO :
  // request the choice of book
  // return the book and update data structures
  
  // check that there are borrowed books
  if (theUser->numBorrowed == 0){
    printf("You have no borrowed books \n");
  }

  else {
    // requesting choice of books 
    int toReturn = optionChoice();

    if (toReturn >= 0 && toReturn < theUser->numBorrowed){
      //updating data structures
      //theUser->borrowed[back] = '\0';
      printf("blep\n");
      
      for (int i = toReturn; i < (theUser->numBorrowed) - 1; i++)
      {
        *(theUser->borrowed[i]) = *(theUser->borrowed[i + 1]); 
      }
      
      // *(theUser->borrowed[0]) = *(theUser->borrowed[1]); 
      // *(theUser->borrowed[1]) = *(theUser->borrowed[2]); 
      // *(theUser->borrowed[2]) = *(theUser->borrowed[3]); 

      bookList[toReturn].available = 1;
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
