#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Player{
int line;
int row;
};

struct Field{
char field;
};

struct Board{
vector<vector<Field>> board;
};

bool checkInputX(Player X){

   if(X.line >= 0 && X.line <= 2 && X.row >= 0 && X.row <= 4){
     return true;
  }
  return false;
}
bool checkInputO(Player O){
  if(O.line >= 0 && O.line <= 2 && O.row >= 0 && O.row <= 4){
    return true;
  }
  return false;
}
bool checkForWinner(vector<Board>board){

  for(int i = 0; i < 3; i++){
    if(board[0].board[i][0].field == 'X' && board[0].board[i][2].field == 'X' && board[0].board[i][4].field == 'X' || board[0].board[i][0].field == 'O' && board[0].board[i][2].field == 'O' && board[0].board[i][4].field == 'O'){
      return true;
    }
  }
  for(int i = 0; i < 5; i += 2){
    if(board[0].board[0][i].field == 'X' && board[0].board[1][i].field == 'X' && board[0].board[2][i].field == 'X' || board[0].board[0][i].field == 'O' && board[0].board[1][i].field == 'O' && board[0].board[2][i].field == 'O'){
      return true;
    }
  }
  if(board[0].board[0][0].field == 'X' && board[0].board[1][2].field == 'X' && board[0].board[2][4].field == 'X' || board[0].board[0][0].field == 'O' && board[0].board[1][2].field == 'O' && board[0].board[2][4].field == 'O'){
    return true;
  }
  if(board[0].board[0][4].field == 'X' && board[0].board[1][2].field == 'X' && board[0].board[2][0].field == 'X' || board[0].board[0][4].field == 'O' && board[0].board[1][2].field == 'O' && board[0].board[2][0].field == 'O'){
    return true;
  }
  return false;
}
bool checkForFieldUseX(vector<Board>board, Player X){

  if(board[0].board[X.line][X.row].field == '_'){
    return true;
  }
  return false;
}
bool checkForFieldUseO(vector<Board>board, Player O){
  if(board[0].board[O.line][O.row].field == '_'){
    return true;
  }
  return false;
}
void game(int numbersOfGames, vector<Board> board, vector<Board> copyBoard){
  
  int i = 0;
  int counterX = 0;
  int counterO = 0;
  while(i < numbersOfGames){
    int inputCounter = 0;
    cout<<"Game "<< i + 1 <<" starting..."<<'\n'<<'\n';
    
    while(checkForWinner(board) == false){

    bool isNumberGood = false;
    
    Player X,O;
      
    cout<<"Player X:"<<'\n'<<'\n';
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      cout << board[0].board[i][j].field;
    }
    cout << endl;
    }
    cout<<endl;
      
      // Player X
      while (!isNumberGood) {
        if (cin >> X.line, cin >> X.row) {
          if(X.row == 1){
          X.row += 1;
          } else if(X.row == 2){
          X.row += 2;
          } else if(X.row == 3){
            X.row += 3;
          } else if(X.row == 4){
            X.row += 4;
          }
          if (checkInputX(X) == true && checkForFieldUseX(board, X) == true) {
            inputCounter++;
            isNumberGood = true;
          } else if(checkInputX(X) == true && checkForFieldUseX(board, X) == false) {
          cout << "Field is used! Try again!" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } else if(checkInputX(X) == false){
            cout << "Incorrect input! Try again!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
        } else {
          cout << "Incorrect input! Try again!" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      } isNumberGood = false;
    
    
    board[0].board[X.line][X.row].field = 'X'; // ispisuje X
    
   
    if(checkForWinner(board)){
      counterX++;
      if(counterX == 1){
          cout<<"Player X won!"<< " Player X has "<< counterX<< " win"<<'\n'<<'\n';
        } else{
          cout<<"Player X won!"<< " Player X has "<< counterX<< " wins"<<'\n'<<'\n';
        }
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
        cout << board[0].board[i][j].field;
        }
      cout << endl;
      }
      cout<<endl;
      continue;
    }
      
    // Player O
    cout<<"Player O:"<<'\n'<<'\n';
  
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      cout << board[0].board[i][j].field;
    }
    cout << endl;
    }
    cout<<endl;
      if(inputCounter == 9){
        cout<<"Game is draw!"<<'\n'<<'\n';
        break;
      }
    while (!isNumberGood) {
        if (cin >> O.line, cin >> O.row) {
          if(O.row == 1){
          O.row += 1;
          } else if(O.row == 2) {
          O.row += 2;
          } else if(O.row == 3){
            O.row += 3;
          } else if(O.row == 4){
            O.row += 4;
          }
          if (checkInputO(O) == true && checkForFieldUseO(board, O) == true) {
            inputCounter++;
            isNumberGood = true;
          } 
          else if(checkInputX(X) == true && checkForFieldUseX(board, X) == false) {
            cout << "Field is used! Try again!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } else if(checkInputO(O) == false){
            cout << "Incorrect input! Try again!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
        } else {
          cout << "Incorrect input! Try again" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      } isNumberGood = false;
      
      board[0].board[O.line][O.row].field = 'O'; // ispisuje O
         
      if(checkForWinner(board)){
        counterO++;
        if(counterO == 1){
          cout<<"Player O won!"<< " Player O has "<< counterO<< " win"<<'\n'<<'\n';
        } else{
          cout<<"Player O won!"<< " Player O has "<< counterO<< " wins"<<'\n'<<'\n';
        }
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 5; j++) {
          cout << board[0].board[i][j].field;
          }
        cout << endl;
        }
        cout<<endl;
        continue;
      }
    
    }
    i++;
    board = copyBoard;
    inputCounter = 0;
  }
  cout<< "Result: X ("<<counterX<<") O ("<<counterO<<")"<<endl;
}

void board(int numbersOfGames){

  int counter = 0;
  vector<Board> board, copyBoard;
  vector<vector<Field>> line;
  for(int i = 0; i < 3; i++){
    vector<Field>row;
    row.push_back({'_'});
    row.push_back({'|'});
    row.push_back({'_'});
    row.push_back({'|'});
    row.push_back({'_'});
    line.push_back({row});
    counter++;

    if(counter == 3){
      board.push_back({line});
    }
  }
  copyBoard = board;
  game(numbersOfGames, board, copyBoard);
}

int main() {
 int numbersOfGames;
  bool inputReadSuccessfully = false;
  while (!inputReadSuccessfully) {
    cout << "Enter number of matches you want to play: "<<endl;
    if (cin >> numbersOfGames) {
      if (numbersOfGames > 0 && numbersOfGames < 11) {
        inputReadSuccessfully = true;
      } else if(numbersOfGames < 0){
        cout << "Invalid input! Please enter a positive integer." << endl<< endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else if(numbersOfGames < 0 || numbersOfGames > 10){
            cout << "Incorrect input! Try again!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
    } else {
      cout << "Incorrect number of games! Please try again." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
  board(numbersOfGames);
}