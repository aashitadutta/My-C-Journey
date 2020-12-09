#include<iostream>
#include<bits/stdc++.h>
#define MIN 0
#define MAX 999
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    
};

node* addNewNode(int data){
    node* newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

node* insertNode(node* root, int data){
    
    if(root==NULL){
        root = addNewNode(data);
        return root;
    }

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp){
            if(temp->left==NULL){
                temp->left = addNewNode(data);
                return root;
            }
            else{
                q.push(temp->left);
            }
            if(temp->right==NULL){
                temp->right = addNewNode(data);
                return root;
            }
            else{
                q.push(temp->right);
            }
        }
        
    }
    
    return root;
}

bool bst(node* root, node* left, node* right){
    if(root==NULL){
        return true;
    }
    if((left && left->data >= root->data) || (right && right->data <= root->data)){
        return false;
    }

    return bst(root->left, left, root) && bst(root->right, root, right);       
}

bool checkBST(node* root){
    return bst(root, NULL, NULL);
}

int main(){
    int n;
    cin>>n;
    node *root=NULL;
    int a[n];
    for(int i=0; i<n; i++){
         cin>>a[i];
     }
     for(int i=0; i<n; i++){
     root = insertNode(root, a[i]);
     }

    if(checkBST(root)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}