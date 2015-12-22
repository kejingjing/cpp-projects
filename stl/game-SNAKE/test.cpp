#include<iostream>
#include<string>

using namespace std;

int main()
{	while(true)
	{	/*char c;
		cout<<"Enter char";
		cin>>c;
		cout<<c;
		*/
		string s;
		cout<<"Enter string"<<endl;
		//getline(cin,s);
		cin>>s;
		cout<<s<<endl;
		cout<<"again: \n";
		getline(cin,s);
		cout<<s<<endl;

	}
	return 0;
}
