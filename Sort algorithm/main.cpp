#include "SortAlgorithm.h"
#include "iostream"

using namespace std;

int main()
{
	SLinkList L;
	L.length = 20;
	for (int i = 20; i > 0; i--)
		L.r[21 - i].rc.key = i;
	SInertSort(L);
	for (int i = L.r[0].next; i != 0; i = L.r[i].next)
		cout << L.r[i].rc.key << endl;
	return 0;
}