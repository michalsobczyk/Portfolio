#ifndef LSTACK_H
#define LSTACK_H

struct Lstack {
	int value;
	Lstack* next;
};

bool lisempty(Lstack* head); //1.inforacja czy stos jest pusty
int lsize(Lstack* head); //2.zwracanie iloœci elementów umieszczonych na stosie
int ltop(Lstack* head);	//3.wartoœæ szczytowego elemetntu na stosie
void lpush(Lstack* &head,int value); //4. umieszczanie nowego elementu na szczycie stosu
void lpop(Lstack* &head);	//5.zdjêcie istniej¹cego elementu ze szczutu stosu

#endif
