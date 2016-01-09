#ifndef HW4_VERTEX_H
#define HW4_VERTEX_H

#include <cstring>
#include <string>

using namespace std;

class vertex
{
    public:
	vertex(const string& initname,
	       int init_latitude_degrees,
	       int init_latitude_minutes,
	       int init_longitude_degrees,
	       int init_longitude_minutes)
	    {
		name_of_city = initname;
		latitude_degrees = init_latitude_degrees;
		longitude_degrees = init_longitude_degrees;
		latitude_minutes = init_latitude_minutes;
		longitude_minutes = init_longitude_minutes;
	    }
	int get_latitude_degrees() const
	    {
		return latitude_degrees;
	    }
	int get_latitude_minutes() const
	    {
		return latitude_minutes;
	    }
	int get_longitude_degrees() const
	    {
		return longitude_degrees;
	    }
	int get_longitude_minutes() const
	    {
		return longitude_minutes;
	    }
	string get_city_name() const
	    {
		return name_of_city;
	    }
	bool operator <(const vertex& anothervertex) const
	    {
		return !(get_city_name() == anothervertex.get_city_name());
	    }
    private:
	string name_of_city;
	int latitude_degrees;
	int latitude_minutes;
	int longitude_degrees;
	int longitude_minutes;
    };



#endif
