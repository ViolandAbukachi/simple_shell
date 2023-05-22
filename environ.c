#include "shell.h"

/**
 * _myenv - Prints the current environ
 * @info: Structure that contains the potential arguments. Used to maintain a constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Gets the value of an environment variable
 * @info: Structure containing the potential arguments.
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *i;

	while (node)
	{
		i = starts_with(node->str, name);
		if (p && *i)
			return (i);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environ variable,or modify an existing one
 * @info: Structure containing the potential arguments. Used to maintain a constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Removes an environ variable
 * @info: Structure that contains the potential arguments. Used to maintain a constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int p;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates the env linked list
 * @info: Structure containing the potential arguments. Used to maintain a constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
