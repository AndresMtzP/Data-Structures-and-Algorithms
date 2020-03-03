/*/////////////////////////////////////////////////////////////////////////////////
// Class salary employee is a child class of class employee, it includes an explicit
// value constructor, mutators, a calculateSalary function and a display function
// private data members are two doubles, salary and salesPercent
/////////////////////////////////////////////////////////////////////////////////*/
using namespace std;

#ifndef SALARYEMPLOYEE_H
#define SALARYEMPLOYEE_H

// inherit from employee
class Salaryemployee : public Employee
{
    public:
        Salaryemployee(string first="", string last="", int id=0,   //explicit value constructor
                       char type=' ', double sal=0, double percent=0);
        void setName(string first, string last);  //mutator setName
        void setID(int id);   //mutator SetID
        void setType(char type);  //mutator setType
        void setSalary(double s);   //mutator setSalary
        void setSalesPercent(double percent);  //mutator setSalesPercent
        double calculateSalary(double totalSales);   //calculateSalary
        virtual void display(ostream & out) const;    //display function
    private:
        double salary,
               salesPercent;
};


//explcit value constructor calls employee's constructor as well as a class invariant for a correct Sales percentage
inline Salaryemployee::Salaryemployee(string first, string last, int id,
                                      char type, double sal, double percent)
        :Employee(first, last, id, type), salary(sal)
{
    if(percent>=0 && percent <=100){
        salesPercent=percent;
    }else{
            cout<<setw(70)<<"//  ***Sales percent is not correct, will be set to zero***   //"<<endl;
    }
}

inline void Salaryemployee::setName(string first, string last)
{
    Employee::setName(first, last);  //call setName on Employee
}

inline void Salaryemployee::setID(int id)
{
    Employee::setID(id);    //call setID on Employee
}

inline void Salaryemployee::setType(char type)
{
    Employee::setType(type);   //call setType on Employee
}

inline void Salaryemployee::setSalary(double s)
{
    salary=s;  //set salary
}

inline void Salaryemployee::setSalesPercent(double percent)
{
    salesPercent=percent;  //set sales percentage
}

inline double Salaryemployee::calculateSalary(double totalSales)
{
    return (salary + (totalSales*(salesPercent/100)));  //calculate salary for a salaried employee
}


inline void Salaryemployee::display(ostream & out) const
{
    //follow algorithm to display info in an organized manner following the graphic interface
    Employee::display(out);
    int length,
        c=salary;
    if(salary<10)
        length=1;
    else{
        for(length=0; c>1; length++)  //calculate length of salary
        {
            c=c/10;
        }
    }
    out <<setw(17)<<"// Salary: ";
    out<<fixed<<showpoint<<setprecision(2)<<  salary;
    out << "  Sales Percentage: ";
    if(salesPercent<10)
        out<<"0";
    out<<salesPercent<<"% ";
    for(int i=0 ; i<(20-length); i++)
        out<<" ";
    out<<"//"<<endl;
}

#endif // OWNER_H

