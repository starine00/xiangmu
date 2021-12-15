
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define N 100 
//using namespace std;

struct mar//该结构体为存储货物信息 
{
    char ID[10];//货号 
    char brand[20];//品名
    double inprice;//进价 
    double outprice;//售价
    int storage;//存储量 
    char date[11];//保质期 
};

struct node//该结构体为存储购物车中的信息 
{
    struct mar buy;//货物信息 
    int number;//购物的数量 
    struct node* next; //指向下一个购物节点 
}NODE;
struct mar goods[N];//结构体数组 
struct node* cart;//购物车头结点 

int menu1();//打印主菜单函数 
int menu2();//打印管理员菜单函数 
int menu3();//打印顾客函数 
void CreateGoods();//录入商品信息函数 
void ShowGoods();//显示库存信息函数
void ShopCart();//对购物车进行操作
int ShopCartMenu();//打印购物车菜单
void ShowCart();//显示购物列表
void add();//在购物车里添加商品 
void UpdateKu();//更新购物车信息函数 
void  calculate();//计算所购商品价格并修改保存 

//#endif



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int login() {
    //管理员登入 
    int username = 10001;
    int password = 1234;
    int scuser;
    int scpass;
    printf("请输入管理员编号 \n");
    scanf("%d", &scuser);//输入管理员编号 
    printf("请输入管理员密码 \n");
    scanf("%d", &scpass);//输入管理员密码 
    if (username == scuser && password == scpass)
        return 1;
    else
        return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu1()
{//打印主菜单函数
    char s[5];//输入的选项 
    int n;//选项为整数 
    printf("\n\n请选择下面的数字表明你的身份：\n");
    printf("1. 管理员\n");
    printf("2. 顾客\n");
    printf("3. 退出系统\n");
    printf("*********************************************************\n");
    printf("--------------------------------------------\n");
    printf("请选择对应数字1~3\n");


    while (1)
    {
        fflush(stdin);//清空输入流
        gets_s(s);//输入一串字符串 
        n = atoi(s);//字符串转化为整数 
        if (n < 1 || n>3)//判断输入的选项是否正确
            printf("输入错误，请重新输入：\n");
        else//输入正确，结束循环 
            break;
    }
    return n;//返回输入选项 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu2()
{//打印主菜单函数
    char s[5];//输入的选项 
    int n;//选项为整数 
    printf("\n\n请选择下面的数字进行操作：\n");
    printf("--------------------------------------------\n");
    printf("1. 录入商品信息\n");
    printf("2. 显示所有商品信息\n");
    printf("3. 返回上一层\n");
    printf("4. 退出程序\n");
    printf("--------------------------------------------\n");
    printf("请选择对应数字1~4\n");


    while (1)
    {
        fflush(stdin);//清空输入流
        gets_s(s);//输入一串字符串 
        n = atoi(s);//字符串转化为整数 
        if (n < 1 || n>4)//判断输入的选项是否正确
            printf("输入错误，请重新输入：\n");
        else//输入正确，结束循环 
            break;
    }
    return n;//返回输入选项 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu3()
{//打印主菜单函数
    char s[5];//输入的选项 
    int n;//选项为整数 
    printf("\n\n请选择下面的数字进行操作：\n");
    printf("--------------------------------------------\n");
    printf("1. 购物车\n");
    printf("2. 结算\n");
    printf("3. 返回上一层\n");
    printf("4. 退出程序\n");
    printf("--------------------------------------------\n");
    printf("请选择对应数字1~4\n");


    while (1)
    {
        fflush(stdin);//清空输入流
        gets_s(s);//输入一串字符串 
        n = atoi(s);//字符串转化为整数 


        if (n < 1 || n>4)//判断输入的选项是否正确
            printf("输入错误，请重新输入：\n");
        else//输入正确，结束循环 
            break;
    }
    return n;//返回输入选项 
}


int n = 0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CreateGoods()
{//手动建立库存信息
    FILE* fp;//定义文件指针 
    int i;
    printf("请输入需要录入的商品个数：\n");
    scanf("%d", &n);//输入数量 
    printf("请依次输入货物信息：\n");
    printf("--------------------------------------------\n");
    for (i = 0; i < n; i++)
    {//向文件中写入信息
        printf("第%d个商品：\n", i + 1);
        printf("货号：");
        fflush(stdin);//清空输入流
        gets_s(goods[i].ID);//输入货号

        printf("品名：");
        fflush(stdin);//清空输入流
        gets_s(goods[i].brand);//输入品名 

        printf("进价: ");
        fflush(stdin);//清空输入流
        scanf("%lf", &goods[i].inprice);//输入进价 

        printf("售价：");
        fflush(stdin);//清空输入流
        scanf("%lf", &goods[i].outprice);//输入售价 

        printf("数量：");
        fflush(stdin);//清空输入流
        scanf("%d", &goods[i].storage);//输入数量 


        printf("保质期：");
        fflush(stdin);//清空输入流
        gets_s(goods[i].date);//输入货号
        printf("\n");
    }
    if ((fp = fopen("kucun.txt", "w")) == NULL)
    {//判断文件是否创建失败
        printf("创建文件失败。\n");
        return;
    }
    //fprintf(fp,"货号       品名      单价    库存量   保质期\n");
    for (i = 0; i < n; i++)
    {//把货物信息写进文件
        fprintf(fp, "%-11s%-15s%-8.3f%-8.3f%-11d%-11s\n", goods[i].ID, goods[i].brand, goods[i].inprice, goods[i].outprice, goods[i].storage, goods[i].date);
    }
    //fwrite(goods,sizeof(struct mar),N,cun);二进制文件输出 
    fclose(fp);//关闭文件 
    printf("信息导入成功\n");
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ShowGoods()
{//显示库存信息函数
    FILE* fp;//定义文件指针 
    int i;
    if ((fp = fopen("kucun.txt", "r")) == NULL)
    {//判断是否打开了文件
        printf("打开文件失败\n");
        return;
    }

    for (i = 0; i < n; i++)
    {//输出物品信息
      //读取文件信息 
        fscanf(fp, "%s%s%lf%lf%d%s", goods[i].ID, goods[i].brand, &goods[i].inprice, &goods[i].outprice, &goods[i].storage, goods[i].date);
        printf("--------------------------------------------\n");
        //输出文件信息 
        printf("编号       名称           单价    库存量     保质期\n");
        printf("%-11s%-15s%-8.3f%-11d%-11s\n", goods[i].ID, goods[i].brand, goods[i].outprice, goods[i].storage, goods[i].date);
    }
    fclose(fp);//关闭文件 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void  ShopCart()
{//对购物车进行操作
    while (1)
    {
        switch (ShopCartMenu())
        {//ShopCartMenu()为输入选项
        case 1: ShowGoods();
            break;//选项1 显示购物车物品信息
        case 2: add();
            break;//选项2 添加购物车物品
        case 3: ShowCart();
        case 4: return;//选项3 退出 

        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ShopCartMenu()
{//打印购物车菜单
    int n;//为整数 
    char s[5];//输入一串字符串 
    printf("\n\n请选择操作：\n");
    printf("--------------------------------------------\n");
    printf("1. 显示商品列表\n");
    printf("2. 在购物车里添加商品\n");
    printf("3. 显示购物车商品\n");
    printf("4. 退出\n");
    printf("--------------------------------------------\n");
    printf("请选择对应数字1~4\n");


    while (1)
    {
        fflush(stdin);//清空输入流
        gets_s(s);//输入一串字符串 
        n = atoi(s);//字符串转化为整数 
        if (n < 1 || n>4)//判断输入的选项是否正确 
            printf("输入错误，请重新输入: \n");
        else//输入正确，结束循环 
            break;
    }
    return n;//返回输入选项 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ShowCart()
{//显示购物列表
    struct node* p; //定义节点指针 
    p = cart;//把购物车链表赋给p 
    FILE* fp1;//定义文件指针 
    if ((fp1 = fopen("cart.txt", "r")) == NULL)
    {//判断是否打开了文件 
        printf("打开文件失败\n");
        //return ;
    }

    if (p == NULL)
    {//购物车为空 
        printf("目前购物车为空：");
        return;
    }
    else
    {//购物车不为空 
        while (p != NULL)
        {//把购物车物品不断减一，直到为空
            printf("--------------------------------------------\n");
            printf("编号       名称           单价    数量\n");
            printf("%-11s%-15s%-8.3f%-7d\n", p->buy.ID, p->buy.brand, p->buy.outprice, p->number);  //输出物品信息 
            p = p->next;
        }
    }
    fclose(fp1);//关闭文件 
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add()
{//在购物车里添加商品 
    FILE* fp, * fp1;//fp表示kucun文件，fp1表示cart文件 
    struct node* p1, * p, * p2;//定义节点指针 
    int i, n;//n表示商品数量 
    char s[20];//表示货号或者品名 
    char choice1[20], choice2[20];//选择项（y继续，n继续） 


    do {
        printf("输入所需物品的名称或货号：\n");
        fflush(stdin);//清空输入流 
        gets_s(s);//输入货号或者品名   
        if ((fp = fopen("kucun.txt", "r")) == NULL)
        {//打开文件 
            printf("打开文件失败\n");
            continue;
        }
        for (i = 0; i < N; i++)
        {//循环N次 
            fscanf(fp, "%s%s%*lf%lf%d", goods[i].ID, goods[i].brand, &goods[i].outprice, &goods[i].storage);//从文件中读取货物信息 

            if ((strcmp(goods[i].ID, s) == 0 || strcmp(goods[i].brand, s) == 0) && goods[i].storage > 0)//找输入对应的商品 
            {
                printf("已找到所需商品：\n");
                printf("--------------------------------------------\n");
                printf("货号       品名           单价    数量\n");
                printf("%-11s%-15s%-8.3f%-7d\n", goods[i].ID, goods[i].brand, goods[i].outprice, goods[i].storage, goods[i].date);//输出所需物品信息 

                printf("请输入所需商品数量: ");
                scanf("%d", &n);//商品数量 
                if (n > goods[i].storage)
                {//判断是否还可以购买不 
                    printf("该商品库存不足\n");
                    break;
                }
                printf("\n是否购买此商品？(Y/N)\n");
                fflush(stdin);//清空输入流 
                scanf("%s", choice1);//输入一个选项 
                if (strcmp(choice1, "Y") == 0 || strcmp(choice1, "y") == 0)
                {//输入y/Y表示购买此商品 
                    p = (node *)malloc(sizeof(NODE));//生成新节点 
                    if (p == NULL)
                    {//分配内存失败 
                        printf("内存申请失败！\n");
                        exit(1);//退出 
                    }
                    p->number = n;//商品数量 
                    p->buy = goods[i];//货物信息 
                    p->next = NULL;
                    p1 = cart;//把头结点赋给p1   
                    if (cart == NULL)//头结点为空 
                        cart = p;//把节点赋值给头结点 
                    else
                    {
                        while (p1->next != NULL)
                            p1 = p1->next;//把链表循环到尾部 
                        p->next = p1->next;
                        p1->next = p;//把新节点p挂在链表尾部 
                    }
                }
                else
                    printf("输入错误\n");
                break;//找到商品结束循环 
            }
        }
        if (i == N)//循环完毕还没找到对应商品 
            printf("未找到所需物品\n");
        fclose(fp);//关闭文件 

        UpdateKu();//更新库存信息函数 
        printf("是否继续购物?(Y/N)\n");
        fflush(stdin);//清空输入流 
        scanf("%s", choice2);//输入选项
        if (strcmp(choice2, "y") != 0 && strcmp(choice2, "Y") != 0)
            printf("放弃购买，返回菜单！\n");

    } while (strcmp(choice2, "y") == 0 || strcmp(choice2, "Y") == 0);//y/Y继续循环 
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//更新购物车信息函数 
void UpdateKu()
{
    FILE* fp;
    struct node* p;
    if ((fp = fopen("cart.txt", "w")) == NULL)
    {//判断文件是否创建失败
        printf("创建文件失败。\n");
        return;
    }

    p = cart;//把购物车链表赋给p2 
    while (p != NULL)
    {
        //  fprintf(fp1,"货号       品名      单价    库存量\n");
          //把货物信息写进文件
        fprintf(fp, "%-11s%-15s%-8.3f%-7d\n", p->buy.ID, p->buy.brand, p->buy.outprice, p->number);
        p = p->next;//指向下一个节点 
    }
    fclose(fp);//关闭文件 

    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calculate()
{//计算所购商品价格并修改保存
    struct node* p;
    p = cart;//把购物车(cart)链表赋给p 
    double sum = 0;//购买商品应付钱数 
    double pay;//购买商品实付钱数 
    FILE* fp;//定义文件指针 
    int i;
    printf("以下是购物清单：\n");
    ShowCart();//调用函数显示购物列表信息 


    if ((fp = fopen("kucun.txt", "r")) == NULL)
    {//打开文件  
        printf("打开文件失败\n");
        return;
    }

    for (i = 0; i < N; i++)
    {//从文件中读取信息 
        fscanf(fp, "%s%s%*lf%lf%d", goods[i].ID, goods[i].brand, &goods[i].outprice, &goods[i].storage);
    }
    fclose(fp);//关闭文件 

    while (p != NULL)
    {//当链表不为空时 
        sum = sum + p->buy.outprice * p->number;//计算应付钱数 
        for (i = 0; i < N; i++)
        {//找出对应商品库存量 
            if (strcmp(goods[i].ID, p->buy.ID) == 0)
            {//找到对应商品 
                goods[i].storage = goods[i].storage - p->number;//库存量变化 
                break;
            }
        }
        p = p->next;//指向下一个节点 
    }

    printf("总计：%-8.3f\n", sum);//输出购买物品共需多少钱 
    printf("输入实付金额：");
    scanf("%lf", &pay);
    printf("实付：  %-8.3f    找零:    %8.3f\n", pay, pay - sum);

    if ((fp = fopen("kucun.txt", "w")) == NULL)
    {//打开文件 
        printf("写入文件失败\n");
        return;
    }
    for (i = 0; i < N; i++)
    {//向文件中写入信息 
        fprintf(fp, "%-11s%-15s%-8.3f%-8.3f%-7d\n", goods[i].ID, goods[i].brand, goods[i].inprice, goods[i].outprice, goods[i].storage);
    }
    fclose(fp);//关闭文件 

    return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{//主函数 
    printf("*********************************************************\n");
    printf("                欢迎进入超市信息管理系统\n");

    int choose = 0;
    int flag = 1;
    while (1)
    {

        switch (menu1())
        {

        case 1:

            while (!login())
            {
                printf("编号或密码错误请重新输入\n");
            }
            flag = 1;
            while (flag) {
                switch (menu2())
                {//menu()函数为输入选项


                case 1:
                    CreateGoods();

                    break;//选项1 手动建立库存信息

                case 2: ShowGoods();
                    break;//选项2 显示库存信息函数

                case 3: flag = 0;
                    break;
                case 4: system("cls");
                    printf("感谢您的使用，再见！\n");
                    Sleep(2000);
                    exit(0);
                }
            }
            break;

        case 2:
            flag = 1;
            while (flag) {
                switch (menu3())
                {//menu()函数为输入选项

                case 1: ShopCart();
                    break;//选项4 对购物车进行操作

                case 2: calculate();
                    break;//选项5 计算所购商品价格并修改保存 

                case 3: flag = 0;
                    break;
                case 4: system("cls");
                    printf("感谢您的使用，再见！\n");
                    Sleep(2000);
                    exit(0);
                }
            }
            break;//选项2 手动建立库存信息



        case 3: system("cls");
            printf("感谢您的使用，再见！\n");
            Sleep(2000);
            exit(0);
        }
    }
    return 0;
}