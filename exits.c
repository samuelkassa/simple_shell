#include "shell.h"

/**
 * _strncpy - This function copies a string from souce to destination
 * @dest: The destination string to be copied to
 * @src: The source string
 * @n: The amount of characterss to be copied
 *
 * Return: the concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - This function concatenates two strings
 * @dest: The first string
 * @src: The second string
 * @n: The amount of bytes to be maximally used
 *
 * Return: The concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - This function locates a character in a sring
 * @s: The string t be parsed
 * @c: The character to look for
 *
 * Return: A pointr to the memory area of c in s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

