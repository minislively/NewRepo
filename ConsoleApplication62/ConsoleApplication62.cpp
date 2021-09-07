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
	Person(const char myname[], int myage) // 생성자
	{
		int len = strlen(myname) + 1; // stlen() 문자열 길이 + 널 문자 
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
		Sleep(1000); //1초
	}
};

int main()
{
	Person man1("박얼", 16);
	Person man2("이찬", 57);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	system("pause");
	return 0;
}