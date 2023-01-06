#include<stdlib.h>
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};


// New node creation
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

//Traverse preorder
void traversePreOrder( struct node *temp){
if (temp != NULL){
    cout<<" "<<temp->data;
    traversePreOrder(temp ->left);
    traversePreOrder(temp->right);
}
}

//Traverse Inorder
void traverseInOrder(struct node *temp){
    if(temp != NULL){
        traverseInOrder(temp->left);
        cout<<" "<<temp->data;
        traverseInOrder(temp->right);
    }
}

//Traverse Post Order
void traversePostOrder(struct node *temp){
    if(temp != NULL){
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout<<" "<<temp->data;
    }
}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    cout<<"\npre-order traversal: ";
    traversePreOrder(root);
    cout<<"\nin-order traversal:";
    traverseInOrder(root);
    cout<<"\npost-order traversal:";
    traversePostOrder(root);
}
