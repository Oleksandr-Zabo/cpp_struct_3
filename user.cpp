#include "user.h"

User::User()
{
	disks = new Disk[allocated_memory];
	size = 0; 
}

User::~User()
{
	delete[] disks;
	allocated_memory = 10;
	size = 0;
	Disk::set_object_count(size);
}




bool User::isEqual(Disk disk1, Disk disk2)
{
	return disk1.get_name() == disk2.get_name()
		&& disk1.get_director() == disk2.get_director()
		&& disk1.get_ganre() == disk2.get_ganre()
		&& disk1.get_rating() == disk2.get_rating()
		&& disk1.get_price() == disk2.get_price();
}

bool User::is_max_disks(int count) {
	int max_count = Disk::get_max_count();
	if (max_count == count) {
		cout << "The disc list is completely filled in. \nDelete some disks to add new" << endl;
		return true;
	}
	else {
		return false;
	}

}

void User::reallocate_memory(int new_size)
{
	Disk* new_disks = new Disk[new_size];
	for (int i = 0; i < size; i++)
	{
		new_disks[i] = disks[i];
	}
	delete[] disks;
	disks = new_disks;
	allocated_memory = new_size;
}

double User::get_total_price() {
	double total_price = 0;
	for (int i = 0; i < size; i++)
	{
		total_price = disks[i].get_price();
	}
	return total_price;
}

void User::push_front(Disk disk)
{
	if (! is_max_disks(size)) {
		if (size == allocated_memory)
		{
			reallocate_memory(allocated_memory + 10);
		}
		for (int i = size; i > 0; i--)
		{
			disks[i] = disks[i - 1];
		}
		disks[0] = disk;
		size++;
		Disk::set_object_count(size);
	}
}

void User::push_back(Disk disk)
{
	if (!is_max_disks(size)) {
		if (size == allocated_memory)
		{
			reallocate_memory(allocated_memory + 10);
		}
		disks[size] = disk;
		size++;
		Disk::set_object_count(size);
	}
}

void User::push_by_index(int index, Disk disk)
{
	if (!is_max_disks(size)) {
		if (size == allocated_memory)
		{
			reallocate_memory(allocated_memory + 10);
		}
		for (int i = size; i > index; i--)
		{
			disks[i] = disks[i - 1];
		}
		disks[index] = disk;
		size++;
		Disk::set_object_count(size);
	}
}

void User::remove_item(Disk disk)
{
	for (int i = 0; i < size; i++)
	{
		if (isEqual(disks[i], disk))
		{
			remove_by_index(i);
			break;
		}
	}
	Disk::set_object_count(size);
}

void User::remove_by_index(int index)
{
	for (int i = index; i < size - 1; i++)
	{
		disks[i] = disks[i + 1];
	}
	size--;
	Disk::set_object_count(size);
}

void User::remove_all()
{
	delete[] disks;
	disks = new Disk[allocated_memory];
	size = 0;
	Disk::set_object_count(size);
}

Disk User::get_item(int index)
{
	return disks[index];
}

int User::get_size()
{
	return size;
}


void User::find_name(string name) {
	bool is_found = false;
	for (int i = 0; i < size; i++)
	{
		if (disks[i].get_name() == name) {
			cout << "Disk " << i + 1 << endl;
			disks[i].print_all();
			is_found = true;
			cout << endl;
		}
	}

	if (!is_found) {
		cout << "Films/disks with your input name is not found" << endl;
	}
}

void User::find_ganre(string ganre) {
	bool is_found = false;
	for (int i = 0; i < size; i++)
	{
		if (disks[i].get_ganre() == ganre) {
			cout << "Disk " << i + 1 << endl;
			disks[i].print_all();
			is_found = true;
			cout << endl;
		}
	}

	if (!is_found) {
		cout << "Films/disks with your input ganre is not found" << endl;
	}
}

void User::find_director(string director) {
	bool is_found = false;
	for (int i = 0; i < size; i++)
	{
		if (disks[i].get_director() == director) {
			cout << "Disk " << i + 1 << endl;
			disks[i].print_all();
			is_found = true;
			cout << endl;
		}
	}

	if (!is_found) {
		cout << "Films/disks with your input director is not found" << endl;
	}
}

void User::max_film_ganre(string ganre) {
	bool is_found = false;
	int max_rating = 0;
	int max_rating_position = 0;
	for (int i = 0; i < size; i++)
	{
		if (disks[i].get_ganre() == ganre) {
			is_found = true;
			if (disks[i].get_rating() > max_rating) {
				max_rating = disks[i].get_rating();
				max_rating_position = i;
			}
		}
	}

	if (!is_found) {
		cout << "Films/disks with your input ganre is not found" << endl;
	}
	else {
		cout << "Disk with max rating in " << ganre << " is " << max_rating_position + 1 << endl;
		disks[max_rating_position].print_all();
	}
}


void User::edit_item(int index, Disk disk)
{
	disks[index] = disk;
}

void User::print_items()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Disk " << i + 1 << endl;
		disks[i].print_all();
	}
}