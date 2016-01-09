#include <cassert>
#include <cstdlib>
#include "binary_search_tree.h"
//#include "bintree.h"

	void bst_remove_max(binary_tree_node*& root_ptr, int& removed)
	// Precondition: root_ptr is a root pointer of a non-empty binary 
	// search tree.
	// Postcondition: The largest item in the binary search tree has been
	// removed, and root_ptr now points to the root of the new (smaller) 
	// binary search tree. The reference parameter, removed, has been set 
	// to a copy of the removed item.
	{

	}

	bool bst_remove(binary_tree_node*& root_ptr, const int& target)
	// Precondition: root_ptr is a root pointer of a binary search tree 
	// or may be nullptr for an empty tree).
	// Postcondition: If target was in the tree, then one copy of target
	// has been removed, and root_ptr now points to the root of the new 
	// (smaller) binary search tree. In this case the function returns true.
	// If target was not in the tree, then the tree is unchanged (and the
	// function returns false).
	{
		if(root_ptr->right != nullptr)
		{
			bst_remove(root_ptr->right, removed);
		}
		
		else()
		{
			removed = root_ptr->data;
			binary_tree_node* old_root_ptr = root_ptr;
			root_ptr = root_ptr->left; // shouldn't we jump up a node to delete the old one?
			delete old_root_ptr; // delet node
			old_root_ptr = nullptr; // delete placeholder
		}
	}

	unsigned int bst_remove_all(binary_tree_node*& root_ptr, const int& target)
	// Precondition: root_ptr is a root pointer of a binary search tree 
	// or may be nullptr for an empty tree).
	// Postcondition: All copies of target have been removed from the tree
	// has been removed, and root_ptr now points to the root of the new 
	// (smaller) binary search tree. The return value tells how many copies
	// of the target were removed.
	{
		if(root_ptr->right == nullptr)
		{
			return false;
		}
		
		if(target < root_ptr->data)
		{
			return bst_remove(root_ptr->left, target);
		}
		
		if(target > root_ptr->data)
		{
			return bst_remove(root_ptr->right, target);
		}
		
		if(root_ptr->left == nullptr)
		{
			binary_tree_node* old_root_ptr = root_ptr;
			root_ptr = root_ptr->right;
			delete old_root_ptr;
			return true;
		}
		
		bst_remove_max(root_ptr->left, root_ptr->data); // find the biggest and overwrights root
			
		return true;
	}

    void init(binary_tree_node*& root_ptr)
	{
		root_ptr = nullptr;
	}
	
	void init(binary_tree_node*& root_ptr, const binary_tree_node* source_root_ptr)
	// Library facilities used: bintree.h
	{
		root_ptr = tree_copy(source_root_ptr);
	}

	void destr(binary_tree_node*& root_ptr)
	// Header file used: bintree.h
	{
		tree_clear(root_ptr); // root passed by ref
	}

	binary_tree_node* binary_search_tree_copy(const binary_tree_node* source_root_ptr)
	{
		binary_tree_node* n = tree_copy(source_root_ptr);
		return n;
	}
	
	unsigned int size(const binary_tree_node* root_ptr)
	// Header file used: bintree.h
	{
		return 0;
	}

	void insert(binary_tree_node*& root_ptr, const int& entry)
	// Header file used: bintree.h
	{
		if(root_ptr == nullptr)
		{
			root_ptr = new binary_tree_node;
			root_ptr->data = entry;
			root_ptr->left = nullptr;
			root_ptr->right = nullptr; // branches are empty
			return;
		}
		
		binary_tree_node* cursor = root_ptr;
		
		bool done = false:
		
		while(!done)
		{
			if(cursor->data >= entry)
			{
				if(cursor->left == nullptr)
				{
					cursor->left = new binary_tree_node;
					cursor->data = entry;
					cursor->left->left = cursor->left->right = nullptr; // chain set both to nullptr
					done = true;
					return;
				}
				
				else
				{
					cursor = cursor->left;
				}
			}
			
			else if (cursor->data < entry)
			{
					if(cursor->right == nullptr)
				{
					cursor->right = new binary_tree_node;
					cursor->data = entry;
					cursor->right->right = cursor->right->left = nullptr; // chain set both to nullptr
					done = true;
					return;
				}
				
				else
				{
					cursor = cursor->right;
				}
			}
		}
	}

    unsigned int frequency(const binary_tree_node* root_ptr, const int& target)
	{
		return 0;
	}

	unsigned int erase(binary_tree_node*& root_ptr, const int& target)
	{
		return 0;
	}

	bool erase_one(binary_tree_node*& root_ptr, const int& target)
	{
		return false;
	}

	void combine(binary_tree_node*& root_ptr, const binary_tree_node* addend_root_ptr)
	{

	}

	binary_tree_node* add(const binary_tree_node* b1, const binary_tree_node* b2)
	{
		binary_tree_node* answer = nullptr;
		return answer;
	}

	void insert_all(binary_tree_node*& root_ptr, const binary_tree_node* addroot_ptr)
        // Precondition: addroot_ptr is the root pointer of a binary search tree that
        // is separate from the binary search tree that activated this
        // method.
        // Postcondition: All the items from the addroot_ptr's binary search tree
        // have been added to the binary search tree that activated this
        // method.
	{
		
	}
