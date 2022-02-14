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
        Iterator	_it;

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

        // // ============================================== //
        // // ===============   Operators    =============== //
        // // ============================================== //
        // VectorIterator& operator= (const VectorIterator& iter){
        //     this->_ptr = iter._ptr;
        //     return (*this);
        // }

    }; // class template reverse_iterator

} // namespace 'ft'

#endif