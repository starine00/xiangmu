
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define N 100 
//using namespace std;

struct mar//�ýṹ��Ϊ�洢������Ϣ 
{
    char ID[10];//���� 
    char brand[20];//Ʒ��
    double inprice;//���� 
    double outprice;//�ۼ�
    int storage;//�洢�� 
    char date[11];//������ 
};

struct node//�ýṹ��Ϊ�洢���ﳵ�е���Ϣ 
{
    struct mar buy;//������Ϣ 
    int number;//��������� 
    struct node* next; //ָ����һ������ڵ� 
}NODE;
struct mar goods[N];//�ṹ������ 
struct node* cart;//���ﳵͷ��� 

int menu1();//��ӡ���˵����� 
int menu2();//��ӡ����Ա�˵����� 
int menu3();//��ӡ�˿ͺ��� 
void CreateGoods();//¼����Ʒ��Ϣ���� 
void ShowGoods();//��ʾ�����Ϣ����
void ShopCart();//�Թ��ﳵ���в���
int ShopCartMenu();//��ӡ���ﳵ�˵�
void ShowCart();//��ʾ�����б�
void add();//�ڹ��ﳵ�������Ʒ 
void UpdateKu();//���¹��ﳵ��Ϣ���� 
void  calculate();//����������Ʒ�۸��޸ı��� 

