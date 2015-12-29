#include<iostream>
#include<vector>
#include<cctype>
#include<string>
#include<numeric>
#include<algorithm>
using namespace std;

bool isNotAlphabet(char);
string checkIfPalindrome(string&);
int main()

{

	//take string input
	cout << "Enter input string \n";
	string input, result;
	while(true)
	{	getline(cin,input);

	//remove everything except letters
		input.erase(remove_if(input.begin(), input.end(), isNotAlphabet), input.end());
	
	//check if string is palndrome

		result = checkIfPalindrome(input);

		cout<<result<<endl;
	}
	return 0;
}

bool isNotAlphabet(char c)
{
	return !isalpha(c);
}

string checkIfPalindrome(string& input)
{
	//transform string to uppercase
	transform(input.begin(), input.end(), input.begin(), ::toupper);

	if(equal(input.begin(), input.begin() + (input.size()/2), input.rbegin()))
	{
		return "Palindrome";
	}
	
	return "Not Palindrome";




}