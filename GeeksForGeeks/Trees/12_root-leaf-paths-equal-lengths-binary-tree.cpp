// C++ program to count root to leaf paths of different 
// lengths. 
#include<bits/stdc++.h> 
using namespace std; 

/* A binary tree node */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

/* utility that allocates a new node with the 
given data and NULL left and right pointers. */
struct Node* newnode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

// Function to store counts of different root to leaf 
// path lengths in hash map m. 
void pathCountUtil(Node *node, unordered_map<int, int> &m, 
											int path_len) 
{ 
	// Base condition 
	if (node == NULL) 
		return; 

	// If leaf node reached, increment count of path 
	// length of this root to leaf path. 
	if (node->left == NULL && node->right == NULL) 
	{ 
		m[path_len]++; 
		return; 
	} 

	// Recursively call for left and right subtrees with 
	// path lengths more than 1. 
	pathCountUtil(node->left, m, path_len+1); 
	pathCountUtil(node->right, m, path_len+1); 
} 

// A wrapper over pathCountUtil() 
void pathCounts(Node *root) 
{ 
// create an empty hash table 
unordered_map<int, int> m; 

// Recursively check in left and right subtrees. 
pathCountUtil(root, m, 1); 

// Print all path lenghts and their counts. 
for (auto itr=m.begin(); itr != m.end(); itr++) 
	cout << itr->second << " paths have length "
		<< itr->first << endl; 
} 

// Driver program to run the case 
int main() 
{ 
	struct Node *root = newnode(8); 
	root->left = newnode(5); 
	root->right = newnode(4); 
	root->left->left = newnode(9); 
	root->left->right = newnode(7); 
	root->right->right = newnode(11); 
	root->right->right->left = newnode(3); 
	pathCounts(root); 
	return 0; 
} 
