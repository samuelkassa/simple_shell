#include "shell.h"

/**
 * _strlen - This function returns the length of a string
 * @s: The string whose length to check
 *
 * Return: integer length of string
 */

int _strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

/**
 * _strcmp - This function performs lexicogarphic comparision of two strings
 * @s1: The first string
 * @s2: the second string
 *
 * Return: Negative if s1 < s2
 * Positive if s1 > s2
 * zero is s1 == s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - This function checkes if needle starts with haystack
 * @haystack: The string to be searched
 * @needle: This is the small string to be searched with-in haystack string.
 *
 * Return: The address of next char of haystck or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - This function concatenates two strings
 * @dest: The destination buffer
 * @src: the source buffer
 *
 * Return: Pointer to the destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (temp);
}
