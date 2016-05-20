#include "sort.h"
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
int main()
{
	srand ( time(0) );
	int n,i;
	ifstream fin;
	ofstream fout;
	fin.open("C:\\Users\\Abhishek\\Desktop\\raw_data.txt");
	fout.open("C:\\Users\\Abhishek\\Desktop\\sorted_data.txt");
	//freopen("C:\\Users\\Abhishek\\Desktop\\input02.txt","r",stdin);
	//freopen("C:\\Users\\Abhishek\\Desktop\\output02.txt","w",stdout);
	fin>>n;
	long long int a[n],b[n];
	for(i=0;i<n;i++)
		fin>>a[i];
	for(i=0;i<n;i++)
		b[i]=a[i];
	cout<<"Executing Insertion Sort...\n";
	clock_t tStart1 = clock();
	insertionSort(b,n);
	double time1=(double)(clock() - tStart1)/CLOCKS_PER_SEC;
	for(i=0;i<n;i++)
		b[i]=a[i];
	cout<<"Executing Selection Sort...\n";
	clock_t tStart2 = clock();
	selectionSort(b,n);
	double time2=(double)(clock() - tStart2)/CLOCKS_PER_SEC;
	for(i=0;i<n;i++)
		b[i]=a[i];
	cout<<"Executing Bubble Sort Sort...\n";
	clock_t tStart3 = clock();
	bubbleSort(b,n);
	double time3=(double)(clock() - tStart3)/CLOCKS_PER_SEC;
	for(i=0;i<n;i++)
		b[i]=a[i];
	cout<<"Executing Quick Sort Sort...\n";
	clock_t tStart4 = clock();
	quickSort(b,0,n-1);
	double time4=(double)(clock() - tStart4)/CLOCKS_PER_SEC;
	for(i=0;i<n;i++)
		b[i]=a[i];
	cout<<"Executing 3 partiton Randomized Quick Sort Sort...\n";
	clock_t tStart5 = clock();
	randomQuickSort(b,0,n-1);
	double time5=(double)(clock() - tStart5)/CLOCKS_PER_SEC;
	for(i=0;i<n;i++)
		b[i]=a[i];
	cout<<"Executing Merge Sort Sort...\n";
	clock_t tStart6 = clock();
	mergeSort(b,0,n-1);
	double time6=(double)(clock() - tStart6)/CLOCKS_PER_SEC;
	cout<<"\nExecution time-\n";
	printf("Insertion Sort: %.6fs\n", time1);
	printf("Selection Sort: %.6fs\n", time2);
	printf("Bubble Sort: %.6fs\n", time3);
	printf("Quick Sort: %.6fs\n", time4);
	printf("3 partition Randomized Quick Sort: %.6fs\n", time5);
	printf("Merge Sort: %.6fs\n", time6);
	double k[6]={time1,time2,time3,time4,time5,time6};
	int min=0;
	for(i=1;i<6;i++)
	{
		if(k[i]<k[min])
		{
			min=i;
		}
	}
	cout<<"\nMinimum time: "<<k[min]<<endl;
	if(k[min]==time1)
	{
		cout<<"Sorting algorithm to use: Insertion Sort"<<endl;	
		cout<<"Data sorted using Insertion Sort"<<endl;
	}
	else if(k[min]==time2)
	{
		cout<<"Sorting algorithm to use: Selection Sort"<<endl;
		cout<<"Data sorted using Selection Sort"<<endl;
	}	
	else if(k[min]==time3)
	{
		cout<<"Sorting algorithm to use: Bubble Sort"<<endl;
		cout<<"Data sorted using Bubble Sort"<<endl;
	}
	else if(k[min]==time4)
	{
		cout<<"Sorting algorithm to use: Quick Sort"<<endl;
		cout<<"Data sorted using Quick Sort"<<endl;
	}
	else if(k[min]==time5)
	{
		cout<<"Sorting algorithm to use: 3 partition Randomized Quick Sort"<<endl;
		cout<<"Data sorted using 3 partition Randomized Quick Sort Sort"<<endl;
	}
	else
	{
		cout<<"Sorting algorithm to use: Merge Sort"<<endl;
		cout<<"Data sorted using Merge Sort"<<endl;
	}
	fout<<n<<endl;
	for(i=0;i<n;i++)
		fout<<b[i]<<endl;

}
