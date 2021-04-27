#include"function.h"
#include<iostream>
#include<string>
using namespace std;
void showMenu(void)
{
	cout<<"***************************"<<endl;
	cout<<"*****"<<"1、添加联系人"<<"*****"<<endl;
	cout<<"*****"<<"2、显示联系人"<<"*****"<<endl;
	cout<<"*****"<<"3、删除联系人"<<"*****"<<endl;
	cout<<"*****"<<"4、查找联系人"<<"*****"<<endl;
	cout<<"*****"<<"5、修改联系人"<<"*****"<<endl;
	cout<<"*****"<<"6、清空联系人"<<"*****"<<endl;
	cout<<"*****"<<"7、清空显示屏"<<"*****"<<endl;
	cout<<"*****"<<"0、退出通讯录"<<"*****"<<endl;	
	cout<<"***************************"<<endl;
}
int searchSameInformation(person* p,int N,string str)//N是通讯录中人员总数 
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
		if((p+i)->sex!="中"&&(p+i)->name!="中"&&(p+i)->addr!="中南海")
		{
			cout<<"第"<<num+1<<"位联系人的姓名是"<<(p+i)->name<<endl; 
			cout<<"第"<<num+1<<"位联系人的电话是"<<(p+i)->cell<<endl; 
			num++; 
		}
	} 
	if(num==0)
		cout<<"无联系人！"<<endl;
}
void deletePerson(person* p,string cell,int* i)
{
	int location;
	if(searchSameInformation(p,*i,cell)==1)
		cout<<"查无此人！请重新检查联系人电话号码"<<endl;
	else
	{
		for(int j=0;j<=*i;j++)
		{
			if(p[j].cell==cell)
				location=j;
		}
		p[location]={"中","中","中南海","0",0};
		*i-=1;
		cout<<"删除成功！"<<endl;
	}
}
void searchPersonInformation(person* p,int N,string cell)
{
	int location;
	if(searchSameInformation(p,N,cell)==1)
		cout<<"查无此人！请重新检查联系人电话号码"<<endl;
	else
	{
		for(int j=0;j<=N;j++)
		{
			if(p[j].cell==cell)
				location=j;
		}
		cout<<"这是第"<<location+1<<"位联系人"<<endl;
		cout<<"姓名："<<p[location].name<<endl;
		cout<<"性别："<<p[location].sex<<endl;
		cout<<"手机电话："<<p[location].cell<<endl;
		cout<<"住址："<<p[location].addr<<endl;
		cout<<"年龄："<<p[location].age<<endl;
	} 
}
void changeIformation(person* p,int N,string cell)
{
	int location,option_sex;
	if(searchSameInformation(p,N,cell)==1)
		cout<<"查无此人！请重新检查联系人电话号码"<<endl;
	else
	{
		for(int i=0;i<=N;i++)
		{
			if((p+i)->cell==cell)
				location=i;
		}
		cout<<"请输入姓名："<<endl; 
		cin>>p[location].name;
		cout<<"请输入性别："<<endl<<"1 -- 男"<<endl<<"2 -- 女"<<endl; 
		cin>>option_sex;
		switch(option_sex)
		{
			case 1:
				p[location].sex="男";break;
			default:
				p[location].sex="女";break;
		} 
		cout<<"请输入年龄："<<endl;
		cin>>p[location].age; 
		cout<<"请输入联系电话："<<endl;
		cin>>cell; 
		if(searchSameInformation(p,N,cell)==1)
		{
			p[location].cell=cell;
			cout<<"请输入家庭住址："<<endl;
			cin>>p[location].addr;
			cout<<"修改成功！"<<endl;
		}
		else
			cout<<"该位用户已在联系人系统中，请重新检查修改联系人信息！"<<endl; 
	}
} 
