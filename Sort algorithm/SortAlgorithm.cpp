#include "SortAlgorithm.h"

//--------------------------------------ֱ�Ӳ�������--------------------------------------
void InsertSort(SqList &L)
{
	/*��L���в�����������󣬹ؼ��ְ���С��������
	*/
	for (int i = 2; i <= L.length; i++)
	{
		if (Compare(L.r[i].key, L.r[i - 1].key) < 0)		//Ҫ��������ݱ����źõ�����С�����в������
		{
			L.r[0] = L.r[i];			//��Ҫ����ĵ�Ԫ���Ƹ��ڱ�
			L.r[i] = L.r[i - 1];		//����Ҫ����ؼ��ִ�ĵ�Ԫ����
			int j;
			for (j = i - 2; j>0; j--)
			{
				if (Compare(L.r[j].key, L.r[0].key) > 0)			
					L.r[j + 1] = L.r[j];		//�����бȹؼ��ִ�ĵ�Ԫ����ƶ�
				else 
					break;
			}
			L.r[j + 1] = L.r[0];				//����Ӧ�ò����λ��
		}//if
	}//for
}

//--------------------------------------�۰��������--------------------------------------
void BInsertSort(SqList &L)
{
	/*��ΪҪ����ĵ�Ԫ֮ǰ�����������У���˲����۰��������������С��������
	**�����ֱ�Ӳ��������۰��������ֻ�Ǽ����˱ȽϵĴ����������ƶ��Ĵ���û�б仯
	*/
	for (int i = 2; i <= L.length; i++)
	{
		if (Compare(L.r[i].key, L.r[i - 1].key) < 0)		//Ҫ��������ݱ����źõ�����С�����в������
		{
			L.r[0] = L.r[i];		//��Ҫ����ĵ�Ԫ���Ƹ��ڱ���Ԫ
			int low = 1;
			int high = i - 1;
			while (low <= high)				//�����۰���ң��������λ����high֮��
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
			for (int j = i - 1; j > high; j--)			//��Ҫ�����λ���Ժ�ĵ�Ԫ���Ų
				L.r[j + 1] = L.r[j];
			L.r[high + 1] = L.r[0];
		}//if
	}//for
}

//---------------------------------------���������----------------------------------------
void SInertSort(SLinkList &L)
{
	/*ֻ����ָ��ָ��ȥ���˽ڵ��ƶ���ʱ��
	*������ʱֻ��˳����ң���Ҫʵ���������۰���ң���Ҫ�����н�������
	*/
	L.r[0].rc.key = MAXINT;		//��ʼ����0�ŵ�Ԫ��¼��Ϊ�����			
	L.r[0].next = 1;					//0�ŵ�Ԫָ��1�ŵ�Ԫ��1�ŵ�Ԫָ��0�ŵ�Ԫ���γ�˫��ѭ������
	L.r[0].last = 1;
	L.r[1].next = 0;
	L.r[1].last = 0;
	for (int i = 2; i <= L.length; i++)
	{
		int j;
		for (j = L.r[0].next; j != 0; j = L.r[j].next)
		{
			if (Compare(L.r[i].rc.key, L.r[j].rc.key) < 0)	//��i����Ĺؼ���С��ǰ��Ľڵ�
			{
				L.r[L.r[j].last].next = i;		//�����ڵ�ָ��
				L.r[i].last = L.r[j].last;
				L.r[i].next = j;
				L.r[j].last = i;
				break;
			}
		}
		if (j == 0)			//��i���ڵ㲻С��ǰ��Ľڵ�
		{
			L.r[L.r[0].last].next = i;	 //�����ڵ�ָ��
			L.r[i].last = L.r[0].last;
			L.r[i].next = 0;
			L.r[0].last = i;
		}//if
	}//for
}

//----------------------------------------ð������-----------------------------------------
void BubbleSort(SqList &L)
{
	/*�ܵ�ʱ�临�Ӷ���O(n^2)
	*/
	for (int i = 1; i < L.length; i++)				//Ҫ���У�L.length-1����ð��
	{
		for (int j = 1; j <= L.length - i; j++)	//��L.length - i���Ժ�������Ѿ��ȽϹ���  ����Ҫ�ٱȽ�
		{
			if (Compare(L.r[j].key, L.r[j + 1].key)>0)
			{
				RcdType tmp = L.r[j];				//����������Ų
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = tmp;
			}//if
		}//for
	}//for
}

//----------------------------------------��������------------------------------------------
void QuickSort(SqList &L, int head, int tail)
{
	/*����˼�룺ͨ��һ�����򽫴��ż�¼�ָ�ɶ������������֣�����һ���ּ�¼�Ĺؼ��־���
	**                ��һ���ּ�¼�Ĺؼ���С����ɷֱ�������ּ�¼���������Դﵽ������������
	**L��Ҫ������������У�	head~tail���ֳ�L����Ҫ����������ݶ�
	*/
	int i = head;			//i��j�ֱ�Ϊͷβָ��
	int j = tail;
	RcdType bound = L.r[head];		//ѡȡ�������еĵ�һ���ڵ���Ϊ�ֽ�
	while (i < j)			//��ͷָ����βָ��ָ��ͬһλ��ʱ��һ�����н���
	{
		while ((i<j) && (Compare(L.r[j].key, bound.key) > 0))
			j--;
		if (i < j)				//�����ڷֽ�Ľڵ��ᵽǰ�벿��
		{
			L.r[i] = L.r[j];
			i++;
		}
		while ((i < j) && (Compare(L.r[i].key, bound.key) < 0))
			i++;
		if (i < j)				//��С�ڷֽ�Ľڵ��õ�����
		{
			L.r[j] = L.r[i];
			j--;
		}	
	}//while
	L.r[i] = bound;		//i���ź����к󣬱߽�ڵ�Ӧ�ڵ�λ��
	if (abs(head - i)>1)		//���ʣ�µ����������еĽڵ������ڵ���2����Ҫ�������ڵ���е���
		QuickSort(L, head, i - 1);
	if (abs(tail - i)>1)
		QuickSort(L, i + 1, tail);
}

