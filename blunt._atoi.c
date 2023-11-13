#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct address
 * @info:the struct address
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**

 * is_delim - checks if character is a delimiter
 * @c: the char to check
 * @delim: the delimiter string
 * is_delim - checks if the character is a delimeter
 * @c: the character to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
    while (*delim)
        if (*delim++ == c)
            return (1);
    return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
    int loop_counter, sign = 1, flag = 0, converted_value;
    unsigned int result = 0;

    for (loop_counter = 0; s[loop_counter] != '\0' && flag != 2; loop_counter++)
    {
        if (s[loop_counter] == '-')
            sign *= -1;

        if (s[loop_counter] >= '0' && s[loop_counter] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[loop_counter] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    converted_value = (sign == -1) ? -result : result;

    return converted_value;
}
