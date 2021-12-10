#include <iostream>
#include "bst.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    bst b;
    b.insert(10);
    b.insert(9);
    b.insert(50);
    if(b.exists(1)) cout<<"ram ";
    b.remove(10);
    auto s=b.inorder();
    cout<<s;
	return 0;
}
