#include "area.h"

char* areaUseStateNames[] = {"������","��ʹ��","��Ч״̬"};
void initArea(struct Area* p)
{
	p->name.str[0] = '\0';
	p->no.str[0] = '\0';
	p->useFlag = 0;
}
