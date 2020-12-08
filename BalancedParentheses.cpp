#include<iostream>
using namespace std;

//recursively prints the brackets until all close and open brackets are equal
//intially string is 0 i.e. no open or close brackets
//n is total pairs the user has input
void showParenthesis(string str, int open_brackets_count, int close_brackets_count, int n)
{
	if(str.length()==2*n){
			
			cout<<str<<endl;
		return;
	}
	//count of open brackets on being less than total number of pairs will call showParenthesis function
	//with open_brackets_count+1 and append open brackets symbol='(' to the string
	if(open_brackets_count < n){
		showParenthesis(str + "(", open_brackets_count+1, close_brackets_count, n);
	}
	//count of close brackets on being less than open_brackets will call showParenthesis function
	//with close_brackets_count+1 and append close brackets symbol=')' to the string
	if(open_brackets_count > close_brackets_count){
		showParenthesis(str + ")", open_brackets_count, close_brackets_count+1, n);
	}
	
}

//driver code
int main(){
	cout<<"Enter the number of pairs of parenthesis you want to permute:"<<endl;
	int n;
	cin>>n;
	string parenthesis[100];    //string array
	int open_brackets=0;
	int close_brackets=0;
	string s="";
	showParenthesis(s, open_brackets, close_brackets, n);
	
}



