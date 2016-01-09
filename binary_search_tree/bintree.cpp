#include <cassert>    // Provides assert
#include <cstdlib>   // Provides nullptr, std::size_t
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout

#include "bintree.h"

    void print(binary_tree_node* node_ptr, unsigned int depth)
    // Library facilities used: iomanip, iostream, stdlib
    {
        if (node_ptr != nullptr)
        {
            print(node_ptr->right, depth+1);
            std::cout << std::setw(4*depth) << ""; // Indent 4*depth spaces.
            std::cout << node_ptr->data << std::endl;
            print(node_ptr->left,  depth+1);
        }
    }    
	
    void tree_clear(binary_tree_node*& root_ptr)
    // Library facilities used: cstdlib
    {
		binary_tree_node* child;
		if (root_ptr != nullptr)
		{
			child = root_ptr->left;
			tree_clear( child );
			child = root_ptr->right;
			tree_clear( child );
			delete root_ptr;
			root_ptr = nullptr;
		}
    }

    binary_tree_node* tree_copy(const binary_tree_node* root_ptr)
    // Library facilities used: cstdlib
    {
		binary_tree_node *l_ptr;
		binary_tree_node *r_ptr;

		if (root_ptr == nullptr)
			return nullptr;
		else
		{
			l_ptr = tree_copy( root_ptr->left );
			r_ptr = tree_copy( root_ptr->right );
			binary_tree_node* new_node = new binary_tree_node;
			new_node->data = root_ptr->data;
			new_node->left = l_ptr;
			new_node->right = r_ptr;
			return new_node;
		}
    }

    unsigned int tree_size(const binary_tree_node* node_ptr)
    // Library facilities used: cstdlib
    {
        if (node_ptr == nullptr)
            return 0;
        else 
            return 1 + tree_size(node_ptr->left) + 
				tree_size(node_ptr->right);
    }    
