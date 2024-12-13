#include "regex.h"

/**
 * regex_match - Checks if a string matches a given regular expression pattern.
 * @str: The string to scan.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern)
{
    int first_match;

    /* If the pattern is empty */
    if (*pattern == '\0')
    {
        /* If the string is also empty: return true, otherwise false */
        return (*str == '\0');
    }

    /* Check if the first character matches */
    /* If str is not empty and str matches pattern or if pattern matches
       any single character. */
    first_match = (*str && (*str == *pattern || *pattern == '.'));

    /* If the second character in the pattern is '*' */
    if (*(pattern + 1) == '*')
    {
        /* Ignore the first and second character ('*') and
           use '*' to match one or more occurrences of the preceding character. */
        return (regex_match(str, pattern + 2)) ||
               (first_match && regex_match(str + 1, pattern));
    }
    else
    {
        /* If the second character in the pattern is not '*' */
        return first_match && regex_match(str + 1, pattern + 1);
    }
}