//#endif



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int login() {
    //����Ա���� 
    int username = 10001;
    int password = 1234;
    int scuser;
    int scpass;
    printf("���������Ա��� \n");
    scanf("%d", &scuser);//�������Ա��� 
    printf("���������Ա���� \n");
    scanf("%d", &scpass);//�������Ա���� 
    if (username == scuser && password == scpass)
        return 1;
    else
        return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu1()
{//��ӡ���˵�����
    char s[5];//�����ѡ�� 
    int n;//ѡ��Ϊ���� 
    printf("\n\n��ѡ����������ֱ��������ݣ�\n");
    printf("1. ����Ա\n");
    printf("2. �˿�\n");
    printf("3. �˳�ϵͳ\n");
    printf("*********************************************************\n");
    printf("--------------------------------------------\n");
    printf("��ѡ���Ӧ����1~3\n");


    while (1)
    {
        fflush(stdin);//���������
        gets_s(s);//����һ���ַ��� 
        n = atoi(s);//�ַ���ת��Ϊ���� 
        if (n < 1 || n>3)//�ж������ѡ���Ƿ���ȷ
            printf("����������������룺\n");
        else//������ȷ������ѭ�� 
            break;
    }
    return n;//��������ѡ�� 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu2()
{//��ӡ���˵�����
    char s[5];//�����ѡ�� 
    int n;//ѡ��Ϊ���� 
    printf("\n\n��ѡ����������ֽ��в�����\n");
    printf("--------------------------------------------\n");
    printf("1. ¼����Ʒ��Ϣ\n");
    printf("2. ��ʾ������Ʒ��Ϣ\n");
    printf("3. ������һ��\n");
    printf("4. �˳�����\n");
    printf("--------------------------------------------\n");
    printf("��ѡ���Ӧ����1~4\n");


    while (1)
    {
        fflush(stdin);//���������
        gets_s(s);//����һ���ַ��� 
        n = atoi(s);//�ַ���ת��Ϊ���� 
        if (n < 1 || n>4)//�ж������ѡ���Ƿ���ȷ
            printf("����������������룺\n");
        else//������ȷ������ѭ�� 
            break;
    }
    return n;//��������ѡ�� 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu3()
{//��ӡ���˵�����
    char s[5];//�����ѡ�� 
    int n;//ѡ��Ϊ���� 
    printf("\n\n��ѡ����������ֽ��в�����\n");
    printf("--------------------------------------------\n");
    printf("1. ���ﳵ\n");
    printf("2. ����\n");
    printf("3. ������һ��\n");
    printf("4. �˳�����\n");
    printf("--------------------------------------------\n");
    printf("��ѡ���Ӧ����1~4\n");


    while (1)
    {
        fflush(stdin);//���������
        gets_s(s);//����һ���ַ��� 
        n = atoi(s);//�ַ���ת��Ϊ���� 


        if (n < 1 || n>4)//�ж������ѡ���Ƿ���ȷ
            printf("����������������룺\n");
        else//������ȷ������ѭ�� 
            break;
    }
    return n;//��������ѡ�� 
}


int n = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CreateGoods()
{//�ֶ����������Ϣ
    FILE* fp;//�����ļ�ָ�� 
    int i;
    printf("��������Ҫ¼�����Ʒ������\n");
    scanf("%d", &n);//�������� 
    printf("���������������Ϣ��\n");
    printf("--------------------------------------------\n");
    for (i = 0; i < n; i++)
    {//���ļ���д����Ϣ
        printf("��%d����Ʒ��\n", i + 1);
        printf("���ţ�");
        fflush(stdin);//���������
        gets_s(goods[i].ID);//�������

        printf("Ʒ����");
        fflush(stdin);//���������
        gets_s(goods[i].brand);//����Ʒ�� 

        printf("����: ");
        fflush(stdin);//���������
        scanf("%lf", &goods[i].inprice);//������� 

        printf("�ۼۣ�");
        fflush(stdin);//���������
        scanf("%lf", &goods[i].outprice);//�����ۼ� 

        printf("������");
        fflush(stdin);//���������
        scanf("%d", &goods[i].storage);//�������� 


        printf("�����ڣ�");
        fflush(stdin);//���������
        gets_s(goods[i].date);//�������
        printf("\n");
    }
    if ((fp = fopen("kucun.txt", "w")) == NULL)
    {//�ж��ļ��Ƿ񴴽�ʧ��
        printf("�����ļ�ʧ�ܡ�\n");
        return;
    }
    //fprintf(fp,"����       Ʒ��      ����    �����   ������\n");
    for (i = 0; i < n; i++)
    {//�ѻ�����Ϣд���ļ�
        fprintf(fp, "%-11s%-15s%-8.3f%-8.3f%-11d%-11s\n", goods[i].ID, goods[i].brand, goods[i].inprice, goods[i].outprice, goods[i].storage, goods[i].date);
    }
    //fwrite(goods,sizeof(struct mar),N,cun);�������ļ���� 
    fclose(fp);//�ر��ļ� 
    printf("��Ϣ����ɹ�\n");
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ShowGoods()
{//��ʾ�����Ϣ����
    FILE* fp;//�����ļ�ָ�� 
    int i;
    if ((fp = fopen("kucun.txt", "r")) == NULL)
    {//�ж��Ƿ�����ļ�
        printf("���ļ�ʧ��\n");
        return;
    }

    for (i = 0; i < n; i++)
    {//�����Ʒ��Ϣ
      //��ȡ�ļ���Ϣ 
        fscanf(fp, "%s%s%lf%lf%d%s", goods[i].ID, goods[i].brand, &goods[i].inprice, &goods[i].outprice, &goods[i].storage, goods[i].date);
        printf("--------------------------------------------\n");
        //����ļ���Ϣ 
        printf("���       ����           ����    �����     ������\n");
        printf("%-11s%-15s%-8.3f%-11d%-11s\n", goods[i].ID, goods[i].brand, goods[i].outprice, goods[i].storage, goods[i].date);
    }
    fclose(fp);//�ر��ļ� 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void  ShopCart()
{//�Թ��ﳵ���в���
    while (1)
    {
        switch (ShopCartMenu())
        {//ShopCartMenu()Ϊ����ѡ��
        case 1: ShowGoods();
            break;//ѡ��1 ��ʾ���ﳵ��Ʒ��Ϣ
        case 2: add();
            break;//ѡ��2 ��ӹ��ﳵ��Ʒ
        case 3: ShowCart();
        case 4: return;//ѡ��3 �˳� 

        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ShopCartMenu()
{//��ӡ���ﳵ�˵�
    int n;//Ϊ���� 
    char s[5];//����һ���ַ��� 
    printf("\n\n��ѡ�������\n");
    printf("--------------------------------------------\n");
    printf("1. ��ʾ��Ʒ�б�\n");
    printf("2. �ڹ��ﳵ�������Ʒ\n");
    printf("3. ��ʾ���ﳵ��Ʒ\n");
    printf("4. �˳�\n");
    printf("--------------------------------------------\n");
    printf("��ѡ���Ӧ����1~4\n");


    while (1)
    {
        fflush(stdin);//���������
        gets_s(s);//����һ���ַ��� 
        n = atoi(s);//�ַ���ת��Ϊ���� 
        if (n < 1 || n>4)//�ж������ѡ���Ƿ���ȷ 
            printf("�����������������: \n");
        else//������ȷ������ѭ�� 
            break;
    }
    return n;//��������ѡ�� 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ShowCart()
{//��ʾ�����б�
    struct node* p; //����ڵ�ָ�� 
    p = cart;//�ѹ��ﳵ������p 
    FILE* fp1;//�����ļ�ָ�� 
    if ((fp1 = fopen("cart.txt", "r")) == NULL)
    {//�ж��Ƿ�����ļ� 
        printf("���ļ�ʧ��\n");
        //return ;
    }

    if (p == NULL)
    {//���ﳵΪ�� 
        printf("Ŀǰ���ﳵΪ�գ�");
        return;
    }
    else
    {//���ﳵ��Ϊ�� 
        while (p != NULL)
        {//�ѹ��ﳵ��Ʒ���ϼ�һ��ֱ��Ϊ��
            printf("--------------------------------------------\n");
            printf("���       ����           ����    ����\n");
            printf("%-11s%-15s%-8.3f%-7d\n", p->buy.ID, p->buy.brand, p->buy.outprice, p->number);  //�����Ʒ��Ϣ 
            p = p->next;
        }
    }
    fclose(fp1);//�ر��ļ� 
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add()
{//�ڹ��ﳵ�������Ʒ 
    FILE* fp, * fp1;//fp��ʾkucun�ļ���fp1��ʾcart�ļ� 
    struct node* p1, * p, * p2;//����ڵ�ָ�� 
    int i, n;//n��ʾ��Ʒ���� 
    char s[20];//��ʾ���Ż���Ʒ�� 
    char choice1[20], choice2[20];//ѡ���y������n������ 


    do {
        printf("����������Ʒ�����ƻ���ţ�\n");
        fflush(stdin);//��������� 
        gets_s(s);//������Ż���Ʒ��   
        if ((fp = fopen("kucun.txt", "r")) == NULL)
        {//���ļ� 
            printf("���ļ�ʧ��\n");
            continue;
        }
        for (i = 0; i < N; i++)
        {//ѭ��N�� 
            fscanf(fp, "%s%s%*lf%lf%d", goods[i].ID, goods[i].brand, &goods[i].outprice, &goods[i].storage);//���ļ��ж�ȡ������Ϣ 

            if ((strcmp(goods[i].ID, s) == 0 || strcmp(goods[i].brand, s) == 0) && goods[i].storage > 0)//�������Ӧ����Ʒ 
            {
                printf("���ҵ�������Ʒ��\n");
                printf("--------------------------------------------\n");
                printf("����       Ʒ��           ����    ����\n");
                printf("%-11s%-15s%-8.3f%-7d\n", goods[i].ID, goods[i].brand, goods[i].outprice, goods[i].storage, goods[i].date);//���������Ʒ��Ϣ 

                printf("������������Ʒ����: ");
                scanf("%d", &n);//��Ʒ���� 
                if (n > goods[i].storage)
                {//�ж��Ƿ񻹿��Թ��� 
                    printf("����Ʒ��治��\n");
                    break;
                }
                printf("\n�Ƿ������Ʒ��(Y/N)\n");
                fflush(stdin);//��������� 
                scanf("%s", choice1);//����һ��ѡ�� 
                if (strcmp(choice1, "Y") == 0 || strcmp(choice1, "y") == 0)
                {//����y/Y��ʾ�������Ʒ 
                    p = (node *)malloc(sizeof(NODE));//�����½ڵ� 
                    if (p == NULL)
                    {//�����ڴ�ʧ�� 
                        printf("�ڴ�����ʧ�ܣ�\n");
                        exit(1);//�˳� 
                    }
                    p->number = n;//��Ʒ���� 
                    p->buy = goods[i];//������Ϣ 
                    p->next = NULL;
                    p1 = cart;//��ͷ��㸳��p1   
                    if (cart == NULL)//ͷ���Ϊ�� 
                        cart = p;//�ѽڵ㸳ֵ��ͷ��� 
                    else
                    {
                        while (p1->next != NULL)
                            p1 = p1->next;//������ѭ����β�� 
                        p->next = p1->next;
                        p1->next = p;//���½ڵ�p��������β�� 
                    }
                }
                else
                    printf("�������\n");
                break;//�ҵ���Ʒ����ѭ�� 
            }
        }
        if (i == N)//ѭ����ϻ�û�ҵ���Ӧ��Ʒ 
            printf("δ�ҵ�������Ʒ\n");
        fclose(fp);//�ر��ļ� 

        UpdateKu();//���¿����Ϣ���� 
        printf("�Ƿ��������?(Y/N)\n");
        fflush(stdin);//��������� 
        scanf("%s", choice2);//����ѡ��
        if (strcmp(choice2, "y") != 0 && strcmp(choice2, "Y") != 0)
            printf("�������򣬷��ز˵���\n");

    } while (strcmp(choice2, "y") == 0 || strcmp(choice2, "Y") == 0);//y/Y����ѭ�� 
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//���¹��ﳵ��Ϣ���� 
void UpdateKu()
{
    FILE* fp;
    struct node* p;
    if ((fp = fopen("cart.txt", "w")) == NULL)
    {//�ж��ļ��Ƿ񴴽�ʧ��
        printf("�����ļ�ʧ�ܡ�\n");
        return;
    }

    p = cart;//�ѹ��ﳵ������p2 
    while (p != NULL)
    {
        //  fprintf(fp1,"����       Ʒ��      ����    �����\n");
          //�ѻ�����Ϣд���ļ�
        fprintf(fp, "%-11s%-15s%-8.3f%-7d\n", p->buy.ID, p->buy.brand, p->buy.outprice, p->number);
        p = p->next;//ָ����һ���ڵ� 
    }
    fclose(fp);//�ر��ļ� 

    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calculate()
{//����������Ʒ�۸��޸ı���
    struct node* p;
    p = cart;//�ѹ��ﳵ(cart)������p 
    double sum = 0;//������ƷӦ��Ǯ�� 
    double pay;//������Ʒʵ��Ǯ�� 
    FILE* fp;//�����ļ�ָ�� 
    int i;
    printf("�����ǹ����嵥��\n");
    ShowCart();//���ú�����ʾ�����б���Ϣ 


    if ((fp = fopen("kucun.txt", "r")) == NULL)
    {//���ļ�  
        printf("���ļ�ʧ��\n");
        return;
    }

    for (i = 0; i < N; i++)
    {//���ļ��ж�ȡ��Ϣ 
        fscanf(fp, "%s%s%*lf%lf%d", goods[i].ID, goods[i].brand, &goods[i].outprice, &goods[i].storage);
    }
    fclose(fp);//�ر��ļ� 

    while (p != NULL)
    {//������Ϊ��ʱ 
        sum = sum + p->buy.outprice * p->number;//����Ӧ��Ǯ�� 
        for (i = 0; i < N; i++)
        {//�ҳ���Ӧ��Ʒ����� 
            if (strcmp(goods[i].ID, p->buy.ID) == 0)
            {//�ҵ���Ӧ��Ʒ 
                goods[i].storage = goods[i].storage - p->number;//������仯 
                break;
            }
        }
        p = p->next;//ָ����һ���ڵ� 
    }

    printf("�ܼƣ�%-8.3f\n", sum);//���������Ʒ�������Ǯ 
    printf("����ʵ����");
    scanf("%lf", &pay);
    printf("ʵ����  %-8.3f    ����:    %8.3f\n", pay, pay - sum);

    if ((fp = fopen("kucun.txt", "w")) == NULL)
    {//���ļ� 
        printf("д���ļ�ʧ��\n");
        return;
    }
    for (i = 0; i < N; i++)
    {//���ļ���д����Ϣ 
        fprintf(fp, "%-11s%-15s%-8.3f%-8.3f%-7d\n", goods[i].ID, goods[i].brand, goods[i].inprice, goods[i].outprice, goods[i].storage);
    }
    fclose(fp);//�ر��ļ� 

    return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{//������ 
    printf("*********************************************************\n");
    printf("                ��ӭ���볬����Ϣ����ϵͳ\n");

    int choose = 0;
    int flag = 1;
    while (1)
    {

        switch (menu1())
        {

        case 1:

            while (!login())
            {
                printf("��Ż������������������\n");
            }
            flag = 1;
            while (flag) {
                switch (menu2())
                {//menu()����Ϊ����ѡ��


                case 1:
                    CreateGoods();

                    break;//ѡ��1 �ֶ����������Ϣ

                case 2: ShowGoods();
                    break;//ѡ��2 ��ʾ�����Ϣ����

                case 3: flag = 0;
                    break;
                case 4: system("cls");
                    printf("��л����ʹ�ã��ټ���\n");
                    Sleep(2000);
                    exit(0);
                }
            }
            break;

        case 2:
            flag = 1;
            while (flag) {
                switch (menu3())
                {//menu()����Ϊ����ѡ��

                case 1: ShopCart();
                    break;//ѡ��4 �Թ��ﳵ���в���

                case 2: calculate();
                    break;//ѡ��5 ����������Ʒ�۸��޸ı��� 

                case 3: flag = 0;
                    break;
                case 4: system("cls");
                    printf("��л����ʹ�ã��ټ���\n");
                    Sleep(2000);
                    exit(0);
                }
            }
            break;//ѡ��2 �ֶ����������Ϣ



        case 3: system("cls");
            printf("��л����ʹ�ã��ټ���\n");
            Sleep(2000);
            exit(0);
        }
    }
    return 0;
}