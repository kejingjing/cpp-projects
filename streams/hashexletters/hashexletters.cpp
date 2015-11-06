#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int getInteger();
bool hashexletters(int);

int main()
{
	

	while(true)
	{	cout<<"Enter Integer"<<endl;
		int x=getInteger();
		bool result = hashexletters(x);
	}	
}

int getInteger()
{
	stringstream mystream;
	string input;
	int x;
	char remaining;
	float remainingfloat;
	while(true)
	{	
		getline(cin,input);
		mystream<<input;
		if(mystream>>x)
		{

			if(mystream>>remaining || mystream>>remainingfloat)
			{
				cout<<"Enter proper integer"<<endl;
			}
			else
			{
				return x;				
			}
	
		}
		else
			cout<<"Retry"<<endl;
	
	}
}

bool hashexletters(int)
{
	return true;
}