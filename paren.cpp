/* Author - Aashita Dutta
To generate all possible strings of valid parenthesis for a given n
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//recursively prints the brackets until all close and open brackets are equal
//intially string is 0 i.e. no open or close brackets
//n is total pairs the user has input
//parenthesis is string vector to store strings generated of from n pairs.
void balanceParenthesis(vector<string>& parenthesis, int open_brackets, int close_brackets, string s, int n){
        if(s.length()==2*n){
            parenthesis.push_back(s);
            return;
        }
        //count of open brackets on being less than total number of pairs will call balanceParenthesis function
		//with open_brackets_count+1 and append open brackets symbol'(' to the string
        if(open_brackets < n){
           balanceParenthesis(parenthesis, open_brackets+ 1, close_brackets, s+"(", n);
        }
        //count of close brackets on being less than open_brackets will call balanceParenthesis function
		//with close_brackets_count+1 and append close brackets symbol')' to the string
        if(open_brackets > close_brackets){
           balanceParenthesis(parenthesis, open_brackets, close_brackets + 1, s+")", n);
        }
    }
    
    //function to call balanceParenthesis function
    //initializes all the parameters needed for balanceParenthesis function
	vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        int open_brackets = 0;
        int close_brackets = 0;
        string s = "";
        balanceParenthesis(parenthesis, open_brackets, close_brackets, s, n);
        return parenthesis;
    }
    
    
  //driver code to print the different combinations of n parenthesis  
    int main() {
    	cout<<"Enter the number of pairs of parenthesis you want to permute:"<<endl;
    	int n;
    	cin>>n;
    	vector<string> result;
    	result = generateParenthesis(n);
    	for(int i=0; i<result.size(); i++){
    		cout<<result[i]<<endl;
    	}
	return 0;
}

