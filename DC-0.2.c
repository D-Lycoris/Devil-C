/*********************************************

Copyright (c), 17������� �Ծ�Ρ��Co.,Ltd
FlieName: gzgl.c
Author:        Version:        Date:

Description:
1.int read(zggz t[])����ȡְ���������ݺ�����        //�������
2.int write(zggz t[])������ְ���������ݺ�����

Version:            //�汾��Ϣ

Function List:      //��Ҫ��������
    1.
    2.
History:            //��ʷ�޸ļ�¼

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

typedef struct ZGGZ{						//���ʽṹ��
	char zg_name[10];						//ְ������
	char id[10];							//ְ������
	double Post_wage;						//��λ����
	double Pay_salary;						//н������
	double Post_allowance;					//ְ�����
	double Performance_salary;				//Ч������
	double Deserved;						//Ӧ������
	double Individual_income_tax;			//��������˰
	double payroll;							//ʵ������
}zggz;

int count=0;


int read(zggz t[])				//����ȡְ���������ݺ�����
{
	zggz T;
	FILE *fp;											//�ļ�ָ��
       if ((fp = fopen("gx.dat", "rb")) == NULL)
		{												//����ļ���ʧ�����˳�
        puts("���ܴ��ļ���");
        return 0;
		}												//����ļ��򿪳ɹ����ȡ����
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
		printf("����ȡ��%d��Ա������Ϣ\n\n",count);
		fclose(fp);
		return count;		
}


int write(zggz t[])								//������ְ���������ݺ�����
{
	int i;
	 if(count>0)
	 {
		FILE* fp1=fopen("gz.dat","w");
		if (fp1==NULL)
		{										//�����ļ�ʧ�����˳�
            puts("���ļ�ʧ�ܣ�");
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
		 printf("����Ϊ�㡣");
	 }

    return 0;
}


int find(zggz t[])						//����ѯְ���������ݺ�����
{
	char gonghao[10];
	int flag=0;							//���Ա���Ƿ����
	int j=0;							//��¼Ա�����ڵ�λ��
	int i=0;							//��¼Ա�����ڵ�λ��
	printf("\n������Ҫ��ѯ�Ĺ��ţ�");
	scanf("%s",gonghao);
	printf("%s",t[0].id);
	printf("%s",gonghao);

	//�ڽṹ������������޸ñ�ŵ�Ա�����������ôflag=1������flag=0
	for(i=0;i<count;i++)
	{
		
		if (*(t[i].id)==*(gonghao))
		{
			printf("%s",t[i].id);
			flag = 1;
			break;
		}
	}

 if (flag)				//������ڸ�Ա������ô�����Ա������Ϣ
 {              
		printf("���\t����\t�Ա�\tְ��\t����\t����\n");              
		printf("%s\t", t[i].zg_name);
		printf("%d\t", t[i].id);              
		printf("%f\t", t[i].Post_wage);              
		printf("%f\t", t[i].Pay_salary);              
		printf("%f\t", t[i].Post_allowance);              
		printf("%f\t", t[i].Performance_salary);    
		printf("%f\t", t[i].Deserved); 
		printf("%f\t", t[i].Individual_income_tax);
		printf("%f\t", t[i].payroll);   

	 /*��j�����Ա��λ�ã������Ա������Ϣ             
	 �ڶ���Ѱ�ҵ���ʼλ�ô�i+1��ʼ*/
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
 } else{ printf("û���ҵ��ñ�ŵ�Ա����\n"); }
     
	printf("\n");
	system("pause");
	return 0;
}


int list(zggz t[])					//�����ְ���������ݺ�����
{

	int j;
	int asd=count;
	if(asd=!0)
	{
		printf("%d",count);
		
		for(j=0;j<count;j++)
		{
			printf("���\t����\t�Ա�\tְ��\t����\t����\n");              
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
	}else{ printf("û�и�Ա����\n");  }
	return 0;
}


int modify(zggz t[])							//���޸�ְ���������ݺ�����
{
	double Post_wage, Pay_salary, Post_allowance, Performance_salary, Deserved, Individual_income_tax,payroll;
	char gonghao[10];
	int flag=0;									//���Ա���Ƿ����
	int j=0;									//��¼Ա�����ڵ�λ��
	int i=0;									//��¼Ա�����ڵ�λ��
	printf("������Ҫ��ѯ�Ĺ���");
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
		printf("���\t����\t�Ա�\tְ��\t����\t����\n");              
		printf("%s\t", t[i].zg_name);
		printf("%d\t", t[i].id);              
		printf("%f\t", t[i].Post_wage);              
		printf("%f\t", t[i].Pay_salary);              
		printf("%f\t", t[i].Post_allowance);              
		printf("%f\t", t[i].Performance_salary);    
		printf("%f\t", t[i].Deserved); 
		printf("%f\t", t[i].Individual_income_tax);
		printf("%f\t", t[i].payroll);     

	 /*��j�����Ա����λ��  Ȼ�������Ա������Ϣ             
	 �ڶ���Ѱ�ҵ���ʼλ�ô�i+1��ʼ*/
	 for (j=i+1; j<count; j++)
	 {                     
		 if (t[j].id == gonghao)
		 {     
			 printf("\n�������޸�Post_wage");
			 scanf("%d",&Post_wage);
				 t[j].Post_wage=Post_wage;

			 printf("\n�������޸�Pay_salary");
			 			 scanf("%d",&Pay_salary);
				 t[j].Pay_salary=Pay_salary;

			 printf("\n�������޸�Post_allowance");
			 			 scanf("%d",&Post_allowance);
				 t[j].Post_allowance=Post_allowance;

			 printf("\n�������޸�Performance_salary");
			 			 scanf("%d",&Performance_salary);
				 t[j].Performance_salary=Performance_salary;

		     printf("\n�������޸�Deserved");
			 	scanf("%d",&Deserved);
				 t[j].Deserved=Deserved;
		 }
	 }
 } else{ printf("û���ҵ��˱��Ա����\n"); }
	return 0;
}


