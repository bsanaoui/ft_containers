// ******************************************************************************************************** //
// ******* //   This is class Vector Iterator template that derived  from base iterator class   // ******** //
// ******************************************************************************************************** //

#ifndef __VECTOR_ITERATOR__HPP__
#define __VECTOR_ITERATOR__HPP__

#include "iterator.hpp"
#include <iostream>

namespace ft
{
    template <typename T>
    // ******************************* //
    // **** Class Vector Iterator **** //
    // ******************************* //
    class VectorIterator : public ft::iterator<std::random_access_iterator_tag, T>
    {
        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
        public:
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference reference;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;


        // ============================================== //
        // ========= Member Private Attributs =========== //
        // ============================================== //
        private:
        pointer _ptr;

    
        public:
        // ============================================== //
        // ======== Constructors && Destructors ========= //
        // ============================================== //
        VectorIterator() : _ptr(NULL){}
        VectorIterator(const VectorIterator& vector_iter){ *this = vector_iter}

        // ============================================== //
        // ===========   Member Functions    ============ //
        // ============================================== //
        pointer getPointer(){ return (this->_ptr); }

        // ============================================== //
        // ===============   Operators    =============== //
        // ============================================== //
        VectorIterator& operation= (const VectorIterator& vector_iter){
            this->_ptr = vector_iter.getPointer();
            return (*this);
        }

        bool    operator== (const VectorIterator& vector_iter){
            if (*(vector_iter.getPointer()) == *(this->_ptr))
                return (true);
            return (false);
        }



    }; // class VectorIterator
} // namespace 'ft'

#endif


