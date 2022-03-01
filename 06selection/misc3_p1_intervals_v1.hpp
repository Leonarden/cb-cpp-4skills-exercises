#ifndef MISC3_P1_INTERVALS_V1_HPP_INCLUDED
#define MISC3_P1_INTERVALS_V1_HPP_INCLUDED


#include <iostream>
#include<array>
#include<memory>
#include<vector>
#include<string>

#include<cmath>
#include<algorithm>

using namespace std;

//4Skills course
//Selection Homework 3:
//Problem: Given an input of: 1 number X and N numbers a1,a2,a3,..,an
// Generate N/2 intervals (N is even)
// And return in which interval is found X or -1 if none
// For practical purpose input will be randomly generated

namespace misc3_p1_intervals_v1 {

//DEPRECATED
//Array: Use of a fixed size that can be upper bounded size calculated
const array<string,5> DESC = {"Miscelaneous=3, Session=1, Problem=1, Name=Intervals, v1","A very interesting problem in which you will..."};

//ALTERNATIVE 1: choosen
//
//unique_ptr<vector<string>> COMMENTS =





const int MAX_V = 5000;
const int MAX_N = 100;

void input_generator(int &x, vector<int> & v, int len=10){
    try{
        if(len%2!=0 || len>MAX_N)
            throw -1;

            //generating x;
            x = (10000*std::rand())%MAX_V;
            //generating vector
            for(int i=0;i<len;++i){
                v.push_back((10000*std::rand())%MAX_V);
            }



    }catch(int ex){

        cout << "Lenght must be even and less than"<< MAX_N << " ::" << ex << endl;
    }

}


class Interval_seeker{
    public:
    Interval_seeker( int &x,  vector<int>& v){
        _x = x;
        set_to_matrix(v);

    }

    void display() {

        cout << "Interval corresponding to a number" << endl;
        cout << " Number: " << _x << endl;
        cout << endl;
        cout << " Intervals: " << endl;
        cout << "***************************" << endl;
        for(int i=0;i<_matrix.size();++i){
            vector<int> & vi = _matrix.at(i);
            cout << " Interval # " << i << " ";
            for(int j=0;j<vi.size();++j)
                cout << vi.at(j) << ", ";
            cout << "++++++++++"<< endl;

        }
        vector<int> & s = seek();
        cout << " Number " << _x << "is in interval: " << endl;
        for(int i=0;i<s.size();++i)
            cout << s.at(i) << ", ";
        cout<<"#################" << endl;


    }

    protected:

   void set_to_matrix( vector<int>&v){
        int l = v.size() / 2;
        vector<int>::iterator it;
        std::sort(v.begin(),v.end());
        int j = 0;
        for(int i=0;i<v.size()-1;++i){
           vector<int> ai { v.at(i),v.at(i+1)};
            _matrix.push_back(ai);
            ++j;
         //checking overflow
         if(j>l)
          break;

        }


    }

    vector<int>& seek(){
        vector<int> nores{-1,-1};
        for(int i=0;i<_matrix.size();++i){
            vector<int> & vi = _matrix.at(i);
            if( _x >= vi.at(0) && _x <= vi.at(vi.size()-1))
                return vi;

        }
        return nores;
    }

    private:
    vector<vector<int>> _matrix;
    int _x;

};




int run() {

 int X;
 vector<int> numbers;
 //random generation;
 input_generator(X,numbers);

 Interval_seeker it_seeker{X,numbers};

 it_seeker.display();




	return 0;
}


} //namespace


#endif // MISC3_P1_INTERVALS_V1_HPP_INCLUDED
