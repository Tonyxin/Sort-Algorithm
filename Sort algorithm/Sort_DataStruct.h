#ifndef SORT_DATASTRUCT_H
#define SORT_DATASTRUCT_H

#include <math.h>
#include <string.h>

#define MAXINT 10000

enum Status{ Success = 1, Error = 0 };
//enum deplth{ LH = 1, EH = 0, RH = -1 };				//LE��ʾ��������ȱ���������ȶ�2

//����ؼ��ֵ�����
//typedef float KeyType;			//�ؼ���Ϊ������
typedef int KeyType;					//�ؼ���Ϊ����
//typedef char* KeyType;			//�ؼ���Ϊ�ַ�����

//Ԫ�����ͣ���һ���ṹ���ʾ
typedef struct RcdType
{
	KeyType key;			//�ؼ�����
	//��������				//Ԫ�ص�������Ϣ
}RcdType;

//˳���洢
#define MAXSIZE 20				//һ��С˳������󳤶�
typedef struct SqList
{
	RcdType r[MAXSIZE + 1];		//˳���洢�ռ䣬0�ŵ�Ԫ���ջ���Ϊ�ڱ���Ԫ
	int length;								//˳����ռ�ó���
}SqList;

//�������Ķ�������洢
typedef struct BiTNode
{
	RcdType data;					//�ڵ�����
	struct BiTNode *lchild, *rchild;			//��������
}BiTNode, *BiTree;

//��̬����-���������
#define SIZE (100+1)				//��̬���������
typedef struct SLNode     //��̬����Ľڵ�ṹ
{
	RcdType rc;		//��¼��
	int next;			//ָ���ָ����һ����¼�Ĵ洢λ��
	int last;				//ָ���ָ����һ����¼�Ĵ洢λ��
}SLNode;
typedef struct SLinkList	//��̬����Ľṹ
{
	SLNode r[SIZE];		//0�ŵ�ԪΪ��ͷ�ڵ�		
	int length;					//����ĵ�ǰ����
}SLinkList;

//��̬����
typedef struct LinkNode
{
	LinkNode *last;				//ָ����ָ���������һ�ڵ�
	RcdType elem;				//�����򣬴洢�йؼ���
	LinkNode *next;			//ָ����ָ���������һ�ڵ�
}LinkNode, *LinkList;

//�Ѳ���˳���洢��ʾ-------������
typedef SqList HeapType;

//�ȽϺ�������ߴ󣬷���1��һ���󣬷���0���ұߴ󣬷���-1
int Compare(int, int);
int Compare(float, float);
int Compare(char*, char*);

//��������Ĳ����������ɹ�����Success��ʧ�ܷ���Error
Status SearchNode(LinkList L, KeyType key, LinkList &LResult);			//�������в��ҹؼ������ڵĽڵ�
Status InsertNode(LinkList L, KeyType key);			//�������в���ڵ�
Status DeleteNode(LinkList L, KeyType key);			//��������ɾ���ڵ�

#endif