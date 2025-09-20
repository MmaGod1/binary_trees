#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure
 *
 * Return: size of the tree, 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

/**
 * heap_insert - inserts a value in a Max Binary Heap
 * @root: double pointer to the root node
 * @value: value to insert
 *
 * Return: pointer to the created node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *tree, *new_node, *curr;
    int size, leaves, level, sub, bit, tmp;

    if (!root)
        return (NULL);
    if (!*root)
        return (*root = binary_tree_node(NULL, value));

    tree = *root;
    size = binary_tree_size(tree);

    /* Compute number of leaves at the bottom level */
    leaves = size;
    for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
        leaves -= sub;

    /* Traverse tree using binary representation of leaves */
    for (bit = 1 << (level - 1); bit > 0; bit >>= 1)
        tree = (leaves & bit) ? tree->right : tree->left;

    /* Insert new node at first empty slot */
    new_node = binary_tree_node(tree, value);
    if (leaves & 1)
        tree->right = new_node;
    else
        tree->left = new_node;

    /* Bubble up values to maintain Max Heap */
    curr = new_node;
    while (curr->parent && curr->n > curr->parent->n)
    {
        tmp = curr->n;
        curr->n = curr->parent->n;
        curr->parent->n = tmp;
        curr = curr->parent;
    }

    return (new_node);
}
