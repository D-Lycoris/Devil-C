/*********************************************

Copyright (c), 17软件工程 赵靖巍，Co.,Ltd
FlieName: gzgl.c
Author:        Version:        Date:

Description:
1.int read(zggz t[])《读取职工工资数据函数》        //板块描述
2.int write(zggz t[])《保存职工工资数据函数》

Version:            //版本信息

Function List:      //主要函数功能
    1.
    2.
History:            //历史修改记录

    <author>    <time>    <version>    <desc>
	  xxx      2018/6/19     0.3       

***********************************************/

/***********************************************

Function:
Description:
Calls:
Called By:
Table Accessed:
Table Update:
Input:
Output:
Return:
Others:

***********************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct ZGGZ{						//工资结构体
	char zg_name[10];						//职工姓名
	char id[10];							//职工工号
	double Post_wage;						//岗位工资
	double Pay_salary;						//薪级工资
	double Post_allowance;					//职务津贴
	double Performance_salary;				//效绩工资
	double Deserved;						//应发工资
	double Individual_income_tax;			//个人所得税
	double payroll;							//实发工资
}zggz;

int count=0;


int read(zggz t[])				//《读取职工工资数据函数》
{
	zggz T;
	FILE *fp;											//文件指针
       if ((fp = fopen("gx.dat", "rb")) == NULL)
		{												//如果文件打开失败则退出
        puts("不能打开文件！");
        return 0;
		}												//如果文件打开成功则读取数据
		while (!feof(fp))       
		{              
			fscanf(fp, "%s\t", &T.zg_name);
			fscanf(fp, "%s\t", &T.id);              
			fscanf(fp, "%lf\t", &T.Post_wage);              
			fscanf(fp, "%lf\t", &T.Pay_salary);              
			fscanf(fp, "%lf\n", &T.Post_allowance);              
			fscanf(fp, "%lf\n", &T.Performance_salary);    
			fscanf(fp, "%lf\n", &T.Deserved); 
			fscanf(fp, "%lf\n", &T.Individual_income_tax);
			fscanf(fp, "%lf\n", &T.payroll);    
			t[count]=T;
			count++;
		}
		printf("共读取到%d个员工的信息\n\n",count);
		fclose(fp);
		return count;		
}


int write(zggz t[])								//《保存职工工资数据函数》
{
	int i;
	 if(count>0)
	 {
		FILE* fp1=fopen("gz.dat","w");
		if (fp1==NULL)
		{										//若打开文件失败则退出
            puts("打开文件失败！");
            return 0;
		}
		for(i=0;i<count;i++)
		{
			printf("\n");
		    fprintf(fp1, "%s\n", t[i].zg_name);
	        fprintf(fp1, "%s\t", t[i].id);              
	       	fprintf(fp1, "%lf\t", t[i].Post_wage);              
			fprintf(fp1, "%lf\t", t[i].Pay_salary);              
			fprintf(fp1, "%lf\n", t[i].Post_allowance);              
			fprintf(fp1, "%lf\n", t[i].Performance_salary);    
			fprintf(fp1, "%lf\n", t[i].Deserved); 
			fprintf(fp1, "%lf\n", t[i].Individual_income_tax);
			fprintf(fp1, "%lf\n", t[i].payroll);
		}	
		fclose(fp1);
	}else
	 {
		 printf("人数为零。");
	 }

    return 0;
}


int find(zggz t[])						//《查询职工工资数据函数》
{
	char gonghao[10];
	int flag=0;							//标记员工是否存在
	int j=0;							//记录员工存在的位置
	int i=0;							//记录员工存在的位置
	printf("\n请输入要查询的工号：");
	scanf("%s",gonghao);
	printf("%s",t[0].id);
	printf("%s",gonghao);

	//在结构体数组查找有无该编号的员工，如果有那么flag=1，否则flag=0
	for(i=0;i<count;i++)
	{
		
		if (*(t[i].id)==*(gonghao))
		{
			printf("%s",t[i].id);
			flag = 1;
			break;
		}
	}

 if (flag)				//如果存在该员工，那么输出该员工的信息
 {              
		printf("编号\t姓名\t性别\t职称\t年龄\t工资\n");              
		printf("%s\t", t[i].zg_name);
		printf("%d\t", t[i].id);              
		printf("%f\t", t[i].Post_wage);              
		printf("%f\t", t[i].Pay_salary);              
		printf("%f\t", t[i].Post_allowance);              
		printf("%f\t", t[i].Performance_salary);    
		printf("%f\t", t[i].Deserved); 
		printf("%f\t", t[i].Individual_income_tax);
		printf("%f\t", t[i].payroll);   

	 /*用j来标记员工位置，输出该员工的信息             
	 第二次寻找的起始位置从i+1开始*/
	 for (j = i+1; j<count; j++)
	 {                     
		 if (t[j].id == gonghao)
		 {                            
			printf("%s\t", t[j].zg_name);
			printf("%d\t", t[j].id);              
			printf("%f\t", t[j].Post_wage);              
			printf("%f\t", t[j].Pay_salary);              
			printf("%f\t", t[j].Post_allowance);              
			printf("%f\t", t[j].Performance_salary);    
			printf("%f\t", t[j].Deserved); 
			printf("%f\t", t[j].Individual_income_tax);
			printf("%f\t", t[j].payroll);
		 }
	 }
 } else{ printf("没有找到该编号的员工！\n"); }
     
	printf("\n");
	system("pause");
	return 0;
}


