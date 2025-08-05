#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with at least 1 child
 * @tree: pointer to the root node
 *
 * Return: number of nodes with at least 1 child
 */
size_t binary_tree_nodes( const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	nodes = 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);

	return (nodes);
}
