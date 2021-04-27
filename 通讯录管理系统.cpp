#include<iostream>
#include<string> 
#include"function.h"
using namespace std;
int main()
{
	showMenu();
	person people[32]={{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0},{"中","中","中南海","0",0}};
	int option,i=0,option_sex,off_on=1,deleteAll=0;//i表示当前系统中联系人个数 
	string cell;
	while(off_on)
	{
		cin>>option;
		switch(option)
		{
			case 1:
				cout<<"请输入姓名："<<endl;
				cin>>people[i].name;
				cout<<"请输入性别："<<endl<<"1 -- 男"<<endl<<"2 -- 女"<<endl;
				cin>>option_sex;
				while(option_sex!=1&&option_sex!=2)
				{
					cout<<"输入错误，请重新检查新建联系人信息！"<<endl;
					cin>>option_sex;
				}
				switch(option_sex)
				{
					case 1:
						people[i].sex="男";break;
					case 2:
						people[i].sex="女";break;
				} 
				cout<<"请输入年龄："<<endl;
				cin>>people[i].age; 
				cout<<"请输入联系电话："<<endl;
				cin>>cell; 
				if(searchSameInformation(people,i,cell)==1)
				{
					people[i].cell=cell;
					cout<<"请输入家庭住址："<<endl;
					cin>>people[i].addr;
					cout<<"添加成功！"<<endl;
					i+=1;break;//break表示跳出switch(option)循环 
				}	 
				else
					cout<<"信息重复录入，请重新检查新建联系人信息！"<<endl;break;
			case 2:
				printAll(people);
				break;
			case 3:
				cout<<"请输入想要删除的手机号："<<endl;
				cin>>cell; 
				deletePerson(people,cell,&i);
				break;
			case 4:
				cout<<"请输入想要查找的手机号："<<endl;
				cin>>cell; 
				searchPersonInformation(people,i,cell); 
				break;
			case 5:
				cout<<"请输入想要修改联系人的手机号："<<endl;
				cin>>cell;
				changeIformation(people,i,cell);
				break;
			case 6:
				cout<<"您确定要删除所有联系人的信息吗？" <<endl<<"1 -- 确定"<<endl<<"2 -- 取消"<<endl;
				cin>>deleteAll;
				switch(deleteAll)
				{
					case 1:
						for(int i;i=0;i<32)
						{
							people[i]={"中","中","中南海","0",0};
						}
						i=0;
					case 2:
						break;
				}
				break;
			case 7:
				system("cls");showMenu();break;
			default:
				cout<<"欢迎您再次使用！"<<endl; 
				off_on=0;
				break;
		} 
	}
}
