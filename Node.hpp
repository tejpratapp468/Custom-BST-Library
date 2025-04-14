#pragma once

template<typename T>
struct Node {
   T data;
   Node<T>* left;
   Node<T>* right;

   Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
};
