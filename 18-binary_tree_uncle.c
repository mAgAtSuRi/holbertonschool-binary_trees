#include "binary_trees.h"

/**
 * binary_tree_sibling - finds sibling of a node
 * @node: node to check
 *
 * Return: pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
		sibling = node->parent->right;
	else
		sibling = node->parent->left;

	return (sibling);
}

/**
 * binary_tree_uncle - find the uncle of a node
 * @node: node to check
 *
 * Return: pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
