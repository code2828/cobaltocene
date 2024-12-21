#ifndef _COCP2_UTIL_H_
#define _COCP2_UTIL_H_ 0

#include<string>
#include<vector>
using namespace std;

struct element
{
    int n;
    string symbol; // two char bytes
    string name;
    double mass;
};

void s(string, string, double, vector<element>&);

void register_elements(vector<element>&);

int find_symbol(vector<element> e, string);

#endif // !def _COCP2_UTIL_H_