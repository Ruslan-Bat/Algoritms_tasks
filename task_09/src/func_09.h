#pragma once

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
    
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* p);
    int bfactor(Node* p);
    void fixheight(Node* p);
    Node* rotateRight(Node* p);
    Node* rotateLeft(Node* q);
    Node* balance(Node* p);
    Node* insertNode(Node* p, int k);
    Node* removeNode(Node* p, int k);
    Node* findMin(Node* p);
    Node* removeMin(Node* p);
    void deleteTree(Node* p); 

public:
    AVLTree(); 
    ~AVLTree();
    
    void Insert(int key);
    bool Find(int key);
    void Remove(int key);
};