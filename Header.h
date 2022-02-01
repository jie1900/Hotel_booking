#pragma once
#include<iostream>
#include<string>
using namespace std;

void Reservation_Check_System(int, int);
void Check_Room_Available(int);
void Book_System(int, int);

struct Reservation_System {
	int book_number;
	int room_number;
	string room_type;
	string book_name;
	int price;
	int period;
};
