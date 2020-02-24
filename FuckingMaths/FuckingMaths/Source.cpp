#include<iostream>

using namespace std;



template <class T>


class SecondList {

private:

	int Size;

	

public:
	template <class T>
	class Node {
	public:
		T Data;
		Node* pNext;
		Node* pPrevious;



	public:
		Node(T Data=Data(), Node* pNext = nullptr, Node*pPrevious = nullptr) {
			
			this->Data= Data;
			this->pNext = pNext;
			this->pPrevious = pPrevious;
			



		}



	};

	SecondList();
	~SecondList();
	int GetSize() {

		return Size;

	}
	void push_back(T data);
	void push_front(T data);
	void insert(T data, int index);
	void pop_front();
	void pop_back();
	void clear();
	T& operator[](const int index);
	Node<T>* head;
	Node<T>* tail;

};


template <class T>
SecondList<T>::SecondList() {

	head = nullptr;
	
	tail = nullptr;
	
	Size = 0;

}

template <class T>
SecondList<T>::~SecondList() {

	clear();


}

template<class T>
void SecondList<T>::push_back(T data)
{

	if (head == nullptr) {

		head = new Node<T>(data);

	

	}

	else if (tail == nullptr) {

		tail = new Node<T>(data);

		head->pNext = tail;

		tail->pPrevious = head;

		

	}

	else {

		Node<T> *current = tail;

		tail = new Node<T>(data);

		current->pNext = tail;

		tail->pPrevious = current;

	}

	Size++;

}

template<class T>
void SecondList<T>::push_front(T data)
{
	if (tail == nullptr) {

		tail = new Node<T>(data);

	}
	
	else if (head == nullptr) {

		head = new Node<T>(data);

		tail->pPrevious = head;

		head->pNext = tail;

	}
	else {

		Node<T>* current = head;

		head = new Node<T>(data);

		current->pPrevious = head;

		head->pNext = current;


	}

	


	Size++;
}

template<class T>
void SecondList<T>::insert(T data, int index)
{

	

	if (index == 0)
	{
		push_front(data);
	}
	else if (index == Size)
	{
		push_back(data);
	}
	else if (index > Size) cout << "Ошибка индекса." << endl;

	else if (index < 0) cout << "Ошибка индекса" << endl;

	else {
		Node<T>* previous = this->head;

		for (int i = 0; i < index-1; i++)
		{

			previous = previous->pNext;

		}

		Node<T>* newNode = new Node<T>(data, previous->pNext, previous);
		Node<T>* nextNode = previous->pNext;
		previous->pNext = newNode;
		nextNode->pPrevious = newNode;
		
		
		Size++;
	}


}

template<class T>
void SecondList<T>::pop_front()
{
	if (head == nullptr)
		cout << "Вы не создали ни один из элементов списка" << endl;

	else {
		Node<T>* current = head;

		head = current->pNext;

		delete current;

		head->pPrevious = nullptr;

		Size--;
	}

}

template<class T>
void SecondList<T>::pop_back()
{
	if (head == nullptr)
		cout << "Вы не создали ни один из элементов списка" << endl;

	else {
		Node<T>* current = tail;

		tail = tail->pPrevious;

		delete current;

		tail->pNext = nullptr;

		Size--;
		
	}
	
}

template<class T>
void SecondList<T>::clear()
{
	while(Size!=0)
	pop_back();
}

template<class T>
T& SecondList<T>::operator[](const int index)
{
	Node<T>* current = head;

	if (index == 0)
		return head->Data;

	else if (index == Size - 1)
		return tail->Data;

	else 
		for (int i = 0; i < index; i++)
		{
			current = current->pNext;
		}
	return current->Data;
}






int main() {

	setlocale(LC_ALL, "ru");


	SecondList < int > lst;

	lst.push_back(12);



	lst.push_back(98);




	lst.push_back(129);


	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;


	}
	cout << "---------------------------------------" << endl;

	lst.insert(5, 2);


	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;


	}

	return 0;
}

