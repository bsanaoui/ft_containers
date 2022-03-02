// ******************************************************************************************************** //
// ******* //   This is class Vector Iterator template that derived  from base iterator class   // ******** //
// ******************************************************************************************************** //

#ifndef __VECTOR_ITERATOR__HPP__
#define __VECTOR_ITERATOR__HPP__

#include "iterator.hpp"
#include <iostream>

namespace ft
{
    // **************************************** //
    // **** Class template Vector Iterator **** //
    // **************************************** //
    template <typename T>
    class VectorIterator : public ft::iterator<std::random_access_iterator_tag, T>
    {
        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
        public:
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type           value_type;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type      difference_type;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer              pointer;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference            reference;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category    iterator_category;


        // ============================================== //
        // ========= Member Private Attributs =========== //
        // ============================================== //
        private:
        pointer _ptr;

    
        public:
        // ============================================== //
        // ============= Constructors  ================== //
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
            this->_ptr = iter.base();
            return (*this);
        }

        // to asigne  
        operator VectorIterator<const T>() const {
			return VectorIterator<const T>(this->_ptr); }

        pointer base() const { return _ptr; }

        bool    operator== (const VectorIterator& iter){
            if (iter._ptr == this->_ptr)
                return (true);
            return (false);
        }

        bool    operator!= (const VectorIterator& iter){
            return (!(*this == iter));
        }

        reference    operator* () const { return (*(this->_ptr)); }

        pointer      operator-> (){ return ((this->_ptr)); }

        value_type   operator*(reference t){
            *(this->_ptr) = t;
            return (*(this->_ptr));
        } 

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

        VectorIterator operator+(difference_type n) const{ //
            VectorIterator iter = *this;
            iter._ptr += n;
            return (iter);
        }

         VectorIterator operator-(difference_type n) const { //
            VectorIterator iter = *this;
            iter._ptr -= n;
            return (iter);
        }

        difference_type operator-(const VectorIterator& iter) const{ // Substring two iterator;
            return (this->_ptr - iter._ptr);
        }

        bool            operator<(const VectorIterator& iter){
            return ( this->_ptr < iter._ptr );
        }

        bool            operator>(const VectorIterator& iter){
            return ( this->_ptr > iter._ptr );
        }

        bool            operator<=(const VectorIterator& iter){
            return ( !(*this > iter) );
        }

        bool            operator>=(const VectorIterator& iter){
            return ( !(*this < iter) );
        }

        VectorIterator&  operator+=(difference_type n){ // Compound assignment operations
            *this = *this + n;
            return (*this);
        }

        VectorIterator&  operator-=(difference_type n){ // Compound assignment operations
            *this = *this - n;
            return (*this);
        }

        // Offset dereference operator
        reference      operator[](difference_type n){
            return (this->_ptr[n]);
        }

    }; // class VectorIterator

    // ============================================== //
    // ========== Operations Overloading ============ //
    // ============================================== //

    template <typename T>
    VectorIterator<T> operator+(int n, const VectorIterator<T> iter){
        return (iter + n);
    }
} // namespace 'ft'

#endif


