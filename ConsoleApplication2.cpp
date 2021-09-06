#include <iostream>
#include <string> 

using namespace std;

class GradeBook
{
public:

    void setCourseName(string name)
    {
        if (name != "")
        {
            courseName = name;
        }
        else
            throw invalid_argument
            (
                "姓名不得為空白"
            );
    }



    void setCourseAge(int age)
    {
        if (age <= 20)
        {
            courseAge = age;
        }
        else
        {

            throw invalid_argument
            (
                "年齡須小於20"
            );
        }
  

        string getCourseName(string  nameOfCourse)
        {

            if (nameOfCourse == "Y")
            {
                return courseName;
            }

            else
            {

                puts("取消");

            }

        }

    }


private:
    string courseName;
    int courseAge;



};



int main()
{
    string  courseName;
    int courseAge;
    string nameOfCourse;

    GradeBook myGradeBook;

    cout << "\n請輸入寵物名字" << endl;
    getline(cin, courseName);


    cout << "\n請輸入寵物年齡" << endl;
    cin >> courseAge;

    cout << "\nY 印出:" << endl;
    getline(cin, nameOfCourse);


    myGradeBook.setCourseName(nameOfCourse);
    cout << endl;
    // myGradeBook.displayMessage();


}