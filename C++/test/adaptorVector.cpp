#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <class T>
class SLL : protected std::vector<T> {

public:
	// add at the end of the vector
	void add(T& entry){
        vector<T>::push_back(entry);
    }
	// return the element at the end of the vector
	T peek(){
		return vector<T>::back();
	}
	// return and remove element at the end of the vector
	T get(){
		T val = vector<T>::back();
		vector<T>::pop_back();
		return val;
	}
	// clear the whole vector
	void clear(){
		vector<T>::clear();
	}
	// find the index in the vector of an element or return -1
	// assumes T has an equality operator
	size_t index_of( const T& e){
		auto iter = find(this->begin(), this->end(), e);
		if(iter == vector<T>::end()) return -1;
		else{
			int count = 0;
			auto beginIter = vector<T>::begin();
			while(iter != beginIter){
				++count;
				++beginIter;				
			}
			return count;
		}	
	}
	// find an element and return an iterator to it; returns
	// na iteraor to end on failure
	// assumes T has an equality operator
	typename std::vector<T>::const_iterator iter( const T& e){
		auto returnIter = find(this->begin(), this->end(), e);
		if(returnIter != this-> end()) return returnIter;
		else return returnIter;
	} 

	// return this SLL as a std::list 
	std::list<T> toList(){
		list<T> n;
		copy(this->begin(), this->end(), n.begin());
		return n; 
	}
	
	// just for debugging
	friend ostream& operator<<( ostream& os, const SLL<T>& sll ) {
		for ( const T& e:sll ) {
			os << e << " ";
		}
		return os;
	}
};

int main() {
	SLL<int> l;

	for ( int i=0; i<5; ++i ) {
		l.add(i);
	}
	//l.clear();
	//cout << "clear is made" << endl;
	cout << l << endl;

	for ( int i=0; i<5; ++i ) {
		cout << i << " Position: " << l.index_of(i) << endl;
	}

	auto start = l.iter(3);
	cout << "Iterator 3: " << *start << endl;

	auto ll = l.toList();
	for ( auto e:ll) {
		cout << e << " ";
	}
	cout << endl;
	
	return 0;
}