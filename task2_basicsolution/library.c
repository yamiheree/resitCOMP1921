/**
 * @file library.c
 * @author YOUR NAME
 * @brief Contains functions which set up and run the main library interface.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryStructures.h"
#include "library.h"
#include "user.h"
#include "librarian.h"
#include "utility.h"

/**
 * @brief Function to initialise the Library object, reading in the books from file
 * and setting up the User object.
 *
 * @param bookFile The filename of where the books file will be found
 * @param theLibrary The library object which encapsulate the bookList and users.
 */
void initLibrary(char *bookFile, Library *theLibrary)
{

  theLibrary->maxBooks = 100;
  theLibrary->maxBorrowed = 4;

  // TO DO :

  // dynamically allocate the bookList array for storing books

  // open the book file

  // use the readBooks function to read in the file and add the book records into the bookList array

  // remember to close the file

  // Initialise the User data

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

  // read from the book file pointer

  // assign values to a Book structure in the bookList array for each complete record

  // read data until the file ends

  return 0;
}

/**
 * @brief Free any allocated data before exit.
 *
 * @param theLibrary The library object where any allocated memory will be found.
 */
void exitLibrary(Library *theLibrary)
{

  // TO DO:

  // free the allocated lists

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
