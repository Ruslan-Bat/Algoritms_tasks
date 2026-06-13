#include "func_09.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    deleteTree(root);
}


int AVLTree::height(Node* p) {
    return p ? p->height : 0;
}

int AVLTree::bfactor(Node* p) {
    return height(p->right) - height(p->left);
}

void AVLTree::fixheight(Node* p) {
    int hl = height(p->left);
    int hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}


Node* AVLTree::rotateRight(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

Node* AVLTree::rotateLeft(Node* q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

Node* AVLTree::balance(Node* p) {
    fixheight(p);
    
    if (bfactor(p) == 2) {
        if (bfactor(p->right) < 0) {
            p->right = rotateRight(p->right);
        }
        return rotateLeft(p);
    }
    
    if (bfactor(p) == -2) {
        if (bfactor(p->left) > 0) {
            p->left = rotateLeft(p->left);
        }
        return rotateRight(p);
    }
    
    return p; 
}


Node* AVLTree::insertNode(Node* p, int k) {
    if (!p) return new Node(k);
    
    if (k < p->key) {
        p->left = insertNode(p->left, k);
    } else if (k > p->key) {
        p->right = insertNode(p->right, k);
    } else {
        return p;
    }
    
    return balance(p); 
}

Node* AVLTree::findMin(Node* p) {
    return p->left ? findMin(p->left) : p;
}

Node* AVLTree::removeMin(Node* p) {
    if (p->left == nullptr) return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

Node* AVLTree::removeNode(Node* p, int k) {
    if (!p) return nullptr;
    
    if (k < p->key) {
        p->left = removeNode(p->left, k);
    } else if (k > p->key) {
        p->right = removeNode(p->right, k);
    } else {
        Node* q = p->left;
        Node* r = p->right;
        delete p;
        
        if (!r) return q;
        
        Node* min = findMin(r);
        min->right = removeMin(r);
        min->left = q;
        
        return balance(min);
    }
    return balance(p);
}

void AVLTree::deleteTree(Node* p) {
    if (p != nullptr) {
        deleteTree(p->left);
        deleteTree(p->right);
        
        delete p;
    }
}


void AVLTree::Insert(int key) {
    root = insertNode(root, key);
}

void AVLTree::Remove(int key) {
    root = removeNode(root, key);
}

bool AVLTree::Find(int key) {
    Node* current = root;
    while (current) {
        if (current->key == key) return true;
        current = (key < current->key) ? current->left : current->right;
    }
    return false;
}
