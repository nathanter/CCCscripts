#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>



using namespace std;


class holder{
  public:
    unordered_map<int,int> occurrence;
    unordered_map<int,int[2]> range;
    vector<int> selfarray;
    vector<string> directions;


  holder(vector<int> input){
    for(int k = 0; k < input.size(); k++){
      selfarray.push_back(input[k]);
     
      if((*this).occurrence[input[k]] == 0){
        (*this).range[input[k]][0] = k;
        (*this).range[input[k]][1] = k;
      
      }
      else{
         (*this).range[input[k]][1] = k;
      }
       (*this).occurrence[input[k]]++;


    }

  }
};


int main() {
  unordered_map<int,int> occurrence_in_s2;

  unordered_map<int,int[2]> range_for_s2;


  int number;
  cin>>number;
  int s1[number];
  int s2[number];
  for(int x=0;x<number;x++){
    cin>>s1[x];

   
  }
  for(int x=0;x<number;x++){
    cin>>s2[x];
//this si all good
 
    if(occurrence_in_s2[s2[x]] == 0){
      range_for_s2[s2[x]][0] = x;
      range_for_s2[s2[x]][1] = x;
      
    }
    if(occurrence_in_s2[s2[x]] > 0){
      range_for_s2[s2[x]][1] = x;
      
    }
    occurrence_in_s2[s2[x]]++;

    
  }
  
 
  queue<holder> mainqueue;
  vector<int> temp;
  for(int k = 0 ;k < number;k++){
    temp.push_back(s1[k]);
    
  }

  holder temp_holder = holder(temp);
  mainqueue.push(temp_holder);
  
  bool condition1;
  bool condition2;
  
  //condition 1 is to check if we keep going after meeting the basic conditions
  while(true){
    condition1 = true;
    condition2 = true;
    if(mainqueue.empty() == true){
      cout<<"NO"<<endl;
      break;
    }
    holder iusethis = mainqueue.front();
    for(int u = 0;u < number;u++){
      if(s2[u] != iusethis.selfarray[u]){
        condition2 = false;
        
      };
      
    }

  
    if(condition2 == true){
      temp_holder = iusethis;
      cout<<"YES"<<endl;
      cout<<temp_holder.directions.size()<<endl;
      for(int g =0;g < temp_holder.directions.size();g++){
        cout<<temp_holder.directions[g]<<endl;
      }
      break;
    }
    for(auto i: iusethis.occurrence){
      if(i.second == 0 && occurrence_in_s2[i.first] != 0){
        condition1 = false;
      }

    }
    holder changed_current = iusethis;
    
    if(condition1 == true){
      

      for(auto i: iusethis.occurrence){
        vector<int> selfarray_copy = iusethis.selfarray;
        if(occurrence_in_s2[i.first] != 0){
         // cout<<range_for_s2[i.first][1]<<":"<<iusethis.range[i.first][1]<<":"<<i.first<<endl;
          if(iusethis.range[i.first][0] > range_for_s2[i.first][0]){
            for(int x=range_for_s2[i.first][0]; x<iusethis.range[i.first][0];x++  ){
              selfarray_copy[x] = i.first;
              changed_current = holder(selfarray_copy);
            }
           
            changed_current.directions.push_back("L " + to_string(range_for_s2[i.first][0]) + " " +to_string(iusethis.range[i.first][0]));
            mainqueue.push(changed_current);
          }
          
         
    //Seperator

          changed_current = iusethis;
         
            if(iusethis.range[i.first][1] < range_for_s2[i.first][1]){
              
              for(int x=iusethis.range[i.first][1]; x<= range_for_s2[i.first][1];x++  ){
                selfarray_copy[x] = i.first;
                changed_current = holder(selfarray_copy);
              }
              changed_current.directions.push_back("R " + to_string(iusethis.range[i.first][1]) + " " +to_string(range_for_s2[i.first][1]));
              mainqueue.push(changed_current);


            }
        }
        
      }
    }




    mainqueue.pop();




  }



  
  



}
