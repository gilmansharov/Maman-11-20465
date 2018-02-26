/*
Author: Gil Mansharov

File Name: letters.c
*/

#include <stdio.h>
#include <ctype.h>


int main()
{
    int c;
    enum status {
        SENTENCE_BEGIN, /*Indicates on the beginning of a sentence*/
        BETWEEN_QUOTATION_MARKS, /*Indicates that the input is inside quotation marks*/
        INSIDE_SENTENCE /*Indicates on a middle of a sentence*/
    };
    int STATE = SENTENCE_BEGIN;
    while ((c = getchar()) != EOF)
    {
        if (!isdigit(c)) /*digits should not be written to the standard output*/
        {
            switch(STATE) /*each state has a specific conditions to output*/
            {
                case SENTENCE_BEGIN:
                    {
                        if (!isspace(c)) /*whitespaces should not be written to the
                        standard output in the sentence beginning*/
                        {
                            if (islower(c)) /*a Sentence should begin with a capital letter*/
                            {
                                c = toupper(c);
                            }
                            putchar(c);
                            
                            if (c == '.') /*Indicates on the end of the sentence*/
                            {
                                putchar('\n');
                                putchar('\n');
                            }
                            else if (c == '\"') /*Check if a quotation has began*/
                                STATE = BETWEEN_QUOTATION_MARKS;
                            else 
                                STATE = INSIDE_SENTENCE;
                        }
                    }
                    break;
                case BETWEEN_QUOTATION_MARKS:
                    {
                        if (islower(c)) /*quotation should be outputted as capital letters*/
                            c = toupper(c);
                        putchar(c);
                        if (c == '\"') /*Indicates on the end of the quotation*/
                            STATE = INSIDE_SENTENCE;
                    }
                    break;
                case INSIDE_SENTENCE:
                    {
                        /*Capital letters should not be outputted
                        as capital if not in the beginning of the sentence or inside quotation marks*/
                        if (isupper(c)) 
                            c = tolower(c);
                        
                        putchar(c);

                        if (c == '\"')
                            STATE = BETWEEN_QUOTATION_MARKS;
                        
                        if (c == '.') /*Indicates on the end of the sentence*/
                        {
                            STATE = SENTENCE_BEGIN;
                            putchar('\n');
                            putchar('\n');
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
