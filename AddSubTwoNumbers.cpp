	#include <iostream>
	#include<sys/time.h>
	using namespace std;
	
	//structure to form node
	struct node{
		int data;
		node* next;
	};
	
	//utility function to print
	void print(node* head){
		node* curr = head;
		while(curr!=NULL){
			cout<<curr->data;
			curr = curr->next;
		}
	}
	
	//utility function to add node in linked list
	node* addNode(node** head, int data){
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		//add new node if linked list is null
		if(*head==NULL){
			*head = newNode;
			return *head;
		}
	    //appending new node at last	
		node* curr = *head;
		//traverse through linked list till last node
		while(curr->next){
			curr = curr->next;
		}
		//make last node's null point to new node
		curr->next = newNode;
		return *head;
	}
	
	
	//reverse the linked list
	void reverseList(node** head){
		node* current = *head;
		node* prev = NULL;
		node* next = NULL;
		while(current){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*head = prev;
	}
	
	//get list size
	int listSize(node* head){
		int count = 0;
		node* current = head;
		while(current){
			current = current->next;
			count++;
		}
		return count;
	}
	
	//make both linked lists of same size by appending zeroes at end
	node* makeSameSize(node* list1, node* list2, int lsize1, int lsize2){
		node* sameNode = NULL;
		int difference;
		if(lsize1<lsize2){
			difference = lsize2 - lsize1;
			for(int i=0;i<difference;i++){
				sameNode = addNode(&list1, 0);
			}
			
		}
		else{
			difference = lsize1 - lsize2;
			for(int i=0;i<difference;i++){
				sameNode = addNode(&list2, 0);
			}
		}
		return sameNode;
	}
	
	//addition function of two lists
	node* addTwoLists(node* head1, node* head2, int listSize1, int listSize2){
		//reverse list before addition
		reverseList(&head1);
	    reverseList(&head2);
	    makeSameSize(head1, head2, listSize1, listSize2);
		node* addList = NULL; 
		node* newList = NULL;                   //final list to store result
		int carry = 0;
		int div, remainder, sum;
		//perform addition
		while(head1 && head2){
			sum = carry + head1->data + head2->data;   //sum of node1's data and node2's data with carry
			div = sum/10;                              //to detect carry
			remainder = sum % 10;
			if(div!=0){
				carry = 1; 
				newList = addNode(&addList,remainder);            //add node with remainder as result
			}
			else{
				carry = 0;
				newList = addNode(&addList,sum);                //add node with sum as result
			}
			if(head1){
				head1 = head1->next;
			}
			if(head2){
				head2 = head2->next;
			}
		}
		//if last result contains carry then add that node
		if(carry>0){
			newList = addNode(&addList,carry);
		}
		//reverse the final list
		reverseList(&newList);
		return newList;
	}
	
		
	//To detect larger list out of two lists for subtraction 
	node* largerList(node* firstList, node* secondList, int size1, int size2){
		
		node* head1 = firstList;
		node* head2 = secondList;
		node* larger=NULL;
		node* smaller = NULL;
		if(size1 != size2){
			if(size1 > size2){
				larger = head1;
			}
			else{
				larger = head2;
			}
			if(size1<size2){
				smaller = head1;
			}
			else{
				smaller = head2;
			}
		}
		else{
		while(firstList && secondList){
		if(firstList->data != secondList->data){
		if(head1->data > head2->data){
			larger = head1;
		}
		else{
			larger = head2;
		}
		if(head1->data < head2->data){
			smaller = head1;
		}
		else{
			smaller = head2;
		}
		break;
	  }
		firstList = firstList->next;
		secondList = secondList->next;
	}
		
	}
	    return larger;
	}
	//subtraction of numbers in linked list
	
	node* subTwoLists(node* lnode, node* snode, int size1, int size2){
		node* large= NULL;
		node* newVal = NULL;
		node* subList = NULL;
		bool borrow = false;
		int subtract;
	    large = largerList(lnode, snode, size1, size2);  //capture the head for the largest list
		if(snode==large){                                //swap the pointer so that first list is always the larger list
			node* temp =  lnode;
			lnode = snode;
			snode = temp;
	}
		//reverse both lists before subtraction
	    reverseList(&lnode);
	    reverseList(&snode);
		makeSameSize(lnode, snode, size1, size2);
		
		//performing subtraction
	    while(lnode!=NULL && snode!=NULL){
	    	if(borrow){                          //if borrow is true decrement the data of first list by one
			lnode->data = lnode->data-1;
			borrow=false;
			}
			
	    	if(lnode && snode && lnode->data < snode->data){
	    		borrow = true;
	    		lnode->data = lnode->data+10;       //if data of list 1 is less than data of list 2 then increament list1's data by 10
	    		
			}
			subtract = (lnode->data)-(snode->data);   //perform subtraction
		 	newVal = addNode(&subList,subtract);
		 	//update the values
		 	if(lnode)
			lnode = lnode->next;
			if(snode)
			snode = snode->next;
			
		}
		//reverse the final answer
		reverseList(&newVal);
	
	    return newVal;
	    
	}
	
	int trimLeadingZeros(int arr[], int len){
		int firstNonZero=-1; 
		for(int i=0; i<len; i++){
		if(arr[i] != 0){
			firstNonZero = i;
			break;
			}
		}
		
		
		return firstNonZero;
	}

	//function to add string1 into array 
	//returning array to arrays to list function
	int* addfirstStringsToArray(string s1, int* s1size){
		int arr1[s1.length()];
		for(int i=0;i<s1.length();i++){
			arr1[i] = s1[i]-'0';
		}
		//trim leading zeros for array 1 if any
		int firstNonZeroIndex1 = trimLeadingZeros(arr1, s1.length());
		int newIndex1 = s1.length() - firstNonZeroIndex1;
		int* newArr1 = new int[newIndex1];
		//int newArr1[newIndex1];
		for(int i=0; i<newIndex1; i++){
			newArr1[i] = arr1[firstNonZeroIndex1+i];
		}
		*s1size = newIndex1;
	   return newArr1;
	}
	
	//function to add string2 into array 
	//returning array to arrays to list function
		int* addSecondStringsToArray(string s2, int* s2size){
		int arr2[s2.length()]; 
		for(int i=0;i<s2.length();i++){
			arr2[i] = s2[i]-'0';
		}
	    //trim leading zeros for array2 if any
		int firstNonZeroIndex2 = trimLeadingZeros(arr2, s2.length());
		int newIndex2 = s2.length() - firstNonZeroIndex2;
		int* newArr2 = new int[newIndex2];
		//int newArr2[newIndex2];
		for(int i=0; i<newIndex2; i++){
			newArr2[i] = arr2[firstNonZeroIndex2+i];
		}
		*s2size = newIndex2;
		return newArr2;
	}
	
	void arraysToListAdd(string s1, string s2){
		int size1, size2;
		int *arr1 = addfirstStringsToArray(s1, &size1);
		int *arr2 = addfirstStringsToArray(s2, &size2);
		node* list1 = NULL;
		node* list2 = NULL;
		node* addList1 = NULL;
		node* addList2 = NULL;
		node* newListAdd = NULL;
		for(int i=0; i<size1;i++){
			addList1 = addNode(&list1, *(arr1+i));
		}
		
			for(int i=0; i<size2;i++){
			addList2 = addNode(&list2, *(arr2+i));
		}
		
		int addListSize1 = listSize(addList1);
	    int addListSize2 = listSize(addList2);
		//call add two list function
		newListAdd = addTwoLists(addList1, addList2, addListSize1, addListSize2);
		cout<<"Addition result of two numbers: "<<endl;
		print(newListAdd);
		cout<<endl;
		
	}
	
		void arraysToListSub(string s1, string s2){
		int size1, size2;
		int *arr1 = addfirstStringsToArray(s1, &size1);
		int *arr2 = addfirstStringsToArray(s2, &size2);
		node* list1 = NULL;
		node* list2 = NULL;
		node* subList1 = NULL;
		node* subList2 = NULL;
		node* newListSub = NULL;
		for(int i=0; i<size1;i++){
			subList1 = addNode(&list1, *(arr1+i));
		}
		
			for(int i=0; i<size2;i++){
			subList2 = addNode(&list2, *(arr2+i));
		}
		
	   int subListSize1 = listSize(subList1);
	   int subListSize2 = listSize(subList2);
	    //subtraction using linked list
	    newListSub = subTwoLists(subList1, subList2, subListSize1, subListSize2);
	    cout<<"Subtraction result of two numbers: "<<endl;
	    print(newListSub);
		cout<<endl;
		
	}
	int main(){
		struct timeval start,stop;    //struct timeval objects 
		long duration;              //variable to calculate difference between start and stop time of execution
		string s1, s2;
		cin>>s1;
		cin>>s2;
		gettimeofday(&start, NULL);        //get system time
		//call to convert arrays elements to list for addition function
		arraysToListAdd(s1, s2);
		//call to convert arrays elements to list for subtraction function
		arraysToListSub(s1, s2);
		gettimeofday(&stop, NULL);
	    duration = (stop.tv_usec) - (start.tv_usec);  //calculating time in microseconds
	    cout<<"Time elapsed "<<duration<<endl;
	return 0;
	}
