#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;
const int numIterations = 10000;

int DieRoll()
{
	int num = (rand()%6) + 1;
	return num;
}
size_t repeatCheck();
int main()
{	
	srand(static_cast<unsigned int>(time(NULL)));
	size_t numberofRolls=0;
	for(int k=0; k<numIterations; ++k)
	{	numberofRolls += repeatCheck();
		
	}
	cout<<"Average number of rolls before repeated number: "<<((double)numberofRolls/numIterations)<<endl;
}
size_t repeatCheck()
{	
	//Uncomment for implementation using sets (more efficient and intuitive since we are dealing with unordered lists). This implementation does not contain
	//any for loops but you also have no concept of 'where' the element occurs in the sequence, which technically is not required in our application
	set<int> numbersRolled;
	while(true)
	{
		int currRoll = DieRoll();
		if(numbersRolled.count(currRoll)) return numbersRolled.size();
		numbersRolled.insert(currRoll);
	}



	/*Uncomment for implementation using vectors
	vector<int> numbersRolled;
	while(true)
	{
		int currRoll = DieRoll();

		for(size_t i=0; i< numbersRolled.size(); ++i)
			{
				if (numbersRolled[i]==currRoll)
				{
					return numbersRolled.size() + 1;
				}
			}
		numbersRolled.push_back(currRoll);
	*/
}
}