int list(zggz t[])					//《浏览职工工资数据函数》
{

	int j;
	int asd=count;
	if(asd=!0)
	{
		printf("%d",count);
		
		for(j=0;j<count;j++)
		{
			printf("编号\t姓名\t性别\t职称\t年龄\t工资\n");              
			printf("%s\t", t[j].zg_name);
			printf("%d\t", t[j].id);
			printf("%f\t", t[j].Post_wage);              
			printf("%f\t", t[j].Pay_salary);              
			printf("%f\t", t[j].Post_allowance);              
			printf("%f\t", t[j].Performance_salary);    
			printf("%f\t", t[j].Deserved); 
			printf("%f\t", t[j].Individual_income_tax);
			printf("%f\t", t[j].payroll);
			printf("\n");
		}
	}else{ printf("没有该员工。\n");  }
	return 0;
}


int modify(zggz t[])							//《修改职工工资数据函数》
{
	double Post_wage, Pay_salary, Post_allowance, Performance_salary, Deserved, Individual_income_tax,payroll;
	char gonghao[10];
	int flag=0;									//标记员工是否存在
	int j=0;									//记录员工存在的位置
	int i=0;									//记录员工存在的位置
	printf("请输入要查询的工号");
	scanf("%s",gonghao);
	for(i=0;i<count;i++)
	{
		if (*(t[i].id)==*(gonghao))
		{
			flag = 1;
			break;
		}
	}

 if (flag)
 {              
		printf("编号\t姓名\t性别\t职称\t年龄\t工资\n");              
		printf("%s\t", t[i].zg_name);
		printf("%d\t", t[i].id);              
		printf("%f\t", t[i].Post_wage);              
		printf("%f\t", t[i].Pay_salary);              
		printf("%f\t", t[i].Post_allowance);              
		printf("%f\t", t[i].Performance_salary);    
		printf("%f\t", t[i].Deserved); 
		printf("%f\t", t[i].Individual_income_tax);
		printf("%f\t", t[i].payroll);     

	 /*用j来标记员工的位置  然后输出该员工的信息             
	 第二次寻找的起始位置从i+1开始*/
	 for (j=i+1; j<count; j++)
	 {                     
		 if (t[j].id == gonghao)
		 {     
			 printf("\n请输入修改Post_wage");
			 scanf("%d",&Post_wage);
				 t[j].Post_wage=Post_wage;

			 printf("\n请输入修改Pay_salary");
			 			 scanf("%d",&Pay_salary);
				 t[j].Pay_salary=Pay_salary;

			 printf("\n请输入修改Post_allowance");
			 			 scanf("%d",&Post_allowance);
				 t[j].Post_allowance=Post_allowance;

			 printf("\n请输入修改Performance_salary");
			 			 scanf("%d",&Performance_salary);
				 t[j].Performance_salary=Performance_salary;

		     printf("\n请输入修改Deserved");
			 	scanf("%d",&Deserved);
				 t[j].Deserved=Deserved;
		 }
	 }
 } else{ printf("没有找到此编号员工。\n"); }
	return 0;
}


