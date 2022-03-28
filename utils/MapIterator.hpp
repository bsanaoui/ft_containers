#ifndef __MAP_ITERATOR__
#define __MAP_ITERATOR__

#include "iterator.hpp"
#include "avl_tree.hpp"
namespace ft{

    // **************************************** //
    // **** Class template Map Iterator **** //
    // **************************************** //
    template<class pair>
    class MapIterator : public iterator<std::bidirectional_iterator_tag, pair>{

        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
        public:
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::value_type            value_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::difference_type       difference_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::pointer               pointer;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::reference             reference;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::iterator_category     iterator_category;
        typedef typename ft::AvlTree <typename pair::first_type, typename pair::second_type>    tree_type;     // add template type alloc compare                                                                 


        // ============================================== //
        // ========= Member Private Attributs =========== //
        // ============================================== //
        private:
        tree_type *_ptr;
        tree_type *_root;

        public:

        // ============================================== //
        // ============= Constructors  ================== //
        // ============================================== //
        MapIterator(): _ptr(NULL), _root(NULL){}
        
        MapIterator(tree_type *root, tree_type *ptr): _ptr(ptr), _root(root){}
        MapIterator(MapIterator const& copy)
        {
            *this = copy;
        }

        ~MapIterator(void){};

        // ============================================== //
        // ===============   Operators    =============== //
        // ============================================== //
        MapIterator&     operator=(MapIterator const& it){
            if (*this == it)
				return (*this);
            this->_ptr = it._ptr;
            this->_root = it._root;
            return *this;
        }
        MapIterator&     operator++(){ // Prefix Incri
            this->_ptr->setRoot(this->_root->nextNode(this->_ptr->getRoot()));
            return *this;
        }
        MapIterator      operator++(int){  // Post Incri
            MapIterator temp = *this;
            ++(*this);
            return temp;
        }
        MapIterator&     operator--(){
            this->_ptr->setRoot(this->_root->previousNode(this->_ptr->getRoot()));
            return *this;
        }
        MapIterator      operator--(int){
            MapIterator temp = *this;
            --(*this);
            return temp;
        }
        bool                operator==(MapIterator const& it) const{
            return  ((this->_ptr == it._ptr) && (this->_root == it._root));
        }
        bool                operator!=(MapIterator const& it) const{
            return  ((this->_ptr != it._ptr) || (this->_root != it._root));
        }
        value_type          operator*() const{
            return  *(this->_ptr->getData());
        }
        reference           operator*(value_type const& t){
            return (this->_ptr->key = t);
        }
        pointer             operator->() const{
            return &this->_ptr->key;
        }

    }; // class template MapIterator

} // namespace ft

#endif