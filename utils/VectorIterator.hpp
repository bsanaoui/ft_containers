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
        VectorIterator() : _ptr(NULL){} // Default constructor 
        VectorIterator(pointer ptr) : _ptr(ptr){} // constructor with param
        VectorIterator(const VectorIterator& vector_iter){ *this = vector_iter; } // // Copy constructor 
        // ~VectorIterator() { if(this->_ptr) free(this->_ptr); } // Destructor 

        // ============================================== //
        // ===========   Member Functions    ============ //
        // ============================================== //
        pointer getPointer(){ return (this->_ptr); }
        void setPointer(pointer ptr){ this->_ptr = ptr; }
        // ============================================== //
        // ===============   Operators    =============== //
        // ============================================== //
        VectorIterator& operator= (const VectorIterator& iter){
            this->_ptr = iter._ptr;
            return (*this);
        }

        bool    operator== (const VectorIterator& iter){
            if (*(iter._ptr) == *(this->_ptr))
                return (true);
            return (false);
        }

        bool    operator!= (const VectorIterator& iter){
            if (*(iter._ptr) != *(this->_ptr))
                return (true);
            return (false);
        }

        reference      operator* (){ return (*(this->_ptr)); }

        pointer      operator-> (){ return ((this->_ptr)); }

        VectorIterator& operator++() { //Prefix Incri
            (this->_ptr)++;
            return (*this);
        }

        VectorIterator operator++(int) { //Postfix Incri
            VectorIterator iter = *this;
            ++(this->_ptr);
            return (iter);
        }

        VectorIterator& operator--() { //Prefix decre
            (this->_ptr)--;
            return (*this);
        }

        VectorIterator operator--(int) { //Postfix decre
            VectorIterator iter = *this;
            --(this->_ptr);
            return (iter);
        }

        VectorIterator operator+(int n){ //
            VectorIterator iter = *this;
            iter._ptr += n;
            return (iter);
        }

         VectorIterator operator-(int n){ //
            VectorIterator iter = *this;
            iter._ptr -= n;
            return (iter);
        }

        difference_type operator-(const VectorIterator& iter){ // Substring two iterator;
            return (this->_ptr - iter._ptr);
        }

        


    }; // class VectorIterator
} // namespace 'ft'

// ============================================== //
// ========== Operations Overloading ============ //
// ============================================== //

template <typename T>
ft::VectorIterator<T> operator+(int n, const ft::VectorIterator<T> iter){
            ft::VectorIterator<T> new_iter = iter;
            new_iter.setPointer(new_iter.getPointer() + n);
            return (new_iter);
}

template <typename T>
ft::VectorIterator<T> operator-(int n, const ft::VectorIterator<T> iter){
            ft::VectorIterator<T> new_iter = iter;
            new_iter.setPointer(new_iter.getPointer() - n);
            return (new_iter);
}

#endif


