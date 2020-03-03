/*/////////////////////////////////////////////////////////////////////////////////
// Class HourlyEmployee is a child class of class Employee, it includes an explicit
// value constructor, mutators, a calculateSalary function and a display function
// private data members is a double MonthlySalary, and an int, years
/////////////////////////////////////////////////////////////////////////////////*/
using namespace std;

#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

//inherit from class Employee
class HourlyEmployee : public Employee
{
    public:
        HourlyEmployee(string first="", string last="", int id=0,  //explicit value constructor
                       double monthlySal=0, int years=0);
        void setName(string first, string last);   //mutator setName
        void setID(int id);    //mutator setID
        void setMonthSalary(double monthly);   //mutator setMonthSalary
        void setYears(int years);    //mutator setYears
        double calculateSalary(double tips);  //calculateSalary function
        void display(ostream & out) const;   //display function
    private:
        double monthlySalary;
        int years;
};

//explicit value constructor calls Employee's cosntructor and sets type to W
inline HourlyEmployee::HourlyEmployee(string first, string last, int id,
                                           double monthlySal, int years)
        :Employee(first, last, id, 'W'), monthlySalary(monthlySal), years(years)
{
}

inline void HourlyEmployee::setName(string first, string last)
{
    Employee::setName(first, last);  //call employee's setName
}

inline void HourlyEmployee::setID(int id)
{
    Employee::setID(id);  //call employee's setID
}

inline void HourlyEmployee::setMonthSalary(double monthly)
{
    monthlySalary=monthly;   //set MonthlySalary
}


inline void HourlyEmployee::setYears(int years)
{
    years=years;   //set years of experience
}

inline double HourlyEmployee::calculateSalary(double tips)
{
    return monthlySalary+tips;  //calculate waiter's salary
}

//display function calls Employee's display and displays the rest of the info in an organized manner
inline void HourlyEmployee::display(ostream & out) const
{
    Employee::display(out);
    int length,
        c=monthlySalary;
    if(c<10)
        length=1;
    else{
        for(length=0; c>1; length++) //calculate the length of Monthly salary and years
            c=c/10;
    }
    if(years<10)
        length++;
    else
        length=length+2;
    out <<setw(25)<< "// Monthly Salary: ";
    out <<fixed<<setprecision(2)<< monthlySalary;
    out << "   Years of experience: "<< years;
    for(int i=0; i<(16-length); i++)
        out<<" ";
    out<<"//"<<endl;

}

#endif // HOURLYEMPLOYEE_H
