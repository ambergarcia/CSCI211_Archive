//Amber Garcia HW#5
// 8 queens on a board problem without goto statements
// 10/8/19

#include <iostream>
using namespace std;
int amount = 0;
//--------------------------------------------------------------------------------------------------------------
void print_queensboard(int given_array[]){
  cout << "Solution" << ++amount << endl;
  cout << "----------------" << endl;
  for(int i = 0; i < 8; i++){
    cout << "|";
    for(int k = 0; k < 8; k++){
      if(given_array[i] == k){
        cout << "X|";
      }else{
        cout << "0|";
      }
    }
    cout << endl;
  }
}
//--------------------------------------------------------------------------------------------------------------
bool ok_function_for_queensboard(int given_array[], int current_column){
  for(int i = 0; i < current_column; i++){
    if(given_array[i] == given_array[current_column] || (current_column-i) == abs(given_array[current_column] - given_array[i])){
      return false;
    }
  }
  return true;
}
//--------------------------------------------------------------------------------------------------------------
int main(){
  int q[8] = {0}, c = 0;
  while(c>=0){
    //NC
    c++;
    if(c == 8){
      print_queensboard(q);
      c--;
    }else{q[c] = -1;}
    //NR
    while(c>=0){
      q[c]++;
      if(q[c] == 8){
        c--;
      }else if(ok_function_for_queensboard(q, c)){break;}
    }
  }
}
//--------------------------------------------------------------------------------------------------------------
