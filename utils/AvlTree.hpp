#ifndef __AVL_HPP__
#define __AVL_HPP__

#include <iostream>
#include "pair.hpp"
#include "node.hpp"
#include "../algorithm/max.hpp"

namespace ft
{
	// ******************************************* //
	// ********* Class template AvlTree ********** //
	// ******************************************* //
	template <	class Key,
				class T,
			  	class Compare,						// deleted after test
			  	class Alloc // deleted after test
			  	>
	class AvlTree
	{
		// ================================== //
		// ========= Member Types =========== //
		// ================================== //
	public:
		typedef Key 									key_type;
		typedef T 										mapped_type;
		typedef Compare 								key_compare;
		typedef Alloc 									allocator_value_type;

		typedef ft::pair<const key_type, mapped_type> 	value_type;
		typedef ft::node<value_type> 					node_type;
		typedef std::allocator<node_type> 				allocator_node_type;
		typedef size_t                                  size_type;


		// ============================================== //
		// ========= Member Private Attributs =========== //
		// ============================================== //
	public:
		node_type 				*_root; // Node elements
		node_type 				*_current; // Current elements
		allocator_value_type 	_alloc_value;
		allocator_node_type 	_alloc_node;
		key_compare				_key_comp;

	public:
		// ============================================== //
		// ============= Constructors  ================== //
		// ============================================== //
		AvlTree() : _root(NULL) , _current(NULL) {} // Default constructor

		AvlTree(node_type const &root, node_type const &current) : _root(root), _current(current){}

		// ============================================== //
		// ===============   Operators    =============== //
		// ============================================== //
		AvlTree &operator=(const AvlTree &tree)
		{
			this->_root = tree._root;
			this->_current = tree._current;
			return (*this);
		}

		bool  operator==(AvlTree const& tree) const{
      		return (this->_root == tree._root && this->_current == tree._current);
    	}

    	bool  operator!=(AvlTree const& tree) const{
      		return (this->_root != tree._root || this->_current != tree._current);
    	}

		// ========================================================= //
		// ===========   Member/ Non Member Functions    ============ //
		// ========================================================= //

		// Calculate height fast
		int height(node_type *N)
		{
			if (N == NULL)
				return 0;
			return N->height;
		}

		// Rotate right
		node_type *rightRotate(node_type *y)
		{
			node_type *x = y->left;
			node_type *beta = x->right;
			x->right = y;
			y->left = beta;
			y->height = ft::max(height(y->left), height(y->right)) + 1;
			x->height = ft::max(height(x->left), height(x->right)) + 1;
			return x;
		}

		// Rotate left
		node_type *leftRotate(node_type *x)
		{
			node_type *y = x->right;
			node_type *beta = y->left;
			y->left = x;
			x->right = beta;
			x->height = ft::max(height(x->left), height(x->right)) + 1;
			y->height = ft::max(height(y->left), height(y->right)) + 1;
			return y;
		}

		// Get the balance factor of each node
		int getBalanceFactor(node_type *N)
		{
			if (N == NULL)
				return 0;
			return height(N->left) - height(N->right);
		}

		node_type *findMin(node_type *root)
		{
			while (root && root->left)
				root = root->left;
			return root;
		}

		node_type *findMax(node_type *root)
		{
			while (root && root->right)
				root = root->right;
			return root;
		}

		// Create new node
		node_type *newNode(const value_type &val)
		{
			node_type *ptr;
			ptr = this->_alloc_node.allocate(1);
			ptr->data = this->_alloc_value.allocate(1);
			this->_alloc_value.construct(ptr->data, val);
			ptr->left = NULL;
			ptr->right = NULL;
			ptr->height = 1;
			return ptr;
		}

