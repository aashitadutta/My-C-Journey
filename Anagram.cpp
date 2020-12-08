/* Author - Aashita Dutta 
Program to find the size of the largest subset of the given set where no two strings are anagrams*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* this function will return the size of the largest subset where no two strings are anagrams.
This function will count the number of strings that are anagrams to each other after sorting them together in string array.
The map will give unique strings in the set and their counts. e.g. if set has { bac, cba, abc, gh, hg} so map will store- abc - 3 and gh - 2
The size of the map is the largest non anagram subset we want*/

void nonAnagramSubset(string arr[], int n)
{
	for(int i=0; i<n;i++)
	{
		if(arr->length()==0)
		{                       //to check if string array has null string
			return;            //then it will just return as its not accepted.
		}
	}
	map<string,int> countMap;
	for(int i=0; i<n;i++)
	{
		countMap[arr[i]]++;   //the count the frequency of unique strings that are anagrams to each other 
	}

	//Map size having collection of unique strings which are completely non anagrams to each other.
	cout<<"Size of the largest subset where no two strings are anagram are: "<<countMap.size()<<endl; 
}

//Driver code that calls the function which will return the size of subset where no two strings are anagram to each other
int main()
{
	cout<<"Enter the number of strings: "<<endl; //string array length
	int n;
	cin>>n;
	string arr[n];
	cout<<"Enter the strings: "<<endl;   //enter the strings in string array
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	string newArr[n];
	for(int i=0;i<n;i++)
	{  
		newArr[i] = arr[i];            //storing original string array into new array
	}

	for(int i=0; i<n; i++)
	{
		sort(newArr[i].begin(), newArr[i].end());      //sort each individual string in string array
	}

	//call to function          
	nonAnagramSubset(newArr, n); 
	
	return 0;
}
