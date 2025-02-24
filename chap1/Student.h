#include <iostream>
using namespace std;
// 自定义数据类型排序

class Student{
        string name;
        int score;
    public:
        bool operator<(const Student& otherStudent){
            return score != otherStudent.score ? 
                score < otherStudent.score : name < otherStudent.name;
        }

        friend ostream& operator<<(ostream &os, const Student &student){
            os<<"Student: "<<student.name<<" "<<student.score<<endl;
            return os;
        }

        Student(std::string name, int score){
            this->name = name;
            this->score = score;
        }

};
