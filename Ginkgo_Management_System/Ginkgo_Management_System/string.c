#include "string.h"
#include <string.h>
#include <stdlib.h>
#include "common.h"

// ��int ת����string
void itos(int i, struct String str)
{
	_itoa(i, str.str, 10);
}

// ��string ת����int
int stoi(struct String str)
{
	return atoi(str.str);
}

// �ַ�������
int mystrcpy(struct String *src, struct String *des)
{
	int i;
	int n = MIN(strlen(src->str), STRING_LENGTH);
	for (i = 0; i < n; i++)
		des->str[i] = src->str[i];
	des->str[n] = '\0';
}

//�ж������ַ����Ƿ����,ע��:ֻ�Ƚ�src1�ĳ���
int isEqualString(struct String *src1, struct String *src2)
{
	if (src1 == NULL || src2 == NULL)
		return FALSE;

	if(strcmp(src1->str, src2->str) == 0)
		return TRUE;
	return FALSE;
}

//�ؼ���ƥ��:��ѯsrc���Ƿ����key
int stringMatchKey(struct String* src, struct String* key)
{
	int is = FALSE;
	if (src == NULL || key == NULL)
		return is;
	char* psrc = src->str;
	char* pkey = key->str;
	int i,j,n = strlen(psrc), m = strlen(pkey);
	for (i = 0; i < n - m + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (psrc[i+j] != pkey[j])//�в�ƥ����ǰ��ֹƥ��
				break;
		}
		if (j == m)//�ҵ�ƥ�䲻�ټ���ƥ����ǰ�˳�
		{
			is = TRUE;
			break;
		}
	}
	return is;
}

//�ж�String�Ƿ�Ϊ��
//�ջ򲻴��ڣ�TRUE
//��������Ч����ֵ����FALSE��Ϊ��
int isEmpty(struct String* src)
{
	if (src != NULL && src->str[0] != '\0')
		return FALSE;
	return TRUE;
}