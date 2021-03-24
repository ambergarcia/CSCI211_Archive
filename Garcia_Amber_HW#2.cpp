//Amber Garcia HW#2
// adding two large strings of integers together
// 9/11/19
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

string add(string a, string b){
  //---------------------------------------------------------------------------------
  //Initializing the variables
  string longest, smallest, store_long_string_end, result;
  if(a.size() > b.size()){
    longest = a;
    smallest = b;
  }else{
    longest = b;
    smallest = a;
  }
  if(smallest.size() != longest.size()){
    store_long_string_end = longest.substr(0, longest.size() - smallest.size());
    longest = longest.substr(store_long_string_end.size(), longest.size() - 1);
  }else{
    store_long_string_end = " ";
  }
  int index = longest.size() - 1;
 //---------------------------------------------------------------------------------
 // Addition properties with the smallest + longest
  while(index >= 0){
    //This section is 'alright', maybe can shrink most of the if statements...
    if(longest[index] - '0' + smallest[index] - '0' > 9 && index >= 0){
        if(index == longest.size() - 1){
            result += char(((((smallest[index] - '0') + (longest[index] - '0')) % 10) + 48));
            index--;
        }
        if(index >= 0 && longest[index + 1] - '0' + smallest[index + 1] - '0' > 9 ){
            result += char(((((smallest[index] - '0') + (longest[index] - '0')) % 10) + 49));
            index--;
        }
        if(index >= 0 && smallest[index] != 9 && longest[index + 1] - '0' + smallest[index + 1] - '0' > 9){
            result += char(((((smallest[index] - '0') + (longest[index] - '0')) % 10) + 49));
            index--;
        }else if(smallest[index] == 9 && longest[index] == 9 && index >= 0){
            result += char(((((smallest[index] - '0') + (longest[index] - '0')) % 10) + 49));
            index--;
        }else if(index >= 0){

            result += char(((((smallest[index] - '0') + (longest[index] - '0')) % 10) + 48));
            index--;
        }
        }else{
            if(index >= 0 && longest[index + 1] - '0' + smallest[index + 1] - '0' > 9 ){
              result += char(((smallest[index] - '0') + (longest[index] - '0')) + 49);
              index--;
            }else{
              result += char(((smallest[index] - '0') + (longest[index] - '0')) + 48);
              index--;
            }
        }
  }
  //---------------------------------------------------------------------------------
  //Adding on store_long_string_end to the 'result'
  index = store_long_string_end.size() - 1;
  int temp = 0;
  while(result.size() != (store_long_string_end + longest).size() && index >= 0){
      if(smallest[0] - '0' + longest[0] - '0' <= 9){
        break;
      }
      //This section could definitely be improved, since it might create horrible errors
      if(smallest[0] - '0' + longest[0] - '0' > 9 && temp > -1){
        if(store_long_string_end[index] - '0' == 9 && result.size() < (store_long_string_end + longest).size()){
          result += char(48);
          index--;
        }
        if(store_long_string_end[index] - '0' == 0 && index == 0 && result.size() >= (store_long_string_end + longest).size() && temp != -1){
          result += char(49);
          index--;
          temp = -1;
        }

        if(result.size() >= (store_long_string_end + longest).size() && store_long_string_end[index] - '0' < 9 && temp != -1){
          result += char(((smallest[0] - '0' + longest[0] - '0') / 10) + 48);
          index--;
          temp = -1;
        }else if(result.size() == longest.size()){
          result += char(((smallest[0] - '0' + longest[0] - '0') / 10) + 48);
          index--;
          temp = -1;
        }
        if(store_long_string_end[index] - '0' < 9 && temp != -1 ){
          result += char((store_long_string_end[index] - '0') + 49);
          index--;
          temp = -1;
        }

      }else{
        result += char((store_long_string_end[index] - '0') + 48);
        index--;
      }

    }
    //---------------------------------------------------------------------------------
    //Reverse result [It starts off backwards]
    // Straight forward
    string reverse_result;
    for(int u = result.size() - 1; u >= 0; u--){
      if(u - 1 == -1){
        reverse_result += result[u];
        break;
      }
      reverse_result += result[u];
    }

    if(smallest[0] - '0' + longest[0] - '0' <= 9){
      reverse_result = store_long_string_end + reverse_result;
    }
    return reverse_result;
}

int main(){
    string user_input1 = "";
    string user_input2 = "";
    while(user_input1 != "done"){
      cout << "Please enter a positive integer a [enter 'done' to exit]: ";
      cin >> user_input1;
      if(user_input1 == "done"){
        cout << "Ending program...";
        break;
      }
      cout << endl;
      cout << "Please enter a positive integer b: ";
      cin >> user_input2;
      cout << endl;

      cout << "Addition is: " << add(user_input1, user_input2) << "." << endl;
    }
}
