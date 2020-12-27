#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void readFile(ifstream& fin){
	char delim, choice, ch;;
		cout<<"\nDo you wish to read file with default delimiter-\"\\n\"?(y/n): ";
		cin>>choice;
		if(choice=='n')
    	{
    		cout<<"\nEnter the delimiter: ";
			  cin>>delim;
    	}
    	else
    		delim='\n';
	
		while(fin){
			fin.get(ch);
			if(ch==delim)
				cout<<"\n";
			else if(ch=='\n')
				continue;
			else
				cout<<ch;
		}
}

int main(int argc, char const *argv[])
{
	string filename;
	cout<<"\nEnter file name of the file you wish to read from: ";
	cin>>filename;
	ifstream fin(filename.c_str());

	if (!fin)
		cout<<"Error!!Cannot open file..aborting----";

	else if(fin){
		readFile(fin);
	}

	fin.close();
	
	return 0;
}