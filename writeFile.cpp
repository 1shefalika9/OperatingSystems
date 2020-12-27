#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void writeFile(ofstream& file){
    char ch;

    while (file) {
        cin.get(ch);
        if(ch=='~')
            break;
        else 
            file.put(ch);
        
    } 
}

int main(int argc, char const *argv[])
{
	string filename;
    cout<<"\nEnter file name of the file you'll write to: ";
    cin>>filename;
	ofstream fout;
    cout<<"\nChoose one of the following-";
    cout<<"\n1.Overwrite the destination file.\n2.Append the destination file\n";
    int choice;
    cin>>choice;

    if (choice==1)
        fout.open(filename.c_str());
        
    else if(choice==2)
        fout.open(filename.c_str(), ios::app);

    cout<<"\nType whatever you wish in file. Type '~' to exit: \n";
    writeFile(fout);    

	fout.close();
	return 0;
}

