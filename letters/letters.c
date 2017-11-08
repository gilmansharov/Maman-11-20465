#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;
    enum status {SENTENCE_BEGIN, BETWEEN_QUETATION_MARKS, INSIDE_SENTENCE};
    int STATE = SENTENCE_BEGIN;
    while ((c = getchar()) != EOF)
    {
        if (c < '0' || c > '9')
        {
            switch(STATE)
            {
                case SENTENCE_BEGIN:
                    {
                        if (!isspace(c))
                        {
                            
                            if (islower(c))
                            {
                                c = toupper(c);
                            }
                            putchar(c);
                            
                            if (c == '.')
                            {
                                putchar('\n');
                                putchar('\n');
                            }
                            else if (c == '\"')
                                STATE = BETWEEN_QUETATION_MARKS;
                            else
                                STATE = INSIDE_SENTENCE;
                        }
                    }
                    break;
                case BETWEEN_QUETATION_MARKS:
                    {
                        if (islower(c))
                            c = toupper(c);
                        putchar(c);
                        if (c == '\"')
                            STATE = INSIDE_SENTENCE;
                    }
                    break;
                case INSIDE_SENTENCE:
                    {
                        
                        if (isupper(c))
                            c = tolower(c);
                        putchar(c);
                        if (c == '\"')
                            STATE = BETWEEN_QUETATION_MARKS;
                        
                        if (c == '.')
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