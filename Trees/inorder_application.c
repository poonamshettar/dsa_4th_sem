#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int k = 0;
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

struct tree *create(int key)
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = key;
    temp->right = temp->left = NULL;
    return temp;
}
struct tree *insert(struct tree *root, int key)
{
    if (root == NULL)
    {
        return create(key);
    }
    else if (root->data > key)
    {
        root->left = insert(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = insert(root->right, key);
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

void kth_largest(struct tree *root, int kth)
{
    if (root != NULL)
    {
        kth_largest(root->left, kth);
        k++;
        if (k == kth)
        {
            printf("%d ", root->data);
        }
        kth_largest(root->right, kth);
    }
}
void kth_smallest(struct tree *root, int kth)
{
    if (root != NULL)
    {
        kth_smallest(root->right, kth);
        k++;
        if (k == kth)
        {
            printf("%d ", root->data);
        }
        kth_smallest(root->left, kth);
    }
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
    printf("\n");
    printf("enter the kth smallest and largest element to be found");
    scanf("%d", &x);
    kth_largest(root, x);
    k = 0;
    kth_smallest(root, x);
    fclose(fp);
}