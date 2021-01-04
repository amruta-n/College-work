/*Name: Amruta Nandargi
Roll No.: PF21
Problem Statement: Design and implement a parallel algorithm to add/subtract/mutiply two large vectors using C programming language*/

//CODE
#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdlib.h>

int main(){
	clock_t ss, sp, es, ep;
	double cpu_time_serial, cpu_time_parallel;
	
	int *a, *b, *c, *adds, *addp, *subp, *subs, *mulp, *muls;
	
	long long n=100000000, i, ctr=0;
	printf("For n=%lld,\n", n);
	//int c[n][1];
	a=malloc(n* sizeof(int));
	b=malloc(n* sizeof(int));
	c=malloc(n* sizeof(int));
	adds=malloc(n* sizeof(int));
	subs=malloc(n* sizeof(int));
	addp=malloc(n* sizeof(int));
	subp=malloc(n* sizeof(int));
	muls=malloc(n* sizeof(int));
	mulp=malloc(n* sizeof(int));
	
	for(i =0; i<n; i++){
		a[i]=rand()%10;
	}
	for(i =0; i<n; i++){
		b[i]=rand()%10;
	}
	for(i =0; i<n; i++){
		c[i]=rand()%10;
	}
	
	//SERIAL
	ss=clock();
	for(i =0; i<n; i++){
		adds[i]=a[i]+b[i];
		subs[i]=a[i]-b[i];
		muls[i]=a[i]*b[i];
	}
	es=clock();
	cpu_time_serial= ((double)(es-ss))/CLOCKS_PER_SEC;
	printf("Serial execution time: %f\n", cpu_time_serial);
	
	//PARALLEL
	sp=clock();
	#pragma omp parallel for shared(a, b, c, addp, mulp, subp) private(i)
		for(i =0; i<n; i++){
			addp[i]=a[i]+b[i];
			subp[i]=a[i]-b[i];
			mulp[i]=a[i]*b[i];
		}
	ep=clock();
	cpu_time_parallel= ((double)(ep-sp))/CLOCKS_PER_SEC;
	printf("Parallel execution time: %f\n", cpu_time_parallel);
	
	for(i=0; i<n; i++){
		if(addp[i]!=adds[i] || subp[i]!=subs[i] || mulp[i]!=muls[i]){
			printf("\nThe result of serial and parallel operations are not the same\n");
			break;
		}
	}
	
	free(a);
	free(b);
	free(adds);
	free(subs);
	free(addp);
	free(subp);
	free(mulp);
	free(muls);
	return 0;
}


//OUTPUT
/*
///////////////////////////////////////

For n=10,
Serial execution time: 0.000002
Parallel execution time: 0.000105
///////////////////////////////////////

For n=1000,
Serial execution time: 0.000008
Parallel execution time: 0.000075
///////////////////////////////////////

For n=100000,
Serial execution time: 0.001310
Parallel execution time: 0.000878
///////////////////////////////////////

For n=1000000,
Serial execution time: 0.017646
Parallel execution time: 0.012031
///////////////////////////////////////
*/

