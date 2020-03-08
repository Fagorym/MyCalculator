#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<windows.h>
#include<fstream>
#include <filesystem>
using namespace std;


fstream fin;
string path = "list.txt";
static int Counter = 0;
class Goods {

public:
	Goods() {
		this->name = "";
		this->Count = this->price = 0;
		this->ID = ++Counter;


	}
	Goods(string name, int price, int count) {

		this->name = name;
		this->Count = count;
		this->price = price;
		this->ID = ++Counter;
	}
	int Count;
	string name;
	int price;
	int ID;
	bool operator ==(const Goods& first) {

		if (this->name == first.name)
		{
			if (this->price == first.price)
			{
				if (this->Count <= first.Count)
				{
					return true;
				}
			}
		}
		else return false;
	}

	void set_count(Goods& first, Goods &second);
	

};
ostream& operator<< (ostream& os, const Goods& good) {


	os << good.name << " " << good.price << " " << good.Count << endl;


	return os;
}
istream& operator>> (istream& is, Goods& good) {


	is >> good.name >> good.price >> good.Count;


	return is;
}
class Shop {
public:
	Shop() {

		vector<Goods> Warehouse;
		vector<Goods> backet;

		{
			fin.open(path, fstream::in | fstream::out | fstream::app);
			if (!fin.is_open())
			{
				cout << "������ ������ ���������!" << endl;
			}
			else {
	
					while (!fin.eof()) {

						Goods god;
						fin >> god;
						if (god.price == 0)
						{
							break;
						}
						else
						Shop::Warehouse.push_back(god);
					
				}
			}

			fin.close();

		}
	}




	void add_good(string name, int price, int count);
	void add_to_backet(const Goods& first);
	void show_Backet();
	void buy_good();
	void delete_good(const Goods& first);
	void show_Warehouse();

private:

	vector<Goods> backet;
	vector<Goods> Warehouse;
	long int TotalPrice = 0;
};

Shop shop;

int main() {
	setlocale(LC_ALL, "ru");
	int answerFirst,answerSecond;
	answerFirst = answerSecond = 0;
	int count, price;
	string name;
	cout << "����� ���������� � �������, �� �������� ��� ����������? \n 1 - �������� \n 2 - ����������" << endl;
	cin >> answerFirst; 
	
	if (answerFirst == 1) {
		while (answerSecond != 5) {
			cout << "������� �������� ����� � �������? ������� 1.\n";
			cout << "������ ������ ����� �� ��������? ������� 2\n";
			cout << "������ ���������� ������ �� ������? ������� 3\n";
			cout << "��� ������ �� �������� ������� 4." << endl;
			cout << "����� ����� ����������� ������� 5." << endl;
			cout << "=============================================================" << endl;
			cin >> answerSecond;



			switch (answerSecond) {

			case 1:
				cout << "������� ��� ������" << endl;
				SetConsoleCP(1251);
				cin >> name;
				SetConsoleCP(866);
				cout << "������� ���� ������" << endl;
				cin >> price;
				cout << "������� ���������� ������" << endl;
				cin >> count;
				shop.add_good(name, price, count);
				cout << "�� �������� ����� � ������� " << endl;
				cout << "=============================================================" << endl;
				break;
			case 2:
				cout << "������� ��� ������" << endl;
				SetConsoleCP(1251);
				cin >> name;
				SetConsoleCP(866);
				cout << "������� ���� ������" << endl;
				cin >> price;
				cout << "������� ���������� ������" << endl;
				cin >> count;
				shop.delete_good(Goods(name, price, count));
				break;
			case 3:
				shop.show_Warehouse();
				break;
			case 4:
				cout << "�� ��������,���!" << endl;
				return 0;
			case 5:
				cout << "������ �� ����������!" << endl;
				goto link;
			}

		}
	}
	else if (answerFirst == 2) {

		while (answerSecond != 5) {
			link:
			cout << "������� �������� ����� � �������? ������� 1.\n";
			cout << "������ ���������� ���������� �������? ������� 2\n";
			cout << "������ ������������ �� �������� � �������? ������� 3\n";
			cout << "��� ������ �� �������� ������� 4." << endl;
			cout << "=============================================================" << endl;
			cin >> answerSecond;
			switch (answerSecond)
			{
			case 1:
				cout << "������� ��� ������" << endl;
				SetConsoleCP(1251);
				cin >> name;
				SetConsoleCP(866);
				cout << "������� ���� ������" << endl;
				cin >> price;
				cout << "������� ���������� ������" << endl;
				cin >> count;
				shop.add_to_backet(Goods(name, price, count));
				break;
			case 2:
				shop.show_Backet();
				break;
			case 3:
				shop.buy_good();
				answerSecond=4;
			case 4:
				cout << "�� ��������!" << endl;
				return 0;
			}
		}
	}
	else {
		cout << "������ ����� ������, ���������� ��� ���" << endl;
		return 0;
	}
	return 0;
}

