//1.��ź�����Ϣ
//����
//�绰
//�Ա�
//��ַ
//����
//2.���Ӻ�����Ϣ
//3.ɾ��ָ�����ֺ�����Ϣ
//4.���Һ�����Ϣ
//5.�޸ĺ�����Ϣ
//6.��ӡ������Ϣ(��ʾ����)

#include "7_19��������contact.h"
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
	struct contact con;//con����ͨѶ¼���������dataָ���capacity��size
	initcontact(&con);//��ʼ��ͨѶ¼ ����ַ���ܸı�con ���Ҵ���ַЧ�ʸ�
	do
	{
		menu();	
		printf("��ѡ��");
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
			printf("�˳�ͨѶ¼\n");
			break;
		case save:
			savecontact(&con);
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	}while(input);

	system("pause");
	return 0;
}