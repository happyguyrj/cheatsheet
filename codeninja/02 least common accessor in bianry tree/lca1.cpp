#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};

Node * newNode(int k) {
    Node *temp = new Node;
    temp->key = k;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int findLCA(Node *root, int n1, int n2) {
    if (root == NULL) {
        return -1;
    }

    if (root->key == n1 || root->key == n2) {
        return root->key;
    }

    int left = findLCA(root->left, n1, n1);
    int right = findLCA(root->right, n1, n2);

    if (left != -1 && right != -1) {
        return root->key;
    }
    else if (left != -1) {
        return left;
    }
    else {
        return right;
    }
}

int main() {
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);

   return 0;
}