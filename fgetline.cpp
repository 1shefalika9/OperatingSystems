#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

void fgetline(ifstream &file, char delim, string filename)
{	char ch;
	string str[100];
	int i=0;
	cout<<"\nReading file \""<<filename<<"\"-----\n\n";

		while(file)
		{	file.get(ch);		
			str[i]=ch;		
			if (ch=='\n' || file.eof())
			{
				str[i]='\0';
				for(int c=0; c<i; ++c)
			  		cout<<str[c];
			  cout<<endl;
				i=0;			
			}
			else 
				i++; 
		}
}		

int main(int argc, char const *argv[])
{
	char delim;
	
	string filename;
	cout<<"\nEnter file name of the file you wish to read from: ";
	cin>>filename;
	ifstream fin;
	fin.open(filename.c_str());
	
	if (!fin)
		cout<<"Error!!Cannot open file..aborting----";

	else if(fin)
	{
		fgetline(fin,delim,filename);
	}

	fin.close();
	return 0;
}

