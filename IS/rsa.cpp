/*Name: Amruta Nandargi
Roll No.: PF21
Problem Statement: RSA Algorithm*/

/*CODE*/
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

//gcd function
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}

//prime number checker
bool isPrime(int a){
  for(int i=2; i<=a/2; i++){
    if(a%i==0){
      return false;
    }
  }
  return true;
}

//driver function
int main(){
  double p, q, z, d, n, e, c, x, C, X, m;

  //accepting p & q
  do{
    cout<<"\nEnter a prime number (p): ";
    cin>>p;
    if(!isPrime(p)){
      cout<<p<<" is not a Prime Number";
    }
  }while(!isPrime(p));
  do{
    cout<<"\nEnter a prime number (q): ";
    cin>>q;
    if(!isPrime(q)){
      cout<<q<<" is not a Prime Number";
    }
  }while(!isPrime(q));
  
  //calculating n
	n=p*q;
	cout<<"\nn= "<<n<<endl;

  //calculating z
	z=(p-1)*(q-1);
	cout<<"\nz= "<<z<<endl;

  //calculating d
	for(int i=7; i<z; i++){
		if(gcd(i, z)==1){
			d=i;
			cout<<"\nd= "<<d<<endl;
			break;
		}
	}      

  //calculating e                              
  double e1;
  e1=1 /d;
  e = fmod(e1, z);
  cout<<"\ne= "<<e<<endl;
  cout<<"\nEnter message:"<<endl;
  cin>>m;
    
  //Encryption with d
  c= pow(m, d);
  C=fmod(c,n);
    
  cout<<"\nEncrypted message:"<<endl;
  cout<<C<<endl;
    

  //Decryption with e
  x= pow(c, e);
  X=fmod(x,n);

  cout<<"\nDecrypted message:"<<endl;
  cout<<X;
  cout<<endl;

	return 0;
}


/*OUTPUT:
Enter a prime number (p): 23

Enter a prime number (q): 11

n= 253

z= 220

d= 7

e= 0.142857

Enter message:
9

Encrypted message:
4

Decrypted message:
9
*/