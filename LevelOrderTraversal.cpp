/* Author - Aashita Dutta
Given a binary tree, print all its elements level by level
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//structure to define node in tree with data and left and right pointers
struct binaryNode{
	int data;
	binaryNode *left;
	binaryNode *right;
	
};

//function to generate new node
binaryNode* getNewNode(int data){
	binaryNode* newNode = new binaryNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//function to insert node in tree
binaryNode* insert(binaryNode* root, int data){
	if(root==NULL){
		root = getNewNode(data);
		return root;
	}
	queue<binaryNode*> binaryQueue;
	binaryQueue.push(root);
	while(!binaryQueue.empty()){
		binaryNode* t = binaryQueue.front();
		binaryQueue.pop();
	if(t!=NULL){
		if(t->left==NULL){
			t->left = getNewNode(data);
			return root;
		}
		else{
			binaryQueue.push(t->left);
		}
		if(t->right==NULL){
			t->right = getNewNode(data);
			return root;
		}
		else{
			binaryQueue.push(t->right);
		}
		}
	}
	return root;
}

//function that calculates maximum depth of the tree
int maxHeight(binaryNode* root){
	int max_height;
	if(root==NULL){
		return 0;
	}
	else{
		int left = maxHeight(root->left);
		int right = maxHeight(root->right);
		max_height = max(left, right)+1;
	}
	return max_height;
}

//function that prints the nodes level by level
void printLevel(binaryNode* root, int level){
	if(root==NULL){
		return;
	}
	if(level==1){
		if(root->data==-1){
			cout<<"NULL"<<" ";
		}
		else{
			cout<<root->data<<" ";
		}
	}
	else if(level>1){
		//recursive calls to nodes of left and right subtree with level going down by 1
		printLevel(root->left, level-1);    
		printLevel(root->right, level-1);
	}
}

//function to call print level function and maxHeight function 
//calls the printlevel functio till it reaches the max depth of the tree
void levelOrderTree(binaryNode* root){
	int height = maxHeight(root);
	for(int i=1; i<=height; i++){
		printLevel(root, i);
		cout<<endl;
	}
}

//driver code
int main(){
	binaryNode* root;
	root = NULL;
	cout<<"Enter the number of nodes you want in binary tree:"<<endl;
	int n;
	cin>>n;
	int a[n];
	cout<<"Enter the data value of nodes:"<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	for(int i=0; i<n; i++){
		root = insert(root, a[i]);
	}
	if(a[0]==-1){
		cout<<"Null tree"<<endl;
		return 0;
	}
	cout<<endl;
	//print the nodes through level order traversal
	levelOrderTree(root);
}
