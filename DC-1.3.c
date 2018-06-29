/*********************************************

Copyright (c), 17������� �Ծ�Ρ��Co.,Ltd
FlieName: gzgl.c
Author:�Ծ�Ρ        Version:1.3        Date:2018/6/25

Description:
��ϵͳ�����Ŀ����ʵ��ְ�����ʼ�¼��¼�롢��ѯ���޸ġ���ӡ�ɾ�������ݱ��湦�ܡ�
�������й���ϵͳ��ʵ�����ȷ��ְ�����ʼ�¼��ְ�����š�ְ����������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������9����Ŀ���ɡ�
ϵͳӦʵ�ֹ��ʼ�¼��������ӡ����桢���ݹ��Ž��в�ѯ�������ɾ��������������޸ĵ�ͬʱ�Զ���ɸ�������˰��Ӧ�����ʵļ��㡣

Version:1.3

Function List:
	1.int read(zggz t[])			����ȡְ���������ݺ�����
	2.int write(zggz t[])			������ְ���������ݺ�����
	3.int find(zggz t[])			����ѯְ���������ݺ�����
	4.int list(zggz t[])			�����ְ���������ݺ�����
	5.void grsds(zggz S[])			�������������˰������ 
	6. int modify(zggz t[])			���޸�ְ���������ݺ�����
	7.int del(zggz t[])				��ɾ��ְ���������ݺ�����
	8.int add(zggz t[])				�����ְ���������ݺ�����
	9.int main						�˵�
	10.int menu						�˵���ʾ
	11.void all_money(zggz S[])		����Ӧ������
	12.void Des_money(zggz S[])		����ʵ������

History:            //��ʷ�޸ļ�¼

    <author>    <time>    <version>    <desc>
	 �Ծ�Ρ    2018/6/19     1.3       

***********************************************/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct ZGGZ{					//���ʽṹ��
	char zg_name[10];					//ְ������
	char id[10];						//ְ������
	double Post_wage;					//��λ����
	double Pay_salary;					//н������
	double Post_allowance;				//ְ�����
	double Performance_salary;			//��Ч����
	double Deserved;					//Ӧ������
	double Individual_income_tax;		//��������˰
	double payroll;						//ʵ������
}zggz;

int count=0;





/***********************************************

Function: read
Description: ��ȡְ��������Ϣ
Calls: all_money��grsds��Des_money
Called By: menu
Table Accessed:	gx.dat
Table Update: gx.dat��gz.dat

***********************************************/

int read(zggz t[])			//����ȡְ���������ݺ�����
{
	zggz T;
	FILE *fp;				//�ļ�ָ��
    if ((fp = fopen("gx.dat", "rb")) == NULL)			//����ļ���ʧ�����˳�
	{
		puts("���ļ�ʧ�ܣ�");
        return 0;
	}
	while (!feof(fp))				//����ļ��򿪳ɹ�����ô���ж�����   
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
		
	printf("\t\t\t\t\t(����ȡ��%d��Ա������Ϣ)\n\n",count);
	fclose(fp);
	return count;		
}




/***********************************************

Function: write
Description: ����һ���µĹ������ݵ��ļ�gz.dat�С�
Called By: menu��write
Table Accessed: gz.dat
Table Update: gz.dat

***********************************************/

