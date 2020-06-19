#include <iostream>
using namespace std;

template<typename T>
class List
{
public:
	List();

	//pop front
	void pop_front();

	//pop back
	void pop_back();

	//push front
	void push_front(T data);

	//push back
	void push_back(T data);

	//clear - delete all elements
	void clear();

	//get size
	size_t getSize() const { return size; }

	//insert element to index
	void insert(T data, size_t index);

	//remove element at index
	void remove(size_t index);

	//operator []
	T& operator[](const size_t index);

	~List();

private:
	template<typename T>
	class Node
	{
	public:
		Node* next;
		T data;

		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	size_t size;
	Node<T>* head;
};

template<typename T>
List<T>::List()
{
	this->size = 0;
	this->head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	this->head = head->next;

	delete temp;
	this->size--;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (this->head == nullptr)
		this->head = new Node<T>(data);
	else
	{
		Node<T>* current = this->head;

		while (current->next != nullptr)
			current = current->next;
		current->next = new Node<T>(data);
	}

	size++;
}

template<typename T>
void List<T>::clear()
{
	for (size_t i = 0; i < size; i++)
		pop_front();
}

template<typename T>
T& List<T>::operator[](const size_t index)
{
	size_t counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
			return current->data;

		current = current->next;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	this->head = new Node<T>(data, head);
	this->size++;
}

template<typename T>
void List<T>::insert(T data, size_t index)
{

	if (index == 0)
		push_front(data);
	else
	{
		Node<T>* previous = this->head;

		for (size_t i = 0; i < index - 1; i++)
			previous = previous->next;

		Node<T>* newNode = new Node<T>(data, previous->next);
		previous->next = newNode;
		this->size++;
	}
}

template<typename T>
void List<T>::remove(size_t index)
{
	if (index == 0)
		pop_front();
	else
	{
		Node<T>* previous = this->head;

		for (size_t i = 0; i < index - 1; i++)
			previous = previous->next;

		Node<T>* toDelete = previous->next;
		previous->next = toDelete->next;
		delete toDelete;

		this->size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	remove(size - 1);
}