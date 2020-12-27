//program to find sum of n numbers using thread library

#include <pthread.h>
#include <iostream>
#include <string>
using namespace std;

int sum;
void *funcSum(void *arg);

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	if (argc != 2)
	{
		cerr<<"Error!! Try typing- ./a.exe <positive integer value>";
		return -1;
	}

	if (stoi(argv[1]) < 0)
	{
		cerr<<"Error!!"<<stoi(argv[1])<<" must be a positive integer\n";
		return -1;
	}

	pthread_attr_init(&attr);						//get default thread attributes
	pthread_create(&tid,&attr,funcSum,argv[1]);		//create thread
	pthread_join(tid, NULL);						//wait for thread to complete execution

	cout<<"The sum of all positive natural nos. upto "<<stoi(argv[1])<<" is: "<<sum;

	return 0;
}

void *funcSum(void *arg){
  //int temp = (int)arg;
	int max = stoi((char*)arg);
	sum = 0;

	for (int i = 1; i <= max; i++)
		sum+=i;

	pthread_exit(0);
}