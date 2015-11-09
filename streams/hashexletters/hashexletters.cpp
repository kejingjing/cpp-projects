#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int getInteger();
bool hashexletters(int);

int main()
{
	

	while(true)
	{	cout<<"Enter Integer: ";
		int x=getInteger();
		cout<<"You Entered: "<<x<<endl;
		bool result = false;
		result = hashexletters(x);
		if(result==true)
		{
			cout<<"'HasHexLetters' \n";
		}
		else
		{
			cout<<"'NoHasHexLeter' \n";
		}

	}	
}

int getInteger()
{
	
	while(true)
	{	
		stringstream mystream;
		string input;
		int x;
		char remaining;
		float remainingfloat;
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
			cout<<"Retry: ";
	
	}
}

bool hashexletters(int x)
{
	stringstream myStream;
	myStream<<x;
	int num;
	myStream>>hex>>num;
	//cout<<num;
	if(num>10)
	{
		return true;
	}
	else
	{
		return false;

	}


}