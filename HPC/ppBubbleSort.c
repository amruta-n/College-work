/*
Name: Amruta Nandargi
Roll no.: Pf21
PRN: S1032180391
Problem Statement: Write a C program for bubble sort. Calculate its time complexity. Identify the hotspots in the program. Write an optimized code for bubble sort using OpenMP
*/

//CODE
#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a , int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}


void bubbleSort(int a[], int n){
	for(int k=0; k<n; k++){
		for(int i=0; i<n-1; i++){
			int j=i+1;
			if(a[j]<a[i]){
				swap(&a[j], &a[i]);
			}
		}
	}
}


void bubbleSortp(int a[], int n){
	int k;
		for(k=0; k<n; k++){
			if(k%2==0){//EVEN LOOP
				int temp;
				#pragma omp parallel for private(temp)
				for(int i=0; i<n-1; i+=2){
					if(a[i+1]<a[i]){
						temp=a[i];
						a[i]=a[i+1];
						a[i+1]=temp;
					}
				}
			}else{//ODD LOOP
				int temp;
				#pragma omp parallel for private(temp)
				for(int i=1; i<n-1; i+=2){
					if(a[i+1]<a[i]){
						temp=a[i];
						a[i]=a[i+1];
						a[i+1]=temp;
					}
				}
			}
		}
}
	
	
	
int main(){
	clock_t ss, sp, es, ep;
	double cpu_time_serial, cpu_time_parallel;

	long long n=1000;
	printf("For n= %lld,\n", n);
	int *a , *b;
	a=malloc(n* sizeof(int));
	b=malloc(n* sizeof(int));
	for(int i=0; i<n; i++){
		a[i]=rand()%10;
		b[i]=a[i];
	}
	
	
	//SERIAL EXECUTION
	ss=clock();
	
	bubbleSort(a, n);
	
	es=clock();
	cpu_time_serial= ((double)(es-ss))/CLOCKS_PER_SEC;
	printf("Serial execution time: %lf\n", cpu_time_serial);
	
	/*printf("\nThe serially sorted array is: ");
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}*/
	//printf("\n");
	
	
	//PARALLEL EXECUTION
	sp=clock();
	
	bubbleSortp(b, n);
	
	ep=clock();
	cpu_time_parallel= ((double)(ep-sp))/CLOCKS_PER_SEC;
	printf("Parallel execution time: %lf\n", cpu_time_parallel);
	
	/*printf("\nThe parallely sorted array is: ");
	for(int i=0; i<n; i++){
		printf("%d ", b[i]);
	}*/
	printf("\n");
	
	
	//CHECK IF SAME SOLUTION
	int ctr=0;
	for(int i=0; i<n; i++){
		if(a[i]!=b[i]){
			printf("\nDifferent results generated by serial and parallel execution!\n");
			break;
		}else{
			ctr++;
		}
	}
	if(ctr==n){
		printf("Same results generated by serial and parallel execution!\n");
	}
	
	return 0;
}


//OUTPUT
/*
/////////////////////////////////////////////////////////

For n= 10,
Serial execution time: 0.000003
Parallel execution time: 0.000085

Same results generated by serial and parallel execution!
/////////////////////////////////////////////////////////

For n= 100,
Serial execution time: 0.000054
Parallel execution time: 0.000275

Same results generated by serial and parallel execution!
/////////////////////////////////////////////////////////

For n= 1000,
Serial execution time: 0.004259
Parallel execution time: 0.003585

Same results generated by serial and parallel execution!
/////////////////////////////////////////////////////////

For n= 10000,
Serial execution time: 0.548356
Parallel execution time: 0.322267

Same results generated by serial and parallel execution!
/////////////////////////////////////////////////////////
*/


