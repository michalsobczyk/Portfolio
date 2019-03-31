#include <cstdlib>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


SDL_Surface *screen;
SDL_Surface *obraz;
SDL_Surface *tlo;
SDL_Rect tloDane;
SDL_Rect tloCel;
SDL_Surface *przycisk[3];
int width = 900;
int height = 600;
char const* tytul = "Projekt";
SDL_Rect przyciskDane;
SDL_Rect przyciskCel[3];
int myszkaX, myszkaY;



struct SDL_5bitColor{
    Uint8 r;
    Uint8 g;
    Uint8 b;
};

SDL_Color *tempTab2 = new SDL_Color [32]; // dedykowana paleta

SDL_5bitColor gradient[32]={
{0,0,0}, //0
{0,0,1}, //1
{0,1,0}, //2
{0,1,1}, //3
{0,2,0}, //4
{0,2,1}, //5
{0,3,0}, //6
{0,3,1}, //7
{1,0,0}, //8
{1,0,1}, //9
{1,1,0}, //10
{1,1,1}, //11
{1,2,0}, //12
{1,2,1}, //13
{1,3,0}, //14
{1,3,1}, //15
{2,0,0}, //16
{2,0,1}, //17
{2,1,0}, //18
{2,1,1}, //19
{2,2,0}, //20
{2,2,1}, //21
{2,3,0}, //22
{2,3,1}, //23
{3,0,0}, //24
{3,0,1}, //25
{3,1,0}, //26
{3,1,1}, //27
{3,2,0}, //28
{3,2,1}, //29
{3,3,0}, //30
{3,3,1} //31
};

void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B);
SDL_Color getPixel (int x, int y);
void czyscEkran(Uint8 R, Uint8 G, Uint8 B);
SDL_5bitColor przesuniecieBitowe(int x, int y);
void set5bitPixel(int x, int y, SDL_5bitColor bit5);
SDL_5bitColor poszukiwanieSomsiada(int x, int y);
void ladujBMP(char const* nazwa, int x, int y);

void Funkcja1();
void Funkcja2();
void Funkcja3();
void Funkcja4();
void Funkcja5();
void Funkcja6();


void listaKolorowDelete(SDL_Color *tab){
    delete [] tab;
}

SDL_Color *listaKolorow(int widthPic, int heightPic){
    int arrayLength = widthPic*heightPic;
    SDL_Color *tab = new SDL_Color [arrayLength];
    for(int i = 0; i < width/2; i++){
        for (int j = 0; j < height/2; j++){
            tab[i*height/2 + j] = getPixel(i, j);
        }
    }
    return tab;
}

SDL_Color srednia (SDL_Color kolor1, SDL_Color kolor2){
    SDL_Color srednia;
    int srR = kolor1.r+kolor2.r/2;
    int srG = kolor1.g+kolor2.g/2;
    int srB = kolor1.b+kolor2.b/2;
    srednia.r = srR;
    srednia.g = srG;
    srednia.b = srB;
    return srednia;
}

