//Amber Garcia HW#3
// 8 queens on a board problem problem with goto statements and 2d array
// 9/25/19
#include <iostream>
using namespace std;
int amount = 0;
int main(){

  int b [8][8], r = 0, c = 0;

  b[0][0] = 1;

  NC: c++;
    if(c == 8){
      goto PRINT;
      cout << c << " Column"<< endl;
    }
    r = -1;
  NR: r++;

  if(r == 8){goto BT;}
    for(int i = 0; i < c; i++){
      if(b[r][i] == 1){goto NR;}
    }
    //up diagonal
    for(int i = 0; r-i >= 0; i++){
      if(b[r-i][c-i] == 1){goto NR;}
    }
    //down diagonal

    for(int i = 1; r+i < 8 && c-i >=0; i++){
      if(b[r+i][c-i] == 1){goto NR;}
    }
  b[r][c] = 1;
  goto NC;

  BT: c--;

  if(c<0){exit(0);}
  r=0;
  while(b[r][c] != 1){
    r++;

  }
  b[r][c] = 0;
  goto NR;

  PRINT: //2 forloops
    cout << "Solution" << ++amount << endl;
    cout << "----------------" << endl;
    for(int i = 0; i < 8; i++){
      cout << "|";
      for(int k = 0; k < 8; k++){
        if(b[i][k] == 1){
          cout << "X|";
        }else{
          cout << "0|";
        }

      }
      cout << endl;

    }
    goto BT;

}
