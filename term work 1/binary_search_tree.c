#include <stdio.h>
#include <stdlib.h>
#include<time.h>
// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the tree
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to perform pre-order traversal
void preOrderTraversal(struct TreeNode* root,FILE *fp1) {
    if (root != NULL) {
        printf("%d ", root->data);
        fprintf(fp1,"%d ",root->data);
        preOrderTraversal(root->left,fp1);
        preOrderTraversal(root->right,fp1);
    }
}

// Function to perform in-order traversal
void inOrderTraversal(struct TreeNode* root,FILE *fp2) {

    if (root != NULL) {
        inOrderTraversal(root->left,fp2);
        printf("%d ", root->data);
        fprintf(fp2,"%d ",root->data);
        inOrderTraversal(root->right,fp2);
    }
}

struct TreeNode* minvalue(struct Node* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct TreeNode* deletenode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deletenode(root->left, data);
    } else if (data > root->data) {
        root->right = deletenode(root->right, data);
    } else {
        // Case 1: No child or only one child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children
        struct TreeNode* temp = minvalue(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }

    return root;
}

// Function to perform post-order traversal
void postOrderTraversal(struct TreeNode* root,FILE *fp3) {
    if (root != NULL) {
        postOrderTraversal(root->left,fp3);
        postOrderTraversal(root->right,fp3);
        printf("%d ", root->data);
        fprintf(fp3,"%d ",root->data);
    }
}

// Function to generate random numbers and store them in a file
void generateRandomNumbers(int count) {
    FILE* file = fopen("random_numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        int number = rand() % 100; // Generating random numbers between 0 and 99
        fprintf(file, "%d\n", number);
    }

    fclose(file);
}

int main() {
    generateRandomNumbers(10); // Generate 10 random numbers
    struct timespec start, end;
    long long elapsed_ns;
    int data;
    FILE* file = fopen("random_numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;
    }
    FILE *fp1=fopen("pre.txt","w");
    FILE *fp2=fopen("ino.txt","w");
    FILE *fp3=fopen("post.txt","w");
    struct TreeNode* root = NULL;
    int number;

    // Read numbers from the file and insert them into the tree
    while (fscanf(file, "%d", &number) != EOF) {
        printf("%d ",number);
        root = insertNode(root, number);
    }
    printf("\n");
    fclose(file);
    printf("Pre-order traversal: ");
    preOrderTraversal(root,fp1);
    printf("\n");
    printf("In-order traversal: ");
    inOrderTraversal(root,fp2);
    printf("\n");
    printf("Post-order traversal: ");
    postOrderTraversal(root,fp3);
    printf("\n");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    printf("\nEnter node to be deleted: ");
    scanf("%d",&data);
    root=deletenode(root,data);
    inOrderTraversal(root,fp2);
    return 0;
}
