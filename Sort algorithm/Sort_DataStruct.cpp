#include "Sort_DataStruct.h"

//�ȽϺ�������ߴ󣬷���1��һ���󣬷���0���ұߴ󣬷���-1
int Compare(int i, int j)
{
	if (i > j)		return 1;
	else if (i == j)	return 0;
	else    return -1;
}
int Compare(float i, float j)
{
	if (i > j)		return 1;
	else if (i == j)	return 0;
	else    return -1;
}
int Compare(char* i, char* j)
{
	int tmp = strcmp(i, j);
	if (tmp > 0)		return 1;
	else if (tmp == 0)	return 0;
	else    return -1;
}

Status SearchNode(LinkList L, KeyType key, LinkList & LResult)				//�������в��ҹؼ������ڵĽڵ�
{
	/*L��ָ�򱻲��ҵ�����key�������ҵĹؼ��֣�LResult��ָ����Ŀ��ؼ��ֵĽڵ�
	**���ҳɹ�������Success������ʧ�ܣ�����Error
	*/
	LResult = L;			//��ʼLResultӦָ������ͷ
	LinkList L_tmp = L->next;
	Status result = Error;
	while (L_tmp)
	{
		LResult = L_tmp;
		int tmp = Compare(L_tmp->elem.key, key);
		if (tmp == 0)
		{
			result = Success;
			break;
		}
		L_tmp = L_tmp->next;
	}
	return result;
}

Status InsertNode(LinkList L, KeyType key)			//�������в���ڵ�
{
	/*L��ָ��Ҫ���������key��Ҫ����Ĺؼ���
	**����ɹ�������Success������ʧ�ܣ����������иýڵ㣩������Error
	*/
	LinkList LPosition = NULL;
	if (SearchNode(L, key, LPosition))		//���иùؼ��֣�����ʧ��
		return Error;
	else
	{
		LinkList NewNode = new LinkNode;
		NewNode->elem.key = key;
		NewNode->next = NULL;
		NewNode->last = LPosition;
		LPosition->next = NewNode;		//�����йؼ��ֵĽڵ����ĩβ
		return Success;
	}
}

Status DeleteNode(LinkList L, KeyType key)			//��������ɾ���ڵ�
{
	/*L��ָ��Ҫɾ��������key��Ҫɾ���Ĺؼ���
	**ɾ���ɹ�������Success��ɾ��ʧ�ܣ����������иýڵ㣩������Error
	*/
	LinkList LPosition = NULL;
	if (!SearchNode(L, key, LPosition))		//δ�ҵ��ùؼ��֣�ɾ��ʧ��
		return Error;
	else
	{
		if (LPosition->next)		//���йؼ��ֵĽڵ㻹����һ���ڵ�
		{
			LPosition->last->next = LPosition->next;			//����ָ��
			LPosition->next->last = LPosition->last;
		}
		else
			LPosition->last->next = NULL;			//����ָ��
		delete LPosition;		//�ͷŽڵ�
		return Success;
	}
}
