#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Header.h"
using namespace std;

int main() {

	int total_rooms = 90;
	int number;
	bool error;
	int a = 0;

	do {
		//Here is the menu for the hotel.//
		cout << "-----------------------------------------------------------" << endl;
		cout << "\tWelcome to Hotel" << endl;
		cout << "\tHere is the menu you need to choose." << endl;
		cout << "\tInput the number to make orders." << endl;
		cout << "\t1 is to make reservation." << endl;
		cout << "\t2 is to check reservation." << endl;
		cout << "\t3 is to check available rooms." << endl;
		cout << "\t4 is to leave." << endl;
		cout << "Please input your number between 1 to 4." << endl;

		//We have the orders and now will check if the orders are correct.//
		do {
			error = false;
			cin >> number;
			if (cin.fail()) {
				cout << "Sorry, but you need to give a number between 1 to 4." << endl;
				error = true;
				cin.clear();
				cin.ignore(80, '\n');
			}
		} while (error);
		//Make the choice between 1 to 4 and run them.//

		switch (number) {
		case 1: //case 1 is booking hotel system
			cout
				<< "\tWe are happy that you pick us, this would be the best choice you made." << endl;
			cout << "\tWe have 90 rooms." << endl;
			cout
				<< "\tHalf of them are single rooms(100euros per night), \n\tand half are double rooms(150 euros per night)." << endl;
			cout
				<< "\tNumber 1 to 45 are single rooms and Number 46-90 are double rooms." << endl;
			cout << "\tWhat kind room would you like to pick?" << endl;
			cout << "\t10% discount for more than 2 days living." << endl;
			cout << "\t20% discount for more than 4 days living." << endl;

			Book_System(a, total_rooms);
			a++;
			break;
		case 2: //check your reservation
			int Reservation_Check;
			cout
				<< "\tWe offer 1 way to check reservation:1.By reservation number;2.Return to superior" << endl;
			cout << "\tYou just need to input 1 or 2." << endl;
			cout << "\tPlease give us your answer:1 or 2." << endl;
			error = false;
			do {
				error = false;
				cin >> Reservation_Check;
				if (cin.fail()) {
					cout
						<< "\tSorry, but you need to give a number: 1(By Reservation Number) or 2(Return)." << endl;
					error = true;
					cin.clear();
					cin.ignore(80, '\n');
				}
			} while (error);

			if (Reservation_Check < 1 || Reservation_Check > 3) { //we use reservation number to check you.
				cout
					<< "\tYou need to give a number: 1(By Reservation Number) or 2(Return)." << endl;
				do {
					error = false;
					cin >> Reservation_Check;
					if (cin.fail()) {
						cout
							<< "\tSorry, but you need to give a number: 1(By Reservation Number) or 2(Return)." << endl;
						error = true;
						cin.clear();
						cin.ignore(80, '\n');
					}
				} while (error);
			}

			if (Reservation_Check == 1) {
				int Reservation_Number;
				cout << "\tYou can input reservation number now:" << endl;
				cin >> Reservation_Number;
				Reservation_Check_System(Reservation_Number, total_rooms);
			}

			else if (Reservation_Check == 2) {
				break;
			}

			break;
		case 3:
			Check_Room_Available(total_rooms);
			break;
		default:
			break;
		}
	} while (number != 4);

	cout << "\tThank you for checking our hotel." << endl;
	cout << "\tKiitos Paljon!" << endl;
	cout << "\tEnjoy your Christamas Holiday!" << endl;
	return 0;
}
