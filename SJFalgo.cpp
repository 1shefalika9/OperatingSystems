//SHEFALIKA GHOSH
//19544
/* Implementing Shortest Job First algorithm */

#include <iostream>
#include <iomanip>
using namespace std;

struct process
{
	int pno;
	int btime;
};

int main(int argc, char const *argv[])
{
	int n;
	cout<<"How many processes: ";
	cin>>n;
	process p[n];
	cout<<"Enter the burst time of each process--\n";
	for (int i = 0; i < n; ++i)
	{	
		cout<<"\nProcess "<<i+1;
		p[i].pno = i+1;
		cout<<"\nBurst time: ";
		cin>>p[i].btime;
	}

  //sorting the processes in increasing order of burst time
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(p[i].btime > p[j].btime)
			{	process temp;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}

	int wtime[n];
	int tat_time[n];
	wtime[0] = 0;
	tat_time[0] = p[0].btime;

	int sum_tat = 0;
	int sum_wait = 0;
	for (int i = 1; i < n; ++i)
	{	
		wtime[i] = wtime[i-1] + p[i-1].btime;
		sum_wait+= wtime[i];
		tat_time[i] = wtime[i] + p[i].btime;		
		sum_tat+= tat_time[i];
	}

	cout<<"\nProcess"<<"  "<<"Wait_Time"<<"  "<<"Turnaround_Time\n";
	for (int i = 0; i < n; ++i)
		cout<<setw(4)<<p[i].pno<<setw(10)<<wtime[i]<<setw(14)<<tat_time[i]<<"\n";

	float avg_wait, avg_tat;
	avg_wait = (float)sum_wait/n;
	avg_tat = (float)sum_tat/n;
	cout<<"\nThe average wait time is: "<<avg_wait<<" time units\n";
	cout<<"The average turnaround time is: "<<avg_tat<<" time units\n";

	return 0;
}