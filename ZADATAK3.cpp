// DVOSTRUKO VEZANA LISTA //

#include <iostream>
using namespace std;

struct telement{
	int broj;
	telement *sljedeci;
	telement *prethodni;
};

void dodavanje_elementa_na_kraj_liste(telement *lista){
	telement *novi, *zadnji;
	zadnji = lista;
	while(zadnji->sljedeci)
		zadnji = zadnji -> sljedeci;
	novi = new telement;
	zadnji -> sljedeci = novi;
	novi -> prethodni = zadnji;
	novi -> sljedeci = NULL;
	cout << "Unesite broj: ";
	cin >> novi->broj;
}

void dodavanje_elementa_na_pocetak_liste(telement *lista){
	if(!lista->sljedeci){
		dodavanje_elementa_na_kraj_liste(lista);
		return;
	}
	telement *novi, *sljedeci;
	sljedeci = lista -> sljedeci;
	novi = new telement;
	novi -> prethodni = lista;
	novi -> sljedeci = sljedeci;
	lista -> sljedeci = novi;
	novi -> sljedeci = sljedeci;
	cout << "Unesite broj: ";
	cin >> novi->broj;
}


void ispis_svih_elemenata_od_pocetka(telement *lista){
	telement *tekuci = lista -> sljedeci;
	while (tekuci){
		cout << tekuci->broj << ", ";
		tekuci = tekuci -> sljedeci;
	}
	cout << "NULL" << endl;
}

void ispis_svih_elemenata_od_kraja(telement *lista){
	telement *tekuci = lista -> sljedeci;
	while (tekuci->sljedeci)
		tekuci = tekuci->sljedeci;
	while (tekuci!=lista){
		cout << tekuci -> broj << ", ";
		tekuci = tekuci -> prethodni;
	}
	cout << "glava" << endl;
}

telement *dealokacija_liste(telement *lista){ 
  telement *tekuci,*prethodni;
  prethodni=lista;
  tekuci=lista->sljedeci;
  while (tekuci){
    delete prethodni;
    prethodni=tekuci;
    tekuci=tekuci->sljedeci;
  }
  delete prethodni;
  return NULL;
};

int main (){
	telement *lista = new telement;
	lista -> sljedeci = NULL;
	lista -> prethodni = NULL;
	int izbor;
	do{
		cout << endl;
		cout << "--------------------MENI---------------------" << endl;
		cout << "1. dodavanje elementa na kraj liste" << endl;
		cout << "2. dodavanje elementa na pocetak liste" << endl;
		cout << "3. ispis svih elemenata od pocetka" << endl;
		cout << "4. ispis svih elemenata od kraja" << endl;
		cout << "9. dealokacija memorije i izlaz iz programa" << endl;
		cout << "---------------------------------------------" << endl;
		cin >> izbor;
		switch(izbor){
			case 1: dodavanje_elementa_na_kraj_liste(lista);break;
			case 2: dodavanje_elementa_na_pocetak_liste(lista);break;
			case 3: ispis_svih_elemenata_od_pocetka(lista);break;
			case 4: ispis_svih_elemenata_od_kraja(lista);break;
			case 9: lista=dealokacija_liste(lista);break;
		}
	}while(izbor!=9);
	return 0;
}
