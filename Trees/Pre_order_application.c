#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
struct tree
{
    char data;
    struct tree *right, *left;
};

struct tree *create(int key)
{
    struct tree *newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->data = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

bool isoperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

struct tree *postfix_exp(char *postfix)
{
    char ch;
    struct tree *a[100];
    int i = -1;
    while (*postfix != '\0')
    {
        ch = *postfix;
        if (isalnum(ch))
        {
            struct tree *root = create(ch);
            a[++i] = root;
        }
        else if (isoperator(ch))
        {
            struct tree *rightop = a[i--];
            struct tree *leftop = a[i--];
            struct tree *op = create(ch);
            op->left = leftop;
            op->right = rightop;
            a[++i] = op;
        }
        postfix++;
    }
    return a[i];
}

void prefix_c(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->data);
    prefix_c(root->left);
    prefix_c(root->right);
}

void main()
{
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    struct tree *root = postfix_exp(postfix);
    printf("Prefix Conversion: ");
    prefix_c(root);
    printf("\n");
}