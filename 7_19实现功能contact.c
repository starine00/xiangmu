#include "7_19��������contact.h"
#include <stdlib.h>
//��ʼ��ͨѶ¼����ʵ��
void initcontact(struct contact*ps)
{
	ps->data=(struct peoinfo*)malloc(3*sizeof(struct peoinfo));
	if(ps->data == NULL)
	{
		return ;
	}
	ps->size=0;
	ps->capacity=default_size;
	//���ļ����Ѿ���ŵ�ͨѶ¼�е���Ϣ���ص�ͨѶ¼��
	loadcontact(ps);
}


//�����ļ��е���Ϣ��ͨѶ¼
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
	//��ȡ�ļ�����ŵ�ͨѶ¼��
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
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}

//����һ����Ϣ��ͨѶ¼
void addcontact(struct contact* ps)
{
	checkcapacity(ps);//��⵱ǰͨѶ¼��������������˾����ݣ����������ɶ�²���
	printf("����������>");
	scanf("%s",ps->data[ps->size].name);
	printf("����������>");
	scanf("%d",&(ps->data[ps->size].age));
	printf("�������Ա�>");
	scanf("%s",ps->data[ps->size].sex);
	printf("������绰>");
	scanf("%s",ps->data[ps->size].tele);
	printf("�������ַ>");
	scanf("%s",ps->data[ps->size].addr);
	ps->size++;
	printf("��ӳɹ�\n");
}
	

//��ʾͨѶ¼�е���Ϣ
void showcontact(const struct contact* ps)
{
	if(ps->size==0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i=0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
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
			return i;//�ҵõ������±�
		}
	}
	return -1;//�Ҳ���
}



//ɾ��ָ����ϵ����Ϣ
void delcontact(struct contact*ps)
{
	int pos=0;
	char name[MAX_NAME];
	printf("������Ҫɾ�������� >");
	scanf("%s",name);
	//1.����Ҫɾ������
	//�ҵ��˷������������±�
	//�Ҳ�������-1
	 pos=findbyname(ps,name);//ȥps������name
	
	//2.ɾ��
	if(pos== -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j=0;
		for(j=pos;j<ps->size-1;j++)
		{
			ps->data[j]=ps->data[j+1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}


//����ָ���˵���Ϣ
void searchcontact(const struct contact*ps)
{
	int pos=0;
	int i=0;
	char name[MAX_NAME];
	printf("������Ҫ�����˵���Ϣ>");
	scanf("%s",name);
	pos=findbyname(ps,name);
	if(pos == -1)
	{
		printf("Ҫ���ҵ��˲���\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
	}
}




//�޸�ָ������Ϣ
void modifycontact(struct contact*ps)
{
	int pos=0;
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵�����>");
	scanf("%s",name);
	pos=findbyname(ps,name);
	if(pos==-1)
	{
		printf("Ҫ�޸ĵ�����Ϣ������\n");
	}
	else
	{
		printf("����������>");
		scanf("%s",ps->data[pos].name);
		printf("����������>");
		scanf("%d",&(ps->data[pos].age));
		printf("�������Ա�>");
		scanf("%s",ps->data[pos].sex);
		printf("������绰>");
		scanf("%s",ps->data[pos].tele);
		printf("�������ַ>");
		scanf("%s",ps->data[pos].addr);
		printf("�޸����\n");
	}
}



//int cmp_stu_by_name( void*e1, void*e2)
//{
//	//�Ƚ����־��ǱȽ��ַ���
//	//�ַ����Ƚϲ�����><=���Ƚϣ�Ҫ��strcmp����
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



//����
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
	//дͨѶ¼�е����ݵ��ļ���
	
	for(i=0;i < ps->size;i++ )
	{
		fwrite(&(ps->data[i]),sizeof(peoinfo),1,pfwrite);
	}
	fclose(pfwrite);
	pfwrite=NULL;
}