//------------------------------------------������------------------------------------------
void HeapSort(HeapType &H)
{
	/*�ѵĶ��壺n���ؼ�Ԫ�ص�����{k1,k2,...,kn}�����ҽ���k[i]<=k[2i]&&k[i]<=k[2i+1]
	* ����������������֣�
	*		1����һ���������н�һ���ѣ�
	*		2������Ѷ�Ԫ�غ󣬽�ʣ��Ԫ�ص���Ϊһ����
	* ʹ�÷�Χ�������ڼ�¼�϶�����
	*�ų������д�С��������
	*/		
	for (int i = H.length / 2; i > 0; i--)			//��ʼ���ѹ��̣�����Ϊ�󶥶�
		HeapAdjust(H, i, H.length);
	for (int i = H.length; i > 1; i--)
	{
		RcdType tmp = H.r[1];
		H.r[1] = H.r[i];
		H.r[i] = tmp;
		HeapAdjust(H, 1, i-1);
	}
}
void HeapAdjust(HeapType &H, int s, int m)			//�����ѳ�Ϊ�󶥶�
{
	/*H.r[s...m]�У�ֻ��H.r[s]�����϶�����H.r[s+1,...,m]�����϶�����
	*/
	if (2 * s <= m)
	{
		//�Ѷ��Ľڵ�ؼ���С���亢�ӵĹؼ��֣����Ѷ����µ���
		if ((Compare(H.r[s].key, H.r[2 * s].key) < 0) || ((2 * s + 1 <= m) && (Compare(H.r[s].key, H.r[2 * s + 1].key) < 0)))		
		{
			//����ýڵ�����Һ��ӣ������Һ����йؼ��ֽϴ�Ľڵ㽻��
			if (2 * s + 1 <= m)
			{
				if (Compare(H.r[2 * s].key, H.r[2 * s + 1].key) > 0)
				{
					RcdType tmp = H.r[2 * s];
					H.r[2 * s] = H.r[s];
					H.r[s] = tmp;
					HeapAdjust(H, 2 * s, m);			//�ݹ����µ���
				}
				else
				{
					RcdType tmp = H.r[2 * s + 1];
					H.r[2 * s + 1] = H.r[s];
					H.r[s] = tmp;
					HeapAdjust(H, 2 * s + 1, m);		//�ݹ����µ���
				}//else
			}
			//���û���Һ��ӣ�ֱ�������ӽ���
			else
			{
				RcdType tmp = H.r[2 * s];
				H.r[2 * s] = H.r[s];
				H.r[s] = tmp;
				HeapAdjust(H, 2 * s, m);			//�ݹ����µ���
			}
		}//if
	}//if
}

//-------------------------------------��ʽ�������򷽷�-------------------------------------
void RadixSort(SLList &L)				//��������
{
	/*L���þ�̬�����ʾ��˳���L��ÿ���ڵ㺬�ж���ؼ���
	* ͨ����εķ������ռ���ʹ��L��Ϊ�ؼ��ִ�С�������е������
	* ע�⣺����ֻ�Ƕ�ָ������˵�������û�жԽڵ��λ�ý��е�����ֻ�ܽ���˳�����
	*/
	Arrtype f, e;		//�ؼ��ֻ�����ָ������[0~RADIX-1]
	//��ʼ��̬ѭ�������ָ��ָ��
	for (int i = 0; i < L.recnum; i++)
		L.r[i].next = i + 1;
	L.r[L.recnum].next = 0;
	for (int i = 0; i < L.keynum; i++)
	{
		Distribute(L, f, e, i);
		Collect(L, f, e, i);
	}
}
void Distribute(SLList &L, Arrtype f, Arrtype e, int keyIndex)		//һ�˷���
{
	/*�������ܣ�������L�еĸ����ڵ㣬���չؼ���[keyIndex]����һ�˷���
	*/
	for (int i = 0; i < RADIX; i++)		//���������ʼ������ָ���һ���ڵ�
	{
		e[i] = 0;		f[i] = 0;
	}
	SLList Ltmp = L;
	for (int i = Ltmp.r[0].next; i != 0; i = Ltmp.r[i].next)		//�������ϸ����ڵ���ݹؼ��ֽ��з���
	{
		int key_tmp = Ltmp.r[i].keys[keyIndex];		//�ؼ���
		if (!f[key_tmp])				//�û����ϻ�û�нڵ�
		{
			f[key_tmp] = i;
			e[key_tmp] = i;
		}
		else                              //�û��������нڵ�
		{
			L.r[e[key_tmp]].next = i;
			e[key_tmp] = i;
		}//else
	}//for
}
void Collect(SLList &L, Arrtype f, Arrtype e, int keyIndex)				//һ���ռ�
{
	/*�������ܣ���f��eָ�Ľڵ����һ���ռ����õ���L�ǰ��ؼ���[keyIndex]�����������������
	*/
	int link = 0;			//���ڷ�0�ֱ�֮���������
	for (int i = 0; i < RADIX; i++)
	{
		if (f[i])
		{
			L.r[link].next = f[i];			//��һ����0�ӱ�����ڵ㣬��������ֱ�ĵ�һ���ڵ�
			link = e[i];						//��������ӱ�����һ���ڵ��
			L.r[e[i]].next = 0;			//Ϊ���γɱպϵ�����ṹ�����������һ���ڵ㻹Ҫ����0�ŵ�Ԫ
		}//if
	}//for
}