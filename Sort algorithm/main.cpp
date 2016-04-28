#include "SortAlgorithm.h"
#include "iostream"

using namespace std;

int main()
{
	/*
	SLinkList L,L1;
	L.length = 30;
	for (int i = 30; i > 0; i--)
		L.r[31 - i].rc.key = i;
	SInertSort(L);
	for (int i = L.r[0].next; i != 0; i = L.r[i].next)
		cout << L.r[i].rc.key << endl;
	
	SqList L;
	L.length = 20;
	for (int i = 20; i > 0; i--)
		L.r[21 - i].key = i;
	HeapSort(L);
	for (int i = 1; i <= 20; i++)
		cout << L.r[i].key << endl;
	*/
	SLList L;
	L.keynum = 2;
	L.recnum = 9;
	for (int i = 1; i <= L.recnum; i++)
	{
		L.r[i].keys[0] = i;
		L.r[i].keys[1] = L.recnum+1 - i;
	}
	RadixSort(L);
	for (int i = L.r[0].next; i != 0; i = L.r[i].next)
		cout << L.r[i].keys[1] << L.r[i].keys[0] << endl;

	return 0;
}