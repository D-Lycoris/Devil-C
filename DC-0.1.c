/*********************************************

Copyright (c), 17������� �Ծ�Ρ��Co.,Ltd
FlieName: gzgl.c
Author:        Version:        Date:
Description:        //�������
Version:            //�汾��Ϣ
Function List:      //��Ҫ��������
    1.
    2.
History:            //��ʷ�޸ļ�¼

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
	char wo_name[10];			//ְ������
	char id[10];				//ְ������
	double position_value, Pay_salary;				//���ʡ�н��
	double duty_allowance, merit_pay, gross_pay, Personal_income_tax, payroll;		//��������Ч��Ӧ������������˰��ʵ������
}zggz;			//���ʽṹ

int count=0;

int read(zggz t[])			//��ȡְ���������ݺ���
{
	zggz T;
	FILE *fp;											//�ļ�ָ��
       if ((fp = fopen("gz.dat", "rb")) == NULL)
		{												//�����ļ�ʧ�����˳�
        puts("���ļ�ʧ�ܣ�");
        return 0;
		}												//����ļ��򿪳ɹ������ȡ���� 
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
			printf("\n��%d��Ա����Ϣ������\n",count);

			fclose(fp);
			return count;		
}


int write(zggz t[])							//����ְ���������ݺ���
{
	int i;
	zggz z;
	 if(count>0)
	 {
		FILE* fp1=fopen("gx.dat","w");
		if (fp1==NULL)
		{									//�����ļ�ʧ�����˳�
        puts("���ļ�ʧ�ܣ�");
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
		 printf("����Ϊ�㡣");
	 }
    return 0;
}


int find(zggz t[])				//��ѯְ���������ݺ���
{
	char gonghao[10];
	int flag=0;					//���Ա����û�д���
	int j=0;					//��¼Ա�����ڵ�λ��
	int i=0;					//��¼Ա�����ڵ�λ��
	printf("\n������Ҫ��ѯ�Ĺ���");
	scanf("%s",gonghao);

	//�ڽṹ������������޸ñ�ŵ�Ա�����������ôflag=1������flag=0
	for(i=0;i<count;i++)
	{
		if (t[i].id==gonghao)
		{
			flag = 1;
			break;
		}
	}
 if (flag)					//������ڸ�Ա������ô�����Ա������Ϣ
 {              
		printf("���\t����\t�Ա�\tְ��\t����\t����\n");              
		printf("%s\t", t[i].wo_name);
		printf("%d\t", t[i].id);              
		printf("%f\t", t[i].position_value);              
		printf("%f\t", t[i].Pay_salary);              
		printf("%f\t", t[i].duty_allowance);              
		printf("%f\t", t[i].merit_pay);    
		printf("%f\t", t[i].gross_pay); 
		printf("%f\t", t[i].Personal_income_tax);
		printf("%f\t", t[i].payroll);
		
	 /*��j�����Ա����λ�ã�Ȼ�������Ա������Ϣ,
	 �ڶ���Ѱ�ҵ���ʼλ��Ӧ�ô�i+1��ʼ*/
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
 } else{ printf("û���ҵ��ñ��Ա��.\n"); }
     
 printf("\n");
 system("pause");
 return 0;
}


