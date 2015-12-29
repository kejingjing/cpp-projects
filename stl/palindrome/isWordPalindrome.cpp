#include<iostream>
#include<vector>
#include<cctype>
#include<string>
#include<numeric>
#include<algorithm>
#include<sstream>
#include<iterator>
using namespace std;
bool isNotAlphabetorSpace(char);
string checkIfPalindrome(string& input);
int main()

{

	//take string input
	cout << "Enter input string \n";
	string input, result;
	while(true)
	{	getline(cin,input);

	//remove everything except letters & spaces
		input.erase(remove_if(input.begin(), input.end(), isNotAlphabetorSpace), input.end());
	
	//check if string is palndrome

		result = checkIfPalindrome(input);

		cout<<result<<endl;
	}
	return 0;
}

bool isNotAlphabetorSpace(char c)
{
	return !isalpha(c) && !isspace(c);
}

string checkIfPalindrome(string& input)
{
	//transform string to uppercase
	transform(input.begin(), input.end(), input.begin(), ::toupper);
	//write input string to a stringstream
	stringstream s(input);
	vector<string> tokens;
	copy(istream_iterator<string>(s), istream_iterator<string>(), back_inserter(tokens));


	if(equal(tokens.begin(), tokens.begin() + (tokens.size()/2), tokens.rbegin()))
	{
		return "Palindrome";
	}
	
	return "Not Palindrome";
}