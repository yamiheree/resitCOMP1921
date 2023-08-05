/**
 * @file librarian.c
 * @author YOUR NAME
 * @brief A collection of functions which provide the librarian with an interface and some basic functionality
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "libraryStructures.h"
#include "librarian.h"
#include "utility.h"

/**
 * @brief Lists the borrowed (not available) books in a given bookList.
 *
 * @param bookList The booklist to display
 * @param numBooks The number of books in booklist
 */
void listBorrowedBooks(Book *bookList, int numBooks)
{

    // TO DO :
    // list the books in format "name - title"
    printf("you are inside listborrowedbooks");
    for (int i = 0; i < numBooks; i++){
        if (bookList[i].available == 0){
            printf("%s - %s\n", bookList[i].author, bookList[i].title);

        }
    }
    return;
}

/**
 * @brief Lists all the books in a given bookList
 *
 * @param bookList The booklist to display
 * @param numBooks The number of books in booklist
 */
void listBooks(Book *bookList, int numBooks)
{
    printf("you are inside listbooks \n");
    printf("%d", numBooks);

    // TO DO :
    // list the books in format "name - title"
    for (int i = 0; i < numBooks; i++){
        printf("%s - %s \n", bookList[i].author, bookList[i].title);
    }

    return;
}

// DO NOT ALTER THIS CODE
/**
 * @brief The command line interface for the librarian. This code should not be altered.
 *
 * @param theLibrary The library object which the librarian is managing.
 */
void librarianCLI(Library *theLibrary)
{
    int librarianLoggedIn = 1;
    int option;

    while (librarianLoggedIn)
    {
        printf("\n Librarian options\n 1 List books\n 2 List borrowed books\n 3 Log out\n Choice:");
        option = optionChoice();

        if (option == 1)
        {
            printf("\nList of books:\n");
            listBooks(theLibrary->bookList, theLibrary->numBooks);
        }
        else if (option == 2)
        {
            printf("\nList of borrowed books:\n");
            listBorrowedBooks(theLibrary->bookList, theLibrary->numBooks);
        }
        else if (option == 3)
        {
            librarianLoggedIn = 0;
            printf("\nLogging out\n");
        }
        else
            printf("\nUnknown option\n");
    }
    return;
}
