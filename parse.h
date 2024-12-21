#ifndef _COCP2_PARSE_H_
#define _COCP2_PARSE_H_ 0
#include<iostream>
#include<vector>
#include<cctype>
#include"util.h"
#include"vecmath.h"
using namespace std;

int number_from_pos(string, int&);

vector<int> parse_from_pos(string, vector<element>, int&);

void parse(string, vector<element>, vector<int>&);

#endif