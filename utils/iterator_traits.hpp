// *************************************************************************************************** //
// ******************** This is a Traits class defining properties of iterators. ********************* //
// *************************************************************************************************** //

#ifndef  __ITERATOR_TRAITS__HPP__
#define  __ITERATOR_TRAITS__HPP__

#include <cstddef> // ptrdiff_t
#include "iterator.hpp"

namespace ft {

    // ************************************************* //
    // **** Class template iterator_traits Generic  **** //
    // ************************************************* //
    template <class Iterator>
    class iterator_traits {
        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
        public:
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;

    }; // class template iterator_traits generic


    // *********************************************************** //
    // **** Class template iterator_traits T* specialization  **** //
    // *********************************************************** //
    template <class T>
    class iterator_traits<T*> {
        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
        public:
        typedef  ptrdiff_t                                  difference_type;
        typedef  T                                          value_type;
        typedef  T*                                         pointer;
        typedef  T&                                         reference;
        typedef typename std::random_access_iterator_tag   iterator_category;

    }; // class template iterator_traits T* specialization

    // ***************************************************************** //
    // **** Class template iterator_traits const T* specialization  **** //
    // ***************************************************************** //
    template <class T>
    class iterator_traits<const T*> {
        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
        public:
        typedef  ptrdiff_t                                  difference_type;
        typedef  T                                          value_type;
        typedef  const T*                                   pointer;
        typedef  const T&                                   reference;
        typedef typename std::random_access_iterator_tag    iterator_category;

    }; // class template iterator_traits const T* specialization

} // namespace 'ft'

#endif