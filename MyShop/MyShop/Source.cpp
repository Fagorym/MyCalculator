#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<windows.h>
#include<fstream>
#include <filesystem>
#include<ostream>
/*
Задачи:
1) Ветвление для выхода из магазина ----------------------------------------------------------------------- РЕАЛИЗОВАНО
2) Добавить функцию удаления товара из корзины =>  их добавления на склад(покупатель) --------------------- РЕАЛИЗОВАНО
4) Осуществить удаление товаров из текстового документа (Общее) ------------------------------------------- РЕАЛИЗОВАНО
5) Упростить создание товаров.  --------------------------------------------------- ------------------------РЕАЛИЗОВАНО
6) Добавить перемножение количества товара на его стоимость(общее) -----------------------------------------РЕАЛИЗОВАНО
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
				cout << "Ошибка работы программы!" << endl;
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
	cout << "Добро пожаловать в магазин, вы владелец или покупатель? \n 1 - Владелец \n 2 - Покупатель" << endl; // Меню выбора
	cin >> answerFirst; 
	
	if (answerFirst == 1) {
		while (answerSecond != 0) {
			cout << "Желаете добавить товар в магазин? Нажмите 1.\n";
			cout << "Хотите убрать товар из магазина? Нажмите 2\n";
			cout << "Хотите посмотреть товары на складе? Нажмите 3\n";
			cout << "Для выхода из магазина нажмите 4." << endl;
			cout << "Чтобы стать покупателем нажмите 5." << endl;
			cout << "=============================================================" << endl;
			cin >> answerSecond;



			switch (answerSecond) {


			case 1:
				shop.add_good(shop.make_good());
				cout << "Вы добавили товар в магазин " << endl;
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
				cout << "До свидания,сэр!" << endl;
				return 0;
			case 5:
				cout << "Теперь вы покупатель!" << endl;
				goto link; // 178 строка
			}

		}
	}
	else if (answerFirst == 2) {

		while (answerSecond != 0) {
			link:
			cout << "Желаете положить товар в корзину? Нажмите 1.\n";
			cout << "Желаете выложить товар из корзины? Нажмите 2.\n";
			cout << "Хотите посмотреть содержимое корзины? Нажмите 3\n";
			cout << "Хотите узнать, какие товары есть в магазине? Нажмите 4\n";
			cout << "Хотите рассчитаться за продукты в корзине? Нажмите 5\n";
			cout << "Для выхода из магазина нажмите 6." << endl;
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
				cout << "До свидания!" << endl;
				return 0;
			}
		}
	}
	else {
		cout << "Ошибка ввода данных, попробуйте еще раз" << endl;
		return 0;
	}
	return 0;
}

Goods& Shop::make_good()
{
	// Позволяет создать товар и экономит место в коде
	int  price, count;
	string name;
	cout << "Введите имя товара" << endl;
	SetConsoleCP(1251);
	cin >> name;
	SetConsoleCP(866);
	cout << "Введите цену и количество товара" << endl;
	cin >> price >> count;
	if (price == 0 || count == 0)
		cout << "Ошибка ввода данных, повторите снова" << endl;
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
	// Позволяет добавить товар на склад
	{
		fin.open(path, fstream::app | fstream::out | fstream::in);
		if (!fin.is_open())
		{
			cout << "Ошибка работы программы!" << endl;
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
	// Удаляет товар со склада, добавляет в корзину
	auto it = find(Warehouse.begin(), Warehouse.end(),first);
	if (it == Warehouse.end()) {
		cout << "Такого товара нет в магазине" << endl;
		cout << "=============================================================" << endl;
	}
	else {
		Goods *god = it._Ptr;
		if (first.Count < god->Count) {
			god->Count -= first.Count;
			backet.push_back(first);
			cout << "Вы положили в корзину то, что хотели" << endl;
			cout << "=============================================================" << endl;
		}
		else if (first.Count > god->Count) {
		
			cout << "В данный момент в магазине всего лишь "<< god->Count << " единиц этого товара" << endl;
			cout << "=============================================================" << endl;
		}

		else {
			backet.push_back(*god);
			Warehouse.erase(it);	
			cout << "Вы положили в корзину то, что хотели" << endl;
			cout << "=============================================================" << endl;
		}
	}
}

void Shop::show_Backet()
{
	// Показывает содержимое корзины
	if (backet.empty()) {

		cout << "Корзина пуста!" << endl;
		cout << "=============================================================" << endl;
	}
	else
	{

		for (auto el : backet)
		{
			cout << "Товар: " << el.name << "\t Цена: " << el.price << "\t Количество: " << el.Count << endl;

		}

		cout << "=============================================================" << endl;

	};
}

void Shop::buy_goods()
{ 
	{ // Подсчитывает общую стоимость товаров, очищает корзину

		int TotalPrice = 0; // Создание нужной переменной

		for (auto el : backet) {

			TotalPrice += el.price*el.Count; // Перебор элементов в корзине, подсчет их стоимости.
		}
		if (TotalPrice == 0)
		{
			cout << "*Вы спокойно вышли из магазина*" << endl; // Если товаров нет в корзине

		}
		else {
			cout << "К оплате: " << TotalPrice << " рублей" << endl;
			cout << "=============================================================" << endl;
			backet.clear();
		}
	};
}

void Shop::delete_good(const Goods& first)
{	// Удаляет товар со склада
	auto it = find(Warehouse.begin(), Warehouse.end(), first); // Находит итератор на нужный товар

	Goods *god = it._Ptr; // Создает указатель на данный товар

	if (it != Warehouse.end()) {  // Проверка на то, найден ли нужный товар

		if (god->Count <= first.Count) { // Если его количество больше или равно тому, которое нужно удалить => удаляется весь товар

		Warehouse.erase(it);
		cout << "Данный товар был удален со склада!" << endl;
		cout << "=============================================================" << endl;
		
		
		}

		else if (god->Count > first.Count) { // Если количество меньше того, которое есть на складе => количество на складе уменьшается.

			god->Count -= first.Count;
			cout << "Количество товара было уменьшено на " << first.Count << " единиц" << endl;
			cout << "=============================================================" << endl;
			
		}
	}

	else {

		cout << "Такого товара нету на складе!" << endl;
		cout << "=============================================================" << endl;

	}
};

void Shop::delete_from_backet(const Goods& first){

	auto it = find(backet.begin(), backet.end(), first);

	Goods* god = it._Ptr;


	if (it == backet.end()) {

		cout << "Такого товара нет в вашей корзине" << endl;
		cout << "=============================================================" << endl;
	}

	else {

		if (god->Count <= first.Count)
		{
			Warehouse.push_back(*god);
			backet.erase(it);
			cout << "Вы поместили товар на прилавок." << endl;
			cout << "=============================================================" << endl;
		}
		else if (god->Count > first.Count)
		{
			Warehouse.push_back(first);
			god->Count -= first.Count;
			cout << "Вы поместили часть товара на прилавок." << endl;
			cout << "=============================================================" << endl;
		}


	}

}

void Shop::reload_text()
{

	std::remove("list.txt");
	fin.open(path, fstream::app | fstream::out | fstream::in); // Удаление старого файла, создание нового, запись туда обновленного вектора.
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		for (auto el : Warehouse) {

			fin << el;
		}
		
	}
	fin.close();
}

void Shop::show_Warehouse()
{// Показывает все элементы вектора
	if (Warehouse.empty()) {

		cout << "Склад пуст!" << endl;
		cout << "=============================================================" << endl;
	}
	else
	{
		for (auto el : Warehouse) {

			cout  << "Товар: " << el.name << "\t Цена: " << el.price << "\t Количество: " << el.Count << endl;

		}
		cout << "=============================================================" << endl;

	


	}
}

void Shop::add_good(Goods &first)
{
	{ // Перегруженая функция
		fin.open(path, fstream::app | fstream::out | fstream::in);
		if (!fin.is_open()) // Проверка на открываемость файла
		{
			cout << "Ошибка работы программы!" << endl;
		}
		else {

			Warehouse.push_back(first); // Добавляет товар на склад

			fin << first; // Записывает товар в файл
		}
	}

	fin.close();
} 
