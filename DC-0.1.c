/*********************************************

Copyright (c), 17软件工程 赵靖巍，Co.,Ltd
FlieName: gzgl.c
Author:        Version:        Date:
Description:        //板块描述
Version:            //版本信息
Function List:      //主要函数功能
    1.
    2.
History:            //历史修改记录

    <author>    <time>    <version>    <desc>
	  xxx      2018/6/19     0.1         

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

typedef struct ZGGZ
{
	char wo_name[10];			//职工工号
	char id[10];				//职工姓名
	double position_value, Pay_salary;				//工资、薪金
	double duty_allowance, merit_pay, gross_pay, Personal_income_tax, payroll;		//津贴、绩效、应发、个人所得税和实发工资
}zggz;			//工资结构

int count=0;

int read(zggz t[])			//读取职工工资数据函数
{
	zggz T;
	FILE *fp;											//文件指针
       if ((fp = fopen("gz.dat", "rb")) == NULL)
		{												//若打开文件失败则退出
        puts("打开文件失败！");
        return 0;
		}												//如果文件打开成功，则读取数据 
		while (!feof(fp))       
		{              
			fscanf(fp, "%s\t", &T.wo_name);
			fscanf(fp, "%d\t", &T.id);              
			fscanf(fp, "%f\t", &T.position_value);              
			fscanf(fp, "%f\t", &T.Pay_salary);              
			fscanf(fp, "%f\n", &T.duty_allowance);              
			fscanf(fp, "%f\n", &T.merit_pay);    
			fscanf(fp, "%f\n", &T.gross_pay); 
			fscanf(fp, "%f\n", &T.Personal_income_tax);
			fscanf(fp, "%f\n", &T.payroll);    
			t[count]=T;
			count++;       }
			printf("\n有%d个员工信息被读入\n",count);

			fclose(fp);
			return count;		
}


int write(zggz t[])							//保存职工工资数据函数
{
	int i;
	zggz z;
	 if(count>0)
	 {
		FILE* fp1=fopen("gx.dat","w");
		if (fp1==NULL)
		{									//若打开文件失败则退出
        puts("打开文件失败！");
        return 0;
		}

		for(i=0;i<count;i++)
			{
		fprintf(fp1, "%s\t", z.wo_name);
		fprintf(fp1, "%d\t", z.id);              
		fprintf(fp1, "%f\t", z.position_value);              
		fprintf(fp1, "%f\t", z.Pay_salary);              
		fprintf(fp1, "%f\n", z.duty_allowance);              
		fprintf(fp1, "%f\n", z.merit_pay);    
		fprintf(fp1, "%f\n", z.gross_pay); 
		fprintf(fp1, "%f\n", z.Personal_income_tax);
		fprintf(fp1, "%f\n", z.payroll);
			}
		}else
	 {
		 printf("人数为零。");
	 }
    return 0;
}


int find(zggz t[])				//查询职工工资数据函数
{
	char gonghao[10];
	int flag=0;					//标记员工有没有存在
	int j=0;					//记录员工存在的位置
	int i=0;					//记录员工存在的位置
	printf("\n请输入要查询的工号");
	scanf("%s",gonghao);

	//在结构体数组查找有无该编号的员工，如果有那么flag=1，否则flag=0
	for(i=0;i<count;i++)
	{
		if (t[i].id==gonghao)
		{
			flag = 1;
			break;
		}
	}
 if (flag)					//如果存在该员工，那么输出该员工的信息
 {              
		printf("编号\t姓名\t性别\t职称\t年龄\t工资\n");              
		printf("%s\t", t[i].wo_name);
		printf("%d\t", t[i].id);              
		printf("%f\t", t[i].position_value);              
		printf("%f\t", t[i].Pay_salary);              
		printf("%f\t", t[i].duty_allowance);              
		printf("%f\t", t[i].merit_pay);    
		printf("%f\t", t[i].gross_pay); 
		printf("%f\t", t[i].Personal_income_tax);
		printf("%f\t", t[i].payroll);
		
	 /*用j来标记员工的位置，然后输出该员工的信息,
	 第二次寻找的起始位置应该从i+1开始*/
	 for (j = i+1; j<count; j++)
	 {                     
		 if (t[j].id == gonghao)
		 {                            
		printf("%s\t", t[j].wo_name);
		printf("%d\t", t[j].id);              
		printf("%f\t", t[j].position_value);              
		printf("%f\t", t[j].Pay_salary);              
		printf("%f\t", t[j].duty_allowance);              
		printf("%f\t", t[j].merit_pay);    
		printf("%f\t", t[j].gross_pay); 
		printf("%f\t", t[j].Personal_income_tax);
		printf("%f\t", t[j].payroll);
		 }
	 }
 } else{ printf("没有找到该编号员工.\n"); }
     
 printf("\n");
 system("pause");
 return 0;
}


