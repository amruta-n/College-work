/*
DAA Tutorial 03
Name: Amruta Nandargi
Roll no.: PF21
Problem Statement: Implementatin of Knapsack problem using greedy approach
*/

/*CODE*/
#include<iostream>
#include<algorithm>
using namespace std;

//sorting function
void swap(double* a, double* b){
	double temp = *a;
	*a=*b;
	*b=temp;
}

//partition function
int partition(double a[], int c[],double P[],double w[], int l, int h){

	int p=l;//set pivot as low
	for(int i=l+1; i<=h; i++){//traverse through entire array
		if(a[i]>a[l]){//to check lower elements
			p++;
			swap(a[p], a[i]);
			swap(c[p], c[i]);
			swap(P[p], P[i]);
			swap(w[p], w[i]);
		}
	}
	swap(a[p], a[l]);//swap element to its position
	swap(c[p], c[l]);
	swap(P[p], P[l]);
	swap(w[p], w[l]);
	return p;//return index of pivot
}

//quicksort function
void quickSort(double a[], int c[],double P[],double w[], int l, int h){
	if(l<h){
		int part= partition(a,c,P,w, l, h);//finding middle index
		quickSort(a,c,P,w, l, part-1);//sort left array
		quickSort(a,c,P,w, part+1, h);//sort right array
	}
}

//driver function
int main(){
	//variable declaration
	int n;
	double total=0.0, W;
	double P[30], w[30], a[30], res[30]={0}; 
	int c[30];
	
	cout<<"Enter weight:";
	cin>>W;//total weight of knapsack

	cout<<"\nEnter the number of objects:";
	cin>>n;//total number of objects

	//accepting profit and weight
	for(int i=0; i<n; i++){
		cout<<"\nFor "<<i+1<<" object:";
		cout<<"\nProfit: ";
		cin>>P[i];
		cout<<"Weight: ";
		cin>>w[i];
		c[i]=i+1;
	}

	//calculating profit/weight ratio
	for(int i=0; i<n; i++){
		a[i]=P[i]/w[i];
	}

	//sorting P/W ratio
	quickSort(a,c,P,w,0,n-1);

	//displaying all the values
	cout<<"\nNo.";
	cout<<"\tP";
	cout<<"\tW";
	cout<<"\tP/W";
	for(int i=0; i<n; i++){
		cout<<endl<<c[i];
		cout<<"\t"<<P[i];
		cout<<"\t"<<w[i];
		cout<<"\t"<<a[i];
	}
	cout<<endl;

	int i;
	for(i=0; i<n; i++){
		if((W-w[i])>0){
			W=W-w[i];//suntracting weight
			total=total+P[i];//adding profit
			res[c[i]-1]=1;//track of object number
		}else if((W-w[i])<=0){
			break;
		}
	}
	
	//fraction subtraction from weight
	if(W!=0){
		double u=W/w[i];
		W=W-(u*w[i]);
		total=total+(P[i]*u);
		res[c[i]-1]=u;
	}

	//display result
	cout<<"\nTotal Profit: "<<total;//total profit
	cout<<"\nX:";//result
	cout<<"[";
	for(int i=0;i<n; i++){
		cout<<res[i]<<"\t";
	}
	cout<<"]\n";

	return 0;
}


/*OUTPUT
Enter weight:60

Enter the number of objects:4

For 1 object:
Profit: 280
Weight: 40

For 2 object:
Profit: 100
Weight: 10

For 3 object:
Profit: 120
Weight: 20

For 4 object:
Profit: 120
Weight: 24

No.	P	W	P/W
2	100	10	10
1	280	40	7
3	120	20	6
4	120	24	5

Total Profit: 440
X:[1	1	0.5	0	]
*/