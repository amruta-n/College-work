// Name: Amruta Nandargi
// Roll No.: PF-21
// Panel: 6/F

#include <iostream>
#include<string.h>
using namespace std;
int main()
{
	//string input
	char str[100];
	cout<<"Enter a string:";
	cin>>str;

	//Shift value
	cout<<"---------------------CAESAR CIPHER-----------------"<<endl;
	int n;
	cout<<"Enter a number between 0-25:";
	cin>>n; 
	if(n<0 || n>25){
		do{
			cout<<"Please enter a number between 0-25:"<<endl;
			cin>>n;
		}while(n<0 || n>25);
	}

	//encryption
	for(int i =0; i<strlen(str); i++){
		if(str[i]>='a'&& str[i]<='z'){
			str[i]=str[i]+n;
			if(str[i]>'z'){
				str[i]=str[i]-'z'+'a'-1;
			}
		}else if(str[i]>='A'&& str[i]<='Z'){
			str[i]=str[i]+n;
			if(str[i]>'Z'){
				str[i]=str[i]-'Z'+'A'-1;
			}
		}
		
	}
	cout<<"Encrypted String:"<<str<<endl;

	//decryption
	for(int i =0; i<strlen(str); i++){
		if(str[i]>='a'&& str[i]<='z'){
			str[i]=str[i]-n;
			if(str[i]<'a'){
				str[i]=str[i]+'z'-'a'+1;
			}
		}else if(str[i]>='A'&& str[i]<='Z'){
			str[i]=str[i]+n;
			if(str[i]<'A'){
				str[i]=str[i]+'Z'-'A'+1;
			}
		}
		
	}
	cout<<"Decrypted String:"<<str<<endl;

	cout<<"---------------------MONOALPHABETIC SUBSTITUION-----------------"<<endl;

	//monoalphabetic encryption
	char p[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x', 'y', 'z'};
	char ch[]={'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O','P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C','V', 'B', 'N', 'M'};
	for(int i =0; i<strlen(str); i++){
		for(int j =0; j<26; j++){
			if(p[j]==str[i]){
				str[i]=ch[j];
				break;
			}
		}
	}

	cout<<"Encrypted String:"<<str<<endl;

	//mono decipher
	for(int i =0; i<strlen(str); i++){
		for(int j =0; j<26; j++){
			if(ch[j]==str[i]){
				str[i]=p[j];
				break;
			}
		}
	}
	cout<<"Decrypted String:"<<str<<endl;
	return 0;
}

// OUTPUT:
// Enter a string:cat
// ---------------------CAESAR CIPHER-----------------
// Enter a number between 0-25:6
// Encrypted String:igz
// Decrypted String:cat
// ---------------------MONOALPHABETIC SUBSTITUION-----------------
// Encrypted String:EQZ
// Decrypted String:cat