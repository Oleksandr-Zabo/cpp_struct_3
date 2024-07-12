#include "user.h"

enum UserAction
{
	exit_main = 0,
	addItem,
	removeItem,
	updateItem,
	getTotalPrice,

	viewAllItems,
	findName, 
	findGanre,
	findDirector,
	maxRatingInGanre
	
};

int main()
{

	User* user = new User();

	//create start disks
	Disk disk1("Avatar", "James Cameron", "sci-fi", 4, 15);
	Disk disk2("Bad Boys", "George Gallo", "comedy", 5, 12);
	Disk disk3("Interstellar", "Christopher Nolan", "sci-fi", 5, 14);
	Disk disk4("The Dark Knight", "Christopher Nolan", "sci-fi", 4, 11);
	Disk disk5("Johnny English", "Neal Purvis", "comedy", 4, 10);
	//add disks to user
	user->push_back(disk1);
	user->push_back(disk2);
	user->push_back(disk3);
	user->push_back(disk4);
	user->push_back(disk5);

	//show start user disks
	cout << "Welcome to the online disk store!" << endl;
	cout << "Here are the discs to choose from" << endl;
	user->print_items();
	system("pause");

	bool main_bool = true;
	do
	{
		system("cls");

		int action;
		do
		{
			cout << "Main menu:" << endl;
			cout << "0 - Exit" << endl;
			cout << "1 - Add Item" << endl;
			cout << "2 - Remove Item" << endl;
			cout << "3 - Update Item" << endl;
			cout << "4 - Get Total Price" << endl;
			cout << "5 - View All Items" << endl;
			cout << "6 - Find Film With Name" << endl;
			cout << "7 - Find Film With Ganre" << endl;
			cout << "8 - Find Film With Director" << endl;

			cin >> action;
			cin.ignore();

		} while (action < 0 || action > 9);

		system("cls");
		switch (action)
		{
		case exit_main:
		{
			system("cls");
			main_bool = false;
		}break;

		case addItem:
		{

			int index;
			do
			{
				cout << "Enter index of disk to add: ";
				cin >> index;
			} while (index < 0 || index > user->get_size());

			Disk disk;
			string name;
			cout << "Enter disk/film director: ";
			cin >> name;
			disk.set_name(name);


			string director;
			cout << "Enter film director: ";
			cin >> director;
			disk.set_director(director);

			string ganre;
			cout << "Enter film director: ";
			cin >> ganre;
			disk.set_director(ganre);

			int rating;
			cout << "Enter film rating: ";
			cin >> rating;
			disk.set_rating(rating);

			double price;
			cout << "Enter disk price: ";
			cin >> price;
			disk.set_price(price);
			user->push_by_index(index, disk);
			system("pause");


			system("cls");
			user->print_items();
			system("pause");
			break;
		}break;

		case removeItem:
		{
			
			user->print_items();
			system("pause");
			system("cls");

			int index;
			do
			{
				cout << "Enter index of disk to remove: ";
				cin >> index;
			} while (index < 0 || index < user->get_size());
			user->remove_by_index(index);
			system("pause");

			system("cls");
			user->print_items();
			system("pause");
		}break;


		
		case updateItem:
		{
			int index;
			
			do
			{
				cout << "Enter index of disk to update: ";
				cin >> index;
			} while (index < 0 || index < user->get_size());
			
			user->remove_by_index(index);

			Disk disk;
			string name;
			cout << "Enter disk/film director: ";
			cin >> name;
			disk.set_name(name);


			string director;
			cout << "Enter film director: ";
			cin >> director;
			disk.set_director(director);

			string ganre;
			cout << "Enter film director: ";
			cin >> ganre;
			disk.set_director(ganre);

			int rating;
			cout << "Enter film rating: ";
			cin >> rating;
			disk.set_rating(rating);

			double price;
			cout << "Enter disk price: ";
			cin >> price;
			disk.set_price(price);
			user->push_by_index(index, disk);

			system("pause");

			system("cls");
			user->print_items();
			system("pause");

		}break;

		case getTotalPrice:
		{
			cout << "Total price: " << user->get_total_price() << endl;
			system("pause");
		}break;


		case viewAllItems:
		{
			user->print_items();
			system("pause");
		}break;

		case findName:
		{
			string name;
			cout << "Enter name: ";
			cin >> name;
			user->find_name(name);
			system("pause");
		}break;

		case findGanre:
		{
			string ganre;
			cout << "Enter ganre: ";
			cin >> ganre;
			user->find_ganre(ganre);
			system("pause");
		}break;

		case findDirector:
		{
			string director;
			cout << "Enter director: ";
			cin >> director;
			user->find_director(director);
			system("pause");
		}break;

		case maxRatingInGanre:
		{
			string ganre;
			cout << "Enter ganre: ";
			cin >> ganre;
			user->max_film_ganre(ganre);
			system("pause");
		}break;

		}
		system("pause");
	} while (main_bool);

	return 0;
}