#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<fstream>
#include<utility>
#include<set>
#include<cctype>

using namespace std;

/* Function: OpenUserFile(ifstream& fileStream);
     * Usage: OpenUserFile(myStream);
     * -------------------------------------------------
     * Prompts the user for a filename until a valid filename
     * is entered, then sets fileStream to read from that file.
     */
void OpenUserFile(ifstream& fileStream);
    /* Function: GetFileContents(ifstream& file);
     * Usage: string contents = GetFileContents(ifstream& file);
     * -------------------------------------------------
     * Returns a string containing the contents of the file passed
     * in as a parameter.
     */
string GetFileContents(ifstream& file);
    /* Function: GenerateKeywordReport(string text);
     * Usage: map<string, size_t> keywords = GenerateKeywordReport(contents);
     * -------------------------------------------------
     * Returns a map from keywords to the frequency at which those keywords
     * appear in the input text string.  Keywords not contained in the text will
     * not appear in the map.
     */
map<string, size_t> GenerateKeywordReport(string contents);

int main()
{	ifstream input;
	OpenUserFile(input);
	map<string, size_t> keywordMap = GenerateKeywordReport(GetFileContents(input));
	for(map<string, size_t>::iterator itr = keywordMap.begin(); itr!=keywordMap.end(); ++ itr)
	{
		cout<<"Keyword "<<itr->first<<" occurred "<<itr->second<<" times \n";
	}

	return 0;
}
void OpenUserFile(ifstream& fileStream)
{
	while(true)
	{	string filename;
		cout<<"Enter filename \n";
		getline(cin, filename);
		fileStream.open(filename.c_str());
		if(fileStream.is_open())
		{
			return;
		}
		cout<<"Couldn't find file, retry:\n";
		fileStream.clear();

	}
}	 
string GetFileContents(ifstream& file)
{	string result;
	string line;
	while(getline(file, line))
	{
		result += line + "\n";
	}
	return result;
}

set<string> LoadKeywords()
{
	set<string> keywordSet;
	ifstream keywordFile("keywords.txt");
	string keyword;
	while(keywordFile>>keyword)
	{
		keywordSet.insert(keyword);
	}
	return keywordSet;

}
void PreprocessString(string& text)
{
	for(size_t k=0; k<text.size(); ++k)
	{
		if(ispunct(text[k]) && text[k] != '_')
		{
			text[k]=' ';
		}
	}
}
map<string, size_t> GenerateKeywordReport(string contents)
{
	set<string> keywordSet = LoadKeywords();
	PreprocessString(contents);
	stringstream tokenizer;
	tokenizer<<contents;
	map<string,size_t> result;
	string word;

	while(tokenizer>>word)
	{
		if(keywordSet.count(word))
		{
			++result[word];
		}
	}
	return result;
}