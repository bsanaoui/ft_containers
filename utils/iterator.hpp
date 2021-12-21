// *************************************************************************************************** //
// **** This is a base class iterator template that can be used to derive iterator classes from it ****//
// *************************************************************************************************** //

#ifndef  __ITERATOR__HPP__
#define  __ITERATOR__HPP__

#include <cstddef> // ptrdiff_t

namespace ft {

    template <class Category,
                class T,
                class Distance = ptrdiff_t, //====/ ptrdiff_t : long is the signed integer type of the result of subtracting two pointers. /====//
                class Pointer = T*,
                class Reference = T&>

    // ************************ //
    // **** Class Iterator **** //
    // ************************ //
    class iterator {
        public :
            typedef T         value_type;
            typedef Distance  difference_type;  //-- Type to represent the difference between two iterators. --//
            typedef Pointer   pointer;  //-- Type to represent a pointer to an element pointed by the iterator. --//
            typedef Reference reference; //-- Type to represent a reference to an element pointed by the iterator. --//
            typedef Category  iterator_category; //-- Category of Iterator, one of the 5 Tag Iterator. --//
    }; // class iterator

} // namespace 'ft'

#endif