void sortowanieListyKolorow(SDL_Color *listaKolor, int *lista, int arrayLength){
    int k;
    unsigned int R = 0, srR = 0;
    unsigned int G = 0, srG = 0;
    unsigned int B = 0, srB = 0;
    for(int i = 0; i < arrayLength; i++){
            R += listaKolor[i].r;
            G += listaKolor[i].g;
            B += listaKolor[i].b;
    }
    srR = R/arrayLength;
    srG = G/arrayLength;
    srB = B/arrayLength;
    //for(int i = 0; i < arrayLength; i++) lista[i] = sqrt(listaKolor[i].r*listaKolor[i].r+listaKolor[i].g*listaKolor[i].g+listaKolor[i].b*listaKolor[i].b);
    for(int i = 0; i < arrayLength; i++) lista[i] = (srR*listaKolor[i].r) + (srG*listaKolor[i].g) + (srB*listaKolor[i].b);
    //for(int i = 0; i < arrayLength; i++) lista[i] = (0.299*listaKolor[i].r) + (0.587*listaKolor[i].g) + (0.114*listaKolor[i].b);
    //for(int i = 0; i < arrayLength; i++) lista[i] = (0.2126*listaKolor[i].r) + (0.7152*listaKolor[i].g) + (0.0722*listaKolor[i].b);
    for(int i = 0; i < arrayLength; i++){
        k = i;
        for(int j = i+1; j<arrayLength; j++){
            if(lista[j]>lista[k]) k=j;
        }
        swap(lista[k], lista[i]);
        swap(listaKolor[k], listaKolor[i]);
    }
    /*
    if ((R >= G && R >= B) && G >=B ){
        for(int i = 0; i < arrayLength; i++){
            k = i;
            for (int j = i+1; j < arrayLength; j++){
                if (listaKolor[j].r > listaKolor[k].r) k = j;
                else if (listaKolor[j].r == listaKolor[k].r && listaKolor[j].g > listaKolor[k].g) k = j;
                else if (listaKolor[j].r == listaKolor[k].r && listaKolor[j].g == listaKolor[k].g && listaKolor[j].b > listaKolor[k].b) k = j;
            }
            swap (listaKolor[k], listaKolor[i]);
        }
    }
    else if ((R >= G && R >= B) && B > G){
        for(int i = 0; i < arrayLength; i++){
            k = i;
            for (int j = i+1; j < arrayLength; j++){
                if (listaKolor[j].r > listaKolor[k].r) k = j;
                else if (listaKolor[j].r == listaKolor[k].r && listaKolor[j].b > listaKolor[k].b) k = j;
                else if (listaKolor[j].r == listaKolor[k].r && listaKolor[j].b == listaKolor[k].b && listaKolor[j].g > listaKolor[k].g) k = j;
            }
            swap (listaKolor[k], listaKolor[i]);
        }
    }
    else if ((G >= R && G >= B) && R >= B){
        for(int i = 0; i < arrayLength; i++){
            k = i;
            for (int j = i+1; j < arrayLength; j++){
                if (listaKolor[j].g > listaKolor[k].g) k = j;
                else if (listaKolor[j].g == listaKolor[k].g && listaKolor[j].r > listaKolor[k].r) k = j;
                else if (listaKolor[j].g == listaKolor[k].g && listaKolor[j].r == listaKolor[k].r && listaKolor[j].b > listaKolor[k].b) k = j;
            }
            swap (listaKolor[k], listaKolor[i]);
        }
    }
    else if ((G >= R && G >= B) && B > R){
        for(int i = 0; i < arrayLength; i++){
            k = i;
            for (int j = i+1; j < arrayLength; j++){
                if (listaKolor[j].g > listaKolor[k].g) k = j;
                else if (listaKolor[j].g == listaKolor[k].g && listaKolor[j].b > listaKolor[k].b) k = j;
                else if (listaKolor[j].g == listaKolor[k].g && listaKolor[j].b == listaKolor[k].b && listaKolor[j].r > listaKolor[k].r) k = j;
            }
            swap (listaKolor[k], listaKolor[i]);
        }
    }
    else if ((B >= R && B >= G) && R >= G){
        for(int i = 0; i < arrayLength; i++){
            k = i;
            for (int j = i+1; j < arrayLength; j++){
                if (listaKolor[j].b > listaKolor[k].b) k = j;
                else if (listaKolor[j].b == listaKolor[k].b && listaKolor[j].r > listaKolor[k].r) k = j;
                else if (listaKolor[j].b == listaKolor[k].b && listaKolor[j].r == listaKolor[k].r && listaKolor[j].g > listaKolor[k].g) k = j;
            }
            swap (listaKolor[k], listaKolor[i]);
        }
    }
    else if ((B >= R && B >= G) && G > R){
        for(int i = 0; i < arrayLength; i++){
            k = i;
            for (int j = i+1; j < arrayLength; j++){
                if (listaKolor[j].b > listaKolor[k].b) k = j;
                else if (listaKolor[j].b == listaKolor[k].b && listaKolor[j].g > listaKolor[k].g) k = j;
                else if (listaKolor[j].b == listaKolor[k].b && listaKolor[j].g == listaKolor[k].g && listaKolor[j].r > listaKolor[k].r) k = j;
            }
            swap (listaKolor[k], listaKolor[i]);
        }
    }*/
}

void showSortedTab (SDL_Color *listaKolor){
    unsigned int temp = 0;
    for (int i = 0; i < width/2; i++){
        for (int j = 0; j < height/2; j++){
            temp++;
            setPixel(i+450, j, listaKolor[temp-1].r, listaKolor[temp-1].g, listaKolor[temp-1].b);
        }
    }
}

void wpiszObrazekDoTablicy (SDL_Color *listaKolor, int arrayLength){
    unsigned int temp = 0;
    for (int i = 0; i < width/2; i++){
        for (int j = 0; j < height/2; j++){
            listaKolor[temp] = getPixel (i+450, j);
            temp++;
        }
    }
}

void podzielNaBloki (int poczatek, SDL_Color *listaKolor, int koniec){
    /*if (counter == 5){
        unsigned int R = 0, G = 0, B = 0, elem = 0;
        unsigned int srR, srG, srB;
        for (int i = poczatek; i < koniec; i++){
            R += listaKolor[i].r;
            G += listaKolor[i].g;
            B += listaKolor[i].b;
            elem++;
        }
        srR = R/elem;
        srG = G/elem;
        srB = B/elem;
        for (int i = poczatek; i < koniec; i++){
            listaKolor[i].r = srR;
            listaKolor[i].g = srG;
            listaKolor[i].b = srB;
        }
    }
    else{
        counter = counter + 1;
        int srodek = (koniec-poczatek)/2;
        podzielNaBloki(poczatek, listaKolor, srodek, counter);
        setPixel (500+counter, 500, 255, 255, 0);
        SDL_Flip(screen);
        podzielNaBloki(srodek+1, listaKolor, koniec, counter);
        setPixel (500+counter, 500, 255, 255, 0);
        SDL_Flip(screen);
    }*/
    unsigned int R, G, B, elem;
    unsigned int srR, srG, srB;
    for (int j = 0; j < 32; j++){
        R=0, G=0, B=0, elem=0, srR=0, srG=0, srB=0;
        for (int i = 4218*j; i < 4218*j+4218; i++){
                R += listaKolor[i].r;
                G += listaKolor[i].g;
                B += listaKolor[i].b;
                elem++;
        }
        srR = R/elem;
        srG = G/elem;
        srB = B/elem;
        for (int i = 4218*j; i < 4218*j+4218; i++){
            listaKolor[i].r = srR;
            listaKolor[i].g = srG;
            listaKolor[i].b = srB;
        }
    }
}


