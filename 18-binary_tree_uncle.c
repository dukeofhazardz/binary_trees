#include "binary_trees.h"

/**
 * binary_tree_uncle - A function that finds the uncle of a node
 * @node: is a pointer to the node to find the uncle
 * Return: must return a pointer to the uncle node
 * If node is NULL, return NULL
 * If node has no uncle, return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *temp;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->parent)
	{
		temp = node->parent->parent;
		return ((temp->right == node->parent) ? temp->left : temp->right);
	}
	return (NULL);
}
