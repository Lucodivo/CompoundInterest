//Here is a simple C++ program I just created for compound interest 
//that might also use monthly compounding
//Not sure if it's what you were looking for but here it is! :)

#include <iostream>

double compoundInterest(double initialValue, float percentRate, int numYears, bool isCompMonthly);

int main(){
	double initialInvestment;
	float investmentRate;
	int yearsToInvest;
	char isCompoundMonthly;

	double endInvestment;

	std::cout << "input your initial investment" << std::endl;
	std::cin >> initialInvestment;
	std::cout << "input the investment rate[ex: input \"2\" for a 2% rate]" << std::endl;
	std::cin >> investmentRate;
	std::cout << "input the amount of years to invest" << std::endl;
	std::cin >> yearsToInvest;
	std::cout << "input \"y\" for monthly compound or \"n\" for simple annual compound" << std::endl;
	std::cin >> isCompoundMonthly;
	if (isCompoundMonthly == 'y' || isCompoundMonthly == 'Y'){
		endInvestment = compoundInterest(initialInvestment, investmentRate, yearsToInvest, true);
	}
	else{
		endInvestment = compoundInterest(initialInvestment, investmentRate, yearsToInvest, false);
	}

	int quickTruncation = (int)(endInvestment /= .01);
	endInvestment = quickTruncation * .01;
	std::cout << "Your end investment will be: $" << endInvestment << std::endl;
}

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