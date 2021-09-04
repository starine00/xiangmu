#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


#define default_size 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
//һ���˵���Ϣ
typedef struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peoinfo;

//ͨѶ¼����
typedef struct contact
{
	struct peoinfo *data;//���һ����Ϣ
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
	int capacity;//��ǰͨѶ¼���������
}contact;

enum option
{
	EXIT,//0
	add,//1
	del,//2
	search,//3
	modify,//4
	show,//5
	sort,//6
	save
};


//��������
//��ʼ��ͨѶ¼
void initcontact(struct contact* ps);
//����һ����Ϣ��ͨѶ¼
void addcontact(struct contact*ps);
//��ʾͨѶ¼�е���Ϣ
void showcontact(const struct contact* ps);
//ɾ��ָ����ϵ����Ϣ
void delcontact(struct contact*ps);
//����ָ���˵���Ϣ
void searchcontact(const struct contact*ps);
//�޸�ָ������Ϣ
void modifycontact(struct contact*ps);
////����
//void sortcontact(struct contact*ps);
//void qsort(void * base,size_t num,size_t width,int(*cmp)(const void* e1,void* e2));


//����
void destorycontact(contact *ps);

//����
void savecontact(contact* ps);

//�����ļ��е���Ϣ��ͨѶ¼
void loadcontact(contact* ps);