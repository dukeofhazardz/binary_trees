#include "binary_trees.h"

/**
 * binary_tree_size - A function that measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 * Return: If tree is NULL, the function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (tree)
	{
		counter += 1;
		counter += binary_tree_size(tree->left);
		counter += binary_tree_size(tree->right);
		return (counter);
	}
	return (0);
}
