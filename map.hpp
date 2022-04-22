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
#include "vector.hpp"
#include "algorithm/equal.hpp"
#include "algorithm/lexicographical_compare.hpp"


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
		typedef	class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			protected:
				Compare comp;
  				value_compare (Compare c) : comp(c) {}
			public:
				bool operator() (const value_type& x, const value_type& y) const{
					return comp(x.first, y.first);
  				}
		} value_compare;
		typedef std::allocator<value_type>                                                          allocator_type;
		typedef typename allocator_type::reference	                                                reference;
		typedef typename allocator_type::const_reference	                                        const_reference;
		typedef typename allocator_type::pointer	                                                pointer;
		typedef typename allocator_type::const_pointer	                                            const_pointer;
		typedef ft::MapIterator<key_type, mapped_type, key_compare, allocator_type>                 iterator;
		typedef ft::MapIterator<const key_type, mapped_type, key_compare, allocator_type>     		const_iterator;
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

		~map()
		{
			erase(begin(), end());
		}

		// ============================================== //
        // ===============   Operators    =============== //
        // ============================================== //

		map&	operator=(map const& x)
		{
			this->clear();
			this->insert(x.begin(), x.end());
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
			node_type	*found = this->_tree.findNode(this->_tree._root, k);
			if (found)
				return (found->data->second);
			this->_tree._root = this->_tree.insertNode(this->_tree._root, ft::make_pair(k, mapped_type()));	 
			this->_size++;
			
			return (this->_tree.findNode(this->_tree._root, k))->data->second;
		}

		// ----------------- Element access: : ------------------ //
		ft::pair<iterator,bool> insert (const value_type& val) //Original !!
		{	
			// check if key found
			node_type	*found = this->_tree.findNode(this->_tree._root, val.first); 
			if (found)
				return (ft::make_pair(iterator(this->_tree._root, found), false)); // false if key already existed
			// If key not found 
			this->_tree._root = this->_tree.insertNode(this->_tree._root, val);	 
			this->_size++;
			return (ft::make_pair(iterator(this->_tree._root, this->_tree.findNode(this->_tree._root, val.first)), true));
		}


		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			return(insert(val).first);
		}

		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				value_type val = *first;
				// check if key not found
				node_type	*found = this->_tree.findNode(this->_tree._root, val.first);
				if (!found)
				{
					this->_tree._root = this->_tree.insertNode(this->_tree._root, val);	 
					this->_size++;
				}
				first++;
			}
		}

		void erase (iterator position)
		{
			this->_tree._root = this->_tree.deleteNode(this->_tree._root, (*position).first);
			this->_size--;
		}


		size_type erase (const key_type& k) //Original
		{
			node_type	*found = this->_tree.findNode(this->_tree._root, k);
			if (!found)
				return (0);
			this->_tree._root = this->_tree.deleteNode(this->_tree._root, k);
			this->_size--;
			return (1);
		}

		void erase (iterator first, iterator last)
		{
			ft::vector<key_type> v; // to store keys to be deleted in a vector
			while(first != last)
				v.push_back((*first++).first);
			for (size_t i = 0; i < v.size(); i++)
				erase(v[i]);
		}

		void swap (map& x)
		{
			ft::swap(this->_tree , x._tree);
			ft::swap(this->_size, x._size);
		}

		void clear()
		{
			erase(begin(), end());
		}

		// ----------------- Observers : ------------------ //
		key_compare key_comp() const
		{
			return (key_compare(this->_tree._key_comp));
		}

		value_compare value_comp() const
		{
			return (value_compare(this->_tree._key_comp));
		}

		// ----------------- Operations : ----------------- //
		iterator find (const key_type& k)
		{
			node_type	*found = this->_tree.findNode(this->_tree._root, k);
			if (found)
				return (iterator(this->_tree._root, found));
			return (end());
		}

		const_iterator find (const key_type& k) const
		{
			node_type	*found = this->_tree.findNode(this->_tree._root, k);
			if (found)
				return (const_iterator(this->_tree._root, found));
			return (end());
		}

		size_type count (const key_type& k) const
		{
			if (this->_tree.findNode(this->_tree._root, k))
				return (1);
			return (0);
		}

		iterator lower_bound (const key_type& k)
		{
			node_type *first = this->_tree.findMin(this->_tree._root);
			while (this->_tree._key_comp(first->data->first, k)) // if (key <= first return it) 2 case
				first = this->_tree.nextNode(this->_tree._root, first);
			if (first)
				return (iterator(this->_tree._root, first));
			return (iterator(end()));
		}

		const_iterator lower_bound (const key_type& k) const
		{
			node_type *first = this->_tree.findMin(this->_tree._root);
			while (this->_tree._key_comp(first->data->first, k)) // if (key <= first return it) 2 case
				first = this->_tree.nextNode(this->_tree._root, first);
			if (first)
				return (const_iterator(this->_tree._root, first));
			return (const_iterator(end()));
		}


		iterator upper_bound (const key_type& k)
		{
			node_type *first = this->_tree.findMin(this->_tree._root);
			while (first->data->first <= k) // if (key < first return it) 1 case
				first = this->_tree.nextNode(this->_tree._root, first);
			if (first)
				return (iterator(this->_tree._root, first));
			return (iterator(end()));
		}

		const_iterator upper_bound (const key_type& k) const
		{
			node_type *first = this->_tree.findMin(this->_tree._root);			
			while (first->data->first <= k) // if (key < first return it) 1 case
				first = this->_tree.nextNode(this->_tree._root, first);
			if (first)
				return (const_iterator(this->_tree._root, first));
			return (const_iterator(end()));
		}

		// ----------------- Allocator : ----------------- //
		allocator_type get_allocator() const
		{
			return(Alloc(this->_tree._alloc_value));
		}


		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			node_type *lower, *upper;

			lower = this->_tree.findMax(this->_tree._root);
			upper = lower;
			this->_tree.findKeysRange(this->_tree._root, k, &lower, &upper);

			return(ft::make_pair(const_iterator(this->_tree._root, lower), const_iterator(this->_tree._root, upper)));
		}

		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			node_type *lower, *upper;

			lower = this->_tree.findMax(this->_tree._root);
			upper = lower;
			this->_tree.findKeysRange(this->_tree._root, k, &lower, &upper);

			// if (!lower && !upper)
			// 	return(ft::make_pair(end(), end()));
			// if (lower && !upper)
			// 	return(ft::make_pair(iterator(this->_tree._root, lower), end()));
			// if (!lower && upper)
			// 	return(ft::make_pair(end(), iterator(this->_tree._root, upper)));
			return(ft::make_pair(iterator(this->_tree._root, lower), iterator(this->_tree._root, upper)));
		}

	}; // class tamplate map

	// ================================================================== //
    // ===============   Non-member function overloads    =============== //
    // ================================================================== //
	template <class Key, class T, class Compare, class Alloc>
  	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}

	// ----------------- > relational operators (map)
	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}


	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		 return (!(lhs == rhs));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}


	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(rhs < lhs));
	}


	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}

} // namespace ft

#endif