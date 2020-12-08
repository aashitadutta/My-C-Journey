/** Author - Aashita Dutta
Implement a sorted list X using linked list that supports the following operations:
(1) Inserting an element in the list in its correct position; (2) Deleting an element from the list if present;
(3) reporting the median element of the list. If the size of the list is even, then your program should
return the average of two median element.**/

#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

//structue to define node
struct node {
	int data;
	node* link;
};

//function to print list
void printList(node* head){
	node* curr = head;
	while(curr){
		cout<<curr->data<<" ";
		curr = curr->link;
	}
	cout<<endl;
}

//function to get the size of list
int listSize(node* head){
	int count = 0;
	node* curr = head;
	while(curr){
		curr= curr->link;
		count++;
	}
	return count;
}

//function to insert at its correct position in the list
//maintain the sorting of list
//compare the element with node's data and insert into its correct place
node* insertNode(node** head, int data){
	//generate new node
	node* newNode = new node;
	newNode->data = data;
	newNode->link = NULL;
	//if list is empty
	if(*head == NULL){
		*head = newNode;
		return *head;
	}
	node* curr = *head;      //pointer to list
	//setting flags
	bool beg = false;
	bool mid = false;
	bool end = false;
	//if list has only one node
	if(curr->link==NULL){
		if(curr->data <= newNode->data){       //if element is larger than node's data
			curr->link = newNode;
			newNode->link = NULL;
			return *head;
		}
		else{                                  //if element is less than node's data
			newNode->link = curr; 
			*head = newNode;
			return *head;
		}
	}
	
	//if list has more than one node
	else{
		//maintain two pointers to list
		node* first = curr;
		node* second = curr->link;
		//loop until end of list is not reached
		while(second){
			if(newNode->data <= first->data){        //if element is less than or equal to first node's data
				beg = true;
				break;	
			}
			//if element to be inserted is at last
			if(newNode->data >= second->data && second->link==NULL){    
				end = true;
				break;
			}
			//if element is somewhere in middle of list
			if(newNode->data >= first->data && newNode->data <= second->data){
				mid = true;
				break;	
			}
			//update the pointers
			first = second;
			second = second->link;
	
		}
		//insert the node in the beginning position of list
		if(beg == true){
			newNode->link = first;
			*head = newNode;
		}
		//insert the node in the end position of list
		if(end==true){
			second->link = newNode;
			newNode->link = NULL;
		}
		//insert the node in the middle position of list
		if(mid == true){
			newNode->link = second;
			first->link = newNode;
		}
			
	}
	return *head;
}

//function to delete element from the list by finding its correct position and maintaining the sorted list
void deleteNode(node** head, int data){
	//if list is empty
	if(*head==NULL){
		cout<<"NULL";
		return;
	}
	//if element to be deleted is in the beginning of list
	if((*head)->data==data){
		 *head = (*head)->link;
		 return;
	}
	
	//maintain two pointers to the list
	node* first = *head;
	node* second = (*head)->link;
	//loop until end of list is not reached
	while(second){
		if(second->data == data){     //if element to be deleted is in the middle or end of the list
			first->link = second->link;
			delete second;
			return;
		}
		//update the pointers
		first = second;
		second = second->link;
				
	}
	cout<<"NULL"<<endl;
	return;
}
//function to find median of the list

float findMedian(node** head){
	//if list is empty
	if(*head==NULL){
		cout<<"NULL";
		return 0;
	}
	//get the size of the list
	int size = listSize(*head);
	float data; 
	int median =0;
	//if list ahs only one node then median is itself that node
	if(size==1){
		data = (*head)->data;
	}
	
	//compute the median
	//if size of list is odd
	if(size%2!=0){
		median = (size+1)/2;
	}
	//if sise is even
	else{
		median = size/2;
	}
	
	//set one pointer to list
	node* curr = *head;
	//iterate from array as 1 index
	int i=1;
	bool flag = false;
	//iterate till you reach median position of list
	while(i<=median){
		//update pointer
		curr = curr->link;
		i++;
		//break when you reach median position
		if(i==median){
			flag = true;
			break;	
		}
	}
	if(flag==true){
		//if size of list is odd then median position data is median
		if(size%2!=0){
			data=curr->data;
		}
		//if list size is even then get the average of two elements at positions median and median+1
		else{
			int data1 = curr->data;
			curr = curr->link;
			int data2 = curr->data;
			data = (data1+data2)/2.0;
		}
		
	}
	return data;
}

int main(){
	//string input from user as 3A2A4A2DM
	string str;
	cin>>str;
	node* list = NULL;
	node* newlist = NULL;
	float median;
	int j=0;
	int n=0;
	string s;
	char input;
	//interate till the string end is not reached
	while(j<str.length()){
		//if string has character as 'M'
		if(str.at(j)=='M'){
			input = 'M';   
			j++;
		}
		else{
			s="";
			//iterate to find if string has more than one digits
			for(int i=j; i<str.length(); i++){
				if(str.at(i)>=48 && str.at(i)<=57){     //comparing the ASCII value for digits(0-9) as 48-57
					s += str.at(i);                     //append the character to empty string
				}
				else 
				if(str.at(i)>=65 && str.at(i)<=90){     //comparing the ASCII value for capital Alphabets(A-Z) as 65-90   
					input = str.at(i);                  //update the input
					j = ++i;                         
					break;                              //break from for loop when you encounter first non-digit character
				}
			}
			//convert the string of digits we got in for loop into integer
			stringstream ss(s);
			ss >> n;
		}
		//switch for each alphabets A for Addition, D for Deletion and M for Median
		switch(input){
			case 'A':
				newlist = insertNode(&list, n);                //call insert function
				printList(newlist);
				break;
			
			case 'D':
				deleteNode(&list, n);                          //call delete function
				printList(list); 
				break;
				
			case 'M':
				median = findMedian(&list);                    //call median function
				cout<<median<<endl;
				break;	
		}
	
	}
	
	
}
