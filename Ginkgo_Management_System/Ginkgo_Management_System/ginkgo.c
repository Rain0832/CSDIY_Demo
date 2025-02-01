#include "ginkgo.h"
#include "common.h"
#include  <stdio.h>
#include  <stdlib.h>

struct Ginkgo ginkgo;//����ȫ�ֱ���
struct Ginkgo* pginkgo = &ginkgo;

void initGinkgo(struct Ginkgo* p)
{
	p->tnum = 0;              //����������
	p->anum = 0;              //��������
	p->bmodify = 0;              //δ�޸�
	p->filename.str[0] = '\0';
}

//����
void save(struct Ginkgo* g)
{
    struct String filename = g->filename;
    //�ж��ļ����Ƿ����
    if (isEmpty(&filename))
    {
        printf("�������ļ���: ");
        gets(filename.str);
    }
   
    if (isEmpty(&filename))
    {
        printf("�ļ���Ϊ�ղ��ܱ���!");
        return;
    }
    //// 1.����ͷ�ļ�
    //// 2.����������
    FILE* fp = NULL;
    //// 3.ָ���򿪵ķ�ʽ    
    fp = fopen(filename.str, "w+");
    if (fp == NULL)
    {
        printf("�����ļ�ʧ�ܣ����治�ɹ�!");
        return;
    }
    //// 4.д����
    fprintf(fp, "%s\n", FILE_CODE);//�ļ���ʽ���
    fprintf(fp, "%d\n",g->anum);//����������
    for(int i = 0; i < g->anum; i++)//��������
        fprintf(fp, "%s %s %d\n", g->areas[i].no.str, g->areas[i].name.str, g->areas[i].useFlag);
    fprintf(fp, "%d\n", g->tnum);//��������
    for (int i = 0; i < g->tnum; i++) {
        fprintf(fp, "%s %d %d %d %d %f %f %d %d %d %d\n",
            g->trees[i].no.str,
            g->trees[i].indexArea,
            g->trees[i].ztime.year, g->trees[i].ztime.month, g->trees[i].ztime.day,
            g->trees[i].height,
            g->trees[i].perimeter,
            g->trees[i].age.year, g->trees[i].age.month, g->trees[i].age.day,
            g->trees[i].state);
    }
    //// 5.�ر��ļ�
    fclose(fp);
    printf("�ļ�����ɹ�!\n");
    g->bmodify = FALSE;

    g->filename = filename;
}

//���ļ�
void open(struct Ginkgo* g)
{
    struct String temp;
    
    struct String filename = g->filename;
    //�ж��ļ����Ƿ����
    if (isEmpty(&filename))
    {
        printf("�������ļ���: ");
        gets(filename.str);
    }

    if (isEmpty(&filename))
    {
        printf("�ļ���Ϊ�ղ��ܱ���!");
        return;
    }
    //// 1.����ͷ�ļ�
    //// 2.����������
    FILE* fp = NULL;
    //// 3.ָ���򿪵ķ�ʽ    
    fp = fopen(filename.str, "r+");
    if (fp == NULL)
    {
        printf("�ļ���ʧ��!");
        return;
    }
    //// 4.������
    fscanf(fp, "%s", temp.str);//�ļ����
    if (strcmp(temp.str, FILE_CODE) != 0)
    {
        printf("��֧�ֵ��ļ���ʽ!");
        fclose(fp);
        return;
    }
    scanf(fp, "%d", &g->anum);//����������
    for (int i = 0; i < g->anum; i++)//��������
        fscanf(fp, "%s %s %d", g->areas[i].no.str, g->areas[i].name.str, &g->areas[i].useFlag);
    fscanf(fp, "%d", &g->tnum);//��������
    for (int i = 0; i < g->tnum; i++) {
        fscanf(fp, "%s %d %d %d %d %f %f %d %d %d %d",
            g->trees[i].no.str,
            &g->trees[i].indexArea,
            &g->trees[i].ztime.year, &g->trees[i].ztime.month, &g->trees[i].ztime.day,
            &g->trees[i].height,
            &g->trees[i].perimeter,
            &g->trees[i].age.year, &g->trees[i].age.month, &g->trees[i].age.day,
            &g->trees[i].state);
    }
    //// 5.�ر��ļ�
    fclose(fp);
    printf("�ļ��򿪳ɹ�!\n");
    g->bmodify = FALSE;

    g->filename = filename;


}