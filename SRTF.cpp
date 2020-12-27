//SHEFALIKA GHOSH
//19544
/*Implementing shortest remaining time first scheduling algorithm*/

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
	int n, total_btime=0;
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

	cout<<"\nGantt Chart representation of SRTF scheduling:\n";
	cout<<"Time  "<<" 	"<<"Process\n";
	process smallest;
	for(int time = 0; time < total_btime; time++)
	{	 
		for (int i = 0; i < n; ++i)
		{
			if(p[i].atime <= time and p[i].btime != 0)
				{smallest=p[i];
				 break;}
		}
		for (int i = 0; i < n; ++i)
        {	
			if(p[i].atime <= time and p[i].btime != 0 and p[i].btime < smallest.btime)
				smallest = p[i];
		}

		cout<<time<<"-"<<time+1<<" 		"<<smallest.pno<<"\n";
    	for (int i = 0; i < n; ++i)
		{
			if (smallest.pno == p[i].pno)
				{	p[i].btime-- ;
          			++p[i].time_run ;
				  	if(p[i].btime == 0)
					  p[i].end_time = time+1;
        		}
	  	}

  	}

  
  	int total_wait = 0;
  	int total_tat = 0;
  	cout<<"\n\nProcess   Wait-time   Turnaround-time\n";
  	for(int k = 0; k<n ; k++)
    { p[k].wtime = p[k].end_time - p[k].atime - p[k].time_run;    
      total_wait+= p[k].wtime;      
      total_tat+= p[k].end_time - p[k].atime;		
      cout<<p[k].pno<<setw(14)<<p[k].wtime<<setw(14)<<p[k].end_time - p[k].atime<<"\n";
    }

  	cout<<"\nAverage wait-time: "<<(float)total_wait/n<<" time units";
  	cout<<"\nAverage turnaround-time: "<<(float)total_tat/n<<" time units";

	return 0;
		
}