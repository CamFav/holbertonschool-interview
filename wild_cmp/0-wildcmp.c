#include "holberton.h"

/**
 * wildcmp - Compares two strings
 * @s1: The first string to be compared.
 * @s2: The second string, which may contain wildcard '*'
 * that can replace any string (including an empty string).
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
    /* If both strings reach their end, return 1 because identical */
    if (*s1 == '\0' && *s2 == '\0')
    {
        return (1);
    }

    if (*s2 == '*')
    {
        return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
    }

    /* If characters match, continue comparing */
    if (*s1 == *s2)
    {
        return (wildcmp(s1 + 1, s2 + 1));
    }
    /* Otherwise, return 0 because the strings aren't identical */
    return (0);
}
