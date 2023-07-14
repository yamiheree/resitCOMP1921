/**
 * @file utility.c
 * @brief This contains some utilities which you may find useful in
 * your implementation - you shouldn't need to edit these, but you can add
 * more functions if you want to.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utility.h"

// DON'T ALTER THESE FUNCTIONS UNLESS YOU KNOW WHAT YOU ARE DOING

/**
 * @brief Reads a user's input from the stdin and converts it to a number.
 * This will sanitize newlines, text, any anything else which can cause issues.
 *
 * @return int The number entered by the user, or 0 for invalid options.
 */
int optionChoice(void)
{
    int option = -1;
    char line[80];

    // read in the current line as a string
    fgets(line, 80, stdin);

    // atoi() converts string to integer, returns 0 if could not convert
    option = (int)atoi(line);

    return option;
}

/**
 * @brief Strips the trailing newline from fgets() inputs.
 *
 * @param string The string to have the newline removed from.
 */
void removeNewLine(char *string)
{

    // gets the length of string
    size_t length = strlen(string);

    // if the string is valid and the last char is a newline, replace it with
    // a null terminator.
    if ((length > 0) && (string[length - 1] == '\n'))
    {
        string[length - 1] = '\0';
    }
    return;
}
