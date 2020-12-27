//SHEFALIKA GHOSH
//19544
//Program to implement first fit memory allocation strategy

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{	
	int blocks, n;
	
	cout<<"\nEnter the no. of memory blocks available: ";
	cin>>blocks;
	int mem[blocks];
	cout<<"\nEnter the size of each memory block: ";
	for (int i = 0; i < blocks; ++i)
	{
		cout<<"\nSize of memory block "<<i+1<<": ";
		cin>>mem[i];
	}
	cout<<"\nEnter the no. of processes: ";
	cin>>n;
	if(n>blocks)
		cout<<"\nNot enough memory blocks available for all processes!!";
	else{
		cout<<"\nEnter the size of each process: ";
		int prc[n];
		for (int i = 0; i < n; ++i)
		{
			cout<<"\nSize of process "<<i+1<<": ";
			cin>>prc[i];
		}
	
		for (int i = 0; i < n; ++i)
		{	int j;
			for (j = 0; j < blocks; ++j)
			{
				if (mem[j] >= prc[i])
				{	
					mem[j]-=prc[i];
					cout<<"\nProcess "<<i+1<<" allocated to memory block "<<j+1;
					cout<<"\nSize remaining in memory block "<<j+1<<" after allocation: "<<mem[j];
					break;
				}
			}
			if(j==blocks)
         		cout<<"\nNot enough memory for process "<<i+1<<" in any block";         	   
		}
	}

	return 0;
}