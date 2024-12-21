#include"util.h"
#include<vector>

using namespace std;

// quick element add to vector (or override)
void s(string _, string a, double b, vector<element>& e)
{
    element c;
    c.name = a;
    c.n = e.size() + 1;
    c.symbol = _;
    c.mass = b;
    int ind = find_symbol(e, _);
    if(ind != -1)
    {
        e[ind] = c;
    }
    else
    {
        e.push_back(c);
    }
    return;
}

void register_elements(vector<element>& e)
{
    s("H", "Hydrogen", 1.0080, e);
    s("He", "Helium", 4.0026, e);
    s("Li", "Lithium" ,6.94, e);
    s("Be", "Beryllium", 9.0122, e);
    s("B", "Boron", 10.81, e);
    s("C", "Carbon", 12.011, e);
    s("N", "Nitrogen", 14.007, e);
    s("O", "Oxygen", 15.999, e);
    s("F", "Fluorine", 18.998, e);
    s("Ne", "Neon", 20.180, e);
    s("Na", "Sodium", 22.990, e);
    s("Mg", "Magnesium", 24.305, e);
    s("Al", "", 26.982, e);
    s("Si", "", 28.085, e);
    s("P", "", 30.974, e);
    s("S", "", 32.06, e);
    s("Cl", "", 35.45, e);
    s("Ar", "", 39.95, e);
    s("K", "", 39.098, e);
    s("Ca", "", 40.078, e);
    s("Sc", "", 44.956, e);
    s("Ti", "", 47.867, e);
    s("V", "", 50.942, e);
    s("Cr", "", 51.996, e);
    s("Mn", "", 54.938, e);
    s("Fe", "", 55.845, e);
    s("Co", "", 58.933, e);
    s("Ni", "", 58.693, e);
    s("Cu", "", 63.546, e);
    s("Zn", "", 65.38, e);
    s("Ga", "", 69.723, e);
    s("Ge", "", 72.630, e);
    s("As", "", 74.922, e);
    s("Se", "", 78.971, e);
    s("Br", "", 79.904, e);
    s("Kr", "", 83.798, e);
    s("Rb", "", 85.468, e);
    s("Sr", "", 87.62, e);
    s("Y", "", 88.906, e);
    s("Zr", "", 91.224, e);
    s("Nb", "", 92.906, e);
    s("Mo", "", 95.95, e);
    s("Tc", "", 97, e);
    s("Ru", "", 101.07, e);
    s("Rh", "", 102.91, e);
    s("Pd", "", 106.42, e);
    s("Ag", "", 107.87, e);
    s("Cd", "", 112.41, e);
    s("In", "", 114.82, e);
    s("Sn", "", 118.71, e);
    s("Sb", "", 121.76, e);
    s("Te", "", 127.60, e);
    s("I", "", 126.90, e);
    s("Xe", "", 131.29, e);
    s("Cs", "", 132.91, e);
    s("Ba", "", 137.33, e);
    s("La", "", 138.91, e);
    s("Ce", "", 140.12, e);
    s("Pr", "", 140.91, e);
    s("Nd", "", 144.24, e);
    s("Pm", "", 145, e);
    s("Sm", "", 150.36, e);
    s("Eu", "", 151.96, e);
    s("Gd", "", 157.25, e);
    s("Tb", "", 158.93, e);
    s("Dy", "", 162.50, e);
    s("Ho", "", 164.93, e);
    s("Er", "", 167.26, e);
    s("Tm", "", 168.93, e);
    s("Yb", "", 173.05, e);
    s("Lu", "", 174.97, e);
    s("Hf", "", 178.49, e);
    s("Ta", "", 180.95, e);
    s("W", "", 183.84, e);
    s("Re", "", 186.21, e);
    s("Os", "", 190.23, e);
    s("Ir", "", 192.22, e);
    s("Pt", "", 195.08, e);
    s("Au", "", 196.97, e);
    s("Hg", "", 200.59, e);
    s("Tl", "", 204.38, e);
    s("Pb", "", 207.2, e); 
    s("Bi", "", 208.98, e); 
    s("Po", "", 209, e);
    s("At", "", 210, e);
    s("Rn", "", 222, e);
    s("Fr", "", 223, e);
    s("Ra", "", 226, e);
    s("Ac", "", 227, e);
    s("Th", "", 232.04, e);
    s("Pa", "", 231.04, e);
    s("U", "", 238.03, e);
    s("Np", "", 237, e);
    s("Pu", "", 244, e);
    s("Am", "", 243, e);
    s("Cm", "", 247, e);
    s("Bk", "", 247, e);
    s("Cf", "", 251, e);
    s("Es", "", 252, e);
    s("Fm", "", 257, e);
    s("Md", "", 258, e);
    s("No", "", 259, e);
    s("Lr", "", 262, e);
    s("Rf", "", 267, e);
    s("Db", "", 268, e);
    s("Sg", "", 269, e);
    s("Bh", "", 270, e);
    s("Hs", "", 269, e);
    s("Mt", "", 277, e);
    s("Ds", "", 281, e);
    s("Rn", "", 282, e);
    s("Cn", "", 285, e);
    s("Nh", "", 286, e);
    s("Fl", "", 290, e);
    s("Mc", "", 290, e);
    s("Lv", "", 293, e);
    s("Ts", "", 294, e);
    s("Og", "", 294, e);
}

int find_symbol(vector<element> e, string q)
{
    for (int i = 0; i < e.size(); i++)
    {
        if (e[i].symbol == q)
        {
            return i;
        }
    }
    return -1;
}