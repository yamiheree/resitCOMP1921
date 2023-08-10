/**
 * @file library.c
 * @author YOUR NAME
 * @brief Contains functions which set up and run the main library interface.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "libraryStructures.h"
#include "library.h"
#include "user.h"
#include "librarian.h"
#include "utility.h"

#define BUFFERSIZE 40

/**
 * @brief Function to initialise the Library object, reading in the books from file
 * and setting up the User object.
 *
 * @param bookFile The filename of where the books file will be found
 * @param theLibrary The library object which encapsulate the bookList and users.
 */
void initLibrary(char *bookFile, Library *theLibrary) //initialize theUser as well

{
  theLibrary->maxBooks = 100;
  theLibrary->maxBorrowed = 4;
  theLibrary->bookList = malloc(theLibrary->maxBooks*sizeof(Book));

  FILE* books = fopen(bookFile, "r");

  theLibrary->numBooks = readBooks(books,theLibrary->bookList);

  fclose(books);
  theLibrary->theUser.numBorrowed = 0;

  return;

}

/**
 * @brief reads in the books from the provided file to a given bookList.
 * Books are stored in file in a set format:
 * Book author
 * Book title
 * blank line
 * And returns the number of books read.
 *
 * @param books The file pointer where the data will be read from.
 * @param bookList The bookList where the books will be stored.
 * @return int The number of books read from the file.
 */

int readBooks(FILE *books, Book *bookList)
{
  // TO DO:
  char buffer[BUFFERSIZE];
  int c;
  int bookID = 0;
  int bookOrAuthor = 0; // even - author name, odd - title name

  // read from the book file pointer
  while ((c = fgetc(books)) != EOF)
  {
    // allocating memory to the Book struct
    int count = 0;

    while (1)
    { // when it is not at the end of file - read book name/author name

      buffer[count] = (char)c;

      if (c == '\0' || c == '\n')
      {
        // abandon string and continue to the next line if the string reads \n or \0
        if (buffer[0] == '\0' || buffer[0] == '\n')
        {
          break;
        }

        // store bookname or author
        buffer[count] = '\0';

        if (bookOrAuthor % 2 == 0)
        {
          strcpy(bookList[bookID].author, buffer);
          bookList[bookID].available = 1;

          bookOrAuthor++;
          break;
          // break;
        }

        else
        {
          strcpy(bookList[bookID].title, buffer);

          bookID++;
          bookOrAuthor++;
          break;
        }
      }

      c = fgetc(books);
      if (c == EOF)
      {
        break;
      }

      count++;
    }
    
  }
  
  return bookID;
}

/**
 * @brief Free any allocated data before exit.
 * 
 * @param theLibrary The library object where any allocated memory will be found.
 */
// TODO: free the bookList object inside theLibrary
void exitLibrary(Library *theLibrary)
{
  // free the bookList object inside theLibrary
  free(theLibrary->bookList);

  return;
}

// DO NOT ALTER THIS FUNCTION 
/**
 * @brief Sets up and runs the library interface - you should not edit any of this code.
 *
 * @param bookFile The filename of the book
 */
void libraryCLI(char *bookFile)
{
  int libraryOpen = 1;
  int option;

  // create the library structure
  Library *theLibrary = (Library *)malloc(sizeof(Library));

  initLibrary(bookFile, theLibrary);

  while (libraryOpen)
  {
    printf("\n Main menu options\n 1 User login\n 2 Librarian login\n 3 Exit system\n Choice:");
    option = optionChoice();

    if (option == 1)
    {
      printf("\nUser login\n");
      userCLI(theLibrary);
    }
    else if (option == 2)
    {
      printf("\nLibrarian login\n");
      librarianCLI(theLibrary);
    }
    else if (option == 3)
    {
      libraryOpen = 0;
      printf("\nClosing\n");
    }
    else
      printf("\nUnknown option\n");
  }

  exitLibrary(theLibrary);

  // free the library structure
  free(theLibrary);

  return;
}