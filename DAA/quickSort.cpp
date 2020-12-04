/*Name: Amruta Nandargi
Panel: F/6
Roll no.: PF21
Batch: F2
Problem Statement: Quicksort 
Implemented it by considering first element as pivot*/

//Code
#include<iostream>
using namespace std;



//swap function
void swap(int* a, int* b){
	int temp = *a;
	*a=*b;
	*b=temp;
}



//partition function
int partition(int a[], int l, int h){

	int p=l;//set pivot as low
	for(int i=l+1; i<=h; i++){//traverse through entire array
		if(a[i]<a[l]){//to check lower elements
			p++;
			swap(a[p], a[i]);
		}
	}
	swap(a[p], a[l]);//swap element to its position
	return p;//return index of pivot
}



//quicksort function
void quickSort(int a[], int l, int h){
	if(l<h){
		int part= partition(a, l, h);//finding middle index
		quickSort(a, l, part-1);//sort left array
		quickSort(a, part+1, h);//sort right array
	}
}



int main(){
	int a[100], n;

	//taking input from user
	cout<<"Enter the number of values:"<<endl;
	cin>>n;
	cout<<"Enter values:"<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	quickSort(a, 0, n-1);//sorting
	//displaying output
	cout<<"Sorted Array:"<<endl;
	for (int i = 0; i < n; i++) {
		cout<<a[i] << " ";
	}
	cout<<endl;
	return 0;
}

//Output
/*
CASE I:
Enter the number of values:
6
Enter values:
9
8
7
6
5
4
Sorted Array:
4 5 6 7 8 9 

CASE II:
Enter the number of values:
5
Enter values:
56
234
12
99
36
Sorted Array:
12 36 56 99 234 

CASE III:
Enter the number of values:
3
Enter values:
1
2
3
Sorted Array:
1 2 3 
*/