#include "binary_trees.h"

/**
 * binary_tree_insert_right - A function that inserts a node
 *			as the left-child of another node
 * @parent: is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure
 *					or if parent is NULL
 * Desc: If parent already has a right-child, the new node must
 *	take its place, and the old left-child must be set as
 *	the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(parent, value);
	if (newNode == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		newNode->right = parent->right;
		parent->right->parent = newNode;
	}
	parent->right = newNode;

	return (newNode);
}
