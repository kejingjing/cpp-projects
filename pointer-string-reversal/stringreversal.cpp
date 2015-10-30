#include<iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{

	string inputString;
	cout<<"Enter String \n";
	getline(cin, inputString);
	char st_r[inputString.length()];
	strcpy(st_r, inputString.c_str());
	
	char *pStart = st_r;
	char *pEnd = st_r + inputString.length()-1;


	char temp;

	while(pStart < pEnd)
	{
		temp=*pStart;
		*pStart=*pEnd;
		*pEnd=temp;
		pStart++;
		pEnd--;
	}

	
	
	cout<<st_r<<"\n";


	return 0;
}	