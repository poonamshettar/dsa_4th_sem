#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
struct tree
{
    char data;
    struct tree *right, *left;
};
struct tree *create(char data)
{
    struct tree *newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->data = data;
    newnode->right = newnode->left = NULL;
    return newnode;
}

struct tree *create_tree(char *exp)
{
    struct tree *a[100];
    char ch;
    int i = -1;
    ;
    while (*exp != '\0')
    {
        ch = *exp;
        if (isdigit(ch))
        {
            struct tree *root = create(ch);
            a[++i] = root;
        }
        else
        {
            struct tree *op = create(ch);
            op->left = a[i--];
            op->right = a[i--];
            a[++i] = op;
        }
        exp++;
    }
    return a[i];
}

int evaluate(struct tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data - '0';
    }
    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    switch (root->data)
    {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    default:
        printf("Invalid operator\n");
        return 0;
    }
}

int main()
{
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    struct tree *root = create_tree(postfix);
    int result = evaluate(root);
    printf("Expression Tree Evaluation: %d\n", result);

    return 0;
}