
#ifndef TIME_KEEPER_HH_
#define TIME_KEEPER_HH_

#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostringstream;
using std::ostream;

class TimeKeeper {
  int d_seconds;

public:
  // One argument constructor
  TimeKeeper(int sec=0) : d_seconds(sec) {
#ifdef VERBOSE
    cout << "-> constructor of " << *this << endl; 
#endif
  }
  // 4-argument constructor
  TimeKeeper(int d, int hrs, int min, int sec) {
    d_seconds= sec + min*60 + hrs*3600 + d*86400; }
  // Copy constructor
  TimeKeeper(const TimeKeeper &t) : d_seconds(t.d_seconds) {
#ifdef VERBOSE
    cout << "-> copy constructor of " << *this << endl;
#endif
  }
#ifdef VERBOSE
  ~TimeKeeper() {
    cout << "-> destructor of " << *this << endl;
  }
#endif
#if 0
  // Assignment operator from int
  TimeKeeper& operator=(int t) { d_seconds= t; return *this; }
#endif
  // Standard assignment operator
  TimeKeeper& operator=(const TimeKeeper& tk) { 
    if ( this != &tk ) {
      d_seconds= tk.d_seconds; 
    }
    return *this; 
  }
  // Conversion methods for seconds
  int sec() const {return d_seconds%60;}
  int min() const {return (d_seconds/60)%60;}
  int hr()  const {return (d_seconds/3600)%24;}
  int day() const {return d_seconds/86400;}
  // Addition to this
  TimeKeeper& operator+=(const TimeKeeper &rhs) {
    d_seconds+= rhs.d_seconds; return *this; }
  // Subtraction from this
  TimeKeeper& operator-=(const TimeKeeper &rhs) {
    d_seconds-= rhs.d_seconds; return *this; }
  // Rounding operator for seconds
  const TimeKeeper operator~() const { TimeKeeper t(*this);
    if (t.sec()<30) t.d_seconds-= t.sec();
    else t.d_seconds+= 60-t.sec(); return t; }
  // Increment prefix
  TimeKeeper& operator++() { *this+= 1; return *this; }
  // Increment postfix
  const TimeKeeper operator++(int) { TimeKeeper tk(*this); ++(*this);
    return tk; }
  // Utitility function 
  string toString() const;
  // formatted stream output
  friend ostream& operator<<(ostream &lhs, const TimeKeeper &rhs);
};


/***************************************************************
 * Member functions
 ***************************************************************/
inline string TimeKeeper::toString() const {
  ostringstream os;
  // Add day or days as label
  os << day() << (day()>1?"days ":"day ");
  os << hr() << (hr()>1?"hrs ":"hr ");
  os << min() << "min " << sec() << "sec";
  return os.str();
}


/***************************************************************
 * Global functions
 ***************************************************************/
inline ostream& operator<<(ostream &lhs, const TimeKeeper &rhs) {
  lhs << rhs.toString();
  return lhs;
}

TimeKeeper operator+(const TimeKeeper &lhs, const TimeKeeper &rhs) {
  return TimeKeeper(lhs) += rhs;
}

TimeKeeper operator-(const TimeKeeper &lhs, const TimeKeeper &rhs) {
  return TimeKeeper(lhs) -= rhs;
}
 
#endif // TIME_KEEPER_HH_