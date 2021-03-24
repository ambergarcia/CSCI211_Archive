//Amber Garcia HW#1
// Overflow [No solution to problem as intended, crashes after reaching limit]
// 9/11/19
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

void findOddSquare(){
  unsigned long long count_sq = 1;
  while(count_sq > 0){
    if(count_sq*count_sq < 100 && (count_sq*count_sq % 100) / 10 != 0 && ((count_sq*count_sq % 10) % 2 != 0) && (((count_sq*count_sq % 100) / 10) % 2) != 0){
        cout << ((count_sq*count_sq % 100) / 10) % 2 << endl;
        cout << count_sq << " squared is equal to " << count_sq*count_sq << " and the last two digits are odd.";

        break;
    }
    //cout << "There is no solution to this problem, it will continue forever and crash computer.
    //     << If using a smaller byte object, like 'int', it would print a negative number but it will not be a perfect square with the last
    //     << 2 digits being odd." << endl;
    count_sq++;
  }
}

int main(){

  findOddSquare();
}
