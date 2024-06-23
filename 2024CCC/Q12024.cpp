#include <iostream>
using namespace std;
int main() {
  int number;
  cin>>number;
  int halfone[number/2];
  int halftwo[number/2];

  int count = 0;
  for(int x = 0;x < number/2;x++){
    cin>>halfone[x];
  }
  for(int x = 0;x < number/2;x++){
    cin>>halftwo[x];
  }

  for(int x = 0;x< number/2;x++){
    if(halfone[x] == halftwo[x]){
      count++;
    }
  }
  cout<<count * 2;

}