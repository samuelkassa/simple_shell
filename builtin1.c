#include "shell.h"

/**
 * _myhistory - This function Do the following three things:
 * first it displays the history list,
 * and the list is in one command by line fashion
 * each command is preceded with line numbers that start from 0
 *
 * @info: A sturcture containing possible arguments. This is used to
 * maintain constant function prtotype.
 *
 * Return: Always 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history); /* print_list - prints all elements of a list_t linked list */
	return (0);
}

/**
 * unset_alias - This function sets alias to the string
 * @info: Parameter string
 * @str: The string alias
 * Aliasing refers to the situation where the same memory location
 * can be accessed using different names.
 *
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *p, character;
	int value;

	p = _strchr(str, '='); /* _strchr - locates a character in a string */
	if (!p)
		return (1);
	character = *p;
	*p = 0;
	value = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	/* delete_node_at_index - deletes node at given index */
	/* node_starts_with - returns node whose string starts with prefix */
	*p = character;
	return (value);
}

/**
 * set_alias - Sets alias to the string
 * @info: Parameter struct
 * @str: The string alias
 *
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info,str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
	/* add_node_end - adds a node to the end of the list */
}

/**
 * print_alias - This function prints alias string
 * @node: The alias node
 *
 * Return: Always 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '='); /* _strchr - locates a character in a string */
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin you can check by typing man alias
 * @info: A structure containing a possible arguments and this used for
 * maintaining constant function prototype.
 *
 * Return: Always 0
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}
