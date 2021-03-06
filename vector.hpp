#ifndef  __VECTOR__HPP__
#define  __VECTOR__HPP__

#include <iostream>
#include "utils/VectorIterator.hpp"
#include "utils/reverse_iterator.hpp"
#include "type_traits/enable_if.hpp"
#include "type_traits/is_integral.hpp"
#include "algorithm/equal.hpp"
#include "algorithm/swap.hpp"
#include "algorithm/lexicographical_compare.hpp"

// -------------------------- Namespace "ft" -------------------------- //
namespace ft
{    
    // ****************************************** //
    // ********** Vector Class template ********* //
    // ****************************************** //
    template < class T, class Alloc = std::allocator<T> >   
    class vector
    {
        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
        public:

        typedef T                                                       value_type;
        typedef Alloc                                                   allocator_type;
        typedef typename allocator_type::reference                      reference; // for the default allocator: value_type&
        typedef typename allocator_type::const_reference                const_reference; // for the default allocator: const value_type&
        typedef typename allocator_type::pointer	                    pointer;
        typedef typename allocator_type::const_pointer	                const_pointer;
        typedef typename ft::VectorIterator<T>                          iterator;
        typedef ft::VectorIterator<const T>                             const_iterator;
        typedef ft::reverse_iterator<iterator>                          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef size_t                                                  size_type; 

        
        // ============================================== //
        // ========= Member Private Attributs =========== //
        // ============================================== //
        private:
		pointer		_arr; // type is std::allocator<T> 
		size_type	_size;
		size_type	_capacity;
		Alloc 		_allocator;

	    // ========================================================== //
        // ============= Constructors & Destructor ================== //
        // ========================================================== //
        public:
        explicit vector (const allocator_type& alloc = allocator_type())
			:  _size(0), _capacity(0){
				this->_allocator = alloc;
				this->_arr = this->_allocator.allocate(0);
			}

        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
			this->_allocator = alloc;
			this->_arr = this->_allocator.allocate(n);
			for (size_type i = 0; i < n; i++) // edit 
				this->_allocator.construct(this->_arr + i, val);
			this->_capacity = n;
			this->_size = n;
		}

		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			: _size(0), _capacity(0) {
				this->_allocator = alloc;
				this->_arr = this->_allocator.allocate(0);
				// this->_capacity = 0;
				assign(first, last);
		}   

		vector (const vector& x)
			: _arr(NULL) ,_size(0), _capacity(0){
			*this = x;
		}

		~vector (){
			for (size_type i = 0; i < size(); i++)
				this->_allocator.destroy(this->_arr + i);
			this->_allocator.deallocate(this->_arr, capacity());
			this->_capacity = 0;
			this->_size = 0;
		}

		// ============================================== //
        // ===============   Operators    =============== //
        // ============================================== //
		vector&	operator= (const vector& x){ //capcaity if big
			clear();
			this->_allocator.deallocate(this->_arr, _capacity);
			this->_size = x.size();
			this->_arr = this->_allocator.allocate(x.capacity());
			this->_capacity = x.capacity();
		
			for (size_type i = 0; i < size(); i++)
				this->_allocator.construct((this->_arr + i), x._arr[i]);
			this->_allocator = x._allocator;
			return (*this);
		}

		reference	operator[] (size_type n){
			return (this->_arr[n]);
		}

		const_reference operator[] (size_type n) const{
			return (this->_arr[n]);
		}

		// ============================================== //
        // ===========   Member Functions    ============ //
        // ============================================== //

		// ----------------- Iterators: -------------------//
		iterator begin(){
			return (iterator(this->_arr));
		}

		const_iterator begin() const{
			return (const_iterator(this->_arr));
		}

		iterator end(){
			return (iterator(this->_arr + this->_size));
		}

		const_iterator end() const{
			return (const_iterator(this->_arr + this->_size)); // in reverse we -1 from base()
		}

		reverse_iterator rbegin(){
			return (reverse_iterator(this->_arr + this->_size));
		}

		const_reverse_iterator rbegin() const{
			return (const_reverse_iterator(this->_arr + this->_size));
		}

		reverse_iterator rend(){
			return (reverse_iterator(this->_arr));
		}

		const_reverse_iterator rend() const{
			return (const_reverse_iterator(this->_arr));
		}

		// ----------------- Capacity: -------------------//

		size_type size() const{
			return (this->_size);
		}

		size_type max_size() const{
			allocator_type alloc;
			return (alloc.max_size());
		}

		void resize (size_type n, value_type val = value_type()){
			if (n > this->_capacity){
				if (n < (this->_capacity * 2))
					reserve(this->_capacity * 2);
				else
					reserve(n);
			}
			if (n > this->_size)
				for (size_type i = this->_size; i < n; i++)
					this->_allocator.construct(this->_arr + i, val);
			if (n < this->_size)
				for (size_type i = n; i < this->_size; i++)
					this->_allocator.destroy(this->_arr + i);
			this->_size = n;
		}
		
		size_type capacity() const{
			return (this->_capacity);
		}

		bool empty() const{
			return (this->_size == 0);
		}

		void reserve (size_type n){
			if (n >= max_size() || n < 0)
					throw std::length_error("vector:");
			if (n > capacity()){
				pointer		new_arr;
				new_arr = this->_allocator.allocate(n);
				for (size_type i = 0; i < size(); i++)
					this->_allocator.construct(new_arr + i, this->_arr[i]);
				for (size_type i = 0; i < size(); i++)
					this->_allocator.destroy(this->_arr + i);
				this->_allocator.deallocate(this->_arr, this->_capacity);
				this->_arr = new_arr;
				this->_capacity = n;
			}
		}
	
