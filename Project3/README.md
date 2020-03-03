# Project 3 - Staque Program

## Computer Engineering 260 (Data Structures and Algorithms) at San Diego State University

This program implements class Staque, which is a combination of a stack and a sueue. The program
displays a menu with the current staque, and several options asking the user what he/she wants to do
to the staque. The choices for the user are: 1. Add a number or numbers to the staque,
2. Delete an even number from the staque, 3. Delete an odd number from the staque, or 4. Exit the program.
If the user chooses option 1, he or she is asked to input the number or numbers he or she wants to add to the
staque. The algorithm used stores a whole line input into a string, analyzes and uses the acceptable inputs
and ignores the rest. The staque accepts any integer, negative or positive. The staque follos the LIFO
(Last In First Out) rule, if the number is an even number, the staque behaves like a stack and pushes and pops
numbers form the front of the staque, if it is odd, the staque will act as queue and push and pop numbers from
the back of the staque.