int del()							//��ɾ��ְ���������ݺ�����
{
	return 0;
}


int add()							//�����ְ���������ݺ�����
{
	return 0;
}


void add_money(zggz S[])		//����Ӧ������       
{
	int i;
	for(i=0;i<count;i++)
		S[i].Deserved=S[i].Post_wage+S[i].Pay_salary+S[i].Post_allowance+S[i].Performance_salary;
}

void grsds(zggz S[])			//�������������˰������
{
	int i;
	for(i=0;i<count;i++)
	{
		if(S[i].Deserved<500)																									//������500Ԫ������˰��5%��
			S[i].Individual_income_tax=S[i].Deserved*0.05;

		else if(S[i].Deserved<2000)																								//����500Ԫ��2000Ԫ�Ĳ��ֵ�����˰��10%��
			S[i].Individual_income_tax=(S[i].Deserved-2000)*0.1+500*0.05;
		
		else if(S[i].Deserved<5000)																								//����2000Ԫ��5000Ԫ�Ĳ��ֵ�����˰��15%��
			S[i].Individual_income_tax=(S[i].Deserved-5000)*0.15+1500*0.1+500*0.05;
		
		else if(S[i].Deserved<20000)																							//����5000Ԫ��20000Ԫ�Ĳ��ֵ�����˰��20%��
			S[i].Individual_income_tax=(S[i].Deserved-20000)*0.2+15000*0.15+1500*0.1+500*0.05;
		
		else if(S[i].Deserved<40000)																							//����20000Ԫ��40000Ԫ�Ĳ��ֵ�����˰��25%��
			S[i].Individual_income_tax=(S[i].Deserved-40000)*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		
		else if(S[i].Deserved<60000)																							//����40000Ԫ��60000Ԫ�Ĳ��ֵ�����˰��30%��
			S[i].Individual_income_tax=(S[i].Deserved-60000)*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;

		else if(S[i].Deserved<80000)																							//����60000Ԫ��80000Ԫ�Ĳ��ֵ�����˰��35%��
			S[i].Individual_income_tax=(S[i].Deserved-80000)*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		
		else if(S[i].Deserved<100000)																							//����80000Ԫ��100000Ԫ�Ĳ��ֵ�����˰��40%��
			S[i].Individual_income_tax=(S[i].Deserved-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;
		
		else																													//����100000Ԫ�Ĳ��ֵ�����˰��45%��
			S[i].Individual_income_tax=(S[i].Deserved-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;		
	}
}

void add_wages(zggz S[])	//����ʵ������	       
{
	int i;
	for(i=0;i<count;i++)
		S[i].payroll=S[i].Deserved-S[i].Individual_income_tax;
}


int main()							//���˵���
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
                find(z);			//��ѯְ�����ʺ���
                break;
            case 2:
                modify(z);			//�޸�ְ�����ʺ���
                break;
            case 3:
                add();				//���ְ�����ʺ���
                break;
            case 4:
                del();				//ɾ��ְ�����ʺ���
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

int menu()
{
   int option=0;
    char i=0;
    printf("****************ְ�����ʹ���ϵͳ**************\n\n");
    printf("������������������������\n");
    printf("         1. �� ѯ ְ �� �� �� �� ��\n");
    printf("         2. �� �� ְ �� �� �� �� ��\n");
    printf("         3. �� �� ְ �� �� �� �� ��\n");
    printf("         4. ɾ �� ְ �� �� �� �� ��\n");
    printf("         5. �� �� ְ �� �� �� �� ��\n");
    printf("         6. � �� ְ �� �� �� �� ��\n");
	printf("         7.       �� �� ϵ ͳ\n");
    printf("������������������������\n\n");
	printf("��������Ҫִ����������ֱ��(1-7):\n");
    scanf("%c",&i);
    option=(int)(i-'0');
    while(option<1||option>7){
        printf("�����������������:\n");
        scanf("%d",&option);
    }
    return option;
}

