#ifndef  __MAP__HPP__
#define  __MAP__HPP__

#include <iostream>
#include "utils/MapIterator.hpp"
#include "utils/reverse_iterator.hpp"
#include "utils/iterator_traits.hpp"
#include "utils/avl_tree.hpp"
#include "type_traits/enable_if.hpp"
#include "type_traits/is_integral.hpp"
// #include "algorithm/equal.hpp"
// #include "algorithm/lexicographical_compare.hpp"

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
		typedef ft::pair<const key_type,mapped_type>                                               value_type;
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

		// ============================================== //
		// ========= Member Private Attributs =========== //
		// ============================================== //
		private:
		tree_type       _tree;
        // tree_type       _root;
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
				_tree._root = _tree.insertNode(_tree._root, *first++);
				_size++;
			}
		}


		// For Test
		void	display(){this->_tree.printTree(_tree._root, "", true);}



	}; // class tamplate map
} // namespace ft

#endif