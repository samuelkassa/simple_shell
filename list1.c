#include "shell.h"

/**
 * list_len - This function determines the length of linked list
 * @h: A pointer to the first node.
 *
 * Return: size of list.
 */

size_t list_len(const list_t *h)
{
	size_t len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}
	return (len);
}

/**
 * list_to_strings - This function returns an array of strings of the list->str
 * @head: A pointer to the first node
 *
 * Return: An array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t len = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !len)
		return (NULL);
	strs = malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);
	for (len = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < len; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[len] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - This function prints all elements of a list_t linked list
 * @h: A pointr to head or first node of the list
 *
 * Return: size of list
 */

size_t print_list(const list_t *h)
{
	size_t length = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		length++;
	}
	return (length)
}

/**
 * node_starts_with - This function returns node whose string starts
 * with prefix
 * @node: A pointer to list head
 * @prefix: A string to match
 * @c: The next character after prefix to match
 *
 * Return: The matching node or NULL
 */

list_t *node_starts_with(list_t *node, char *prefix, char)
{
	char *indicator = NULL;

	while (node)
	{
		indicator = starts_with(node->str, prefix);
		if (indicator && ((c == -1) || (*indicator == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - This function gets the index of a node.
 * @head: A pointer to the first node of the list
 * @node: A pointer to the node
 *
 * Return: index of node or -1
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head)
	{
		if (head == node)
			return (index);
		head = head->next;
		index++;
	}
	return (-1);
}

