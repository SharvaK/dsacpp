#include<iostream>
using namespace std;

struct Node{
    int key;
    struct Node *left,*right;
};

//create a node
struct Node *newNode(char k){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

bool isFullBinTree(struct Node *root){
    //Checking for emptiness
    if(root == NULL)
       return true;
    
    //cehck children nodes exist
    if(root->left == NULL && root->right == NULL)
       return true;

    if((root->left)&&(root->right))
       return (isFullBinTree(root->left)&& isFullBinTree(root->right));
    return false;         
}

int main(){
 struct Node *root = NULL;
 root = newNode(1);
 root->left = newNode(2);
 root->right = newNode(3);

 root->left->left = newNode(4);
 root->left->right = newNode(5);

 root->left->right->left = newNode(6);
 root->left->right->right = newNode(7);

 if(isFullBinTree(root))
    cout<<"it is full binary tree";
 else
    cout<<"it is not full binary tree";   
}