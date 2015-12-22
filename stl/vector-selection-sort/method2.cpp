#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

int getInteger()
{
	
	while(true)
	{
		string intString;
		stringstream myStream;
		int n;
		getline(cin,intString);
		myStream<<intString;

		if(myStream>>n)
		{
			char remaining;
			if(myStream>>remaining)
			{
				cout<<"Invalid Integer \n";

			}
			else
			{
				return n;
			}
		}
		else		
		{
			cout<<"Not an Integer \n";
		}
	cout<<"Retry: ";
	}
		
}


size_t getBestIndex(vector<int>& v, int n)
{	//Calculate appropriate index to insert new integer
	for(size_t i=0; i<v.size(); ++i)
	{
		if (n<v[i])
		{
			return i;
		}
	}
	return v.size();
}

int main()
{
	int kNumValues = 10, v;
	size_t appropriate_index;
	vector<int> val;
	
	//Getting input from user and storing in vector<int> val at appropriate location
	for(int i=0; i<kNumValues; ++i)
	{   cout<<"Enter another integer: ";
		
		//cin>>v;
		v=getInteger();
		appropriate_index = getBestIndex(val,v);
		val.insert(val.begin()+appropriate_index, v);

	}

	//Print sorted vector
	for(size_t i=0; i<val.size(); ++i)
	{
		cout<<val[i]<<endl;

	}
	return 0;
}