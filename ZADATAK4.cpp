#include <iostream>
using namespace std;

struct troba{
	int sifra;
	char naziv [35];
	char proizvodjac [35];
	troba *sljedeci;
	troba *prethodni;
	troba *lijevo;
	troba *desno;
};

void dodavanje_elementa_na_kraj_liste(troba *lista){
	troba *novi, *zadnji;
	zadnji = lista;
	while (zadnji->sljedeci)
		zadnji = zadnji->sljedeci;
	novi = new troba;
	zadnji -> sljedeci = novi;
	novi -> prethodni = zadnji;
	novi -> sljedeci = NULL;
	cout << "Unesite sifru robe: ";
	cin >> novi->sifra;
	cout << "Naziv robe: ";
	cin >> novi->naziv;
	cout << "Proizvodjac: ";
	cin >> novi->proizvodjac;
}

void dodavanje_elementa_na_pocetak_liste(troba *lista){
	if (!lista->sljedeci){
		dodavanje_elementa_na_kraj_liste(lista);
		return;
	}
	troba *novi, *sljedeci;
	sljedeci = lista->sljedeci;
	novi = new troba;
	novi -> sljedeci = sljedeci;
	novi -> prethodni = lista;
	lista -> sljedeci = novi;
	sljedeci -> prethodni = novi;
	cout << "Unesite sifru robe: ";
	cin >> novi->sifra;
	cout << "Naziv robe: ";
	cin >> novi->naziv;
	cout << "Proizvodjac: ";
	cin >> novi->proizvodjac;
}

void ispis_liste_od_pocetka(troba *lista){
	troba *tekuci = lista -> sljedeci;
	while(tekuci){
		cout << tekuci->sifra << ", " << tekuci->naziv << ", " << tekuci->proizvodjac << ", ";
		tekuci = tekuci->sljedeci;
	}
	cout << "NULL.";
}

void ispis_liste_od_kraja(troba *lista){
	troba *tekuci = lista -> sljedeci;
	while (tekuci->sljedeci)
		tekuci = tekuci->sljedeci;
	while(tekuci!=lista){
		cout << tekuci->sifra << ", " << tekuci->naziv << ", " << tekuci->proizvodjac << ", ";
		tekuci = tekuci->prethodni;
	}
	cout << "glava." << endl;
}

void brisanje_elementa_iz_liste(troba *lista, int sifra_robe){
	troba *brisi = lista -> sljedeci, *prethodni = lista;
	while(brisi){
		if(brisi->sifra==sifra_robe){
			prethodni -> sljedeci = brisi -> sljedeci;
			delete brisi;
			cout << "Element je uspjesno izbrisan!" << endl;
			return;
		}
		prethodni = brisi;
		brisi = brisi -> sljedeci;
	}
	cout << "Element kojeg ste zeljeli izbrisat nije pronadjen!" << endl;
}

void dodaj_element_u_stablo(troba *stablo, int broj){
  troba *zadnji,*novi;
  int dalje = 1;
	zadnji = stablo;
	do{
		if (broj > zadnji->sifra){
			if (zadnji->desno!=NULL){
				zadnji = zadnji -> desno;
			}
		else{ 
			novi = new troba;
			zadnji -> desno = novi;
			novi -> sifra = broj;
			novi -> lijevo = NULL;
			novi -> desno = NULL;
			dalje = 0;
			}
		}
		else{
			if (zadnji->lijevo!=NULL){
				zadnji = zadnji -> lijevo;
			} 
		else{ 
			novi = new troba;
			zadnji -> lijevo = novi;
			novi -> sifra = broj;
			novi -> lijevo = NULL;
			novi -> desno = NULL;
			dalje = 0;
			}
		}
	}while (dalje==1);
};

void sort_uzlazno(troba *stablo){
  	static troba *korijen = stablo;
	if (stablo==NULL) return;
		sort_uzlazno (stablo -> desno);
	if (stablo!=korijen) cout << stablo -> sifra << ", ";
		sort_uzlazno (stablo -> lijevo);
};

int main (){
	troba *lista = new troba;
	troba *stablo = new troba;
	stablo -> lijevo = NULL;
	stablo -> desno = NULL;
	lista -> sljedeci = NULL;
	lista -> prethodni = NULL;
	int izbor, sifra_robe, broj;
	do{
		cout << endl;
		cout << "------------------------MENI---------------------------" << endl;
		cout << "1. za dodavanje elementa na kraj dvostruko vezane liste" << endl;
		cout << "2. za dodavanje elementa na pocetak liste" << endl;
		cout << "3. za ispis liste od pocetka" << endl;
		cout << "4. za ispis liste od kraja" << endl;
		cout << "5. za brisanje elementa iz liste (prema kljucu)" << endl;
		cout << "6. za dodavanje cvora u binarno stablo" << endl;
		cout << "7. za ispis cvorova stabla" << endl;
		cout << "9. za izlaz iz programa" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << endl;
		cin >> izbor; 
		switch(izbor){
			case 1: dodavanje_elementa_na_kraj_liste(lista);break;
			case 2: dodavanje_elementa_na_pocetak_liste(lista);break;
			case 3: ispis_liste_od_pocetka(lista);break;
			case 4: ispis_liste_od_kraja(lista);break;
			case 5: {
				cout << "Unesite element liste kojeg zelite izbrisati: ";
				cin >> sifra_robe;
				brisanje_elementa_iz_liste(lista, sifra_robe);
				break;
			}
			case 6: {
				cout << "Unesite broj: ";
              	cin >> broj;
              	dodaj_element_u_stablo(stablo, broj);
				break;
			}
			case 7: {
				sort_uzlazno(stablo);
              	cout << "." << endl;
				break;
			}
			case 9: break;
		}
	}while(izbor!=9);
	return 0;
}
