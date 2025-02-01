#pragma once
#include "string.h"
#include "date.h"
#include "area.h"

enum StateTree {STATE_DEATH = 0, STATE_LIVE = 1,STATE_UNKOWN = 2,
};
//��������Ϣ����� ���ֵ��� ����ʱ�� �� �� ���� �Ƿ��
struct Tree
{
	struct String no;
	int indexArea;//�����������,���򲻻ᱻ����ɾ�������Կ����������±�
	struct Date ztime;
	float height;
	float perimeter;
	struct Date age;
	enum StateTree state;//1���
};
//��ָ����Ϊ�����������ڴ濽�����Ӷ��������Ч��
void initTree(struct Tree *p);