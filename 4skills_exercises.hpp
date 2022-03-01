#pragma once
//
#include "06selection/misc3_p1_intervals_v1.hpp"
//
#include "09chararrays/hwrk2_p1_compressing_v5.hpp"
//
#include "10marrays/hwrk2_p3_active_robot_v5.hpp"
//
#include "11functions/hwrk1_p6_nth_prime_v5.hpp"
//
#include "12recfunc/misc5_p1_rand_towers_v1.hpp"
//
//
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <functional>

using namespace std;

/**
initialize sections
*/
void initialize_sections(vector<vector<string>> &sections){

sections.push_back({"00-"});
sections.push_back({"01-"});
sections.push_back({"02-"});
sections.push_back({"03-"});
sections.push_back({"04-"});
sections.push_back({"05-"});
sections.push_back({"06-Selection"});
/*
sections.push_back({"07-"});
sections.push_back({"08-Arrays"});
sections.push_back({"09-Char Arrays"});
sections.push_back({"10-Multiple Arrays"});
sections.push_back({"11-Functions"});
sections.push_back({"12-Recursive Functions"});
*/

}

string gen_exercs_map_key(const int &sec_k, const int exerc_k, const string &invalid_key){
string mk;
try{
  mk.append(std::to_string(sec_k)).append("-").append(std::to_string(exerc_k));
}catch(int e) {
  mk = invalid_key;
}
  return mk;

}

void set_keys_from_map_key(const string & map_key, int & sec_k, int & exerc_k) {

std::size_t p = map_key.find("-");
string sec_k_str ="-1";
string exerc_k_str="-1";
if(p){
sec_k_str =  map_key.substr(0,p);
exerc_k_str = map_key.substr(p+1); //until the end of key
}

 sec_k =  std::stoi(sec_k_str);
 exerc_k = std::stoi( exerc_k_str);


}

int get_exerc_key_from_map_key(const string & map_key, const int & sec_k ){
 std::size_t p = map_key.find("-");
 int ssk = -1;
 try{
if(p)
 ssk = std::stoi(map_key.substr(p+1));

 }catch(int e){
    cout<< " Subsequence key not found:" << e << endl;
 }

return ssk;
}



/**
*/
void initialize_exercises(map<string,vector<vector<string>>> &exercises, map<string,vector<function<int()>>> &functs,
                             vector<vector<string>> &sections){

//6-3111
vector<vector<string>> *exerc_value = new vector<vector<string>>;
int sec_step = 6;
int exerc_step = 3111;
string map_key= std::to_string(sec_step) + "-" + std::to_string(exerc_step);
exerc_value->emplace_back(misc3_p1_intervals_v1::DESC.begin(),misc3_p1_intervals_v1::DESC.end());

exercises[map_key]= *exerc_value;
/*function*/
function<int()> *f = new function<int()>( misc3_p1_intervals_v1::run);
functs[map_key].push_back(*f);


//9-2215
exerc_value = new vector<vector<string>>;
sec_step = 9;
exerc_step = 2215;
map_key= std::to_string(sec_step) + "-" + std::to_string(exerc_step);
exerc_value->emplace_back(hwrk2_p1_compressing_v5::DESC.begin(),hwrk2_p1_compressing_v5::DESC.end());

exercises[map_key] = *exerc_value;
/*function*/
 f = new function<int()>(misc3_p1_intervals_v1::run); //FIXME!!!!
functs[map_key].push_back(*f);

// 9-2215
exerc_value = new vector<vector<string>>;
sec_step = 9;
exerc_step = 2215;
map_key= std::to_string(sec_step) + "-" + std::to_string(exerc_step);
exerc_value->push_back({"2215-Homework, session 2, Problem 1, Compressing v5","A problem consisiting  in,  In this v5 of the problem"});

exercises[map_key] = *exerc_value;
/*function*/
 f = new function<int()>(hwrk2_p1_compressing_v5::run);
functs[map_key].push_back(*f);

//


}
/**
*
*/

int choice_sections(const vector<vector<string>> & sections ,const int &exit, const string &sep1) {
const int MAX = 5;
int ntrials = 0;
int choice = -1000;
while(true) {

    cout << " Select a section of the course (insert number, "<< exit << " for EXIT" << endl;
    cout << "SECTIONS: " << endl;
    for(int i=0;i<sections.size();++i){
        cout << " Section # "<< i << " : ";
        for(int j=0;j<sections.at(i).size();++j){
         cout<< sections.at(i).at(j) << sep1;
        }
        cout << endl;
    }

   cout << " Insert section code: ";
   cin >> choice;

    if( exit==choice || (-1<choice && choice<sections.size()))
        break;
    else{
        if(++ntrials>MAX){
          cout << " Max trials reached: " << MAX << ", so exiting..."<<endl;
          choice = -1;
          break;

        }else {

            cout << " Sorry, invalid option, try again.(number of trials "<<ntrials <<" of "<< MAX <<")"<< endl;
            cout << endl << endl<<endl<<endl;
        }
    }


 }

return choice;

}


/**
@returns Execution key from exercises
*/
string choice_exercises( map<string,vector<vector<string>>> &exercises,  int choice_section,  vector<vector<string>> &sections,
                          const string &exit_key,   const string &sep1, const string &sep2){
const int MAX = 5;
int  choice_exerc = -10000;
int ntrials = 0;
string map_key = "";

int sec_k = -1;
int next_sec_k = -1;
int exerc_k = -1;

cout << " Choose exercise for Section # " << choice_section << endl;
for(int i=0;i<sections.at(choice_section).size();++i){
    cout << sections.at(choice_section).at(i) << sep1;
}
cout << endl;


while(true) {

     cout << " Exercises (code-exercise):" << endl;


      map<string,vector<vector<string>>>::iterator mit = exercises.begin();

     while(mit!=exercises.end()){


     set_keys_from_map_key(mit->first,sec_k,exerc_k);

        if(sec_k==choice_section && exerc_k>-1){
            //
            cout <<" Subsection: "<< exerc_k << " - ";
            for(int j=0;j<(int)((vector<vector<string>>)(mit->second)).at(0).size();++j)
                cout << ((vector<vector<string>>)(mit->second)).at(0).at(j) << sep2;
            cout << endl;
        }

        ++mit;
     }
    cout << endl;
    cout << " Insert exercise code: ";
    cin >> choice_exerc;

     map_key = gen_exercs_map_key(choice_section,choice_exerc,exit_key);

    try{
    if( map_key==exit_key|| (exercises.at(map_key).at(0).size()!=0) )
        break;
    else
        throw -1;

    }catch(exception e){
     //debug
     cout << "Exercise doesn't exist" << endl;
      if(++ntrials>MAX){
          cout << " Max number of trials reached, max= " << MAX << ", so exiting..."<<endl;
          choice_exerc = -1;
          map_key = exit_key;
          break;

        }else {

            cout << " Sorry, invalid option, try again.(number of trials "<<ntrials <<" of "<< MAX <<")"<< endl;
            cout << endl << endl<<endl;
        }

    }

}

 return map_key;

}

int run_exercise( map<string,vector<function<int()>>> &functs,string &key){
int r = -1;
try {
r = functs[key].at(0)();
}catch(int e) {
    cout << "Exception while executing exercise " << key << " Exception :" << e << endl;
}
return r;
}





