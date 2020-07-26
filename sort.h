#include<stdlib.h>
#include<time.h>
#include"method.h"

#define MAX  100

using namespace std;


//========================================// 
//                比较排序 				  // 
//========================================// 

void merge(int A[],int p,int q,int r)  //归并排序的子函数 
{
	int n1=q-p+1,n2=r-q;
	int i=0,j;
	int L[n1];
	int R[n2];
	for(;i<n1;i++)
		L[i]=A[p+i];
	for(i=0;i<n2;i++)
		R[i]=A[q+1+i];
	i=j=0;
	while((i<n1)&&(j<n2))  //优化：在L、R数组末尾加上哨兵项 
	{
		if(L[i]<=R[j])
		{
			A[p++]=L[i];
			i++;
		}
		else
		{
			A[p++]=R[j];
			j++;
		}		
	}
	if(i==n1)
		for(;j<n2;j++)
			A[p++]=R[j];
	else
		for(;i<n1;i++)
			A[p++]=L[i];
}
void Merge(int A[],int p,int q)   //归并排序 
{
	if(p<q){              //正常归并排序 
		int n=(p+q)/2;
		Merge(A,p,n);
		Merge(A,n+1,q);
		merge(A,p,n,q);	
	}


/*	if((q-p+1)>(int)(log((double)(q-p+1))/log((double)2)))   //优化归并排序 
	{
		int n=(p+q)/2;
		Merge(A,p,n);
		Merge(A,n+1,q);
		merge(A,p,n,q);	
	}
	else
	{
		insertSort(A,p,q);
	}
*/ 
}
void insertSort(int A[],int n)    //插入排序 
{
	int temp,j;
	for(int i=1;i<n;i++)
	{
		temp=A[i];
		j=i-1;
		while((j>0)&&(A[j]>temp))
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=temp;
	}
}

/* TODO (Bill#1#): 此为优化归并排序所用到的子程序，即当归
                   并的对象规模满足k<logn 时采用直接插入
                   排序， */
void insertSort(int A[],int m,int n) 
{
	int temp,j;
	for(int i=m+1;i<=n;i++)
	{
		temp=A[i];
		j=i-1;
		while((j>0)&&(A[j]>temp))
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=temp;
	}
}
void selectSort(int A[],int n)    //选择排序 
{
	int min,j;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(A[j]<A[min])
				min=j;
		swap(A[i],A[min]);
	} 
	
}
void bubbleSort(int A[],int n)  //冒泡排序 
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(A[j]>A[j+1])
				swap(A[j],A[j+1]);
		}
	}
}



void heapSort(int A[],int n)			//堆排序       不稳定      使以i为根的子树成为最大堆
{
	maxHeap(A,n);
	int heapsize=n;
	for(int i=n;i>0;i--)
	{
		swap(A[0],A[i-1]);
		heapsize--;
		heap(A,heapsize,0);
	} 
} 
void maxHeap(int A[],int n)    //使数组A成为大顶堆 
{
	int heapsize=n;
	for(int i=(n-1)/2;i>=0;i--)
		heap(A,heapsize,i);
}
void heap(int A[],int heapsize,int i)  //使数组A中以下标i为根节点的子树成为大顶堆
{
	int left=2*i+1;
	int right=2*i+2;
	int max;
	if((left<heapsize)&&(A[left]>A[i]))
		max=left;
	else
		max=i;
	if((right<heapsize)&&(A[right]>A[max]))
		max=right;
	if(max!=i)
	{
		swap(A[max],A[i]);
		heap(A,heapsize,max);	
	}
}
 

void quickSort(int A[],int m,int n)   //快速排序 
{
	if(m<n)
	{
		int t=partion2(A,m,n);
		quickSort(A,m,t-1);
		quickSort(A,t+1,n);
	}
}
int partion1(int A[],int p,int q)     //快速排序子程序1
{
	int i=p-1;
	if(p<q)
	{	
		for(int j=p;j<q;j++)
		{
			if(A[j]<=A[q])
			{
				i++;
				swap(A[i],A[j]);
			}
		}
		swap(A[i+1],A[q]);
	}
	return i+1;
}
int partion2(int A[],int p,int q)  //快速排序子程序2
{
	int key=A[p];
	while(p<q)
	{
		while((p<q)&&(A[q]>=key)) q--;
		A[p]=A[q];
		while((p<q)&&(A[p]<=key)) p++;
		A[q]=A[p];
	}
	A[p]=key; 
	return q;
} 
int partion3(int A[],int p,int q) //快速排序子程序3
{
	int i=p,j=q;
	while(true)
	{
		while(A[i]<=A[p])
			i++;
		while(A[j]>=A[q])
			j--;
		if(i<j)
			swap(A[i],A[j]);
		else return j;	
	} 
} 



//========================================// 
//     		    非比较排序 				  // 
//========================================// 

void conutSort(int A[],int n,int max);   //计数排序    稳定 













int randInt(int n)
{
	srand((unsigned)time(NULL));
	return (rand()%n+1);
}
void randomArray(int A[],int n)
{
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++)		
		A[i]=rand()%MAX+1; 		
}
 

 
int BinarySearch(int A[],int n,int x)  //二分查找 
{
	int left=0,right=n-1;         //迭代 非递归 
	int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(A[mid]==x)
			return mid;
		else if(A[mid]<x)
			left=mid+1;
		else
			right=mid-1;		
	}
	return -1;
} 

void swap(int &a,int &b)          //交换数据 
{
	int temp=a;
	a=b;
	b=temp;
}

void printArray(int A[],int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<endl; 
} 
