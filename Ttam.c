#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


int areMirrors(struct Node* root1, struct Node* root2) {

    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    
  
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
    
   
    return (root1->data == root2->data) &&
           areMirrors(root1->left, root2->right) &&
           areMirrors(root1->right, root2->left);
}

int main() {
   
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

  
    struct Node* root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);
    root2->right->left = newNode(5);
    root2->right->right = newNode(4);

   
    if (areMirrors(root1, root2)) {
        printf("\nThe two trees are mirror images of each other.\n");
    } else {
        printf("\nThe two trees are NOT mirror images of each other.\n");
    }

    return 0;
}




//input from user type programm


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


int areMirrors(struct Node* root1, struct Node* root2) {

    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    
   
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
    
    
    return (root1->data == root2->data) &&
           areMirrors(root1->left, root2->right) &&
           areMirrors(root1->right, root2->left);
}


struct Node* inputTree() {
    int data;
    printf("Enter data for node (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* node = newNode(data);
    printf("Enter left child of %d\n", data);
    node->left = inputTree();
    printf("Enter right child of %d\n", data);
    node->right = inputTree();
    
    return node;
}

int main() {
    printf("Input first tree:\n");
    struct Node* root1 = inputTree();

    printf("\nInput second tree:\n");
    struct Node* root2 = inputTree();

   
    if (areMirrors(root1, root2)) {
        printf("\nThe two trees are mirror images of each other.\n");
    } else {
        printf("\nThe two trees are NOT mirror images of each other.\n");
    }

    return 0;
}


