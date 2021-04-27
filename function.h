#include<iostream>
using namespace std;
struct person
{
	string sex;
	string name;
	string addr;
	string cell;
	int age;
};
void showMenu(void);
int searchSameInformation(person* p,int N,string str);
void printAll(person* p,int N);
void deletePerson(person* p,string cell,int* i);
void searchPersonInformation(person* p,int N,string str);
void changeIformation(person* p,int N,string cell);
