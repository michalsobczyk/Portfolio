#include "functions.h"
#include "tree.h"

void addTree (int weight, int value, struct BTNode *start){         // Dodajemy element o wadze i wartosci, tworzy lewa i prawa galaz do ostatnich elementów
    if (root == NULL){
        root = new BTNode;
        root->weightN = 19;
        root->valueN = NULL;
        root->leftN = NULL;
        root->rightN = NULL;
        root->parentN = NULL;
        root->treeLevelN = 0;
    }
    else{
        if(start->leftN != NULL) {
            addTree(weight, value ,start->leftN);
            addTree(weight, value, start->rightN);
        }
        else{
            BTNode *newbieL = new BTNode;
            newbieL->weightN = weight;
            newbieL->valueN = value;
            newbieL->leftN = NULL;
            newbieL->rightN = NULL;
            newbieL->parentN = start;
            newbieL->treeLevelN = treeLevelN + 1;
            start->leftN = newbieL;
            BTNode *newbieR = new BTNode;
            newbieR-> weightN = 0;
            newbieR->leftN = NULL;
            newbieR->rightN = NULL;
            newbieR->parentN = start;
            newbieR->treeLevelN = treeLevelN + 1;
            start->rightN = newbieR;
        }
    }
}

int countK (struct BTNode *start, int &maxWeight){
    int actWeight = 0;
    if (actWeight < maxWeight && (start->treeLevelN) < 5 ){
        actWeight += (start->weightN);
        countK (start->leftN, actWeight, maxWeight);
    }
    else if ((start->treeLevelN) < 5) return start->treeLevelN - 1;
    else if ((start->treeLevelN) == 5) return start->treeLevelN;
    else return 0;
}

int countT (struct BTNode *start, int &k, int actWeight){
    if ((start->treeLevelN) <= k){
        actWeight += (start->weightN);
        countT (start->leftN, k, actWeight)
    }
    else return actWeight;
}

int countB (struct BTNode *start, int &k, int profit){
    if((start->treeLevelN) <= k){
        profit += (start->valueN);
        countB (start->leftN, k, profit);
    }
    else return profit;
}

bool promising (struct BTNode *start, int weight, int maxWeight){
    if (start->leftN != NULL){
        if (weight += (start->weightN) < maxWeight)
            return 1;
    }
    else return 0;
}

float pw (struct BTNode *start, k){
    if (k>1){
        k--;
        pw(start->leftN, k);
    }
    else if (k==1){
        float dz = (start->valueN) / (start->weightN);
        return dz;
    }
}

void backtrackingBackpack (struct BTNode *start, int &maxProfit, int p, int w, int maxWeight, ofstream &out)){
    unsigned int k = countK(start, maxWeight);
    unsigned int t = w + countT(start, k, w);
    unsigned int b;
    if (k < 5){
        int dz = pw(start, k);
        b = (p + countB(start, k, p)) + (maxWeight - t) * dz;
    }
    else b = (p + countB(start, k, p));
    int best = 0;
    if (promising(start, w, maxWeight)){
        w += start->weightN;
        p += start->valueN;
        out << "ide w lewo, ";
        backtrackingBackpack (start->leftN, maxProfit, p, w, maxWeight, out, 0);
    }
    else if ()
    else if (w + start->weightN > maxWeight){
        if (p > best){
            best = p;
            out << "nie ide dalej, bo przekroczylbym maxWage, podmieniam best, wracam ";
            if (start->parentN != NULL) backtrackingBackpack ((start->parentN)->rightN, maxProfit, p, w, maxWeight, out);
        }
        else{
            out << "nie ide dalej, bo przekroczylbym maxWage, wracam ";
            w -= start->weightN;
            p -= start->valueN;
            if (start->parentN != NULL) backtrackingBackpack ((start->parentN)->rightN, maxProfit, p, w, maxWeight, out);
        }
    }
    else if (w + start->weightN == maxWeight && ) {
        if (p + start->valueN > best){
            best = p + start->valueN;
            out << "nie ide dalej, bo wezel nie jest obiecujacy, podmieniam best, wracam ";
            if (start->parentN != NULL) backtrackingBackpack ((start->parentN)->rightN, maxProfit, p, w, maxWeight, out);
        }
        else {
            out << "nie ide dalej, bo wezel nie jest obiecujacy, wracam ";
            if (start->parentN != NULL) backtrackingBackpack ((start->parentN)->rightN, maxProfit, p, w, maxWeight, out);
        }
    }
    else if (start->leftN == NULL) {
        if (p > best){
            best = p;
            out << "Nie ide dalej, bo wezel nie ma dzieci, podmieniam best, wracam ";
            if (start->parentN != NULL) backtrackingBackpack ((start->parentN)->rightN, maxProfit, p, w, maxWeight, out);
        }
        else{
            out << "Nie ide dalej, bo wezel nie ma dzieci, wracam ";
            if (start->parentN != NULL) backtrackingBackpack ((start->parentN)->rightN, maxProfit, p, w, maxWeight, out);
        }
    }
}
