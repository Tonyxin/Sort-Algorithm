#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include "Sort_DataStruct.h"

//直接插入排序
void InsertSort(SqList &L);

//折半插入排序
void BInsertSort(SqList &L);

//表插入排序
void SInertSort(SLinkList &L);

//冒泡排序
void BubbleSort(SqList &L);

//快速排序
void QuickSort(SqList &L, int head, int tail);

//堆排序
void HeapSort(HeapType &H);			
void HeapAdjust(HeapType &H, int s, int m);			//调整堆

#endif


