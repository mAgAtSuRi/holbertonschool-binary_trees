#include "binary_trees.h"
/**
 * binary_tree_is_full - check if a tree is full
 * @tree: pointer to the root node
 *
 * Return: 1 if full otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}

/**
 * binary_tree_last_left - go to the deepest left node
 * @tree: pointer to a node
 *
 * Return: pointer to the leftest node
 */
binary_tree_t *binary_tree_last_left(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return ((binary_tree_t *)tree);

	return (binary_tree_last_left(tree->left));
}

/**
 * binary_tree_depth - measures depth of a node in binary tree
 * @tree: pointer to the node
 *
 * Return: the depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	if (tree->parent == NULL)
		return (depth);

	depth = 1 + binary_tree_depth(tree->parent);
	return (depth);
}

/**
 * same_depth_leaves - check if all leaves have same depth
 * @tree: tree to check
 * @expected_depth: depth expected
 *
 * Return: 1 if same depth otherwise 0
 */
int same_depth_leaves(const binary_tree_t *tree, size_t expected_depth)
{
	size_t depth;
	int result = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		depth = binary_tree_depth(tree);
		if  (depth == expected_depth)
			return (1);
	}
	result = same_depth_leaves(tree->left, expected_depth)
	&& same_depth_leaves(tree->right, expected_depth);

	return (result);
}

/**
 * binary_tree_is_perfect - check if its a perfect tree
 * @tree: pointer to the root node
 *
 * Return: 1 if perfect otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left_node;
	size_t depth;

	if (tree == NULL)
		return (0);

	if (binary_tree_is_full(tree) == 0)
		return (0);

	left_node = binary_tree_last_left(tree);
	if (left_node == NULL)
		return (0);

	depth = binary_tree_depth(left_node);

	return (same_depth_leaves(tree, depth));
}
