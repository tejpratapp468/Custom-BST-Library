# Binary Search Tree (BST) CLI

An interactive, template-based Binary Search Tree (BST) implementation in C++. This project allows users to insert, remove, and search elements, and perform tree traversals for different data types via a simple command-line interface.

---

## 📁 Files Included

- `BST.hpp` – Template BST implementation with insertion, deletion, traversal, and utility functions.
- `Node.hpp` – Node structure used in the BST.
- `main.cpp` – CLI program that takes a data type argument and launches an interactive session.

---

## 🚀 Getting Started

### 🔧 Compile

```bash
g++ -std=c++17 main.cpp -o bst_cli
```

### ▶️ Run

Choose the data type you want to work with:

```bash
./bst_cli int
./bst_cli float
./bst_cli char
```

---

## 🕹️ CLI Commands

Once you're in the interactive CLI:

| Command          | Description                                  |
|------------------|----------------------------------------------|
| `insert <val>`   | Insert one or more values                    |
| `remove <val>`   | Remove one or more values                    |
| `exists <val>`   | Check if a value exists                      |
| `inorder`        | Print inorder traversal                      |
| `preorder`       | Print preorder traversal                     |
| `postorder`      | Print postorder traversal                    |
| `help`           | Show list of available commands              |
| `exit` / `quit`  | Exit the program                             |

Example session:

```
> insert 10 5 15
> inorder
5 10 15
> exists 7
No
> remove 5
> inorder
10 15
```

---

## ✅ Usage & Benefits

### 🔧 **Usage**

This project provides a hands-on way to interact with a **Binary Search Tree** using a simple terminal interface. It allows you to:

- Learn how **BST operations** like insertion, deletion, and search behave.
- Visualize how **different traversal orders** work (`inorder`, `preorder`, `postorder`).
- Test your algorithms across **multiple data types** (`int`, `float`, `char`) without changing the core code.
- Quickly **prototype or debug** logic for data structures assignments or interviews.

### 🌟 **Benefits**

| Feature                     | Benefit                                                                 |
|----------------------------|-------------------------------------------------------------------------|
| 🧩 **Template-based design**   | Write once, use with any data type—flexible and reusable.                |
| 🖥️ **Interactive CLI**         | Experiment in real-time, no need to recompile after every change.        |
| 🔄 **Dynamic insertion/removal** | Simulates real-world usage of BSTs, such as dynamic datasets.           |
| 🧠 **Educational Tool**         | Great for visualizing traversal and understanding tree structure.       |
| 🧹 **Automatic memory handling** | Clean up memory using destructors—no leaks, even with dynamic trees.     |
| ➕ **Operator overloading**     | Makes the tree more intuitive and STL-like: `tree + value` is valid.     |

---

## ⚡ Efficiency & Low Latency with Templates

Templates in C++ aren't just about code reuse—they also provide **performance advantages** that directly impact efficiency and runtime behavior of this BST project:

### 🚀 **1. Compile-Time Type Resolution**
- All operations (insert, remove, search, traversal) are **resolved at compile-time** for the specific type (`int`, `float`, `char`).
- This eliminates the need for dynamic type checking (like with polymorphism or void pointers), resulting in **faster function calls** and **zero runtime overhead**.

### 🧠 **2. Inline Expansion by the Compiler**
- Since template functions are often defined in headers, compilers can inline them where appropriate.
- This reduces function call overhead, especially in tight loops during traversal or recursive operations.

### 🧺 **3. No Virtual Table Overhead**
- Unlike class hierarchies using `virtual` methods, template-based designs **avoid v-tables** and virtual dispatch.
- Every operation is concrete and type-specific, which leads to **cache-friendly, branch-predictable code**.

### 🏗️ **4. Lightweight Instantiations**
- Only the types actually used (`int`, `float`, `char`) are instantiated.
- The compiler generates **tailored, minimal versions** of the BST class for each type, keeping the binary lean and memory-efficient.

### 🧬 **5. Strong Typing Improves Optimization**
- The compiler knows the exact data types being manipulated, so it can apply **better optimizations**, like loop unrolling, constant folding, and better register allocation.

---

## 📬 Feedback

Feel free to open an issue or submit a pull request if you'd like to contribute or suggest improvements!

