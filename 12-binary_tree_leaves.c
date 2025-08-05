#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the number of leaves
 * @tree: pointer to the root of the tree to check
 *
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	leaves += binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (leaves);
}
