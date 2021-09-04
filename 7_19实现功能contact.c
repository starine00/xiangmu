#include "7_19声明函数contact.h"
#include <stdlib.h>
//初始化通讯录功能实现
void initcontact(struct contact*ps)
{
	ps->data=(struct peoinfo*)malloc(3*sizeof(struct peoinfo));
	if(ps->data == NULL)
	{
		return ;
	}
	ps->size=0;
	ps->capacity=default_size;
	//把文件中已经存放的通讯录中的信息加载到通讯录中
	loadcontact(ps);
}


//加载文件中的信息到通讯录
void checkcapacity(struct contact* ps);
void loadcontact(contact* ps)
{
	peoinfo tmp={0};
	int i=0;
	FILE* pfread=fopen("contact.dat","rb");
	if(pfread==NULL)
	{
		printf("loadcontact::%s\n",strerror(errno));
		return ;
	}
	//读取文件，存放到通讯录中
	while(fread(&tmp,sizeof(peoinfo),1,pfread))
	{
		checkcapacity(ps);
		ps->data[ps->size]=tmp;
		ps->size++;
	}
	fclose(pfread);
	pfread=NULL;
}

void checkcapacity(struct contact* ps)
{
	if(ps->size == ps->capacity)
	{
		struct peoinfo* ptr =realloc(ps->data,(ps->capacity+2)*sizeof(peoinfo));
		if(ptr != NULL)
		{
			ps->data=ptr;
			ps->capacity +=2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}

//增加一个信息到通讯录
void addcontact(struct contact* ps)
{
	checkcapacity(ps);//检测当前通讯录的容量，如果满了就增容，如果不满，啥事不干
	printf("请输入名字>");
	scanf("%s",ps->data[ps->size].name);
	printf("请输入年龄>");
	scanf("%d",&(ps->data[ps->size].age));
	printf("请输入性别>");
	scanf("%s",ps->data[ps->size].sex);
	printf("请输入电话>");
	scanf("%s",ps->data[ps->size].tele);
	printf("请输入地址>");
	scanf("%s",ps->data[ps->size].addr);
	ps->size++;
	printf("添加成功\n");
}
	

//显示通讯录中的信息
void showcontact(const struct contact* ps)
{
	if(ps->size==0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i=0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		for(i=0;i<ps->size;i++)
		{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
		}
	}

}




static int findbyname(const struct contact* ps,char name[MAX_NAME])
{
	int i=0;
	for(i=0;i<ps->size;i++)
	{
		if(0==strcmp(ps->data[i].name,name))
		{
			return i;//找得到返回下标
		}
	}
	return -1;//找不到
}



//删除指定联系人信息
void delcontact(struct contact*ps)
{
	int pos=0;
	char name[MAX_NAME];
	printf("请输入要删除的名字 >");
	scanf("%s",name);
	//1.查找要删除的人
	//找到了返回名字所在下标
	//找不到返回-1
	 pos=findbyname(ps,name);//去ps里面找name
	
	//2.删除
	if(pos== -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j=0;
		for(j=pos;j<ps->size-1;j++)
		{
			ps->data[j]=ps->data[j+1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}


//查找指定人的信息
void searchcontact(const struct contact*ps)
{
	int pos=0;
	int i=0;
	char name[MAX_NAME];
	printf("请输入要查找人的信息>");
	scanf("%s",name);
	pos=findbyname(ps,name);
	if(pos == -1)
	{
		printf("要查找的人不存\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
	}
}




//修改指定人信息
void modifycontact(struct contact*ps)
{
	int pos=0;
	char name[MAX_NAME];
	printf("请输入要修改人的名字>");
	scanf("%s",name);
	pos=findbyname(ps,name);
	if(pos==-1)
	{
		printf("要修改的人信息不存在\n");
	}
	else
	{
		printf("请输入名字>");
		scanf("%s",ps->data[pos].name);
		printf("请输入年龄>");
		scanf("%d",&(ps->data[pos].age));
		printf("请输入性别>");
		scanf("%s",ps->data[pos].sex);
		printf("请输入电话>");
		scanf("%s",ps->data[pos].tele);
		printf("请输入地址>");
		scanf("%s",ps->data[pos].addr);
		printf("修改完成\n");
	}
}



//int cmp_stu_by_name( void*e1, void*e2)
//{
//	//比较名字就是比较字符串
//	//字符串比较不能用><=来比较，要用strcmp函数
//
//	return strcmp(((struct stu*)e1)->name,((struct stu*)e2)->name);
//}
//
//
//void sortcontact(struct contact*ps)
//{
//	int sz=sizeof(struct peoinfo)/sizeof(struct peoinfo[1]);
//	qsort(peoinfo,sz,sizeof(s[0]),cmp_stu_by_name);//cmp_stu_by_name
//	
//}



//销毁
void destorycontact(contact*ps)
{
	free(ps->data);
	ps->data=NULL;
}



void savecontact(contact* ps)
{
	int i=0;
	FILE* pfwrite=fopen("contact.dat","wb");
	if(pfwrite == NULL)
	{
		printf("%s\n",strerror(errno));
		return ;
	}
	//写通讯录中的数据到文件中
	
	for(i=0;i < ps->size;i++ )
	{
		fwrite(&(ps->data[i]),sizeof(peoinfo),1,pfwrite);
	}
	fclose(pfwrite);
	pfwrite=NULL;
}


