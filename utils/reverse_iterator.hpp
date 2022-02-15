// ******************************************************************************************************** //
// **** This is a class template reverse_iterator that reverses the direction of random-access iterator ****//
// ******************************************************************************************************** //

#ifndef  __REVERSE_ITERATOR__HPP__
#define  __REVERSE_ITERATOR__HPP__

#include "iterator_traits.hpp"

namespace ft {

    // **************************************** //
    // **** Class template reverse_terator **** //
    // **************************************** //
    template <class Iterator> 
    class reverse_iterator {
         
        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
        public:
        typedef 		 Iterator										iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
        typedef typename iterator_traits<Iterator>::value_type	   		value_type;
        typedef typename iterator_traits<Iterator>::difference_type		difference_type;
        typedef typename iterator_traits<Iterator>::pointer	   			pointer;
        typedef typename iterator_traits<Iterator>::reference			reference;

		// ============================================== //
        // ========= Member Private Attributs =========== //
        // ============================================== //
        private:
        iterator_type	_it;

        public:
        // ============================================== //
        // ============= Constructors  ================== //
        // ============================================== //
        reverse_iterator() : _it(NULL){} // Default constructor

        explicit reverse_iterator (iterator_type it) : _it(it){} // constructor initialization

        template <class Iter> // // Copy constructor
        reverse_iterator (const reverse_iterator<Iter>& rev_it){
            *this = rev_it;
        }

        // ============================================== //
        // ===========   Member Functions    ============ //
        // ============================================== //
        iterator_type base() const{
            return (this->_it);
        }

        // // ============================================== //
        // // ===============   Operators    =============== //
        // // ============================================== //
       reference operator*() const{
           return (*(base() - 1));
       }

       reverse_iterator operator+ (difference_type n) const{
           return reverse_iterator(base() - n);
       }
       
       reverse_iterator& operator++(){
           --this->_it;
           return *this;
       }
       
       reverse_iterator  operator++(int){
           reverse_iterator tmp = *this;
           ++(*this);
           return (tmp);
       }
       
       reverse_iterator& operator+= (difference_type n){
            this->_it -= n;
            return (*this);
       }

        reverse_iterator operator- (difference_type n) const{
           return reverse_iterator(base() + n);
       }
       
       reverse_iterator& operator--(){
           ++this->_it;
           return *this;
       }
       
       reverse_iterator  operator--(int){
           reverse_iterator tmp = *this;
           --(*this);
           return (tmp);
       }
       
       reverse_iterator& operator-= (difference_type n){
            this->_it += n;
            return (*this);
       }
        
        pointer operator->() const {
           return &(operator*());
        }

        reference operator[] (difference_type n) const{
            return (base()[-n-1]);
        }



    }; // class template reverse_iterator

} // namespace 'ft'

#endif