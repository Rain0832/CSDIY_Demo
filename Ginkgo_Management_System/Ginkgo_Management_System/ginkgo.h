#pragma once
#include "tree.h"

#define MAX_NUM_OF_TREES  1000//���¼����������
#define MAX_NUM_OF_AREAS  100
#define FILE_CODE "Ginkgo"

//������
struct Ginkgo
{
	struct Tree trees[MAX_NUM_OF_TREES];//����������	
	int tnum;              //����������

	struct Area areas[MAX_NUM_OF_AREAS];     //������������
	int anum;              //��������

	int bmodify;              //�Ƿ������޸�1�޸�

	struct String filename;
};

//��ָ����Ϊ�����������ڴ濽�����Ӷ��������Ч��
void initGinkgo(struct Ginkgo *p);

//����
void save(struct Ginkgo *g);
//���ļ�
void open(struct Ginkgo *g);

