/*********************************************

Copyright (c), 17软件工程 赵靖巍，Co.,Ltd
FlieName: gzgl.c
Author:赵靖巍        Version:1.3        Date:2018/6/25

Description:
本系统的设计目标是实现职工工资记录的录入、查询、修改、添加、删除及数据保存功能。
根据现有工资系统的实际情况确定职工工资记录由职工工号、职工姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税和实发工资9个项目构成。
系统应实现工资记录的逐条添加、保存、根据工号进行查询、浏览、删除，并能在添加修改的同时自动完成个人所得税和应发工资的计算。

Version:1.3

Function List:
	1.int read(zggz t[])			《读取职工工资数据函数》
	2.int write(zggz t[])			《保存职工工资数据函数》
	3.int find(zggz t[])			《查询职工工资数据函数》
	4.int list(zggz t[])			《浏览职工工资数据函数》
	5.void grsds(zggz S[])			《计算个人所得税函数》 
	6. int modify(zggz t[])			《修改职工工资数据函数》
	7.int del(zggz t[])				《删除职工工资数据函数》
	8.int add(zggz t[])				《添加职工工资数据函数》
	9.int main						菜单
	10.int menu						菜单显示
	11.void all_money(zggz S[])		计算应发工资
	12.void Des_money(zggz S[])		计算实发工资

History:            //历史修改记录

    <author>    <time>    <version>    <desc>
	 赵靖巍    2018/6/19     1.3       

***********************************************/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct ZGGZ{					//工资结构体
	char zg_name[10];					//职工姓名
	char id[10];						//职工工号
	double Post_wage;					//岗位工资
	double Pay_salary;					//薪级工资
	double Post_allowance;				//职务津贴
	double Performance_salary;			//绩效工资
	double Deserved;					//应发工资
	double Individual_income_tax;		//个人所得税
	double payroll;						//实发工资
}zggz;

int count=0;





/***********************************************

Function: read
Description: 读取职工工资信息
Calls: all_money、grsds、Des_money
Called By: menu
Table Accessed:	gx.dat
Table Update: gx.dat、gz.dat

***********************************************/

int read(zggz t[])			//《读取职工工资数据函数》
{
	zggz T;
	FILE *fp;				//文件指针
    if ((fp = fopen("gx.dat", "rb")) == NULL)			//如果文件打开失败则退出
	{
		puts("打开文件失败！");
        return 0;
	}
	while (!feof(fp))				//如果文件打开成功，那么进行读数据   
	{              
		fscanf(fp, "%s ", &T.zg_name);
		fscanf(fp, "%s ", &T.id);              
		fscanf(fp, "%lf ", &T.Post_wage);              
		fscanf(fp, "%lf ", &T.Pay_salary);              
		fscanf(fp, "%lf\n", &T.Post_allowance);              
		fscanf(fp, "%lf\n", &T.Performance_salary);    
		fscanf(fp, "%lf\n", &T.Deserved); 
		fscanf(fp, "%lf\n", &T.Individual_income_tax);
		fscanf(fp, "%lf\n", &T.payroll);    
		t[count]=T;
		count++;       
	}
		
	printf("\t\t\t\t\t(共读取到%d个员工的信息)\n\n",count);
	fclose(fp);
	return count;		
}




/***********************************************

Function: write
Description: 保存一份新的工资数据到文件gz.dat中。
Called By: menu、write
Table Accessed: gz.dat
Table Update: gz.dat

***********************************************/

int write(zggz t[])				//《保存职工工资数据函数》
{
	int i;
	if(count>0) 
	{
		FILE* fp1=fopen("gz.dat","w");
		if (fp1==NULL)				//如果文件打开失败则退出
		{
            puts("打开文件失败！");
            return 0;
		}

		for(i=0;i<count;i++)
		{
			printf("\n");
		    fprintf(fp1, "%s\n", t[i].zg_name);
	        fprintf(fp1, "%s\n", t[i].id);              
	       	fprintf(fp1, "%lf\n", t[i].Post_wage);              
			fprintf(fp1, "%lf\n", t[i].Pay_salary);              
			fprintf(fp1, "%lf\n", t[i].Post_allowance);              
			fprintf(fp1, "%lf\n", t[i].Performance_salary);    
			fprintf(fp1, "%lf\n", t[i].Deserved); 
			fprintf(fp1, "%lf\n", t[i].Individual_income_tax);
			fprintf(fp1, "%lf\n", t[i].payroll);
		}	
		fclose(fp1);
	}else
	{
		 printf("没有人数数量。");
	}

    return 0;
}





