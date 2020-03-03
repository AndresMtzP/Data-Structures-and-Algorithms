/*/////////////////////////////////////////////////////////////////////////////////
// Class Chef is a child class of class salaryEmployee, it includes an explicit
// value constructor, mutators, a calculateSalary function and a display function
// private data members is a string special
/////////////////////////////////////////////////////////////////////////////////*/
using namespace std;

#ifndef CHEF_H
#define CHEF_H

//inherit from Salaryemployee
class Chef : public Salaryemployee
{
    public:
        Chef(string first="", string last="", int id=0,  //explicit value constructor
             double sal=0, double percent=0, string sp="");
        void setName(string first, string last);   //mutator setName
        void setID(int id);   //mutator setID
        void setSalary(double s);   //mutator setSalary
        void setSalesPercent(double percent);   //mutator setSalesPercent
        void setSpecial(string sp);   //mutator setSpecial
        void display(ostream & out) const;   //display function
    private:
        string special;
};

//explicit value constructor calls SalaryEmployee's constructor, sets type to C
inline Chef::Chef(string first, string last, int id,
                  double sal, double percent, string sp)
        :Salaryemployee(first, last, id, 'C', sal, percent), special(sp)
{
}

inline void Chef::setName(string first, string last)
{
    Salaryemployee::setName(first, last);   //call setName on Salaryemployee
}

inline void Chef::setID(int id)
{
    Salaryemployee::setID(id);   //call setID on Salaryemployee
}

inline void Chef::setSalary(double s)
{
    Salaryemployee::setSalary(s);   //call setSalary on Salaryemployee
}

inline void Chef::setSalesPercent(double percent)
{
    Salaryemployee::setSalesPercent(percent);   //call setSalesPercent on Salaryemployee
}

inline void Chef::setSpecial(string sp)
{
    special=sp;   //set special
}

//display function calls display on SalaryEmployee
inline void Chef::display(ostream & out) const
{
    Salaryemployee::display(out);
    out<<setw(18) <<"// Special: "<< special;
    //follow graphic interface
    for(int i=0; i<(50-special.length()); i++)
    {
        out<<" ";
    }
    out<<"//"<<endl;
}

#endif // CHEF_H
