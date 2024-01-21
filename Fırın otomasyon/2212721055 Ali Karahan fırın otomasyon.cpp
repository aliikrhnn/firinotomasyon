/* ALÝ KARAHAN 
   Öðrenci No : 2212721055
   Proje : Fýrýn otomasyon projesi	
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
	//console ekranýný temizler.
	system("cls");
	cout << "|-------------------------------------------------------------------------------------------------|"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|                                          - Hoþgeldiniz -                                        |"<<endl;
	cout << "|                                   Fýrýný Açmak için '1' e basýnýz.                              |"<<endl;
	cout << "|                           Fýrýn Ayarlarýnýzý görüntülemek için '2' ye basýnýz.                  |"<<endl;
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

	cout <<endl<< "Ana menüye dönmek ister misiniz ? (e/h) "<<endl;
	secim=getche();
	

	}
	while(secim=='e' || secim=='E');
	
	return 0;
}

void AyarYap()
{
	cout << "\n|-------------------------------------------------------------------------------------------------|"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|                                           Fýrýn açýldý.                                         |"<<endl;
	cout << "|                                       Ayarlarýnýzý giriniz.                                     |"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|-------------------------------------------------------------------------------------------------|"<<endl;

	ofstream yaz("firinayarlari.dat",ios::binary | ios::app);
	char secim;
	
	do
	{
	cout << "|                                   Fýrýn derecesini giriniz : ";
	cin>>ayar.derece;
	cout << "|                                   Piþirme dakikasýný giriniz : ";
	cin>>ayar.time; 
	cout << "|                                   Piþirmek istediðiniz ürünü giriniz: ";
	cin>>ayar.urun;
	cout << "|                                   Faný açmak için (e/E) ye kapatmak için (h/H) ye basýnýz. ";
	ayar.fan=getche();
	cout << "\n|-------------------------------------------------------------------------------------------------|"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|                                   Fýrýn çalýþmaya baþlamýþtýr...                                |"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|-------------------------------------------------------------------------------------------------|"<<endl;
	yaz.write((char*)&ayar,sizeof(ayar));
	cout << "\nFýrýný durdurmak ister misiniz ? (e/h)" << endl;
	secim=getche();	
	if(secim=='e'||secim=='E') cout << "\nFýrýn durdurulmuþtur."<<endl;
								
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
	cout << "|                                   Fýrýnýn derecesi : " << ayar.derece << endl ;
	cout << "|                                   Piþirme dakikasýný : "<< ayar.time << endl;
	cout << "|                                   Piþen ürün : "<<ayar.urun <<endl;
	if(ayar.fan=='e'|| ayar.fan=='E') 
	cout << "|                                   Fan Durumu :" << " Açýk"<<endl;
	else if(ayar.fan=='h' || ayar.fan=='H')
	cout << "|                                   Fan Durumu :" << " Kapalý"<<endl;


		}
		oku.close();
	}
}
	

	

