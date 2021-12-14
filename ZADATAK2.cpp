#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;

struct tinventar{
	int sifra;
	char naziv[30];
	int br_komada;
	long vrijeme;
	tinventar *sljedeci;
};

void unos(tinventar *lista){
	tinventar *novi, *zadnji;
	zadnji = lista;
	while(zadnji->sljedeci)
		zadnji = zadnji->sljedeci;
	novi = new tinventar;
	zadnji -> sljedeci = novi;
	novi -> sljedeci = NULL;
	vrijeme_pocetak();
	cout << "Sifra inventara: ";
	cin >> novi->sifra;
	cout << "Naziv inventara: ";
	unos(novi->naziv);
	cout << "Broj komada: ";
	cin >> novi->br_komada;
	vrijeme_kraj();
	novi -> vrijeme = vrijeme_proteklo()/1000;
}

void ispis(tinventar *lista){
	tinventar *tekuci = lista -> sljedeci;
	int suma = 0;
	while(tekuci){
		cout << "Sifra inventara: " << tekuci->sifra << endl;
		suma += tekuci->sifra;
		cout << "Naziv inventara: " << tekuci->naziv << endl;
		cout << "Broj komada: " << tekuci->br_komada << endl;
		cout << "Vrijeme unosa: " << tekuci->vrijeme << " sekundi" << endl;
		cout << "Adresa sljedeceg elementa: " << int((size_t) tekuci -> sljedeci) << endl;
		cout << "----------------------------------" << endl;
		tekuci = tekuci -> sljedeci;
	}
	cout << "Zbroj primarnih kljuceva iznosi: " << suma << endl;
}

void pretrazivanje_liste(tinventar *lista, int sifra_inventara){
	tinventar *tekuci = lista -> sljedeci;
	while(tekuci){
		if (tekuci->sifra==sifra_inventara){
			cout << "Sifra inventara: " << tekuci->sifra << endl;
			cout << "Naziv inventara: " << tekuci->naziv << endl;
			cout << "Broj komada: " << tekuci->br_komada << endl;
			cout << "Vrijeme unosa: " << tekuci->vrijeme << " sekundi" << endl;
			cout << "Adresa sljedeceg elementa: " << float((size_t) tekuci -> sljedeci) << endl;
			cout << "----------------------------------" << endl;
			return;
		}
		tekuci = tekuci->sljedeci;
	}
	cout << "Trazeni element nije pronadjen!" << endl;
}

void brisanje_elementa_liste(tinventar *lista, int sifra_inventara){
	tinventar* brisi = lista -> sljedeci, *prethodni = lista;
	while(brisi){
		if(brisi->sifra==sifra_inventara){
			prethodni -> sljedeci = brisi -> sljedeci;
			delete brisi;
			cout << "Element je uspjesno izbrisan!" << endl;
			return;
		}
		prethodni = brisi;
		brisi = brisi->sljedeci;
	}
	cout << "Trazeni element nije pronadjen!" << endl;
}


int main (){
	tinventar *lista = new tinventar;
	lista -> sljedeci = NULL;
	int izbor, sifra_inventara;
	do{
		cout << endl;
		cout << "-------------------------------MENI------------------------------------" << endl;
		cout << "1. za unos novog elementa vezane liste na kraj" << endl;
		cout << "2. za ispis sadrzaja vezane liste zajedno sa zbrojem primarnih kljuceva" << endl;
		cout << "3. za pretrazivanje vezane liste prema primarnom kljucu" << endl;
		cout << "4. za brisanje elementa lista prema primarnom kljucu" << endl;
		cout << "9. za izlaz iz programa" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		cout << endl;
		cin >> izbor;
		switch(izbor){
			case 1: unos(lista);break;
			case 2: ispis(lista);break;
			case 3: {
				cout << "Unesite sifru inventara: ";
				cin >> sifra_inventara;
				pretrazivanje_liste(lista, sifra_inventara);
				break;
			}
			case 4: {
				cout << "Unesite sifru inventara kojeg zelite obrisati: ";
				cin >> sifra_inventara;
				brisanje_elementa_liste(lista, sifra_inventara);
				break;
			}
			case 9: break;
		}
	}while(izbor!=9);
}
