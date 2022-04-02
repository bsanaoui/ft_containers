#ifndef  __MAP__HPP__
#define  __MAP__HPP__

#include <iostream>
#include "utils/MapIterator.hpp"
#include "utils/reverse_iterator.hpp"
#include "utils/iterator_traits.hpp"
#include "utils/AvlTree.hpp"
#include "type_traits/enable_if.hpp"
#include "type_traits/is_integral.hpp"
#include "utils/pair.hpp"
#include "utils/make_pair.hpp"


// -------------------------- Namespace "ft" -------------------------- //
namespace ft
{    
	// ****************************************** //
	// ********** Map Class template ********* //
	// ****************************************** //
	template <  class Key,                                           // map::key_type
				class T,                                             // map::mapped_type
				class Compare = std::less<Key>,                      // map::key_compare
				class Alloc = std::allocator<ft::pair<const Key,T> > >// map::allocator_type
	class map
	{
		// ================================== //
		// ========= Member Types =========== //
		// ================================== //
		public:

		typedef Key                                                                                 key_type;
		typedef T                                                                                   mapped_type;
		typedef ft::pair<const key_type,mapped_type>                                               	value_type;
		typedef Compare                                                                             key_compare;
		// typedef         value_compare;                       													// To implement
		typedef std::allocator<value_type>                                                          allocator_type;
		typedef typename allocator_type::reference	                                                reference;
		typedef typename allocator_type::const_reference	                                        const_reference;
		typedef typename allocator_type::pointer	                                                pointer;
		typedef typename allocator_type::const_pointer	                                            const_pointer;
		typedef ft::MapIterator<key_type, mapped_type, key_compare, allocator_type>                 iterator;
		typedef ft::MapIterator<const key_type, const mapped_type, key_compare, allocator_type>     const_iterator;
		typedef ft::reverse_iterator<iterator>                                                      reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>                                                const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type 							difference_type;
		typedef size_t                                                  							size_type;

		// Custom Tree Type
		typedef typename ft::AvlTree <key_type, mapped_type, key_compare, allocator_type>    		tree_type;                                                               
		typedef typename tree_type::node_type														node_type;						
		// ============================================== //
		// ========= Member Private Attributs =========== //
		// ============================================== //
		private:
		tree_type       _tree;
		size_type		_size;

		// ========================================================== //
		// ============= Constructors & Destructor ================== //
		// ========================================================== //
		public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0)
		{
			this->_tree._key_comp = comp;
			this->_tree._alloc_value = alloc;
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
				: _size(0)
		{
			this->_tree._key_comp = comp;
			this->_tree._alloc_value = alloc;
			while (first != last)
			{
				this->_tree._root = this->_tree.insertNode(this->_tree._root, *first++);
				this->_size++;
			}
		}

		map (const map& x)
		{
			*this = x;
		}

		// ============================================== //
        // ===============   Operators    =============== //
        // ============================================== //

		map&	operator=(map const& x)
		{
			this->_tree = x._tree;
			this->_size = x._size;
			return (*this);
		}

		// ------------ Test Methods ---------- //
		void	display(int i)
		{	std::cout << "--------------- Map < " << i << " > ---------------- " << std::endl;
			tree_type::printTree(_tree._root, "", true);
		}
		// -------------- End Test ------------ //
	
		// ============================================== //
        // ===========   Member Functions    ============ //
        // ============================================== //

		// ----------------- Iterators: ----------------- //
		iterator begin()
		{
			return (iterator(this->_tree._root, this->_tree.findMin(_tree._root)));
		}

		const_iterator begin() const
		{
			return (const_iterator(this->_tree._root, this->_tree.findMin(_tree._root)));
		}

		iterator end()
		{
			return (iterator(this->_tree._root, NULL));
		}

		const_iterator end() const
		{
			return (const_iterator(this->_tree._root, NULL));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(begin()));
		}

		// ----------------- Capacity : ------------------ //
		bool empty() const
		{
			return (size() == 0);
		}

		size_type size() const
		{
			return (_size);
		}

		size_type max_size() const{
			allocator_type alloc;
			return (alloc.max_size());
		}

		// ----------------- Element access: : ------------------ //
		mapped_type& operator[] (const key_type& k) // if time complexity use avl insert method
		{
			node_type	*found = tree_type::findNode(this->_tree._root, k);
			if (found)
				return (found->data->second);
			this->_tree._root = this->_tree.insertNode(this->_tree._root, ft::make_pair(k, mapped_type()));	 
			this->_size++;
			return (tree_type::findNode(this->_tree._root, k))->data->second;
		}

		// ----------------- Element access: : ------------------ //
		ft::pair<iterator,bool> insert (const value_type& val)
		{	
			// check if key found
			node_type	*found = tree_type::findNode(this->_tree._root, val.first); 
			if (found)
				return (ft::make_pair(iterator(this->_tree._root, found), false)); // false if key already existed
			// If key not found 
			this->_tree._root = this->_tree.insertNode(this->_tree._root, val);	 
			this->_size++;
			return (ft::make_pair(iterator(this->_tree._root, tree_type::findNode(this->_tree._root, val.first)), true));
		}

		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			return(insert(val).second);
			

		}



	}; // class tamplate map
} // namespace ft

#endif