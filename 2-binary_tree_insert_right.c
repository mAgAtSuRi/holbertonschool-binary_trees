#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a node as right child
 * @parent: pointer to the parent node
 * @value: value to insert
 *
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		node->right = parent->right;
		parent->right->parent = node;
		parent->right = node;

	}
	else
		parent->right = node;

	return (node);
}