/***********************************************

Function: find
Description: 查询并显示文件中选定的某条数据
Calls: all_money、grsds、Des_money
Called By: menu
Table Accessed:	gx.dat
Input: 输入需要查询到工号
Output:	输出选定数据的各项信息

***********************************************/

int find(zggz t[])					//《查询职工工资数据函数》
{
	char gonghao[10];
	int flag=0;						//标记员工是否存在
	int j=0;						//记录员工所在位置
	int i=0;						//记录员工所在位置
	printf("\n请输入需要查询的工号:");
	scanf("%s",gonghao);
	for(i=0;i<count;i++)			//在结构体数组查找有无该编号的员工，如果有那么flag=1，否则flag=0
	{
		if (strcmp(t[i].id,gonghao)==0)
		{
			flag = 1;
			break;
		}
	}
	if (flag)						//若存在该员工，则输出该员工的信息
	{    
		
		printf("\n");              
		printf("  姓名:%s\n", t[i].zg_name);
		printf("  工号:%s\n", t[i].id);              
		printf("  岗位工资:%lf\n", t[i].Post_wage);              
		printf("  薪级工资:%lf\n", t[i].Pay_salary);              
		printf("  职务津贴:%lf\n", t[i].Post_allowance);              
		printf("  绩效工资:%lf\n", t[i].Performance_salary);    
		printf("  应发工资:%lf\n", t[i].Deserved); 
		printf("  个人所得税:%lf\n", t[i].Individual_income_tax);
		printf("  实发工资:%lf\n", t[i].payroll);   

	 } 
	 else
	 { 
		 printf("没有找到该编号的员工！\n"); 
	 }
	printf("\n");
	system("pause");
    return 0;
}





/***********************************************

Function: list
Description: 浏览查看所有数据
Calls: all_money、grsds、Des_money
Called By: menu
Table Accessed:	gx.dat
Output: 输出文件gx.dat中所有的数据

***********************************************/

int list(zggz t[])					//《浏览职工工资数据函数》
{

	int i;
	int cx=count;
	if(cx=!0)
	{
			
		for(i=0;i<count;i++)
		{
			printf("  工号:%s\n", t[i].id);  
			printf("  姓名:%s\n", t[i].zg_name);            
			printf("  岗位工资:%lf\n", t[i].Post_wage);              
			printf("  薪级工资:%lf\n", t[i].Pay_salary);              
			printf("  职务津贴:%lf\n", t[i].Post_allowance);              
			printf("  绩效工资:%lf\n", t[i].Performance_salary);    
			printf("  应发工资:%lf\n", t[i].Deserved); 
			printf("  个人所得税:%lf\n", t[i].Individual_income_tax);
			printf("  实发工资:%lf\n", t[i].payroll);  
			printf("\n");
		}
	}
	else
	{ 
		printf("没有该员工！\n");  
	}
	return 0;
}





/***********************************************

Function: all_money
Description: 计算四份钱的合	
Called By: grsds
Table Accessed: gx.dat

***********************************************/

void all_money(zggz S[])			//计算应发工资       
{
	int i;
	for(i=0;i<count;i++)
		S[i].Deserved=S[i].Post_wage+S[i].Pay_salary+S[i].Post_allowance+S[i].Performance_salary;
}


/***********************************************

Function: grsds
Description: 计算金钱总和的税
Calls: all_money
Called By: Des_money
Table Accessed:	gx.dat

***********************************************/

