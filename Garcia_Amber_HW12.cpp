//Amber Garcia HW#12
// Tower of Hanoi ODD + EVEN without recursion
// 11/30/19

#include <iostream>
#include <vector>
using namespace std;

vector<int> t[3];
int ring_number = 0;
int move_NUM = 0;
int from = 0;
int to = 0;
int select_ring = 1;

void print_tsolution(int ring, int tower1, int tower2){
  cout << "Move " << ++move_NUM << ": Move ring " << ring << " from " << char(tower1+65) << " to " << char(tower2+65) << endl;
  //Move ring x from tower y to tower z
}
void calc_tohanoi(int ring_num){
  for(int i = ring_num+1; i>0; i--){
      t[0].push_back(i);
  }

  t[1].push_back(ring_num+1);
  t[2].push_back(ring_num+1);

  //initialize 'to'
  if(ring_num % 2 == 1){ to = 1; }else{to = 2;}

  while(t[1].size() < ring_num+1){

    print_tsolution(select_ring, from, to);
    t[to].push_back(t[from].back());
    t[from].pop_back();
    //ODD
    if(ring_num%2 == 1){
      if(t[(to+1)%3].back() < t[(to+2)%3].back()){
        from = (to+1)%3;
      }else{
        from = (to+2)%3;
      }

      if(t[(from)%3].back() < t[(from+1)%3].back()){
        to = (from+1)%3;
      }else{
        to = (from+2)%3;
      }
      select_ring = t[from].back();

    }else{
      //EVEN
      if(t[(to+1)%3].back() < t[(to+2)%3].back()){
        from = (to+1)%3;
      }else{
        from = (to+2)%3;
      }
      if(t[(from)%3].back() < t[(from+2)%3].back()){
        to = (from+2)%3;
      }else{
        to = (from+1)%3;
      }
      select_ring = t[from].back();
    }

    }

}

int main(){

  cout << "How many rings: ";
  cin >> ring_number;

  calc_tohanoi(ring_number);
  return 0;
}