void bit5paleta(){

    int kolor=0;
    for(int i=1;i<640;i++){
        for(int j=0;j<height;j++){
                set5bitPixel(i,j,gradient[kolor]);

        }
        if(i%20 == 0)
                    kolor++;
    }

}

SDL_5bitColor przesuniecieBitowe(int x, int y){
    //RRGGB
    int R, G, B;
    SDL_5bitColor bit5;
    SDL_Color kolor;
    kolor = getPixel(x,y);
    R = kolor.r; G = kolor.g; B=kolor.b;
            // R
    if(R <= 63)
        bit5.r = 0;
    else if(R >= 64 && R <= 127)
        bit5.r = 1;
    else if(R >= 128 && R <= 191)
        bit5.r = 2;
    else if(R >= 192 && R <= 255)
        bit5.r = 3;

    if(G <= 63)
        bit5.g = 0;
    else if(G >= 64 && G <= 127)
        bit5.g= 1;
    else if(G >= 128 && G <= 191)
        bit5.g = 2;
    else if(G >= 192 && G <= 255)
        bit5.g = 3;

    if(B <= 127)
        bit5.b = 0;
    else if(B >= 128)
        bit5.b = 1;

    return bit5;
}

int przesuniecieBitoweBW(int x, int y){
    //RRGGB
    int R, G, B;
    SDL_5bitColor bit5;
    SDL_Color kolor;
    kolor = getPixel(x,y);
    R = kolor.r; G = kolor.g; B=kolor.b;

    int BW = (0.299*R) + (0.587*G) + (0.114*B);

    int bit5BW= BW/8;

    return bit5BW;
}

SDL_5bitColor poszukiwanieSomsiada(int x, int y){
    //RRGGB
    int R, G, B;
    SDL_5bitColor bit5;
    SDL_Color kolor;
    kolor = getPixel(x,y);
    R = kolor.r; G = kolor.g; B=kolor.b;
            // R
    // 0 85 170 255 //

    if(0+R <= 85-R)
        bit5.r = 0;
    else if(R-85 <= 170-R)
        bit5.r = 1;
    else if(R-170 <= 255-R)
        bit5.r = 2;
    else if(R-170 >= 255-R)
        bit5.r = 3;

    if(0+G <= 85-G)
        bit5.g = 0;
    else if(G-85 <= 170-G)
        bit5.g= 1;
    else if(G-170 <= 255-G)
        bit5.g = 2;
    else if(G-170 >= 255-G)
        bit5.g = 3;

    if(0+B < 255 -B)
        bit5.b = 0;
    else
        bit5.b = 1;

    return bit5;
}

void set5bitPixel(int x, int y, SDL_5bitColor bit5){

    int R, G, B;

    if(bit5.r == 0)
        R = 0;
    else if(bit5.r == 1)
        R = 85;
    else if(bit5.r == 2)
        R = 170;
    else if(bit5.r == 3)
        R = 255;

    if(bit5.g == 0)
        G = 0;
    else if(bit5.g == 1)
        G = 85;
    else if(bit5.g == 2)
        G = 170;
    else if(bit5.g == 3)
        G = 255;

    if(bit5.b == 0)
        B = 0;
    else if(bit5.b == 1)
        B = 255;

    setPixel(x,y,R,G,B);
}

void set5bitPixelBW(int x, int y, int BW){
    setPixel(x,y,BW*8,BW*8,BW*8);
}

int dopasujKolor(SDL_5bitColor bit5){
    int index=0;

    while(bit5.r!=0)
        index+=8, bit5.r--;
    while(bit5.g!=0)
        index+=2, bit5.g--;
    while(bit5.b!=0)
        index+=1, bit5.b--;

    return index;
}

SDL_Color findColor(SDL_Color* listaKolor, SDL_Color pixel, int &minimum){
    for (int i = 1; i < 32; i++) if (sqrt((pixel.r-listaKolor[i].r)*(pixel.r-listaKolor[i].r)+
                                          (pixel.g-listaKolor[i].g)*(pixel.g-listaKolor[i].g)+
                                          (pixel.b-listaKolor[i].b)*(pixel.b-listaKolor[i].b)) <
                                     sqrt((pixel.r-listaKolor[minimum].r)*(pixel.r-listaKolor[minimum].r)+
                                          (pixel.g-listaKolor[minimum].g)*(pixel.g-listaKolor[minimum].g)+
                                          (pixel.b-listaKolor[minimum].b)*(pixel.b-listaKolor[minimum].b)) )
                                            minimum = i;
    return listaKolor[minimum];
}

void showV(vector <vector <int> > wektor, vector <int> word){
    for(int i=0;i<20;i++)
        cout<<word[i]<<" ";

    cout<<endl;

    for(int i=0;i<20;i++)
        cout<<wektor[i][0]<<" "<<wektor[i][1]<<" "<<wektor[i][2]<<endl, getchar();

}

vector <int> subStr(vector <int> wektor){
    vector <int> W;
    for(int i=0;i<wektor.size()-1;i++)
        W.push_back(wektor[i]);
    return W;
}

