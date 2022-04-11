#ifndef __AVL_HPP__
#define __AVL_HPP__

#include <iostream>
#include "pair.hpp"
#include "node.hpp"
#include "../vector.hpp"
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
		AvlTree() : _root(nullptr) , _current(nullptr) {} // Default constructor

		AvlTree(node_type const &root, node_type const &current) : _root(root), _current(current){}

		// ============================================== //
		// ===============   Operators    =============== //
		// ============================================== //
		AvlTree &operator=(const AvlTree &tree)
		{
			this->_root = tree._root;
			this->_current = tree._current;
			// this->_alloc_value = tree._alloc_value;
			// this->_key_comp = tree._key_comp;
			return (*this);
		}

		~AvlTree()
		{
			// this->_alloc_node.deallocate(this->_root, 1);
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

		node_type *findMin(node_type *root) const
		{
			while (root && root->left)
				root = root->left;
			return root;
		}

		node_type *findMax(node_type *root) const
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
			ptr->left = NULL;
			ptr->right = NULL;
			ptr->data = this->_alloc_value.allocate(1);
			this->_alloc_value.construct(ptr->data, val);
			ptr->height = 1;
			return ptr;
		}

		// Insert new node in the avl tree
		node_type *insertNode(node_type *node, const value_type &val)
		{
			// Find the correct postion and insertNode the node
			if (node == nullptr)
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

		node_type *deleteNode(node_type *root, const key_type &key) // test
		{
			// Find the node and delete it
			if (root == NULL)
				return root;
			if (_key_comp(key, root->data->first))
				root->left = deleteNode(root->left, key);
			else if (_key_comp(root->data->first, key))
				root->right = deleteNode(root->right, key);
			else
			{
				if ((root->left == NULL) || (root->right == NULL))
				{
					node_type *temp = root->left ? root->left : root->right;
					if (temp == NULL)
					{
						temp = root;
						root = nullptr;
					}
					else
					{
						// *root = *temp;
						root->right = temp->right;
						root->left = temp->left;
						root->height = temp->height;
						this->_alloc_value.destroy(root->data);
						this->_alloc_value.construct(root->data, *(temp->data));
					}
							
					this->_alloc_value.deallocate(temp->data, 1);
					this->_alloc_node.deallocate(temp, 1);
				}
				else
				{
					node_type *temp = findMin(root->right);
					// root->data = temp->data;
					this->_alloc_value.destroy(root->data);
					this->_alloc_value.construct(root->data, *(temp->data));

					root->right = deleteNode(root->right, temp->data->first);
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
		node_type *nextNode(node_type *root, node_type *x) const
		{
			node_type *succ = nullptr;
			if (!root)
				return nullptr;
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
			node_type *prec = nullptr;
			if (!root)
				return nullptr;
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

		node_type* findNode(node_type *root,  const key_type &key) const
		{
			if (!root)
				return NULL;
			if (_key_comp(root->data->first, key))
				return (findNode(root->right, key));
			else if (_key_comp(key, root->data->first))
				return (findNode(root->left, key));
		
			return root;
		}

		void  findKeysRange(node_type *root, const key_type &key, node_type **lower, node_type **upper) const
		{

			if (root)
			{
				if (key <= root->data->first && root->data->first < (*lower)->data->first)
					*lower = root;
				if (key < root->data->first && root->data->first < (*upper)->data->first)
					*upper = root;
				if (root->data->first <= key)
					findKeysRange(root->right, key, lower, upper);
				else if (key <= root->data->first)
					findKeysRange(root->left, key, lower, upper);
			}
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


#endif