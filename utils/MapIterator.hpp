#ifndef __MAP_ITERATOR__
#define __MAP_ITERATOR__

#include "iterator.hpp"
#include "avl_tree.hpp"
namespace ft{

    // **************************************** //
    // **** Class template Map Iterator **** //
    // **************************************** //
     template < class Key,                                           // map::key_type
                class T,                                             // map::mapped_type
                class Compare = std::less<Key>,                      // map::key_compare
                class Alloc = std::allocator<ft::pair<const Key,T> > >
    class MapIterator : public iterator<std::bidirectional_iterator_tag, ft::pair<const Key, T> >
    {
        // ================================== //
        // ========= Member Types =========== //
        // ================================== //
        public:
        typedef typename ft::pair<const Key, T>                                                 pair;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::value_type            value_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::difference_type       difference_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::pointer               pointer;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::reference             reference;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::iterator_category     iterator_category;
        typedef typename ft::AvlTree <Key, T, Compare, Alloc>                                   tree_type;     // add template type alloc compare                                                                 


        // ============================================== //
        // ========= Member Private Attributs =========== //
        // ============================================== //
        private:
        tree_type       _tree; //_tree(root_node, current_node);

        public:

        // ============================================== //
        // ============= Constructors  ================== //
        // ============================================== //
        MapIterator(): _tree(){}
        
        MapIterator(tree_type *tree): _tree(*tree)
        {
            this->_tree._current = this->_tree.findMin(this->_tree._root);
        }

        MapIterator(const MapIterator& copy) : _tree()
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
            this->_tree = it._tree;
            return *this;
        }

        MapIterator&     operator++(){ // Prefix Incri
            this->_tree._current = this->_tree.nextNode(this->_tree._root, this->_tree._current);
            return *this;
        }

        MapIterator      operator++(int){  // Post Incri
            MapIterator temp(*this);
            ++(*this);
            return temp;
        }

        MapIterator&     operator--(){
            this->_tree._current = this->_tree.previousNode(this->_tree._root, this->_tree._current);
            return *this;
        }

        MapIterator      operator--(int){
            MapIterator temp(*this);
            --(*this);
            return temp;
        }

        bool                operator==(MapIterator const& it) const{
            return  (this->_tree == it._tree);
        }
        
        bool                operator!=(MapIterator const& it) const{
            return  (this->_tree != it._tree);
        }
        
        reference        operator*() const{
            return  *(this->_tree._current->data);
        }

        reference           operator*(value_type const& t){ // *a = t
            return (this->_tree._current->data = t);
        }

        pointer             operator->() const{
            return this->_tree._current->data;
        }

    }; // class template MapIterator

} // namespace ft

#endif