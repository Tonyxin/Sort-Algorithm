#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include "Sort_DataStruct.h"

//ֱ�Ӳ�������
void InsertSort(SqList &L);

//�۰��������
void BInsertSort(SqList &L);

//���������
void SInertSort(SLinkList &L);

//ð������
void BubbleSort(SqList &L);

//��������
void QuickSort(SqList &L, int head, int tail);

//������
void HeapSort(HeapType &H);			
void HeapAdjust(HeapType &H, int s, int m);			//������

//��ʽ��������
void RadixSort(SLList &L);				//��������
void Distribute(SLList &L, Arrtype f, Arrtype e, int keyIndex);	//һ�˷���
void Collect(SLList &L, Arrtype f, Arrtype e, int keyIndex);		//һ���ռ�

#endif


