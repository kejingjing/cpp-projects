#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void OpenFile(ifstream&);

int main()
{
	ifstream myStream;
	OpenFile(myStream);	
	return 0;

}

void OpenFile(ifstream& myStream)
{

	while(true)
	{	string fileName;
		cout<<"Enter file name to be opened: \n";
		getline(cin, fileName);
		myStream.open(fileName.c_str());
		if(myStream.fail())
		{
			cerr<<"File nonexistant, retry \n";

		}
		else
		{	
			cout<<"File Opened...";
			break;
		}


	}


}