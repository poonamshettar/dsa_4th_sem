
#include<stdio.h>
#include<stdlib.h>
int i=0,j=0;
struct tree
{
    int key;
    struct tree *right,*left;
    int height;
};

int random(int n, FILE *fp)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        x=rand()%100;
        fprintf(fp, "%d ",x);
    }
}

int height(struct tree *root)
{
    if(root==NULL)
        return 0;
     return root->height;
}

int getbalance(struct tree*root)
{
    if(root==NULL)
        return 0;
    return height(root->left)-height(root->right);
}

int max(int a,int b)
{
    return(a>b)?a:b;
}


struct tree* minvalue(struct tree*root)
{
    if(root->left!=NULL)
    {
        minvalue(root->left);
    }
    return root;
}

struct tree*right_rotate(struct tree*y)
{
    i++;
    struct tree*x=y->left;
    struct tree*t2=x->right;
    x->right=y;
    y->left=t2;
    x->height=max(height(x->right),height(x->left))+1;
    y->height=max(height(y->right),height(y->left))+1;
    return x;

}

struct tree*left_rotate(struct tree*x)
{
    j++;
 struct tree*y=x->right;
 struct tree*t2=y->left;
 y->left=x;
 x->right=t2;
 x->height=max(height(x->right),height(x->left))+1;
 y->height=max(height(y->right),height(y->left))+1;
return y;
}

struct tree* create(int key)
{
 struct tree *newnode=(struct tree*)malloc(sizeof(struct tree));
 newnode->key=key;
 newnode->right=newnode->left=NULL;
 newnode->height=1;
 return newnode;
}

struct tree* insert(struct tree*root,int key)
{ //printf("%d ",key);
    if(root==NULL)
       return create(key);
    if(root->key>key)
        root->left=insert(root->left,key);
    else if(root->key<key)
        root->right=insert(root->right,key);
    else
        return root;

    root->height=max(height(root->left),height(root->right))+1;
    int balance=getbalance(root);

    if(balance>1&&key<root->left->key)
        return right_rotate(root);

    if(balance<-1&&key>root->right->key)
            return left_rotate(root);

    if(balance>1&&key>root->left->key)
    {
            root->left=left_rotate(root->left);
            return right_rotate(root);
    }

    if(balance<-1&&key<root->right->key)
    {
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}


struct tree*delete_node(struct tree*root,int key)
{
 if(root==NULL)
        return root;
 if(key<root->key)
    root->left=delete_node(root->left,key);
 else if(key>root->key)
    root->right=delete_node(root->right,key);
 else
 {
     if((root->left==NULL)||(root->right==NULL))
     {
         struct tree*temp=root->left?root->left:root->right;
         if(temp==NULL)
         {
             temp=root;
             root=NULL;
         }
         else
         {
             *root=*temp;
             free(temp);
         }

     }
     else
     {
         struct tree*temp=minvalue(root->right);
         root->key=temp->key;
         root->right=delete_node(root->right,temp->key);
     }
 }
 if(root==NULL)
    return root;

 root->height=max(height(root->left),height(root->right))+1;
 int balance=getbalance(root);
 if(balance>1&&getbalance(root->left)>=0)
    return right_rotate(root);
 if(balance>1&&getbalance(root->left)<0)
 {
    root->left=left_rotate(root->left);
    return right_rotate(root);
 }
 if(balance<-1&&getbalance(root->right)<=0)
    return left_rotate(root);
 if(balance<-1&&getbalance(root->right)>0)
 {
    root->right=right_rotate(root->right);
    return left_rotate(root);
 }
 return root;

}

void pre_disp(struct tree*root)
{
    if(root!=NULL)
    {
    printf("%d ",root->key);
    pre_disp(root->left);
    pre_disp(root->right);
    }
}

void in_disp(struct tree*root)
{
    if(root!=NULL)
    {
       in_disp(root->left);
       printf("%d ",root->key);
       in_disp(root->right);
    }
}

void post_disp(struct tree*root)
{
    if(root!=NULL)
    {
        post_disp(root->left);
        post_disp(root->right);
        printf("%d ",root->key);
    }
}

void disp(struct tree *root,int space)
{
    if(root==NULL)
        return;
    space+=10;
    disp(root->right,space);
    printf("\n");
    for(int i=10;i<=space;i++)
        printf(" ");
    printf("%d\n",root->key);
    disp(root->left,space);
}

int check1(struct tree *root)
{
    if (root == NULL)
        return;
    return (check1(root->left) == check1(root->right)) ? 1 : 0;
}

void check(int count, int i)
{
    if (count == pow(2, i) - 1)
        printf("\nperfect binary tree\n");
    else if (count != pow(2, i) - 1)
        printf("\ncomplete binary tree\n");
}

void main()
{
    struct tree *root = NULL;
    int x, n;
    srand(time(NULL));
    FILE *fp = fopen("random.txt", "w+");
    FILE *fp1 = fopen("pre.txt", "w");
    FILE *fp2 = fopen("in.txt", "w");
    FILE *fp3 = fopen("post.txt", "w");
    printf("Enter no of nodes:");
    scanf("%d", &n);
    random(n, fp);
    rewind(fp);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &x);
        root = insert(root, x);
    }
    disp(root, 0);
    if (height(root->left) == height(root->right))
    {
        if (check1(root))
        {
            check(n, log(n - 1) + 2);
        }
    }
    else
        printf("\nDegenerate\n");


}

