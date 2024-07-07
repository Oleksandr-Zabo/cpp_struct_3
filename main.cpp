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
	bool main_bool = true;
	do
	{
		system("cls");

		int action;
		do
		{
			cout << "Welcome to the online store!" << endl;
			cout << "0 - Exit" << endl;
			cout << "1 - Add Item" << endl;
			cout << "2 - Remove Item" << endl;
			cout << "3 - Update Item" << endl;
			cout << "4 - Get Total Price" << endl;
			cout << "5 - View All Items" << endl;
			cout << "6 - Find Film With Name" << endl;
			cout << "7 - Find Film With Ganre" << endl;
			cout << "8 - Find Film With Director" << endl;

		} while (action < 0 || action > 9);
		

		
		cin >> action;
		cin.ignore();
		system("cls");
		switch (action)
		{
		case exit_main:
		{
			main_bool = false;
		}break;

		case addItem:
		{
			Disk disk;
			string name;
			cout << "Enter disk/film name: ";
			cin >> name;
			disk.set_name(name);


			string director;
			cout << "Enter film director: ";
			cin >> director;
			disk.set_director(director);

			string ganre;
			cout << "Enter film ganre: ";
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
			user->push_back(disk);
			break;
		}break;

		case removeItem:
		{
			int index;
			cout << "Enter index of disk to remove: ";
			cin >> index;
			user->remove_by_index(index);
		}break;


		// continue work with ||
		//					  ||
		//					  \/
		case updateItem:
		{
			Disk disk;
			string name;
			cout << "Enter disk/film name: ";
			cin >> name;
			disk.set_name(name);


			string director;
			cout << "Enter film director: ";
			cin >> director;
			disk.set_director(director);

			string ganre;
			cout << "Enter film ganre: ";
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
			user->push_back(disk);
			break;

		}break;

		case getTotalPrice:
		{
			cout << "Total price: " << user->get_total_price() << endl;
		}break;
		case viewAllItems:
		{
			user->print();
		}break;
		}
		system("pause");
	} while (main_bool);

	return 0;
}