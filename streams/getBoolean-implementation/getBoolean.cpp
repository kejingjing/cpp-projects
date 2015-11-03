#include<iostream>
#include<sstream>
#include<string>
using namespace std;

bool getBoolean();

int main()
{
	while(true)
	{
		bool value = getBoolean();
		cout<<"Corresponding boolean value: "<<value<<endl;
	}

}

bool getBoolean()
{

		while(true)
		{
	 	cout<<"Enter true or false"<<endl;
		string myString;
		stringstream myStream;
		bool value; 
		getline(cin,myString);
		myStream<<myString;
		if(myStream>>boolalpha>>value)
		{
			char remaining;
			if(myStream>>remaining)
			{
			cout<<"Invalid input \n";	

			}
			else
			{
				return value;
			}
		}
		else
		{
			cout<<"Enter Boolean Please"<<endl;
		}
		cout<<"retry"<<endl;
		}


}