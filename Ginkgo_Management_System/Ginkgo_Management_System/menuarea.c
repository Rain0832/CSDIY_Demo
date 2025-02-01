#include "menuarea.h"
#include "ginkgo.h"
#include "string.h"
#include "common.h"

extern struct Ginkgo ginkgo;//�ⲿ����

//��ӡ������������˵�
void printAreaMenu()
{
    printf("            ���������ֹ���ϵͳ         \n");
    printf("*************���ֹ������˵�************\n");
    printf("*********** 1����ʾ�������� **********\n");
    printf("*********** 2�������������� **********\n");
    printf("*********** 3���޸��������� **********\n");
    printf("*********** 4��ɾ���������� **********\n");
    printf("*********** 0���˳������������ ******\n");
}
//�˵�����
enum MenuType ProcessAreaMenu(struct String *select)
{
    enum MenuType state = MENU_AREA;
    if (isEqualString(menuNames[1],select)) 
    {//��ʾ��������
        showAreas();
    }
    else if (isEqualString(menuNames[2],select)) {//���
        addAreas();
    }
    else if (isEqualString(menuNames[3],select)) {//�޸�
		if (chectAreasNum(AREA_ALL_STATE))
			modifyArea();
    }
    else if (isEqualString(menuNames[4],select)) {//ɾ��
		if (chectAreasNum(AREA_USE_STATE))
			deleteArea();
		printf("���򲻴���,���������������򣡣���");
    }
    else if (isEqualString(menuNames[0],select)) {//�˳�
        state = MENU_MAIN;
        printf("�˳������������");
    }
    else
        printf("��֧�ֵĹ��ܣ�����ѡ!");

    return state;
}

//�����������
int chectAreasNum(enum AreaUseState use)
{
	int i = 0, n0 = 0, n1 = 0;	
	for (i = 0; i < ginkgo.anum; i++)
	{
		if (ginkgo.areas[i].useFlag == AREA_NOUSE_STATE)
		{
			n0++;
		}
		else if (ginkgo.areas[i].useFlag == AREA_USE_STATE)
		{
			n1++;
		}
	}
	if (use == AREA_NOUSE_STATE)
		return n0;
	else if (use == AREA_USE_STATE)
		return n1;

	return n0+n1;
}

//��ʾ��������
void showAreas()
{
	printf("�������� %d ��\n", ginkgo.anum  );
	for (int i = 0; i < ginkgo.anum; i++)
	{
		printf("%d %s %s %s\n",i , 
			ginkgo.areas[i].no, 
			ginkgo.areas[i].name, 
			areaUseStateNames[ginkgo.areas[i].useFlag]);
	}
}

//����������
static int inputAreaNo(enum AreaUseState use)
{
	int n = -1;
	if (!chectAreasNum(use))
		return n;
	struct Area a;
	while (TRUE)
	{
		printf("����������������: ");
		gets(a.no.str);
		if ((n = findAreaIndexByNo(&a.no, use)) != -1)
			break;
		printf("������Ϸ��ı��!");
	}
	printf("%s %s\n", ginkgo.areas[n].no, ginkgo.areas[n].name);
	return n;
}

void inputArea(struct Area* pa)
{
	struct Area a;
	do {
		printf("����������������: ");
		gets(a.no.str);
		if (findAreaByNo(&a.no) == NULL)//todoΨһ�Լ��
		{
			break;
		}
		printf("����Ѵ��ڣ�����������!\n");
	} while (1);
	printf("������������������: ");
	gets(a.name.str);
	a.useFlag = 1;
	*pa = a;
}

//�����������
void addAreas()
{
	inputArea(&ginkgo.areas[ginkgo.anum]);//������β��
	ginkgo.anum++;//����������������
}

//����Ų�������
struct Area* findAreaByNo(struct String* s)
{
	int n;
	struct Area* p = NULL;
	for (n = 0; n < ginkgo.anum; n++) {
		p = &ginkgo.areas[n];
		if (isEqualString(s, &p->no) == TRUE)
			return p;
	}
	return NULL;
}

//����Ų���������
int findAreaIndexByNo(struct String* s, enum AreaUseState use)
{
	int n;
	for (n = 0; n < ginkgo.anum; n++)
	{
		if (use != AREA_ALL_STATE)
		{
			if (ginkgo.areas[n].useFlag != use)
				continue;
		}
		
		if (isEqualString(s, &ginkgo.areas[n].no) == TRUE)
			return n;
	}
	return -1;
}

//�޸���������
void modifyArea()
{
	int n = 0;
	struct Area a;
	n = inputAreaNo(AREA_ALL_STATE);
	ginkgo.areas[n].no.str[0] = '\0';//��������
	inputArea(&ginkgo.areas[n]);
}

//ɾ������
void deleteArea()
{
	int n = -1,i = 0;

	//����Ҫɾ��������no
	n = inputAreaNo(AREA_USE_STATE);
	//�ж������Ƿ�������
	for (i = 0; i < ginkgo.tnum; i++)
	{
		if (n == ginkgo.trees[i].indexArea)
		{
			printf("�������ѱ�ʹ�ã�����ɾ��!\n");
			//todo show tree
			return;
		}
	}
	////���û��������ɾ��
	//for (i = n + 1; i < ginkgo.anum; i++)
	//{
	//	ginkgo.areas[i - 1] = ginkgo.areas[i];//��ǰ��
	//}
	ginkgo.areas[i].useFlag = 0;
	printf("ɾ���ɹ�!\n");
}

