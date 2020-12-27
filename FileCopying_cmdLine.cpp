#include <iostream>
#include <sys/stat.h>
#include <cstring>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc < 4)
	{
		cout<<"\nAll command-line arguments not entered!! Try one of the following:";
		cout<<"\nType: ./copy2 -o src.txt dst.txt	-to overwrite the dst.txt file by the src.txt contents"; 
		cout<<"\nType: ./copy2 -a src.txt dst.txt	-to append the dst.txt file by the src.txt contents";
		cout<<"\nType: ./copy2 -u src.txt dst.txt	-to overwrite the dst.txt file by the src.txt contents if src.txt was modified later as compared to the dst.txt";
		return -1;
	}

	struct stat ss;
	struct stat sd;
	char buffer[100];
	FILE *f_source;
	FILE *f_dest;

	f_source = fopen(argv[2], "rb");

	if (strcmp(argv[1],"-o")==0)
	{
		f_dest = fopen(argv[3], "wb");
		while(!feof(f_source)){
			fread(buffer, sizeof(buffer), 1, f_source);
			fwrite(buffer,sizeof(buffer),1,f_dest);
		}
		fclose(f_dest);
		fclose(f_source);
	}

	else if (strcmp(argv[1],"-a")==0){
		f_dest = fopen(argv[3], "a");
		while(!feof(f_source)){
			fread(buffer, sizeof(buffer), 1, f_source);
			fwrite(buffer,sizeof(buffer),1,f_dest);
		}
		fclose(f_dest);
		fclose(f_source);
	}

	else if (strcmp(argv[1],"-u")==0)
	{
		
		if(stat(argv[2],&ss) < 0)
			cout<<"\nError obtaining source file information!!";
		// else if(stat(argv[3],&sd) < 0)
		// 	cout<<"\nError obtaining destination file information!!";
		else{
				time_t time0 = ss.st_mtime;
				time_t time1 = sd.st_mtime;
        // cout<<"\nsource: "<<time0;
        //  cout<<"\ndest: "<<time1;
				if (difftime(sd.st_mtime, ss.st_mtime)<0)
				{	f_dest = fopen(argv[3], "w");
					while(!feof(f_source)){
						fread(buffer, sizeof(buffer), 1, f_source);
						fwrite(buffer,sizeof(buffer),1,f_dest);
					}
					fclose(f_dest);
					fclose(f_source);
				}
				else
					cout<<"\nNo updation required in destination file";
			}
	}
	

	return 0;
}