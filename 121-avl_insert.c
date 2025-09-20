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
    int balance;

    if (!tree)
        return (NULL);

    if (!*tree)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        if ((*tree)->left)
            node = avl_insert(&(*tree)->left, value);
        else
            node = (*tree)->left = binary_tree_node(*tree, value);
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right)
            node = avl_insert(&(*tree)->right, value);
        else
            node = (*tree)->right = binary_tree_node(*tree, value);
    }
    else
        return (NULL);

    /* Rebalance */
    balance = binary_tree_balance(*tree);

    if (balance > 1)
    {
        if (value < (*tree)->left->n)
            *tree = binary_tree_rotate_right(*tree);
        else
        {
            (*tree)->left = binary_tree_rotate_left((*tree)->left);
            *tree = binary_tree_rotate_right(*tree);
        }
    }
    if (balance < -1)
    {
        if (value > (*tree)->right->n)
            *tree = binary_tree_rotate_left(*tree);
        else
        {
            (*tree)->right = binary_tree_rotate_right((*tree)->right);
            *tree = binary_tree_rotate_left(*tree);
        }
    }

    return (node);
}