int del()							//《删除职工工资数据函数》
{
	return 0;
}


int add()							//《添加职工工资数据函数》
{
	return 0;
}


void add_money(zggz S[])		//计算应发工资       
{
	int i;
	for(i=0;i<count;i++)
		S[i].Deserved=S[i].Post_wage+S[i].Pay_salary+S[i].Post_allowance+S[i].Performance_salary;
}

void grsds(zggz S[])			//《计算个人所得税函数》
{
	int i;
	for(i=0;i<count;i++)
	{
		if(S[i].Deserved<500)																									//不超过500元的所得税（5%）
			S[i].Individual_income_tax=S[i].Deserved*0.05;

		else if(S[i].Deserved<2000)																								//超过500元到2000元的部分的所得税（10%）
			S[i].Individual_income_tax=(S[i].Deserved-2000)*0.1+500*0.05;
		
		else if(S[i].Deserved<5000)																								//超过2000元到5000元的部分的所得税（15%）
			S[i].Individual_income_tax=(S[i].Deserved-5000)*0.15+1500*0.1+500*0.05;
		
		else if(S[i].Deserved<20000)																							//超过5000元到20000元的部分的所得税（20%）
			S[i].Individual_income_tax=(S[i].Deserved-20000)*0.2+15000*0.15+1500*0.1+500*0.05;
		
		else if(S[i].Deserved<40000)																							//超过20000元到40000元的部分的所得税（25%）
			S[i].Individual_income_tax=(S[i].Deserved-40000)*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		
		else if(S[i].Deserved<60000)																							//超过40000元到60000元的部分的所得税（30%）
			S[i].Individual_income_tax=(S[i].Deserved-60000)*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;

		else if(S[i].Deserved<80000)																							//超过60000元到80000元的部分的所得税（35%）
			S[i].Individual_income_tax=(S[i].Deserved-80000)*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		
		else if(S[i].Deserved<100000)																							//超过80000元到100000元的部分的所得税（40%）
			S[i].Individual_income_tax=(S[i].Deserved-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		
		else																													//超过100000元的部分的所得税（45%）
			S[i].Individual_income_tax=(S[i].Deserved-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;		
	}
}

void add_wages(zggz S[])	//计算实发工资	       
{
	int i;
	for(i=0;i<count;i++)
		S[i].payroll=S[i].Deserved-S[i].Individual_income_tax;
}


int main()							//《菜单》
{
	zggz z[50];
	int menu();
	count=read(z);
	add_money(z);
	grsds(z);
	add_wages(z);

    do{ 
        switch(menu()){
            case 1:
                find(z);			//查询职工工资函数
                break;
            case 2:
                modify(z);			//修改职工工资函数
                break;
            case 3:
                add();				//添加职工工资函数
                break;
            case 4:
                del();				//删除职工工资函数
                break;
            case 5:
                write(z);			//保存职工工资函数
                break;
            case 6:
                list(z);			//浏览职工工资函数
				break;
            case 7:
                goto exit;
        }
    }while(1);
    exit:
    return 0;
}

int menu()
{
   int option=0;
    char i=0;
    printf("****************职工工资管理系统**************\n\n");
    printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
    printf("         1. 查 询 职 工 工 资 数 据\n");
    printf("         2. 修 改 职 工 工 资 数 据\n");
    printf("         3. 添 加 职 工 工 资 数 据\n");
    printf("         4. 删 除 职 工 工 资 数 据\n");
    printf("         5. 保 存 职 工 工 资 数 据\n");
    printf("         6. 浏 览 职 工 工 资 数 据\n");
	printf("         7.       退 出 系 统\n");
    printf("★★★★★★★★★★★★★★★★★★★★★★★\n\n");
	printf("请输入需要执行命令的数字编号(1-7):\n");
    scanf("%c",&i);
    option=(int)(i-'0');
    while(option<1||option>7){
        printf("输入错误，请重新输入:\n");
        scanf("%d",&option);
    }
    return option;
}

