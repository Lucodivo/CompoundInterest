//A simple C++ program for compound interest 
//that might also use monthly compounding

#include <iostream>

double compoundInterest(double initialValue, float percentRate, int numYears, bool isCompMonthly);

int main(){
	//interest variables
	double initialInvestment;
	float investmentRate;
	int yearsToInvest;
	char isCompoundMonthly;

	//end investment after calculation
	double endInvestment;

	//acquiring input from user
	std::cout << "input your initial investment" << std::endl;
	std::cin >> initialInvestment;
	std::cout << "input the investment rate[ex: input \"2\" for a 2% rate]" << std::endl;
	std::cin >> investmentRate;
	std::cout << "input the amount of years to invest" << std::endl;
	std::cin >> yearsToInvest;
	std::cout << "input \"y\" for monthly compound or \"n\" for simple annual compound" << std::endl;
	std::cin >> isCompoundMonthly;

	//calculation changes on whether it should be compounded monthly or not	
	if (isCompoundMonthly == 'y' || isCompoundMonthly == 'Y'){
		endInvestment = compoundInterest(initialInvestment, investmentRate, yearsToInvest, true);
	}
	else{
		endInvestment = compoundInterest(initialInvestment, investmentRate, yearsToInvest, false);
	}

	//quick truncation to display only 2 decimal places
	endInvestment = (int)(endInvestment /= .01) * .01;
	
	//inform user of the end investment
	std::cout << "Your end investment will be: $" << endInvestment << std::endl;
}

//recursive function to calculate compound interest
double compoundInterest(double initialValue, float percentRate, int numYears, bool isCompMonthly){
	if (isCompMonthly){
		numYears *= 12;
		percentRate /= (float)12.0;
	}
	if(numYears){
		initialValue += (initialValue * (.01 * percentRate));
		numYears--;
		return compoundInterest(initialValue, percentRate, numYears, false);
	}
	else{
		return initialValue;
	}
}
