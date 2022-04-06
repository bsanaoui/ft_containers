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
        reverse_iterator() : _it(Iterator()){} // Default constructor

        explicit reverse_iterator (const iterator_type& it) : _it(it){} // constructor initialization

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
        template <class Iter>
  	   	reverse_iterator& operator= (const reverse_iterator<Iter>& rev_it)
		{
			_it = rev_it.base();
			return (*this);	  
		}

       reference operator*() const{
           iterator_type temp = _it;
           (--temp);
           return (*temp);
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

    // ============================================== //
    // ========== Operations Overloading ============ //
    // ============================================== //    
    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                       return (lhs.base() == rhs.base());
                   }

    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                       return (lhs.base() != rhs.base());
                   }

    template <class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                       return (lhs.base() > rhs.base());
                   }

    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                       return (lhs.base() >= rhs.base());
                   }

    template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                       return (lhs.base() < rhs.base());
                   }

    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs){
                       return (lhs.base() <= rhs.base());
                   }
    // :operator+ (reverse_iterator)
    template <class Iterator>
    reverse_iterator<Iterator> operator+ (
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it){
                 return reverse_iterator<Iterator>(rev_it.base() - n);
             }

    // :operator- (reverse_iterator)
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){
        return (rhs.base() - lhs.base());
    }
} // namespace 'ft'

#endif