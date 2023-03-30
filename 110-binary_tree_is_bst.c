#include "binary_trees.h"

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
		if (tree->left->n > tree->n || tree->right->n < tree->n)
			return (1);
		return (0);
	}
	return (0);
}
