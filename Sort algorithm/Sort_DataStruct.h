#ifndef SORT_DATASTRUCT_H
#define SORT_DATASTRUCT_H

#include <math.h>
#include <string.h>

#define MAXINT 10000

enum Status{ Success = 1, Error = 0 };
//enum deplth{ LH = 1, EH = 0, RH = -1 };				//LE表示左子树深度比右子树深度多2

//定义关键字的类型
//typedef float KeyType;			//关键字为浮点数
typedef int KeyType;					//关键字为整型
//typedef char* KeyType;			//关键字为字符串型

//元素类型，用一个结构体表示
typedef struct RcdType
{
	KeyType key;			//关键字域
	//…………				//元素的其他信息
}RcdType;

//顺序表存储
#define MAXSIZE 20				//一个小顺序表的最大长度
typedef struct SqList
{
	RcdType r[MAXSIZE + 1];		//顺序表存储空间，0号单元留空或作为哨兵单元
	int length;								//顺序表的占用长度
}SqList;

//二叉树的二叉链表存储
typedef struct BiTNode
{
	RcdType data;					//节点数据
	struct BiTNode *lchild, *rchild;			//左右子树
}BiTNode, *BiTree;

//静态链表-表插入排序
#define SIZE (100+1)				//静态链表的容量
typedef struct SLNode     //静态链表的节点结构
{
	RcdType rc;		//记录项
	int next;			//指针项，指向下一个记录的存储位置
	int last;				//指针项，指向上一个记录的存储位置
}SLNode;
typedef struct SLinkList	//静态链表的结构
{
	SLNode r[SIZE];		//0号单元为表头节点		
	int length;					//链表的当前长度
}SLinkList;

//动态链表
typedef struct LinkNode
{
	LinkNode *last;				//指针域，指向链表的上一节点
	RcdType elem;				//数据域，存储有关键字
	LinkNode *next;			//指针域，指向链表的下一节点
}LinkNode, *LinkList;

//堆采用顺序表存储表示-------堆排序
typedef SqList HeapType;

//比较函数，左边大，返回1；一样大，返回0；右边大，返回-1
int Compare(int, int);
int Compare(float, float);
int Compare(char*, char*);

//对于链表的操作函数，成功返回Success，失败返回Error
Status SearchNode(LinkList L, KeyType key, LinkList &LResult);			//在链表中查找关键字所在的节点
Status InsertNode(LinkList L, KeyType key);			//在链表中插入节点
Status DeleteNode(LinkList L, KeyType key);			//在链表中删除节点

#endif