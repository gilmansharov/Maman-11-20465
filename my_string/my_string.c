/*
Author: Gil Mansharov

File Name: my_string.c
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define CS_IS_BIGGER    1
#define CS_EQUAL_TO_CT  0
#define CT_IS_BIGGER    -1
#define CHAR_IS_NOT_EXIST   -1
#define MAX_LENGTH  128


/*
This function takes 2 strings as input, and returns:
-1 if cs is before ct in lexicographical order
0 if cs and ct are equal
1 if cs is after ct in lexicographical order
*/
int my_strcmp(const char* cs, const char* ct)
{
    int min_length, i, cs_length, ct_length;
    cs_length = strlen(cs);
    ct_length = strlen(ct);
    min_length = (cs_length < ct_length) ? cs_length : ct_length;
    for (i = 0; i < min_length; i++)
    {
        if (cs[i] < ct[i])
            return CT_IS_BIGGER;
        else if (cs[i] > ct[i])
            return CS_IS_BIGGER;
    }
    if (cs_length == ct_length)
        return CS_EQUAL_TO_CT;
    else
        return (cs_length < ct_length) ? CT_IS_BIGGER : CS_IS_BIGGER;

}

/*
This function takes 2 strings and an integer as input, and returns:
-1 if cs is before ct in lexicographical order in the first n characters
0 if cs and ct are equal the first n characters
1 if cs is after ct in lexicographical order the first n characters
*/
int my_strncmp(const char* cs, const char* ct, int n)
{
    int min_length, i, cs_length, ct_length, length;
    cs_length = strlen(cs);
    ct_length = strlen(ct);
    min_length = (cs_length < ct_length) ? cs_length : ct_length;
    length = (min_length <= n) ? min_length : n;

    for (i = 0; i < length; i++)
    {
        if (cs[i] < ct[i])
            return CT_IS_BIGGER;
        else if (cs[i] > ct[i])
            return CS_IS_BIGGER;
    }
    if (n > min_length)
        if (cs_length != ct_length)
            return (cs_length > ct_length) ? CS_IS_BIGGER : CT_IS_BIGGER;
    return CS_EQUAL_TO_CT;
}

/*
This function takes a string and a character as input, and returns the index
of the first occurrence of c in cs.
if cs does not contain c, the function returns -1
*/
int my_strchr(const char* cs, char c)
{
    int i, length;
    length = strlen(cs);
    for (i = 0; i < length; i++)
        if (cs[i] == c)
            return i;
    return CHAR_IS_NOT_EXIST;
}


/*
main function to call for one function with a number from 1-3.
1 for my_strcmp
2 for my_strncmp
3 for my_strchr

and then typing the parameters you want to call the function with.

The main function prints to the standard output the function name that called,
the parameters, and the result that the function has returned
*/
int main()
{
    enum functions {
        STR_CMP = 1,
        STR_N_CMP = 2,
        STR_CHR = 3
    };

    int funcNumber;
    printf("Please type a number from 1 to 3, in order to call one of the functions:\n");
    printf("my_strcmp: type 1\nmy_strncmp: type 2\nmy_strchr: type 3\n");
    scanf("%d", &funcNumber);
    switch(funcNumber)
    {
        case STR_CMP:
            {
                int result;
                char cs[MAX_LENGTH], ct[MAX_LENGTH];
                printf("Please type the parameters you want to use with strcmp:\n");
                scanf("%s %s", cs, ct);
                result = my_strcmp(cs, ct);
                printf("Function called: my_strcmp\n");
                printf("Parameters are: %s, %s\n", cs, ct);
                printf("The function returned: %d\n", result);
            }
            break;
        case STR_N_CMP:
            {
                int n, result;
                char cs[MAX_LENGTH], ct[MAX_LENGTH];
                printf("Please type the parameters you want to use with strncmp:\n");
                scanf("%s %s %d", cs, ct, &n);
                result = my_strncmp(cs, ct, n);
                printf("Function called: my_strncmp\n");
                printf("Parameters are: %s, %s, %d\n", cs, ct, n);
                printf("The function returned: %d\n", result);
            }
            break;
        case STR_CHR:
            {
                char c, cs[MAX_LENGTH];
                int result;
                printf("Please type the parameters you want to use with strchr:\n");
                scanf("%s %c", cs, &c);
                result = my_strchr(cs, c);
                printf("Function called: my_strchr\n");
                printf("Parameters are: %s, %c\n", cs, c);
                printf("The function returned: %d\n", result);
            }
            break;

        default:
            printf("Error: You need to choose a number from 1-3 in order to call a function\n");
            break;
    }
    return 0;
}
