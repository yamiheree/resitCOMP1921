[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/Z6I1a0h6)
# Library Project

- [Library Project](#library-project)
  - [Task 1 - Planning your Tests - 20%](#task-1---planning-your-tests---20)
  - [Task 2 - Basic Library System - 60%](#task-2---basic-library-system---60)
  - [Task 3 - Extension - Login and Users - 20%](#task-3---extension---login-and-users---20)
  - [Creating Your Submission](#creating-your-submission)


Inside this repo, you have a collection of files which form a library project. Every file has been commented, with doxygen style comments on all functions and structs to clarify what they should do. You will see that at the moment, this code doesn't do very much.

You should `cd task1_testplan`, where you can compile the code using the command `make`.

And you can then run the library using `./bin/library bin/books.txt`.

To clean up and remove the executables, you can run `make clean`.

## Task 1 - Planning your Tests - 20%

Your first step should be to open and familiarise yourself with the code - read through each file and make sure you understand the flow of the program.

As you read through, consider what **errors** might occur - where are you taking in inputs from the user (command line, files, or stdin), and what issues could there be with any of these? You might want to make some notes as you look through - a simple markdown document like this might be useful, or use a notepad and pen.

Once you have read through the code and spent some time thinking about how you could make the code defensive, you will write a **test plan** which explains how you will go about testing your program. This will help you to write better, more defensive code- which is why you should do this **first** and use test-driven development!

You will see that 'testplan.md' already exists - this has one section started for you, so you can use it to see how detailed you should be. You should write down what causes the error, give an example of the input you will use to cause the error, and explain what the program **should** do when that error happens. Hint: it should not crash!

You should run your tests manually (or using a script - see 'tipsntricks.md' for help) at least every time you finish a full file (i.e. once you have finished implementing main.c, run through all the tests. Once you have finished library.c, you should do all the tests in main() and library). The best way to evidence this is simple to create a copy of the test file and mark them off as passing or failing in there:

```bash
cp testplan.md tests_11thAugust.md
```

This creates a copy of the testplan, and you can then mark tests using the checkboxes.

- [x] for passing
- [ ] for failing

Note that Codespace doesn't render checkboxes very well in tables, so these might just show as `[x]` and `[]` - this is fine!

As you develop your code, you may add new tests - that is normal and you don't need to go back and add those tests to any previous dated copied of the tests, and this shows you're developing your test suite! Just make sure that your 'final' testplan is the one which you submit on Gradescope.

You will be marked based on:
    - The number and range of test cases you have thought of
    - How well evidenced your testing is

## Task 2 - Basic Library System - 60%

Now you will actually write the code to run the library. You should write your code into the functions provided, following the 'to do' instructions. These 'to do' instructions are deliberately brief and don't give you all the errors you should be checking for- this is because you should be thinking about this yourself! You should be alerting users when they are successful and when they are not successful, with *helpful* error/success messages, and your program should only exit if there is an issue on startup (ie. an issue with arguments or the books file), or if a user selects the exit option.

I recommend starting with the functions which are run first- you will find that different parts of the code rely on each other, and therefore there is an order to how you will develop your code. You can look at main() and trace the program through to work out which bits to program first.

You should regularly compile and run your code - **do not write all the code and then try to compile it!**. You should compile your code regularly, as it is much easier to work through one or two compilation errors in a single file than work through 20-30 errors across 5 different .c files!

You will be marked on:
    - Functionality (your code does what it is supposed to do)
    - General quality (structure and comments)
    - Defensiveness (your code doesn't crash)
    - Your use of Git (regular commits, branching)

## Task 3 - Extension - Login and Users - 20%

This section is much harder than Task 2, and is an **extension** provided for people with uncapped resits who want to push for high marks - it is not required to attempt this section to pass.

**You must keep your Task 2 and Task 3 code separate - use branching or the folder structure to keep your code separate.**

You will have noticed that the library system has a few flaws- there is only a single user, and there is no way of saving which books have been borrowed.

You should implement:
    - A functional login system which allows users to sign up for accounts and sign in to access the library
    - A logout system so that multiple users can sign in and sign out of the system before it is closed
    - A method of saving these account details between the program closing and reopening
    - A system which saves which users have borrowed which books which is saved between the program closing and reopening.

You have full freedom in how you want to develop this- you can lay out your files and code however you want. However, you should keep the same functionality as exists in Task 2.

If you create any new .c and .h files, you should ensure you add them in to the makefile so that your code compiles - and ensure you submit this makefile with your code.

This section will be marked on:
    - functionality
    - defensiveness

## Creating Your Submission

You should submit a single .zip file containing the three subfolders which hold the different parts of the submission.

This is very simple:

```bash
zip submission.zip */*
```

Which will create 'submission.zip' which you can download and submit to Gradescope.

You should double-check that this contains all the files you expect, and that 