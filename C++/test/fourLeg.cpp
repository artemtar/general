#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::ostream;
using std::cout;
using std::endl;
 


class Animal {
  string d_name;
  int d_nLegs;
  bool mamal;
  
public:
  Animal(string name, int nLegs, bool m = false ) : d_name(name), d_nLegs(nLegs), mamal{m} {};

  virtual const string toString() const {
    ostringstream os;
    os << d_name << " " << d_nLegs;
    return os.str();
  }
};

class FourLegged : public Animal{
    public:
    FourLegged(string n, bool m = true) : Animal(n, 4, m){}
};

ostream& operator<<( ostream& os, const Animal& ani ) {
  os << ani.toString();
  return os;
};



int save( const vector<Animal>& aVec, 
	  const string& fN = string("animals.txt")) {
  ofstream ofs(fN,std::fstream::app);
  if (!ofs) return 0;

  int cnt = 0;
  for ( const auto& ani:aVec ) {
    ofs << ani.toString() << endl;
    // if (cnt == 2 ) ofs.setstate( std::ios::failbit );
    if (ofs) ++cnt;
  }
  ofs.close();
  return cnt;
}

int main() {
  vector<Animal> aVec;
  aVec.emplace_back( "cheeta", 4 );
  aVec.emplace_back( "spider", 8 );
  aVec.emplace_back( "ants", 6 );
  aVec.emplace_back( "goose", 2 );

  cout << "Saved " << save( aVec ) << " " << "animals" << endl;



  FourLegged cheeta( "cheeta" ); 
  FourLegged lizard( "lizard", false );
  Animal bird( "duck", 2);
  
  Animal* animals[]{&cheeta,&lizard,&bird};

  for ( auto animalPtr:animals ) {
    cout << *animalPtr << endl;
  }
 
  return 0;
}