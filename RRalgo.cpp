//SHEFALIKA GHOSH
//19544
/* Implementing Round Robin algorithm; assuming a time quantum of 2 time units */
/* Objective- To display a gantt-chart representation with times-units and process executing at that time-unit along with wait-time and turnaround-time for each process when using round robin scheduling algo */

#include <iostream>
#include <iomanip>
using namespace std;

struct process
{
	int pno;
	int btime;
	int atime;
  	int wtime;
  	int time_run;
  	int end_time;
};

int main(int argc, char const *argv[])
{
	int n, total_btime=0, quantum = 2;
	cout<<"How many processes: ";
	cin>>n;
	process p[n];
	cout<<"Enter the burst time and arrival time for the processes.\n";
	for (int i = 0; i < n; ++i)
	{	
		cout<<"Process "<<i+1;
		p[i].pno = i+1;
		cout<<"\nBurst time: ";
		cin>>p[i].btime;
		cout<<"Arrival time: ";
		cin>>p[i].atime;
		cout<<"\n";
		total_btime+=p[i].btime;
    	p[i].wtime=0;
   		p[i].time_run = 0;
    	p[i].end_time = 0;
	}

  //sorting the processes in increasing order of arrival time
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(p[i].atime > p[j].atime)
			{	process temp;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
  
	cout<<"\nTime-Unit  Process\n";
	int time = 0;
	while (time < total_btime){
		for (int j = 0; j <= n; ++j)
		{
			if (p[j].atime <= time)
			{ 	if(p[j].btime != 0)
				{	if(p[j].btime >= 2)
					{ 
						cout<<time<<"-"<<time+2<<setw(12)<<p[j].pno<<"\n";
						p[j].btime-=2;
						time+=2;
            			p[j].time_run += 2;
            			if (p[j].btime==0)
              				p[j].end_time = time;
					}
					else if(p[j].btime == 1)
					{
						cout<<time<<"-"<<time+1<<setw(12)<<p[j].pno<<"\n";
						p[j].btime--;
						time+=1;
            			p[j].time_run += 1;
            			if (p[j].btime==0)
              				p[j].end_time = time;
					}
				}
			}
		}		
	}

  int total_wait = 0;
  int total_tat = 0;
  cout<<"\nProcess   Wait-time   Turnaround-time\n";
  for(int k = 0; k<n ; k++)
    { p[k].wtime = p[k].end_time - p[k].time_run;      
      total_wait+= p[k].wtime;
      total_tat+= p[k].end_time;
      cout<<p[k].pno<<setw(14)<<p[k].wtime<<setw(14)<<p[k].end_time<<"\n";
    }

  cout<<"\nAverage wait-time: "<<(float)total_wait/n<<" time units";
  cout<<"\nAverage turnaround-time: "<<(float)total_tat/n<<" time units";

	return 0;
}