#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *node;

    if (!tree)
        return (NULL);

    /* Insert as in a BST */
    if (!*tree)
        return (*tree = binary_tree_node(NULL, value));

    if (value < (*tree)->n)
        node = (*tree)->left ? avl_insert(&(*tree)->left, value)
                              : (*tree)->left = binary_tree_node(*tree, value);
    else if (value > (*tree)->n)
        node = (*tree)->right ? avl_insert(&(*tree)->right, value)
                               : (*tree)->right = binary_tree_node(*tree, value);
    else
        return (NULL); /* Ignore duplicates */

    /* Rebalance if needed */
    int balance = binary_tree_balance(*tree);

    if (balance > 1)
        *tree = (value < (*tree)->left->n) ? 
                 binary_tree_rotate_right(*tree) : 
                 (binary_tree_rotate_left((*tree)->left), binary_tree_rotate_right(*tree));

    if (balance < -1)
        *tree = (value > (*tree)->right->n) ? 
                 binary_tree_rotate_left(*tree) : 
                 (binary_tree_rotate_right((*tree)->right), binary_tree_rotate_left(*tree));

    return (node);
}
