
#include<iostream>
using namespace std;

int main()
{
   int choice;
   long num1, num2, x;


   cout << "Please choose your option:";
   cout << "\n1:Addition\n2:Subtraction\n3:Multiplication\n4:Division\n";
   cin >> choice;
	



	   switch (choice)
	   {
      
	      case 1:
	         cout << "Enter two numbers: \n";
	         cin >> num1 >> num2;
	         x = num1 + num2;
	         cout << "Sum = " << x;
	         break;

      
	      case 2:
	         cout << "Enter two numbers: \n";
	         cin >> num1 >> num2;
	         x = num1 - num2;
	         cout << "Subtraction = " << x;
	         break;

      
	      case 3:
	         cout << "Enter two numbers: \n";
	         cin >> num1 >> num2;
	         x = num1 * num2;
	         cout << "Product = " << x;
	         break;

      
	      case 4:
	         cout << "Enter Dividend: ";
	         cin >> num1;
	         cout << "Enter Divisor: ";
	         cin >> num2;

         }
	}
