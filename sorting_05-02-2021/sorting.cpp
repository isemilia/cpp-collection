#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v){
	
	for(int i = 0; i < v.size(); i++){
		
		cout << v.at(i) << " ";
	}
	cout << endl;
}

int swap(int* a, int* b){
	
	int temp = *a;
	*a = *b;
	*b = temp;
	
	return 0;
}

int sorting(vector<int> &v){
	
	for (auto i = 0; i < v.size(); i++){
		
        for (auto j = 0; j < v.size(); j++){
        	
            if(v.at(i) < v.at(j)){
            	
                swap(&v.at(i), &v.at(j));
            }
        }   
    }
	return 0;
}

int getMin(vector<int> &v){
	int min = v.at(0);

	for (int i = 0; i < v.size(); i++){
		if(v.at(i)<min){
			min = v.at(i);
		}
	}
	return min;
}

int getMax(vector<int> &v){
	int max = v.at(0);

	for (int i = 0; i < v.size(); i++){
		if(v.at(i)>max){
			max = v.at(i);
		}
	}
	return max;
}

int main(){
	
	vector<int> data = {12, 19, 15, 16, 21, 20, 7};
	
	printVector(data);
	
	cout << "\nThe smallest number is " << getMin(data) << endl;
	cout << "The largest number is " << getMax(data) << endl;
	
	cout << endl;

	sorting(data);
	
	printVector(data);
	
	return 0;
}
