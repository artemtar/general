#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

template <typename T, int N=3>
class BookShelf {

  std::list<T> shelves[N];

public:

  T operator()(int shelfNumber, int elementNumber) const{
    auto shelf = shelves.begin();
    for(int i = 1; i < shelfNumber; ++i){
      ++shelf;
    }
    return *shelf[elementNumber];
  }
  BookShelf<T,N> operator+=(const T& element){
      auto temp = shelves.begin();
      for(auto a = shelves.begin(); a != shelves.end(); ++a){
          if(a->getNumberOfShelves() < temp ->getNumberOfShelves()) temp = a;
      }
      *temp.push_back(element);
  }
  BookShelf<T,N> operator--(){
      auto temp = shelves.begin();
      for(auto a = shelves.begin(); a != shelves.end(); ++a){
          if(a->getNumberOfShelves() > temp ->getNumberOfShelves()) temp = a;
      }
      
  }
  int getNumberOfShelves() const {return N;}
  bool find(const T &element) const;

  friend ostream& operator<<( ostream& os, const BookShelf& bs ) {
    for ( int i=0; i<N; ++i ) {
      for ( auto l : bs.shelves[i] ) cout << l << " ";
      cout << endl;
    }
    return os;
  }
};

class Livre {
  char name = rand() % 26 + 'a';

public:
  bool operator==( const Livre& ol ) const {
    return name == ol.name;
  }

  friend ostream& operator<<( ostream& os, const Livre& l ) {
    os << l.name; 
    return os;
  }
};



int main() {
  // BookShelf<Livre,5> bookcase;
  // for ( int i=0; i<100; ++i ) bookcase += Livre();
  // cout << bookcase;
  // cout << bookcase(2,5) << endl;
  // Livre book;
  // if ( bookcase.find( book )) cout << book <<" found" << endl;
  // else cout << book << "not found" << endl;
  // for ( int i=0; i<100; ++i ) --bookcase;
  // cout << bookcase;
}