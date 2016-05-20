#ifndef SORT
#define SORT
	#include<utility>
	#include<bits/stdc++.h>
	using namespace std;
	template<class t1, class t2> void insertionSort(t1 a[],t2 n)
	{
		t1 key;
		t2 i,j;
		for(j=1;j<n;j++)
		{
			key=a[j];
			i=j-1;
			while(i>=0&&a[i]>key)
			{
				a[i+1]=a[i];
				i--;
			}
			a[i+1]=key;
		}
	}
	template<class t1, class t2> void selectionSort(t1 a[],t2 n)
	{
		t2 i,j,min;
		t1 temp;
		for(i=0;i<n;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
			{
				if(a[j]<a[min])
				{
					min=j;
				}
			}
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	template <class t1, class t2> void bubbleSort(t1 a[], t2 n)
	{
		t2 i,j;
		t1 temp;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	template<class t1, class t2, class t3> t2 Partition(t1 a[], t2 l, t3 r)
	{
		t1 x=a[l],temp;
		t3 j=l,i;
		for(i=l+1;i<=r;i++)
		{
			if(a[i]<=x)
			{
				j=j+1;
				if(i!=j)
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		temp=a[l];
		a[l]=a[j];
		a[j]=temp;
		return j;
	}
	template<class t1, class t2, class t3> void quickSort(t1 a[],t2 l, t3 r)
	{
		if(l>=r)
			return;
		else
		{
			t2 m=Partition(a,l,r);
			quickSort(a,l,m-1);
			quickSort(a,m+1,r);
		}
	}
	template<class t1, class t2, class t3> pair<t2,t3> Partition3(t1 a[], t2 l, t3 r)
	{
		t1 x=a[l], temp;
		t3 j=l,i,k=l;
		for(i=l+1;i<=r;i++)
		{
			if(a[i]<=x)
			{
				j=j+1;
				if(i!=j)
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		temp=a[l];
		a[l]=a[j];
		a[j]=temp;
		for(i=j;i>=l;i--)
		{
			if(x!=a[i])
				break;
		}
		return (make_pair(i+1,j));
	}
	template<class t1, class t2, class t3> void randomQuickSort(t1 a[],t2 l, t3 r)
	{
		if(l>=r)
			return;
		else
		{
			t1 temp;
			t2 m1;
			t3 m2;
			pair <t2,t3> p;
			t3 x=l+(rand()%(l-r));
			temp=a[l];
			a[l]=a[x];
			a[x]=temp;
			p=Partition3(a,l,r);
			m1=p.first;
			m2=p.second;
			randomQuickSort(a,l,m1-1);
			randomQuickSort(a,m2+1,r);
		}
	}
	template<class t1, class t2, class t3, class t4> void merge(t1 arr[], t2 l, t3 m, t4 r)
	{
    	t4 i, j, k;
    	t4 n1 = m - l + 1;
    	t4 n2 =  r - m;
    	t1 L[n1], R[n2];
    	for (i = 0; i < n1; i++)
        	L[i] = arr[l + i];
    	for (j = 0; j < n2; j++)
        	R[j] = arr[m + 1+ j];
	    i = 0;
	    j = 0; 
    	k = l; 
   	 	while (i < n1 && j < n2)
    	{
        	if (L[i] <= R[j])
        	{
            	arr[k] = L[i];
            	i++;
       	 	}
        	else
        	{
            	arr[k] = R[j];
            	j++;
        	}
        	k++;
    	}
    	while (i < n1)
    	{
        	arr[k] = L[i];
        	i++;
        	k++;
    	}
    	while (j < n2)
    	{
       		arr[k] = R[j];
        	j++;
        	k++;
    	}
	}
	template<class t1, class t2, class t3> void mergeSort(t1 arr[], t2 l, t3 r)
	{
    	if (l < r)
    	{
        	t3 m = l+(r-l)/2;
        	mergeSort(arr, l, m);
        	mergeSort(arr, m+1, r);
        	merge(arr, l, m, r);
    	}
	}
#endif