vector <vector <int> > LZ77(vector <int> word){

    vector < vector <int> > outPut;
    vector <int> temp;

    int siz=32;
    map<vector <int>,int> hm;

    int k=1;

    for(int i=0;i<word.size();i++)
    {

        temp.push_back(word[i]);

        if(temp.size()==1 && hm.find(temp)==hm.end()){

            hm[temp]=k++;
            vector <int> p;
            p.push_back(0);
            p.push_back(0);
            p.push_back(temp[0]);
            outPut.push_back(p);
            //cout<<"<"<<0<<",0,"<<temp[0]<<">"<<endl;
            temp.clear();
        }

        else if(temp.size()<siz && hm.find(temp)==hm.end()){

            vector <int> already_pres=subStr(temp);

            hm[temp]=k;
            k+=temp.size();
            vector <int> p;
            p.push_back(temp.size()-1);
            p.push_back(hm[already_pres]);
            p.push_back(temp[temp.size()-1]);
            outPut.push_back(p);
            //cout<<"<"<<temp.size()-1<<","<<hm[already_pres]<<","<<temp[temp.size()-1]<<">"<<endl;
            temp.clear();
        }

        else if(temp.size()>=siz){

            vector <int> already_pres=subStr(temp);

            hm[temp]=k;
            k+=temp.size();
            vector <int> p;
            p.push_back(temp.size()-1);
            p.push_back(hm[already_pres]);
            p.push_back(temp[temp.size()-1]);
            outPut.push_back(p);
            //cout<<"<"<<temp.size()-1<<","<<hm[already_pres]<<","<<temp[temp.size()-1]<<">"<<endl;
            temp.clear();
            //hm[temp]=k++;
            //temp.clear();
        }
    }

    if(temp.size() != 0){

        vector <int> already_pres=subStr(temp);
        hm[temp]=k++;
        vector <int> p;
        p.push_back(0);
        p.push_back(hm[already_pres]);
        p.push_back(temp[temp.size()-1]);
        outPut.push_back(p);
        //cout<<"<"<<0<<","<<hm[already_pres]<<","<<temp[temp.size()-1]<<">"<<endl;
    }
    return outPut;
}

void LZ77save(vector <vector <int> > wektor){

    fstream plik( "LZ77.txt", ios::out );
    if( plik.good() )
    {
        for( int i = 0; i < wektor.size(); i++ )
        {
            plik << wektor[i][0] <<" "<<wektor[i][1]<<" "<<wektor[i][2]<<endl;
            //plik.flush();
        }
        plik.close();
    }
}

vector <int> LZ77decoder(vector < vector <int> > wektor){

    vector <int> decoding;
    for(int i=0;i<wektor.size();i++){
        if(wektor[i][0]==0)
                decoding.push_back(wektor[i][2]);
        else if(wektor[i][0]!=0 && wektor[i][1]!=0){
                int przesuwnica=wektor[i][1]-1;
                int znacznik=przesuwnica+wektor[i][0];
                while(przesuwnica!=znacznik)
                    decoding.push_back(decoding[przesuwnica]), przesuwnica++;
                decoding.push_back(wektor[i][2]);
        }
    }
    return decoding;
}

void showDecoded1(vector <int> decoding){
    int k=0;
    for(int i=0;i<width/2;i++){
        for(int j=0;j<height/2;j++){
             set5bitPixel(i+450,j+300,gradient[decoding[k]]);
             k++;
        }
    }
}

void showDecoded2(vector <int> decoding){
    int k=0;
    int BW=0;
    for(int i=0;i<width/2;i++){
        for(int j=0;j<height/2;j++){
            BW=decoding[k];
            set5bitPixelBW(i+450,j+300,BW);
            k++;
        }
    }
}

void showDecoded3(vector <int> decoding){
    int k=0;
    int index=0;
    for(int i=0;i<width/2;i++){
        for(int j=0;j<height/2;j++){
            index=decoding[k];
            setPixel(i+450,j+300,tempTab2[index].r,tempTab2[index].g,tempTab2[index].b);
            k++;
        }
    }
}

void ditheringInGreyScale5bitColor(int startX, int startY){      // dla 5bit pixeli

    SDL_Color kolor ;
    int accurateBlackWhite ;
    //int act

    float errors[(width/2) + 2][(height/2) + 2] ; // zeby nie pisac warunkow przekroczenia tablicy
    memset(errors, 0, sizeof(errors)) ;

    int blad = 0 ;
    int przesuniecie = 1 ; // aby nie wyjsc pponizej (-1) tabeli bladow

    for(int y=startY; y<startY + 300; y++){
        for(int x=startX; x< startX + 450; x++){
           kolor = getPixel(x,y) ;
           accurateBlackWhite = 0.299 * kolor.r + 0.587 * kolor.g + 0.114 * kolor.b;
           accurateBlackWhite += errors[(x - startX) + przesuniecie][y - startY] ;

           for(int i=0; i<=32; i++){
                if(i == 32) {
                    setPixel(x + 450, y, 255, 255, 255) ;
                    blad = accurateBlackWhite - 255 ;
                    break ;
                }
                else if(accurateBlackWhite < 3 + (8 * i) ){
                    setPixel(x + 450, y, 8 * i, 8 * i, 8 * i );
                    blad = accurateBlackWhite - (8 * i) ;
                    break ;
                }
           }

            errors[(x - startX)+przesuniecie + 1][(y - startY)    ] += (blad * 7.0 / 16.0 ) ;
            errors[(x - startX)+przesuniecie + 1][(y - startY) + 1] += (blad * 1.0 / 16.0 ) ;
            errors[(x - startX)+przesuniecie    ][(y - startY) + 1] += (blad * 5.0 / 16.0 ) ;
            errors[(x - startX)+przesuniecie -1 ][(y - startY) + 1] += (blad * 3.0 / 16.0 ) ;
        }
    }
}
                    // dithering 2 - > paleta dedykowana

