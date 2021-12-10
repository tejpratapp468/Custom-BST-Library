#pragma once
#include "node.h"
#include <string>
#include<vector>
using namespace std;

class bst{
	private:
		node *root;
	public:
		bst();
		bst(int);
		bst(const bst&);
		bst(const vector<int>&);
		~bst();
		void insert(int);
		void remove(int);
		bool exists(int);
		string preorder() const;
		string inorder() const;
		string postorder() const;
		
		bst& operator+(int);
		bst& operator=(const bst&);
};
