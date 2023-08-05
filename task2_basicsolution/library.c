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

#define BUFFERSIZE 1024

/**
 * @brief Function to initialise the Library object, reading in the books from file
 * and setting up the User object.
 *
 * @param bookFile The filename of where the books file will be found
 * @param theLibrary The library object which encapsulate the bookList and users.
 */
void initLibrary(char *bookFile, Library *theLibrary) //initialize theUser as well
{
  printf("initLibrary \n");

  theLibrary->maxBooks = 100;
  theLibrary->maxBorrowed = 4;
  theLibrary->theUser.numBorrowed = 0;

  // TO DO :

  // dynamically allocate the bookList array for storing books
  theLibrary->bookList = (Book *)malloc(sizeof(Book) * theLibrary->maxBorrowed);
  printf("book malloc \n");

  // open the book file
  FILE *inputFile = fopen(bookFile, "r");

  if (inputFile == NULL)
  {
    printf("Error opening file. \n");
    exit(1);
  }

  // printf("%s \n", bookFile);

  // use the readBooks function to read in the file and add the book records into the bookList array
  theLibrary->numBooks = readBooks(inputFile, theLibrary->bookList);
  printf("readbooks done\n");

  // remember to close the file
  //fclose(inputFile);
  printf("file is actually not closed lmao L\n");

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
// TODO: 
// 1. debug the code (Hint: add one "break" statement somewhere is enough(;)
// 2. prevent buffer overflow (Hint: make use of realloc())
// 3. returns the number of books read
int readBooks(FILE *books, Book *bookList)
{
  printf("readBooks\n");
  // TO DO:
  char *buffer = (char *)malloc(sizeof(char) * BUFFERSIZE);
  int c;
  int bookID = 0;
  int bookOrAuthor = 0; // even - author name, odd - title name
  printf("variable done\n");

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
          memcpy(bookList[bookID].author, buffer, strlen(buffer)+1);
          // strcpy(bookList[bookID].author, buffer);
          bookList[bookID].available = 1;
          printf("%s \n", bookList[bookID].author);
          // printf("%d \n", bookOrAuthor);
          bookOrAuthor++;
          break;
          // break;
        }

        else
        {
          memcpy(bookList[bookID].title, buffer, strlen(buffer)+1);
          // strcpy(bookList[bookID].title, buffer);
          printf("%s \n", bookList[bookID].title);
          // printf("%d \n", bookOrAuthor);
          bookID++;
          printf("%d\n", bookID);
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
    // if (c == EOF)
    //   {
    //     break;
    //   }
  }
  // assign values to a Book structure in the bookList array for each complete record

  // read data until the file ends

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

  // TO DO:

  // free the allocated lists
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
  printf("you are in libraryCLI \n");

  // create the library structure
  Library *theLibrary = (Library *)malloc(sizeof(Library));

  initLibrary(bookFile, theLibrary);
  printf("you are after initLibrary \n");

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
