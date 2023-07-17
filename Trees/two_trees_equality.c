#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int equality(struct tree *root1, struct tree *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 != NULL && root2 != NULL)
    {
        return ((root1->data == root2->data) && equality(root1->left, root2->left) && equality(root1->right, root2->right));
    }
    return 0;
}
void main()
{
    struct tree *root1 = NULL;
    struct tree *root2 = NULL;
    int n, i, key, x;
    printf("Enter n");
    scanf("%d", &n);
    FILE *fp = fopen("random.txt", "w+");
    random(fp, n);
    rewind(fp);
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &key);
        root1 = insert(root1, key);
    }
    rewind(fp);
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &key);
        root2 = insert(root2, key);
    }
    inorder(root1);
    inorder(root2);
    if (equality(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
}