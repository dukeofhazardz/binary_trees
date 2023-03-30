#include "binary_trees.h"
#include "limits.h"
/**
 * is_bst_helper - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - A function that checks if a binary tree is a
 *					valid Binary Search Tree
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 *
 * Properties of a Binary Search Tree:
 * The left subtree of a node contains only nodes with values
 *				less than the node’s value
 * The right subtree of a node contains only nodes with values
 *				greater than the node’s value
 * The left and right subtree each must also be a binary search tree
 * There must be no duplicate values
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree)
	{
		return (is_bst_helper(tree, INT_MIN, INT_MAX));
	}
	return (0);
}
