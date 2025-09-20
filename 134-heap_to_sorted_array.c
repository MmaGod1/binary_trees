#include "binary_trees.h"

/**
 * tree_size - Computes the number of nodes in a binary tree
 * @root: Pointer to the root node
 *
 * Return: Number of nodes
 */
size_t tree_size(const binary_tree_t *root)
{
	if (!root)
		return (0);
	return (1 + tree_size(root->left) + tree_size(root->right));
}

/**
 * heap_to_sorted_array - Converts a Max Binary Heap to a sorted array
 *                        in descending order
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i, heap_size;

	if (!heap || !size)
		return (NULL);

	/* 1. Count number of nodes */
	heap_size = tree_size(heap);
	*size = heap_size;

	/* 2. Allocate array */
	array = malloc(sizeof(int) * heap_size);
	if (!array)
		return (NULL);

	/* 3. Extract max repeatedly */
	for (i = 0; i < heap_size; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
