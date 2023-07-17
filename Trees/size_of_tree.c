#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int x = 0;
struct tree
{
    int data;
    struct tree *right, *left;
};

void random(FILE *fp, int n)
{
    int i;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", rand() % 100);
    }
}

struct tree *create(int data)
{
    struct tree *newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->data = data;
    newnode->right = newnode->left = NULL;
    return newnode;
}

struct tree *insert(struct tree *root, int value)
{
    if (root == NULL)
    {
        return create(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}
void inorder(struct tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int size(struct tree *root)
{
    if (root == NULL)
        return x;
    x = size(root->left) + 1 + size(root->right);
}
void main()
{

    int n, i, key, x;
    struct tree *root = NULL;
    printf("Enter n");
    scanf("%d", &n);
    FILE *fp = fopen("random.txt", "w+");
    random(fp, n);
    rewind(fp);
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &key);
        root = insert(root, key);
    }
    inorder(root);
    printf("\n%d ", size(root));
}