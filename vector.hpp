#ifndef  __VECTOR__HPP__
#define  __VECTOR__HPP__

#include <iostream>
#include "utils/VectorIterator.hpp"
#include "utils/reverse_iterator.hpp"

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

	    // ============================================== //
        // ============= Constructors  ================== //
        // ============================================== //
        public:
        explicit vector (const allocator_type& alloc = allocator_type()){
			this->_allocator = alloc;
			this->_arr = this->_allocator.allocate(0);
			this->_capacity = 0;
			this->_size = 0;
		}


        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
			this->_allocator = alloc;
			this->_arr = this->_allocator.allocate(n);
			for (int i = 0; i < n; i++) // edit 
				this->_allocator.construct(this->_arr + i, val);
			this->_capacity = n;
			this->_size = n;
            std::cout << " constr fill" << std::endl;
		}

        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename std::enable_if<!std::is_integral<InputIterator>::value>::type = InputIterator()){
			// for (size_type i = 0; i < count; i++)
			// { 
			// 	/* code */
			// }
                std::cout << "Iterator const" << std::endl;
		}   

		// vector (const vector& x){

		// }

        // vector()
        // {
        //     T *t;
        //     t = Alloc::allocate(85);
        // }
    
    }; // clas tamplate vector
} // namespace ft

#endif