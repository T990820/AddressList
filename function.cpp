#include"function.h"
#include<iostream>
#include<string>
using namespace std;
void showMenu(void)
{
	cout<<"***************************"<<endl;
	cout<<"*****"<<"1�������ϵ��"<<"*****"<<endl;
	cout<<"*****"<<"2����ʾ��ϵ��"<<"*****"<<endl;
	cout<<"*****"<<"3��ɾ����ϵ��"<<"*****"<<endl;
	cout<<"*****"<<"4��������ϵ��"<<"*****"<<endl;
	cout<<"*****"<<"5���޸���ϵ��"<<"*****"<<endl;
	cout<<"*****"<<"6�������ϵ��"<<"*****"<<endl;
	cout<<"*****"<<"7�������ʾ��"<<"*****"<<endl;
	cout<<"*****"<<"0���˳�ͨѶ¼"<<"*****"<<endl;	
	cout<<"***************************"<<endl;
}
int searchSameInformation(person* p,int N,string str)//N��ͨѶ¼����Ա���� 
{
	int key=1;
	if(N==0)
		return 1;
	else
	{
		for(int i=1;i<=N;i++)
		{
			if((p+i-1)->cell==str)
				key=0;
		}
		return key;
	} 
} 
void printAll(person* p)
{
	int num=0;
	for(int i=0;i<=31;i++)
	{
		if((p+i)->sex!="��"&&(p+i)->name!="��"&&(p+i)->addr!="���Ϻ�")
		{
			cout<<"��"<<num+1<<"λ��ϵ�˵�������"<<(p+i)->name<<endl; 
			cout<<"��"<<num+1<<"λ��ϵ�˵ĵ绰��"<<(p+i)->cell<<endl; 
			num++; 
		}
	} 
	if(num==0)
		cout<<"����ϵ�ˣ�"<<endl;
}
void deletePerson(person* p,string cell,int* i)
{
	int location;
	if(searchSameInformation(p,*i,cell)==1)
		cout<<"���޴��ˣ������¼����ϵ�˵绰����"<<endl;
	else
	{
		for(int j=0;j<=*i;j++)
		{
			if(p[j].cell==cell)
				location=j;
		}
		p[location]={"��","��","���Ϻ�","0",0};
		*i-=1;
		cout<<"ɾ���ɹ���"<<endl;
	}
}
void searchPersonInformation(person* p,int N,string cell)
{
	int location;
	if(searchSameInformation(p,N,cell)==1)
		cout<<"���޴��ˣ������¼����ϵ�˵绰����"<<endl;
	else
	{
		for(int j=0;j<=N;j++)
		{
			if(p[j].cell==cell)
				location=j;
		}
		cout<<"���ǵ�"<<location+1<<"λ��ϵ��"<<endl;
		cout<<"������"<<p[location].name<<endl;
		cout<<"�Ա�"<<p[location].sex<<endl;
		cout<<"�ֻ��绰��"<<p[location].cell<<endl;
		cout<<"סַ��"<<p[location].addr<<endl;
		cout<<"���䣺"<<p[location].age<<endl;
	} 
}
void changeIformation(person* p,int N,string cell)
{
	int location,option_sex;
	if(searchSameInformation(p,N,cell)==1)
		cout<<"���޴��ˣ������¼����ϵ�˵绰����"<<endl;
	else
	{
		for(int i=0;i<=N;i++)
		{
			if((p+i)->cell==cell)
				location=i;
		}
		cout<<"������������"<<endl; 
		cin>>p[location].name;
		cout<<"�������Ա�"<<endl<<"1 -- ��"<<endl<<"2 -- Ů"<<endl; 
		cin>>option_sex;
		switch(option_sex)
		{
			case 1:
				p[location].sex="��";break;
			default:
				p[location].sex="Ů";break;
		} 
		cout<<"���������䣺"<<endl;
		cin>>p[location].age; 
		cout<<"��������ϵ�绰��"<<endl;
		cin>>cell; 
		if(searchSameInformation(p,N,cell)==1)
		{
			p[location].cell=cell;
			cout<<"�������ͥסַ��"<<endl;
			cin>>p[location].addr;
			cout<<"�޸ĳɹ���"<<endl;
		}
		else
			cout<<"��λ�û�������ϵ��ϵͳ�У������¼���޸���ϵ����Ϣ��"<<endl; 
	}
} 
