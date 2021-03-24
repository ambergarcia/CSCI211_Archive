//Amber Garcia HW#7
// Marriage Problem
// 10/23/19
#include <iostream>
using namespace std;
int amount = 0;
//This code does not work correctly, but it does run. I do think the problem is with some of the
//decisions within the backtracking. In comments at the very bottom, was a second attempt at fixing
// the problem with just while loops, but I messed that up as well.
//---------------------------------------------------------------------------------------

bool ok(int q[], int fem_pref[][3], int male_pref[][3], int c){
  for(int i = 0; i < c; i++){
    if(q[i] == q[c]){return false;}
    if(male_pref[i][q[c]] < male_pref[i][q[i]] && fem_pref[q[c]][i] < fem_pref[q[c]][c]){return false;}
    if(male_pref[c][q[i]] < male_pref[c][q[c]] && fem_pref[q[i]][c] < fem_pref[q[i]][i]){return false;}
  }

  /*for(int i = 0; i < c; i++){

  }

  for(int i = 0; i < c; i++){

  }*/

  return true;
}

void print_possibility(int array[], int size){
  cout << "-=-=-=-=-=-=-=-=-" << endl;
  cout<< "Solution #" << " " << ++amount << endl;
  cout << "Man" << "    " << "Woman" << endl;
  for(int i = 0; i < size; i++){
   cout << i << "      " << array[i] << endl;
 }
 cout << "-=-=-=-=-=-=-=-=-" << endl;
}

//---------------------------------------------------------------------------------------
/*Pseudo Code:
1: Go through q[] function to read each mans and woman
2: use ok function to set values
3: use.. utube
*/
//---------------------------------------------------------------------------------------

int main(){

  int mp[3][3] = {
    {0,2,1}, //man1 = index num
    {2,1,0}, //man2
    {1,2,2}, //man3

  };
  //man pref
  int wp[3][3] = {
    {0,1,2}, //woman1 = index num
    {2,1,1}, //woman2
    {0,2,1},//woman3
  };
  //woman pref
  int q_fem[3] = {0, 0, 0};
  int c_man = 0;
  /*
    >q[i] is current woman
    >q[c] is new woman
    >q[2] woman number

    >i is current man
    >c is new man
    >2 number man
  */
//using backtracking?

/*------------------------------------------------------------------------*/
  NC: c_man++;
    if(c_man == 3){goto PR;}
    q_fem[c_man]=-1;/*reset the woman pref.*/
    cout << "entered NC" << c_man << "+" << q_fem[c_man] <<  endl;
/*------------------------------------------------------------------------*/
  NR: q_fem[c_man]++;
    cout << "entered NR" << c_man << "+" << q_fem[c_man] << endl;
    if(q_fem[c_man] == 3){
      //if statement might be wrong
      q_fem[c_man]--;
      //once it goes to BT, then back to NR, it will instantly become 2? hmm
      goto BT;
    }
    if(ok(q_fem,wp,mp,c_man)){goto NR;}
    goto NC;
/*------------------------------------------------------------------------*/
  BT: c_man--;
  cout << "entered bt" << c_man << "+" << q_fem[c_man] <<  endl;
  if(c_man<0){exit(0);}
  goto NR;
/*------------------------------------------------------------------------*/
  PR:
    cout << "entered print" << c_man << "+" << q_fem[c_man] <<  endl;
    print_possibility(q_fem, 3);
    goto BT;
/*------------------------------------------------------------------------*/
/*c = c_man
q = q_fem*/
/*while(c>=0 && c<3){

  c++;
  if(c == 3){
    //print(q);
    c--;
  }else{
    //do i need this hhm
    //q[c] = -1;}

}
  while(c>=0 && c<3){
    //go through preference arrays
    q[c]++;
    //check next woman, then check compatibility with man
    if(q[c] == 3){
      q[c]--;
      c--;

    }else if(ok(q, c)){break;}
  }
}*/

}
