#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}

int main()
{
      int m = 7919, n = 100; // 7919 is prime
	int j = 0, max_load_factor = m/2, step = n;

	float l[max_load_factor/step], q[max_load_factor/step], d[max_load_factor/step];
	Hashtable H(m);
	
	while(n <= max_load_factor){
		srand(time(0));

		for (int i = 0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		l[j] = H.probeRate();
		H.clear();
		
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		q[j] = H.probeRate();
		H.clear();
		
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1);
		}
		d[j] = H.probeRate();
		H.clear();
		
		n +=step;
		j++;
	}
	cout<<"  l \t  q \t  d"<<endl;

	for (int i = 0; i < max_load_factor/step; ++i)
	{
		cout<<l[i]<<"\t"<<q[i]<<"\t"<<d[i]<<endl;
	}

}

/*int main(int argc, char *argv[]) {
	int n, m;
	srand(time(0));

	if (argc == 1) {
		cout << "Running your test code..." << endl;
		 

		return 0;
	}
	
	if (argc != 4) {
		usage(argv);
	}
	n = atoi(argv[2]);
	m = atoi(argv[3]);
	Hashtable H(m);
	
	switch(argv[1][0]) {
	case 'l':
		for (int i=0; i<n; ++i) {
			H.linsert(rand() / 10000000);
		}
		    H.print();
		cout << "Linear: ";  
		H.printStats();
		break;
	case 'q':
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() / 10000000);
		}
		    H.print();
		cout << "Quadratic: ";
		H.printStats();
		break;
	case 'd':
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() / 10000000);
		}
		    H.print();
		cout << "Double Hashing: "; 
		H.printStats();
		break;
	default:
		usage(argv);
	}
}*/

