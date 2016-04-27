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
	*/
	SqList L;
	L.length = 20;
	for (int i = 20; i > 0; i--)
		L.r[21 - i].key = i;
	QuickSort(L,1,20);
	for (int i = 1; i <= 20; i++)
		cout << L.r[i].key << endl;
	return 0;
}