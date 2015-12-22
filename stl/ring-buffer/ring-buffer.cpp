#include<iostream>
#include<deque>
#include<string>
#include<sstream>
#include<cstdlib>

using namespace std;


const string clearcommand = "clear";
const int numValues = 10;
void displayMenu(deque<int>& );
void performOperation(int , deque<int>&);
void Pause(double t);
void rotatecounterclockwise(deque<int>&);
void rotateclockwise(deque<int>&);
void readelement(deque<int>&);
void writeelement(deque<int>&);
int getInteger()
{
	while(true)
	{
		stringstream intStream;
		string intString;
		int value;
		
		getline(cin,intString);
		intStream<<intString;
		if(intStream>>value)
		{	char remaining;
			if(intStream>>remaining)
			{
				cout<<"Not a valid integer \n";
			}
			else
			{
				return value;
			}
		}
		else
		{
			cout<<"Enter an integer please \n";
		}

		cout<<"Retry \n";
	}


}



int main()
{	deque<int> ringbuffer;
	cout<<"Enter numbers for ring buffer in clockwise manner \n";
	for(int i=0; i<numValues; ++i)
	{
		ringbuffer.push_back(getInteger());
	}
	while(true)
	{	displayMenu(ringbuffer);
		cout<<"Select number corresponding to operation to be performed \n";
		int option = getInteger();
		performOperation(option, ringbuffer);
	}
}


void displayMenu(deque<int>& buffer)
{	system(clearcommand.c_str());
	cout<<"Current ringbuffer \n";
	for(size_t i=0; i<buffer.size(); ++i)
	{
		cout<<buffer[i]<<"\t";
	}
	cout<<endl;
	cout<<"Options are \n 1. Rotate counter-clockwise \n 2. Rotate clockwise \n 3. Read element at cursor \n 4. Write element at cursor \n";

}

void performOperation(int option , deque<int>& buffer)
{
	switch(option){
	
		case 1: rotatecounterclockwise(buffer);
		break;
		case 2: rotateclockwise(buffer);
		break;
		case 3: readelement(buffer);
		break;
		case 4: writeelement(buffer);
		break;
		default: "Not a valid option; Retry \n";
		break;		
	}
	Pause(0.2);
}

void Pause(double t)
{
	clock_t startTime = clock();
	while(static_cast<double>(clock() - startTime)/CLOCKS_PER_SEC < t);
}
void rotateclockwise(deque<int>& buffer)
{
	int popped;

	popped = buffer.back();
	buffer.pop_back();
	buffer.push_front(popped);
}

void rotatecounterclockwise(deque<int>& buffer)
{
	int popped;
	popped = buffer.front();
	buffer.pop_front();
	buffer.push_back(popped);
}
void readelement(deque<int>& buffer)
{
	int number = buffer.front();
	cout<<"Number at cursor: "<<number<<endl;
	Pause(0.2);
}
void writeelement(deque<int>&buffer)
{
	int number = getInteger();
	buffer.front() = number;
}