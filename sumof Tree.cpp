#include<iostream>
#include<stdio.h>
using namespace std;


struct node{
    int data;
    node *left,*right;
};

node *create(int data){
    node *tmp = new node;
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
void print(node *root){
     if(root==NULL)
        return;
     print(root->left);
     printf("%d\n",root->data);
     print(root->right);

}

int sumofvalue(node *root){
    if(root==NULL){
        return 0;
    }
    int val=root->data;
    root->data=sumofvalue(root->left)+sumofvalue(root->right);

    return root->data+val;

}


int main(){
        node *root=NULL;
        root=create(10);
        root->left=create(20);
        root->right=create(30);
        print(root);
        sumofvalue(root);
        print(root);
}
