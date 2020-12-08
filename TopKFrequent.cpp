/* Author- Aashita Dutta 
Program to find the top k most frequent elements in the list of integers */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* This function will give the repeating numbers count i.e. frequency */
map<int,int> countFrequency(int arr[], int size)
{
	map<int, int> frequencyMap;
	for(int i=0; i<size; i++)
	{
		frequencyMap[arr[i]]++;   //this map will store the elements as key with their frequency as value
	}
	return frequencyMap;
}

/*structure that implements the operator overloading
  Third parameter in priority queue.*/
struct comp
{
	bool operator()(const pair<int,int> &a, const pair<int,int> &b)
	{
		/*returns true if priority value i.e.frequency of first parameter is considered to go before b.
		This defines the heap property and implement as max heap.*/
		return a.second < b.second;   
		
	}
};

//Function that implements priority queue and gives top k most frequent element by popping the elements in non-increasing way
void mostFrequent(int arr[], int size, int top)
{

	map<int,int> freq_map = countFrequency(arr,size);
	
	
/* Priority queue is implementation for Max-Min heap data structure with comparator defines it as max or min. By default its max heap
priority queue at any time returns the head with highest priority. So the priorityvalue here is frequency of each element
So the top k frequenct elements will be stored in queue according to the priority defined by their frequency.
First parameter is - type of elements
Second parameter - type of internal underlying object where the elements are stored- its a pair- having element and their frequency
Third parameter- compare functor that takes two parameter and returns a bool*/
	priority_queue<int, vector<pair<int,int> >, comp> element_queue(freq_map.begin(), freq_map.end()); 
	
			
	int i=0;
	cout<<"Top "<<top<<" most frequent elements of array are:"<<endl;
	while(i<top)
	{
		//output the top element of priority queue with value as element itself without popping
		
		cout<<element_queue.top().first<<endl;  
		//after returning the element with highest priority, 
		//pop the element from queue and replace with next element in queue with next highest priority
		element_queue.pop();                    
		i++;                 //incremennt i to get the next most frequent element
	}
}

int main()
{
	int k=0;
	cout<<"Enter the size of array: ";
	int n;
	cin>>n;
	cout<<"Enter the elements of array in integers: ";
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter how many top frequent numbers you want: ";
	cin>>k;
	
	//call to the function to find top K most frequent element 
	mostFrequent(arr, n, k);

}
