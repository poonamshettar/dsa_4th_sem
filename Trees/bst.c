#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int s=0,x=0;
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

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

void preOrderTraversal(struct TreeNode* root,FILE *fp1) {
    if (root != NULL) {
        printf("%d ", root->data);
        fprintf(fp1,"%d ",root->data);
        preOrderTraversal(root->left,fp1);
        preOrderTraversal(root->right,fp1);
    }
}

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

struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            struct TreeNode* temp = minvalue(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void postOrderTraversal(struct TreeNode* root,FILE *fp3) {
    if (root != NULL) {
        postOrderTraversal(root->left,fp3);
        postOrderTraversal(root->right,fp3);
        printf("%d ", root->data);
        fprintf(fp3,"%d ",root->data);
    }
}

void generateRandomNumbers(int count) {
    FILE* file = fopen("random_numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        int number = rand() % 100;
        fprintf(file, "%d\n", number);
    }

    fclose(file);
}

int main() {
    generateRandomNumbers(5);
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
    root=deleteNode(root,data);
    inOrderTraversal(root,fp2);
    return 0;
}
