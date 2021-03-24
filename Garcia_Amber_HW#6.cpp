//Amber Garcia HW#6
// Cross Test Algorithm 
// 10/16/19
#include <iostream>
using namespace std;


//Currently there are multiple problems/tiny things that I wanted to fix, but I couldn't figure out in time.
// For example, I would have done the print_cross function a lot better, but I needed to see the end result of
// The while loop.
// At the moment, I do not think the helper array aligns with the expected result either.
// Though, it does make sure that the same numbers are not adjacent, so it's probably just a problem with my current loop.

void print_cross(int cross[]){
  cout << "Solution" << endl;
  cout << "----------------" << endl;
  int line = 0;
  /*
  [1][4]
[0][2][5][7]
  [3][6]
  current format used for the boxes
  */
  for(int line = 0; line < 3; line++){
    if(line == 0 || line == 2){
      cout << "   ";
      if(line ==0){
        cout << "[" << cross[1] << "]" << "[" << cross[4] << "]";
      }else{
        cout << "[" << cross[3] << "]" << "[" << cross[6] << "]";
      }
      cout << endl;
    }else{
      cout << "[" << cross[0] << "]" << "[" << cross[2] << "]" << "[" << cross[5] << "]" << "[" << cross[7] << "]";
      cout << endl;
    }
  }

}
//--------------------------------------------------------------------------------------------------------------
bool ok(int helper[][5], int c, int cross[]){
  //finding adjacent squares
  for(int i = 0; i < c; i++){
    if(cross[i] == cross[c]){return false;}
}
  for(int i = 0; helper[c][i] != -1; i++){
    if(abs(cross[c] - cross[helper[c][i]] == 1)){return false;}
  }
  return true;

}
//--------------------------------------------------------------------------------------------------------------

int main(){

  int helper_array[8][5]{
    {-1},//0
    {-1},//1
    {-1},//2
    {0,1,-1},//3
    {0,2,3,-1},//4
    {0,2,3,-1},//5
    {0,1,2,4,-1},//6
    {0,1,2,5,-1},//7
  };


  int cross_test[8] = {3};
  //intended result starts with 3
  int b = 0;
  while(b>=0){
    if(b == 7){
      print_cross(cross_test);
      return 0;
    }
    if(ok(helper_array, b, cross_test)){
      b++;
    }else{
      cross_test[b]++;
      }
    }
}
