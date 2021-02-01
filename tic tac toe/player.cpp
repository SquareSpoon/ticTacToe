#include <iostream>
#include "player.hpp"

std::string board[9]= {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;
void introduction(){
  std::cout << "aperte o Enter para jogar :" << '\n';
  std::cin.ignore();

  std::cout << '\n';

  std::cout << "===========" << '\n';
  std::cout << "tic tac toe" << '\n';
  std::cout << "===========" << '\n';
  
  std::cout << "player1) X" << '\n';
  std::cout << "player2) O" << '\n';

  std::cout << '\n';

  std::cout << "       |       |       " << '\n';
  std::cout << "   1   |   2   |   3   " << '\n';
  std::cout << "-----------------------" << '\n';
  std::cout << "       |       |       " << '\n';
  std::cout << "   4   |   5   |   6   " << '\n';
  std::cout << "-----------------------" << '\n';
  std::cout << "       |       |       " << '\n';
  std::cout << "   7   |   8   |   9   " << '\n';

  std::cout << '\n';
  

}


bool filled(){
  bool filled = false;
  int count= 0;
  for(int i = 0; i < 9; i++){
    if(board[i] != " ") {
      count++;
    }
  }
  if(count == 9){
    filled = true;
  }
  return filled;
}

void position1(){
  std::cout << "Player " << player << " digite um número valido na tabela (1, 9): " ;
  while(!(std::cin >> position)) {
      std::cout << "Player " << player << " digite um número valido na tabela (1, 9): " ;
      std::cin.clear();
      std::cin.ignore();
    }
    
  

  std::cout << '\n';

  while(board[position-1] != " "){
    std::cout << "Player " << player << " parece que ja existe esse numero na tabela! " << '\n';
    std::cout << '\n';

    std::cout << "Player " << player << " digite um número valido na tabela (1, 9): " ;
    std::cin >> position;
    std::cout << '\n';

    
  }
}

void update(){
  if(player == 1){
    board[position-1] = "X";
  } else {
    board[position-1] = "O";
  }
}

void change(){
  if(player == 1){
    player++;
  } else {
    player--;
  }
}

bool winner(){
  bool winner = false;
  if((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " "){
    winner = true;
  } else if((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " "){
    winner = true;
  } else if((board[6] == board[7]) && (board[7] == board[8]) && board[6] != " "){
    winner = true;
  } else if((board[0] == board[3]) && (board[3] == board[6]) && board[0] != " "){
    winner = true;
  } else if((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " "){
    winner = true;
  } else if((board[2] == board[5]) && (board[5] == board[7]) && board[2] != " "){
    winner = true;
  } else if((board[0] == board[4]) && (board[4] == board[8]) && board[0] != " "){
    winner = true;
  } else if((board[2] == board[4]) && (board[4] == board[6]) && board[2] != " "){
    winner = true;
  }
  return winner;
}

void show(){
  std::cout << "     |          |       " << '\n';
  std::cout << board[0] <<"    |    " << board[1] << "     |    " << board[2]  << '\n';
  std::cout << "-----------------------" << '\n';
  std::cout << board[3] <<"    |    " << board[4] << "     |    " << board[5]  << '\n';
  std::cout << "-----------------------" << '\n';
  std::cout << "     |          |       " << '\n';
  std::cout << board[6] <<"    |    " << board[7] << "     |    " << board[8]  << '\n';
}

void turn(){
  while(!winner() && !filled()){
    position1();
    update();
    change();
    show();
  }
}

void end(){
  if(winner()){
    std::cout << "temos un vencedor!!" << '\n';

  } else if(filled()){
    std::cout << "tivemos um empate!" << '\n';
  }
}