int list(zggz t[])				//���ְ���������ݺ���
{
	int j;
	if(count=!0)
	{
		for(j=0;j<count;j++)
		{
		printf("���\t����\t�Ա�\tְ��\t����\t����\n");              
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
	}else{ printf("û��Ա����\n");  }
	return 0;
}

int modify(zggz t[])				//�޸�ְ���������ݺ���
{
	double position_value, Pay_salary, duty_allowance, merit_pay, gross_pay, Personal_income_tax,payroll;
	char gonghao[10];
	int flag=0;						//���Ա����û�д���
	int j=0;						//��¼Ա�����ڵ�λ��
	int i=0;						//��¼Ա�����ڵ�λ��
	printf("������Ҫ��ѯ�Ĺ���");
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
		printf("���\t����\t�Ա�\tְ��\t����\t����\n");              
		printf("%s\t", t[i].wo_name);
		printf("%d\t", t[i].id);              
		printf("%f\t", t[i].position_value);              
		printf("%f\t", t[i].Pay_salary);              
		printf("%f\t", t[i].duty_allowance);              
		printf("%f\t", t[i].merit_pay);    
		printf("%f\t", t[i].gross_pay); 
		printf("%f\t", t[i].Personal_income_tax);
		printf("%f\t", t[i].payroll);     
	 /*����Ա���������ж�����һ����Ա����������Ҫ����Ѱ�ң���j�����Ա����λ��  Ȼ�������Ա������Ϣ             
	 �ڶ���Ѱ�ҵ���ʼλ��Ӧ�ô�i+1��ʼ ��Ϊ֮ǰ���Ѿ��ҹ���*/
	 for (j=i+1; j<count; j++)
	 {                     
		 if (t[j].id == gonghao)
		 {     
			 printf("\n�������޸�position_value");
			 scanf("%d",&position_value);
				 t[j].position_value=position_value;

			 printf("\n�������޸�Pay_salary");
			 			 scanf("%d",&Pay_salary);
				 t[j].Pay_salary=Pay_salary;

			 printf("\n�������޸�duty_allowance");
			 			 scanf("%d",&duty_allowance);
				 t[j].duty_allowance=duty_allowance;

			 printf("\n�������޸�merit_pay");
			 			 scanf("%d",&merit_pay);
				 t[j].merit_pay=merit_pay;

		     printf("\n�������޸�gross_pay");
			 	scanf("%d",&gross_pay);
				 t[j].gross_pay=gross_pay;
		 }
	 }
 } else{ printf("û���ҵ��˱��Ա����\n"); }
	return 0;
}

void add_money(zggz S[])		//����Ӧ������       
{
	int i;
	for(i=0;i<count;i++)
		S[i].gross_pay=S[i].position_value+S[i].Pay_salary+S[i].duty_allowance+S[i].merit_pay;
}


void grsds(zggz S[])			//�����������˰       
{
	int i;
	for(i=0;i<count;i++)
	{
		if(S[i].gross_pay<500)																									//������500Ԫ������˰��5%��
			S[i].Personal_income_tax=S[i].gross_pay*0.05;
		else if(S[i].gross_pay<2000)																							//����500Ԫ��2000Ԫ�Ĳ��ֵ�����˰��10%��
			S[i].Personal_income_tax=(S[i].gross_pay-2000)*0.1+500*0.05;	
		else if(S[i].gross_pay<5000)																							//����2000Ԫ��5000Ԫ�Ĳ��ֵ�����˰��15%��
			S[i].Personal_income_tax=(S[i].gross_pay-5000)*0.15+1500*0.1+500*0.05;														     			
		else if(S[i].gross_pay<20000)																							//����5000Ԫ��20000Ԫ�Ĳ��ֵ�����˰��20%��
			S[i].Personal_income_tax=(S[i].gross_pay-20000)*0.2+15000*0.15+1500*0.1+500*0.05;														    
		else if(S[i].gross_pay<40000)																							//����20000Ԫ��40000Ԫ�Ĳ��ֵ�����˰��25%��
			S[i].Personal_income_tax=(S[i].gross_pay-40000)*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;											     
		else if(S[i].gross_pay<60000)																							//����40000Ԫ��60000Ԫ�Ĳ��ֵ�����˰��30%��
			S[i].Personal_income_tax=(S[i].gross_pay-60000)*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;								     		
		else if(S[i].gross_pay<80000)																							//����60000Ԫ��80000Ԫ�Ĳ��ֵ�����˰��35%��
			S[i].Personal_income_tax=(S[i].gross_pay-80000)*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;		     				
		else if(S[i].gross_pay<100000)																							//����80000Ԫ��100000Ԫ�Ĳ��ֵ�����˰��40%��
			S[i].Personal_income_tax=(S[i].gross_pay-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+20000*0.2+15000*0.15+1500*0.1+500*0.05;				
		else																													//����100000Ԫ�Ĳ��ֵ�����˰��45%��
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

int menu()                                                //�˵�
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
	printf("��������Ҫִ����������ֱ��(1-7):");
    scanf("%c",&i);
    option=(int)(i-'0');

    while(option<1||option>7){
        printf("Input Error!\nPlease retype:\n");
        scanf("%d",&option);
    }
    return option;
}

