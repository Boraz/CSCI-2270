#include <cstdlib>     // Provides NULL and size_t
#include "bintree.h"   // Provides binary_tree_node and related functions

    // CONSTRUCTORS and DESTRUCTOR
	void init(binary_tree_node*& root_ptr);
    void init(binary_tree_node*& root_ptr, const binary_tree_node* source_ptr);
	void destr(binary_tree_node*& root_ptr);
	unsigned int size(const binary_tree_node* root_ptr);
	binary_tree_node* binary_search_tree_copy(const binary_tree_node* source_ptr);

	void insert(binary_tree_node*& root_ptr, const int& entry);
    unsigned int frequency(const binary_tree_node* root_ptr, const int& target);
	unsigned int erase(binary_tree_node*& root_ptr, const int& target);
	bool erase_one(binary_tree_node*& root_ptr, const int& target);
	unsigned int bst_remove_all(binary_tree_node*& root_ptr, const int& target);
	bool bst_remove(binary_tree_node*& root_ptr, const int& target);
	void bst_remove_max(binary_tree_node*& root_ptr, int& removed);
	void combine(binary_tree_node*& root_ptr, const binary_tree_node* addend_root_ptr);
	binary_tree_node* add(const binary_tree_node* b1, const binary_tree_node* b2);
	void insert_all(binary_tree_node*& root_ptr, const binary_tree_node* addroot_ptr);
	
