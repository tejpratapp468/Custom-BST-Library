#include "BST.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Utility to print type names
template<typename T>
std::string getTypeName() {
    if (typeid(T) == typeid(int)) return "int";
    if (typeid(T) == typeid(float)) return "float";
    if (typeid(T) == typeid(char)) return "char";
    if (typeid(T) == typeid(std::string)) return "string";
    return "unknown";
}

// Generic CLI runner for any type T
template<typename T>
void runCLI() {
    BST<T> tree;
    std::string line, command;
    T value;

    std::cout << "=== Interactive BST CLI [" << getTypeName<T>() << "] ===\n";
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> command;

        if (command == "exit" || command == "quit") break;
        else if (command == "insert") {
            while (ss >> value) {
                tree.insert(value);
                std::cout << "Inserted: " << value << "\n";
            }
        } else if (command == "remove") {
            while (ss >> value) {
                if (tree.remove(value)) {
                    std::cout << "Removed: " << value << "\n";
                } else {
                    std::cout << value << " doesn't exist in BST\n";
                }
            }
        } else if (command == "exists") {
            if (ss >> value) {
                std::cout << (tree.exists(value) ? "Yes\n" : "No\n");
            }
        } else if (command == "inorder") {
            std::cout << "Inorder: " << tree.inorder() << "\n";
        }
        else if (command == "preorder") {
            std::cout << "Preorder: " << tree.preorder() << "\n";
        }
        else if (command == "postorder") {
            std::cout << "Postorder: " << tree.postorder() << "\n";
        }
        else if (command == "help") {
            std::cout << "Commands:\n";
            std::cout << "  insert <val1> <val2> ...   Insert values\n";
            std::cout << "  remove <val1> <val2> ...   Remove values\n";
            std::cout << "  exists <val>               Check if value exists\n";
            std::cout << "  inorder                    Print inorder traversal\n";
            std::cout << "  preorder                   Print preorder traversal\n";
            std::cout << "  postorder                  Print postorder traversal\n";
            std::cout << "  exit or quit               Exit the program\n";
        } else {
            std::cout << "Unknown command. Type 'help' for available commands.\n";
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./bst_cli [int|float|char|string]\n";
        return 1;
    }

    std::string type = argv[1];
    if (type == "int") runCLI<int>();
    else if (type == "float") runCLI<float>();
    else if (type == "char") runCLI<char>();
    else if (type == "string") runCLI<std::string>();
    else {
        std::cerr << "Unsupported type. Use: int, float, char or string.\n";
        return 1;
    }

    return 0;
}

