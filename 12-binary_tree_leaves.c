#include "binary_trees.h"

/**
 * binary_tree_leaves - A function that counts the leaves in a binary tree
 * @tree: is a pointer to the root node of the tree to count
 *					the number of leaves
 * Return: If tree is NULL, the function must return 0
 * Desc: A NULL pointer is not a leaf
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t counter;

	if (tree)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);

		counter = 0;
		counter += binary_tree_leaves(tree->left);
		counter += binary_tree_leaves(tree->right);

		return (counter);
	}
	return (0);
}
