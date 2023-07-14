# Tips and Tricks

In this section, you will find some useful bits of information which might help you out. There is no additional information about the task, just some suggestions which may help you with it.

- [Tips and Tricks](#tips-and-tricks)
  - [Test Scripts](#test-scripts)
  - [Style \& Comments](#style--comments)
    - [Comments](#comments)
    - [Code Style](#code-style)
      - [Brackets](#brackets)
      - [Spacing](#spacing)
    - [Naming](#naming)
  - [Git Basics](#git-basics)
    - [Staging](#staging)
    - [Commiting](#commiting)
    - [Pushing](#pushing)
    - [Branching](#branching)

## Test Scripts

Testing the code takes quite a lot of time, and therefore, making an automated test script to run it would be a good idea. While this isn't neccessarily worth marks, it's a useful skill and will serve as evidence of testing in your project.

Because the code uses the stdin, you will find that making short text files and piping them into the program is much quicker and easier than typing them out every time:

```bash
./bin/library books.txt < data/test1.txt
```

This runs library with books.txt as the argument, and pipes in whatever is in the 'test1.txt' file to the stdin:

**data/test1.txt example:**

```bash
1
3
5
```

Every input should be on its own line, as in the example above.

You can then make a bash script which runs all of the tests - you can find a plethora of information about writing bash scripts online, but a simple example would be:

```bash
#!/bin/bash

make all

echo "Testing bad input"
./library fake.txt

echo "Testing new loan and view loans"
./library books.txt < data/test1.txt
```

You may also find it useful to pipe your output *out* to a file, as this prevents it from filling your screen:

```bash
#!/bin/bash

echo "Testing new loan and view loans"
./library books.txt < data/test1.txt > out.txt

# at the end you can:
rm out.txt
```

You can pipe in and pipe out in the same line, and you can pipe multiple things to the same file - they just overwrite each other.

## Style & Comments

You get some marks for style and comments, so here is a little guidance about how to get top marks on those aspects.

### Comments

Some of the commenting has already been done for you- there are file-level and function-level doxygen comments. This is a structured comment which can be used to generate documentation automatically, and these are very popular and common in code. You should keep these doxygen comments, and add some comments to explain your code as you write it.

**You do not need to comment every line of code**.

```c
// ask the user for the book ID
printf("What ID are you searching for?");
// get the user input
scanf("%d", &id);
// go through all the books in the book list
for(int i=0;i<numBooks;i++>){
    // if the book ID is equal to the ID the user entered
    if(books[i].id==id){
        // then print out the name of the book
        printf("Book title: %s\n", books[i].title);
    }
}
```

That code has been **excessively** commented- while comments are useful at times, they aren't necessary for very basic things such as printing, scanf, or even a for loop. If your variable names are clear, then generally someone reading your code can follow the logic without difficulty. Instead, reserve comments for places with more complex logic, and have just a brief top-level comment on sections where the logic is not complicated.

Comments are generally useful for things such as:
    - complicated logic which is hard to follow, such as a complex algorithm or maths
    - using non-standard functions which a user might not know (such as most string functions)
    - doxygen comments on functions
    - any code which someone familiar with the language you are using might not understand.

Treat comments as a sort of sub-heading in your code- they're useful to keep track of what's happening, but you definitely don't need one for every line. You should assume that the person looking at your code understands basic programming constructs.

### Code Style

There is no 'right' way to style your code- the important thing is that it is consistent. I would recommend using an autoformatter since this enforces consistency and is standard in industry- I personally use the standard C formatter which VSCode provides since it's easy to get and follows the usual C standard.

#### Brackets

Brackets are down to personal preference, but the autoformatter will give you my preferred format:

```c
while(1)
{
    // I like brackets on their own lines
    // indented to the same level as their parent
}
```

It's also best to avoid non-bracketed if/for/while statements:

```c
if(youWantFullMarks)
    dontDoThis();
```

Use brackets - they make it clearer what you're trying to do and make it easier to find mistakes.

Alternative acceptable bracket styles include:

```c
while(1) {
    // this is fine if you're consistent!
    // I usually do this when I'm coding
    // then auto-format it
}

while(1)
    {
    // Hamish's preferred style
    }
```

#### Spacing

What an autoformatter *won't* do is add 'decorative' newlines. Newlines should be used to split up logical blocks in order to make your code easier to read- again, there isn't a right way of doing this but generally one blank line between blocks of logic which are doing different things is good.

Think of your code like paragraphs of text - if I removed all the paragraphs and subheadings in this document, it would be very hard to follow. Your code is the same.

Newlines are 'paragraphs', and comments are 'headings'.

### Naming

Variable and function names should be internally consistent- stick to snake_case or camelCase.

Single character variables are only acceptable when you're creating, using and discarding them within a loop:

```c
for(int i=0 ; i<10 ; i++)
{
    printf("%d\n", i);
}
```

Most programmers use i/j/k as standard, but this is up to you!

Your variable names don't need to be very long, but try and ensure that their meaning is clear to someone else:

```c
Book* availableBooks;
// is much easier to understand than
Book* aBooks;
```

## Git Basics

Your use of Git is assessed, so I will re-cover the basics here. You will find many Git courses online which walk you through the more complicated parts. This will all be command line Git, but you can also use the GUI version which is built in to Codespaces and VSCode.

Git allows you to keep track of files, saving them to the server regularly and enabling you to recover previous versions if you make a mistake or need to backtrack. It also means you can work across multiple machines without worrying about emailing yourself the files or losing work.

The basic process of using git is:

- Stage your changes
- Commit your changes
- Push your changes

And you can also use **branching** to create multiple versions of your code.

### Staging

To stage your changes, you use `git add`:

```git
git add .
git add -A
git add individual_file_name.c
```

You can add all by using the options `add .` or `add -A`, or you can add individual files if you only want to push one thing up.

### Commiting

You should commit your changes regularly - a commit is essentially a checkpoint which you can return to, and it saves the state of everything which has been staged.

```git
git commit -m "write something informative"
git commit -a -m "these messages are visible to your lecturer"
```

You always add a message to your commit- if you forget, a text editor will pop up and you can't close it until you write a message! These messages are visible to you, and you should make them reasonably informative as you might need them to get back to a previous working version.

You can stage all and commit by using the `-a` option as shown in the 2nd line above- this runs `git add .` in the same line as the commit.

You can do many commits before you push your changes up to the server- these serve as points you can return to, and you should aim to commit your work roughly every **hour**. Think of it as saving your work - you should do it regularly!

### Pushing

But you do need to push from time to time - this saves your work on the remote, which is on GitHub's servers where it stays nice and safe and can't be accidentally deleted or overwritten!

```git
git push origin branch_name
git push
```

Pushing will upload all your commits to GitHub, meaning you can get your current code (and any previous commited version) on any device. You can usually push with just `git push` but you can also specify where to push it to- often this will be `git push origin main`, but if you are working on another branch, you should use that branch's name.

### Branching

Branches allow you to create multiple, separate versions of your code. This is useful if you want to try something which might break your code, or if you move on to Task 3 and need a new copy of your code to develop on.

```git
git checkout -b Task3
// or
git branch Task3
git checkout Task3
```

This creates a branch called 'Task3', and moves you onto it with the current version of your code. You can then work on your code on this branch, which will not affect the version stored on your previous branch (usually this will be called 'main'). You can see all available branches using `git branch` and you can move to any other branch using `git checkout branchname`.