		// Insert new node in the avl tree
		node_type *insertNode(node_type *node, const value_type &val)
		{
			// Find the correct postion and insertNode the node
			if (node == NULL)
				return (newNode(val));
			if (_key_comp(val.first, node->data->first))
				node->left = insertNode(node->left, val);
			else if (_key_comp(node->data->first, val.first))
				node->right = insertNode(node->right, val);
			else
				return node;

			// Update the balance factor of each node and
			// balance the tree
			node->height = 1 + ft::max(height(node->left), height(node->right));
			int balanceFactor = getBalanceFactor(node);
			if (balanceFactor > 1)
			{
				if (_key_comp(val.first, node->left->data->first))
				{
					return rightRotate(node);
				}
				else if (_key_comp(node->left->data->first, val.first))
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}
			}
			if (balanceFactor < -1)
			{
				if (_key_comp(node->right->data->first, val.first))
				{
					return leftRotate(node);
				}
				else if (_key_comp(val.first, node->right->data->first))
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
			}
			return node;
		}

		// Delete node from the avl tree
		node_type *deleteNode(node_type *root, const value_type &val)
		{
			// Find the node and delete it
			if (root == NULL)
				return root;
			if (_key_comp(val.first, root->data->first))
				root->left = deleteNode(root->left, val);
			else if (_key_comp(root->data->first, val.first))
				root->right = deleteNode(root->right, val);
			else
			{
				if ((root->left == NULL) || (root->right == NULL))
				{
					node_type *temp = root->left ? root->left : root->right;
					if (temp == NULL)
					{
						temp = root;
						root = NULL;
					}
					else
						*root = *temp;
					// delete temp;
					this->_alloc_node.destroy(temp);
				}
				else
				{
					node_type *temp = findMin(root->right);
					root->data = temp->data;
					root->right = deleteNode(root->right, *temp->data);
				}
			}
			if (root == NULL)
				return root;
			// Update the balance factor of each node and
			// balance the tree
			root->height = 1 + ft::max(height(root->left), height(root->right));
			int balanceFactor = getBalanceFactor(root);
			if (balanceFactor > 1)
			{
				if (getBalanceFactor(root->left) >= 0)
					return rightRotate(root);
				else
				{
					root->left = leftRotate(root->left);
					return rightRotate(root);
				}
			}
			if (balanceFactor < -1)
			{
				if (getBalanceFactor(root->right) <= 0)
					return leftRotate(root);
				else
				{
					root->right = rightRotate(root->right);
					return leftRotate(root);
				}
			}
			return root;
		}
		
		// Get next node using inorder successor
		node_type *nextNode(node_type *root, node_type *x)
		{
			node_type *succ = NULL;
			if (!root)
				return NULL;
			while (1)
			{
				if (_key_comp(x->data->first, root->data->first))
				{
					succ = root;
					root = root->left;
				}
				else if (_key_comp(root->data->first, x->data->first))
					root = root->right;
				else
				{
					if (root->right)
						succ = findMin(root->right);
					break;
				}
				if (!root)
					return succ;
			}
			return succ;
		}

		// Get previous node using inorder successor
		node_type *previousNode(node_type *root, node_type *x)
		{
			// std::cout<< "root " <<root->data->first<<std::endl;
			// std::cout<< "x " << x->data->first<<std::endl;
			node_type *prec = NULL;
			if (!root)
				return NULL;
			while (1)
			{
				if (_key_comp(x->data->first, root->data->first))
					root = root->left;
				else if (_key_comp(root->data->first, x->data->first))
				{
					prec = root;
					root = root->right;
				}
				else
				{
					if (root->left)
						prec = findMax(root->left);
					break;
				}
				if (!root){
					// std::cout<< "prec " << prec->data->first<<std::endl;
					return prec;
				}
			}
			return prec;
		}

		static node_type* findNode(node_type *root,  const key_type &key)
		{
			if (root)
			{
				if (root->data->first == key)
					return (root);
				else
				{
					node_type *found_node = findNode(root->left, key);
					if (found_node == NULL)
						found_node = findNode(root->right, key);
					return found_node;
				}
			}
			else
				return (NULL);
		}

