//DAA Tutorial 05 (08/01/2021)
//Amruta Nandargi PF21
//Implementation of n-Queen Problem using Backtracking Approach

//CODE
#include<iostream>
#include<cstdlib>
using namespace std;
int x[10];
int sol_no=0;

//function to find if column i is correct in row k
bool place(int k, int i){
	for(int j=1; j<=k-1; j++){
		if(x[j]==i ){
			return false; //element already presen
		}else if(abs(x[j]-i)==abs(j-k)){ //same diagonal
			return false;
		} 
	}
	return true;
}

//function to print the tuple/ solution
void print(int n){
	sol_no++;
	cout<<"Solution: "<<sol_no;
	cout<<"\nX = [ ";
	for(int i=1; i<=n; i++){
		cout<<x[i]<<" ";
	}
	cout<<"]\n";
}

//recursive function to find solution
void nQueen(int k, int n){
	int i;
	for(i =1; i<=n; i++){ //checking for all columns
		if(place(k, i)){
			x[k]=i; //place in solution if place() returns true
			if(k==n){
				print(n); //print after filling all columns of tuple
			}else{
				nQueen(k+1, n); //recursive call to move to next row
			}
		}
	}
}

//driver function
int main(){

	cout<<"***** 4-Queens Problem *****\n";
	int n=4;
	int k=0;
	nQueen(k, n);
	return 0;
}



//OUTPUT
/*
***** 4-Queens Problem *****
Solution: 1
X = [ 2 4 1 3 ]
Solution: 2
X = [ 3 1 4 2 ]
*/