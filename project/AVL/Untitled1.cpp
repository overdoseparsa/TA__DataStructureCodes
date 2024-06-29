#include <iostream>
using namespace std;

class BTreeNode {
public:
    int data;
    BTreeNode* left;
    BTreeNode* right;
};





class BinaryTree {
public:
    BTreeNode* root;

    BinaryTree() {
        root = nullptr;
    }

    BTreeNode* createGTree() {
        // Implement the creation of the generic tree here
        return nullptr; // Placeholder return
    }

    BTreeNode* convertToBinaryTree(BTreeNode* genericNode) {
        if (genericNode == nullptr) {
            return nullptr;
        }

        BTreeNode* binaryNode = new BTreeNode;
        binaryNode->data = genericNode->data;

        binaryNode->left = convertToBinaryTree(genericNode->firstChild);
        binaryNode->right = convertToBinaryTree(genericNode->nextSibling);

        return binaryNode;
    }

    void printInOrder(BTreeNode* root) {
        if (root == nullptr) {
            return;
        }

        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
};

int main() {
    cout << "A quick tip: 'y' is for yes and 'n' is for no" << endl;

    BinaryTree binaryTree;

    GTreeNode* rootGeneric = binaryTree.createGTree(); // Call the createGTree function

    BTreeNode* rootBinary = binaryTree.convertToBinaryTree(rootGeneric);

    cout << "Inorder form of the binary tree: ";
    binaryTree.printInOrder(rootBinary);

    return 0;
}
