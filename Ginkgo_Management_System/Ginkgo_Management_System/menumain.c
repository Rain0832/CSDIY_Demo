#include<stdio.h>
#include "menumain.h"
#include "menutree.h"
#include "ginkgo.h"

extern struct Ginkgo ginkgo;//�ⲿ����
extern struct Ginkgo* pginkgo;
void printMainMenu()
{
    printf("********************************************\n");
    printf("**             ����������ϵͳ             **\n");
    printf("**                                        **\n");
    printf("**              �������˵�                **\n");
    printf("**          1����ʾ�������б�             **\n");
    printf("**          2�������Ų�ѯ������         **\n");
    printf("**          3���޸���������Ϣ             **\n");
    printf("**          4��������ɾ��������         **\n");
    printf("**          5��������������Ϣ�ı��ļ�     **\n");
    printf("**          6������������Ϣ�ı��ļ�     **\n");
    printf("**          7��ͳ�Ƹ�������������         **\n");
    printf("**          8��ͳ�Ƹ�����������           **\n");
    printf("**          9����������Ϣ����             **\n");
    printf("**         10�������������������         **\n");
    printf("**          0���˳�ϵͳ                   **\n");
    printf("**                                        **\n");
    printf("**    ˵����������ѡ���Ӧ�����Խ���ѡ�**\n");
    printf("********************************************\n");
}

enum MenuType ProcessMainMenu(struct String *select)
{
    enum MenuType state = MENU_MAIN;

    if (isEqualString(menuNames[0], select)  ||
        isEqualString(menuNames[21], select) ||
        isEqualString(menuNames[22], select) ||
        isEqualString(menuNames[23], select) ||
        isEqualString(menuNames[24], select) ||
        isEqualString(menuNames[25], select))
    {
        if (ginkgo.bmodify == 1)
        {
            struct String temp;
            printf("�ļ��ѷ����޸�,�Ƿ񱣴棨y:���棬n:�����棩: ");
            gets(temp.str);
            if (temp.str[0] == 'y' || temp.str[0] == 'Y')
                save(pginkgo);
        }
        exit(0);
    }
    else if (isEqualString(menuNames[1], select)) {
        showTrees();
    }
    else if (isEqualString(menuNames[2], select)) {//find trees
        findTreesListByNo(NULL);
    }
    else if (isEqualString(menuNames[3], select)) {//�޸�
        modifyTree();
    }
    else if (isEqualString(menuNames[4], select)) {//ɾ��
        deleteTree();
    }
    else if (isEqualString(menuNames[5], select))
    {
        save(pginkgo);
    }
    else if (isEqualString(menuNames[6], select))
    {        
        open(pginkgo);
    }
    else if (isEqualString(menuNames[7], select)) {
        findTreesListByArea(NULL);//todo
    }
    else if (isEqualString(menuNames[8], select)) {
        findTreesListByAge();
    }
    else if (isEqualString(menuNames[9], select)) {
        if (chectAreasNum(pginkgo))
            state = MENU_TREES;
    }
    else if (isEqualString(menuNames[10], select)) {
        state = MENU_AREA;
        printf("���������������\n");
    }
    else
        printf("��֧�ֵĹ��ܣ�����ѡ!\n");

    return state;
}

