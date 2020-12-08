/* Author- Aashita Dutta 
Program to count the number of blocks in binary matrix where block is collection of adjacent cells having 1 in matrix*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findBlocks(vector<int>A[], int N, int M);  //function definition

//driver function that calls number of blocks function in binary matrix and output number of blocks present
int main() {
	int N, M;        //N is number of rows and M is number of columns for matrix
	cout<<"Enter the number of rows and columns for binary matrix"<<endl;
	cin>>N>>M;
	vector<int>A[N];   //declaring array of vectors for matrix
	int i,j;
	cout<<"Enter the binary matrix values for each row and column"<<endl;
	for(i=0; i<N; i++) {
		for(j=0; j<M; j++) {
			int values;
			cin>>values;                //store the columns values for particular rows
			A[i].push_back(values);     //store the values as vectors in matrix and push them in array
		}
	}
	int result = findBlocks(A, N, M);
	cout<< "Number of blocks: "<< result <<endl;
	return 0;
}

/*function to check on visiting 1 in matrix and traversing all the adjacent cellssuch that traversal doesn't go out of boundary 
or whether the cell within matrix or not. Returns the boolean value for particular cell row and column value is greater than 0 
and should be less than total row and column size of matrix. Content inside cell should be 1 and visited as false*/
bool withinBoundary(vector<int> Array[], int i, int j, int r, int c, vector<vector<bool> >& visited) {
	return i>=0 && j>=0 && i<r && j<c && ((Array[i][j])==1 && visited[i][j]==false);
}

/*using breadth first search criteria to get the track of matrix cells visited and have level order traversal of each adjacent 
ones in all 8 directions such that if node is at (0,0) the cover all 8 possible direction from this cell and traverse like
a graph using bfs maintaining queue having two values i and j. 
*/
void breadthFirstSearch(vector<int> Arr[], int row, int col, int matrixRow, int matrixCol, vector<vector<bool> >& visit) {
	/*array that all row values and column values are in 8 directions from one cell. Start from i=0, j=0 then 
	(i,j+1), (i,j-1), (i+1,j), (i+1,j+1), (i+1,j-1), (i-1,j), (i-1,j+1), (i-1,j-1)*/
	int rows[] = {0, 0, 1, 1, 1, -1, -1, -1};
	int cols[] = {1, -1, 0, 1, -1, 0, 1, -1};
	
	//maintaining queue all the pairs - row and column values that are visited and traverse its neighbours in level
	queue<pair<int,int> > q;
	
	//set visit array of the node where first 1 encountered as true
	visit[row][col] = true;
	
	//push the pair of row and column where first 1 seen
	q.push(make_pair(row, col));
	
	//loop till queue is empty
	while(!q.empty()) {
		
		//store the front of queue values in variable
		int i = q.front().first;        
		int j = q.front().second;
		
		//pop the front values
		q.pop();
		bool x=false;
		
		//loop till all the adjacent 8 directions are covered and push the nodes all adjacent ones in queue
		for(int k=0; k<8; k++) {
			//check if all adjacent ones that covered of the first one is within matrix or not
			x = withinBoundary(Arr, i+rows[k], j+cols[k], matrixRow, matrixCol, visit);
			
			//if the above adjacent cells are within matrix
			if(x){
               visit[i+rows[k]][j+cols[k]]=true;       //set the visit of the adjacent cells of cell containing 1 as true
               
               //now push the adjacent cells of cell containing one in loop till
               //and run again this loop till queue is empty

               q.push(make_pair(i+rows[k], j+cols[k]));   
			   
			}
		}
	}
}

//function to find the number of connected cells containing 1 in adjacent way, and count the number of such blocks where 
//cells containing ones are adjacent
int findBlocks(vector<int> A[], int N, int M) {
	int count;
	vector<vector<bool> > visited(N, vector<bool> (M, false)); //initialize boolean vector of vectors to track visited cell
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(A[i][j]== 1 && visited[i][j]==false) {       //check for each row and column that cell has 1 and not yet visited
			//increment the count as single cell without adjacent cells having 1 is also a block and count for all the blocks 
			//with or without adjacent cells
				count++;									
				breadthFirstSearch(A, i, j, N, M, visited);    //call breadth first search function for all the adjacent cells
			}
		}
	}
	return count;
}