void ditheringInOriginalScale(int startX, int startY){      // dla 5bit pixeli

    SDL_Color kolor ;
    SDL_5bitColor kolor5bit ;
    int actualR ;
    int actualG ;
    int actualB ;
    //int act

    float errorsR[(width/2) + 2][(height/2) + 2] ; //
    float errorsG[(width/2) + 2][(height/2) + 2] ; //
    float errorsB[(width/2) + 2][(height/2) + 2] ; //
    memset(errorsR, 0, sizeof(errorsR)) ;
    memset(errorsG, 0, sizeof(errorsG)) ;
    memset(errorsB, 0, sizeof(errorsB)) ;

    int bladR = 0 ;
    int bladG = 0 ;
    int bladB = 0 ;
    int przesuniecie = 1 ; // aby nie wyjsc pponizej (-1) tabeli bladow

    for(int y=startY; y<startY + 300; y++){
        for(int x=startX; x< startX + 450; x++){
           kolor = getPixel(x,y) ;

            actualR = kolor.r ;
            actualR += errorsR[(x - startX) + przesuniecie][y - startY] ;

            actualG = kolor.g ;
            actualG += errorsG[(x - startX) + przesuniecie][y - startY] ;

            actualB = kolor.b ;
            actualB += errorsB[(x - startX) + przesuniecie][y - startY] ;

            if(actualR < 64){           //R
                kolor5bit.r = 0 ;
                bladR = actualR ;
            }
            else if(actualR < 128){
                kolor5bit.r = 1 ;
                bladR = actualR - 85 ;
            }
            else if(actualR < 192){
                kolor5bit.r = 2 ;
                bladR = actualR - 170;
            }
            else{
                kolor5bit.r = 3 ;
                bladR = actualR - 255 ;
            }

            if(actualG < 64){           //G
                kolor5bit.g = 0 ;
                bladG = actualG ;
            }
            else if(actualG < 128){
                kolor5bit.g = 1 ;
                bladG = actualG - 85 ;
            }
            else if(actualG < 192){
                kolor5bit.g = 2 ;
                bladG = actualG - 170;
            }
            else{
                kolor5bit.g = 3 ;
                bladG = actualG - 255 ;
            }

            if(actualB < 128){           //B
                kolor5bit.b = 0 ;
                bladB = actualB ;
            }
            else {
                kolor5bit.b = 1 ;
                bladB = actualB - 255 ;
            }

            set5bitPixel(x+450, y, kolor5bit) ;

            errorsR[(x - startX)+przesuniecie + 1][(y - startY)    ] += (bladR * 7.0 / 16.0 ) ;
            errorsR[(x - startX)+przesuniecie + 1][(y - startY) + 1] += (bladR * 1.0 / 16.0 ) ;
            errorsR[(x - startX)+przesuniecie    ][(y - startY) + 1] += (bladR * 5.0 / 16.0 ) ;
            errorsR[(x - startX)+przesuniecie -1 ][(y - startY) + 1] += (bladR * 3.0 / 16.0 ) ;

            errorsG[(x - startX)+przesuniecie + 1][(y - startY)    ] += (bladG * 7.0 / 16.0 ) ;
            errorsG[(x - startX)+przesuniecie + 1][(y - startY) + 1] += (bladG * 1.0 / 16.0 ) ;
            errorsG[(x - startX)+przesuniecie    ][(y - startY) + 1] += (bladG * 5.0 / 16.0 ) ;
            errorsG[(x - startX)+przesuniecie -1 ][(y - startY) + 1] += (bladG * 3.0 / 16.0 ) ;

            errorsB[(x - startX)+przesuniecie + 1][(y - startY)    ] += (bladB * 7.0 / 16.0 ) ;
            errorsB[(x - startX)+przesuniecie + 1][(y - startY) + 1] += (bladB * 1.0 / 16.0 ) ;
            errorsB[(x - startX)+przesuniecie    ][(y - startY) + 1] += (bladB * 5.0 / 16.0 ) ;
            errorsB[(x - startX)+przesuniecie -1 ][(y - startY) + 1] += (bladB * 3.0 / 16.0 ) ;
        }
    }
}
            // dithering 3 -> paleta narzucona

