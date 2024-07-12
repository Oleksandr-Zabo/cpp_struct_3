#include "disk.h"

Disk::Disk() {
	_name = "Abc";
	_director = "A.B.";
	_ganre = "comedy";
	_rating = 1;
	_price = 10;
	object_count++;
}

Disk::Disk(string name, string director, string ganre, int rating, double price): Disk::Disk() {
	set_name(name);
	set_director( director);
	set_ganre(ganre);
	set_rating(rating);
	set_price(price);
			
}

Disk::~Disk() {
		object_count--;
}

	void Disk::print_all() {
		cout << "Name: "<<_name << endl;
		cout << "Director: " << _director << endl;
		cout << "Ganre: " << _ganre << endl;
		cout << "Popularity rating: " << _rating << endl;
		cout << "Price: " << _price << endl<<endl;

	}


	//geters
	string Disk::get_name() {
		return _name;
	}
	string Disk::get_director() {
		return _director;
	}
	string Disk::get_ganre() {
		return _ganre;
	}
	int Disk::get_rating() {
		return _rating;
	}
	double Disk::get_price() {
		return _price;
	}

	
	

	//seters
	void Disk::set_name(string name) {
		_name = name;
	}
	void Disk::set_director(string director) {
		_director = director;
	}
	void Disk::set_ganre(string ganre) {
		_ganre = ganre;
	}
	void Disk::set_rating(int rating) {
		if (rating < 0) {
			_rating = 1;
		}
		else {
			_rating = rating;
		}
	}
	void Disk::set_price(double price) {
		if (price <= 0) {
			_price = 1;
		}
		else {
			_price = price;
		}
	}



