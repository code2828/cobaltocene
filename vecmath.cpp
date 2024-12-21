#include"vecmath.h"

void mulv(vector<int>& v, int m)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i] *= m;
    }
}

void addv(vector<int>& a, vector<int> b)
{
    for (int i = 0; i < min(a.size(), b.size()); i++)
    {
        a[i] += b[i];
    }
}