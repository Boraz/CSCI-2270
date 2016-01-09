#include <iostream>

struct node {
	char data;
	node* next;
	node* prev;
};

void add_node(node*& head_ptr, node*& tail_ptr, const char& payload);

bool remove_node(node*& head_ptr, node*& tail_ptr, const char& target);

void print_list(const node* head_ptr);

void print_list_backwards (const node* tail_ptr);

bool find_list(const node* head_ptr, const char& target);

void clear_list(node*& head_ptr, node*& tail_ptr);

void copy_list(const node* source_head_ptr,
	node*& dest_head_ptr, node*& dest_tail_ptr);

