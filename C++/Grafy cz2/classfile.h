#ifndef CLASSFILE_H
#define CLASSFILE_H
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


using namespace std;

struct Wezel_t {
    int wartosc;
    Wezel_t *nastepny;
};

class List {
public:
    Wezel_t *pierwszy;
    Wezel_t *wsk;

    List (){
        pierwszy = nullptr;
        wsk = nullptr;
    }

    void addwart (int wart){
        Wezel_t *newwart = new Wezel_t;
        newwart -> wartosc = wart;
        newwart -> nastepny = pierwszy;
        pierwszy = newwart;
    }

    void popwart() {
        wsk = pierwszy;
        if (wsk != nullptr) {
            pierwszy = wsk->nastepny;
        }
        else {
            cout << "Lista pusta" << endl;
            return;
        }
    }

    int sizeList() {
        wsk = pierwszy;
        int size = 0;
        while (wsk != nullptr) {
            size = size + 1;
            wsk = wsk->nastepny;
        }
        return size;
    }

    int getList(int wart) {
        wsk = pierwszy;
        if (wsk == nullptr) {
            cout << "Lista pusta" << endl;
            return 0;
        }
        int licznikWart = 0;
        while (wsk->nastepny != nullptr && licznikWart != wart) {
            ++licznikWart;
            wsk = wsk->nastepny;
        }
        if (licznikWart == wart) {
            return wsk->wartosc;
        }
        cout << "Lista pusta" << endl;
        return 0;
}
};

#endif // CLASSFILE_H
