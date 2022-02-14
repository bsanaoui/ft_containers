#ifndef  __VECTOR__HPP__
#define  __VECTOR__HPP__

#include <iostream>
#include "utils/VectorIterator.hpp"

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

        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference; // for the default allocator: value_type&
        typedef typename allocator_type::const_reference    const_reference; // for the default allocator: const value_type&
        typedef typename allocator_type::pointer	        pointer;
        typedef typename allocator_type::const_pointer	    const_pointer;
        typedef typename ft::VectorIterator<T>              iterator;
        typedef const iterator                              const_iterator;


        
        private:
        // ============================================== //
        // ========= Member Private Attributs =========== //
        // ============================================== //
        /*
        ...
        ...
        */

        public:
        vector()
        {
            T *t;
            t = Alloc::allocate(85);
        }
    
    }; // clas tamplate vector
} // namespace ft

#endif