		// Print the balanced tree
		static void printTree(node_type *root, std::string indent, bool last)
		{
			if (root != nullptr)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}
				std::cout << root->data->first << std::endl;
				printTree(root->left, indent, false);
				printTree(root->right, indent, true);
			}
		}
	}; // class template AvlTree
} // namespace ft



//  void  inorder(node_type *root)
//     {
//       if (root)
//       {
//         inorder(root->left);
//         std::cout << root->data->first << " ";
//         inorder(root->right);
//       }
//     }

//     void  preorder(node_type *root)
//     {
//       if (root)
//       {
//         std::cout << root->data->first << " ";
//         preorder(root->left);
//         preorder(root->right);
//       }
//     }

//     void  postorder(node_type *root)
//     {
//       if (root)
//       {
//         postorder(root->left);
//         postorder(root->right);
//         std::cout << root->data->first << " ";
//       }
//     }

// t_node*     insertNode(t_node* node, int data)
// {
//     // Find the correct postion and insertNode the node
//   if (node == NULL)
//     return (newNode(data));
//   if (data < node->data)
//     node->left = insertNode(node->left, data);
//   else if (data > node->data)
//     node->right = insertNode(node->right, data);
//   else
//     return node;

//   // Update the balance factor of each node and
//   // balance the tree
//   node->height = 1 + std::ft::max(height(node->left),
//                height(node->right));
//   int balanceFactor = getBalanceFactor(node);
//   if (balanceFactor > 1) {
//     if (data < node->left->data) {
//       return rightRotate(node);
//     } else if (data > node->left->data) {
//       node->left = leftRotate(node->left);
//       return rightRotate(node);
//     }
//   }
//   if (balanceFactor < -1) {
//     if (data > node->right->data) {
//       return leftRotate(node);
//     } else if (data < node->right->data) {
//       node->right = rightRotate(node->right);
//       return leftRotate(node);
//     }
//   }
//   return node;
// }

// void    printGivenLevel(t_node *root, int level)
// {
//     if (root == NULL)
//         return;
//     if (level == 1)
//         std::cout << root->data << " ";
//     else if (level > 1)
//     {
//         printGivenLevel(root->left, level - 1);
//         printGivenLevel(root->right, level - 1);
//     }
// }

// void    printLevelOrder(t_node *root)
// {
//     int h = height(root);
//     for (int i = 0; i <= h; i++)
//     {
//        printGivenLevel(root, i);
//        std::cout << "\n";
//     }
// }

// // --- Returns the node with minimum key value found in that tree
// t_node* minValueNode(t_node *node)
// {
//     t_node* current = node;
//     while (current && current->left )
//         current = current->left;
//     return current;
// }
// // --- Delete a data and returns the new root



// t_node* deleteNode(t_node *root, int data)
// {
//     // Find the node and delete it
//     if (root == NULL)
//         return root;
//     if (data < root->data)
//         root->left = deleteNode(root->left, data);
//     else if (data > root->data)
//         root->right = deleteNode(root->right, data);
//     else {
//         if ((root->left == NULL) ||
//         (root->right == NULL)) {
//         t_node *temp = root->left ? root->left : root->right;
//         if (temp == NULL) {
//             temp = root;
//             root = NULL;
//         } else
//             *root = *temp;
//         free(temp);
//         } else {
//         t_node *temp = minValueNode(root->right);
//         root->data = temp->data;
//         root->right = deleteNode(root->right,
//                     temp->data);
//         }
//     }

//     if (root == NULL)
//         return root;

//     // Update the balance factor of each node and
//     // balance the tree
//     root->height = 1 + std::ft::max(height(root->left),
//                 height(root->right));
//     int balanceFactor = getBalanceFactor(root);
//     if (balanceFactor > 1) {
//         if (getBalanceFactor(root->left) >= 0) {
//         return rightRotate(root);
//         } else {
//         root->left = leftRotate(root->left);
//         return rightRotate(root);
//         }
//     }
//     if (balanceFactor < -1) {
//         if (getBalanceFactor(root->right) <= 0) {
//         return leftRotate(root);
//         } else {
//         root->right = rightRotate(root->right);
//         return leftRotate(root);
//         }
//     }
//     return root;
// }