void set5bitPixelForcedColors(int x, int y, SDL_5bitColor bit5, int *tableRed, int *tableGreen, int *tableBlue){

    int R, G, B;

    if(bit5.r == 0)
        R = tableRed[0];
    else if(bit5.r == 1)
        R = tableRed[1];
    else if(bit5.r == 2)
        R = tableRed[2];
    else if(bit5.r == 3)
        R = tableRed[3];

    if(bit5.g == 0)
        G = tableGreen[0];
    else if(bit5.g == 1)
        G = tableGreen[1];
    else if(bit5.g == 2)
        G = tableGreen[2];
    else if(bit5.g == 3)
        G = tableGreen[3];

    if(bit5.b == 0)
        B = tableBlue[0];
    else if(bit5.b == 1)
        B = tableBlue[1];

    setPixel(x,y,R,G,B);
}

void ditheringInForcedScale(int startX, int startY, int *tableRed, int *tableGreen, int *tableBlue){      // dla 5bit pixeli

    SDL_Color kolor ;
    SDL_5bitColor kolor5bit ;
    int actualR ;
    int actualG ;
    int actualB ;

    float errorsR[(width/2) + 2][(height/2) + 2] ; //
    float errorsG[(width/2) + 2][(height/2) + 2] ; //
    float errorsB[(width/2) + 2][(height/2) + 2] ; //
    memset(errorsR, 0, sizeof(errorsR)) ;
    memset(errorsG, 0, sizeof(errorsG)) ;
    memset(errorsB, 0, sizeof(errorsB)) ;

    int bladR = 0 ;
    int bladG = 0 ;
    int bladB = 0 ;
    int przesuniecie = 1 ; // aby nie wyjsc pponizej (-1) tabeli bladow

    for(int y=startY; y<startY + 300; y++){
        for(int x=startX; x< startX + 450; x++){
           kolor = getPixel(x,y) ;

            actualR = kolor.r ;
            actualR += errorsR[(x - startX) + przesuniecie][y - startY] ;

            actualG = kolor.g ;
            actualG += errorsG[(x - startX) + przesuniecie][y - startY] ;

            actualB = kolor.b ;
            actualB += errorsB[(x - startX) + przesuniecie][y - startY] ;

            if(actualR < 64){           //R
                kolor5bit.r = 0 ;
                bladR = actualR - tableRed[0];
            }
            else if(actualR < 128){
                kolor5bit.r = 1 ;
                bladR = actualR - tableRed[1];
            }
            else if(actualR < 192){
                kolor5bit.r = 2 ;
                bladR = actualR - tableRed[2];
            }
            else{
                kolor5bit.r = 3 ;
                bladR = actualR - tableRed[3];
            }
            if(actualG < 64){           //G
                kolor5bit.g = 0 ;
                bladG = actualG - tableGreen[0];
            }
            else if(actualG < 128){
                kolor5bit.g = 1 ;
                bladG = actualG - tableGreen[1];
            }
            else if(actualG < 192){
                kolor5bit.g = 2 ;
                bladG = actualG - tableGreen[2];
            }
            else{
                kolor5bit.g = 3 ;
                bladG = actualG - tableGreen[3];
            }

            if(actualB < 128){           //B
                kolor5bit.b = 0 ;
                bladB = actualB - tableBlue[0];
            }
            else {
                kolor5bit.b = 1 ;
                bladB = actualB - tableBlue[1] ;
            }

            set5bitPixelForcedColors(x+450, y, kolor5bit, tableRed, tableGreen, tableBlue) ;

            errorsR[(x - startX)+przesuniecie + 1][(y - startY)    ] += (bladR * 7.0 / 16.0 ) ;
            errorsR[(x - startX)+przesuniecie + 1][(y - startY) + 1] += (bladR * 1.0 / 16.0 ) ;
            errorsR[(x - startX)+przesuniecie    ][(y - startY) + 1] += (bladR * 5.0 / 16.0 ) ;
            errorsR[(x - startX)+przesuniecie -1 ][(y - startY) + 1] += (bladR * 3.0 / 16.0 ) ;

            errorsG[(x - startX)+przesuniecie + 1][(y - startY)    ] += (bladG * 7.0 / 16.0 ) ;
            errorsG[(x - startX)+przesuniecie + 1][(y - startY) + 1] += (bladG * 1.0 / 16.0 ) ;
            errorsG[(x - startX)+przesuniecie    ][(y - startY) + 1] += (bladG * 5.0 / 16.0 ) ;
            errorsG[(x - startX)+przesuniecie -1 ][(y - startY) + 1] += (bladG * 3.0 / 16.0 ) ;

            errorsB[(x - startX)+przesuniecie + 1][(y - startY)    ] += (bladB * 7.0 / 16.0 ) ;
            errorsB[(x - startX)+przesuniecie + 1][(y - startY) + 1] += (bladB * 1.0 / 16.0 ) ;
            errorsB[(x - startX)+przesuniecie    ][(y - startY) + 1] += (bladB * 5.0 / 16.0 ) ;
            errorsB[(x - startX)+przesuniecie -1 ][(y - startY) + 1] += (bladB * 3.0 / 16.0 ) ;
        }
    }
}


