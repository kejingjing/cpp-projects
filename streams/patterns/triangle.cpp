#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
using namespace std;

int getInteger();
void displayPattern(int, string);

int main()
{

	while(true)
	{	cout<<"Enter Height(Integer): ";
		int x=getInteger();
		cout<<x<<endl;
		cout<<"Enter character to print: ";
		string c;
		getline(cin,c);
		displayPattern(x,c);
	}
	return 0;
}

int getInteger()
{

	while(true)
	{
		stringstream myStream;
		string input;
		getline(cin,input);
		int x;
		char rem;
		myStream<<input;
		if(myStream>>x)
		{
			if(myStream>>rem)
			{
				cout<<"Invalid Integer \n";
			}
			else
			{
				return x;
			}
		}
		cout<<"Retry \n";
	}


}
void displayPattern(int height, string s)
{

	for(int i=0; i<height; ++i)
	{	cout<<setw(height-i);
			for(int j=1; j<=2*(i+1)-1; ++j)
		
		{cout<<s;
		}
		cout<<endl;
	}


}