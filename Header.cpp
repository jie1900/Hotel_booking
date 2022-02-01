#include "Header.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//The rooms are 0 as not reserved, when they got reserved they are 1.
int single_room[45] = { 0 };
int double_room[90] = { 0 };

Reservation_System LIST[1000];

void Book_System(int a, int n) {
	int y;

	int room_type;
	int book_choice;
	cout << "\tSo you will book new rooms:1 is yes,and 2 is back." << endl;
	cin >> book_choice;
	switch (book_choice) { //Let customers choose what they want, single or double room
	case 1:
		cout << "Please insert your name:" << endl;
		cin.ignore();
		getline(cin, LIST[a].book_name);
		cout << "Choose 1(single room) or 2(double room)" << endl;
		cin >> room_type;
		while (room_type < 1 || room_type > 2) {
			cout << "\tPick 1(Single-Room) or 2(Double-Room)." << endl;
			cin >> room_type;
		}
		if (room_type == 1) { //when they make choice, then we store the information into static.
			LIST[a].room_type = "Single Room";
		}
		else if (room_type == 2) {
			LIST[a].room_type = "Double Room";
		}

		int number_type;
		cout
			<< "\tThank you for making choice of room(s) now is reservation numbers."
			<< endl;
		cout << "\tYou want Machine number or you pick one:" << endl;
		cout << "\t1 is machine number and 2 is yours." << endl;
		cin >> number_type;

		while (room_type < 1 || room_type > 2) { //when they booked rooms, we will offer reservation number choice:Machine created or customer make their own numbers
			cout << "\tPick 1(Machine number) or 2(your number)." << endl;
			cin >> number_type;
		}
		switch (number_type) {

		case 1:
			int x; //This part is random number
			if (number_type == 1) {
				x = rand() % (n / 2);
				while (single_room[x] != 0) { //we use this to check if there repeated rooms, if so, we got new rroms.
					x = rand() % (n / 2);
				}
				LIST[a].room_number = x + 1;
				single_room[x] = single_room[x] + 1;
			}

			else if (number_type == 2) {
				x = rand() % (n / 2) + n / 2;
				while (double_room[x] != 0) {
					x = n / 2 + rand() % (n / 2);
				}
				LIST[a].room_number = x + 1;
				double_room[x] = double_room[x] + 1;
			}

			break;

		case 2:
			int select; //This is numbers you ordered
			y = n / 2;

			if (room_type == 1) {
				cout << "\tInput the number you want from 1 to 45: " << endl;
				cin >> select;
			}
			else if (room_type == 2) {
				cout << "\tInput the number you want from 46 to 90 : " << endl;
				cin >> select;
			}
			break;
		default:
			break;
		}

		bool error;
		int period_1;
		int discount; //There will be discount based on the period you live.
		cout << "\tEnter the days you want to live:" << endl;
		do {
			error = false;
			cin >> period_1;
			if (cin.fail()) {
				cout << "\tPlease input valid days you want to live:";
				error = true;
				cin.clear();
				cin.ignore(80, '\n');
			}
		} while (error);

		while (period_1 < 0) {
			cout << "\tEnter the valid days you want to live:" << endl;
		}
		if (period_1 > 0 && period_1 < 2) {
			discount = 0;
		}
		else if (period_1 > 2 && period_1 < 5) {
			discount = 10;
		}
		else if (period_1 > 5) {
			discount = 20;
		}
		LIST[a].period = period_1;

		int total;
		if (room_type == 1) {
			total = 100 * period_1 * 0.9;
		}
		if (room_type == 2) {
			total = 150 * period_1 * 0.9;
		}
		LIST[a].price = total;

		srand((unsigned)time(0));
		LIST[a].book_number = rand() % 89999 + 10000;

		cout << "\tHere is the order:" << endl;
		cout << "\tReservation Number: " << LIST[a].book_number << endl;
		cout << "\tName: " << LIST[a].book_name << endl;
		cout << "\tRoom Number: " << LIST[a].room_number << endl;
		cout << "\tRoom type: " << LIST[a].room_type << endl;
		cout << "\tYour discount: " << discount << " %" << endl;
		cout << "\tPrice: " << LIST[a].price << endl;

		break;
	case 2:
		break;

	default:
		cout << "Please input 1 or 2." << endl;
		break;
	}
}

void Reservation_Check_System(int Res_Check_Num, int n) {
	int i;
	bool ref = false;
	for (i = 0; i < n; i++) {
		if (LIST[i].book_number == Res_Check_Num) {
			//use bool to check if we have the number in system
			ref = true;

			cout << "\tReservation Number: " << LIST[i].book_number << endl;
			cout << "\tYour name is:" << LIST[i].book_name << endl;
			cout << "\tYour book number is:" << LIST[i].room_number << endl;
			cout << "\tYour room type is:" << LIST[i].room_type << endl;
			cout << "\tYour price is:" << LIST[i].price << endl;
		}
	}
	if (ref == false) {
		cout << "\tThere  is no information in our system." << endl;
	}
	else
		cout << "\tHere is all the information" << endl;

}

void Check_Room_Available(int n) {
	int i, j;
	int Single_Room_Check = 0;
	int Double_Room_Check = 0;

	for (i = 0; i < n / 2; i++) {
		if (single_room[i] == 0) {
			Single_Room_Check = Single_Room_Check + 1;
		}
		//We use 45*0 means we have 45 empty room, if it got reserverted then it will be 1//
	}

	for (j = n / 2; j < n; j++) {
		if (double_room[j] == 0) {
			Double_Room_Check = Double_Room_Check + 1;
		}
	}
	cout << "\tThere are " << Single_Room_Check << " free single rooms and "
		<< Double_Room_Check << " free double rooms." << endl;
	cout << endl;
}
