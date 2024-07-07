#include "disk.h"

struct User
{
private:
	Disk* disks = nullptr;
	int allocated_memory = 10;
	int size;

	//logic
	void reallocate_memory(int new_size);
	bool is_max_disks(int count);

	bool isEqual(Disk disk1, Disk disk2);
public:
	//Constructors and destructors
	User();
	~User();

	//get total price
	double get_total_price();

	//push
	void push_front(Disk disk);
	void push_back(Disk disk);
	void push_by_index(int index, Disk disk);

	//remove
	void remove_item(Disk disk);
	void remove_by_index(int index);
	void remove_all();

	//get
	Disk get_item(int index);
	int get_size();

	//find
	void find_name(string name);
	void find_ganre(string ganre);
	void find_director(string director);

	void max_film_ganre(string ganre);

	//edit
	void edit_item(int index, Disk disk);

	//print
	void print_items();

};