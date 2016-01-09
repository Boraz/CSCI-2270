#include "bintree.h"
#include "binary_search_tree.h"
#include "doubly_linked_list.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void tree_to_list_inorder(const binary_tree_node* root_ptr, node*& head_ptr, node*& tail_ptr)
{
	if(root_ptr == nullptr) return;
	if(root_ptr != nullptr)
	{
	tree_to_list_inorder(root_ptr->left, head_ptr, tail_ptr); // traverse down the tree to find the smallest number
	
	node* added_node = new node; // print out data at root send the data to the list
	added_node->data = root_ptr->data;
	
	if(head_ptr == nullptr) // null list
	{
		node* added_node = new node; // print out data at root send the data to the list
		added_node->data = root_ptr->data;
		head_ptr = added_node;
		head_ptr->next = nullptr;
		head_ptr->prev = nullptr;
		tail_ptr = head_ptr;
		}
	else // list cant be null if we get here because of above if
	{
		node* cursor = tail_ptr; // add at the tail
		tail_ptr = added_node;
		cursor->next = added_node;
		added_node->next = nullptr;
		added_node->prev = cursor;	
	}
	
	tree_to_list_inorder(root_ptr->right, head_ptr, tail_ptr); // move back along the tree*/
	}
	 
}

void tree_to_list_preorder(const binary_tree_node* root_ptr, node*& head_ptr, node*& tail_ptr)
{
	if(root_ptr == nullptr) return;
	if(root_ptr != nullptr)
	{
	node* added_node = new node; // print out data at root send the data to the list
	added_node->data = root_ptr->data;
	
	if(head_ptr == nullptr) // null list
	{
		node* added_node = new node; // print out data at root send the data to the list
		added_node->data = root_ptr->data;
		head_ptr = added_node;
		head_ptr->next = nullptr;
		head_ptr->prev = nullptr;
		tail_ptr = head_ptr;
		}
	else // list cant be null if we get here because of above if
	{
		node* cursor = tail_ptr; // add at the tail
		tail_ptr = added_node;
		cursor->next = added_node;
		added_node->next = nullptr;
		added_node->prev = cursor;	
	}
	 
	tree_to_list_inorder(root_ptr->left, head_ptr, tail_ptr); // traverse down the tree to find the smallest number
	
	tree_to_list_inorder(root_ptr->right, head_ptr, tail_ptr); // move back along the tree
	}
}

void tree_to_list_postorder(const binary_tree_node* root_ptr, node*& head_ptr, node*& tail_ptr)
{
	if(root_ptr == nullptr) return;
	if(root_ptr != nullptr)
	{
	tree_to_list_inorder(root_ptr->left, head_ptr, tail_ptr); // traverse down the tree to find the smallest number
	
	tree_to_list_inorder(root_ptr->right, head_ptr, tail_ptr); // move back along the tree
	
	node* added_node = new node; // print out data at root send the data to the list
	added_node->data = root_ptr->data;
	
	if(head_ptr == nullptr) // null list
	{
		node* added_node = new node; // print out data at root send the data to the list
		added_node->data = root_ptr->data;
		head_ptr = added_node;
		head_ptr->next = nullptr;
		head_ptr->prev = nullptr;
		tail_ptr = head_ptr;
		}
	else // list cant be null if we get here because of above if
	{
		node* cursor = tail_ptr; // add at the tail
		tail_ptr = added_node;
		cursor->next = added_node;
		added_node->next = nullptr;
		added_node->prev = cursor;	
	}
	}
}

int main()
{
	srand(time(0));
	// make a random binary search tree
	binary_tree_node* root_ptr1 = nullptr;
	for (unsigned int k = 0; k < 10; ++k)
	{
		int num = rand() % 20;
		insert(root_ptr1, num);
	}
	cout << "Binary search tree " << endl;
	print(root_ptr1, 0);
	
	node* list_head_ptr = nullptr;
	node* list_tail_ptr = nullptr;
	cout << "In order " << endl;

	tree_to_list_inorder(root_ptr1, list_head_ptr, list_tail_ptr);
	print_list(list_head_ptr);
	clear_list(list_head_ptr, list_tail_ptr);
	
	list_head_ptr = nullptr;
	list_tail_ptr = nullptr;
	cout << "Pre order " << endl;	
	tree_to_list_preorder(root_ptr1, list_head_ptr, list_tail_ptr);
	print_list(list_head_ptr);
	clear_list(list_head_ptr, list_tail_ptr);
	
	list_head_ptr = nullptr;
	list_tail_ptr = nullptr;
	cout << "Post order " << endl;
	tree_to_list_postorder(root_ptr1, list_head_ptr, list_tail_ptr);
	print_list(list_head_ptr);
	clear_list(list_head_ptr, list_tail_ptr);
}
