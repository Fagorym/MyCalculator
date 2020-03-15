#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<windows.h>
#include<fstream>
#include <filesystem>
#include<ostream>
/*
������:
1) ��������� ��� ������ �� �������� ----------------------------------------------------------------------- �����������
2) �������� ������� �������� ������ �� ������� =>  �� ���������� �� �����(����������) --------------------- �����������
4) ����������� �������� ������� �� ���������� ��������� (�����) ------------------------------------------- �����������
5) ��������� �������� �������.  --------------------------------------------------- ------------------------�����������
6) �������� ������������ ���������� ������ �� ��� ���������(�����) -----------------------------------------�����������
*/
using namespace std;
fstream fin;
string path = "list.txt";
class Goods {

public:


	Goods(string name) {
		this->name = name;
		this->Count = this->price = 0;


	}
	Goods() {
		this->name = "";
		this->Count = this->price = 0;


	}
	Goods(string name, int price, int count) {

		this->name = name;
		this->Count = count;
		this->price = price;
	}
	int Count;
	string name;
	int price;
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


	Goods& make_good();
	void add_good(string name, int price, int count);
	void add_good(Goods &first);
	void add_to_backet(const Goods& first);
	void show_Backet();
	void buy_goods();
	void delete_good(const Goods& first);
	void show_Warehouse();
	void delete_from_backet(const Goods& first);
	void reload_text();

private:

	vector<Goods> backet;
	vector<Goods> Warehouse;
};

Shop shop;
Goods godBless;

