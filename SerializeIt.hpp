//Saber Interactive - 2
/*
Реализуйте функции сериализации и десериализации двусвязного списка в бинарном формате в файл. Алгоритмическая сложность должна быть быстрее квадратичной.
struct ListNode {
     ListNode *      prev;
     ListNode *      next;
     ListNode *      rand; // указатель на произвольный элемент данного списка либо NULL
     std::string     data;
};

class List {
public:
     void Serialize   (FILE * file);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
     void Deserialize (FILE * file);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))

private:
     ListNode *      head;
     ListNode *      tail;
     int       count;
};
*/
#include <iostream>
#include <fstream>

//для возможности работать с fopen() (unsafe), с помощью которого получен указатель на файл (в соответствии с требованием задания)
//при необходимости добавить в настройках проекта (для MS Visual Studio)
//для gcc/g++ макрос не требуется
#define _CRT_SECURE_NO_DEPRECATE

struct ListNode {
	ListNode * prev;
	ListNode * next;
	ListNode * rand;
	std::string data;
public:
	//конструктор
	ListNode() : prev(NULL), next(NULL), rand(NULL), data("") {}

	ListNode(std::string value) {
		ListNode();
		this->data = value;
	}

	//геттеры/сеттеры полей
	void SetData(std::string value) {
		this->data = value;
	}
	std::string GetData() {
		return this->data;
	}
	void SetNext(ListNode * newNext) {
		this->next = newNext;
	}
	ListNode * GetNext() {
		return this->next;
	}
	void SetPrev(ListNode * newPrev) {
		this->prev = newPrev;
	}
	ListNode * GetPrev() {
		return this->prev;
	}
	void SetRand(ListNode * newRand) {
		this->rand = newRand;
	}
	ListNode * GetRand() {
		return this->rand;
	}
};

class List {
public:

	List() {
		count = 0;
		ListNode * root = new ListNode();
		SetHead(root);
		SetTail(root);
	}

	//функция сериализации
	//
	//
	void Serialize(FILE * file) {
		ListNode * tempHead = this->GetHead();
		ListNode * tempTail = this->GetTail();
		std::string tempStr("");
		while (tempHead != tempTail) {
			tempStr = tempHead->GetData();
			fputs(tempStr.c_str(), file);
			tempHead = tempHead->GetNext();
		}
	}

	//функция десериализации
	//
	//
	void Deserialize(FILE * file) {
		if (file) {
			std::fseek(file, 0, SEEK_END);
			size_t len = std::ftell(file);
			std::fseek(file, 0, SEEK_SET);
			char * input = new char[len];
			std::string tempStr = "";
			std::fread(input, 1, len, file);
			int n(0);
			while (n < len) {
				while (input[n] != '\n') {
					tempStr += input[n];
					n++;
				}
				n++;
				this->AddLast(tempStr);
				tempStr = "";
			}
			delete[] input;
		}
	}

	//менеджмент двусвязного списка
	void AddLast(ListNode * node) {
		if (count == 0) {
			head = node;
			tail = node;
			this->count++;
			return;
		}
		node->SetPrev(this->tail);
		this->GetTail()->SetNext(node);
		this->SetTail(node);
		this->count++;
	}
	void AddLast(std::string value) {
		ListNode * node = new ListNode(value);
		AddLast(node);
	}
	void AddFirst(ListNode * node) {
		if (count == 0) {
			head = node;
			tail = node;
			this->count++;
			return;
		}
		node->SetNext(this->head);
		this->GetHead()->SetPrev(node);
		this->SetHead(node);
		this->count++;
	}
	void AddFirst(std::string value) {
		ListNode * node = new ListNode(value);
		AddFirst(node);
	}

	//геттеры/сеттеры полей
	void SetHead(ListNode * newHead) {
		this->head = newHead;
	}
	ListNode * GetHead() {
		return this->head;
	}
	void SetTail(ListNode * newTail) {
		this->tail = newTail;
	}
	ListNode * GetTail() {
		return this->tail;
	}
	int GetCount() {
		return this->count;
	}

private:
	ListNode * head;
	ListNode * tail;
	int count;
};
