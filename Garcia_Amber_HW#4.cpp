//Amber Garcia HW#4
// 8 queens on a board problem with goto statements and 1d array
// 9/25/19
#include <iostream>
using namespace std;
int amount = 0;
int main(){

  int q[8], c = 0;
  q[0] = 0;

  NC: c++;
    if(c == 8){
      goto PRINT;
    }
    q[c] = -1;
  NR: q[c]++;

  if(q[c] == 8){goto BT;}
    for(int i = 0; i < c; i++){
      if(q[i] == q[c] || (c-i) == abs(q[c] - q[i])){goto NR;}
    }
  goto NC;

  BT: c--;
  if(c<0){exit(0);}
  goto NR;

  PRINT:
    cout << "Solution" << ++amount << endl;
    cout << "----------------" << endl;
    for(int i = 0; i < 8; i++){
      cout << "|";
      for(int k = 0; k < 8; k++){
        if(q[i] == k){
          cout << "X|";
        }else{
          cout << "0|";
        }
      }
      cout << endl;
    }
    goto BT;

}