int main() {
	setlocale(LC_ALL, "ru");
	int answerFirst,answerSecond;
	answerFirst = answerSecond = 1;
	cout << "����� ���������� � �������, �� �������� ��� ����������? \n 1 - �������� \n 2 - ����������" << endl; // ���� ������
	cin >> answerFirst; 
	
	if (answerFirst == 1) {
		while (answerSecond != 0) {
			cout << "������� �������� ����� � �������? ������� 1.\n";
			cout << "������ ������ ����� �� ��������? ������� 2\n";
			cout << "������ ���������� ������ �� ������? ������� 3\n";
			cout << "��� ������ �� �������� ������� 4." << endl;
			cout << "����� ����� ����������� ������� 5." << endl;
			cout << "=============================================================" << endl;
			cin >> answerSecond;



			switch (answerSecond) {


			case 1:
				shop.add_good(shop.make_good());
				cout << "�� �������� ����� � ������� " << endl;
				cout << "=============================================================" << endl;
				break;
			case 2:
				shop.delete_good(shop.make_good());
				shop.reload_text();
				break;
			case 3:
				shop.show_Warehouse();
				break;
			case 4:
				cout << "�� ��������,���!" << endl;
				return 0;
			case 5:
				cout << "������ �� ����������!" << endl;
				goto link; // 178 ������
			}

		}
	}
	else if (answerFirst == 2) {

		while (answerSecond != 0) {
			link:
			cout << "������� �������� ����� � �������? ������� 1.\n";
			cout << "������� �������� ����� �� �������? ������� 2.\n";
			cout << "������ ���������� ���������� �������? ������� 3\n";
			cout << "������ ������, ����� ������ ���� � ��������? ������� 4\n";
			cout << "������ ������������ �� �������� � �������? ������� 5\n";
			cout << "��� ������ �� �������� ������� 6." << endl;
			cout << "=============================================================" << endl;
			cin >> answerSecond;
			switch (answerSecond)
			{
			case 1:
				shop.add_to_backet(shop.make_good());
				break;
			case 2: 
				shop.delete_from_backet(shop.make_good());
				shop.reload_text();
				break;
			case 3:
				shop.show_Backet();
				break;
			case 4:
				shop.show_Warehouse();
				break;
			case 5:
				shop.buy_goods();
				shop.reload_text();
				answerSecond=4;
			case 6:
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

Goods& Shop::make_good()
{
	// ��������� ������� ����� � �������� ����� � ����
	int  price, count;
	string name;
	cout << "������� ��� ������" << endl;
	SetConsoleCP(1251);
	cin >> name;
	SetConsoleCP(866);
	cout << "������� ���� � ���������� ������" << endl;
	cin >> price >> count;
	if (price == 0 || count == 0)
		cout << "������ ����� ������, ��������� �����" << endl;
	else 
	{
			godBless.Count = count;
			godBless.name = name;
			godBless.price = price;
			return godBless;
		
	}
}

void Shop::add_good(string name, int price, int count)
{
	// ��������� �������� ����� �� �����
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
	// ������� ����� �� ������, ��������� � �������
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
	// ���������� ���������� �������
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

void Shop::buy_goods()
{ 
	{ // ������������ ����� ��������� �������, ������� �������

		int TotalPrice = 0; // �������� ������ ����������

		for (auto el : backet) {

			TotalPrice += el.price*el.Count; // ������� ��������� � �������, ������� �� ���������.
		}
		if (TotalPrice == 0)
		{
			cout << "*�� �������� ����� �� ��������*" << endl; // ���� ������� ��� � �������

		}
		else {
			cout << "� ������: " << TotalPrice << " ������" << endl;
			cout << "=============================================================" << endl;
			backet.clear();
		}
	};
}

void Shop::delete_good(const Goods& first)
{	// ������� ����� �� ������
	auto it = find(Warehouse.begin(), Warehouse.end(), first); // ������� �������� �� ������ �����

	Goods *god = it._Ptr; // ������� ��������� �� ������ �����

	if (it != Warehouse.end()) {  // �������� �� ��, ������ �� ������ �����

		if (god->Count <= first.Count) { // ���� ��� ���������� ������ ��� ����� ����, ������� ����� ������� => ��������� ���� �����

		Warehouse.erase(it);
		cout << "������ ����� ��� ������ �� ������!" << endl;
		cout << "=============================================================" << endl;
		
		
		}

		else if (god->Count > first.Count) { // ���� ���������� ������ ����, ������� ���� �� ������ => ���������� �� ������ �����������.

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

void Shop::delete_from_backet(const Goods& first){

	auto it = find(backet.begin(), backet.end(), first);

	Goods* god = it._Ptr;


	if (it == backet.end()) {

		cout << "������ ������ ��� � ����� �������" << endl;
		cout << "=============================================================" << endl;
	}

	else {

		if (god->Count <= first.Count)
		{
			Warehouse.push_back(*god);
			backet.erase(it);
			cout << "�� ��������� ����� �� ��������." << endl;
			cout << "=============================================================" << endl;
		}
		else if (god->Count > first.Count)
		{
			Warehouse.push_back(first);
			god->Count -= first.Count;
			cout << "�� ��������� ����� ������ �� ��������." << endl;
			cout << "=============================================================" << endl;
		}


	}

}

void Shop::reload_text()
{

	std::remove("list.txt");
	fin.open(path, fstream::app | fstream::out | fstream::in); // �������� ������� �����, �������� ������, ������ ���� ������������ �������.
	if (!fin.is_open()) {
		cout << "������ �������� �����!" << endl;
	}
	else {
		for (auto el : Warehouse) {

			fin << el;
		}
		
	}
	fin.close();
}

void Shop::show_Warehouse()
{// ���������� ��� �������� �������
	if (Warehouse.empty()) {

		cout << "����� ����!" << endl;
		cout << "=============================================================" << endl;
	}
	else
	{
		for (auto el : Warehouse) {

			cout  << "�����: " << el.name << "\t ����: " << el.price << "\t ����������: " << el.Count << endl;

		}
		cout << "=============================================================" << endl;

	


	}
}

void Shop::add_good(Goods &first)
{
	{ // ������������ �������
		fin.open(path, fstream::app | fstream::out | fstream::in);
		if (!fin.is_open()) // �������� �� ������������� �����
		{
			cout << "������ ������ ���������!" << endl;
		}
		else {

			Warehouse.push_back(first); // ��������� ����� �� �����

			fin << first; // ���������� ����� � ����
		}
	}

	fin.close();
} 
