/** Author - Aashita Dutta
To find the largest path in an undirected acyclic graph in O(m+n) time**/
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

//initializing global variables
int length = 0;
int maxLength = 0;
int far_node = 0;
int longestPath = 0;
vector<int> storeList;

//to add nodes adjacent to node s1 in adjacent list of graph
void addEdges(vector<int> newGraph[], int s1, int s2){
	newGraph[s1].push_back(s2);
	newGraph[s2].push_back(s1);
}

//depth first search on graph to find the longest node from source node
//and then to find farthest node from new source node found in first dfs
int dfs(vector<int> newGraph[], int s1, bool visit[]){
	
	visit[s1] = true;
	for(int i=0; i<newGraph[s1].size(); i++){
			if(visit[newGraph[s1][i]] == false){
				length++;
				dfs(newGraph, newGraph[s1][i], visit);
				length--;
				
			}
			if(length>maxLength){
				maxLength = length;
				far_node = s1;
			}
			
		}

	
	visit[s1] = false;
	length = 0;
	maxLength = 0;
	return far_node;
}

//to print the longest path in tree from begin node to end node of longest path
int printLongestPath(vector<int> graph[], int src, bool visit[], int dest){
	
	visit[src] = true;
	if(storeList.empty()){
		cout<<src;
	}
	for(int i=0; i<graph[src].size(); i++){
		if(visit[graph[src][i]] == false){
			storeList.push_back(graph[src][i]);
			
			if(graph[src][i] == dest){
				
				for(int i=0; i<storeList.size(); i++){
					cout<<"->"<<storeList[i];
				}
				
				longestPath = storeList.size();
			}
			printLongestPath(graph, graph[src][i], visit, dest );
			storeList.pop_back();
			
		}
	}
	return longestPath;
}

//function that prints the source node and destination node of the longest path
//also prints the longest path with all nodes traversal
void findLongestPath(vector<int> graph[], int src, int size){
	int source_node, dest_node, longestPath;
	bool visited[size] = {false};
	//call dfs to find farthest node from src(0) node
	source_node = dfs(graph, src, visited);
	//call dfs to find farthest node from source node
	dest_node = dfs(graph, source_node, visited);
	cout<<"source node: "<<source_node<<endl;
	cout<<"destination node: "<<dest_node<<endl;
	//call function to print the longest path
	longestPath = printLongestPath(graph, source_node, visited, dest_node);
	cout<<endl;
	cout<<"Length of Longest Path in the graph: " << longestPath<<endl;
}


//driver code to call find longest path function
int main(){
	//read the file where edges are given
	ifstream infile;
	infile.open("C:\\Users\\aashita\\Desktop\\longestPath.txt");
	int n=16;                                   //total vertices in graph
	int i, j;                          
	vector<int> edgeList[n];                    //vector array to store edges in adjacent list form
	if(!infile){                                //if infile not there then print error
		cerr<<"Unable to open file"<<endl;
	}
	else{
	//read the contents of file till you reach end of file
	while(true){
		infile>>i>>j;
		addEdges(edgeList, i, j);
		if(infile.eof()){
			break;
		}
		
	}
}

	infile.close();
	//to show the adjacent list created
	for(i=0; i<n; ++i){
		cout<<i;
		for(j=0; j<edgeList[i].size(); j++){
			cout<<"->"<<edgeList[i][j];
		}
		cout<<endl;
	}
	//set first source node as 0
	int s = 0;
	//call to function findLongestPath in graph
	findLongestPath(edgeList, s,n);
}


