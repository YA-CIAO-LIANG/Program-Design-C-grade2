// 實體化GradeBook類別物件,以建構子指定課程名稱.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<string>


class GradeBook
{
public:
	explicit GradeBook(std::string name)
		:courseName(name)
	{

	}
	void setCourseName(std::string name)
	{
		courseName = name;
	}
	std::string getCourseName()const
	{
		return courseName;
	}
	void displayMessage() const
	{
		std::cout << "Welcome to the grade book for \n" << getCourseName() << "!" << std::endl;
	}
private:
	std::string courseName;
};

