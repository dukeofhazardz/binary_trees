#include "binary_trees.h"

/**
 * binary_trees_ancestor - A function that finds the lowest
 *				common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * Desc: If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *dad, *mom;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent, dad = second->parent;
	if (first == dad || mom == NULL || (!mom->parent && dad))
		return (binary_trees_ancestor(first, dad));
	else if (mom == second || dad == NULL || (!dad->parent && mom))
		return (binary_trees_ancestor(mom, second));
	return (binary_trees_ancestor(mom, dad));
}
