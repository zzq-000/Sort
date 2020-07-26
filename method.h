
//========================================// 
//                比较排序 				  // 
//========================================// 

void merge(int A[],int p,int q,int r);//归并排序算法  稳定 ==>>分治策略                                           比 
void Merge(int A[],int p,int q);      //归并子函数 
void insertSort(int A[],int m,int n);// 优化归并排序时所用到的的子程序，仍待解决 (k<logn时，采用插入排序） 
void insertSort(int A[],int n);       //插入排序    稳定                                                          
void selectSort(int A[],int n);        //选择排序   不稳定                                                        较 
void bubbleSort(int A[],int n);       //冒泡排序    稳定 
void quickSort(int A[],int m,int n);   //快速排序   不稳定  ==>>分治策略
int partion1(int A[],int p,int q);  //快速排序子程序1 															 
int partion2(int A[],int p,int q);  //快速排序子程序2															  排 
int partion3(int A[],int p,int q);  //快速排序子程序3
void heapSort(int A[],int n);			//堆排序       不稳定      使以i为根的子树成为最大堆      
void maxHeap(int A[],int n);   //使数组A成为大顶堆 
void heap(int A[],int n,int i);    //使数组A中以下标i为根节点的子树成为大顶堆 									  序 
/* 堆排序 =>>优先级队列 
*堆排序和优先级队列在算法层面并没有什么区别 
*堆排序是一种排序算法==>>算法 
*优先级队列是一种数据结构，可以用来存储数据，实现数据的增删查改，实时维护==>>数据结构 
*/



//========================================// 
//     		    非比较排序 				  // 
//========================================//
void conutSort(int A[],int n,int max)   //计数排序    稳定 
{
	int i=0;
	int C[max+1]={0}; 
	int B[n]={0};
	for(;i<n;i++)
		C[A[i]]++;
	for(i=1;i<max+1;i++)
		C[i]=C[i]+C[i-1];
	for(i=n-1;i>=0;i--)
	{
		B[C[A[i]]-1]=A[i];
		C[A[i]]--;
	}
	for(int i=0;i<n;i++)
		A[i]=B[i];
}
 




void swap(int &a,int &b);       //交换数据
int BinarySearch(int A[],int n,int x);   //二分查找递归/非递归  
void randomArray(int A[],int n);//产生随机数组 
int randInt();                  //产生随机数 
void printArray(int A[],int n);//打印数组 