// // Print the tree
// void printTree(t_node *root, std::string indent, bool last) {
//   if (root != nullptr) {
//     std::cout << indent;
//     if (last) {
//       std::cout << "R----";
//       indent += "   ";
//     } else {
//       std::cout << "L----";
//       indent += "|  ";
//     }
//     std::cout << root->data << std::endl;
//     printTree(root->left, indent, false);
//     printTree(root->right, indent, true);
//   }
// }

// t_node* findMin(t_node* root)
// {
//     while (root->left)
//       root = root->left;
//     return root;
// }

// t_node* findMax(t_node* root)
// {
//     while (root->right)
//         root = root->right;
//     return root;
// }



//******** TEMP FUNCTIONS *********//
// // function to find left most node in a tree
// t_node* leftMostNode(t_node* node)
// {
//     while (node != NULL && node->left != NULL)
//         node = node->left;
//     return node;
// }

// // function to find right most node in a tree
// t_node* rightMostNode(t_node* node)
// {
//     while (node != NULL && node->right != NULL)
//         node = node->right;
//     return node;
// }

// // recursive function to find the Inorder Successor
// // when the right child of node x is NULL
// t_node* findInorderRecursive(t_node* root, t_node* x )
// {
//     if (!root)
//         return NULL;

//     if (root==x || (temp = findInorderRecursive(root->left,x)) ||
//                    (temp = findInorderRecursive(root->right,x)))
//     {
//         if (temp)
//         {
//             if (root->left == temp)
//             {
//                 // std::cout << "Inorder Successor of " << x->data;
//                 // std::cout << " is "<< root->data << "\n";
//                 return NULL;
//             }
//         }

//         return root;
//     }

//     return NULL;
// }

// // function to find inorder successor of
// // a node
// t_node* inorderSuccessor(t_node* root, t_node* x)
// {
//     // Case1: If right child is not NULL
//     if (x->right != NULL)
//     {
//         t_node* inorderSucc = leftMostNode(x->right);
//         // std::cout<<"Inorder Successor of "<<x->data<<" is ";
//         // std::cout<<inorderSucc->data<<"\n";
//         return (inorderSucc);
//     }

//     // Case2: If right child is NULL
//     if (x->right == NULL)
//     {
//         t_node* rightMost = rightMostNode(root);

//         // case3: If x is the right most node
//         if (rightMost == x)
//             return (NULL);
//         else
//             return (findInorderRecursive(root, x));
//     }
//     return NULL;
// }

// // Display elements; inorder traversal of BST  : non-decreasing order.
// void        inorder(t_node *root)
// {
//     if (root)
//     {
//         inorder(root->left);
//         std::cout << root->data << " ";
//         inorder(root->right);
//     }
// }

// // Preorder traversal;  first visits the root node and then traverses the left and the right subtree // for copy !!
// void        preorder(t_node *root)
// {
//     if(root)
//     {
//         std::cout << root->data << " ";
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// // Postorder traversal ;first traverses the left and the right subtree and then visits the root node. It is used to delete the tree.
// void       postorder(t_node *root)
// {
//     if (root)
//     {
//         postorder(root->left);
//         postorder(root->right);
//         std::cout << root->data << " ";
//     }
// }

// height of the BST
// The depth of a node in a binary tree is the total number of edges from the root node to the target node
// int        height(t_node* node)
// {
//     if (!node)
//         return 0;
//     else
//     {
//         // calculate the depth of each subtree
//         int l_depth = height(node->left);
//         int r_depth = height(node->right);
//         // use the larger one
//         return (std::ft::max(l_depth, r_depth) + 1);
//     }
// }

#endif