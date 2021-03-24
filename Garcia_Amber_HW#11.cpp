//Amber Garcia HW#11
// N Queens Board Problem
// 11/30/19

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n_queens = 0;
int amount = 0;
//KEPT the printing board function
void print_q(int que_sol[], int size){
  cout << "Solution" << ++amount << endl;
  cout << "----------------" << endl;
  for(int i = 0; i < size; i++){
    cout << "|";
    for(int k = 0; k < size; k++){
      if(que_sol[i] == k){
        cout << "X|";
      }else{
        cout << "0|";
      }
    }
    cout << endl;
  }
}
//Function to print total solution amount
void print_solutionnum(int a_num, int q_num){
  cout << "---------------------------------------------------" << endl;
  cout << "There are " << a_num << " solutions to the " << q_num << " Queens problem." << endl;
  cout << "---------------------------------------------------" << endl;
}

bool ok(int que[], int c){
  for(int i = 0; i < c; i++){
    if(que[i] == que[c] || (c-i) == abs(que[c] - que[i])){
      return false;
    }
  }
  return true;
}
void queens_calculate(int n){
  int col = 0;
  int* q = new int[n];
  //now we have vague amount N.
  //n queens on board size n^n

  //1-d loop
  while(col>=0){
    //NC
    col++;
    if(col == n){
      print_q(q, n);
      col--;
    }else{q[col] = -1;}
    //NR
    while(col>=0){
      q[col]++;
      if(q[col] == n){
        col--;
      }else if(ok(q, col)){break;}
    }
  }

  delete []q;

}

int main(){
  cout << "Enter a queens amount: ";
  cin >> n_queens;
  queens_calculate(n_queens);
  print_solutionnum(amount,n_queens);

}
