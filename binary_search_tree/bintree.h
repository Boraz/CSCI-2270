
#include <cstdlib>  // Provides NULL and size_t


	struct binary_tree_node	
	{
			int data;
			binary_tree_node *left;
			binary_tree_node *right;
	};

	void print(binary_tree_node* node_ptr, unsigned int depth);

	void tree_clear(binary_tree_node*& root_ptr);

	binary_tree_node* tree_copy(const binary_tree_node* root_ptr);

	unsigned int tree_size(const binary_tree_node* node_ptr);
