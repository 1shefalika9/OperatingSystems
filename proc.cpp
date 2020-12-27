#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		cout<<"\nNo command-line arguments entered!! Try one of the following:";
		cout<<"\nType: ./proc 1 - to display the Kernel version";
		cout<<"\nType: ./proc 2 - to display the CPU information ";
		cout<<"\nType: ./proc 3 - to display the memory information";
		cout<<"\nType: ./proc 1 2 - to display the Kernel version and CPU information and so on";
		return -1;
	}

	else{
		int choice;
		for(int i=1; i<argc; i++)
		 {  choice = stoi(argv[i]);
			switch(choice){
				case 1: cout<<"\nKernel version: \n";
						system("cat /proc/version|awk '{print $1,$2, $3}'");
						break; 
				case 2: cout<<"\nCPU information:\n\n";
						cout<<"1. Vendor Id-\n";
						system("cat /proc/cpuinfo|awk 'NR==2'|awk '{print $3}'");
						cout<<"\n2. CPU family-\n";
						system("cat /proc/cpuinfo|awk 'NR==3'|awk '{print $4}'");
						cout<<"\n3. CPU Model-\n";
						system("cat /proc/cpuinfo|awk 'NR==4'|awk '{print $3}'");
						cout<<"\n4. Model Name-\n";
						system("cat /proc/cpuinfo|awk 'NR==5'|awk '{print $4, $5, $6, $7, $8, $9}'");
						cout<<"\n5. Processor Speed-\n";
						system("cat /proc/cpuinfo|awk 'NR==8'|awk '{print $4}'");
						cout<<"\n6. Cache size-\n";
						system("cat /proc/cpuinfo|awk 'NR==9'|awk '{print $4}'");
						cout<<"\n7. No. of CPU cores-\n";
						system("cat /proc/cpuinfo|awk 'NR==13'|awk '{print $4}'");
						break;
				case 3: cout<<"\nMemory information:\n\n";
				    	cout<<"Total usable RAM-\n";
				    	system("cat /proc/meminfo|awk 'NR==1'|awk '{print $2, $3}'");
				    	cout<<"Free memory-\n";
				    	system("cat /proc/meminfo|awk 'NR==2'|awk '{print $2, $3}'");
				    	break;
				default:cout<<"Command-line argument not valid!! Exiting----";
						break;
			}
		}
	}
	return 0;
}