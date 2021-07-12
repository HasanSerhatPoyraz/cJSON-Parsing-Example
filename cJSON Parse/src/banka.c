#include "banka.h"

#include "hisseOkuParcala.h"
#include "portfoyOkuParcala.h"
#include "emirOkuParcala.h"
#include "hisse.h"
#include "portfoy.h"
#include "emir.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Banka BankaOlustur()
{
	Banka this;
	this=(Banka)malloc(sizeof(struct BANKA));
	
	this->yoket=&BankaYoket;
	this->islemler=&Islemler;
	return this;
}
void BankaYoket(Banka this)
{
	if(this==NULL) return;
	free(this);
}
void Islemler(Banka banka)
{
	
	int hisseEleman=elemanSayisi_Hisse();
	int portfoyEleman=elemanSayisi_Portfoy();
	int emirEleman=elemanSayisi_Emir();


	Hisse* hisseDizi=(Hisse*)malloc(hisseEleman*sizeof(Hisse));
	Portfoy* portfoyDizi=(Portfoy*)malloc(portfoyEleman*sizeof(Portfoy));
	Emir* emirDizi=(Emir*)malloc(emirEleman*sizeof(Emir));

	int gonderilecekHisse=-1;
	int gonderilecekPortfoy=-1;

	double guncelFiyatSatis=0;
	double maliyetSatis=0;
	double karZararSatis=0;
	double toplamKarZararSatis=0;

	double yeniMaliyetAlis=0;
	double guncelFiyatAlis=0;
	double eskiMaliyetAlis=0;

	Json_parcala_Hisse(hisseDizi);
	Json_parcala_portfoy(portfoyDizi);
	Json_parcala_emir(emirDizi);

	printf("\n%s\n","Satislar Kar/Zarar:");
	
	int k;
	for(k=0;k<emirEleman;k++)//her emir icin tek tek islem yapacak dongu
	{
		int i;
		for(i=0;i<hisseEleman;i++)	//hisseleri tutan diziden ilgili emiri iceren degeri donduruyor.
		{
			if(strcmp(emirDizi[k]->sembol,hisseDizi[i]->sembol)==0)
			{
				gonderilecekHisse=i;
			}
		}
	
	
		int j;
		for(j=0;j<portfoyEleman;j++)//portfoylari tutan diziden ilgili emiri iceren degeri donduruyor.
		{
			if(strcmp(emirDizi[k]->sembol,portfoyDizi[j]->sembol)==0)
			{
				gonderilecekPortfoy=j;
			}	
		}
	
		if(gonderilecekHisse==-1)
		{
			//printf("%s\n","islem yapmak istediginiz hisse mevcut degil.");	
		}	
	
		else if(strcmp(emirDizi[k]->islem,"SATIS")==0 )	//satis islemlerini yapıyor
		{
			
			
			if(gonderilecekPortfoy==-1)
			{
			//	printf("%s\n","islem yapmak istediginiz portfoy mevcut degil.");	
			}
			else if(emirDizi[k]->adet>portfoyDizi[gonderilecekPortfoy]->adet)
			{
				//printf("%s\n","mevcut miktardan fazla adet satmaya calisiyosunuz.");	
			}
			else
			{
				
				guncelFiyatSatis=hisseDizi[gonderilecekHisse]->fiyat*emirDizi[k]->adet;
		
				maliyetSatis=portfoyDizi[gonderilecekPortfoy]->maliyet*emirDizi[k]->adet;
		
				karZararSatis=guncelFiyatSatis-maliyetSatis;
				toplamKarZararSatis+=karZararSatis;
			
				if(karZararSatis>0)
				{
					printf("%s%s%.1f%s\n",emirDizi[k]->sembol,":",karZararSatis," Kar");
				}	
				else if(karZararSatis<0)
				{
					printf("%s%s%.1f%s\n",emirDizi[k]->sembol,":",-1*karZararSatis," Zarar");
				}	
				else
				{
					printf("%s%s%.1f%s\n",emirDizi[k]->sembol,":",karZararSatis," Kar");
				}
				
				portfoyDizi[gonderilecekPortfoy]->adet-=emirDizi[k]->adet;
			}			
		
		}
		else if(strcmp(emirDizi[k]->islem,"ALIS")==0)		//alis islemlerini yapıyor
		{
			
			guncelFiyatAlis=hisseDizi[gonderilecekHisse]->fiyat*emirDizi[k]->adet;
		
			if(gonderilecekPortfoy!=-1)//sembol, portfoyda mevutsa bu if bloguna giriyor ve islemleri yapiyor
			{
				eskiMaliyetAlis=portfoyDizi[gonderilecekPortfoy]->maliyet*portfoyDizi[gonderilecekPortfoy]->adet;
				yeniMaliyetAlis=(eskiMaliyetAlis+guncelFiyatAlis)/(portfoyDizi[gonderilecekPortfoy]->adet+emirDizi[k]->adet);
			
				portfoyDizi[gonderilecekPortfoy]->adet+=emirDizi[k]->adet;	
				portfoyDizi[gonderilecekPortfoy]->maliyet=yeniMaliyetAlis;	
			}
			else //eger alis yapilacak sembol portfoyda mevcut degilse portfoylari tutan dizinin eleman sayisi arttiriliyor ve yeni deger diziye ekleniyor
			{
				yeniMaliyetAlis=hisseDizi[gonderilecekHisse]->fiyat;
			
				portfoyDizi=(Portfoy*)realloc(portfoyDizi,(portfoyEleman+1)*sizeof(Portfoy));
				portfoyDizi[portfoyEleman]=PortfoyOlustur(emirDizi[k]->sembol,yeniMaliyetAlis,emirDizi[k]->adet);
		
				portfoyEleman++;
			}	
		
		}
		else
		{
			printf("%s","hatali islem");
		}
	
		gonderilecekHisse=-1;
		gonderilecekPortfoy=-1;
	
}
	//kar ve zararlar ekrana basiliyor
		if(toplamKarZararSatis>0)
		{
			printf("%s%.1f%s\n","Toplam Kar/Zarar: +",toplamKarZararSatis," TL");
		}
		if(toplamKarZararSatis<0)
		{
			printf("%s%.1f%s\n","Toplam Kar/Zarar: ",toplamKarZararSatis," TL");
		}
		
		//guncel portfoy ekrana basiliyor
		printf("\n\n%s\n","Guncel Portfoy:");
		int i;
		for(i=0;i<portfoyEleman;i++)
		{
			if(portfoyDizi[i]->adet!=0)
			{
				printf("\n%s%s\n","Hisse:",portfoyDizi[i]->sembol);
				printf("%s%.0f\n","Adet:",portfoyDizi[i]->adet);
				printf("%s%.2f\n","Maliyet:",portfoyDizi[i]->maliyet);
				if(i!=portfoyEleman-1)
					printf("%s\n","--------------------------");
				
			}
		}
		//isi biten degeler ilgili metotlari yardimiyla serbest birakiliyor
		int h;
		for(h=0;h<hisseEleman;h++)
		{
			HisseYoket(hisseDizi[h]);
		}
		
		int p;
		for(p=0;p<portfoyEleman;p++)
		{
			PortfoyYoket(portfoyDizi[p]);
		}
		
		int e;
		for(e=0;e<emirEleman;e++)
		{
			EmirYoket(emirDizi[e]);
		}
		
		free(hisseDizi);
		free(portfoyDizi);
		free(emirDizi);
}


