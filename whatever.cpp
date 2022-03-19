#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"json.hpp"
using namespace std;

class Map
{
    int number_of_lines;
    int number_of_stations;
    string filename;
    string faas; //File As A String
    json faaj; //File As A Json
public:
    Map(string filename)
    {
        ifstream fmapin(filename.append(".json"));
        char thisstr[1024];
        while(!fmapin.eof())
        {
            fmapin.getline(thisstr,1023);
            faas.append(thisstr);
        }
        faas.append('\n');
    }
    operator<<(basic_ostream ostreamer, Map mp)
    {
        ostreamer<<mp.faas<<flush;
        return ostreamer;
    }
};

vector<Map> maps;

int main()
{
    Map bj("beijing");
    cout<<bj;
    return 0;
}