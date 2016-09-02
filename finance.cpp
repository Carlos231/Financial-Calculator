/****************************************
 * Program: finance.cpp
 * Author: Carlos Lopez Molina
 * Date: 1/18/2016
 * Description: Financial Calculator ofr Loan Balance, Continuously Compounded Interest and Future value.
 * Input: Numbers for which calculation they would like to make, then input their numbers into the "calculator"
 * Output: Loan Balance, Continuously Compound Interest, or Future values with whether or not they will meet their goals.
****************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int selection, goal, n, t, Co;
	double A, r, FV, i, P, B;

  //Prompt the user for what calculation they will want
	cout << endl;
	cout << "Welcome to the Financial Calculator!" << endl;
	cout << "------------------------------------" << endl;
	cout << "What would you like to calculate? Input 1 for Loan Balance, 2 for Continuously Compounded Interest or 3 for Future Value? ";
	cin >> selection;
	cout << endl;

	if (selection == 1){
		
		cout << "You have chosen Loan Balance." << endl;
		//B = A(1+i)^n - (P/i)*[(1+i)^n-1]
		
		/* 
		For checking/testing: A=18000, i=14.25, P=617.39, n=24 should result in 6866.97 
		*/
		cout << "What is the initial investment? ";
		cin >> A;
		
		cout << "What is the interest rate percent per period (month), not per year? ";
		cin >> i; //period as in months
		i = (i/12)/100;
		
		cout << "What is the amount of each equal payment($)? ";
		cin >> P;
		
		cout << "Number of time periods (months)? ";
		cin >> n;
		
		cout << "What is your goal ballance amount($)? ";
		cin >> goal;
		
		double B = A * pow((1+i), n) - (P/i) * (pow((1+i), n)-1); //double to get correct amount of decimals/cents
		
		cout << "Your future goal ballance was $" << goal << endl;
		cout << "Calculation of loan Balance after " << n << " payments have been made is $" << B << endl;
		cout << endl;
		
   //Check if will meet their goal or not
		if (goal > B){
			cout << "You will not meet your goal:(" << endl;
		}
		else if (goal <= B){
			cout << "You will meet your goal!" << endl;
		}
	}	
 
	else if (selection == 2){ //Continuously Compound Interest
		//A = Pe^rt
    		cout << "You have chosen to calculate Continuously Compounded Interest." << endl;
		
		cout << "What is the Principal Investment in dollars? ";
		cin >> P;
		
		cout << "What is the annual interest rate percent? ";
		cin >> r;
		r=r/100; //to convert percent into the decimal form
		
		cout << "How long in years will you be computing? ";
		cin >> t;
		
		cout << "What is your goal Amount in dollars by the provided time? ";
		cin >> goal;
		
		float A = P * exp(r*t);
		
		cout << endl;
		cout << "Your goal amount was $" << goal << endl;
		cout << "The actual amount after " << t << " years is $" << A << endl;
		
    //Check if user will meet their goal or not
		if (goal > A){
			cout << "You will not meet your goal." << endl;
		}
		else if (goal <= A){
			cout << "You will meet your goal." << endl;
		}
	}
 
	else if (selection == 3){
		//FV = C0*(1+r)^n
		cout << "You have chosen to calculate your Future Value." << endl;
		
		cout << "What is your starting amount? ";
		cin >> Co; //Cash flow at period 0
		
		cout << "What percent is your rate of return? ";
		cin >> r;
    		r=r/100; //convert percent into decimal form
		
		cout << "How many periods (months)? ";
		cin >> n;
		
		cout << "What is your future value goal? ";
		cin >> goal;
		
		FV = Co * pow ((1 + r), n);
		
		cout << "Your future goal was $" << goal << endl;
		cout << "Actual Future Value will be: $" << FV << endl;
		
    //check if user will meet their goal or not
		if (goal > FV){
			cout << "You will not meet your goal:(" << endl;
		}
		else if (goal <= FV){
			cout << "You will meet your goal!" << endl;
		}
	}
	return 0;
}