int list(zggz t[])				//浏览职工工资数据函数
{
	int j;
	if(count=!0)
	{
		for(j=0;j<count;j++)
		{
		printf("编号\t姓名\t性别\t职称\t年龄\t工资\n");              
		printf("%s\t", t[j].wo_name);
		printf("%d\t", t[j].id);              
		printf("%f\t", t[j].position_value);              
		printf("%f\t", t[j].Pay_salary);              
		printf("%f\t", t[j].duty_allowance);              
		printf("%f\t", t[j].merit_pay);    
		printf("%f\t", t[j].gross_pay); 
		printf("%f\t", t[j].Personal_income_tax);
		printf("%f\t", t[j].payroll);
		}
	}else{ printf("没有员工！\n");  }
	return 0;
}

int modify(zggz t[])				//修改职工工资数据函数
{
	double position_value, Pay_salary, duty_allowance, merit_pay, gross_pay, Personal_income_tax,payroll;
	char gonghao[10];
	int flag=0;						//标记员工有没有存在
	int j=0;						//记录员工存在的位置
	int i=0;						//记录员工存在的位置
	printf("请输入要查询的工号");
	scanf("%s",gonghao);
	for(i=0;i<count;i++)
	{
		if (t[i].id==gonghao)
		{
			flag = 1;
			break;
		}
	}

 if (flag)
 {              
		printf("编号\t姓名\t性别\t职称\t年龄\t工资\n");              
		printf("%s\t", t[i].wo_name);
		printf("%d\t", t[i].id);              
		printf("%f\t", t[i].position_value);              
		printf("%f\t", t[i].Pay_salary);              
		printf("%f\t", t[i].duty_allowance);              
		printf("%f\t", t[i].merit_pay);    
		printf("%f\t", t[i].gross_pay); 
		printf("%f\t", t[i].Personal_income_tax);
		printf("%f\t", t[i].payroll);     
	 /*由于员工数组中有多个编号一样的员工，所以需要继续寻找，用j来标记员工的位置  然后输出该员工的信息             
	 第二次寻找的起始位置应该从i+1开始 因为之前的已经找过了*/
	 for (j=i+1; j<count; j++)
	 {                     
		 if (t[j].id == gonghao)
		 {     
			 printf("\n请输入修改position_value");
			 scanf("%d",&position_value);
				 t[j].position_value=position_value;

			 printf("\n请输入修改Pay_salary");
			 			 scanf("%d",&Pay_salary);
				 t[j].Pay_salary=Pay_salary;

			 printf("\n请输入修改duty_allowance");
			 			 scanf("%d",&duty_allowance);
				 t[j].duty_allowance=duty_allowance;

			 printf("\n请输入修改merit_pay");
			 			 scanf("%d",&merit_pay);
				 t[j].merit_pay=merit_pay;

		     printf("\n请输入修改gross_pay");
			 	scanf("%d",&gross_pay);
				 t[j].gross_pay=gross_pay;
		 }
	 }
 } else{ printf("没有找到此编号员工。\n"); }
	return 0;
}

void add_money(zggz S[])		//计算应发工资       
{
	int i;
	for(i=0;i<count;i++)
		S[i].gross_pay=S[i].position_value+S[i].Pay_salary+S[i].duty_allowance+S[i].merit_pay;
}


void grsds(zggz S[])			//计算个人所得税       
{
	int i;
	for(i=0;i<count;i++)
	{
		if(S[i].gross_pay<500)																									//不超过500元的所得税（5%）
			S[i].Personal_income_tax=S[i].gross_pay*0.05;
		else if(S[i].gross_pay<2000)																							//超过500元到2000元的部分的所得税（10%）
			S[i].Personal_income_tax=(S[i].gross_pay-2000)*0.1+500*0.05;	
		else if(S[i].gross_pay<5000)																							//超过2000元到5000元的部分的所得税（15%）
			S[i].Personal_income_tax=(S[i].gross_pay-5000)*0.15+1500*0.1+500*0.05;														     			
		else if(S[i].gross_pay<20000)																							//超过5000元到20000元的部分的所得税（20%）
			S[i].Personal_income_tax=(S[i].gross_pay-20000)*0.2+15000*0.15+1500*0.1+500*0.05;														    
		else if(S[i].gross_pay<40000)																							//超过20000元到40000元的部分的所得税（25%）
			S[i].Personal_income_tax=(S[i].gross_pay-40000)*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;											     
		else if(S[i].gross_pay<60000)																							//超过40000元到60000元的部分的所得税（30%）
			S[i].Personal_income_tax=(S[i].gross_pay-60000)*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;								     		
		else if(S[i].gross_pay<80000)																							//超过60000元到80000元的部分的所得税（35%）
			S[i].Personal_income_tax=(S[i].gross_pay-80000)*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;		     				
		else if(S[i].gross_pay<100000)																							//超过80000元到100000元的部分的所得税（40%）
			S[i].Personal_income_tax=(S[i].gross_pay-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;				
		else																													//超过100000元的部分的所得税（45%）
			S[i].Personal_income_tax=(S[i].gross_pay-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;		
	}
}

int main()
{
	zggz z[100];
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

int menu()                                                //菜单
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
	printf("请输入需要执行命令的数字编号(1-7):");
    scanf("%c",&i);
    option=(int)(i-'0');

    while(option<1||option>7){
        printf("Input Error!\nPlease retype:\n");
        scanf("%d",&option);
    }
    return option;
}

