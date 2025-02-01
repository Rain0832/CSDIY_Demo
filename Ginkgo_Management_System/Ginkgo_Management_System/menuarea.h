#pragma once
#include "common.h"
#include "string.h"
#include "menuarea.h"
//��������
// 
//��ӡ������������˵�
void printAreaMenu();
//����˵�����
enum MenuType ProcessAreaMenu(struct String *op);

//�����������
int chectAreasNum(enum AreaUseState use);
//����Ų�������
struct Area* findAreaByNo(struct String* s);
//����Ų���������
int findAreaIndexByNo(struct String* s,enum AreaUseState use);

//��ʾ�������� *
void showAreas();
//����������
//use:-1��������0��ʹ�õ�����1ʹ�õ�����
static int inputAreaNo(enum AreaUseState use);
//��������
static void inputArea(struct Area* pa);
//�����������
void addAreas();
//�޸���������
void modifyArea();
//ɾ������
void deleteArea();


