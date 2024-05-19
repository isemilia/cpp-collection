#include <iostream>

int choice;
int choice2;
double c;
double f;
double k;

double ctof(double c){
	double f = (c*9/5)+32;
	return f;
}

double ftoc(double f){
	double c = (f-32)*5/9;
	return c;
}

double ftok(double f){
	double k = (f-32)*5/9+273.15;
	return k;
}

double ctok(double c){
	double k = c+273.15;
	return k;
}

double ktoc(double k){
	double c = k-273.15;
	return c;
}

double ktof(double k){
	double f = ((k-273.15)*9/5)+32;
	
	return f;
}
void menu();
void switchcase();

int main(){
	std::cout << "Temperature converter.\n";
	
	menu();
	switchcase();
	
	std::cin.ignore();
	std::cin.get();
	
	return 0;
}

void menu(){
	std::cout << "\nChoose option:" << std::endl;
	std::cout << "0. Celsius to Fahrenheit. \n1. Fahrenheit to Celsius." << std::endl;
	std::cout << "2. Fahrenheit to Kelvin. \n3. Celsius to Kelvin." << std::endl;
	std::cout << "4. Kelvin to Celsius. \n5. Kelvin to Fahrenheit." << std::endl;
	std::cout << "\nYour choice: ";
	std::cin >> choice;
}

void menu2(){
	std::cout << "\n\nChoose next action:" << std::endl;
	std::cout << "0. Again. \n1. Quit." << std::endl;
	std::cout << "\nYour choice: ";
	std::cin >> choice2;
	
	switch(choice2){
		case 0:
			menu();
			switchcase();
			break;
		case 1:
			std::cout << "\nDone." << std::endl;
			break;
		default:
			std::cout << "\n\aInvalid option.";
			menu2();
			break;	
	}
}

void switchcase(){
	switch(choice){
		case 0:
			std::cout << "\nEnter temperature in Celsius: ";
			std::cin >> c;
			
			std::cout << "Temperature in Fahrenheit: " << ctof(c);
			
			menu2();
			break;
		case 1:
			std::cout << "\nEnter temperature in Fahrenheit: ";
			std::cin >> f;
			
			std::cout << "Temperature in Celsius: " << ftoc(f);
			
			menu2();
			break;
		case 2:
			std::cout << "\nEnter temperature in Fahrenheit: ";
			std::cin >> f;
			
			std::cout << "Temperature in Kelvin: " << ftok(f);
			
			menu2();
			break;
		case 3:
			std::cout << "\nEnter temperature in Celsius: ";
			std::cin >> c;
			
			std::cout << "\nTemperature in Kelvin: " << ctok(c);
			
			menu2();
			break;
		case 4:
			std::cout << "\nEnter temperature in Kelvin: ";
			std::cin >> k;
	
			std::cout << "Temperature in Celsius: " << ktoc(k);
			
			menu2();
			break;
		case 5:
			std::cout << "\nEnter temperature in Kelvin: ";
			std::cin >> k;
			
			std::cout << "Temperature in Fahrenheit: " << ktof(k);
			
			menu2();
			break;
		default:
			std::cout << "\n\aInvalid option.";
			
			menu2();
			break;
	}
}
