#pragma once
#include "Node.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template<typename T>
class BST { // Binary Search Tree
	private:
	Node<T>* root = nullptr;

	// Helper functions
	Node<T>* insertUtil(Node<T>*, const T& val);
	Node<T>* removeUtil(Node<T>*, const T& val);
	bool existsUtil(Node<T>*, const T& val) const;

	void preorderUtil(Node<T>* node, std::stringstream& result) const;
        void inorderUtil(Node<T>* node, std::stringstream& result) const;
        void postorderUtil(Node<T>* node, std::stringstream& result) const;

	void copyUtil(Node<T>*& dest, Node<T>* src) const;
	void destroyUtil(Node<T>* node);

	public:
	// Constructors and Destructor
	BST();
	BST(const T& val);
	BST(std::vector<T>& values);
	BST(const BST<T>& other);
	~BST();

	// Methods in BST
	void insert(const T& val);
	bool remove(const T& val);
	bool exists(const T& val) const;
	
	std::string preorder() const;
    	std::string inorder() const;
    	std::string postorder() const;

	//Operator Overloads
	BST<T>& operator+(const T& val);
	BST<T>& operator=(const BST<T>& other);
};

// --------------------- IMPLEMENTATION ---------------------

template<typename T>
BST<T>::BST() : root(nullptr) {}

template<typename T>
BST<T>::BST(const T& val){
	root = new Node<T>(val);
}

template<typename T>
BST<T>::BST(const BST<T>& tree) {
	copyUtil(root, tree.root);
}

template<typename T>
BST<T>::BST(std::vector<T>& values) {
	for (const auto& val : values) {
		insert(val);
	}
}

template<typename T>
BST<T>::~BST() {
	destroyUtil(root);
}

// Public methods
template<typename T>
void BST<T>::insert(const T& val) {
	root = insertUtil(root, val);
}

template<typename T>
bool BST<T>::remove(const T& val) {
	if (exists(val)) {
		removeUtil(root, val);
		return true;
	}
	return false;
}

template<typename T>
bool BST<T>::exists(const T& val) const {
	return existsUtil(root, val);
}

template<typename T>
std::string BST<T>::preorder() const {
	std::stringstream result;
	preorderUtil(root, result);
	return result.str();
}

template<typename T>
std::string BST<T>::inorder() const {
	std::stringstream result;
	inorderUtil(root, result);
	return result.str();
}

template<typename T>
std::string BST<T>::postorder() const {
	std::stringstream result;
	postorderUtil(root, result);
	return result.str();
}

template<typename T> 
BST<T>& BST<T>::operator+(const T& val) {
	insert(val);
	return *this;
}

template<typename T> 
BST<T>& BST<T>::operator=(const BST<T>& other) {
	if (this != &other) {
		destroyUtil(root);
		copyUtil(root, other.root);
	}
	return *this;
}

// ------------------ Helpers ------------------

template<typename T>
Node<T>* BST<T>::insertUtil(Node<T>* node, const T& val) {
	if (!node) {
		node = new Node<T>(val);
		return node;
	}
	if (node->data > val) {
		node->left = insertUtil(node->left, val);
	} else {
		node->right = insertUtil(node->right, val);
	}
	return node;
} 

template<typename T>
Node<T>* BST<T>::removeUtil(Node<T>* node, const T& val) {
	if (!node) return nullptr;

	if (node->data > val) {
		node->left = removeUtil(node->left, val);
	} else if (node->data < val) {
		node->right = removeUtil(node->right, val);
	} else {
		if (!node->left and !node->right) {
			delete node;
			return nullptr;
		} else if (node->left && node->right) {
			Node<T>* successor = node->right;
			while (successor->left) {
				successor = successor->left;
			}
			node->data = successor->data;
			node->right = removeUtil(node->right, successor->data);
		} else {
			Node<T>* child = (node->left ? node->left : node->right);
			delete node;
			return child;
		}
	}
	return node;
} 

template<typename T>
bool BST<T>::existsUtil(Node<T>* node, const T& val) const {
	if (!node) return 0;
	if (node->data < val) {
		return existsUtil(node->right, val);
	} else if (node->data > val) {
		return existsUtil(node->left, val);
	}
	return true;
}

template<typename T>
void BST<T>::preorderUtil(Node<T>* node, std::stringstream& result) const {
	if (!node) return;
	result << node->data << " ";
	preorderUtil(node->left, result);
	preorderUtil(node->right, result);
}

template<typename T>
void BST<T>::inorderUtil(Node<T>* node, std::stringstream& result) const {
	if (!node) return;
	inorderUtil(node->left, result);
	result << node->data << " ";
	inorderUtil(node->right, result);
}

template<typename T>
void BST<T>::postorderUtil(Node<T>* node, std::stringstream& result) const {
	if (!node) return;
	postorderUtil(node->left, result);
	postorderUtil(node->right, result);
	result << node->data << " ";
}

template<typename T>
void BST<T>::copyUtil(Node<T>*& dest, Node<T>* src) const{
	if (!src) {
		dest = src;
		return;
	}
	dest = new Node<T>(src->data);
	copyUtil(dest->left, src->left);
	copyUtil(dest->right, src->right);
}

template<typename T>
void BST<T>::destroyUtil(Node<T>* node) {
	if (node == nullptr) return;
	destroyUtil(node->left);
	destroyUtil(node->right);
	delete node;
}
