
#include "Tstack.h"
#include "Table.h"
#include <iostream>

using namespace std;

bool tisempty(Tstack t) {               //1.informacja czy stos jest pusty
	return !t.wks;
}

int tsize(Tstack t) {                   //2.zwracanie iloœci elementów umieszczonych na stosie
	return t.wks;
}

int ttop(Tstack t) {                    //3.wartoœæ szczytowego elemetntu na stosie
	if (t.wks != 0)
		return t.S[t.wks - 1];
}

void tpush(Tstack &t,int value) {       //4. umieszczanie nowego elementu na szczycie stosu
	if (t.wks < t.n) {
		t.S[t.wks] = value;
		t.wks++;
	}
}

void tpop(Tstack &t) {                  //5.zdjêcie istniej¹cego elementu ze szczutu stosu
	*(t.S + (t.wks - 1)) = NULL;
	t.wks--;
}