void grsds(zggz S[])				//《计算个人所得税函数》       
{
	int i;
	for(i=0;i<count;i++)
	{
		if
			(S[i].Deserved<500)						//不超过500元所得税（5%）																											
			S[i].Individual_income_tax=S[i].Deserved*0.05;
		else if
			(S[i].Deserved<2000)					//超过500元到2000元部分的所得税（10%）
			S[i].Individual_income_tax=(S[i].Deserved-500)*0.1+500*0.05;
		else if
			(S[i].Deserved<5000)					//超过2000元到5000元部分的所得税（15%）
			S[i].Individual_income_tax=(S[i].Deserved-2000)*0.15+1500*0.1+500*0.05;	
		else if
			(S[i].Deserved<20000)					//超过5000元到20000元部分的所得税（20%）
			S[i].Individual_income_tax=(S[i].Deserved-5000)*0.2+3000*0.15+1500*0.1+500*0.05;															     			
		else if
			(S[i].Deserved<40000)					//超过20000元到40000元部分的所得税（25%）
			S[i].Individual_income_tax=(S[i].Deserved-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;															    
		else if
			(S[i].Deserved<60000)					//超过40000元到60000元部分的所得税（30%）
			S[i].Individual_income_tax=(S[i].Deserved-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;											     
		else if
			(S[i].Deserved<80000)					//超过60000元到80000元部分的所得税（35%）
			S[i].Individual_income_tax=(S[i].Deserved-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;								     					
		else if
			(S[i].Deserved<100000)					//超过80000元到100000元部分的所得税（40%）
			S[i].Individual_income_tax=(S[i].Deserved-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;				
		else										//超过100000元的部分的所得税（45%）
			S[i].Individual_income_tax=(S[i].Deserved-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		
	}
}


/***********************************************

Function: Des_money					//函数名称
Description: 计算实际发的工资				//函数功能、性能等的描述
Calls: grsds、all_money
Table Accessed:	gx.dat

***********************************************/

void Des_money(zggz S[])			//计算实发工资	       
{
	int i;
	for(i=0;i<count;i++)
		S[i].payroll=S[i].Deserved-S[i].Individual_income_tax;
}




/***********************************************

Function: modify
Description: 修改文件gx.dat中的工资数据
Calls: all_money、grsds、Des_money
Called By: menu
Table Accessed:	gx.dat
Table Update: gx.dat

***********************************************/

int modify(zggz t[])				//《修改职工工资数据函数》
{
	char gonghao[10];
	int flag=0;						//标记员工是否存在
	int i=0;						//记录员工所在位置
	printf("\n请输入要修改的工号：");
	scanf("%s",gonghao);
	for(i=0;i<count;i++)
	{
		if (strcmp(t[i].id,gonghao)==0)
		{
			flag = 1;
			break;
		}
	}

	if (flag)
	{              
			printf("\n请输入需要修改的内容：\n"); 
			printf("  工号:%s\n", t[i].id);          
			printf("  姓名:%s\n", t[i].zg_name);
			printf("  岗位工资:%lf\n", t[i].Post_wage);              
			printf("  薪级工资:%lf\n", t[i].Pay_salary);              
			printf("  职务津贴:%lf\n", t[i].Post_allowance);              
			printf("  绩效工资:%lf\n", t[i].Performance_salary);    
			printf("  应发工资:%lf\n", t[i].Deserved); 
			printf("  个人所得税:%lf\n", t[i].Individual_income_tax);
			printf("  实发工资:%lf\n", t[i].payroll);
			printf("\n");
   
				printf("\n请输入修改后的岗位工资：");
				scanf("%lf",&t[i].Post_wage);
				 
				printf("\n请输入修改后的薪级工资：");
			 	scanf("%lf",&t[i].Pay_salary);

				printf("\n请输入修改后的职务津贴：");
			 	scanf("%lf",&t[i].Post_allowance);


				printf("\n请输入修改后的绩效工资：");
			 	scanf("%lf",&t[i].Performance_salary);
				
				all_money(t);
				grsds(t);
				Des_money(t);
	} 
	else
	{ 
		printf("没有找到该编号的员工！\n"); 
	}
	return 0;
}





/***********************************************

Function: del
Description: 删除选择的数据
Calls: write
Called By: menu
Table Accessed:	gx.dat
Table Update: gx.gat

***********************************************/

int del(zggz t[])					//《删除职工工资数据函数》
{
	char gonghao[10];
	int flag=0;						//标记是否有该员工
	int sum_count=0;				//记录删除了几条信息
	int i=0;
	int j=0;
	printf("\n请输入需要删除员工的编号：");
	scanf("%s",gonghao);

	for(i=0;i<=count;i++)
	{
		if(strcmp(t[i].id,gonghao)==0)		//寻找需要删除员工的编号
		{
			flag=1;
			break;				  
		}
	}	

	if(flag)
	{
		for(j=i;j<count;j++)
		{
			t[j]=t[j+1];
		}		
			printf("\n该员工信息已删除！\n");
			sum_count++;
	}
	count = count-sum_count;
	if(flag==1)
	{
		printf("\n已删除该员工信息！\n");
	}
	write(t);
	return 0;
}





/***********************************************

Function: add
Description: 添加一条员工数据信息
Calls: all_money、grsds、Des_money
Called By: menu
Table Accessed:	gz.dat
Table Update: gz.dat
Input: 输入六个数据信息并保存到gz.dat文件

***********************************************/

int add(zggz t[])					//《添加职工工资数据函数》
{
	if (count>100)
	{
		printf("员工信息已满！\n");
        return 0;
	} 
	else
	{
        printf("\n");

		printf("\n请输入添加员工的编号：");
        scanf("%s", t[count].id);
			  		 
        printf("\n请输入添加员工的姓名：");
		scanf("%s",t[count].zg_name);

		printf("\n请输入添加员工的岗位工资：");
		scanf("%lf",&t[count].Post_wage);

		printf("\n请输入添加员工的薪级工资：");
		scanf("%lf",&t[count].Pay_salary);
		
		printf("\n请输入添加员工的职务津贴：");
		scanf("%lf", &t[count].Post_allowance);
		
		printf("\n请输入添加员工的绩效工资：");
		scanf("%lf", &t[count].Performance_salary);
	
		count++;
		all_money(t);
		grsds(t);
		Des_money(t);
		printf("\n信息添加成功！\n\n");
    }
	return 0;
}




/***********************************************

Function: main
Description: 主函数用来调用其他函数
Calls: find、modify、add、del、write、list、read、all_money、grsds、Des_money

***********************************************/
int main()							//《主菜单函数》
{
	zggz z[50];
	int menu();
	read(z);
	all_money(z);
	grsds(z);
	Des_money(z);

    do{ 
        switch(menu()){
            case 1:
                find(z);			//查询职工工资函数
                break;
            case 2:
                modify(z);			//修改职工工资函数
                break;
            case 3:
                add(z);				//添加职工工资函数
                break;
            case 4:
                del(z);				//删除职工工资函数
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



/***********************************************

Function: menu
Description: 显示该程序的菜单
Calls: find、modify、add、del、write、list
Called By: main

***********************************************/

int menu()						//《菜单显示》
{
   int option=0;
    char i=0;
	printf("\t\t**** 欢迎使用广西民族大学软件与信息安全学院职工工资管理系统 ***\n\n");
	printf("\t请选择数字菜单 <1 - 7>\n");
    printf("\t ==============================================================================\n");
    printf("\t丨\t\t1. 查 询 职 工 工 资 数 据                                    丨\n");
    printf("\t丨\t\t2. 修 改 职 工 工 资 数 据                                    丨\n");
    printf("\t丨\t\t3. 添 加 职 工 工 资 数 据                                    丨\n");
    printf("\t丨\t\t4. 删 除 职 工 工 资 数 据                                    丨\n");
    printf("\t丨\t\t5. 保 存 职 工 工 资 数 据                                    丨\n");
    printf("\t丨\t\t6. 浏 览 职 工 工 资 数 据                                    丨\n");
	printf("\t丨\t\t7.       退 出 系 统                                          丨\n");
    printf("\t ==============================================================================\n\n");
	printf("\t请输入需要执行命令的数字编号(1-7):");
    scanf("%c",&i);
    option=(int)(i-'0');
    while(option<1||option>7){
        printf("输入错误，请重新输入：\n");
        scanf("%d",&option);
    }
    return option;
}

