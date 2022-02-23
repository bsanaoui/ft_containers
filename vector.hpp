#ifndef  __VECTOR__HPP__
#define  __VECTOR__HPP__

#include <iostream>
#include "utils/VectorIterator.hpp"
#include "utils/reverse_iterator.hpp"
#include "type_traits/enable_if.hpp"
#include "type_traits/is_integral.hpp"
#include "algorithm/equal.hpp"

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
        typedef const iterator                                          const_iterator;
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
			: _allocator(alloc), _arr(_allocator.allocate(0)), _capacity(0), _size(0){}


        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
			this->_allocator = alloc;
			this->_arr = this->_allocator.allocate(n);
			for (int i = 0; i < n; i++) // edit 
				this->_allocator.construct(this->_arr + i, val);
			this->_capacity = n;
			this->_size = n;
		}

		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
				this->_allocator = alloc;
				this->_arr = this->_allocator.allocate(last - first);
				for (size_type i = 0; first != last; i++){
					this->_allocator.construct(this->_arr + i, *(first++));
					this->_size++;
					this->_capacity++;
				}
		}   

		vector (const vector& x)
			: _allocator(x._allocator), _capacity(0), _size(0){
			*this = x;
		}

		~vector (){
			for (size_type i = 0; i < this->_size; i++)
				this->_allocator.destroy(this->_arr + i);
			this->_capacity = 0;
			this->_size = 0;
		}

		// ============================================== //
        // ===============   Operators    =============== //
        // ============================================== //
		vector&	operator= (const vector& x){
			if(!this->_size){
				this->_arr = this->_allocator.allocate(x.size());
				this->_size = x.size();
				this->_capacity = x.size();
			}
			for (size_type i = 0; i < x.size(); i++)
				(*this)[i] = x[i];
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
			return (const_iterator(this->_arr + this->_size));
		}

		reverse_iterator rbegin(){
			return (reverse_iterator(this->_arr + this->_size - 1));
		}

		const_reverse_iterator rbegin() const{
			return (const_reverse_iterator(this->_arr + this->_size - 1));
		}

		reverse_iterator rend(){
			return (reverse_iterator(this->_arr - 1));
		}

		const_reverse_iterator rend() const{
			return (const_reverse_iterator(this->_arr - 1));
		}

		// ----------------- Capacity: -------------------//

		size_type size() const{
			return (this->_size);
		}

		size_type max_size() const{
			return (this->_allocator.max_size());
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

		void reserve (size_type n){
			if (n > this->_capacity){
				pointer		new_arr;
				new_arr = this->_allocator.allocate(n);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(new_arr + i, this->_arr[i]);
				this->_allocator.deallocate(this->_arr, this->_capacity);
				this->_arr = new_arr;
				this->_capacity = n;
			}
		}

    }; // clas tamplate vector
} // namespace ft

#endif