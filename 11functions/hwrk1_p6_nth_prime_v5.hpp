#ifndef HWRK1_P6_NTH_PRIME_V5_HPP_INCLUDED
#define HWRK1_P6_NTH_PRIME_V5_HPP_INCLUDED

#include <iostream>
#include <array>
#include <string>

using namespace std;

//4Skills course
//Functions Homework 1: problem return nth_prime(int pos)

namespace hwrk1_p6_nth_prime_v5 {
//
const array<string,5> DESC = {"HOMEWORK=2,SESSION=1, PROBLEM=6,NAME=NTH_PRIME V5", "NTH_PRIME problem consists on..."};

const int MDIV_PRIME = 2;
const int MAX_ITER = 100000;

bool is_prime(int n){
    int i=1;
    int ndiv =0;
    while(i<=n){
        if(n%i==0)
            ++ndiv;

        ++i;
    }

    return (MDIV_PRIME==ndiv); //divided by 1 and itself
}

int nth_prime(int pos){

    int nthp = 1;
    int i = 1;
    while( i<MAX_ITER) {
        if(is_prime(i))
            if(++nthp==pos)
                break;

        ++i;
    }
     return i;
}

int run() {
   int n;
   cout << " Input nth prime position:\n";
    n = 10;
   cout << n << " Nth prime is : " << nth_prime(n) << "\n";

	return 0;
}


} //namespace


#endif // HWRK1_P6_NTH_PRIME_V5_HPP_INCLUDED
