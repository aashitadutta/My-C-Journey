/* Author - Aashita Dutta
To verify whether AB=C or not usinh random vector
*/

#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string>
using namespace std;

//function to count number of rows in file using file pointer of ifstream
int countRows(ifstream& ifile){
	string line;
	int rows=0;
	if(ifile==NULL){
		cerr<<"Can't open the file"<<endl;
	}
	else{
		while(getline(ifile, line)){
			rows++;
		}
	}
	
	ifile.close();
	return rows;
}

//function to fill the matrix by reading values from file using infile pointer and input in 2D vector matrix
void inputMatrix(vector<vector<int> >& arr, int size, ifstream& ifile){
	for(int i=0; i<size; i++){
			vector<int> row;
			for(int j=0; j<size; j++){
				int values;
				ifile >> values;
				row.push_back(values);
			}
		arr.push_back(row);
	}
		ifile.close();
}

void showMatrix(vector<vector<int> >& arr, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//matrix multiplication of n*n matrix with n*1 matrix gives matrix of size n*1
vector<vector<int> > matrixMultiplication(vector<vector<int> >& arr1, vector<vector<int> >& arr2, 
										  vector<vector<int> >& mat,int size)
{
	for(int i=0; i<size; i++){
		for(int j=0; j<1; j++){
			for(int k=0; k<size; k++){
			mat[i][j] += (arr1[i][k] * arr2[k][j]);
			}
		}
	}
    return mat;
}

int main(){
	string s1 = "A1.txt";
	string s2 = "A2.txt";
	string s3 = "B1.txt";
	string s4 = "B2.txt";
	string s5 = "C1.txt";
	string s6 = "C2.txt";
	vector<vector<int> > matrixA1;
	vector<vector<int> > matrixB1;
	vector<vector<int> > matrixC1;
	vector<vector<int> > matrixA2;
	vector<vector<int> > matrixB2;
	vector<vector<int> > matrixC2;
	vector<vector<int> >matrixRandom;
	
	ifstream infile;
	//file A1
	//count rows and input values in matrix A1
	infile.open(s1.c_str());
	int a1 = countRows(infile);
	infile.open(s1.c_str());
	
	inputMatrix(matrixA1, a1, infile);
	
	//File A2
	//count rows and input values in matrix A2
	infile.open(s2.c_str());
	int a2 = countRows(infile);
	infile.open(s2.c_str());
	
	inputMatrix(matrixA2, a2, infile);
	
	
	//File B1
	//count rows and input values in matrix B1
	infile.open(s3.c_str());
	int a3 = countRows(infile);
	infile.open(s3.c_str());
	
	inputMatrix(matrixB1, a3, infile);
	
	
	//file B2
	//count rows and input values in matrix B2
	infile.open(s4.c_str());
	int a4 = countRows(infile);
	infile.open(s4.c_str());
	
	inputMatrix(matrixB2, a4, infile);
	
	
	//file C1
	//count rows and input values in matrix C1
	infile.open(s5.c_str());
	int a5 = countRows(infile);
	infile.open(s5.c_str());
	
	inputMatrix(matrixC1, a5, infile);
	
	
	//file C2
	//count rows and input values in matrix C2
	infile.open(s6.c_str());
	int a6 = countRows(infile);
	infile.open(s6.c_str());
	
	inputMatrix(matrixC2, a6, infile);
	
	//Random binary matrix generated
	for(int i=0; i<a1; i++){
		vector<int> row;
		for(int j=0; j<1; j++){
			int values = rand() % 2;
			row.push_back(values);
		}
		matrixRandom.push_back(row);
	}
    //showMatrix(matrixRandom, a1);

	vector<vector<int> > temp(a1, vector<int>(a1, 0));
	vector<vector<int> > res(a1, vector<int>(a1, 0));
	vector<vector<int> > store(a1, vector<int>(a1, 0));
	vector<vector<int> > aux;
	vector<vector<int> > aux1;
	int count1=0; int count2=0;
	
	cout<<"output for checking A1B1=C1 10 times: "<<endl;
	for(int i=0; i<10; i++){
    	aux = matrixMultiplication(matrixB1, matrixRandom, temp, a1);
		aux = matrixMultiplication(matrixA1, aux, res, a1);
		aux1 = matrixMultiplication(matrixC1, matrixRandom, store, a1);
		if(aux != aux1){
			count1++;
		}
		else{
			count2++;
		}
		
	}
	cout<<"Number of NO as output is: "<<count1<<endl;
	cout<<"Number of YES as output is: "<<count2<<endl;
	
	count1 = 0; count2 = 0;
	cout<<endl;
	
	cout<<"output for checking A1B1=C1 100 times: "<<endl;
	for(int i=0; i<100; i++){
    	aux = matrixMultiplication(matrixB1, matrixRandom, temp, a1);
		aux = matrixMultiplication(matrixA1, aux, res, a1);
		aux1 = matrixMultiplication(matrixC1, matrixRandom, store, a1);

		if(aux != aux1){
			count1++;
		}
		else{
			count2++;
		}
		
	}
	cout<<"Number of NO as output is: "<<count1<<endl;
	cout<<"Number of YES as output is: "<<count2<<endl;
	count1 = 0; count2 = 0;
	cout<<endl;
	
	cout<<"output for checking A2B2=C2 10 times: "<<endl;
	for(int i=0; i<10; i++){
    	aux = matrixMultiplication(matrixB2, matrixRandom, temp, a1);
		aux = matrixMultiplication(matrixA2, aux, res, a1);
		aux1 = matrixMultiplication(matrixC2, matrixRandom, store, a1);

		if(aux != aux1){
			count1++;
		}
		else{
			count2++;
		}
	}
	cout<<"Number of NO as output is: "<<count1<<endl;
	cout<<"Number of YES as output is: "<<count2<<endl;
	count1 = 0; count2 = 0;
	cout<<endl;
	
	cout<<"output for checking A2B2=C2 100 times: "<<endl;
	for(int i=0; i<100; i++){
    	aux = matrixMultiplication(matrixB2, matrixRandom, temp, a1);
		aux = matrixMultiplication(matrixA2, aux, res, a1);
		aux1 = matrixMultiplication(matrixC2, matrixRandom, store, a1);

		if(aux != aux1){
			count1++;
		}
		else{
			count2++;
		}
	}
	cout<<"Number of NO as output is: "<<count1<<endl;
	cout<<"Number of YES as output is: "<<count2<<endl;
}


