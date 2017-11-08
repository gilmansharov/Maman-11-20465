#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define CS_IS_BIGGER    1
#define CT_IS_BIGGER    -1
#define CS_EQUAL_TO_CT  0
#define MAX_LENGTH  128


/*

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

int my_strchr(const char* cs, char c)
{
    int i, length;
    length = strlen(cs);
    for (i = 0; i < length; i++)
        if (cs[i] == c)
            return i;
    return -1;
}

int main()
{
    int funcNumber;
    printf("Hello, Please type a number from 1 to 3, in order to call one of the functions:\n");
    printf("my_strcmp: type 1\nmy_strncmp: type 2\nmy_strchr: type 3\n");
    scanf("%d", &funcNumber);
    switch(funcNumber)
    {
        case 1:
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
        case 2:
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
        case 3:
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