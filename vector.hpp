#ifndef  __VECTOR__HPP__
#define  __VECTOR__HPP__

#include <iostream>

// ==================================== Class template Vector ============================================ //

// -------- template < Create Namespace "ft" ------------ //
namespace ft
{
    // *********************************** //
    template < class T, class Alloc = std::allocator<T> >
    
    // ************************************ //
    // *** Vector Template *** //
    // *********************************** //   
    class vector
    {
        vector()
        {
            T *t;
            t = Alloc::allocate(85);
        }
    };
} // namespace ft

#endif