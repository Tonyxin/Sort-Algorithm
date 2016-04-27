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