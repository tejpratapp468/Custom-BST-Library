#include "node.h"
#include "bst.h"
#include <string>
using namespace std;

void traversal(node*,string&,int);
node* insertUtil(node*,const int);
node* removeUtil(node*,const int);
bool existsUtil(node*,const int);
void copyUtil(node*&,node*);
void destroyUtil(node*);

//<-------------------constructors------------------------------->
bst::bst()
{
	root = nullptr;
}
bst::bst(int data)
{
	this->root = new node;
	this->root->data = data;
	this->root->left = nullptr;
	this->root->right = nullptr;
}
bst::bst(const bst& tree)
{
	copyUtil(this->root,tree.root);
}

bst::bst(const vector<int>& v)
{
	for(int i=0;i<v.size();i++)
	{
		insert(v[i]);
	}
}

//<-------------------------------------Destructor--------------------------------------------->
bst::~bst()
{
	destroyUtil(root);
}

//<-----------------------------------Methods in BST ---------------------------------------->
void bst::insert(int data)
{
	if(root==nullptr)
	{
		root = new node;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
	}
	else{
		insertUtil(root,data);
	}
}

void bst::remove(int key)
{
	if(exists(key))
	{
		removeUtil(root,key);
	}
}

bool bst::exists(int key)
{
	return existsUtil(this->root,key);
}


string bst::preorder() const
{
	string ret = "";
	traversal(root,ret,1);
	return ret;
}

string bst::inorder() const
{
	string ret = "";
	traversal(this->root,ret,2);
	return ret;
}

string bst::postorder() const
{
	string ret = "";
	traversal(root,ret,3);
	return ret;
}

bst& bst::operator+(int data)
{
	bst *temp = new bst(*this);//*pointer=value of pointer
	temp->insert(data);
	return *temp;
}

bst& bst::operator=(const bst &tree)
{
	copyUtil(root,tree.root);
	return *this;
}
//<---------------------------------------------- Utiities--------------------------------------------------------------->

//<---------------------------------------------- insert a node with given data--------------------------------------------------------------->
node* insertUtil(node *root,const int data)
{
	if(root==nullptr)
	{
		node*p = new node;
		p->data = data;
		p->left = nullptr;
		p->right = nullptr;
		return p;
	}
	if(data<root->data)
	{
		root->left = insertUtil(root->left,data);
	}
	else{
		root->right = insertUtil(root->right,data);
	}
	return root;
}

//<----------------------------------------Check if a node with given key value exist or not---------------------------------------------------->
bool existsUtil(node* root,const int key)
{
	if(root==nullptr)
	{
		return false;
	}
	return root->data==key || existsUtil(root->left,key) || existsUtil(root->right,key);
}

//<----------------------------------------remove a node with given key value---------------------------------------------------->

node* removeUtil(node* root,const int key)
{
	if(root==nullptr) return nullptr;
	if(root->data==key)
	{
		if(root->left==nullptr && root->right==nullptr)
		{
			delete(root);
			return root=nullptr;
		}
		else if(root->left && root->right)
		{
			node* temp = root->right;
			while(temp->left)
			{
				temp=temp->left;
			}
			root->data = temp->data;
			root->right = removeUtil(root->right,temp->data);
		}
		else{
			node *temp=root->left?root->left:root->right;
			delete(root);
			root=nullptr;
			return temp;
		}
	}
	else if(root->data<key)
	{
		root->right = removeUtil(root->right,key);
	}
	else{
		root->left = removeUtil(root->left,key);
	}
	return root;
}

//<---------------------------------------------- Traversals--------------------------------------------------------------->
void traversal(node *root,string &ret,const int type)
{
	if(root==nullptr) return;
	if(type==1)
	{
		ret+= to_string(root->data) + " ";
		traversal(root->left,ret,type);
		traversal(root->right,ret,type);
	}
	else if(type==2)
	{
		traversal(root->left,ret,type);
		ret+= to_string(root->data) + " ";
		traversal(root->right,ret,type);
	}
	else if(type==3)
	{
		traversal(root->left,ret,type);
		traversal(root->right,ret,type);
		ret+= to_string(root->data) + " ";
	}
}

//<------------------------------------ Initialising a bst  with another tree----------------------------------->
void copyUtil(node*&root,node* tree)
{
	if(tree==nullptr)
	{
		root=nullptr;
	}
	else{
		root = new node;
		root->data = tree->data;
		root->left = nullptr;
		root->right = nullptr;
		copyUtil(root->left,tree->left);
		copyUtil(root->right,tree->right);
	}
}

//<------------------------------------ Destroying/deleting ou tree----------------------------------->
void destroyUtil(node *root)
{
	if(root==nullptr) return;
	destroyUtil(root->left);
	destroyUtil(root->right);
	
	delete(root);
	root=nullptr;
}



