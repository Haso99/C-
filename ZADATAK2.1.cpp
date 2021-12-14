#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;

struct tstudent{
	int mat_br;
	char prez_ime[35];
	int god_stu;
	tstudent *sljedeci;
};

void dodavanje_elementa_na_kraj_liste(tstudent *lista){
	tstudent *novi, *zadnji;
	zadnji = lista;
	while(zadnji->sljedeci)
		zadnji = zadnji->sljedeci;
	novi = new tstudent;
	zadnji -> sljedeci = novi;
	novi -> sljedeci = NULL;
	cout << "UNESITE PODATKE O STUDENTU" << endl;
	cout << "Maticni broj studenta: ";
	cin >> novi->mat_br;
	cout << "Ime i prezime studenta: ";
	unos(novi->prez_ime);
	cout << "Godina studija: ";
	cin >> novi->god_stu;
}

void ispis_svih_elemenata(tstudent *lista){
	tstudent *tekuci = lista -> sljedeci;
	while(tekuci){
		cout << "Maticni broj studenta: " << tekuci->mat_br << endl;
		cout << "Ime i prezime studenta: " << tekuci->prez_ime << endl;
		cout << "Godina studija: " << tekuci->god_stu << endl;
		cout << "------------------------" << endl;
		tekuci = tekuci->sljedeci;
	};
}

void pretrazivanje_liste(tstudent *lista, int mat_br){
	tstudent *tekuci = lista -> sljedeci;
	while(tekuci){
		if(tekuci->mat_br==mat_br){
			cout << "Maticni broj studenta: " << tekuci->mat_br << endl;
			cout << "Ime i prezime studenta: " << tekuci->prez_ime << endl;
			cout << "Godina studija: " << tekuci->god_stu << endl;
			cout << "------------------------" << endl;
			return;
		}
		tekuci = tekuci->sljedeci;
	}
	cout << "Trazeni student ne postoji!" << endl;
}

void brisanje_elementa(tstudent *lista, int mat_br){
	tstudent *brisi = lista -> sljedeci, *prethodni = lista;
	while(brisi){
		if(brisi->mat_br==mat_br){
			prethodni -> sljedeci = brisi -> sljedeci;
			delete brisi;
			cout << "USPJESNO STE OBRISALI STUDENTA!" << endl;
			return;
		}
		prethodni = brisi;
		brisi = brisi->sljedeci;
	}
	cout << "Student kojeg ste zeljeli izbrisati ne postoji!" << endl;
}

int main (){
	tstudent *lista = new tstudent;
	lista -> sljedeci = NULL;
	int izbor,mat_br;
	do{
		cout << endl;
		cout << "--------------------MENI-------------------" << endl;
		cout << "1. za dodavanje elementa na kraj liste" << endl;
		cout << "2. za ispis svih elemenata liste" << endl;
		cout << "3. za pretrazivanje liste prema kljucu" << endl;
		cout << "4. za brisanje elementa liste prema kljucu" << endl;
		cout << "9. za izlaz iz programa" << endl;
		cout << "---------------------------------------------" << endl;
		cout << endl;
		cin >> izbor;
		switch(izbor){
			case 1: dodavanje_elementa_na_kraj_liste(lista);break;
			case 2: ispis_svih_elemenata(lista);break;
			case 3: {
				cout << "Unesite maticni broj: ";
				cin >> mat_br;
				pretrazivanje_liste(lista, mat_br);
				break;
			}
			case 4: {
				cout << "Unesite maticni broj studenta kojeg zelite obrisati: ";
				cin >> mat_br;
				brisanje_elementa(lista, mat_br);
				break;
			}
			case 9: break;
		}
	}while(izbor!=9);
	return 0;
}
