/** Author - Aashita Dutta
To print all possible paths from a pair of nodes s and t in a directed graph**/

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

//to add nodes adjacent to node s1 in adjacent list of graph
void addEdges(vector<int> newGraph[], int s1, int s2){
	newGraph[s1].push_back(s2);
}

//function to print all paths from s to t
//visit array to track all vertiec that visited
//nodes array that contains vertices 
//index is current index of nodes array
void printPathDfs(vector<int> newGraph[], int n, int s1, int s2, bool visit[], int nodes[], int index){
	visit[s1] = true;          //marking current vertex as true
	nodes[index] = s1;         //add current vertex to nodes array
	index++;                   //increment index
	if(s1 != s2){              //if current vertex is not equal to destination node
		
		for(int i=0; i<newGraph[s1].size(); i++){
			if(visit[newGraph[s1][i]] == false){            //if adjacent node of current vertex is not yet visited
			//recursively call printPathDfs function for all the adjacent nodes to current vertex
				printPathDfs(newGraph, n, newGraph[s1][i], s2, visit, nodes, index);
			}
		}
		
	}
	//if current vertex is equal to destination node, then print the current path
	else{
		for(int i=0; i<index; i++){
			cout<<nodes[i] <<" ";
		}
	cout<<endl;
	}
	
	//decrement the index to remove current node from nodes array
	//mark this cuurent node as false
	index--;
	visit[s1]=false;
	
}

//utility function to call printPathDfs function to print all paths
void findAllPaths(vector<int> graph[], int size, int src, int dest){
	
	//intialize visited array as false
	bool visited[size] = {false};
	//initialize the nodes array as 0 to store all the nodes connecting s to t
	int nodes[size] = {0}; 
	int index = 0;
	printPathDfs(graph, size, src, dest, visited, nodes, index);
	
}


//driver code to call findAllPaths function
int main(){
	ifstream infile;
	//read the file where edges are given
	infile.open("print_paths_edges.txt");
	int n=4;                //total vertices in graph
	int i, j, s, t;
	vector<int> edgeList[n];            //vector array to store edges in adjacent list form
	if(!infile){						//if infile not there then print error
		cerr<<"Unable to open file"<<endl;
	}
	//read the contents of file till you reach end of file
	else{
		while(true){
			infile>>i>>j;
			if(infile.eof()){
				break;
			}
		//add edges to vector array
		addEdges(edgeList, i, j);
		}
	}
	
	infile.close();
	//to show the adjacent list created
	for(i=0; i<n-1; ++i){
		cout<<i;
		for(j=0; j<edgeList[i].size(); j++){
			cout<<"->"<<edgeList[i][j];
		}
		cout<<endl;
	}
	
	cout<<"Enter the source node and destination node that you want to print all its paths"<<endl;
	cin>>s>>t;
	//call to function to print all paths between s and t
	findAllPaths(edgeList, n, s, t);
}
