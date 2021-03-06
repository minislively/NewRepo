#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char myname[], int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person() // 소멸자
	{
		delete[] name;
		cout << "destructor is called!" << endl;
		Sleep(1000);
	}
};

int main()
{
	Person man1("박진수", 15);
	Person man2("이민", 18);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	system("pause");

	return 0;
}