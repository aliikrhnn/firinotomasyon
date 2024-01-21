/* AL� KARAHAN 
   ��renci No : 2212721055
   Proje : F�r�n otomasyon projesi	
*/

#include <iostream>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;
void AyarYap();
void AyarGoster();


struct Firin
{

	char derece[30];
	char time[30];
	char urun[30];
	char fan;
};
	Firin ayar;
int main()
{
	setlocale(LC_ALL, "Turkish");
	char secim;
	do
	{
	//console ekran�n� temizler.
	system("cls");
	cout << "|-------------------------------------------------------------------------------------------------|"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|                                          - Ho�geldiniz -                                        |"<<endl;
	cout << "|                                   F�r�n� A�mak i�in '1' e bas�n�z.                              |"<<endl;
	cout << "|                           F�r�n Ayarlar�n�z� g�r�nt�lemek i�in '2' ye bas�n�z.                  |"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|-------------------------------------------------------------------------------------------------|"<<endl;
	secim=getche();
	
	switch(secim)
	{
		
		case '1':
			{
			AyarYap();
			break;	
			}
		case '2':
			{
			AyarGoster();
			break;	
			}

	}

	cout <<endl<< "Ana men�ye d�nmek ister misiniz ? (e/h) "<<endl;
	secim=getche();
	

	}
	while(secim=='e' || secim=='E');
	
	return 0;
}

void AyarYap()
{
	cout << "\n|-------------------------------------------------------------------------------------------------|"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|                                           F�r�n a��ld�.                                         |"<<endl;
	cout << "|                                       Ayarlar�n�z� giriniz.                                     |"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|-------------------------------------------------------------------------------------------------|"<<endl;

	ofstream yaz("firinayarlari.dat",ios::binary | ios::app);
	char secim;
	
	do
	{
	cout << "|                                   F�r�n derecesini giriniz : ";
	cin>>ayar.derece;
	cout << "|                                   Pi�irme dakikas�n� giriniz : ";
	cin>>ayar.time; 
	cout << "|                                   Pi�irmek istedi�iniz �r�n� giriniz: ";
	cin>>ayar.urun;
	cout << "|                                   Fan� a�mak i�in (e/E) ye kapatmak i�in (h/H) ye bas�n�z. ";
	ayar.fan=getche();
	cout << "\n|-------------------------------------------------------------------------------------------------|"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|                                   F�r�n �al��maya ba�lam��t�r...                                |"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|-------------------------------------------------------------------------------------------------|"<<endl;
	yaz.write((char*)&ayar,sizeof(ayar));
	cout << "\nF�r�n� durdurmak ister misiniz ? (e/h)" << endl;
	secim=getche();	
	if(secim=='e'||secim=='E') cout << "\nF�r�n durdurulmu�tur."<<endl;
								
	}while(secim=='e' || secim=='E');
	yaz.close();
	
	
}
void AyarGoster()
{
	
	ifstream oku("firinayarlari.dat",ios::binary | ios::app);

	oku.seekg(0,ios::end);
	int adet=oku.tellg()/sizeof(ayar);
	if(adet>0)
	{
		for(int i=0; i<adet; i++)
		{
			oku.read((char*)&ayar,sizeof(ayar));
			cout << endl;
	cout << "|                                   F�r�n�n derecesi : " << ayar.derece << endl ;
	cout << "|                                   Pi�irme dakikas�n� : "<< ayar.time << endl;
	cout << "|                                   Pi�en �r�n : "<<ayar.urun <<endl;
	if(ayar.fan=='e'|| ayar.fan=='E') 
	cout << "|                                   Fan Durumu :" << " A��k"<<endl;
	else if(ayar.fan=='h' || ayar.fan=='H')
	cout << "|                                   Fan Durumu :" << " Kapal�"<<endl;


		}
		oku.close();
	}
}
	

	

