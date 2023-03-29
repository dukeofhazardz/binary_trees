#include "binary_trees.h"

/**
 * binary_tree_insert_left - A function that inserts a node
 *			as the left-child of another node
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure
 *					or if parent is NULL
 * Desc: If parent already has a left-child, the new node must
 *	take its place, and the old left-child must be set as
 *	the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(parent, value);
	if (newNode == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		newNode->left = parent->left;
		parent->left->parent = newNode;
	}
	parent->left = newNode;

	return (newNode);
}
