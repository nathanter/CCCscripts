#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <regex>



using namespace std;
void art(){
  int drops;
  int commaval;

  
  cin>>drops; 
  string droppos[drops];
  int yarray[drops];
  int xarray[drops];
  for(int x = 0;x < drops;x++){
    cin>>droppos[x];
    commaval = droppos[x].find(",");
    
    xarray[x] = stoi(droppos[x].substr(0,commaval),NULL,10);
    
    yarray[x] = stoi(droppos[x].substr(commaval + 1, drops - commaval - 1),NULL,10);
    
  }
  int tempval;
  int finalxval = xarray[0];
  int finalxvall= xarray[0];
  int finalyval= yarray[0];
  int finalyvall= yarray[0];

  for(int x = 0;x < drops;x++){
    tempval = xarray[x];
    if(finalxvall < tempval){
      finalxvall = tempval;
    }
    if(finalxval > tempval){
      finalxval = tempval;
    }
  }

  tempval = yarray[0];
  for(int x = 0;x < drops;x++){
    tempval = yarray[x];
    if(finalyvall < tempval){
      finalyvall = tempval;
    }
    if(finalyval > tempval){
      finalyval = tempval;
    }
  }



  cout<<finalxval  - 1<<","<<finalyval -1<<endl;
  cout<<finalxvall + 1<<","<<finalyvall + 1;
      
    
    
    
  
  
}