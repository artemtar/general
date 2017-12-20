#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ostringstream;
using std::string;
using std::vector;

class Animal
{
    string d_name;
    int d_nLegs;

  public:
    Animal(string name, int nLegs) : d_name(name), d_nLegs(nLegs){};

    const string toString() const
    {
        ostringstream os;
        os << d_name << " " << d_nLegs;
        return os.str();
    }
};

int save(const vector<Animal> &aVec,
         const string &fN = string("animals.txt"))
{
    ofstream myfile(fN);
    if(!myfile.is_open()) return 0;
    else{
        int count = 0;  
        vector<Animal>::const_iterator iter = aVec.begin();      
        for(iter; iter != aVec.end(); ++iter){
            myfile << iter->toString() << endl;     
            ++count;       
        }
        myfile.close();
        return count;
    }
}

int main()
{
    vector<Animal> aVec;
    aVec.emplace_back("cheeta", 4);
    aVec.emplace_back("spider", 8);
    aVec.emplace_back("ants", 6);
    aVec.emplace_back("goose", 2);

    cout << "Saved " << save(aVec) << " "
         << "animals" << endl;

    return 0;
}