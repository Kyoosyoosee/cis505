#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int arr[]){
	int n = sizeof(arr)/sizeof(int);
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

int* merge(int a[], int b[]){
	int sizeA = sizeof(a)/sizeof(int);
	int sizeB = sizeof(b)/sizeof(int);
	int sizeR = sizeA + sizeB;
	int res[sizeR];
	int i = 0;
	int j = 0;
	int curr = 0;

	while(i < sizeA || j < sizeB){
		if(a[i] < b[j] && i < sizeA){
			res[curr] = a[i];
			i++;
		}
		else if(a[i] >= b[j] && j < sizeB){
			res[curr] = b[j];
			j++;
		}
		curr++;
	}
	return res;
}

int main(int argc, char *argv[])
{
	int nflag = 0;
	int tflag = 0;
	int nvalue = 4;
	int opts;
	vector <string> filenames;

	if(argc < 2){
		fprintf(stderr, "Shangcheng Jiang (scjiang)\n");
		return 1;
	}

	//process program options
	while((opts = getopt(argc, argv, "tn:")) != -1){
		switch(opts){
		case 't':
			tflag = 1;
			break;
		case 'n':
			nflag = 1;
			nvalue = atoi(optarg);
			if(nvalue < 0){
				fprintf(stderr, "Option -n requires a positive integer as its argument.\n");
				return 1;
			}
			break;
		case '?':
			if(optopt == 'n'){
				fprintf(stderr, "Option -n requires a positive integer as its argument.\n");
			}
			else{
				fprintf(stderr, "Invalid flag\n");
			}
			return 1;
		default:
			break;
		}
	}
	//stores filenames needed to be processed
	for(int i = optind; i < argc; i++){
		filenames.push_back(argv[i]);
	}

	for(int i = 0; i < filenames.size(); i++){
		string filename = filenames[i];

	}

	return 0;

}
