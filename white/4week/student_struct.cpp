#include<iostream>
#include<vector>
#include<string>

struct Student
{
    std::string first_name;
    std::string last_name;
    
    int day;
    int month;
    int year;
};

Student fill_student(const std::string& name, const std::string& last_name, int day, int month, int year)
{
    Student men;
    men.first_name = name;
    men.last_name = last_name;
    men.day = day;
    men.month = month;
    men.year = year;

    return men;
}

void PrintName(Student men)
{
    std::cout << men.first_name << " " << men.last_name << std::endl;
}

void PrintDateOfBirth(Student men)
{
    std::cout << men.day << "." << men.month << "." << men.year << std::endl;
}

int main()
{
    int N;
    int M;
    int num_student;
    int day;
    int month; 
    int year;
    
    std::string command;
    std::string f_name;
    std::string l_name;
    std::vector<Student> student_list;
   
    std::cin >> N;
     
    for(int i = 0; i < N; ++i)
    {
        std::cin >> f_name >> l_name >> day >> month >> year;
        student_list.push_back(fill_student(f_name, l_name, day, month, year));
    }

//    std::cout << "end of record" << std::endl;

    std::cin >> M;
    
    for(int i = 0; i < M; ++i)
    {
        std::cin >> command >> num_student;
        
        if(command == "name" and num_student > 0 and num_student < N+1)
        {
//            std::cout << "in if_name" << std::endl;
//            std::cin >> num_student;
            PrintName(student_list[num_student-1]);
        } else if(command == "date" and num_student > 0 and num_student < N+1)
        {
//            std::cin >> num_student;
            PrintDateOfBirth(student_list[num_student-1]);
        } else
        {
            std::cout << "bad request" << std::endl;
        }
    }

    return 0;
}
