#include<iostream>
#include<string>

struct Specialization
{
    std::string value;
    explicit Specialization(const std::string& new_value)
    {
        value = new_value;
    }
};

struct Course
{
    std::string value;
    explicit Course(const std::string& new_value)
    {
        value = new_value;
    }
};

struct Week
{
    std::string value;
    explicit Week(const std::string& new_value)
    {
        value = new_value;
    }
};

struct LectureTitle
{
    std::string specialization;
    std::string course;
    std::string week;

    explicit LectureTitle(const Specialization& spec, const Course& cours, const Week& week_const)
    {
        specialization = spec.value;
        course = cours.value;
        week = week_const.value;
    }
};

