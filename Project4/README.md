# Project 4 - OOP Program

## Computer Engineering 260 (Data Structures and Algorithms) at San Diego State University

This program works with the concepts of polymorphism and inheritance
by simulating a database for a family restaurant. The parent class for this
program is the Employee class, this class has two derived classes, Salaryemployee
and HourlyEmployee, and SalaryEmployee has one child class Chef.
The idea for this program is to display the statistics of every employee in an organized manner
To implement this program, two linked lists were used. One, Database, which holds nodes with their Data portions
as pointers to objects of class employee. This way, The employees are stored in an organized way
The nodes of this list also hold another linked list called MonthRecords. The nodes of this list hold data for a
specific month, as well as the statistics of that month, including the total sales of the month, the tips earned,
if the employee is a waiter, and the total salary paid to the employee. These nodes also hold a pointer to the
to the same employee stored in that original node, so that each MonthRecords node has access to the data members
of the employee. The navigation for this program is a complex series of menus which allow the user to display the
current employees, and access their records to add or delete monthly records. Also, the user has the option to
search for an employee by entering the Last name or the ID number, this also gives the user access to the desired
employee's records. Finally, the user also has the option to add new employees or delete existing employees.