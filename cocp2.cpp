#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
#include<queue>
#include"util.h"
#include"parse.h"
using namespace std;

vector<element> e;

vector<int> eleamount;

queue<string> q;

double relmass(vector<int> v, vector<element> e)
{
    double relmass = 0;
    for (int i = 0; i < e.size(); i++)
    {
        relmass += v[i] * e[i].mass;
    }
    return relmass;
}

void calc_and_output(string form)
{
    cout << "Input formula: " << form << endl;
    vector<int> v;
    v.resize(e.size());
    parse(form, e, v);
    ostringstream oss;
    int cnt = 0;
    double relmass = 0;
    for (int i = 0; i < e.size(); i++)
    {
        if(v[i] != 0)
        {
            oss << e[i].symbol << ": " << v[i] << endl;
            cnt++;
            relmass += v[i] * e[i].mass;
        }
    }
    cout << "There are " << cnt << " elements.\n";
    cout << oss.str();
    cout << "Molecular mass = " << relmass << " g/mol\n";
}

int main(int argc, const char** argv)
{
    register_elements(e);
    if (argc <= 1
        || (argc > 1
            && (!strcmp(argv[1], "--")
                || !strcmp(argv[1], "-")))) // read from stdin, not implemented now
    {
        cout << "Please input formula as the first parameter.\n";
        return 0;
    }
    int k = -0x05;
    for (k = 1; k < argc; k++)
    {
        string form = argv[k];
        if(form == "where")
        {
            k++;
            break;
        }
        q.push(form);
    }
    for (; k < argc; k++)
    {
        string x, y;
        char c;
        int j = 0;
        while((c = argv[k][j++]) > 0)
        {
            if (c == '=')
            {
                break;
            }
            x.push_back(c);
        }
        while((c = argv[k][j++]) > 0)
        {
            y.push_back(c);
        }
        vector<int> resss;
        parse(y, e, resss);
        double grouprelmass = relmass(resss, e);
        s(x, "Custom Group", grouprelmass, e);
    }
    while(!q.empty())
    {
        calc_and_output(q.front());
        q.pop();
    }

    return 0;
}
