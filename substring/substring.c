#include "substring.h"

/**
 * find_substring - finds all the starting indices of substrings that are
 *                  a concatenation of all the given words exactly once,
 *                  in any order.
 * @s: the input string to scan.
 * @words: the array of words to concatenate.
 * @nb_words: the number of words in the array.
 * @n: pointer to store the number of found indices.
 *
 * Return: an allocated array of indices, or NULL if no solution is found.
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
    int word_len, substring_len, s_len;
    int *indices = NULL;
    int *found_indices;
    int i, j, k, match;

    if (!s || !words || nb_words == 0 || !n)
        return (NULL);

    word_len = strlen(words[0]);
    if (word_len == 0)
        return (NULL);

    s_len = strlen(s);
    substring_len = word_len * nb_words;

    if (substring_len > s_len)
        return (NULL);

    indices = malloc(s_len * sizeof(int));
    if (!indices)
        return (NULL);

    *n = 0;

    for (i = 0; i <= s_len - substring_len; i++)
    {
        found_indices = calloc(nb_words, sizeof(int));
        if (!found_indices)
        {
            free(indices);
            return (NULL);
        }

        match = 1;
        for (j = 0; j < nb_words; j++)
        {
            int word_found = 0;

            for (k = 0; k < nb_words; k++)
            {
                if (!found_indices[k] &&
                    strncmp(s + i + j * word_len, words[k], word_len) == 0)
                {
                    found_indices[k] = 1;
                    word_found = 1;
                    break;
                }
            }

            if (!word_found)
            {
                match = 0;
                break;
            }
        }

        free(found_indices);

        if (match)
        {
            indices[*n] = i;
            (*n)++;
        }
    }

    if (*n == 0)
    {
        free(indices);
        return (NULL);
    }

    return (indices);
}
