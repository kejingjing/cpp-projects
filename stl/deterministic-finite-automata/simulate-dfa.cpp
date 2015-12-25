/*Simulate a pre-defined DFA for different user inputs of state transitions
in the form of alphabets of the DFA. Currently the DFA parameters like states, state transitions, DFA alphabet etc. 
are fixed. This program will be extended in the future to incorporate DFA parameters read from text files */
#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<string>
#include<sstream>
#include<cstdlib>
#include<iomanip>


using namespace std;

struct DFA
{
	map<pair<int, char>, int> DFAtable;
	set<int> acceptingStates;
	int startState;
	int currState;
	
};


void InitializeDFA(DFA& dfa);
void DisplayDFA(DFA& dfa);
string simulateDFA(DFA& dfa, string input);

int main()
{
	string input;
	DFA dfa;
	InitializeDFA(dfa);
	while(true)
	{	DisplayDFA(dfa);
		cout<<"Enter input in form of alphabets \n";
		getline(cin,input);
		string result = simulateDFA(dfa,input);
		cout<<"Output of Deterministic Finite Automata is: "<<result<<endl;
		cout<<"(Press Return) ";
		string c;
		getline(cin,c);


	}



}
void InitializeDFA(DFA& dfa)
{
	
	//Populate DFA transition table for current DFA
	dfa.DFAtable[make_pair(0, '0')] = 1;
	dfa.DFAtable[make_pair(0, '1')] = 2;
	dfa.DFAtable[make_pair(1, '0')] = 0;
	dfa.DFAtable[make_pair(1, '1')] = 3;
	dfa.DFAtable[make_pair(2, '0')] = 3;
	dfa.DFAtable[make_pair(2, '1')] = 0;
	dfa.DFAtable[make_pair(3, '0')] = 2;
	dfa.DFAtable[make_pair(3, '1')] = 1;
	//Define DFA accepting states
	dfa.acceptingStates.insert(3);



}
string simulateDFA(DFA& dfa, string input)
{
	int currState = dfa.currState;
	for(size_t i=0; i<input.size(); ++i)
	{
		char command = input[i];
		map<pair<int,char>, int>::iterator itr = dfa.DFAtable.find(make_pair(currState,command));
		currState = itr->second;
	}
	if(dfa.acceptingStates.count(currState))
	{
		
		return "Accepted!";

	}
	return "Rejected :(";


}

void DisplayDFA(DFA& dfa)
{	string clearcommand = "clear";
	system(clearcommand.c_str());
	map<pair<int,char>, int> DFAtable = dfa.DFAtable;
	cout<<setw(10)<<"States |"<<setw(10)<<"Transition |"<<setw(10)<<"Resulting State \n";
	for(map<pair<int,char>, int>::iterator itr = DFAtable.begin(); itr != DFAtable.end(); ++itr)
	{
		cout << setw(10) << itr->first.first << " |"<< setw(10)<< itr->first.second << " |" << setw(10) << itr->second << endl;
	}
}