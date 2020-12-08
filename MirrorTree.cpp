/* Author - Aashita Dutta
To check if tree is palindromic or not for given binary tree
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//structure to define node in tree with data and left and right pointers
struct node{
	int data;
	node* left;
	node* right;
};

//function to generate new node
node* generateNewNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

//function to insert node in tree
node* insert(node* root, int data){
	//if root is itself null then create node for root
	if(root==NULL){
		root = generateNewNode(data);
		return root;
	}
	//data structure for level order input in the tree using queue
	//queue stores all the nodes of tree
	queue<node*> q;
	//push root node to queue
	q.push(root);
	//inserting node using queue
	while(!q.empty()){
		//create temporary node to store popped values from queue for search purpose
		node* temp = q.front();
		//pop the first node inside from queue
		q.pop();
		//check for current popped node
		if(temp!=NULL){
			if(temp->left == NULL){
				//generate new node if left child is null
				temp->left = generateNewNode(data);
				return root;
			}
			else{
				//push the node to queue
				q.push(temp->left);
			}
			if(temp->right==NULL){
				//generate new node if left child is null
				temp->right = generateNewNode(data);
				return root;
			}
			else{
				//push the node to queue
				q.push(temp->right);
			}
		}
	}
	return root;
}

//function to check if root nodes of left and right subtrees are mirror images of each other or not
bool checkMirrorTree(node* root1, node* root2){
	bool value=false;
	//if both the subtrees are empty or their data value is -1 then return true
	if(root1 == NULL && root2 == NULL || (root1->data == -1 && root2->data == -1)){
		value = true;
		return value;
	}
	//if any one of the roots of subtrees is null then tree is not palindromic
	if(root1 == NULL || root2 == NULL){
		value = false;
		return value;
	}
	//if both subtrees exists
	if(root1 && root2){
		//if data of roots of both subtrees are equal
		if(root1->data == root2->data){
			//return true if left child of left subtree is equal to right child of right subtree
			//and if right child of left subtree is equal to left child of right subtree
			value = checkMirrorTree(root1->left, root2->right)&& 
			checkMirrorTree(root1->right, root2->left);
			return value;
		}
	}	
	
	return value;
}

//function to check if given binary tree is palindromic or symmetric or not
bool isPalindrome(node* root){
	//call to function to check if tree is mirror image or not
	return checkMirrorTree(root, root);
}

//driver code to take user input
int main(){
	node* root;
	root = NULL;
	int n;
	cout<<"Enter the number of nodes:"<<endl;
	cin>>n;
	cout<<"Enter values of nodes to check if tree is palindome:"<<endl;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	//call to insert function according to user input values in array
	for(int i=0; i<n; i++){
		root = insert(root, a[i]);
	}
	
	//call to function to check if tree is mirror image of itself or not
	//vertically mirrored at root
	if(!isPalindrome(root)){
		cout<<"Tree is not palindromic"<<endl;
	}
	else{
		cout<<"Tree is palindromic"<<endl;
	}
}
