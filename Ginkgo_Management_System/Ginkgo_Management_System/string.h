#pragma once
#include <string.h>
#include <stdlib.h>

#define STRING_LENGTH 255//��Ч�ַ��������
#define MAX_STRING_LENGTH STRING_LENGTH+1//����ַ���ռ���ڴ�
//�̵��ַ���
struct String
{
	char str[MAX_STRING_LENGTH];
};

// ��int ת����string
void itos(int i, struct String str);
// ��string ת����int
int stoi(struct String str);
// �ַ�������
int mystrcpy(struct String *src, struct String *des);
//�ж������ַ����Ƿ����,ע��:ֻ�Ƚ�src1�ĳ���
//����ƥ��
int isEqualString(struct String *src1, struct String *src2);
//�ؼ���ƥ��:��ѯsrc���Ƿ����key
int stringMatchKey(struct String* src, struct String* key);
//�ж�String�Ƿ�Ϊ��
int isEmpty(struct String* src);