int write(zggz t[])				//������ְ���������ݺ�����
{
	int i;
	if(count>0) 
	{
		FILE* fp1=fopen("gz.dat","w");
		if (fp1==NULL)				//����ļ���ʧ�����˳�
		{
            puts("���ļ�ʧ�ܣ�");
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
		 printf("û������������");
	}

    return 0;
}





/***********************************************

Function: find
Description: ��ѯ����ʾ�ļ���ѡ����ĳ������
Calls: all_money��grsds��Des_money
Called By: menu
Table Accessed:	gx.dat
Input: ������Ҫ��ѯ������
Output:	���ѡ�����ݵĸ�����Ϣ

***********************************************/

int find(zggz t[])					//����ѯְ���������ݺ�����
{
	char gonghao[10];
	int flag=0;						//���Ա���Ƿ����
	int j=0;						//��¼Ա������λ��
	int i=0;						//��¼Ա������λ��
	printf("\n��������Ҫ��ѯ�Ĺ���:");
	scanf("%s",gonghao);
	for(i=0;i<count;i++)			//�ڽṹ������������޸ñ�ŵ�Ա�����������ôflag=1������flag=0
	{
		if (strcmp(t[i].id,gonghao)==0)
		{
			flag = 1;
			break;
		}
	}
	if (flag)						//�����ڸ�Ա�����������Ա������Ϣ
	{    
		
		printf("\n");              
		printf("  ����:%s\n", t[i].zg_name);
		printf("  ����:%s\n", t[i].id);              
		printf("  ��λ����:%lf\n", t[i].Post_wage);              
		printf("  н������:%lf\n", t[i].Pay_salary);              
		printf("  ְ�����:%lf\n", t[i].Post_allowance);              
		printf("  ��Ч����:%lf\n", t[i].Performance_salary);    
		printf("  Ӧ������:%lf\n", t[i].Deserved); 
		printf("  ��������˰:%lf\n", t[i].Individual_income_tax);
		printf("  ʵ������:%lf\n", t[i].payroll);   

	 } 
	 else
	 { 
		 printf("û���ҵ��ñ�ŵ�Ա����\n"); 
	 }
	printf("\n");
	system("pause");
    return 0;
}





/***********************************************

Function: list
Description: ����鿴��������
Calls: all_money��grsds��Des_money
Called By: menu
Table Accessed:	gx.dat
Output: ����ļ�gx.dat�����е�����

***********************************************/

int list(zggz t[])					//�����ְ���������ݺ�����
{

	int i;
	int cx=count;
	if(cx=!0)
	{
			
		for(i=0;i<count;i++)
		{
			printf("  ����:%s\n", t[i].id);  
			printf("  ����:%s\n", t[i].zg_name);            
			printf("  ��λ����:%lf\n", t[i].Post_wage);              
			printf("  н������:%lf\n", t[i].Pay_salary);              
			printf("  ְ�����:%lf\n", t[i].Post_allowance);              
			printf("  ��Ч����:%lf\n", t[i].Performance_salary);    
			printf("  Ӧ������:%lf\n", t[i].Deserved); 
			printf("  ��������˰:%lf\n", t[i].Individual_income_tax);
			printf("  ʵ������:%lf\n", t[i].payroll);  
			printf("\n");
		}
	}
	else
	{ 
		printf("û�и�Ա����\n");  
	}
	return 0;
}





/***********************************************

Function: all_money
Description: �����ķ�Ǯ�ĺ�	
Called By: grsds
Table Accessed: gx.dat

***********************************************/

void all_money(zggz S[])			//����Ӧ������       
{
	int i;
	for(i=0;i<count;i++)
		S[i].Deserved=S[i].Post_wage+S[i].Pay_salary+S[i].Post_allowance+S[i].Performance_salary;
}


/***********************************************

Function: grsds
Description: �����Ǯ�ܺ͵�˰
Calls: all_money
Called By: Des_money
Table Accessed:	gx.dat

***********************************************/

void grsds(zggz S[])				//�������������˰������       
{
	int i;
	for(i=0;i<count;i++)
	{
		if
			(S[i].Deserved<500)						//������500Ԫ����˰��5%��																											
			S[i].Individual_income_tax=S[i].Deserved*0.05;
		else if
			(S[i].Deserved<2000)					//����500Ԫ��2000Ԫ���ֵ�����˰��10%��
			S[i].Individual_income_tax=(S[i].Deserved-500)*0.1+500*0.05;
		else if
			(S[i].Deserved<5000)					//����2000Ԫ��5000Ԫ���ֵ�����˰��15%��
			S[i].Individual_income_tax=(S[i].Deserved-2000)*0.15+1500*0.1+500*0.05;	
		else if
			(S[i].Deserved<20000)					//����5000Ԫ��20000Ԫ���ֵ�����˰��20%��
			S[i].Individual_income_tax=(S[i].Deserved-5000)*0.2+3000*0.15+1500*0.1+500*0.05;															     			
		else if
			(S[i].Deserved<40000)					//����20000Ԫ��40000Ԫ���ֵ�����˰��25%��
			S[i].Individual_income_tax=(S[i].Deserved-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;															    
		else if
			(S[i].Deserved<60000)					//����40000Ԫ��60000Ԫ���ֵ�����˰��30%��
			S[i].Individual_income_tax=(S[i].Deserved-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;											     
		else if
			(S[i].Deserved<80000)					//����60000Ԫ��80000Ԫ���ֵ�����˰��35%��
			S[i].Individual_income_tax=(S[i].Deserved-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;								     					
		else if
			(S[i].Deserved<100000)					//����80000Ԫ��100000Ԫ���ֵ�����˰��40%��
			S[i].Individual_income_tax=(S[i].Deserved-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;				
		else										//����100000Ԫ�Ĳ��ֵ�����˰��45%��
			S[i].Individual_income_tax=(S[i].Deserved-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		
	}
}


/***********************************************

Function: Des_money					//��������
Description: ����ʵ�ʷ��Ĺ���				//�������ܡ����ܵȵ�����
Calls: grsds��all_money
Table Accessed:	gx.dat

***********************************************/

void Des_money(zggz S[])			//����ʵ������	       
{
	int i;
	for(i=0;i<count;i++)
		S[i].payroll=S[i].Deserved-S[i].Individual_income_tax;
}




/***********************************************

Function: modify
Description: �޸��ļ�gx.dat�еĹ�������
Calls: all_money��grsds��Des_money
Called By: menu
Table Accessed:	gx.dat
Table Update: gx.dat

***********************************************/

int modify(zggz t[])				//���޸�ְ���������ݺ�����
{
	char gonghao[10];
	int flag=0;						//���Ա���Ƿ����
	int i=0;						//��¼Ա������λ��
	printf("\n������Ҫ�޸ĵĹ��ţ�");
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
			printf("\n��������Ҫ�޸ĵ����ݣ�\n"); 
			printf("  ����:%s\n", t[i].id);          
			printf("  ����:%s\n", t[i].zg_name);
			printf("  ��λ����:%lf\n", t[i].Post_wage);              
			printf("  н������:%lf\n", t[i].Pay_salary);              
			printf("  ְ�����:%lf\n", t[i].Post_allowance);              
			printf("  ��Ч����:%lf\n", t[i].Performance_salary);    
			printf("  Ӧ������:%lf\n", t[i].Deserved); 
			printf("  ��������˰:%lf\n", t[i].Individual_income_tax);
			printf("  ʵ������:%lf\n", t[i].payroll);
			printf("\n");
   
				printf("\n�������޸ĺ�ĸ�λ���ʣ�");
				scanf("%lf",&t[i].Post_wage);
				 
				printf("\n�������޸ĺ��н�����ʣ�");
			 	scanf("%lf",&t[i].Pay_salary);

				printf("\n�������޸ĺ��ְ�������");
			 	scanf("%lf",&t[i].Post_allowance);


				printf("\n�������޸ĺ�ļ�Ч���ʣ�");
			 	scanf("%lf",&t[i].Performance_salary);
				
				all_money(t);
				grsds(t);
				Des_money(t);
	} 
	else
	{ 
		printf("û���ҵ��ñ�ŵ�Ա����\n"); 
	}
	return 0;
}





/***********************************************

Function: del
Description: ɾ��ѡ�������
Calls: write
Called By: menu
Table Accessed:	gx.dat
Table Update: gx.gat

***********************************************/

int del(zggz t[])					//��ɾ��ְ���������ݺ�����
{
	char gonghao[10];
	int flag=0;						//����Ƿ��и�Ա��
	int sum_count=0;				//��¼ɾ���˼�����Ϣ
	int i=0;
	int j=0;
	printf("\n��������Ҫɾ��Ա���ı�ţ�");
	scanf("%s",gonghao);

	for(i=0;i<=count;i++)
	{
		if(strcmp(t[i].id,gonghao)==0)		//Ѱ����Ҫɾ��Ա���ı��
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
			printf("\n��Ա����Ϣ��ɾ����\n");
			sum_count++;
	}
	count = count-sum_count;
	if(flag==1)
	{
		printf("\n��ɾ����Ա����Ϣ��\n");
	}
	write(t);
	return 0;
}





/***********************************************

Function: add
Description: ���һ��Ա��������Ϣ
Calls: all_money��grsds��Des_money
Called By: menu
Table Accessed:	gz.dat
Table Update: gz.dat
Input: ��������������Ϣ�����浽gz.dat�ļ�

***********************************************/

int add(zggz t[])					//�����ְ���������ݺ�����
{
	if (count>100)
	{
		printf("Ա����Ϣ������\n");
        return 0;
	} 
	else
	{
        printf("\n");

		printf("\n���������Ա���ı�ţ�");
        scanf("%s", t[count].id);
			  		 
        printf("\n���������Ա����������");
		scanf("%s",t[count].zg_name);

		printf("\n���������Ա���ĸ�λ���ʣ�");
		scanf("%lf",&t[count].Post_wage);

		printf("\n���������Ա����н�����ʣ�");
		scanf("%lf",&t[count].Pay_salary);
		
		printf("\n���������Ա����ְ�������");
		scanf("%lf", &t[count].Post_allowance);
		
		printf("\n���������Ա���ļ�Ч���ʣ�");
		scanf("%lf", &t[count].Performance_salary);
	
		count++;
		all_money(t);
		grsds(t);
		Des_money(t);
		printf("\n��Ϣ��ӳɹ���\n\n");
    }
	return 0;
}




/***********************************************

Function: main
Description: ����������������������
Calls: find��modify��add��del��write��list��read��all_money��grsds��Des_money

***********************************************/
int main()							//�����˵�������
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
                find(z);			//��ѯְ�����ʺ���
                break;
            case 2:
                modify(z);			//�޸�ְ�����ʺ���
                break;
            case 3:
                add(z);				//���ְ�����ʺ���
                break;
            case 4:
                del(z);				//ɾ��ְ�����ʺ���
                break;
            case 5:
                write(z);			//����ְ�����ʺ���
                break;
            case 6:
                list(z);			//���ְ�����ʺ���
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
Description: ��ʾ�ó���Ĳ˵�
Calls: find��modify��add��del��write��list
Called By: main

***********************************************/

int menu()						//���˵���ʾ��
{
   int option=0;
    char i=0;
	printf("\t\t**** ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ ***\n\n");
	printf("\t��ѡ�����ֲ˵� <1 - 7>\n");
    printf("\t ==============================================================================\n");
    printf("\tح\t\t1. �� ѯ ְ �� �� �� �� ��                                    ح\n");
    printf("\tح\t\t2. �� �� ְ �� �� �� �� ��                                    ح\n");
    printf("\tح\t\t3. �� �� ְ �� �� �� �� ��                                    ح\n");
    printf("\tح\t\t4. ɾ �� ְ �� �� �� �� ��                                    ح\n");
    printf("\tح\t\t5. �� �� ְ �� �� �� �� ��                                    ح\n");
    printf("\tح\t\t6. � �� ְ �� �� �� �� ��                                    ح\n");
	printf("\tح\t\t7.       �� �� ϵ ͳ                                          ح\n");
    printf("\t ==============================================================================\n\n");
	printf("\t��������Ҫִ����������ֱ��(1-7):");
    scanf("%c",&i);
    option=(int)(i-'0');
    while(option<1||option>7){
        printf("����������������룺\n");
        scanf("%d",&option);
    }
    return option;
}

