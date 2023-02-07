#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Student{
    public:
    Student(string x):name(x){}
    void addCourse(string x){courses.push_back(x);}
    bool hasCourse(string x){
        if(find( courses.cbegin(), courses.cend(), x )!=courses.cend())
            return true;
        else return false;}
    string getName(){return name;}
    vector<string>& getCourses(){
        return courses;
    }
    string toString(){
        string s;
        s="student "+name+" with courses of ";
        for ( auto i= courses.cbegin(); i<courses.cend()-1; i++ )
            s=s+ *i + " and ";
        s+=*(courses.cend()-1);
        return s;
    }
    private:
    string name;
    vector<string> courses;
};
class TA: public Student{
    public:
    TA(string x):Student(x){}
    void addAssistantCourse(string x){assitant.push_back(x);}
    void printTakenCorses(){
        vector<string> c=getCourses();
        for ( auto i= c.cbegin(); i<c.cend(); i++ )
            cout<<*i<<" ";
        return;
    }
    string toString(){
        string s;
        s=Student::toString();
        s+=", assists in ";
        for ( auto i= assitant.cbegin(); i<assitant.cend()-1; i++ )
            s=s+ *i + " and ";
        s+=*(assitant.cend()-1);
        return s;
    }
    private:
    vector<string> assitant;
};
int main(){
    Student s("ali");
    TA t("mina");
    t.addCourse("physics");
    t.addCourse("math2");
    t.addAssistantCourse("programming1");
    t.addAssistantCourse("math1");
    cout<<t.toString();
    cout<<"\n*****\n";
    t.printTakenCorses();
    return 0;
}