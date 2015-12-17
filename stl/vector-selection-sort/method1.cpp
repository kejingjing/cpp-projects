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

size_t getSmallestIndex(vector<int>& v, size_t ind)
{	size_t smallestIndex =ind;
	for(size_t i = ind; i<v.size(); ++i)
	{
		if(v[i]<v[smallestIndex])
		{
			smallestIndex=i;
		}
	}
	return smallestIndex;
}

void selectionSort(vector<int>& v)
{	size_t bestIndex;
	for (size_t i=0; i<v.size(); ++i)
	{
		bestIndex = getSmallestIndex(v,i);
		swap(v[i], v[bestIndex]);

	}


}
int main()
{
	int kNumValues = 10, v;
	//cout<<"Hello World!!!!";
	vector<int> val;
	//Getting input from user and storing in vector<int> val
	for(int i=0; i<kNumValues; ++i)
	{   cout<<"Enter another integer: ";
		
		//cin>>v;
		v=getInteger();
		val.push_back(v);

	}

	//Sorting vector using selectionsort

	selectionSort(val);
	//Print out sorted vector
	for(size_t i=0; i<val.size(); ++i)
	{
		cout<<val[i]<<endl;

	}
	return 0;
}