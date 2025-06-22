#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <iomanip>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define firstPenonton(p) p->firstPenonton
#define infoFilm(p) p->infoFilm
#define nextFilm(p) p->nextFilm
#define prevFilm(p) p->prevFilm
#define nextPenonton(p) p->nextPenonton
#define infoPenonton(p) p->infoPenonton


typedef struct elmFilm *adrfilm;
typedef struct elmPenonton *adrPenonton;
typedef struct film infotypeF;
typedef struct penonton infotypeP;
struct film{
    string Judul;
    float Rating;
    string Sinopsis;
    int Batasan_Umur;
    string Genre;
    string Durasi;
};

struct penonton{
    string Nama;
    int Umur;
};

struct elmFilm{
    infotypeF infoFilm;
    adrfilm nextFilm;
    adrfilm prevFilm;
    adrPenonton firstPenonton;
};

struct elmPenonton{
    infotypeP infoPenonton;
    adrPenonton nextPenonton;;
};

struct List{
    adrfilm first;
    adrfilm last;
};

int Menu();
void backtoMenu(int &opsi);
void pilihan(int opsi,List &L);

void createList(List &L);
adrfilm createElmFilm(infotypeF info);
adrfilm searchFilm(List L, string judul);
void inserLastFilm(List &L, adrfilm P);
void showAllFilm(List L);
void deleteFilm(List &L);
void deleteFirstFilm(List &L, adrfilm &P);
void deleteLastFilm(List &L, adrfilm &P);
void deleteAfterFilm(List &L, adrfilm &P);
void updateFilm(List &L);

adrPenonton createElmPenonton(infotypeP info);
adrPenonton searchPenontonInFilm(List L,string nama);
void insertFirstPenonton(List &L, adrPenonton P, adrfilm F);
void showFilmdanPenonton(List &L);
void deleteFirstPenonton(adrfilm &P, adrPenonton Q);
void deleteLastPenonton(adrfilm &P, adrPenonton Q);
void deleteAfterPenonton(adrfilm &P, adrPenonton Q);
void deletePenonton(List &L);
void updatePenonton(List &L);
int countTotalPenonton(List L);
void Print_penonton(List &L);

void input_test(List &L,infotypeF data,infotypeP dataP);






#endif // TUBES_H_INCLUDED
