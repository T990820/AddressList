#include<iostream>
#include"function.h"
using namespace std;
int main()
{
	showMenu();
	person people[1000];
	for(int i;i=0;i<1000)
	{
		people[i]={"��","��","���Ϻ�","0",0};
	}
	int option,i=0,option_sex,off_on=1,deleteAll=0;//i��ʾ��ǰϵͳ����ϵ�˸��� 
	string cell;
	while(off_on)
	{
		cin>>option;
		switch(option)
		{
			case 1:
				cout<<"������������"<<endl; 
				cin>>people[i].name;
				cout<<"�������Ա�"<<endl<<"1 -- ��"<<endl<<"2 -- Ů"<<endl; 
				cin>>option_sex;
				switch(option_sex)
				{
					case 1:
						people[i].sex="��";break;
					default:
						people[i].sex="Ů";break;
				} 
				cout<<"���������䣺"<<endl;
				cin>>people[i].age; 
				cout<<"��������ϵ�绰��"<<endl;
				cin>>cell; 
				if(searchSameInformation(people,i,cell)==1)
				{
					people[i].cell=cell;
					cout<<"�������ͥסַ��"<<endl;
					cin>>people[i].addr;
					cout<<"��ӳɹ���"<<endl;
					i+=1;break;//break��ʾ����switch(option)ѭ�� 
				}	 
				else
					cout<<"��Ϣ�ظ�¼�룬�����¼���½���ϵ����Ϣ��"<<endl;break;
			case 2:
				printAll(people,i);
				break;
			case 3:
				cout<<"��������Ҫɾ�����ֻ��ţ�"<<endl;
				cin>>cell; 
				deletePerson(people,cell,&i);
				break;
			case 4:
				cout<<"��������Ҫ���ҵ��ֻ��ţ�"<<endl;
				cin>>cell; 
				searchPersonInformation(people,i,cell); 
				break;
			case 5:
				cout<<"��������Ҫ�޸���ϵ�˵��ֻ��ţ�"<<endl;
				cin>>cell;
				changeIformation(people,i,cell);
				break;
			case 6:
				cout<<"��ȷ��Ҫɾ��������ϵ�˵���Ϣ��" <<endl<<"1 -- ȷ��"<<endl<<"2 -- ȡ��"<<endl;
				cin>>deleteAll;
				switch(deleteAll)
				{
					case 1:
						for(int i;i=0;i<1000)
						{
							people[i]={"��","��","���Ϻ�","0",0};
						}
						i=0;
					case 2:
						break;
				}
				break;
			default:
				cout<<"��ӭ���ٴ�ʹ�ã�"<<endl; 
				off_on=0;
				break;
		} 
	}
}
