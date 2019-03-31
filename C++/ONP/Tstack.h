
#ifndef TSTACK_H
#define TSTACK_H
#include "Table.h"
struct Tstack {
	int n;
	int wks;
	int *S;
};

bool tisempty(Tstack t); //1.inforacja czy stos jest pusty
int tsize(Tstack t); //2.zwracanie iloœci elementów umieszczonych na stosie
int ttop(Tstack t);	//3.wartoœæ szczytowego elemetntu na stosie
void tpush(Tstack &t,int value); //4. umieszczanie nowego elementu na szczycie stosu
void tpop(Tstack &t);	//5.zdjêcie istniej¹cego elementu ze szczutu stosu

#endif

