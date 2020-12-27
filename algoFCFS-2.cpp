//implementing FCFS algo (including arrival time of processes, not using Gantt chart)

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	int btime[10], n, wtime[10], atime[10];	
	cout<<"How many processes?: ";
	cin>>n;
	cout<<"\nEnter the burst time of each process: \n";
	for(int i = 0; i < n; i++){
		cout<<"Process "<<i+1<<" : ";
		cin>>btime[i];
	}

	cout<<"\nEnter the arrival time of each process: \n";
	for(int i = 0; i < n; i++){
		cout<<"Process "<<i+1<<" : ";
		cin>>atime[i];
	}

	wtime[0] = 0;
	for(int i = 1; i < n; i++){
		int value;
		value = wtime[i-1] + btime[i-1] - (atime[i] - atime[i-1]);
		if (value < 0)
			wtime[i] = 0;
		else
			wtime[i] = value;
	}

	int sum_wait = 0;
	cout<<"\nProcess"<<"  "<<"Wait_Time\n";
	for (int i = 0; i < n; ++i){
		cout<<(i+1)<<setw(12)<<wtime[i]<<"\n";
		sum_wait+= wtime[i]; 
	}

	float avg_wait;
	avg_wait = (float)sum_wait/n;
	cout<<"\nThe average wait time is: "<<avg_wait<<" time units\n";

	return 0;
}