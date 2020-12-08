	/** Author - Aashita Dutta**/
	
	#include <iostream>
	#include <stdlib.h>
	#include<fstream>
	#include<vector>
	#include<sys/time.h>
	using namespace std;
	
	//swap function - utility function
	
	int swap(int* first, int* second){
	    int temp = *first;
	    *first = *second;
	    *second = temp;
	}
	
	//partition_beg function takes first element of array as pivot
	//by placing pivot at its correct position in such a way
	//that ell elements less than pivot will appear at left of pivot
	//and all elements greater than pivot will apprear right of pivot
	int partition_beg(int arr[], int beg, int end){
	    int pivot = arr[beg]; //initialize first element as pivot
	    int i = beg;          //two pointers i and j initialzed as first and last array index
	    int j = end;
	    int temp;
	    while(i<j){      //outer loop to check until i does not cross j
	        while(arr[i]<=pivot){ 
	            i++;              //increment i until you find any element greater than pivot
	        }
	
	        while(arr[j]>pivot){
	            j--;             //decrement j until you find any element less than pivot
	        }
	        //if after incrementing i and decrementing j you find element less than
	        //and greater than pivot then swap elements at i and j
	        if(i<j){            
	            swap(&arr[i], &arr[j]);
	        }
	    }
	    //when i met crosses j
	   //at last swap the pivot element with the element at position j
	   //this makes pivot positioned at its place with elements at left are less than pivot
	   //and all elements are greater than pivot at right
	    swap(&arr[beg], &arr[j]);
	
	    return j;
	}
	
	//quicksort_beg function implementing partition_beg function
	void quicksort_beg(int arr[], int beg, int end){
	    if(beg<end){
	        int k = partition_beg(arr, beg, end); //position returned by partition function stored in variable
	        quicksort_beg(arr, beg, k-1);             // call quicksort iteratively for elements less than pivot at left
	        quicksort_beg(arr, k+1, end);             //call quicksort iteratively for elements larger than pivot at right
	    }
	
	}
	
	//partition_end function takes last element of array as pivot
	//by placing pivot at its correct position in such a way
	//that ell elements less than pivot will appear at left of pivot
	//and all elements greater than pivot will apprear right of pivot
	
	int partition_end(int arr[], int beg, int end){
	    int pivot = arr[end];        //pivot as end array element
	    int i = beg-1;               //pointer initialized as beyond begin index of array
	    int temp;
	    for(int j = beg; j<end; j++){     //loop for j element to get element less than pivot
	        if(arr[j]<pivot){
	            i++;                      //increment i to swap with elements at i and j
	            swap(&arr[i], &arr[j]);
	        }
	
	    }
	    swap(&arr[i+1], &arr[end]);          //swap pivot element with index i+1
	    return i+1;                          //return position of pivot
	
	}
	//implementation of partition using random element
	//random element generated between start and end position of array and stored in variable as random position
	//swapping of random position with beginning of array
	
	int rand_partition(int arr[], int beg, int end){
	    int rand_pivot = beg + rand() % (end - beg + 1);
	    int temp = arr[rand_pivot];
	    arr[rand_pivot] = arr[beg];
	    arr[beg] = temp;
	
	    return partition_end(arr, beg, end);
	}
	
	//quicksort_end function implementing partition_end function
	void quicksort_random(int arr[], int beg, int end){
	    if(beg<end){
	        int k = partition_end(arr, beg, end);    //position returned by partition function stored in variable
	        quicksort_random(arr, beg, k-1);         // call quicksort iteratively for elements less than pivot at left
	        quicksort_random(arr, k+1, end);         //call quicksort iteratively for elements larger than pivot at right
	    }
	
	}
	
	//partition_dual function takes first element of array as left pivot and
	//last element of array as right pivot
	//by placing pivot at its correct position in 3 subarrays
	//1st subarray has items < left pivot
	//2nd subarray has items >= left pivot or items <= right pivot
	//3rd subarray has items >= right pivot
	
	int partition_dual(int arr[], int beg, int end, int* pointers){
		int left_pivot = arr[beg];    //first element as left pivot
		int right_pivot = arr[end];    //last element as right pivot
		//pointers initialization to track the current position of left and right pivots
		int left = beg+1;              
		int right = end-1;            
		int temp = beg+1;               
		if(arr[beg]>arr[end]){
			swap(&arr[beg], &arr[end]);    //if left pivot > right pivot then swap
		}
		while(temp<=right){                 //increment temp until temp crosses right
			if(arr[temp]<left_pivot){       
				swap(&arr[temp], &arr[left]);    //swap if element at temp less than left pivot
				temp++;
			}
			//else part
			else if(arr[temp]>=right_pivot){
				while(arr[right]>right_pivot && temp<right){
					right--;                         //decrementing pointer until element at right less than right pivot and temp position > right
				}
				swap(&arr[temp], &arr[right]);     //swap element at right with temp
				right--;
				//after swapping check new element at k is less that left pivot and swap if not
				if(arr[temp]<left_pivot){          
					swap(&arr[temp], &arr[left]);
					temp++;
				}
			}
			temp = temp+1; 
		}
		 //at last decrement and incremenet the left and right position to get right position of left and righ pointer
		left = left-1;    
		right = right+1;
		//swap the elements
		//get the correct positions of left and right pivot
		swap(&arr[beg], &arr[left]); 
		swap(&arr[end], &arr[right]);
		*pointers = left;   //store left pivot in pointer to be used in quicksort method
	
	    return right;
	}
	
	//quicksort_dual function implementing partition_dual function
	void quicksort_dual(int arr[], int beg, int end){
		int lpivot, rpivot;
	    if(beg<end){
	    	rpivot = partition_dual(arr, beg, end, &lpivot); //position returned by partition function stored in variable
	        quicksort_dual(arr, beg, lpivot-1);         // call quicksort iteratively for elements less than pivot at left
	        quicksort_dual(arr, lpivot+1, rpivot-1);         //call quicksort iteratively for elements larger or equal to left pivot but less than or equaalt to right pivot
	        quicksort_dual(arr, rpivot+1, end);        //call quicksort iteratively for elements larger than right pivot
	    }
	
	}
	
	
	//driver code to implement quicksort using beginning, random and ual pivot
	//takes size of array and array inputs
	int main(){
		struct timeval start,stop;    //struct timeval objects 
		long duration;              //variable to calculate difference between start and stop time of execution
		ifstream inputFile;           //input file object to read file
		ofstream outputFile;          //output file object to write file
		inputFile.open("C:\\Users\\aashita\\Desktop\\data.txt");   //open file
		std::vector<int> integers;      //vectors for dynamic reading and writing of array
		int i=0;
		
		//read integers from file and push in vector(arry)
		while(!inputFile.eof()){
			inputFile >> i;
			integers.push_back(i);
		}
		int n = integers.size();
		inputFile.close();
		int arr[n];
		//convert vector to array
		for(i=0; i<n; i++){
			arr[i] = integers[i];
		}
		gettimeofday(&start, NULL);
		outputFile.open("C:\\Users\\aashita\\Desktop\\outputBegPivot.txt");
	    quicksort_beg(arr, 0, n-1);             //call quicksort_beg function with beginning element as pivot
	    for(int i=0; i<n; i++){
	        outputFile << arr[i]<<" ";         //writing sorted elements in file as array
	    }
	    outputFile.close();
	    gettimeofday(&stop, NULL);
	    duration = (stop.tv_usec) - (start.tv_usec);  //calculating time in microseconds
	    cout<<"Time elapsed for quick sort using beginning element pivot "<<duration<<endl;
	    
	    //Calling quicksort function with random element as pivot
	    gettimeofday(&start, NULL);
	    outputFile.open("C:\\Users\\aashita\\Desktop\\outputRanPivot.txt");
	    quicksort_random(arr, 0, n-1);
	    //output sorted array
	    for(int i=0; i<n; i++){
	        outputFile << arr[i]<<" ";
	    }
	    outputFile.close();
	    gettimeofday(&stop, NULL);
	    duration = (stop.tv_usec) - (start.tv_usec);  //calculating time in microseconds
	    cout<<"Time elapsed for quick sort using random element pivot "<<duration<<endl;
	    
	    //Calling quicksort function with dual elements as pivot
	    gettimeofday(&start, NULL);
	    outputFile.open("C:\\Users\\aashita\\Desktop\\outputDualPivot.txt");
	    quicksort_dual(arr, 0, n-1);
	    //output sorted array
	    for(int i=0; i<n; i++){
	        outputFile << arr[i]<<" ";
	    }
	    outputFile.close();
	    gettimeofday(&stop, NULL);
	    duration = (stop.tv_usec) - (start.tv_usec);  //calculating time in microseconds
	    cout<<"Time elapsed for quick sort using dual element pivot "<<duration<<endl;
	return 0;
	}
