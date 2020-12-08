/** Author - Aashita Dutta
To count the number of sink vertices in a given directed graph**/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//to add nodes adjacent to node s1 in adjacent list of graph
void addEdges(vector<int> newGraph[], int s1, int s2){
	newGraph[s1].push_back(s2);
}

//to convert adjacent list to adjacent matrix
vector<vector<int> > listToMatrix(vector<int> adjList[], int n){
	//declare two dimensional matrix of size n+1 with all 0 values.
	vector<vector<int> > adjMatrix(n+1, vector<int>(n+1, 0)); 
	for(int i=1; i<=n; i++){
		for(int j=0; j<adjList[i].size(); j++){
			adjMatrix[i][adjList[i][j]] = 1;     //fill the cell value as 1 for edge between two node in the list
		}
	}
	return adjMatrix;
}

//to find the vertices that has no outgoing edge in graph
int findSinkVertices(vector<vector<int> > matrix, int n){
	int count; 
	vector<int> arr;
	for(int i=1; i<=n; i++){
		count=0;
		for(int j=1; j<=n; j++){
			if(matrix[i][j]==0){
				count++;        //increment count if cell's value is 0
			}
			else{
				break;
			}
		}
	//when all cells have 0 value in 8 columns of particular row then push that row in vector arr
		if(count==n){
			arr.push_back(i);
		}
	
	}
	return arr.size();
}

//driver code
int main(){
	//read the file where edges are given
	ifstream infile;
	infile.open("sinkEdgeList.txt");
	int n=8;                      //total vertices in graph
	int i, j;
	vector<int> edgeList[n+1];       //vector array to store edges in adjacent list form
	if(!infile){					 //if infile not there then print error
		cerr<<"Unable to open file"<<endl;
	}
	//read the contents of file till you reach end of file
	else{
		while(!infile.eof()){
			infile>>i>>j;
			//add edges to vector array
			addEdges(edgeList, i, j);
		}
	}
	infile.close();
	//to show the adjacent list created
	for(int i=1; i<=n; ++i){
		cout<<i;
		for(int j=0; j<edgeList[i].size(); j++){
			cout<<"->"<<edgeList[i][j];
		}
		cout<<endl;
	}
	
	vector<vector<int> > adjacentMatrix = listToMatrix(edgeList,n);
	//to show the adjacent matrix created
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; j++){
			cout<<adjacentMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	//call to function findSinkVertices in graph
	cout<<"Number of sink vertices in a graph: "<<findSinkVertices(adjacentMatrix, n)<<endl;
}
