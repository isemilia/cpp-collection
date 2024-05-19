#include <iostream>
#include <ctime>

using namespace std;

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;

int user_choice;
int comp_choice;

void get_comp_choice(int comp_choice){
    if(comp_choice == ROCK){
        cout << "rock" << endl; 
    }else if(comp_choice == PAPER){
        cout << "paper" << endl;
    }else if(comp_choice == SCISSORS){
        cout << "scissors" << endl;
    }
}

void find_winner(int user, int comp){
    if(user == ROCK && comp == PAPER){
        cout << "Computer win! Paper wraps rock." << endl;
    }else if(user == ROCK && comp == SCISSORS){
        cout <<  "You win! Rock beats scissors." << endl;
    }else if(user == PAPER && comp == ROCK){
        cout << "You win! Paper wraps rock." << endl;
    }else if(user == PAPER && comp == SCISSORS){
        cout << "Computer win! Scissors cut paper." << endl;
    }else if(user == SCISSORS && comp == ROCK){
        cout << "Computer win! Rock beats scissors." << endl;
    }else if(user == SCISSORS && comp == PAPER){
        cout << "You win! Scissors cut paper." << endl;
    }else{
        cout << "Tie." << endl;
    }
}

int main(){
    cout << "Game menu\n---------" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;

    cout << "\nYour choice: ";
    cin >> user_choice;

    srand(time(NULL));
    comp_choice = rand()%3+1;

    cout << "Computer choice: ";
    get_comp_choice(comp_choice);

    cout << endl;

    find_winner(user_choice, comp_choice);

    return 0;
}