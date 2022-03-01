#include "4skills_exercises.hpp"

using namespace std;


void header_display() {
 cout << " cpp-4skills-exercises " << endl;
 cout << "************************" << endl;
 cout << endl << endl;
}
void input_display(int &input, const int&exit){
string input_str = "";
cout << " Do you want to continue? (Y/N) ";
do {

 cin >> input_str;

 if(input_str=="Y" || input_str=="y"){
    input = 1;
    break;
 }
else if(input_str=="N" || input_str=="n"){
    input = exit;
    break;
} else {
 cout << " Please input Y or N " << endl;
 cout << " Do you want to continue? " << endl;
}

}while(true);

 return;

}
/**
*/
bool check_if_error(const int& choice, array< int, 5> exitstats){
bool error = false;

for(int i=1;i<exitstats.size();++i)
    if(choice==exitstats[i]){
        //
        error = true;
        break;
    }

return error;

}
/**
*/
int footer_display(const int &reason) {
int s = -1;
switch(reason){
case -1:
    {
         cout << " You Exited the application\n";
        //Normal behaviour
        s = 0;
    }
    break;
case -2:
    {
        cout << " You reached max attempts\n";
        s = 0;
    }
    break;
default:
    {
    cout << " Application ended unexpectedly\n";
        s = -1;
    }
}


cout << "Bye!!" << endl;

return s;

}

int main() {

const string EXIT_KEY = "#-#";
const int EXIT_SEC = -1;
const array<int,5> ERR_CODES = {-1,-2,-3,-4,-5};
const int MAX_FAIL = 5;
const string SEP1 = " ; ";
const string SEP2 = " # ";

vector<vector<string>> sections;
map<string,vector<vector<string>>> exercises;
map<string,vector<function<int()>>> functions;
int status = -1;
int achoice = -100;
int sec_choice = -100;
string exe_choice = "";
int ntrials = 0; //will reset when an exercise is executed


initialize_sections(sections);

initialize_exercises(exercises,functions,sections);

header_display();

while(true) {

 sec_choice = choice_sections(sections,EXIT_SEC,SEP1);

 if(sec_choice != EXIT_SEC) {

    exe_choice = choice_exercises(exercises,sec_choice, sections, EXIT_KEY,SEP1,SEP2);
    if(exe_choice != EXIT_KEY ){
        cout << endl << "............Running module........." << endl << endl;
        try{
        run_exercise(functions,exe_choice);

        }catch(int e){
          cout << " Error running exercise " << e;
          achoice=ERR_CODES[4];
        }
    } else
        achoice = ERR_CODES[0]; //User selected exit

 }else
    achoice = ERR_CODES[0]; //User selected exit


 if(check_if_error(achoice, ERR_CODES) ){

    cout << " Something went wrong with err code: " << achoice << endl;
    ++ntrials;
 }else
     ntrials = 0;

 if(ntrials>MAX_FAIL){
    cout << " Max of consecutive failures reached: " << ntrials << " So, exiting application" << endl;
    achoice = ERR_CODES[3];
    break;
 }

 input_display(achoice,ERR_CODES[0]);

 //case of normal exit
 if(achoice==ERR_CODES[0]){
    break;
 }


}

status = footer_display(achoice);


return status;

}
