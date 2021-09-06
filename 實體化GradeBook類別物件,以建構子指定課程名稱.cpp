// 實體化GradeBook類別物件,以建構子指定課程名稱.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<string>
using namespace std;

class GradeBook
{
public:
	explicit GradeBook(string name):Name(name){}
	explicit GradeBook(int age) :Age(age) {}


	void set(string name)
	{
		Name = name;
	}
	void set2(int age)
	{
		Age = age;
	}
	string getName()const
	{
		if (Name != " ")
		{
			return Name;
		}
		else
		{
			puts("!!!請輸入姓名資料!!!");
		}
	}
	int getAge() const
	{
		if (Age > 0 && Age <= 20)
		{
			return Age;
		}
		else
		{
			puts("!!!請輸入年齡範圍為1-20!!!");
		}
	}
	
private:
	string Name;
	int Age;
};

int main()
{

	string nameofPet;
	int ageofPet;
	string y;

	cout << "\n請輸入寵物名 : " << endl;
	getline(cin, nameofPet);
	GradeBook gradeBook1(nameofPet);

	cout << "請輸入寵物年齡:\n " << endl;
	cin >> ageofPet;
	GradeBook gradeBook2(ageofPet);
	
	cout << "\n輸入Y為印出列表:";
	cin >> y;
	if (y != "Y")
	{
		cout << "\n";
	}
	else
	{
		cout << "寵物名 :" << gradeBook1.getName()

			<< "\n寵物年齡 " << gradeBook2.getAge() << endl;
	}

}

