//Programmer: DAVID GARDINER               Date: 4/14/2017
//File: mybstree.hpp                       Class: 1510 C
//Purpose: Functions definitions for the MyBSTree class.

#include "mybstree.h"

template <typename T>
MyBSTree<T>::MyBSTree()
{
  root = new TreeNode<T>;   // Create the tree
  num_nodes = 0;
}

template <typename T>
MyBSTree<T>::MyBSTree(const MyBSTree<T>& rhs)
{
  *this = rhs;             // Use operator=
}

template <typename T>
MyBSTree<T>& MyBSTree<T>::operator=(const MyBSTree<T>& rhs)
{
  root = recursive_copy(rhs.getRoot());  // Call recursive_copy function
}

template <typename T>
const T& MyBSTree<T>::getMin() const throw(Oops)
{
  if(!num_nodes)                    // Check if tree is empty
    throw Oops("Tree is empty!");   // Throw "Oops" object
  return recursive_min(root);       // Return the found min
}

template <typename T>
const T& MyBSTree<T>::getMax() const throw (Oops)
{
  if(!num_nodes)                    // Check if tree is empty
    throw Oops("Tree is empty!");   // Throw "Oops" object
  return recursive_max(root);       // Return the found max
}

template <typename T>
int MyBSTree<T>::find(const T& x) const
{
  return recursive_find(root, x);   // Call recursive helper
}

template <typename T>
void MyBSTree<T>::insert(const T& x)
{
  if(!num_nodes)                    // If inserting root
  {
    root->m_data = x;
    num_nodes++;
  }
  else if(find(x) < 0)
  {
    recursive_insert(root, x);
    num_nodes++;
  }
}

template <typename T>
void MyBSTree<T>::clear()
{
  recursive_clear(root);          // Call recursive clear helper
}

template <typename T>
void MyBSTree<T>::remove(const T& x)
{
  if(find(x) > 0)                 // Make sure x is in the tree
    recursive_remove(root, x);    // Call remove helper
}

template <typename T>
void MyBSTree<T>::printPreOrder() const
{
  recursive_printPreOrder(root);  // Call pre-order helper
}

template <typename T>
void MyBSTree<T>::printPostOrder() const
{
  recursive_printPostOrder(root);  // Call post-order helper
}

template <typename T>
void MyBSTree<T>::print() const
{
  if(num_nodes)                   // Make sure tree isn't empty
    recursive_print(root, 0);     // Call print helper
}

template <typename T>
void MyBSTree<T>::recursive_clear(TreeNode<T>* node)
{
  if(node == NULL)                // If reached last node
    return;
  recursive_clear(node->m_right);
  recursive_clear(node->m_left);
  delete node;
}

template <typename T>
void MyBSTree<T>::recursive_print(const TreeNode<T>* node, int pad) const
{
  string s(pad, ' ');             // For outputting pretty
  if (node == NULL)               // If no child
    cout << endl;
  else
  {
    recursive_print(node->m_right, pad+4);
    cout << s << (node->m_data) << endl;
    recursive_print(node->m_left, pad+4);
 }
}

template <typename T>
void MyBSTree<T>::recursive_insert(TreeNode<T>* node, const T& x)
{
  if(x < node->m_data)    // If x < current node
  {
    if(node->m_left == NULL)  // If left child is empty
      node->m_left = new TreeNode<T>(x);
    else
      recursive_insert(node->m_left, x);
  }
  else if(x > node->m_data)   // If x > current node
  {
    if(node->m_right == NULL)   // if right child is empty
      node->m_right = new TreeNode<T>(x);
    else
      recursive_insert(node->m_right, x);
  }
}

template <typename T>
int MyBSTree<T>::recursive_find(const TreeNode<T>* node, const T& x) const
{
  static int level = 0;
  if(node->m_data == root->m_data)  // Reset level if at root
    level = 0;
  level++;
  if(node->m_data == x)   // If found
    return level;
  if(node->m_left != NULL)  // Make sure left child isn't empty
    if(x < node->m_data)
      return recursive_find(node->m_left, x);
  if(node->m_right != NULL)   // Make sure right child isn't empty
    if(x > node->m_data)
      return recursive_find(node->m_right, x);
  return -level-1;    // return negative level if not found
}

