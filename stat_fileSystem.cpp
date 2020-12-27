#include <iostream>
#include <sys/stat.h>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
	struct stat s;

	if (argc < 2)
	{
		cout<<"No file name entered!!";
		return -1;
	}

	for (int i = 1; i < argc; ++i)
	{
		cout<<"\n\nFor file: "<<argv[i];
		if(stat(argv[i],&s) < 0)
			cout<<"\nError obtaining file information!!";
		else{
			cout<<"\nOwner ID: "<<s.st_uid;
			cout<<"\nGroup ID: "<<s.st_gid;
			cout<<"\nFile type: ";
			switch(s.st_mode & S_IFMT){
				case S_IFBLK: cout<<"Block Device";
							  break;
				case S_IFCHR: cout<<"Character Device";
							  break;
				case S_IFDIR: cout<<"Directory";
							  break;
				case S_IFIFO: cout<<"FIFO/Pipe";
							  break;
				case S_IFLNK: cout<<"Symlink";
							  break;
				case S_IFREG: cout<<"Regular File";
							  break;
				case S_IFSOCK: cout<<"Socket";
							   break;
				default: cout<<"File type unknown!!";
						 break;
			}

			cout<<"\nFile Permissions: "<<oct<<(s.st_mode & (S_IRWXG | S_IRWXU | S_IRWXO));
			cout<<"\nFile-last access time: "<<ctime(&(s.st_atime));
			unsigned long long int size = s.st_size;
			cout<<"File Size: "<<size;
			unsigned long long int blk_size = s.st_blksize;
			cout<<"\nFile Size (in blocks): "<<blk_size;
		}
	
	}
	return 0;
}