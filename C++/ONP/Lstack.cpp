#include "Lstack.h"
#include <iostream>

using namespace std;


bool lisempty(Lstack* head) {            //1.inforacja czy stos jest pusty
	return !head;
}

int lsize(Lstack* head) {                //2.zwracanie iloœci elementów umieszczonych na stosie
	int i = 0;
	while (head != nullptr) {
		i++;
		head = head->next;
	}
	return i;
}

int ltop(Lstack* head) {                 //3.wartosc szczytowego elemetntu na stosie
	return head->value;
}

void lpush(Lstack* &head, int val) {    //4. umieszczanie nowego elementu na szczycie stosu
	Lstack* new_e = new Lstack;
	new_e->value = val;
	new_e->next = head;
	head = new_e;
}

void lpop(Lstack* &head) {              //5.zdjecie istniejacego elementu ze szczutu stosu
	if (head) {
		Lstack * new_e = head;
		head = head->next;
		delete new_e;
	}

}
