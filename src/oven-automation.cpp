/* Oven Automation
   BLG-101 Introduction to Algorithms and Programming
   Isparta University of Applied Sciences
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
	//console ekranını temizler.
	system("cls");
	cout << "|------------------------------------------------------------------------------------------------|"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|                                          - Hoşgeldiniz -                                    |"<<endl;
	cout << "|                                   Fırını Açmak için '1' e basınız.                          |"<<endl;
	cout << "|                           Fırın Ayarlarınızı görüntülemek için '2' ye basınız.                  |"<<endl;
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
	cout << "|                                           Fırın açıldı.                                         |"<<endl;
	cout << "|                                       Ayarlarınızı giriniz.                                     |"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|-------------------------------------------------------------------------------------------------|"<<endl;

	ofstream yaz("firinayarlari.dat",ios::binary | ios::app);
	char secim;
	
	do
	{
	cout << "|                                   Fırın derecesini giriniz : ";
	cin>>ayar.derece;
	cout << "|                                   Pişirme dakikasını giriniz : ";
	cin>>ayar.time; 
	cout << "|                                   Pişirmek istediğiniz ürünü giriniz: ";
	cin>>ayar.urun;
	cout << "|                                   Fanı açmak için (e/E) ye kapatmak için (h/H) ye basınız. ";
	ayar.fan=getche();
	cout << "\n|-------------------------------------------------------------------------------------------------|"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|                                   Fırın çalışmaya başlamıştır...                                |"<<endl;
	cout << "|                                                                                                 |"<<endl;
	cout << "|-------------------------------------------------------------------------------------------------|"<<endl;
	yaz.write((char*)&ayar,sizeof(ayar));
	cout << "\nFırını durdurmak ister misiniz ? (e/h)" << endl;
	secim=getche();	
	if(secim=='e'||secim=='E') cout << "\nFırın durdurulmuştur."<<endl;
								
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
	cout << "|                                   Fırının derecesi : " << ayar.derece << endl ;
	cout << "|                                   Pişirme dakikasını : "<< ayar.time << endl;
	cout << "|                                   Pişen ürün : "<<ayar.urun <<endl;
	if(ayar.fan=='e'|| ayar.fan=='E') 
	cout << "|                                   Fan Durumu :" << " Açık"<<endl;
	else if(ayar.fan=='h' || ayar.fan=='H')
	cout << "|                                   Fan Durumu :" << " Kapalı"<<endl;


		}
		oku.close();
	}
}
	

	

