#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_valid_number - Checks if a string is a valid number.
 * @num: The string to check.
 * Return: 1 if valid, 0 otherwise.
 */
int is_valid_number(char *num)
{
    if (*num == '\0')
        return (0);
    while (*num)
    {
        if (*num < '0' || *num > '9')
            return (0);
        num++;
    }
    return (1);
}

/**
 * reverse_string - Reverses a string in place.
 * @str: The string to reverse.
 * @len: The length of the string.
 */
void reverse_string(char *str, int len)
{
    int i = 0, j = len - 1;
    char tmp;

    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

/**
 * multiply - Multiplies two numbers as strings and prints the result.
 * @num1: The first number.
 * @num2: The second number.
 */
void multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j, carry, product;
    int *result;
    char *str;

    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;
    reverse_string(num1, len1);
    reverse_string(num2, len2);

    result = calloc(len1 + len2, sizeof(int));
    if (!result)
        exit(98);

    for (i = 0; i < len1; i++)
    {
        carry = 0;
        for (j = 0; j < len2; j++)
        {
            product = (num1[i] - '0') * (num2[j] - '0') + result[i + j] + carry;
            carry = product / 10;
            result[i + j] = product % 10;
        }
        if (carry > 0)
            result[i + j] += carry;
    }

    i = len1 + len2 - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    if (i == -1)
    {
        _putchar('0');
        _putchar('\n');
        free(result);
        return;
    }

    str = malloc(i + 2);
    if (!str)
    {
        free(result);
        exit(98);
    }

    for (j = 0; i >= 0; i--, j++)
        str[j] = result[i] + '0';
    str[j] = '\0';

    for (i = 0; str[i]; i++)
        _putchar(str[i]);
    _putchar('\n');

    free(result);
    free(str);
}

/**
 * main - Entry point.
 * @argc: The number of arguments.
 * @argv: The arguments array.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char **argv)
{
    if (argc != 3 || !is_valid_number(argv[1]) || !is_valid_number(argv[2]))
    {
        _putchar('E');
        _putchar('r');
        _putchar('r');
        _putchar('o');
        _putchar('r');
        _putchar('\n');
        exit(98);
    }

    multiply(argv[1], argv[2]);

    return (0);
}
