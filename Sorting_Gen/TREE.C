#include<stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data);
struct node * insertnode(struct node * root,int data);
void inorder(struct node * root);
void preorder(struct node *root);
void postorder(struct node * root);
void reverse(struct node * root);

struct node * root;

int main(){
    int y=1,val;
    printf("Funtion to create a BST !");
    do{
        printf("\nValue to insert:");
        scanf("%d",&val);
        root=insertnode(root,val);
        printf("\nInsert more ? (1/0) :");
        scanf("%d",&y);
    }
    while(y==1);
    printf("\nInorder traversal (Ascending order):");
    inorder(root);
    printf("\nPreorder traversal :");
    preorder(root);
    printf("\nPostorder traversal :");
    postorder(root);
    printf("\nReverse order of tree (Descending order):");
    reverse(root);
}

struct node * createnode(int data){
    struct node * nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
struct node * insertnode(struct node * root,int data){
    if(root==NULL){
        root=createnode(data);
    }
    if(data<root->data){
        root->left=insertnode(root->left,data);
    }
    else if(data>root->data){
        root->right=insertnode(root->right,data);
    }
    else{
        return root;
    }
    return root;
}
void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void reverse(struct node * root){
    if(root!=NULL){
        reverse(root->right);
        printf("%d ",root->data);
        reverse(root->left);
    }
}

