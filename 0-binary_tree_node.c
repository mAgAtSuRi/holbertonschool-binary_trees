#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to th parent node
 * @value: value to put in the new node
 *
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->right = NULL;

	if (parent == NULL)
		node->parent = NULL;
	else
		node->parent = parent;

	return (node);
}
