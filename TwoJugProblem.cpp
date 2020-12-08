/** Author - Aashita Dutta
Given two jugs, one is m litres and other is n litres, measure the x litres of water using these two jugs**/
#include<iostream>
using namespace std;

//calculate GCD of two jugs - m and n capacity
int findGcd(int a, int b){
	int gcd;
	if(b==0){
		return -1;
	}
	else{
		for(int i=1; i<=a&&i<=b; i++){
			if(a%i==0 && b%i==0){
				gcd = i;
			}
		}
	}
	return gcd;
}

//function to measure xliters of water using a and b litres of jug
//first is from which jug water is filled
//second is to which jug water is filled
int measureJug(int a, int b, int x){  
	//initialize both jugs with 0 and 0 liters  
	int first = 0;
	int second = 0;
	int k=0;
	int steps=0;               //to measure countof steps for measuring x liters of water
	cout<<"Let initially: "<<endl;
	cout<<endl;
	cout<<"("<<first<<" , "<<second<<")"<<endl;      //output initial configuration of jugs at (0,0)
	cout<<endl;
	cout<<"Procedure starts: "<<endl;
	cout<<endl;
	while(first!=x && second!=x){         //loop until either of two jugs does not have x liters of water
		
		//fill first jug if its empty, show the configuration and increment steps
		if(first == 0){
			first = a;                      
			cout<<"("<<first<<" , "<<second<<")"<<endl;
			cout<<endl;
			steps++;
		}
		//empty second jug if its full, show the configuration and increment steps
		else if(second == b){
			second = 0;
			cout<<"("<<first<<" , "<<second<<")"<<endl;
			cout<<endl;
			steps++;
		}
		else{
			
		//subtract current capacity of second jug from its total capacity and measure if its minimum than current first jug
			if((b-second)<first){
				k = b-second;
			}
			else{
				k = first;
			}
		//subtract the value k from second 
			second = second + k;
		//add k to first
			first = first - k;
			steps++;
			cout<<"("<<first<<" , "<<second<<")"<<endl;
			cout<<endl;
			
		}
		//break the while loop when either of the jugs has x litres of water
		if(first==x || second==x){
			break;
		}
	
	}
	
}

//driver code to calculate x litrers of water using diophantine equation
int main(){
	int m,n,x;
	int min=0;
	cout<<"Enter the capacity of jug A as m litres:"<<endl;
	cin>>m;
	cout<<"Enter the capacity of jug B as n litres:"<<endl;
	cin>>n;
	cout<<"Enter how many litres of water you want to measure as x litres:"<<endl;
	cin>>x;
	
	if(x<m || x<n){                 //if water to be measured is less than m or n
		if(x%findGcd(m,n)!=0){      //if x is not divisible with gcd of m and n then measuring not possible 
			cout<<"Measuring is not possible";      
			return 0;
		}
		else{						//if x is divisible with gcd of m and n
			cout<<"Measuring X litres filling m litres jug first:"<<endl;
			cout<<endl;
			int n1 = measureJug(m,n,x);      //call function where water is filled from m to n
			cout<<"Measuring X litres filling n litres jug first:"<<endl;
			cout<<endl;
			int n2 = measureJug(n,m,x);      //call function where water is filled from n to m
			//find which one gives minimum steps and output it
			if(n1<n2){
				min = n1;
				
			}	
			else{
				min = n2;
			}
			cout<<"Minimum steps required is "<<min<<endl;
			
		}
	}
	//if watre to be measured is not less than from either of the m or n then no solution possible
	else{
		cout<<"Measuring is not possible";
		return 0;
	}	
}
