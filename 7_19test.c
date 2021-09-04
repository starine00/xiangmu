//1.存放好友信息
//名字
//电话
//性别
//地址
//年龄
//2.增加好友信息
//3.删除指定名字好友信息
//4.查找好友信息
//5.修改好友信息
//6.打印好友信息(显示出来)

#include "7_19声明函数contact.h"
void menu()
{
	printf("******************************\n");
	printf("******1.add     2.del**********\n");
	printf("******3.search   4.modify*****\n");
	printf("*******5.show    6.sort******\n");
	printf("********7.save   0.EXIT********\n");
	printf("*******************************\n");
}
int main()
{
	int input=0;
	struct contact con;//con就是通讯录，里面包含data指针个capacity和size
	initcontact(&con);//初始化通讯录 传地址才能改变con 并且传地址效率高
	do
	{
		menu();	
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
		case add:
			addcontact(&con);
			break;
		case del:
			delcontact(&con);
			break;
		case search:
			searchcontact(&con);
			break;
		case modify:
			modifycontact(&con);
			break;
		case show:
			showcontact(&con);
			break;
		case sort:
			/*sortcontact(&con);*/
			break;
		case EXIT:
			savecontact(&con);
			destorycontact(&con);
			printf("退出通讯录\n");
			break;
		case save:
			savecontact(&con);
			break;
		default:
			printf("选择错误\n");
			break;
		}
	}while(input);

	system("pause");
	return 0;
}