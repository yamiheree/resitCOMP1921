# Test Plan

You should add your own test cases in here, explaining what you are testing, what data your are going to use, and what you would expect the working system to do. The only things which should cause the program to end are issues with the start-up process (i.e. argument errors, input file errors). In other cases, you should be providing an error message and giving users another chance - your program **should not crash or exit** unless a user selects the 'exit' option.

main() has been started to show you the level of granularity you should be using, but isn't a full list of possible errors- you should add to this, thinking about all potential user or system errors which could happen.

Make sure you run these tests regularly and mark off whether they are passing - it is recommended that you copy this file and date these attempts so you have evidence of doing these regularly.

## main() Tests

| Test Case      | Data To Use | Expected Outcome | Passing? |
| ----------- | ----------- | ----------- | ------------ |
| Valid books file  | ./bin/library books.txt  | Program proceeds with no issues | [x] |
| Books file does not exist  |  ./bin/library fake.txt  |  Program should exit and alert user | [x] |
| Books file has no read permissions | chmod -r books.txt <br> ./bin/library books.txt <br> chmod +r books.txt | Program should exit and alert user | [ ] |
| No books file provided | ./bin/library  | Program should give usage message and exit | [x] |

*There are lots more tests you could include here - try and think of more!*

## Librarian

 | Test Case | Data To Use | Expected Outcome | Passing? |
 | -- | -- | -- | -- |
 | List out the booklist | ./bin/library books.txt | Prints out booklist in a specified format and also the number of books in the list | [x] |
 | Print out available books | listBorrowedBooks | print out all the books where bookList[i].available == 0 | [x] |

## Library

 | Test Case | Data To Use | Expected Outcome | Passing? |
 | -- | -- | -- | -- |
 | turn booklist into an array | initLibrary() | Reads through all the data from books.txt and put into bookList with respective details such as title, author and bookID | [x] |
 | Empty booklist | initLibrary() | Program exits and alert user | [x] |
 | book name might be too long | initLibrary() | memory would be dynamically allocated | [x] |

## User

 | Test Case | Data To Use | Expected Outcome | Passing? |
 | -- | -- | -- | -- |
 | User exceeded borrow limit and still attempts to borrow | theUser -> numBorrowed | Inform user that they can't borrow any more books and returns | [x] |
 | User borrowing a book that is unavailable | bookList[i].available | Tell user that book is unavailable and returns to the previous page | [x] |
 | User wants to leave the current option | press enter | Returns to the previous menu | [x] |
 | User returns one of the books from his bookList | theUser -> borrowed[] | theUser->borrowed[] updates and moves the books in the list forward by one | [x] |
 | User wants to see the available books | booklist[i].available == 1 | Prints out the books available with their respective bookID | [x] |

## Anything Else

*If you have more than two or three tests in here related to one part of your system, consider adding another heading for that part.*

 | Test Case | Data To Use | Expected Outcome | Passing? |
 | -- | -- | -- | -- |
 |  |  |  | [ ] |
