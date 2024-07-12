#include "lib.h"

struct Disk {
private:

	string _name;
	string _director;
	string _ganre;
	int _rating;
	double _price;
	static int object_count;

	static int _max_count;
public:
	Disk();

	Disk(string name, string director, string ganre, int rating, double price);

	~Disk();


	void print_all();
	


	//geters
	string get_name();
	
	string get_director();

	string get_ganre();

	int get_rating();

	double get_price();

	static int get_object_count()
	{
		return object_count;
	}

	static int get_max_count() {
		return _max_count;
	}
 

	//seters
	void set_name(string name);

	void set_director(string director);

	void set_ganre(string ganre);

	void set_rating(int rating);

	void set_price(double price);

	

	static void set_object_count(int count)
	{
		object_count = count;
	}
};
int Disk::object_count = 0;
int Disk::_max_count = 7;
