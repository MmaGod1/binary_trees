#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_up - Moves a node up to maintain Max Heap property
 * @node: Pointer to the node to heapify
 */
void heapify_up(heap_t *node)
{
    int tmp;

    while (node->parent && node->n > node->parent->n)
    {
        tmp = node->n;
        node->n = node->parent->n;
        node->parent->n = tmp;
        node = node->parent;
    }
}

/**
 * heap_size - Returns the total number of nodes in a binary tree
 * @tree: Pointer to the root node
 * Return: Size of the tree
 */
size_t heap_size(const heap_t *tree)
{
    if (!tree)
        return (0);
    return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * heap_insert_node - Inserts a node at the first available spot (level-order)
 * @root: Pointer to the root node
 * @node: Node to insert
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert_node(heap_t **root, heap_t *node)
{
    size_t size = heap_size(*root);
    heap_t **queue = malloc(sizeof(heap_t *) * size);
    size_t front = 0, rear = 0;
    heap_t *current;

    if (!queue)
        return (NULL);

    queue[rear++] = *root;

    while (front < rear)
    {
        current = queue[front++];
        if (!current->left)
        {
            current->left = node;
            node->parent = current;
            free(queue);
            return (node);
        }
        if (!current->right)
        {
            current->right = node;
            node->parent = current;
            free(queue);
            return (node);
        }
        queue[rear++] = current->left;
        queue[rear++] = current->right;
    }

    free(queue);
    return (NULL);
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *node;

    if (!root)
        return (NULL);

    node = binary_tree_node(NULL, value);
    if (!node)
        return (NULL);

    if (!*root)
    {
        *root = node;
        return (node);
    }

    heap_insert_node(root, node);
    heapify_up(node);

    return (node);
}
