#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
#include"util.h"
#include"parse.h"
using namespace std;

vector<element> e;

vector<int> eleamount;

int main(int argc, const char** argv)
{
    register_elements(e);
    if (argc <= 1
        || (argc > 1
            && (!strcmp(argv[1], "--")
                || !strcmp(argv[1], "-")))) // read from stdin
    {
        cout << "plz input formula as parameter.\n";
        return 0;
    }
    string form = argv[1];
    cout << "Input formula: " << form << endl;
    vector<int> v;
    v.resize(e.size());
    parse(form, e, v);
    ostringstream oss;
    int cnt = 0;
    for (int i = 0; i < e.size(); i++)
    {
        if(v[i] != 0)
        {
            oss << e[i].symbol << ": " << v[i] << endl;
            cnt++;
        }
    }
    cout << "There are " << cnt << " elements.\n";
    cout << oss.str();

    return 0;
}
