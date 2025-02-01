#include "ginkgo.h"
#include "menutree.h"
#include "common.h"
#include "menuarea.h"
#include <stdio.h>

extern struct Ginkgo ginkgo;//�ⲿ����

//��ӡ������������˵�
void printTreesMenu()
{
	printf("            ����������ϵͳ          \n");
	printf("*************��������ľ���˵�*******\n");
	printf("*********** 1����ʾ������ľ ********\n");
	printf("*********** 2��������ľ   **********\n");
	printf("*********** 3���޸���ľ   **********\n");
	printf("*********** 4��ɾ����ľ   **********\n");
	printf("*********** 0���˳�������ľ���� ****\n");
}
//�˵�����
//����ֵ���˵�ѡ��
//����ֵ���˵�����
enum MenuType ProcessTreesMenu(struct String* select)
{
	enum MenuType state = MENU_TREES;//��ǰ����˵�
	if (isEqualString(menuNames[1], select))
	{//��ʾ������ľ
		showTrees();
	}
	else if (isEqualString(menuNames[2], select)) {//���
		addTrees();
	}
	else if (isEqualString(menuNames[3], select)) {//�޸�
		modifyTree();
	}
	else if (isEqualString(menuNames[4], select)) {//ɾ��
		deleteTree();
	}
	else if (isEqualString(menuNames[0], select)) {//�˳�
		state = MENU_MAIN;//�������˵�
		printf("�˳���ľ����");
	}
	else
		printf("��֧�ֵĹ��ܣ�����ѡ!");

	return state;
}

void inputTree(struct Tree* t)
{
	struct String no;
	printf("��������(0000): ");
	gets(t->no.str); //��Ų����ظ�
	printf("����������ʱ��(2000 12 12): ");
	scanf("%d%d%d", &t->ztime.year, &t->ztime.month, &t->ztime.day);//���ڸ�ʽ���
	while (TRUE)
	{
		printf("����������������:");
		gets(no.str);
		if ((t->indexArea = findAreaIndexByNo(&no, AREA_USE_STATE)) != -1)
			break;
		printf("δ�ҵ�����������,����������!");
	}
	printf("����������: ");
	scanf("%f", &t->height);
	printf("����������Χ: ");
	scanf("%f", &t->perimeter);
	printf("����������(2000 12 12): ");
	scanf("%d%d%d", &t->age.year, &t->age.month, &t->age.day);
	t->state = STATE_LIVE;
	return t;
}

//¼��һ��������
void addTrees()
{
	if (ginkgo.tnum >= MAX_NUM_OF_TREES)
	{
		puts("���ݴﵽ����1000,������¼������!!!\n");
		return;
	}
	inputTree(&ginkgo.trees[ginkgo.tnum]);

	ginkgo.tnum++;
}
//��ʾһ����
void showTree(struct Tree* t, int i)
{
	printf("%d %s %s %d-%d-%d %f %f %d-%d-%d %d\n",
		i,
		t->no,
		ginkgo.areas[t->indexArea].name.str,
		t->ztime.year, t->ztime.month, t->ztime.day,
		t->perimeter,
		t->height,
		t->age.year, t->age.month, t->age.day,
		t->state
	);
}

//��ʾ����������
void showTrees()
{
	printf("���������� %d  ��\n", ginkgo.tnum);
	
	for (int i = 0; i < ginkgo.tnum; i++)
		showTree(&ginkgo.trees[i], i);
}

//��ѯ����ȷ����
//�������:��Ҫ��ѯ�ı��
//����ֵ���������
int findTreeByNo(struct String *pno)
{
	struct String no;
	if (pno != NULL)
	{
		no = *pno;
	}
	if (isEmpty(&no))//���û�����룬��Ҫ����
	{
		puts("���������������: ");
		gets(no.str);
	}
	if (isEmpty(&no))
	{
		puts("��Ч����������ţ�");
		return -1;
	}
	for (int i = 0; i < ginkgo.tnum; i++)
	{
		if (isEqualString(&ginkgo.trees[i].no, &no)) {
			showTree(&ginkgo.trees[i], i);
			return i;
		}
	}
	printf("û�鵽������!\n");
	return -1;
}
//ģ��ƥ�����Tree�б�
int findTreesListByNo(struct String* pno)
{
	int n = 0;
	struct String no;
	no.str[0] = '\0';
	if (pno != NULL)
		no = *pno;
	if (isEmpty(&no))//���û�����룬��Ҫ����
	{
		puts("���������������: ");
		gets(no.str);
	}
	if (isEmpty(&no))
	{
		puts("��Ч����������ţ�\n");
		return -1;
	}
	for (int i = 0; i < ginkgo.tnum; i++)
	{
		if (stringMatchKey(&ginkgo.trees[i].no, &no)) {
			showTree(&ginkgo.trees[i], i);
			n++;
		}
	}
	printf("����ѯ�������� %d ��\n",n);
	return n;
}

//������ģ��ƥ�����Tree�б�
int findTreesListByArea(struct String* pno)
{
	printf("�ù���δʵ�֣�����ѡ!\n");
}
//������ƥ�����Tree�б�
int findTreesListByAge()
{
	printf("�ù���δʵ�֣�����ѡ!\n");
}
//�޸�
//todo
void modifyTree()
{
	printf("�ù���δʵ�֣�����ѡ!\n");
}

//ɾ��
void deleteTree()
{
	int index = findTreeByNo(NULL);//��ѯ��Ҫɾ������
	if (index > 0)
	{
		for (int i = index + 1; i < ginkgo.tnum; i++)//�������������ǰ�ƶ�
			ginkgo.trees[i - 1] = ginkgo.trees[i];
		ginkgo.tnum--;//������ľ����
		if (ginkgo.tnum < 0)
			ginkgo.tnum = 0;
		printf("ɾ���ɹ�\n");
	}
}