void Funkcja1(vector <int> &word) {

    ladujBMP("obrazek1.bmp",0,0);
    SDL_5bitColor kolor;
    for(int i=0;i<width/2;i++){
        for(int j=0;j<height/2;j++){
             kolor = przesuniecieBitowe(i,j);
             word.push_back(dopasujKolor(kolor));
             set5bitPixel(i,j+300, kolor);
        }
    }
    int *tableRed = new int[4] ;

    tableRed[0] = 15 ;
    tableRed[1] = 95 ;
    tableRed[2] = 160 ;
    tableRed[3] = 240 ;

    int *tableGreen = new int[4] ;

    tableGreen[0] = 15 ;
    tableGreen[1] = 95 ;
    tableGreen[2] = 160 ;
    tableGreen[3] = 240 ;

    int *tableBlue = new int[2] ;

    tableBlue[0] = 15 ;
    tableBlue[1] = 240 ;

    ditheringInForcedScale(0,0, tableRed, tableGreen, tableBlue) ;
}

void Funkcja2() {

    bit5paleta();
    SDL_Flip(screen);

}


void Funkcja3(vector <int> &word) {

    ladujBMP("1.bmp",0,0);
    int BW=0;
    for(int i=0;i<width/2;i++){
        for(int j=0;j<height/2;j++){
             BW = przesuniecieBitoweBW(i,j);
             word.push_back(BW);
             set5bitPixelBW(i,j+300, BW);
        }
    }
    ditheringInGreyScale5bitColor(0,0) ;
}


void Funkcja4(vector <int> &word, SDL_Color *tempTab2) {

    SDL_Color pixel1, pixel2;
    ladujBMP("obrazek5.bmp",0,0);
    SDL_Flip(screen);
    int* tempTab = new int [135000];
    SDL_Color* tablica = listaKolorow(width/2, height/2);
    sortowanieListyKolorow(tablica, tempTab, 135000);
    podzielNaBloki(0, tablica, 135000);
    delete [] tempTab;
    for(int i = 0; i < 32; i++) tempTab2[i] = tablica[i*4220];
    for(int i = 0; i < width/2; i++){
        for(int j = 0; j < height/2; j++){
            int index=0;
            pixel1 = getPixel(i, j);
            pixel2 = findColor(tempTab2, pixel1,index);
            word.push_back(index);
            setPixel(i, j+300, pixel2.r, pixel2.g, pixel2.b);
        }
    }
    listaKolorowDelete(tablica);
    ditheringInOriginalScale(0,0) ;
//...


    SDL_Flip(screen);

}

                // dithering 1 - > skala szarości



void Funkcja5() {



//...


    SDL_Flip(screen);

}

void Funkcja6() {



//...


    SDL_Flip(screen);

}


void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B)
{
  if ((x>=0) && (x<width) && (y>=0) && (y<height))
  {
    /* Zamieniamy poszczególne składowe koloru na format koloru pixela */
    Uint32 pixel = SDL_MapRGB(screen->format, R, G, B);

    /* Pobieramy informacji ile bajtów zajmuje jeden pixel */
    int bpp = screen->format->BytesPerPixel;

    /* Obliczamy adres pixela */
    Uint8 *p = (Uint8 *)screen->pixels + y * screen->pitch + x * bpp;

    /* Ustawiamy wartość pixela, w zależności od formatu powierzchni*/
    switch(bpp)
    {
        case 1: //8-bit
            *p = pixel;
            break;

        case 2: //16-bit
            *(Uint16 *)p = pixel;
            break;

        case 3: //24-bit
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                p[0] = (pixel >> 16) & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = pixel & 0xff;
            } else {
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
            }
            break;

        case 4: //32-bit
            *(Uint32 *)p = pixel;
            break;

    }
         /* update the screen (aka double buffering) */
  }
}


void ladujBMP(char const* nazwa, int x, int y)
{
    SDL_Surface* bmp = SDL_LoadBMP(nazwa);
    if (!bmp)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
    }
    else
    {
        SDL_Rect dstrect;
        dstrect.x = x;
        dstrect.y = y;
        SDL_BlitSurface(bmp, 0, screen, &dstrect);
        SDL_Flip(screen);
        SDL_FreeSurface(bmp);
    }

}


void czyscEkran(Uint8 R, Uint8 G, Uint8 B)
{
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, R, G, B));
    SDL_Flip(screen);

}

SDL_Color getPixel (int x, int y) {
    SDL_Color color ;
    Uint32 col = 0 ;
    if ((x>=0) && (x<width) && (y>=0) && (y<height)) {
        //determine position
        char* pPosition=(char*)screen->pixels ;
        //offset by y
        pPosition+=(screen->pitch*y) ;
        //offset by x
        pPosition+=(screen->format->BytesPerPixel*x);
        //copy pixel data
        memcpy(&col, pPosition, screen->format->BytesPerPixel);
        //convert color
        SDL_GetRGB(col, screen->format, &color.r, &color.g, &color.b);
    }
    return ( color ) ;
}


