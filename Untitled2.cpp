#include<iostream>
#include<ctime>
#include<random>

using namespace std;

char board[9] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };

void viewboard();
void get_x_playerchoice();
void get_o_playerchoice();
void getcomputerchoice();
int countboard(char symbol);
char checkwinner();
void computervsplayer();
void playervsplayer();




int main()
{
	system("cls");
	int mode;
	
	cout<<"Press 1. For Computer VS Player " <<endl;
	cout<<"Press 2. For Player VS Player   " <<endl;
	cout<<"Select Your CHOICE: ";
	cin>>mode;
	
	switch(mode){
		case 1 : 
				computervsplayer();
				break;
		case 2 : 
				playervsplayer();
				break;
		default :
			cout<<"Please Select a valid choice";
			break;
	}	
	return 0;
	
}

void computervsplayer()  //using this function user can play with computer
{
	string playername;
	
	cout<<"Enter Your Name: ";
	cin>>playername;
	
	while (true) 
	{
		system("cls");
		viewboard();
		
		if(countboard('X') == countboard('O')){
			cout<<playername<<"'s Turn. " <<endl;
			get_x_playerchoice();
		}
		
		else{
			getcomputerchoice();
		}
		
		char winner = checkwinner();
		
		if(winner == 'X'){
			system("cls");
			viewboard();
			cout<<playername<<"Won The game "<<endl;
			break;
		}
		
		else if (winner == 'O'){
			system("cls");
			viewboard();
			cout<<"Coumpter won the game"<<endl;
			break;
		}
		
		else if(winner == 'D'){
			cout<<"Game is Draw"<<endl;
			break;
		}
	}
		
}

void playervsplayer()  //using this function user can play with user
{
	string xplayer, oplayer;
	
	cout<<"Enter X player Name: ";
	cin>>xplayer;
	cout<<"Enter Y player Name";
	cin>>oplayer;
	
	while(true){
		system("cls");
		viewboard();
		if(countboard('X') == countboard('O')){
			cout<<xplayer<<"'s Turn. " <<endl;
			get_x_playerchoice();
		}
		
		else{
			cout<<oplayer<<"'s Turn" <<endl;
			get_o_playerchoice();
		}
		
	   char winner = checkwinner();
	   
	   if(winner == 'X'){
	   	system("cls");
	   	viewboard();
	   	cout<<xplayer<<" WON THE GAME" << endl;
	   	break;
	   }	
	   else if(winner == 'O'){
	   	system("cls");
	   	viewboard();
	   	cout<<oplayer<<" WON THE GAME" <<endl;
	   	break;
	   }
	   else if(winner == 'D'){
	   	system("cls");
	   	viewboard();
	   	cout<<"The Game is Draw!!"<<endl;
	   }	
	}
}

void viewboard(){		// using this function we'll view our board
	cout << "    " << "   |   " << "   |  "<<endl;
	cout << "    " <<board[0] << "  |  " <<board[1] << "   |  " <<board[2]<<endl;
	cout << "    " << "   |   " << "   |  "<<endl;
	cout << "----------------------" <<endl;
	cout << "    " << "   |   " << "   |  "<<endl;
	cout << "    " <<board[3] << "  |  " <<board[4] << "   |  " <<board[5]<<endl;
	cout << "    " << "   |   " << "   |  "<<endl;
	cout << "----------------------" <<endl;
	cout << "    " << "   |   " << "   |  "<<endl;
	cout << "    " <<board[6] << "  |  " <<board[7] << "   |  " <<board[8]<<endl;
	cout << "    " << "   |   " << "   |  "<<endl;
}

void getcomputerchoice(){  // using this function we'll get computer choice

	srand(time(0));
	
	int choice;
	
	do{
		choice = rand() % 9;
	}while (board[choice] != ' ');
	
	board[choice] = 'O';
}


void get_x_playerchoice(){ //using this function we'll get 'X' player choice

	while(true)
	{
		cout<<"Select Your Position between (1 to 9): ";
		int choice;
		cin>>choice;
		choice--;
		
	if (choice < 0 || choice > 8)
	 { 
			cout<<"Please Select your choice between 1 to 9: "<< endl;
	 }
	else if (board[choice] != ' ')
	 {
		cout<<" Please Select Empty Position "<<endl;
	 }
	
	else
	 {
	 	 board[choice] = 'X';
	 	 break;
	 }
	}

	
}

void get_o_playerchoice(){ //using this function we'll get 'X' player choice

	while(true)
	{
		cout<<"Select Your Position between (1 to 9): ";
		int choice;
		cin>>choice;
		choice--;
		
	if (choice < 0 || choice > 8)
	 { 
			cout<<"Please Select your choice between 1 to 9: "<< endl;
	 }
	else if (board[choice] != ' ')
	 {
		cout<<" Please Select Empty Position "<<endl;
	 }
	
	else
	 {
	 	 board[choice] = 'O';
	 	 break;
	 }
	}

}


int countboard(char symbol){
	int total,i;
	
	for(i=0;i<9;i++)
	{
		if(board[i] == symbol){
			total += 1;
		}
	 
	}
	 return total;
}

char checkwinner()
{
	// checking winner horizontally
	if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
			return board[0];
			
	if(board[3] == board[4] && board[4] == board[5] && board[4] != ' ')
			return board[3];
			
	if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
			return board[6];
			
	//checking winner vertically
	
	if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
			return board[0];
			
	if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
			return board[1];
			
	if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
			return board[2];
			
	//checking winner diognally
	
	if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
			return board[0];
			
	if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
			return board[2];
			
	if(countboard('X') + countboard('O') < 9)
			return 'C';
	else
		return 'D';
}
