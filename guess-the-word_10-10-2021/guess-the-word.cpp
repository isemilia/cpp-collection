#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

string getWord(vector<string> v){
	srand(time(NULL));
	int rand_index = rand()%v.size();
	
	return v.at(rand_index);
}

vector<string> words = {"computer", "internet", "browser", "google", "system", "database", "programming",
			"food", "burrito", "taco", "borsch", "vareniki", "pelmeni", "barbecue", "lasagna", "pizza", "sushi",
			"school", "class", "mathematics", "philosophy", "physics", "biology", "chemistry", "history",
			"russia", "mexico", "kazakhstan", "japan", "italy", "germany", "england", "france", "canada",
			"instagram", "facebook", "youtube", "twitter", "discord", "spotify", "telegram",
			"apple", "orange", "grapefruit", "pear", "tomato", "potato", "cucumber", "eggplant", "onion", "raspberry", "strawberry",
			"helicopter", "individual", "professor", "administrator", "moderator", "classification", "astonishment", "sensitivity",
			"republic", "universe", "discovery", "adventure", "distance", "happiness", "mousepad", "musician", "composer",
			"question", "wonder", "superstition", "belief", "television", "architecture", "engineering", "development"};
	
string word = getWord(words);
string hidden_word = word;

int mistake = 7;

void checkLetter(char guess){
	int count = 0;
	for(int i=0; i<word.size();i++){
		if(word.at(i) == guess){
			hidden_word.at(i) = guess;
			count++;
		}
	}
	
	if(count==0){
		cout << "Letter " << guess << " does not exist!" << endl;
		mistake--;
		cout << "Free mistakes left: " << mistake << endl;
		//Sleep(1000);
	}
}

void printHiddenWord(){
	for(int i=0; i<word.size(); i++){
		cout << hidden_word.at(i) << " ";
	}
}

void printWord(){
	for(int i=0; i<word.size(); i++){
		cout << word.at(i) << " ";
	}
}
int main(){
	
	for(int i=0; i<word.size(); i++){
		hidden_word.at(i) = '_';
	}
	
	do{
	   	printHiddenWord();
	
	   	cout << "\nTake a guess: ";
	   	char guess;
		cin >> guess;
	
		checkLetter(guess);
	
		cout << "\n";
	
		//system("CLS");	
	
	}while(hidden_word!=word && mistake>0);
	
	if(mistake>0){
		printWord();
		cout << "\nCongratulations! The word was " << word;
	}else{
		printHiddenWord();
		cout << "\nYou lose. The word was " << word;
	}
	
	cin.ignore();
	cin.get();
	
	return 0;
}
