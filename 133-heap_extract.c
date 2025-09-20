#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node
 *
 * Return: number of nodes in the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}


/**
 * heapify_down - Restores Max Heap property by moving a node down
 * @node: Pointer to the node to start bubbling down
 *
 * Description: Compares a node with its children and swaps values
 *              to ensure the max-heap property is maintained.
 */
static void heapify_down(heap_t *node)
{
    heap_t *max = node;
    int tmp;

    while (node)
    {
        if (node->left && node->left->n > max->n)
            max = node->left;
        if (node->right && node->right->n > max->n)
            max = node->right;
        if (max == node)
            break;
        tmp = node->n;
        node->n = max->n;
        max->n = tmp;
        node = max;
    }
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Description: Removes the root node, replaces it with the last node
 *              in level-order, then restores the Max Heap property.
 *
 * Return: The value stored in the removed root node
 *         0 on failure
 */
int heap_extract(heap_t **root)
{
    heap_t **queue, *last = NULL, *current;
    int value;
    size_t front = 0, rear = 0, size;

    if (!root || !*root)
        return 0;

    value = (*root)->n;
    size = binary_tree_size(*root);
    if (size == 1)
    {
        free(*root);
        *root = NULL;
        return value;
    }

    queue = malloc(sizeof(heap_t *) * size);
    if (!queue)
        return 0;

    queue[rear++] = *root;
    while (front < rear)
    {
        current = queue[front++];
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
        last = current;
    }

    (*root)->n = last->n;
    if (last->parent->left == last)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;
    free(last);
    free(queue);

    heapify_down(*root);
    return value;
}
