/** Author - Aashita Dutta
To print all the subsets of a given set S of integers with elements in sorted order 
that contains a particular element given as user input**/

#include<iostream>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;

//to find subsets for the remaining n-1 elements(i.e. except the element that we want in list)
vector<vector<int> > subset(int a[], int n){
	//compute power set function
	int count = pow(2, n);
	vector<vector<int> > newArr;
	//for each subset and elements in power set, push the subsets into vector of vector
	for(int i=0; i<count; i++){
		vector<int> row;
		for(int j=0; j<n; j++){
			if(i & (1<<j)){                //if j'th bit in i is set 
				row.push_back(a[j]);       //push this element into row vector
			}
		}
		//push row in newArr vector of vector
		newArr.push_back(row);
	}

	return newArr;
}

//function to print deisred subsets with particular element
void printSubsets(vector<vector<int> >& newArr){
	cout<<"Desired subsets: "<<endl;
	for(int i=0; i<newArr.size(); i++){
		cout<<"{ ";
		for(int j=0; j<newArr[i].size(); j++){
			cout<<newArr[i][j]<<" ";
		}
		cout<<"}, ";
	}
}

//append the particular element into 2D array that we got in subset function
void append(vector<vector<int> >& newArr, int value){
	//for each row in 2D vector
	for(int i=0; i<newArr.size(); i++){
			newArr[i].push_back(value);      //append new value into each row
			sort(newArr[i].begin(), newArr[i].end());     //sort each row
	}
	//sort full 2D array
	sort(newArr.begin(), newArr.end());
	//print the desired subsets
	printSubsets(newArr);
	return;
}

//search the position of the particular element to be present in subsets
int binarySearch(int arr[], int l, int r, int k){
	//Given an array arr of elements in non decreasing order, 
	//determine whether k is present and if so return mid such that a[mid] = k;
	int mid=0;
	while(l<=r){
		mid = l+(r-l)/2;
		if(k == arr[mid]){
			return mid;
		}
		else if(k>arr[mid]){
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	return -1;
}

//driver code
int main(){
	cout<<"Enter size of set:"<<endl;
	int n,k;
	cin>>n;
	int arr[n];
	cout<<"Enter set elements:"<<endl;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Enter element that you always want in subset:"<<endl;
	cin>>k;
	//sort the array
	sort(arr, arr+n);
	//call binary search function get position of element k in array
	int pos = binarySearch(arr, 0, n-1, k);
	//if k is not there in array
	if(pos == -1){
		return 0;
	}
	//swap the k element with the last element of array
	else{
		int temp = arr[pos];
		arr[pos] = arr[n-1];
		arr[n-1] = temp;
	}
	//call subset function the remaining n-1 elements(except k element at last index of array)
	vector<vector<int> > subsetArr = subset(arr, n-1);
	//append the last k element of array with the subsets
	append(subsetArr, arr[n-1]);
	return 0;
}
