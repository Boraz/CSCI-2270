#include <iostream>

struct node {
	int data;
	node* next;
};

bool remove_node(node*& head_ptr, const int& target);

void add_node(node*& head_ptr, const int& payload);

void clear_list(node*& head_ptr);

void print_list(const node*& head_ptr);

bool find_list(const node*& head_ptr, const int& target);

void copy_list(const node*& source_ptr, node*& dest_ptr);
