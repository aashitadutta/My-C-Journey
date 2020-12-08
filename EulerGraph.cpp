/** Author - Aashita Dutta
To check whether the graph has an eulerian cycle or not**/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//to add nodes adjacent to node in adjacent list of undirected graph
void addEdges(vector<int> newGraph[], int s1, int s2){
	newGraph[s1].push_back(s2);
	newGraph[s2].push_back(s1);
}

//perform dfs algorithm
void dfsGraph(vector<int> graph[], int size, int src, bool visit[]){
	visit[src] = true;
	for(int i=0; i<graph[src].size(); i++){
		if(visit[graph[src][i]]==false){
			dfsGraph(graph, size, graph[src][i], visit);
		}
	}
}

//check if graph is connected
bool checkConnected(vector<int> graph[], int size, int src){
	//if graph is null
	if(size==0){
		return true;
	}
	
	bool visited[size] = {false};
	//call dfs function
	dfsGraph(graph, size, src, visited);
	
	int count = 0;
	//check if all vertices are visited once
	for(int i=0; i<size; i++){
		if(visited[i]){
			count++;
		}
	}
	if(count==size){
		return true;
	}
	return false;
}

//check if all the vertices have even degree
bool checkEuler(vector<int> graph[], int size, int src){
	if(!checkConnected(graph, size, src)){
		return false;
	}
	int oddDegree=0;
	for(int i=0; i<size; i++){
		//if each edge list size is odd
		if(graph[i].size()%2 !=0){
			oddDegree++;
		}
		if(oddDegree !=0){
			return false;
		}
	}
	
	return true;
}
//driver code
int main(){
	//read the file where edges are given
	ifstream infile;
	infile.open("yesEulerEdgeList.txt");
	int n=5;                      //total vertices in graph
	int i, j;
	vector<int> edgeList[n];       //vector array to store edges in adjacent list form
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
	//set source vertex as 0
	int k=0;
	
	//call checkEuler function to check if graph has an euler cycle
	if(checkEuler(edgeList, n, k)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO";
	}
	
	//empty the edge list
	cout<<endl;
	for(int i=0; i<n; i++){
		for(j=0; j<(int)edgeList[i].size(); j++){     
			edgeList[i].clear();
		}
	}
	//read the file where edges are given
	infile.open("noEulerEdgeList.txt");
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
	//call checkEuler function to check if graph has an euler cycle
	if(checkEuler(edgeList, n, k)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO";
	}
}
