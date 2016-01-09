#include "doubly_linked_list.h"

using namespace std;

void add_node(node*& head_ptr, node*& tail_ptr, const char& payload)
{
	node* added_node = new node;
	added_node->data = payload;
	// adding to an empty list
	if (head_ptr == nullptr)
	{
		head_ptr = added_node;
		added_node->next = nullptr;
		added_node->prev = nullptr;
		tail_ptr = head_ptr;
	}
	else
	{
		// adding a new head node
		if (head_ptr->data > payload)
		{
			added_node->next = head_ptr;
			added_node->prev = nullptr;
			// BUG FIXED
			head_ptr->prev = added_node;
			head_ptr = added_node;
		}
		else
		{
			// adding a node after the head node
			node* cursor = head_ptr;
			while (cursor != nullptr && cursor->next != nullptr 
				&& cursor->next->data < payload)
				cursor = cursor->next;
			// adding to the end of the list
			if (cursor->next == nullptr)
			{	
				tail_ptr = added_node;
				cursor->next = added_node;
				added_node->next = nullptr;
				added_node->prev = cursor;
			}	
			// adding before the end of the list
			else
			{
				added_node->next = cursor->next;
				added_node->prev = cursor;
				// BUG FIXED
				cursor->next->prev = cursor;
				cursor->next = added_node;
			}
		}
	}		
}

bool remove_node(node*& head_ptr, node*& tail_ptr, const char& target)
{
	if (head_ptr == nullptr) return false;
	
	node* removed_node_ptr = head_ptr;	
	// check if we are removing the head node
	if (removed_node_ptr->data == target)
	{
		if (head_ptr->next == nullptr)
			tail_ptr = nullptr;
		head_ptr = head_ptr->next;
		
		if (head_ptr != nullptr)
			head_ptr->prev = nullptr;
		
		delete removed_node_ptr;
		removed_node_ptr = nullptr;
		return true;
	}
	
	// look for the node to remove after the head node
	while (removed_node_ptr != nullptr && 
		removed_node_ptr->next != nullptr &&
		removed_node_ptr->next->data != target)
		removed_node_ptr = removed_node_ptr->next;
		
	// stop here before the node to remove
	if (removed_node_ptr != nullptr &&
		removed_node_ptr->next != nullptr)
	{
		node* next_node_ptr = removed_node_ptr->next->next; 
		delete removed_node_ptr->next;
		removed_node_ptr->next = next_node_ptr;
		// removing a node other than the tail
		if (next_node_ptr != nullptr)
			next_node_ptr->prev = removed_node_ptr;
		// removing the tail node
		else
			tail_ptr = removed_node_ptr;
		return true;
	}
	else
		return false;	
}

bool find_list(const node* head_ptr, const char& target)
{
	const node* cursor = head_ptr;
	while (cursor != nullptr)
	{
		if (cursor->data == target)
			return true;
		cursor = cursor->next;
	}
	return false;
}

void clear_list(node*& head_ptr, node*& tail_ptr)
{
	node* destroyed_node_ptr;
	while (head_ptr != nullptr)
	{
		destroyed_node_ptr = head_ptr;
		head_ptr = head_ptr->next;
		delete destroyed_node_ptr;
	}
	tail_ptr = nullptr;

}

void print_list(const node* head_ptr)
{
	const node* cursor = head_ptr;
	while (cursor != nullptr)
	{
		cout << cursor->data << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

void print_list_backwards(const node* tail_ptr)
{
	const node* cursor = tail_ptr;
	while (cursor != nullptr)
	{
		cout << cursor->data << " ";
		cursor = cursor->prev;
	}
	cout << endl;
}

void copy_list(const node* source_head_ptr,
	node*& dest_head_ptr, node*& dest_tail_ptr)
{
	clear_list(dest_head_ptr, dest_tail_ptr);
	if (source_head_ptr == nullptr)
		return;
	dest_head_ptr = new node();
	dest_head_ptr->data = source_head_ptr->data;
	dest_head_ptr->next = nullptr;
	// define the prev pointer for the destination's head
	dest_head_ptr->prev = nullptr;
	dest_tail_ptr = dest_head_ptr; 
	node* cursor = dest_head_ptr;
	while (source_head_ptr->next != nullptr)
	{
		source_head_ptr = source_head_ptr->next;
		cursor->next = new node();
		cursor->next->data = source_head_ptr->data;
		cursor->next->next = nullptr;
		// set the previous pointer for the node we just made
		cursor->next->prev = cursor;
		cursor = cursor->next;
		dest_tail_ptr = cursor;
	}
}