		// ----------------- Element access: -------------------//

		// *** Operator [] implimented in operations section in this file *** 
	
		reference at (size_type n){
			if (n < this->_size && n >= 0)
				return (this->_arr[n]);
			throw std::out_of_range("vector");
		}

		const_reference at (size_type n) const{
			if (n < this->_size && n >= 0)
				return (this->_arr[n]);
			throw std::out_of_range("vector");
		}

		reference front(){
			return (*(this->_arr));
		}
	
		const_reference front() const{
			return (*(this->_arr));
		}

		reference back(){
			return (*(this->_arr + this->_size - 1));
		}
	
		const_reference back() const{
			return (*(this->_arr + this->_size - 1));
		}

		// ----------------- Modifiers: -------------------//

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last,
		  	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
				reserve(last - first);
				size_type i;
				for (i = 0; first != last; i++)
					this->_allocator.construct(this->_arr + i, *(first++));
				this->_size = i;
		}

		void assign (size_type n, const value_type& val){
				reserve(n);
				for (size_type i = 0; i < n ; i++)
					this->_allocator.construct(this->_arr + i, val);
				this->_size = n;
		}

		void push_back (const value_type& val){
			// std::cout << _size ;
			if (!this->_capacity)
				reserve(1);
			if (this->_size == this->_capacity)
				reserve(this->_capacity * 2);
			this->_allocator.construct(this->_arr + this->_size++, val);
		}

		void pop_back(){ 
			this->_allocator.destroy(this->_arr + this->_size - 1);
			this->_size--;
		}

		//------> Single element
		iterator insert (iterator position, const value_type& val){
			difference_type pos = position.getPointer() - this->_arr ; // Posi of elemen

			if (!this->_size)
				reserve(1);
			else if (this->_size == this->_capacity)
				reserve(this->_capacity * 2);
			this->_size++;
			for (size_type i = size() - 1; i > (size_type)pos; i--) // to begin complexity
				this->_allocator.construct(this->_arr + i, (*this)[i - 1]);
			this->_allocator.construct(this->_arr + pos, val); // insert element
			return (iterator(this->_arr + pos));
		}

		//------> Fill
		void insert (iterator position, size_type n, const value_type& val){
			size_type pos = position - begin()  ; // Posi of elemen

			if (!this->_size)
				reserve(n);
			else if ((n + size()) > capacity()){
				if ((n + size()) <= (capacity() * 2))
					reserve(capacity() * 2);
				else
					reserve(n + size());
			}
			for (size_type i = pos; i < size(); i++)
				this->_allocator.construct(this->_arr + i + n, (*this)[i]);
			this->_size += n;
			for (size_type i = 0; i < n; i++)
				this->_allocator.construct(this->_arr + pos + i, val); // insert elements
		}

		//------> Range
		template <class InputIterator> // error if first is not position
    	void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
				size_type pos = position - begin(); // Posi of elemen
				size_type n = last - first;

				if (!this->_size)
					reserve(n);
				else if ((n + size()) > capacity()){
					if ((n + size()) <= (capacity() * 2))
						reserve(capacity() * 2);
					else
						reserve(n + size());
				}
				for (size_type i = pos; i < size(); i++)
					this->_allocator.construct(this->_arr + i + n, (*this)[i]);
				this->_size += n;
				for (size_type i = 0; i < n; i++)
					this->_allocator.construct(this->_arr + pos + i, *(first++)); // insert elements
		}

		iterator erase (iterator position){
			difference_type pos = position.getPointer() - this->_arr ; // Posi of element

			this->_size--;
			this->_allocator.destroy(this->_arr + pos); // delete element
			for (size_type i = pos; i < size() + 1; i++) // Relocate elements
				this->_allocator.construct(this->_arr + i, (*this)[i + 1]);
			this->_allocator.destroy(this->_arr + size());
			return (iterator(this->_arr + pos));
		}

		iterator erase (iterator first, iterator last)
		{
			size_type pos = first.getPointer() - this->_arr ; // Posi of element
			size_type n = last - first;

			// std::cout << "pos = " << pos << " | n = " << n << std::endl;
			for (size_type i = pos; i < n; i++)			// delete elements
				this->_allocator.destroy(this->_arr + i); 
			for (size_type i = pos; (i + n) < size() ; i++) 	//  Relocate elements
				this->_allocator.construct(this->_arr + i, (*this)[i + n]);
			for (size_type i = pos + n; i < size(); i++)	// destroy empty storage;
				this->_allocator.destroy(this->_arr + i); 
			this->_size -= n;
			return (iterator(this->_arr + pos));
		}

		void swap (vector& x){
			ft::swap(this->_size, x._size);
			ft::swap(this->_arr, x._arr);
			ft::swap(this->_allocator, x._allocator);
			ft::swap(this->_capacity, x._capacity);
		}			

		void clear(){
			for (size_type i = 0; i < size(); i++)
				this->_allocator.destroy(this->_arr + i);
			this->_size = 0;
		}

		allocator_type get_allocator() const{
			return (Alloc(this->_allocator));
		}

    }; // class template vector

	// ================================================================== //
    // ===============   Non-member function overloads    =============== //
    // ================================================================== //

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		  x.swap(y);
	}

	// ----------------- > relational operators (vector)
	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		  return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		  return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		  return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		  return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		  return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		  return (!(lhs < rhs));
	}

} // namespace ft

#endif