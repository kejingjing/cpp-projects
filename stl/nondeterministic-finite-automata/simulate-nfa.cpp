/*Simulate a pre-defined DFA for different user inputs of state transitions
in the form of alphabets of the DFA. Currently the DFA parameters like states, state transitions, DFA alphabet etc. 
are fixed. This program will be extended in the future to incorporate DFA parameters read from text files */
#include<iostream>
#include<map>
#include<set>

#include<iomanip>
#include<string>
#include<sstream>
#include<utility>

using namespace std;

struct NDFA{
multimap<pair<int,char>,int> ndfatable;
set<int> acceptingStates;
set<int> currStates;
int startState;
};

void InitializeNDFA(NDFA&);
string SimulateNDFA(NDFA&, string);
int main()
{
	NDFA ndfa;
	InitializeNDFA(ndfa);
	string input,result;

	while(true)
	{
		cout<<"Enter set of inputs: "<<endl;
		getline(cin, input);
		result = SimulateNDFA(ndfa,input);
		cout<<"Output of Non-Deterministic Finite Automata is: "<<result<<endl;
		cout<<"(Press Return) ";
		string c;
		getline(cin,c);
	}

}

void InitializeNDFA(NDFA& ndfa)
{
	//Populate NDFA table
	ndfa.ndfatable.insert(make_pair(make_pair(0,'0'), 0));
	ndfa.ndfatable.insert(make_pair(make_pair(0,'0'), 1));
	ndfa.ndfatable.insert(make_pair(make_pair(0,'1'), 0));
	ndfa.ndfatable.insert(make_pair(make_pair(0,'1'), 3));
	ndfa.ndfatable.insert(make_pair(make_pair(1,'0'), 2));
	ndfa.ndfatable.insert(make_pair(make_pair(3,'1'), 4));
	//Set startstate
	ndfa.startState = 0;
	//Set currstates containing startState only
	ndfa.currStates.insert(ndfa.startState);
	//Set accepting states
	ndfa.acceptingStates.insert(2);
	ndfa.acceptingStates.insert(4);

}

string SimulateNDFA(NDFA& ndfa,string input)
{
	
	for(string::iterator itr = input.begin(); itr != input.end(); ++itr)
	{	set<int> nextStates;
		for(set<int>::iterator itr2 = ndfa.currStates.begin(); itr2 != ndfa.currStates.end(); ++itr2)
		{
			pair<multimap<pair<int,char>,int>::iterator,multimap<pair<int,char>,int>::iterator>
				action = ndfa.ndfatable.equal_range(make_pair(*itr2,*itr));
				
			for(multimap<pair<int,char>,int>::iterator itr3 = action.first; itr3 != action.second; ++itr3)
			{
				nextStates.insert(itr3->second);
			}
		}
		ndfa.currStates = nextStates;
	}

for(set<int>::iterator itr = ndfa.currStates.begin(); itr != ndfa.currStates.end(); ++itr)
{
	if(ndfa.acceptingStates.count(*itr))
	{
		return "Accepted!";

	}
	
}

return "Rejected :(";

}
