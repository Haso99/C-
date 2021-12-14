#include <iostream>
#include <cstring>
#include <cmath>
#include "biblioteka_vrijeme.cc"
#include <iomanip>
using namespace std;


struct tstudent{
	int mat_broj;
	char prez_ime[30];
	int god_stu;
};

void staticka_varijabla(){
	tstudent student, memcpy_funkcija;
	cout << "Unesite maticni broj studenta: ";
	cin >> student.mat_broj;
	strcpy(student.prez_ime, "Hasan Colakovic");
	cout << "Unesite godinu studija: ";
	cin >> student.god_stu;
	memcpy(&memcpy_funkcija, &student, sizeof(tstudent));
	cout << "----------------------------" << endl;
	cout << "ISPIS:" << endl;
	cout << "Maticni broj studenta: " << memcpy_funkcija.mat_broj << endl;
	cout << "Przeime i ime: " << memcpy_funkcija.prez_ime << endl;
	cout << "Godina studija: " << memcpy_funkcija.god_stu << endl;
}

void dinamicko_polje(){
	string d_polje[3] = {"ventilator", "radni stol", "olovka"};
	for (int i=0; i<(sizeof(d_polje)/sizeof(*d_polje)); i++){
		cout << d_polje[i] << endl;
	}
}

double pravokutnik(){
	double a,b,P;
	cout << "Unesite stranicu a: ";
	cin >> a;
	if (a<0 || a==0){
		do{
			cout << "STRANICA MORA BITI POZITIVNA, POKUSAJTE PONOVO!" << endl;
			cout << "Unesite stranicu a: "; 
			cin >> a;
		}while(a<0 || a==0);
	}
	
	cout << "Unesite stranicu b: ";
	cin >> b;
	if (b<0 || b==0){
		do{
			cout << "STRANICA MORA BITI POZITIVNA, POKUSAJTE PONOVO!" << endl;
			cout << "Unesite stranicu b: "; 
			cin >> b;
		}while(b<0 || b==0);
	}
	
	P = a*b;
	cout << "Povrsina pravokutnika iznosi: " << P << endl;
}

float heronova_formula(){
	float a,b,c;
	do{
		vrijeme_pocetak();
		cout << "Unesite 3 stranice trokuta: " << endl;
		cin >> a >> b >> c;
		if(a>=0 || b>0 || c>=0){
			if(a+b>c && a+c>b && b+c>a){
				float s = (a+b+c)/2;
				float A = s*(s-a)*(s-b)*(s-c);
				float rezultat = pow(A,2);
				cout << "Povrsina trokuta iznosi: " << rezultat << endl;
				vrijeme_kraj();
				break;
			}
			cout << "Unesene stranice ne cine trokut, pokusajte ponovo!" << endl;
		}
	}while(a>=0 || b>=0 || c>=0);
	cout << "Trebalo vam je " << setprecision(4) << vrijeme_proteklo()/100 << " tisucinki sekunde!" << endl;
}

int main (){
	int izbor;
	
	do{
		cout << "------------MENI----------------" << endl;
		cout << endl;
		cout << "1. za ispis sadrzaja dinamickog polja" << endl;
		cout << "2. za izracunavanje povrsine pravokutnika" << endl;
		cout << "3. za unos i ispis podataka studenta" << endl;
		cout << "4. za racunanje povrsine trokuta uz pomoc Heronove formule" << endl;
		cout << "9. za izlaz iz programa" << endl;
		cout << "--------------------------------" << endl;
		cin >> izbor;
		switch(izbor){
			case 1: dinamicko_polje();break;
			case 2: pravokutnik();break;
			case 3: staticka_varijabla();break;
			case 4: heronova_formula();break;
			case 9: break;
		}
	}while(izbor!=9);
	return 0;
}
