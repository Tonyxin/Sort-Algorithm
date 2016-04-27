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

