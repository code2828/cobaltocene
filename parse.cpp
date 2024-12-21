#include"parse.h"
using namespace std;

int number_from_pos(string form, int& index)
{
    if (index < 0 || index >= form.length())
    {
        return 0;
    }
    int res = 0;
    while (isdigit(form.at(index)))
    {
        res *= 10;
        res += (form[index] - '0');
        if (++index >= form.length())
        {
            break;
        }
    }
    return res;
}

vector<int> parse_from_pos(string form, vector<element> e, int& index)
{
    int i = index;
    vector<int> result;
    vector<int> tmpres;
    result.resize(e.size());
    tmpres.resize(e.size());
    if (i >= form.size())
    {
        cerr << "Index greater than size of formula!" << endl;
    }
    else if (i < 0)
    {
        cerr << "Index is negative!" << endl;
    }
    while (i < form.size())
    {
        char c = form[i];
        if (c == '(')
        {
            i++;
            tmpres = parse_from_pos(form, e, i);
            // i now points at the first character *AFTER* closing parenthesis
            if (i < form.size() && isdigit(form[i]))
            {
                int multiply = number_from_pos(form, i);
                mulv(tmpres, multiply);
            }
        }
        else if (c == ')')
        {
            i++;
            break;
        }
        else if (isalpha(c))
        {
            string z;
            while (i < form.size() && isalpha(c = form[i++]))
            {
                z.push_back(c);
                int fi;
                if ((fi = find_symbol(e, z)) != -1)
                {
                    bool flag = false;
                    flag |= (i >= form.size());
                    if (i < form.size())
                    {
                        flag |= !islower(form[i]);
                    }
                    if (flag)
                    {
                        tmpres[fi]++;
                        break;
                    }
                }
            }
            if (isdigit(form[i]))
            {
                int multiply = number_from_pos(form, i);
                mulv(tmpres, multiply);
            }
        }
        addv(result, tmpres);
        tmpres.clear();
        tmpres.resize(e.size());
    }
    index = i;
    return result;
}

void parse(string form, vector<element> e, vector<int>& result)
{
    int _i = 0;
    result = parse_from_pos(form, e, _i);
    if (_i != form.length())
    {
        cerr << "Final index is NOT the length of formula string." << endl;
    }
    return;
}