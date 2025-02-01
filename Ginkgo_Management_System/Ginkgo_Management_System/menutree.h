#pragma once
#include "tree.h"
//��������
// 
//��ӡ������������˵�
void printTreesMenu();
//�˵�����
enum MenuType ProcessTreesMenu(struct String* select);

//����һ�������ڲ�����
void inputTree(struct Tree* t);
//¼��һ��������,�ⲿ����
void addTrees();
//��ʾһ�������ڲ�����
void showTree(struct Tree* t, int i);
//��ʾ����������,�ⲿ����
void showTrees();

//��ѯ
//�������:��Ҫ��ѯ�ı��
//����ֵ���������
int findTreeByNo(struct String* pno);
//�����ģ��ƥ�����Tree�б�
int findTreesListByNo(struct String* pno);
//������ģ��ƥ�����Tree�б�
int findTreesListByArea(struct String* pno);
//������ƥ�����Tree�б�
int findTreesListByAge();
//�޸�
void modifyTree();
//ɾ��
void deleteTree();