#include "binary_trees.h"

/**
 * binary_tree_height - Returns the height of a binary tree in nodes.
 * @tree: Pointer to the root node.
 *
 * Return: Height of the tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;

    if (tree == NULL)
        return 0;

    if (tree->left)
        left_height = 1 + binary_tree_height(tree->left);
    else
        left_height = 1;

    if (tree->right)
        right_height = 1 + binary_tree_height(tree->right);
    else
        right_height = 1;

    return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Calculates the balance factor of a node.
 * @tree: Pointer to the node.
 *
 * Return: left subtree height - right subtree height, 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return ( (int)binary_tree_height(tree->left) -
             (int)binary_tree_height(tree->right) );
}
