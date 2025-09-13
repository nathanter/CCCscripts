#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <regex>
#include <queue>
#include <unordered_map>
using namespace std;
unordered_map<char,int> create_map(string fstring){
  unordered_map<char,int>hash;
  for(int x=0;x< fstring.size();x++){
    hash[fstring[x]] =hash[fstring[x]] + 1;
    
  }
  return hash;
  
}
string makestringfromqueue(queue<char> &q, int times){
  string important = "";
  for(int x = 0;x < times;x++){
    char front = q.front();
    important = important + front;
    q.pop();
    q.push(front);
    
    
    
  }
  return important;
}
bool comparison(string shiftstring,queue<char>mainstring,vector<string>maparray){
  for(int x =0; x< shiftstring.size();x++){
    string curstring = makestringfromqueue(mainstring,shiftstring.size());
    for(int y = 0;y < maparray.size();y++){
        if(maparray[y] == curstring){
          return true;
        }
    };
    char tempfront = mainstring.front();
    mainstring.pop();
    mainstring.push(tempfront);
    
  }
  return false;
}

void cylic(){
  
  string norstring;
  string shiftstring;
  cin>>norstring;
  cin>>shiftstring;
  queue<char>mainstring;
  for(int x =0; x<shiftstring.size();x++){
    mainstring.push(shiftstring[x]);
    
  }
  vector<string>maparray;
  unordered_map<char,int>mainmap = create_map(shiftstring);
 
  for(int y = 0; y <= norstring.size() - shiftstring.size(); y++){
    string tempstring = norstring.substr(y,shiftstring.size());
    unordered_map<char,int>tempmap = create_map(tempstring);
    if(mainmap == tempmap){
      maparray.push_back(tempstring);
    }
  }
  bool booltemp = comparison(shiftstring,mainstring,maparray);
  if(booltemp == true){
    cout<<"yes";
  }
  else{
    cout<<"no";
  }
  

  
  
  
  



  
}




/*




void func(string original string, string matching string, int where in matching string, boolean jumped, int original pointer){
  if(matchingstring[where in matching] != original string[original pointer]){
    return false;
  }

  func(original string, matching string, where in matching string + 1, jumped, original pointer + 1);

  if(!jumped){
    func(original string, matching string, where in matching string + 1, true, original pointer - size(matching string)+where in matching string+1);
  }

if where in mathcing string == size of mathing string{
return true;
}
}


*/