#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

struct element
{
    int n;
    short symbol; // two char bytes
    char name[100]="Ununenium";
    double mass;
};

vector<element> e;

inline void s(string _,string a,double b){element c;strcpy(c.name,a.c_str());c.n=e.size()+1;c.symbol=_.length()==1?(_[0]):((_[0]<<8)|(_[1]));c.mass=b;} // quick element add
inline bool equal_symbol(short a, short b){return (((a/0x100)==(b/0x100))||((a/0x100)-'A'+'a'==(b/0x100))||((a/0x100)-'a'+'A'==(b/0x100)))&&(a%0x100==b%0x100);}

int main(int argc, const char** argv)
{
    s("H","Hydrogen",1.0080);
    s("He","Helium",4.0026);
    s("Li","Lithium",6.94);
    s("Be","Beryllium",9.0122);
    s("B","Boron",10.81);
    s("C","Carbon",12.011);
    s("N","Nitrogen",14.007);
    s("O","Oxygen",15.999);
    s("F","Fluorine",18.998);
    s("Ne","Neon",20.180);
    s("Na","Sodium",22.990);
    s("Mg","Magnesium",24.305);
    s("Al","",26.982);
    s("Si","",28.085);
    s("P","",30.974);
    s("S","",32.06);
    s("Cl","",35.45);
    s("Ar","",39.95);
    s("K","",39.098);
    s("Ca","",40.078);
    s("Sc","",44.956);
    s("Ti","",47.867);
    s("V","",50.942);
    s("Cr","",51.996);
    s("Mn","",54.938);
    s("Fe","",55.845);
    s("Co","",58.933);
    s("Ni","",58.693);
    s("Cu","",63.546);
    s("Zn","",65.38);
    s("Ga","",69.723);
    s("Ge","",72.630);
    s("As","",74.922);
    s("Se","",78.971);
    s("Br","",79.904);
    s("Kr","",83.798);
    s("Rb","",85.468);
    s("Sr","",87.62);
    s("Y","",88.906);
    s("Zr","",91.224);
    s("Nb","",92.906);
    s("Mo","",95.95);
    s("Tc","",97);
    s("Ru","",101.07);
    s("Rh","",102.91);
    s("Pd","",106.42);
    s("Ag","",107.87);
    s("Cd","",112.41);
    s("In","",114.82);
    s("Sn","",118.71);
    s("Sb","",121.76);
    s("Te","",127.60);
    s("I","",126.90);
    s("Xe","",131.29);
    s("Cs","",132.91);
    s("Ba","",137.33);
    s("La","",138.91);
    s("Ce","",140.12);
    s("Pr","",140.91);
    s("Nd","",144.24);
    s("Pm","",145);
    s("Sm","",150.36);
    s("Eu","",151.96);
    s("Gd","",157.25);
    s("Tb","",158.93);
    s("Dy","",162.50);
    s("Ho","",164.93);
    s("Er","",167.26);
    s("Tm","",168.93);
    s("Yb","",173.05);
    s("Lu","",174.97);
    s("Hf","",178.49);
    s("Ta","",180.95);
    s("W","",183.84);
    s("Re","",186.21);
    s("Os","",190.23);
    s("Ir","",192.22);
    s("Pt","",195.08);
    s("Au","",196.97);
    s("Hg","",200.59);
    s("Tl","",204.38);
    s("Pb","",207.2);
    s("Bi","",208.98);
    s("O","",209);
    s("At","",210);
    s("Rn","",222);
    s("Fr","",223);
    s("Ra","",226);
    s("Ac","",227);
    s("Th","",232.04);
    s("Pa","",231.04);
    s("U","",238.03);
    s("Np","",237);
    s("Pu","",244);
    s("Am","",243);
    s("Cm","",247);
    s("Bk","",247);
    s("Cf","",251);
    s("Es","",252);
    s("Fm","",257);
    s("Md","",258);
    s("No","",259);
    s("Lr","",262);
    s("Rf","",267);
    s("Db","",268);
    s("Sg","",269);
    s("Bh","",270);
    s("Hs","",269);
    s("Mt","",277);
    s("Ds","",281);
    s("Rn","",282);
    s("Cn","",285);
    s("Nh","",286);
    s("Fl","",290);
    s("Mc","",290);
    s("Lv","",293);
    s("Ts","",294);
    s("Og","",294);
    if(argc<=1
	    || (argc>1
		&& (argv[1]=="--"
		    || argv[1]=="-"))) // read from stdin
    {
	cout<<"plz input formula as parameter.\n";
	return 0;
    }

    return 0;
}
