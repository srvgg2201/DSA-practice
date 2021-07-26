#include<iostream>
#include<queue>
using namespace std;

class BST {
    int data;
    BST *left;
    BST *right;

    public:
    BST() {
        data = 0;
        left = right = NULL;
    }

    BST(int val) {
        data = val;
        left = right = NULL;
    }

    BST* insert(BST* root, int val) {
        if(!root) {                 //tree is empty, fill first node.
            return new BST(val);
        }
        if(val < root->data) {
            //insert to the left, because value to be inserted is less than root key

            root->left = insert(root->left, val);
        }
        else {
            // insert to the right, because value to be inserted is greater than root key

            root->right = insert(root->right, val);
        }
        return root;
    }

    void print_inorder(BST* root) {
        if(!root) {
            return;
        }
        print_inorder(root->left);  //left
        cout << root->data << " ";  //root
        print_inorder(root->right); //right

    }
    
};

int main() {
    BST b;
    BST* root = NULL;
    root = b.insert(root, 30); 
    b.insert(root, 40);
    b.insert(root, 20);
    b.insert(root, 50);
    b.insert(root, 60);
    b.insert(root, 10);
    b.print_inorder(root);
    
}