template <typename T>
int MyBSTree<T>::recursive_height(const TreeNode<T>* node) const
{
  static int level = 1;
  if(node->m_data == root->m_data)  // Reset level if at root
    level = 1;
  level++;
  if(node->m_left != NULL)
    return recursive_height(node->m_left);
  if(node->m_right != NULL)
    return recursive_height(node->m_right);
  return level;
}

template <typename T>
T& MyBSTree<T>::recursive_min(TreeNode<T>* node) const
{
  if(node->m_left == NULL)  // Found min
    return node->m_data;
  else
    return recursive_min(node->m_left);
}

template <typename T>
T& MyBSTree<T>::recursive_max(TreeNode<T>* node) const
{
  if(node->m_right == NULL)   // Found max
    return node->m_data;
  else
    return recursive_max(node->m_right);
}

template <typename T>
void MyBSTree<T>::recursive_printPreOrder(const TreeNode<T>* node) const
{
  if (node == NULL)   // If at an empty child
    cout << "";
  else
  {
    cout << (node->m_data) << " ";
    recursive_printPreOrder(node->m_left);
    recursive_printPreOrder(node->m_right);
  }
}

template <typename T>
void MyBSTree<T>::recursive_printPostOrder(const TreeNode<T>* node) const
{
  if (node == NULL)   // If at an empty child
    cout << "";
  else
  {
    recursive_printPostOrder(node->m_left);
    recursive_printPostOrder(node->m_right);
    cout << (node->m_data) << " ";
  }
}

template <typename T>
TreeNode<T>* MyBSTree<T>::getMax(TreeNode<T>* node) const
{
  if(node->m_right == NULL) // Max found
    return node;
  else
    return getMax(node->m_right);
}

template <typename T>
TreeNode<T>* MyBSTree<T>::deleteMax(TreeNode<T>* node) const
{
  if(node->m_right == NULL)
    return node->m_left;
  else
  {
    node->m_right = deleteMax(node->m_right);
    return node;
  }
}

template <typename T>
bool MyBSTree<T>::isLeaf(const TreeNode<T>* node) const
{
  if(node->m_left == NULL && node->m_right == NULL) // Make sure is leaf
    return true;
  return false;
}

template <typename T>
void MyBSTree<T>::recursive_remove(TreeNode<T>* node, const T& x)
{
  if(x < node->m_data) // If x < current node
  {
    if(node->m_left != NULL && x == node->m_left->m_data &&
       isLeaf(node->m_left)) // Check if x = left child
      node->m_left = NULL;
    else if(node->m_right != NULL && x == node->m_right->m_data &&
            isLeaf(node->m_right)) // Check if x = right child
      node->m_right = NULL;
    else
      recursive_remove(node->m_left, x);
  }
  else if(x > node->m_data) // If x > current node
  {
    if(node->m_left != NULL && x == node->m_left->m_data &&
       isLeaf(node->m_left))  // Check if x = left child
      node->m_left = NULL;
    else if(node->m_right != NULL && x == node->m_right->m_data &&
            isLeaf(node->m_right)) // Check if x = right child
      node->m_right = NULL;
    else
      recursive_remove(node->m_right, x);
  }
  else  // x found in tree
  {
    TreeNode<T>* temp = node; // copy the node
    if(node->m_left != NULL) // if left child present, copy everything
    {
      temp = getMax(node->m_left);
      node->m_data = temp->m_data;
      node->m_left = deleteMax(node->m_left); // delete max
    }
    else if(node->m_right != NULL) // if right child present, copy everything
    {
      temp = getMax(node->m_right);
      node->m_data = temp->m_data;
      node->m_right = deleteMax(node->m_right); // delete max

    }
    delete temp;
  }
}

template <typename T>
TreeNode<T>* MyBSTree<T>::recursive_copy(const TreeNode<T>* node)
{
  num_nodes++; // Increase size
  if(node == NULL) // If empty child
    return NULL;
  else
    return new TreeNode<T>(node->m_data, recursive_copy(node->m_left),
                           recursive_copy(node->m_right));
}
