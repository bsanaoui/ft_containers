#ifndef __NODE_HPP__
#define __NODE_HPP__

namespace ft{

    // ********************************************* //
    // **** Structure template Node Of AVL Tree **** //
    // ********************************************* //
    template <class pair>
    struct node
    {
        // Member Types
        typedef pair    value_type;
        
        // node elements
        node        *right;  // The right subtree , keys greater than node's key
        node        *left;   // The left subtree , keys lesser than node's key
        value_type  *data;   // expected ft::Pair<key, T> Type
        int         height;  // height of the node

    }; //structure template node
    
} // namespace ft

#endif