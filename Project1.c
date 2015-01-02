/*
 * Programmer: Max Downs
 * Red ID: 814291745
 * Class: CS 320 - Programming Languages
 * Instructor: Dr. John Caroll
 * Date: 09/26/2013
 * Assignment: Programming Project 1
 * Description: The purpose of this program is to ask the user to input a series of characters.
 *              The program will then determine whether or not the character is a part of the
 *              ASCII character set.  If it is not, the program will disregard the character.
 *              Approved characters will be printed out in a line until there are 72 characters
 *              on a line, at which point the characters will be printed on the next line.
 */

#include <stdio.h>
#include <ctype.h>

/* define MAXCOLUMN as 72 to remove magic number from code */
#define MAXCOLUMN 72

int main()
{
    /* create files for input and output */
    FILE *fin = fopen("input1", "rb");
    FILE *fout = fopen("output1", "w");

    /* increment variable to determine newlines*/
    int column = 0;

    /* variable to determine if changes were made */
    int change = 1;

    /* input variable to be tested for printing or deletion */
    int iochar;
    
    /* Documentation: Outline for while loop comes from www.stackoverflow.com/questions/3264915/remove-non-ascii-characters-in-a-file */
    /* while the input has not reached the end of file */
    while ((iochar = fgetc(fin)) != EOF)
    {
        /* determine if the input character is a printable*/
        if (isprint(iochar))
        {
            /* if so, write it to stdout, and increment column */
            fputc(iochar, fout);
            column++;
        }

        /* if the  character is not printable */
        else if ((iochar < 32) || (iochar != 10))
        {
            /* print the equivalent control-key, set change to 0, and increment column */
            fputc('^'+(iochar+64), fout);
            change = 0;
            column++;
        }

        /* output for newline character */
        else if (iochar = 10)
        {
            fputc('$/n', fout);
            change = 0;
        }

        /* output for DEL */
        else if (iochar = 177)
        {
            fputc('^?', fout);
            change = 0;
            column++;
        }

        /* if more than 72 characters are on one line move to the next line and reset column */
        if(column > MAXCOLUMN)
        {
            fputc('/n', fout);
            column = 0;
        }
    }

    fclose(fin);
    fclose(fout);

	return change;
}
