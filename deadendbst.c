           #include <stdio.h>
#include <stdlib.h>

// Structure to represent a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check if the BST contains any dead end
int containsDeadEnd(struct Node* root, int min, int max) {
    // Base case: if the node is NULL, there is no dead end
    if (root == NULL) {
        return 0;
    }

    // If the node is a leaf (no children), it's a dead end
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Check recursively if any of the subtrees contains a dead end
    // For left child, we update the max value, and for right child, we update the min value
    return containsDeadEnd(root->left, min, root->data - 1) || containsDeadEnd(root->right, root->data + 1, max);
}

// Function to check if the BST contains dead end or not
int checkDeadEnd(struct Node* root) {
    // Start the search with the full range of possible values for the BST nodes
    return containsDeadEnd(root, 1, 1000);  // Adjust the max as per the constraints of your tree
}

int main() {
    // Example BST:
    //          50
    //         /  \
    //        30   70
    //       /  \  /  \
    //      20   40  60  80

    struct Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    // Check if the BST contains a dead end
    if (checkDeadEnd(root)) {
        printf("The BST contains a dead end.\n");
    } else {
        printf("The BST does NOT contain a dead end.\n");
    }

    return 0;
}
