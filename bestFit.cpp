//SHEFALIKA GHOSH
//19544
//Program to implement best fit memory allocation strategy

#include <iostream>
using namespace std;

void sortAsc(int mem[], int block_no[], int blocks){
	for (int k = 0; k < blocks; ++k)
	{
		for (int m = k+1; m < blocks; ++m)
		{
			if(mem[k] > mem[m])
			{	int temp;
				int bno;

				temp=mem[k];
				bno = block_no[k];

				mem[k]=mem[m];
				block_no[k] = block_no[m];

				mem[m]=temp;
				block_no[m] = bno;
			}
		}
	}
}

int main(int argc, char const *argv[])
{	
	int blocks, n;
	
	cout<<"\nEnter the no. of memory blocks available: ";
	cin>>blocks;
	int mem[blocks], block_no[blocks];
	cout<<"\nEnter the size of each memory block: ";
	for (int i = 0; i < blocks; ++i)
	{
		cout<<"\nSize of memory block "<<i+1<<": ";
		cin>>mem[i];
		block_no[i] = i+1;
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

		//sort the memory blocks in ascending order
		sortAsc(mem, block_no, blocks);
		
		//allocating blocks to processes
		for (int i = 0; i < n; ++i)
		{	int j;
			for (j = 0; j < blocks; ++j)
			{
				if (mem[j] >= prc[i])
				{	
					mem[j]-=prc[i];
					cout<<"\nProcess "<<i+1<<" allocated to memory block "<<block_no[j];
					cout<<"\nSize remaining in memory block "<<block_no[j]<<" after allocation: "<<mem[j];
					break;
				}
			}
			if(j==blocks)
         		cout<<"\nNot enough memory for process "<<i+1<<" in any block";

			//sort the memory blocks in ascending order
			sortAsc(mem, block_no, blocks);         	   
		}
	}

	return 0;
}