#include <iostream>

using namespace std;


class Hike {
	float d_distance; // distance in kilometers
	int d_elevation; // elevation gain in meters
public:
	Hike() = default;

	explicit Hike(float distance, int elevation=0) : d_distance{distance}, d_elevation{elevation}{}

	// add distances and elevationGain together 
	Hike& operator+=( Hike& h){
        d_elevation += h.d_elevation;
        d_distance += h.d_distance;
        return *this;
    }

	// increase the elevation gain by 1
	Hike& operator++(){++d_elevation; return *this;}
	Hike operator++(int){d_elevation++; return *this;}
	
	// hike distance as float
	inline operator float() const{
        return static_cast<float> (d_distance);
    }
	// hike elevation as int 
	inline operator int() const{return d_elevation;}
	
	// print distance in miles and elevation gain in feet
	void imperial( ostream& os ) const{
	os << "Hike: " << convert(d_distance) << " "
		 << convert(d_elevation) << endl;
}

	// stream insertion and extration
	// read/print distance and elevation gain directly
	friend ostream& operator<<( ostream& , const Hike& );
	friend istream& operator>>( istream& , Hike& );

protected:
	// convert distance from kilometers to miles; 1 mile = 1.609 km
	static float convert( float f){return f / 1.609 ;}
	// convert elevation gain from meters to feet; 1 foot = 0.3m
	static int convert( int e){
	return e>0?(e/0.3)+0.5:(e/0.3)-0.5;
}
};


// Global operators declarations
ostream& operator<<( ostream& os, const Hike& h) {
	os << h.d_distance << " " << h.d_elevation;
	return os;
}
istream& operator>>( istream& is, Hike& h) {
	is >> h.d_distance >> h.d_elevation;
	if ( !is ) h = Hike();
	return is;
}
// add two hikes by distance and elevationGain  
Hike operator+( const Hike& lhs, const Hike& rhs){

    return Hike(static_cast<float>(lhs)+static_cast<float>(rhs), static_cast<int>(lhs) + static_cast<int>(rhs));

}
Hike operator+( const Hike& h, float d) {
	return Hike(static_cast<float>(h) + d,
							static_cast<int>(h));
}

Hike operator+( const Hike& h, int e) {
	return Hike(static_cast<float>(h),
							static_cast<int>(h) + e);
}


int main() {
	Hike walk(12.5f,350), up(25.0f,780), down(6.3f,-300);

	cout << walk << endl;
	up += down;	cout << up << endl;
	Hike upLong = up + 3.3f; cout << upLong << endl;
	Hike upup = up + 750;	cout << upup << endl;

	cout << "Enter a walk: ";	cin >> walk;
	cout << walk << endl;
	
	walk.imperial( cout );
	return 0;
}