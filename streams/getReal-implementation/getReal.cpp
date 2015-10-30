#include<iostream>
#include<sstream>
#include<string>
using namespace std;

double getReal();
int main()
{

	cout<<"Enter Real Number \n";
	double num = getReal();
	cout<<"You entered:"<<num<<endl;

}

double getReal()
{
	while(true)
	{
		//realString = getline(cin, realString);
		string realString;
		stringstream myStream;
		double realnum;
		getline(cin,realString);
		
		myStream<<realString;
		
		if(myStream>>realnum)
		{	
			char remaining;
			if(myStream>>remaining)
			{
				cout<<remaining<<endl;
				cout<<"Not a valid input \n";
			}
			else
				{return realnum;}

		}
		else
		{
			cout<<"Enter a real number \n";
		}

		cout<<"retry: \n";

	}




}