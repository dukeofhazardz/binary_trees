#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recurse(const binary_tree_t *tree, size_t leaf_depth,
							size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
size_t binary_tree_depth(const binary_tree_t *tree);

/**
 * binary_tree_is_leaf - A function that checks if a node is a leaf
 * @node: is a pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 * Desc: If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left || node->right)
		return (0);
	return (1);
}

/**
 * binary_tree_depth - A function that measures the depth of
 *                              a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + binary_tree_depth(tree->parent));

	return (0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (binary_tree_is_leaf(tree))
	{
		return (tree);
	}
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recurse - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect_recurse(const binary_tree_t *tree, size_t leaf_depth,
						size_t level)
{
	if (binary_tree_is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);

	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recurse(tree->left, leaf_depth, level + 1) &&
		is_perfect_recurse(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - A function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree)
	{
		return (is_perfect_recurse(tree, binary_tree_depth(get_leaf(tree)), 0));
	}
	return (0);
}
