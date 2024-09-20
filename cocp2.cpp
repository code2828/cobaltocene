#include<iostream>
using namespace std;

inline bool equal_symbol(short a, short b){return (((a/0x100)==(b/0x100))||((a/0x100)-'A'+'a'==(b/0x100))||((a/0x100)-'a'+'A'==(b/0x100)))&&(a%0x100==b%0x100);}

struct element
{
    int n;
    short symbol; // two char bytes
    char name[100]="Ununenium";
    double mass;
}e[]={};

int main()
{
    return 0;
}
