#include "SortAlgorithm.h"

//--------------------------------------直接插入排序--------------------------------------
void InsertSort(SqList &L)
{
	/*对L进行插入排序，排序后，关键字按从小到大排列
	*/
	for (int i = 2; i <= L.length; i++)
	{
		if (Compare(L.r[i].key, L.r[i - 1].key) < 0)		//要插入的数据比已排好的数据小，进行插入操作
		{
			L.r[0] = L.r[i];			//将要插入的单元复制给哨兵
			L.r[i] = L.r[i - 1];		//将比要插入关键字大的单元后移
			int j;
			for (j = i - 2; j>0; j--)
			{
				if (Compare(L.r[j].key, L.r[0].key) > 0)			
					L.r[j + 1] = L.r[j];		//将所有比关键字大的单元向后移动
				else 
					break;
			}
			L.r[j + 1] = L.r[0];				//插入应该插入的位置
		}//if
	}//for
}

//--------------------------------------折半插入排序--------------------------------------
void BInsertSort(SqList &L)
{
	/*因为要插入的单元之前都是有序序列，因此采用折半插入排序，排序后从小到大排列
	**相比于直接插入排序，折半插入排序只是减少了比较的次数，但是移动的次数没有变化
	*/
	for (int i = 2; i <= L.length; i++)
	{
		if (Compare(L.r[i].key, L.r[i - 1].key) < 0)		//要插入的数据比已排好的数据小，进行插入操作
		{
			L.r[0] = L.r[i];		//将要插入的单元复制给哨兵单元
			int low = 1;
			int high = i - 1;
			while (low <= high)				//进行折半查找，最后插入的位置在high之后
			{
				int mid = (low + high) / 2;
				int tmp = Compare(L.r[mid].key, L.r[0].key);
				if (tmp == 0)
					break;
				else if (tmp > 0)
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (int j = i - 1; j > high; j--)			//将要插入的位置以后的单元向后挪
				L.r[j + 1] = L.r[j];
			L.r[high + 1] = L.r[0];
		}//if
	}//for
}

//---------------------------------------表插入排序----------------------------------------
void SInertSort(SLinkList &L)
{
	/*只调整指针指向，去掉了节点移动的时间
	*但查找时只能顺序查找，想要实现有序表的折半查找，还要对序列进行重排
	*/
	L.r[0].rc.key = MAXINT;		//初始化，0号单元记录项为无穷大			
	L.r[0].next = 1;					//0号单元指向1号单元，1号单元指向0号单元，形成双向循环链表
	L.r[0].last = 1;
	L.r[1].next = 0;
	L.r[1].last = 0;
	for (int i = 2; i <= L.length; i++)
	{
		int j;
		for (j = L.r[0].next; j != 0; j = L.r[j].next)
		{
			if (Compare(L.r[i].rc.key, L.r[j].rc.key) < 0)	//第i个点的关键字小于前面的节点
			{
				L.r[L.r[j].last].next = i;		//调整节点指针
				L.r[i].last = L.r[j].last;
				L.r[i].next = j;
				L.r[j].last = i;
				break;
			}
		}
		if (j == 0)			//第i个节点不小于前面的节点
		{
			L.r[L.r[0].last].next = i;	 //调整节点指针
			L.r[i].last = L.r[0].last;
			L.r[i].next = 0;
			L.r[0].last = i;
		}//if
	}//for
}

//----------------------------------------冒泡排序-----------------------------------------
void BubbleSort(SqList &L)
{
	/*总的时间复杂度是O(n^2)
	*/
	for (int i = 1; i < L.length; i++)				//要进行（L.length-1）轮冒泡
	{
		for (int j = 1; j <= L.length - i; j++)	//（L.length - i）以后的数据已经比较过了  不需要再比较
		{
			if (Compare(L.r[j].key, L.r[j + 1].key)>0)
			{
				RcdType tmp = L.r[j];				//将大的数向后挪
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = tmp;
			}//if
		}//for
	}//for
}

//----------------------------------------快速排序------------------------------------------
void QuickSort(SqList &L, int head, int tail)
{
	/*基本思想：通过一趟排序将待排记录分割成独立的两个部分，其中一部分记录的关键字均比
	**                另一部分记录的关键字小，则可分别对两部分记录继续排序，以达到整个序列有序
	**L：要进行排序的序列；	head~tail划分出L中需要被排序的数据段
	*/
	int i = head;			//i与j分别为头尾指针
	int j = tail;
	RcdType bound = L.r[head];		//选取被排序列的第一个节点作为分界
	while (i < j)			//当头指针与尾指针指向同一位置时，一次排列结束
	{
		while ((i<j) && (Compare(L.r[j].key, bound.key) > 0))
			j--;
		if (i < j)				//将大于分界的节点提到前半部分
		{
			L.r[i] = L.r[j];
			i++;
		}
		while ((i < j) && (Compare(L.r[i].key, bound.key) < 0))
			i++;
		if (i < j)				//将小于分界的节点拿到后面
		{
			L.r[j] = L.r[i];
			j--;
		}	
	}//while
	L.r[i] = bound;		//i是排好序列后，边界节点应在的位置
	if (abs(head - i)>1)		//如果剩下的两个序列中的节点数大于等于2，还要对两个节点进行迭代
		QuickSort(L, head, i - 1);
	if (abs(tail - i)>1)
		QuickSort(L, i + 1, tail);
}

//------------------------------------------堆排序------------------------------------------
void HeapSort(HeapType &H)
{
	/*堆的定义：n个关键元素的序列{k1,k2,...,kn}，当且仅当k[i]<=k[2i]&&k[i]<=k[2i+1]
	* 堆排序包含两个部分：
	*		1、由一个无需序列建一个堆；
	*		2、输出堆顶元素后，将剩余元素调整为一个堆
	* 使用范围：适用于记录较多的情况
	*排出的序列从小到大排列
	*/		
	for (int i = H.length / 2; i > 0; i--)			//初始建堆过程，调整为大顶堆
		HeapAdjust(H, i, H.length);
	for (int i = H.length; i > 1; i--)
	{
		RcdType tmp = H.r[1];
		H.r[1] = H.r[i];
		H.r[i] = tmp;
		HeapAdjust(H, 1, i-1);
	}
}
void HeapAdjust(HeapType &H, int s, int m)			//调整堆称为大顶堆
{
	/*H.r[s...m]中，只有H.r[s]不符合堆排序，H.r[s+1,...,m]均符合堆排序
	*/
	if (2 * s <= m)
	{
		//堆顶的节点关键字小于其孩子的关键字，将堆顶向下调整
		if ((Compare(H.r[s].key, H.r[2 * s].key) < 0) || ((2 * s + 1 <= m) && (Compare(H.r[s].key, H.r[2 * s + 1].key) < 0)))		
		{
			//如果该节点存在右孩子，与左右孩子中关键字较大的节点交换
			if (2 * s + 1 <= m)
			{
				if (Compare(H.r[2 * s].key, H.r[2 * s + 1].key) > 0)
				{
					RcdType tmp = H.r[2 * s];
					H.r[2 * s] = H.r[s];
					H.r[s] = tmp;
					HeapAdjust(H, 2 * s, m);			//递归向下调整
				}
				else
				{
					RcdType tmp = H.r[2 * s + 1];
					H.r[2 * s + 1] = H.r[s];
					H.r[s] = tmp;
					HeapAdjust(H, 2 * s + 1, m);		//递归向下调整
				}//else
			}
			//如果没有右孩子，直接与左孩子交换
			else
			{
				RcdType tmp = H.r[2 * s];
				H.r[2 * s] = H.r[s];
				H.r[s] = tmp;
				HeapAdjust(H, 2 * s, m);			//递归向下调整
			}
		}//if
	}//if
}

//-------------------------------------链式基数排序方法-------------------------------------
void RadixSort(SLList &L)				//基数排序
{
	/*L是用静态链表表示的顺序表，L中每个节点含有多个关键字
	* 通过多次的分类与收集，使得L称为关键字从小到大排列的有序表
	* 注意：这里只是对指针进行了调整，并没有对节点的位置进行调整，只能进行顺序查找
	*/
	Arrtype f, e;		//关键字基数的指针数组[0~RADIX-1]
	//初始静态循环链表的指针指向
	for (int i = 0; i < L.recnum; i++)
		L.r[i].next = i + 1;
	L.r[L.recnum].next = 0;
	for (int i = 0; i < L.keynum; i++)
	{
		Distribute(L, f, e, i);
		Collect(L, f, e, i);
	}
}
void Distribute(SLList &L, Arrtype f, Arrtype e, int keyIndex)		//一趟分配
{
	/*函数功能：对链表L中的各个节点，按照关键字[keyIndex]进行一趟分类
	*/
	for (int i = 0; i < RADIX; i++)		//基数数组初始化，均指向第一个节点
	{
		e[i] = 0;		f[i] = 0;
	}
	SLList Ltmp = L;
	for (int i = Ltmp.r[0].next; i != 0; i = Ltmp.r[i].next)		//将链表上各个节点根据关键字进行分配
	{
		int key_tmp = Ltmp.r[i].keys[keyIndex];		//关键字
		if (!f[key_tmp])				//该基数上还没有节点
		{
			f[key_tmp] = i;
			e[key_tmp] = i;
		}
		else                              //该基数上已有节点
		{
			L.r[e[key_tmp]].next = i;
			e[key_tmp] = i;
		}//else
	}//for
}
void Collect(SLList &L, Arrtype f, Arrtype e, int keyIndex)				//一趟收集
{
	/*函数功能：对f、e指的节点完成一趟收集，得到的L是按关键字[keyIndex]进行排序的有序序列
	*/
	int link = 0;			//用于非0字表之间进行连接
	for (int i = 0; i < RADIX; i++)
	{
		if (f[i])
		{
			L.r[link].next = f[i];			//上一个非0子表的最后节点，连上这个字表的第一个节点
			link = e[i];						//保存这个子表的最后一个节点号
			L.r[e[i]].next = 0;			//为了形成闭合的链表结构，整个表最后一个节点还要连回0号单元
		}//if
	}//for
}