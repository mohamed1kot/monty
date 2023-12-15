#include "monty.h"

/**
 * _strcmp - Compare two strings lexicographically.
 *
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: 0 if the strings are equal,
 * a negative value if str1 < str2,
 * or a positive value if str1 > str2.
*/

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

