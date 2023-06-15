#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
struct Elem
{
	// Любые данные
	T data;
	Elem* next, * prev;
};
template <typename T>
class List
{
	// Голова хвост
	Elem<T>* Head, * Tail;
	int Count;
public:
	List();
	List(const List&);
	~List();
	int GetCount();
	Elem<T>GetHead() { return Head; }
	Elem<T>* GetElem(int);
	void DelAll();
	void Del(int);
	void AddTail(T);
	void AddHead(T);
	void Print();
	List& operator = (const List&);
	List operator + (const List&);
    List operator * (const List&);

	Elem<T>* Clone(List& L);   
};


template <typename T>
List<T>::List()
{
	Head = Tail = 0;
	Count = 0;
}

template <typename T>
List<T>::List(const List& L)
{
	Head = Tail = 0;
	Count = 0;

	Elem<T>* temp = L.Head;

	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

template <typename T>
List<T>::~List()
{
	DelAll();
}

template <typename T>
Elem<T>* List<T>::GetElem(int pos)
{
	Elem<T>* temp = Head;
	//Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		//Неверная позиция
		cout << "Incorrect position !!!\n";
	}
	return;
	int i = 1;
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}

	if (temp == 0)
		return 0;
	else
		return temp;
}

template <typename T>
void List<T>::AddHead(T n)
{
	Elem<T>* temp = new Elem<T>;
	temp->prev = 0;
	temp->data = n;
	temp->next = Head;
	if (Head != 0)
		(*Head).prev = temp;

	if (Count == 0)
		Head = Tail = temp;
	else
		Head = temp;
	Count++;
}

template <typename T>
void List<T>::AddTail(T n)
{
	Elem<T>* temp = new Elem<T>;
	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;
	if (Tail != 0)
		Tail->next = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;
	Count++;
}

template <typename T>                               ///////////////////////////////////////
Elem<T>* List<T>::Clone(List<T>& L)  // клонируем текущий список в L
{
	if (L.Head != 0) L.DelAll();  //!!!!!!!!!
	L.Head = L.Tail = 0;
	L.Count = 0;

	Elem<T>* temp = Head; // не L.Head, берем голову текущего списка

	while (temp != 0)
	{
		L.AddTail(temp->data);  //добавляем элементы в L 
		temp = temp->next;
	}
	return L.Head;
}

template <typename T>
void List<T>::Print()
{
	if (Count != 0)
	{
		Elem<T>* temp = Head;
		while (temp != 0)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
	}
}
template <typename T>
void List<T>::Del(int n)
{
	if (n < 1 || n > Count)
	{
		cout << "Incorrect position !!!\n";
		return;
	}
	int i = 1;
	Elem<T>* Del = Head;
	while (i < n)
	{
		//Доходим до элемента, который удаляется
		Del = Del->next;
		i++;
	}
	//Доходим до элемента, который предшествует
	//удаляемому
	Elem<T>* PrevDel = Del->prev;
	//Доходим до элемента, который следует за
	//удаляемым
	Elem<T>* AfterDel = Del->next;
	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;
	if (n == 1)
		Head = AfterDel;
	if (n == Count)
		Tail = PrevDel;
	delete Del;
	Count--;
}
template <typename T>
void List<T>::DelAll()
{
	while (Count != 0)
		Del(1);
}
template <typename T>
int List<T>::GetCount()
{
	return Count;
}
template <typename T>
List<T>& List<T>::operator = (const List<T>& Q_int)
{
	if (this == &Q_int)
		return *this;
	this->~List();
	Elem<T>* temp = Q_int.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
	return *this;
}
template <typename T>
List<T> List<T>::operator + (const List<T>& L)
{
	List Result(*this);
	Elem<T>* temp = L.Head;
	while (temp != 0)
	{
		Result.AddTail(temp->data);
		temp = temp->next;
	}
	return Result;
}

template<typename T>
List<T> List<T>::operator * (const List& L)   //  ?????
{
	List Result(*this);
	
	return Result;
		
}


int main()
{
	setlocale(0, "");
	List<int> Q_int1;
	List<int> Q_int2;
	List<double> Q_doub;
	List<double> Q_doubClone; //!!!!!!!!!!!!!!
	List<char> Q_ch;
	
	char number;
	do
	{
		cout << "1. Заполнить список в очереди" << endl;
		cout << "2. Вывести  список в очереди" << endl;
		cout << "3. Клонировать  список в очереди" << endl;
		cout << "4. Operator +" << endl;
		cout << "5. Operator *" << endl;
		cout << "0. Выйти\n\n";
		cout << "Номер меню -> ";
		cin >> number;
		switch (number)
		{
		case '1':
		{
			for (int i = 1; i < 11; i++) Q_int1.AddHead(rand() % 10);
			for (int i = 1; i < 11; i++) Q_int2.AddHead(rand() % 10);
			for (int i = 1; i < 11; i++) Q_doub.AddHead(rand() % 255 * 0.1);
			for (int i = 1; i < 11; i++) Q_ch.AddHead(rand() % 255);
			system("cls");
			cout << "Очередь заполнена \n\n";
		}
		break;

		case '2':
		{
			Q_int1.Print();
			cout << endl;
			Q_int2.Print();
			cout << endl;
			Q_doub.Print();
			cout << endl;
			Q_ch.Print();
			cout << endl << endl;
		}
		break;

		case '3':  Q_doub.Clone(Q_doubClone); 
			cout << "Первоначальный список : ";			
			Q_doub.Print();			
			cout << endl;
			cout << "Клонированный список  : ";			
			Q_doubClone.Print();			
			cout << endl << endl;
			break;

		case '4':
		{
			Q_doub = Q_doub + Q_doubClone;
			Q_doub.Print();
			cout << endl << endl;
		}
		break;
		case '5':
		{
			List<int> Q_int_int;
			Q_int_int = Q_int1 * Q_int2;			
			Q_int_int.Print();
			cout << endl << endl;
		}
		break;

		case '0': break;
		default: cout << endl << "Не верный выбор \n\n";
			break;
		}
	} while (number != '0');



	return 0;
}
