#include <iostream>

using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //поле

char current_marker; //текущий маркер (х или о)
int current_player; //текущий игрок (1 или 2)

void printBoard() //вывести поле на консоль
{
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "-----------\n";
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "-----------\n";
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void placeMarker(int slot) //сделать ход
{
	int row, col; 
	if(slot%3==0)
		row = (slot/3)-1; //если остаток делени€ номера €чейки на 3 равен 0, 
	else                  //то индекс строки равен номер €чейки/3 - 1 (6/3-1=1)
	     row = slot/3;
	
	if(slot%3==0)
		col = 2; //если остаток делени€ номера €чейки на 3 равен 0, то индекс столбца равен 2
	else 
		col = (slot%3)-1;  //в противном случае - остаток делени€ €чейки на 3 - 1 (7%3-1=0)
	
	if(board[row][col] == 'X' || board[row][col] == 'O') //проверить свободна ли выбранна€ €чейка
	{
		cout << "\aError! That slot is occupied." << endl;
		cout << "Player " << current_player << "'s turn. Enter your slot: ";
		cin >> slot;
		placeMarker(slot);
	}
	else 
	{
		board[row][col] = current_marker;
	}
}

int winner() //определить победител€
{
	for(int i=0; i<3; i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return current_player;
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return current_player;
	}
	
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return current_player;
	if(board[0][2] == board[1][1] && board [1][1] == board[2][0])
		return current_player;
		
	return 0;
}

void swapPlayerAndMarker()  //переключение между игроками, смена х на о и наоборот
{
	if(current_marker == 'X')  
		current_marker = 'O';
	else
		current_marker = 'X';
		
	if(current_player == 1)
		current_player = 2;
	else
		current_player = 1;			
}

void game() //начало игры
{
	cout << "Player 1, choose your marker(X or O): ";
	char marker_p1;
	cin >> marker_p1;
	
	cout << "\n\n";
	system("CLS");
	
	printBoard();
	
	current_player = 1;
	current_marker = marker_p1;
	
	int player_won;
	
	for(int i=0; i<9; i++)
	{
		cout << "Player " << current_player << "'s turn. Enter your slot: ";
		int slot;
		cin >> slot;
		
		if(slot<10 && slot>0)
		{
			placeMarker(slot);
		}
		else
		{
			cout << "\aError! That slot does not exist." << endl;
			cout << "Player " << current_player << "'s turn. Enter your slot: ";
			cin >> slot;
			placeMarker(slot);
		}
		
		player_won = winner();
		
		swapPlayerAndMarker();
		system("CLS");
		printBoard();
		
		if(player_won == 1)
		{
			cout << "Player 1 won!" << endl;
			break;
		}
		if(player_won == 2)
		{
			cout << "Player 2 won!" << endl;
			break;
		}
		
	}
	if(player_won == 0)
		cout << "It's a tie!" << endl;
}

int main()
{
	printBoard();
	
	game();
	
	cin.ignore();
	cin.get();
	
	return 0;
}
