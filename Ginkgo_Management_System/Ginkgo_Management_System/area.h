#pragma once
#include "string.h"

enum AreaUseState {AREA_NOUSE_STATE=0, AREA_USE_STATE =1,AREA_ALL_STATE=2,
};
struct Area
{
	struct String no;
	struct String name;
	int useFlag;//ɾ����־0ɾ��1ʹ��
};
extern char* areaUseStateNames[];
//��ָ����Ϊ�����������ڴ濽�����Ӷ��������Ч��
void initArea(struct Area *p);


