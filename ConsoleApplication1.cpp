#include <iostream> 
#include <string>  

using namespace std;



class GradeBook
{
    ​​​​
public:

    void setCourseName(string name)
    {
        ​​​​
            if (name != "")
            {
                ​​​​
                    courseName = name;
            }​​​​
            else
            {
                ​​​​
                    puts("姓名不得為空白");
            }​​​​
    }​​​​
        void setCourseAge(int age)
            {
                ​​​​
                    if (age >= 0 && age < 20)
                    {
                        ​​​​
                            courseAge = age;
                    }​​​​
                    else
                    {
                        ​​​​
                            puts("年齡須小於20");
                    }​​​​
            }​​​​





private:
    string courseName;
    int courseAge;
}​​​​;



int main(void)
{
    ​​​​
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



    if (nameOfCourse == "Y")
    {
        ​​​​
            myGradeBook.setCourseName(nameOfCourse);
        cout << endl;
    }​​​​
    else
    {
       ​​​
            puts("取消");
    }​​​​
}​​​​