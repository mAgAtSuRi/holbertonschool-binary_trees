#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert node as left child
 * @parent: pointer to the parent node
 * @value: value to put in created left node
 *
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp;

	if (parent == NULL)
		return (NULL);
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);
	
	if (parent->left != NULL)
	{
		temp = parent->left;
		parent->left = node;
		node->left = temp;
		temp->parent = node;
	}

	return (node);
}
