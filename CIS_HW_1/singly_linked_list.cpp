#include "singly_linked_list.h"

using namespace std;

 /*
 #include "singly_linked_list.h"

using namespace std;

void add_node(node*& head_ptr, const int& payload)
{
	node* added_node = new node;
	added_node->data = payload;
	if (head_ptr == nullptr)
	{
		head_ptr = added_node;
		added_node->next = nullptr;
	}
	else
	{
		if (head_ptr->data > payload)
		{
			added_node->next = head_ptr;
			head_ptr = added_node;
		}
		else
		{
			node* cursor = head_ptr;
			while (cursor != nullptr && cursor->next != nullptr && cursor->next->data < payload)
				cursor = cursor->next;
			if (cursor->next == nullptr)
			{	
				cursor->next = added_node;
				added_node->next = nullptr;
			}	
			else
			{
				added_node->next = cursor->next;
				cursor->next = added_node;
			}
		}
	}		
}

bool remove_node(node*& head_ptr, const int& target)
{
	if (head_ptr == nullptr) return false;
	
	node* removed_node_ptr = head_ptr;	
	if (removed_node_ptr->data == target)
	{
		head_ptr = head_ptr->next;
		delete removed_node_ptr;
		removed_node_ptr = nullptr;
		return true;
	}
	
	while (removed_node_ptr != nullptr && 
		removed_node_ptr->next != nullptr &&
		removed_node_ptr->next->data != target)
		removed_node_ptr = removed_node_ptr->next;
		
	if (removed_node_ptr != nullptr &&
		removed_node_ptr->next != nullptr)
	{
		node* next_node_ptr = removed_node_ptr->next->next; 
		delete removed_node_ptr->next;
		removed_node_ptr->next = next_node_ptr;
		return true;
	}
		
	return false;	
}

void clear_list(node*& head_ptr)
{
	node* destroyed_node_ptr;
	while (head_ptr != nullptr)
	{
		destroyed_node_ptr = head_ptr;
		head_ptr = head_ptr->next;
		delete destroyed_node_ptr;
	}
}

void print_list(const node*& head_ptr)
{
	const node* printed_node_ptr = head_ptr;
	while (printed_node_ptr != nullptr)
	{
		cout << printed_node_ptr->data << " ";
		printed_node_ptr = printed_node_ptr->next;
	}
	cout << endl;
}

bool find_list(const node*& head_ptr, const int& target)
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

void copy_list(const node*& source_ptr, node*& dest_ptr)
{
	clear_list(dest_ptr);
	if (source_ptr == nullptr)
		return;
	dest_ptr = new node();
	dest_ptr->data = source_ptr->data;
	dest_ptr->next = nullptr;
	node* cursor = dest_ptr;
	while (source_ptr->next != nullptr)
	{
		source_ptr =  source_ptr->next;
		cursor->next = new node();
		cursor->next->data = source_ptr->data;
		cursor->next->next = nullptr;
		cursor = cursor->next;
	}
}
 */ 

void add_node(node*& head_ptr, const int& payload) // if,else if or individual for loops?
 // same result but different process
{
	if(head_ptr == nullptr) // If list is empty make a new node
	{
		empty = new node; // new node code here
		empty->data = payload; // need to add the data
		empty->next = nullptr;
		empty = head_ptr;
	}
	
	else if(head_ptr->next == target) // walk the list until the correct position is found
	{
		last = new node;
		last->data = payload; // need to add the data
		head_ptr->next = last;
		last->next = target;
	}
	
	else if(head_ptr) // new node before first node
	{
		first = new node;
		first->data = payload;
		first->next = head_ptr;
		head_ptr = first;
		//head_ptr->payload;
	}
	
	sort(head_ptr); // function to sort the nodes
	
	 /* node* added_node = new node;
	 added_node->data = payload;
	 
	 if(head_ptr == nullptr)
	 { 
	 head_ptr = added_node;
	 added_node->next = nullptr
	 }
	 else 
	 {
	 node* cursor = head_ptr;
	 while(cursor != nullptr && cursor->next != nullptr && cursor->next->data < payload)
	 if(cursor->next == nullptr)
	 {
	 cursor->next = added_node;
	 added_node->next = nullptr;
	 }
	 else
	 {
	 added_node->next = cursor->next;
	 cursor->next = added_node;
	 }
	 
	 */
	 
	return 0;
}

bool remove_node(node*& head_ptr, const int& target)
{

/*
if(head_ptr == nullptr) return false;
node* removed_node_ptr = head_ptr;
if(removed_node_ptr->data == target)
{
head_ptr = head_ptr->next;
delete removed_node_ptr;
removed_node_ptr = nullptr
return true;
}
while(removed_node_ptr != nullptr && removed_node_ptr->next != nullptr && removed_node_ptr->next->data != target)
removed_node_ptr = removed_node_ptr->next;
*/
	if(target* == head_ptr) // remove nodes
	{
		node* temp = head_ptr;
		head_ptr = head_ptr->next;
		delete temp;
	}
	
	else if(target* == nullptr)
	{
		node* temp2 = new node;
		temp2->next = nullptr;
		target->next;
	}
	
	else if(head_ptr->next == target) // case 3 extra?
	{
		
	}
	
	return false;
}

bool find_list(const node*& head_ptr, const int& target)
{
	on_node = new node;// coding
	on_node = head_ptr
	
	if(on_node == nullptr)
	{
		return 0;
	}
	else
	{
		while(on_node != target && on_node != nullptr)
		{
		// on_node point to next node
		on_node = head_ptr->next
		}
	 
		if(on_node->data == target)
		{
			return on_node;
		}
		else
		{
		return 0;
		}
	}
}

void clear_list(node*& head_ptr)
{
	while(head_ptr != nullptr) // clear list
	{
		node* remove = head_ptr;
		head_ptr = remove->next;
		delete remove;
	}
}

void print_list(const node*& head_ptr)
{
	const node* cursor = head_ptr;
	while (cursor != nullptr) // print from current position
	{
		cout << cursor->data << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

void copy_list(const node*& source_ptr, node*& dest_ptr)
{
	 // copy the list
}

void sort(node*& head_ptr)
{
	for(unsigned int i = 0; (i < 10) && (head_ptr != nullptr); head_ptr = head_ptr->next, ++i) // sort code
	{
		for(unsigned int k = 0; k < 10; ++k)
		{
			while(head_ptr > head_ptr->next)
		{
			swap(head_ptr, head_ptr->next); // again just swap the data and leave the pointers
		}
	}
}

void swap(head_ptr->data&, head_ptr->next.data&)
{
	int = t3;
	t3 = t1;
	t1 = t2;
	t2 = t3;
	 // redo the pointer so the order is the same?
	 // do i need to include the preceding and following pointers to keep the order?
	 //just swap the data and leave the pointers
}
