#include "binary_trees.h"
/**
 * binary_tree_height_node - measures height of a node tree
 * @tree: pointer to the tree to measure
 *
 * Return: size of the tree
 */
int binary_tree_height_node(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = binary_tree_height_node(tree->left);
	right_height = binary_tree_height_node(tree->right);

	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node
 *
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance = 0;

	if (tree == NULL)
		return (0);

	balance = binary_tree_height_node(tree->left) -
	binary_tree_height_node(tree->right);

	return (balance);
}
