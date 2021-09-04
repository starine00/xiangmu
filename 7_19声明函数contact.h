#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


#define default_size 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
//一个人的信息
typedef struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peoinfo;

//通讯录类型
typedef struct contact
{
	struct peoinfo *data;//存放一个信息
	int size;//记录当前已经有的元素个数
	int capacity;//当前通讯录的最大容量
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


//声明函数
//初始化通讯录
void initcontact(struct contact* ps);
//增加一个信息到通讯录
void addcontact(struct contact*ps);
//显示通讯录中的信息
void showcontact(const struct contact* ps);
//删除指定联系人信息
void delcontact(struct contact*ps);
//查找指定人的信息
void searchcontact(const struct contact*ps);
//修改指定人信息
void modifycontact(struct contact*ps);
////排序
//void sortcontact(struct contact*ps);
//void qsort(void * base,size_t num,size_t width,int(*cmp)(const void* e1,void* e2));


//销毁
void destorycontact(contact *ps);

//保存
void savecontact(contact* ps);

//加载文件中的信息到通讯录
void loadcontact(contact* ps);