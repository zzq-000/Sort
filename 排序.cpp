	#include<iostream>
#include<stdlib.h> 
#include<time.h>
#include"sort.h"

#define SIZE 20
#define MAX  100
/* TODO (Bill#1#): 归并排序的优化问题仍未解决 */
/* TODO (Bill#2#): 快速排序的第三种HOARE-PARTITION()以及相应的quickSort()方法仍未解决 */

using namespace std;

/*void merge(int A[],int p,int q,int r);//归并排序算法  稳定 
void Merge(int A[],int p,int q);      //归并子函数 
void quickSort(int A[],int m,int n);   //快速排序   不稳定  ==>>分治策略
void quickSort(int A[],int m,int n);   //快速排序   不稳定  ==>>分治策略
int partion1(int A[],int p,int q);  //快速排序子程序1 
int partion2(int A[],int p,int q);  //快速排序子程序2
int partion3(int A[],int p,int q);  //快速排序子程序3     !!!
void insertSort(int A[],int n);       //插入排序    稳定 
void selectSort(int A[],int n);        //选择排序   不稳定 
void bubbleSort(int A[],int n);       //冒泡排序    稳定 
void HEAPSORT(int A[],int n);			//堆排序       不稳定      使以i为根的子树成为最大堆
void heapSort(int A[],int n,int i);    //使数组A中以下标i为根节点的子树成为大顶堆


void conutSort(int A[],int n,int max);   //计数排序    稳定 

void insertSort(int A[],int m,int n);// 优化归并排序时所用到的的子程序，仍待解决 
void swap(int &a,int &b);       //交换数据
int BinarySearch(int A[],int n,int x);   //二分查找递归/非递归 

void randomArray(int A[],int n);   //产生长度为n的随机数组 
int randInt();              //产生随机数 
void printArray(int A[],int n);//打印数组 
*/ 

int main()
{
	
	int n=randInt(SIZE);
	int data[n];
	int x;
	int index;
	cout<<"系统产生的待排序数的个数为："<<n<<endl; 
	randomArray(data,n);
	cout<<"待排序的数组内容为:"<<endl; 
	printArray(data,n);
	
	
	//========================================// 
	//                比较排序 				  // 
	//========================================// 
	//Merge(data,0,n-1);   		//归并排序   空间复杂度O(n),时间复杂度O(nlogn)
	//quickSort(data,0,n-1);      //快速排序   空间复杂度O(1),时间复杂度:最好O(n^2),最差O(n^2),平均O(nlogn)
	//insertSort(data,n);  		//插入排序   空间复杂度O(1),时间复杂度:最好O(n),最差O(n^2),平均O(n^2) 
	//selectSort(data,n);  		//选择排序   空间复杂度O(1),时间复杂度:最好O(n^2),最差O(n^2),平均O(n^2)
	//bubbleSort(data,n);  		//冒泡排序   空间复杂度O(1),时间复杂度:最好O(n),最差O(n^2),平均O(n^2)
	//heapSort(data,n);    		//堆排序   空间复杂度O(1),时间复杂度：最好O(nlogn),最差O(nlogn),平均O(nlogn)  
	
	
	
	
	//========================================// 
	//     		    非比较排序 				  // 
	//========================================//
	conutSort(data,n,MAX);      //计数排序  空间复杂度 O(max+n),时间复杂度O(n+max) 
	cout<<"排序后的数组:"<<endl; 
	printArray(data,n);
	cout<<"请输入要查询的数据:"<<endl;
	cin>>x;
	index=BinarySearch(data,n,x);
	cout<<"待查询的数字在数组中的位置下标为:"<<index<<endl;
}



