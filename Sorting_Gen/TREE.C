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
struct node * delete(struct node * root,int data);
struct node * min(struct node * root);
struct node * max(struct node * root);
void search(struct node * root,int data);
int countnode(struct node * root);
int height(struct node * root);


struct node * root;

int main(){
    //Insertion
    int y=1,val,ct,ht;
    printf("Funtion to create a BST !");
    do{
        printf("\nValue to insert:");
        scanf("%d",&val);
        root=insertnode(root,val);
        printf("Insert more ? (1/0) :");
        scanf("%d",&y);
    }
    while(y==1);
    
    //Traversal
    printf("\nInorder traversal (Ascending order):");
    inorder(root);
    printf("\nPreorder traversal :");
    preorder(root);
    printf("\nPostorder traversal :");
    postorder(root);
    printf("\nReverse order of tree (Descending order):");
    reverse(root);
    
    //Max & Min
    printf("\nMinimum node in tree %d",min(root)->data);
    printf("\nMaximum node in tree %d",max(root)->data);
    
    //Count of nodes
    ct=countnode(root);
    printf("\nNo of node present in tree : %d",ct);
    
    //Height of tree
    ht=height(root);
    printf("Height of the tree is : %d",ht);
    
    //Deletion of nodes
    printf("\nDeletion of tree nodes");
    do{
        printf("\nValue to delete:");
        scanf("%d",&val);
        root=delete(root,val);
        printf("\nAfter deletion:");
        inorder(root);
        printf("\nDelete more ? (1/0) :");
        scanf("%d",&y);
    }
    while(y==1);
    
    //Search for a node value
    printf("\nLets search for a node!...");
    do{
        printf("\nValue to search:");
        scanf("%d",&val);
        search(root,val);
        printf("\nSearch Another ? (1/0) :");
        scanf("%d",&y);
    }
    while(y==1);
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

struct node * delete(struct node *root,int data){
    
    if(root==NULL){
        return root;
    }
    else if(data<root->data&&root->left!=NULL){
        root->left=delete(root->left,data);
    }
    else if(data>root->data&&root->right!=NULL){
        root->right=delete(root->right,data);
    }
    else if(root->data==data){
        
        if(root->left==NULL){
            struct node * temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL){
            struct node * temp=root->left;
            free(root);
            return temp;
        }
        if(root->left!=NULL&&root->right!=NULL){
            struct node *temp=min(root->right);
            root->data = temp->data;               
            root->right = delete(root->right, temp->data); 
            return root;
        }
    }
    else{
        printf("No such value to delete");
    }
    return root;
}

struct node * min(struct node * root){
    if(root->left==NULL){
        return root;
    }
    return min(root->left);
}

struct node * max(struct node * root){
    if(root->right==NULL){
        return root;
    }
    return max(root->right);
}

void search(struct node * root,int data){
    if(root->data==data){
        printf("Data found!");
        return;
    }
    else if(root->data>data&&root->left!=NULL){
        search(root->left,data);
    }
    else if(root->data<data&&root->right!=NULL){
        search(root->right,data);
    }
    else{
        printf("Data not found...");
        return;
    }
}

int countnode(struct node * root){
    while(root==NULL){
        return 0;
    }
    return 1 + countnode(root->left)+countnode(root->right);
}

int height(struct node * root) {
    if (root == NULL) {
        return -1;  // Empty tree has height -1
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