int main ( int argc, char** argv )
{


    freopen( "CON", "wt", stdout );
    freopen( "CON", "wt", stderr );

    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    atexit(SDL_Quit);

    screen = SDL_SetVideoMode(width, height, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if ( !screen )
    {
        printf("Unable to set video: %s\n", SDL_GetError());
        return 1;
    }

    SDL_WM_SetCaption( tytul , NULL );

    vector <int> word;
    vector < vector <int> > outPut;
    vector <int> decoding;

    bool done = false;
    tloDane.w = 900;
    tloDane.h = 600;
    tloCel.x = 0;
    tloCel.y = 0;
    przyciskCel[0].x = 650;
    przyciskCel[0].y = 120;
    przyciskCel[1].x = 650;
    przyciskCel[1].y = przyciskCel[0].y + 144;
    przyciskCel[2].x = 650;
    przyciskCel[2].y = przyciskCel[1].y + 144;
    przyciskDane.w = 200;
    przyciskDane.h = 124;
    tlo = SDL_LoadBMP("tlo.bmp");
    przycisk[0] = SDL_LoadBMP("przycisk1.bmp");
    przycisk[1] = SDL_LoadBMP("przycisk2.bmp");
    przycisk[2] = SDL_LoadBMP("przycisk3.bmp");
    SDL_Event event;

     while (!done)
    {

        SDL_FillRect(screen, NULL, 0 );
        SDL_BlitSurface(tlo, &tloDane, screen, &tloCel);
        //SDL_BlitSurface()
        SDL_BlitSurface( przycisk[0], & przyciskDane, screen, & przyciskCel[0] );
        SDL_BlitSurface( przycisk[1], & przyciskDane, screen, & przyciskCel[1] );
        SDL_BlitSurface( przycisk[2], & przyciskDane, screen, & przyciskCel[2] );
        SDL_Flip(screen);

        while( SDL_PollEvent( &event ) )
        {

            if( event.type == SDL_MOUSEMOTION )
            {
                myszkaX = event.motion.x;
                myszkaY = event.motion.y;
            }

            if((myszkaX > przyciskCel[0].x && myszkaX < (przyciskCel[0].x + przyciskDane.w)) && (myszkaY > przyciskCel[0].y && myszkaY < (przyciskCel[0].y + przyciskDane.h)))
                przycisk[0] = SDL_LoadBMP( "przycisk1hover.bmp" );
            else
                przycisk[0] = SDL_LoadBMP( "przycisk1.bmp" );
            if((myszkaX > przyciskCel[1].x && myszkaX < (przyciskCel[1].x + przyciskDane.w)) && (myszkaY > przyciskCel[1].y && myszkaY < (przyciskCel[1].y + przyciskDane.h)))
                przycisk[1] = SDL_LoadBMP( "przycisk2hover.bmp" );
            else
                przycisk[1] = SDL_LoadBMP( "przycisk2.bmp" );
            if((myszkaX > przyciskCel[2].x && myszkaX < (przyciskCel[2].x + przyciskDane.w)) && (myszkaY > przyciskCel[2].y && myszkaY < (przyciskCel[2].y + przyciskDane.h)))
                przycisk[2] = SDL_LoadBMP( "przycisk3hover.bmp" );
            else
                przycisk[2] = SDL_LoadBMP( "przycisk3.bmp" );

            if( event.type == SDL_MOUSEBUTTONDOWN )
            {
                if( event.button.button == SDL_BUTTON_LEFT  && myszkaX > przyciskCel[0].x && myszkaX < (przyciskCel[0].x + przyciskDane.w) && myszkaY > przyciskCel[0].y && myszkaY < (przyciskCel[0].y + przyciskDane.h))
                {
                    tlo = SDL_LoadBMP("tlo1.bmp");
                    SDL_BlitSurface(tlo, &tloDane, screen, &tloCel);
                    Funkcja1(word);
                    outPut=LZ77(word);
                    LZ77save(outPut);
                    decoding=LZ77decoder(outPut);
                    showDecoded1(decoding);
                    SDL_Flip(screen);



                    done = true;
                }

                if( event.button.button == SDL_BUTTON_LEFT  && myszkaX > przyciskCel[1].x && myszkaX < (przyciskCel[1].x + przyciskDane.w) && myszkaY > przyciskCel[1].y && myszkaY < (przyciskCel[1].y + przyciskDane.h))
                {

                    tlo = SDL_LoadBMP("tlo1.bmp");
                    SDL_BlitSurface(tlo, &tloDane, screen, &tloCel);
                    Funkcja3(word);
                    outPut=LZ77(word);
                    LZ77save(outPut);
                    decoding=LZ77decoder(outPut);
                    showDecoded2(decoding);
                    SDL_Flip(screen);
                    SDL_Flip(screen);


                    done = true;
                }

                if( event.button.button == SDL_BUTTON_LEFT  && myszkaX > przyciskCel[2].x && myszkaX < (przyciskCel[2].x + przyciskDane.w) && myszkaY > przyciskCel[2].y && myszkaY < (przyciskCel[2].y + przyciskDane.h))
                {
                    tlo = SDL_LoadBMP("tlo1.bmp");
                    SDL_BlitSurface(tlo, &tloDane, screen, &tloCel);
                    Funkcja4(word, tempTab2);
                    outPut=LZ77(word);
                    LZ77save(outPut);
                    decoding=LZ77decoder(outPut);
                    showDecoded3(decoding);
                    SDL_Flip(screen);
                    done = true;
                }
            }
            if( event.key.keysym.sym == SDLK_ESCAPE ) done = true;

        }
    }

    SDL_FreeSurface(przycisk[0]);
    SDL_FreeSurface(przycisk[1]);
    SDL_FreeSurface(przycisk[2]);
    done=false;
    while (!done){
        while( SDL_PollEvent( &event ) ){
            if( event.type == SDL_MOUSEBUTTONDOWN )
                done=true;
        }
    }
    printf("Exited cleanly\n");
    return 0;
}
