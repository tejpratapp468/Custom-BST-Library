#include <iostream>
#include "bst.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	bst *root = new bst({10,2,30});
//	root->insert(20);
//	root->insert(35);
//	root->insert(12);
	std::cout<<root->inorder()<<endl;
	root->remove(35);
	std::cout<<root->inorder();
	std::cout<<root->preorder();
	std::cout<<root->postorder();
	return 0;
}
