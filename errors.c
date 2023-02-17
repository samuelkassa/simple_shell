#include "shell.h"

/**
 * _eputs - This function prints an input string
 * @str: The string to be printed
 *
 * Return: Nothing
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Writes the character c to the stderr
 * @c: The character to be printed.
 *
 * Return: on Success 1
 * On error -1 is returnd, and errno is set appropriately
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - This function writes the given character c to given fd
 * @c: The character to be printed
 * @fd: the fd or file descriptor in which the character is going to be printed
 *
 * Return: On success 1
 * On error -1 is returned, and errno is set appropriately
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - This function prints the string to fd
 * @str: The string to be printed
 * @fd: The file descriptor in which c is goint to be writen
 *
 * Return: The number of chars put
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
