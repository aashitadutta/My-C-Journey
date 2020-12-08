/* Author- Aashita Dutta 
Program to find whether the graph is bipartite or not from the set of given edge list*/

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int dfsGraph(vector<int>[], int, bool[], int[]);
int color[100];

//function that adds edges read from file in array of vectors as adjacency list
addEdges(vector<int> edges[], int source, int dest){
	//source is source node, and dest is list of nodes in that particular row, having edge from source node
	edges[source].push_back(dest);  

}

//Implement depth first search function at one present node- called from main as 1, and then this function will recursively
//call dfs function for all the nodes to which this current node connected and color those nodes accordingly.
int checkBipartite(vector<int> adjList[], int v, int index){
	int x;
	//initialize bool visited array, to mark that node is visited, mark this current node visited as false
	bool visited[v] = {false};                 
	color[index] = 0;						//initialize the color array with current node assigned color as zero as int
	x =	dfsGraph(adjList, index, visited, color); //call the dfs graph function for the neighbours of the current node
	//if graph has two adjacent vertices as same color or odd length cycle exists then graph is not bipartite
	if(x==0){                                
		return 0;
	}
	for(int i=1; i<v; i++){			
		if(visited[i]==false){     //if any of the vertices visited is false then this function will return 0
		return 0;
		}
	}
	return 1;
}

//This function will recursively check for each node neighbours of parent called from parent node in Depth First Search Function
//This also tracks if particular node is visited to avoid visiting again and color the node opposite to from last visited node
//color assigned as the edge is read from file and assign opposite colors always. Here two colors used as 0 and 1.
//If there is odd length cycle then graph is not bipartite otherwise yes

int dfsGraph(vector<int> adjList[], int vertex, bool visit[], int color[]){
	int x;
	visit [vertex] = true;  //visit the current vertex as true
	//loop until you reach the size of array of vectors according to rows or total nodes
	for(int i=0; i<adjList[vertex].size(); i++) {

		if(visit[adjList[vertex][i]]==false)    //if the neighbour of the current vertex in list is not visited
		{
			
			//color the neighbour vertex as opposite to previous visited node in stack(recursion)
			color[adjList[vertex][i]] = !color[vertex];    
			
			//call the dfs function for this unvisited neigbour node in adjacency list
			x = dfsGraph(adjList, adjList[vertex][i], visit, color);    
			 if(x==0){
			 	return 0;   //graph is disconnected, then no dfs possible
			 }
        }
        //check if adjacent node of the vertex has same color as the vertex node(parent) and
        //also visited array of this adjacent of parent node marked as true then return 0, graph is not bipartite
		else if(color[adjList[vertex][i]] == color[vertex] && visit[adjList[vertex][i]]==true)
		{
			return 0;
		}

    }

	return 1;
}

//Driver code that determines if graph is bipartite or not
int main(){
	ifstream infile;               //ifstream object to read file
	infile.open("no_bipartite.txt");            
	int n1 = 6;
	int n2 = 4;
	vector<int> edgeList[100];           //initialize array of vectors
	int i, j, x;
	int k=1; int k2=1;
	if(!infile){						//if file doesn't exist
		cerr<<"Error opening the file\n";
		return 0;
	}
	
	while(!infile.eof()){
		infile>>i>>j;					//file consist of edges list as two numbers in each line (1 2)- edge from 1 to 2
		addEdges(edgeList,i,j);
	}
	infile.close();
	for(int i=0; i<=n1; i++){
		for(j=0; j<(int)edgeList[i].size(); j++){     
			cout<<i<<" -> "<<edgeList[i][j]<<endl;   //to show how many edges are there in file - no_bipartite
		}
	}
	x = checkBipartite(edgeList, n1, k);            //call to depth first search function to check bipartite
	if(x==1){
		cout<<"Yes"<<endl;						   //if graph is bipartite
	}
	else{
		cout<<"No"<<endl;						   //if graph is not bipartite
	}
	cout<<endl;
	for(int i=0; i<=n1; i++){
		for(j=0; j<(int)edgeList[i].size(); j++){     
			edgeList[i].clear();
		}
	}
	infile.open("yes_bipartite.txt");  
	if(!infile){						         
		cerr<<"Error opening the file\n";
		return 0;
	}
	while(!infile.eof()){
		infile>>i>>j;					
		addEdges(edgeList,i,j);
	}
	infile.close();

	for(int i=0; i<=n2; i++){
		for(j=0; j<(int)edgeList[i].size(); j++){     
			cout<<i<<" -> "<<edgeList[i][j]<<endl;   //to show how many edges are there in file - yes_bipartite
		}
	}
	x = checkBipartite(edgeList, n2, k2);      //call to depth first search function
	if(x==1){
		cout<<"Yes"<<endl;								//if graph is bipartite
	}
	else{
		cout<<"No"<<endl;							    //if graph is not bipartite
	}
}