void Shop::add_good(string name, int price, int count)
{
	{
		fin.open(path, fstream::app | fstream::out | fstream::in);
		if (!fin.is_open())
		{
			cout << "������ ������ ���������!" << endl;
		}
		else {
			
			Goods god(name, price, count);

			Warehouse.push_back(god);

			fin << god;
		}
	}

	fin.close();
}

void Shop::add_to_backet(const Goods &first)
{
	auto it = find(Warehouse.begin(), Warehouse.end(),first);
	if (it == Warehouse.end()) {
		cout << "������ ������ ��� � ��������" << endl;
		cout << "=============================================================" << endl;
	}
	else {
		Goods *god = it._Ptr;
		if (first.Count < god->Count) {
			god->Count -= first.Count;
			backet.push_back(first);
			cout << "�� �������� � ������� ��, ��� ������" << endl;
			cout << "=============================================================" << endl;
		}
		else if (first.Count > god->Count) {
		
			cout << "� ������ ������ � �������� ����� ���� "<< god->Count << " ������ ����� ������" << endl;
			cout << "=============================================================" << endl;
		}

		else {
			backet.push_back(*god);
			Warehouse.erase(it);	
			cout << "�� �������� � ������� ��, ��� ������" << endl;
			cout << "=============================================================" << endl;
		}
	}
}

void Shop::show_Backet()
{

	if (backet.empty()) {

		cout << "������� �����!" << endl;
		cout << "=============================================================" << endl;
	}
	else
	{

		for (auto el : backet)
		{
			cout << "�����: " << el.name << "\t ����: " << el.price << "\t ����������: " << el.Count << endl;

		}

		cout << "=============================================================" << endl;

	};
}

void Shop::buy_good()
{
	{
		for (auto el : backet) {

			TotalPrice += el.price;
		}
		cout << "� ������: " << TotalPrice << " ������" << endl;
		cout << "=============================================================" << endl;
		backet.clear();
	};
}

void Shop::delete_good(const Goods& first)
{	
	auto it = find(Warehouse.begin(), Warehouse.end(), first);

	Goods *god = it._Ptr;

	if (it != Warehouse.end()) {

		if (god->Count <= first.Count) {

			Warehouse.erase(it);
			cout << "������ ����� ��� ������ �� ������!" << endl;
			cout << "=============================================================" << endl;
		}

		else if (god->Count > first.Count) {

			god->Count -= first.Count;
			cout << "���������� ������ ���� ��������� �� " << first.Count << " ������" << endl;
			cout << "=============================================================" << endl;
		}
	}

	else {

		cout << "������ ������ ���� �� ������!" << endl;
		cout << "=============================================================" << endl;

	}
};

void Shop::show_Warehouse()
{
	if (Warehouse.empty()) {

		cout << "����� ����!" << endl;
		cout << "=============================================================" << endl;
	}
	else
	{
		for (auto el : Warehouse) {

			cout << "�����: " << el.name << "\t ����: " << el.price << "\t ����������: " << el.Count << endl;

		}
		cout << "=============================================================" << endl;
	}
}


void Goods::set_count(Goods &first, Goods &second) {






}