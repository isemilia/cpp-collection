#include <iostream>
#include <ctime> //for time()
#include <cstdlib> //for srand() and rand()

int answer; //declare variables. all of them are global æ
int guess;
int count = 0;
int points_earned;
int points;
int choice;

int guessing(int); //declare functions (their definitions are at the bottom)
void start();
void menu();

int main() {
	
	std::cout << "Welcome to the guessing game." << std::endl;
	
	srand(time(0)); //initialize random number generator
	answer = rand() % 10 + 1; //generate a random number
	
	start();

	guessing(guess);	
	
	std::cout << "\nExit" << std::endl;
	
	std::cin.get();
	
	return 0;
}

int guessing(int guess){
	if(guess == answer){
		std::cout << "\nCorrect! The answer is: " << answer << std::endl;
		
		points_earned = guess == answer ? 10 : 0; //you get 10 points if you get the number right
		std::cout << "\nPoints earned: " << points_earned << std::endl; 
	
		points = points+points_earned; //your current number of points + points earned(10 if you get the number right) 
		std::cout << "Your total score is: " << points << std::endl;
			
		menu();
				
	}else if(guess > answer){
		std::cout << "\nYour guess is too high.";
		
		count = count + 1; //you have a limited number of attempts - 3
			
		if(count <=2){
			std::cout << "\nTry again: ";
			std::cin >> guess;
			guessing(guess);
		}else if(count>2){
			std::cout << "\nYou haven't guessed it. The answer is: " << answer << std::endl;
			
			points_earned = guess == answer ? 10 : 0; //you get 10 points if you get the number right
			std::cout << "\nPoints earned: " << points_earned << std::endl;
	
			points = points+points_earned; //your current number of points + points earned(10 if you get the number right)
			std::cout << "Your total score is: " << points << std::endl;
			
			menu();
		}
	}else if(guess < answer){
		std::cout << "\nYour guess is too low.";
		
		count = count + 1; //you have a limited number of attempts - 3
		
		if(count <=2){
			std::cout << "\nTry again: ";
			std::cin >> guess;
			guessing(guess);
		}else if(count>2){
			std::cout << "\nYou haven't guessed it. The answer is: " << answer << std::endl;
			
			points_earned = guess == answer ? 10 : 0; //you get 10 points if you get the number right
			std::cout << "\nPoints earned: " << points_earned << std::endl;
	
			points = points+points_earned; //your current number of points + points earned(10 if you get the number right)
			std::cout << "Your total score is: " << points << std::endl;
			
			menu(); 
		}
	}
		
	return 0;
}

void start(){
	std::cout << "\nGuess the number from 1 to 10: ";
	std::cin >> guess; //get user input(guess)
}

void menu(){
	std::cout << "\nPlay again? \n0.Play \n1.Quit" << std::endl;
	std::cout << "\nYour choice: ";
	std::cin >> choice;	//choose what to do next, either play again or quit
	
	switch(choice){
		case 0: //play again			
			answer = 0;
			guess = 0;
			count = 0;
			choice = 0; //set the variables back to zero
			
			srand(time(0)); //initialize random number generator
			answer = rand() % 10 + 1; //generate a random number
			
			start();
			
			guessing(guess);
			break;
		case 1: //quit
			std::cout << "\nGame over." << std::endl; 
			break;
	}
}
