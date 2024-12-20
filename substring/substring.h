/* substring.h */
#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <string.h>

/**
 * find_substring - finds all the starting indices of substrings that are
 * a concatenation of all the given words exactly once, in any order.
 * @s: the input string to scan.
 * @words: the array of words to concatenate.
 * @nb_words: the number of words in the array.
 * @n: pointer to store the number of found indices.
 *
 * Return: an allocated array of indices, or NULL if no solution is found.
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n);

#endif /* SUBSTRING_H */