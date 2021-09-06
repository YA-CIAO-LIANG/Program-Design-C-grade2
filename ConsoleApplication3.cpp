#include <iostream>
#include <string> 
using namespace std;


class GradeBook
{
 
public:
    explicit GradeBook(string name)
        :courseName(name) 
    {

    }
   
    void set(string name)
    {
        Name = name;
    }

    void set2( int age)
    {   
        Age = age;
    }

    string getName() const
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
    string getAllow() const
    {
        if (Key !="Y")
        {
            puts("!!!停止!!!");
        }
        else
        {
            puts("為:");
        }
    }

    void displayMessage() const
    {
     
        
        cout << "寵物名 :  " << getName() << "\n寵物年齡 " << getAge() << endl;
   
    }
private:
    string Name;
    int  Age;
    string Key;
    string courseName;
};


int main()
{
    string nameOfPet;
    int ageOfPet;
    string y;
   

    cout << "\n請輸入寵物名 : " << endl;
    getline(cin, nameOfPet);
    GradeBook gradeBook1(nameOfPet);


   // cout << "請輸入寵物年齡:\n " << endl;
    //cin >> ageOfPet;
   // GradeBook gradeBook2(ageOfPet);

    cout<<"\n輸入Y為印出列表:";
    cin >> y;
    if (y != "Y")
    {
       cout << "\n"; 
    } 
   else
   {
        cout << "寵物名 :  " << gradeBook1 .getName()<< "\n寵物年齡 " <<  endl;
    }
   
}





