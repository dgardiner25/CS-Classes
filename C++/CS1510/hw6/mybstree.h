//Programmer: DAVID GARDINER               Date: 4/14/2017
//File: mybstree.h                         Class: 1510 C
//Purpose: Implementation of the Abstract Tree class.

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include <string>
#include "abstractbstree.h"

// Tree Node class
template <typename T>
class TreeNode
{
  public:
    T m_data;
    TreeNode* m_right;
    TreeNode* m_left;

    // Default constructor
    TreeNode()
    {
      m_left = NULL;
      m_right = NULL;
    }

    // If value is known
    TreeNode(const T& x)
    {
      m_data = x;
      m_left = NULL;
      m_right = NULL;
    }

    // Full copy constructor
    TreeNode(const T& x, TreeNode<T>* l, TreeNode<T>* r)
    {
      m_data = x;
      m_left = l;
      m_right = r;
    }
};

template <typename T>
class MyBSTree : public AbstractBSTree<T>
{
  public:
    // Default constructor
    MyBSTree();

    // Copy constructor
    MyBSTree(const MyBSTree<T>& rhs);

    // Operator=
    MyBSTree<T>& operator=(const MyBSTree<T>& rhs);

    // Destructor
    ~MyBSTree() { clear(); }

    // Returns size of tree
    int size() const { return num_nodes; }

    // Returns if tree is empty or not
    bool isEmpty() const { return (!num_nodes ? true : false); }

    // Returns height of tree
    int height() const { return recursive_height(root); }

    // Gets max value of tree, throws an oops object is tree is empty
    const T& getMax() const throw (Oops);

    // Gets min value of tree, throws an oops object is tree is empty
    const T& getMin() const throw (Oops);

    // Returns the level at which x is at, if x is not found, the
    // negative of the level that was searched is returned.
    int find(const T& x) const;

    // Clears the tree
    void clear();

    // Insert a value into the correct position of the tree
    void insert(const T& x);

    // removes an element from the tree, assuming it is present
    void remove(const T& x);

    // Output the tree in pre-order
    void printPreOrder() const;

    // Output the tree in post-order
    void printPostOrder() const;

    // Description:
    // Pre:
    // Post:
    void print() const;

    // Returns the pointer to the root of the tree
    TreeNode<T>* getRoot() const { return root; }

    // Returns the pointer to the max of the tree
    TreeNode<T>* getMax(TreeNode<T>* node) const;

    // Deletes the max element of a tree
    TreeNode<T>* deleteMax(TreeNode<T>* node) const;

    // Returns whether or not the given node is a leaf
    bool isLeaf(const TreeNode<T>* node) const;

  private:
    int num_nodes;  // Size of the tree
    TreeNode<T>* root;  // Root of the tree

    /* RECURSIVE HELPER FUNCTIONS */
    void recursive_clear(TreeNode<T>* node);
    void recursive_insert(TreeNode<T>* node);
    void recursive_print(const TreeNode<T>* node, int pad) const;
    void recursive_insert(TreeNode<T>* node, const T& x);
    int recursive_find(const TreeNode<T>* node, const T& x) const;
    int recursive_height(const TreeNode<T>* node) const;
    T& recursive_min(TreeNode<T>* node) const;
    T& recursive_max(TreeNode<T>* node) const;
    void recursive_printPreOrder(const TreeNode<T>* node) const;
    void recursive_printPostOrder(const TreeNode<T>* node) const;
    void recursive_remove(TreeNode<T>* node, const T& x);
    TreeNode<T>* recursive_copy(const TreeNode<T>* node);
};


#include "mybstree.hpp"

#endif
