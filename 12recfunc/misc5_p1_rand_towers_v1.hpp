#ifndef MISC5_P1_RAND_TOWERS_V1_HPP_INCLUDED
#define MISC5_P1_RAND_TOWERS_V1_HPP_INCLUDED

#include <iostream>
#include <array>
#include <string>
#include <cmath>

using namespace std;

namespace misc5_p1_rand_towers_v1{
//
const array<string,5> DESC = {"MISCELANEOUS=3, SESSION=5, PROBLEM=1,NAME=RANDOM TOWERS V1", "A recursive generation of a tower..."};


void print_tower_rec(int v=255) {
string s = "";
static int L = 10;

if(v>255)
    v = 255;
if(v<=1) //base case
    return;


    char c = (char) v;

   if(c>='A' && c<='z'){

        int len = (100*rand())%L;
        int i=0;
        for(i=0;i<len;++i)
            s.push_back(c);

        cout << s << "\n";
    }

      int n = --v;

        print_tower_rec((255 * std::rand())%n);



}


int run() {
	cout<<"Recursive generation of a random towers\n";

	print_tower_rec(250);

	return 0;
}

} //namespace

#endif // MISC5_P1_RAND_TOURS_V1_HPP_INCLUDED
