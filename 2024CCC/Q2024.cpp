#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
  int number;
  int length;


  cin>>number>>length;
  char check[number];


  for(int x = 0;x< number;x++){
    string word;
    unordered_map<char,int> vect;
    cin>>word;
    for(int y = 0;y<length;y++){
      vect[word[y]] += 1;
    }
    int current_status = 1;
    int result = 1;
    if(vect[word[0]] != 1){
      current_status = 0;
    }

    //
    for(int y = 0;y<length;y++){

      if(vect[word[y]] == 1){
        if(current_status != 1){
          result = 0;

        }


      }
      if(vect[word[y]] > 1){
        if(current_status != 0){
          result = 0;


        }

      }
      if(current_status == 1){
        current_status = 0;
      }
      else if(current_status == 0){
        current_status = 1;
      }
    }
   //

    if(result == 1){
      check[x] = 'T';
    }
    else{
      check[x] = 'F';
    }



  }
  for(int i= 0;i < number;i++){
    cout<<check[i]<<endl;
  }

}