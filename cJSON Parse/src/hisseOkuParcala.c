#include "hisse.h"
#include "hisseOkuParcala.h"
#include "cJSON.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dosyadan okuma islemi 
char* HisseOku(char* yol){
	char* icerik=NULL;
	int boyut=0;
	FILE *fp;
	fp = fopen(yol,"r");
	if(!fp) return NULL;
	fseek(fp,0,SEEK_END);
	boyut = ftell(fp);
	rewind(fp);
	icerik = (char*)malloc(sizeof(char)*(boyut+1));
	size_t toplamUzunluk = fread(icerik, 1, boyut, fp);
	icerik[toplamUzunluk]='\0';
	fclose(fp);
	return icerik;	
}
//hisseleri iceren json dosyasindaki eleman sayisini buluyor
int elemanSayisi_Hisse()
{
	int sayac=0;
	cJSON* Hisse=NULL;
	cJSON* Hisseler=NULL;
	
	char* json = HisseOku("./doc/hisseler.json");
	cJSON *hisse_json =cJSON_Parse(json);
	Hisse=cJSON_GetObjectItemCaseSensitive(hisse_json,"Hisseler");

	cJSON_ArrayForEach(Hisseler,Hisse)
	{
		sayac++;
	}
	free(json);
	return sayac;
}
//json dosyasini elemanlarına gore parcalama islemi yapiliyor
void Json_parcala_Hisse(Hisse* hisseDizi)
{
	

	cJSON* Hisse=NULL;
	cJSON* Hisseler=NULL;
	cJSON* Sembol=NULL;
	cJSON* Ad=NULL;
	cJSON* Fiyat=NULL;
	int sayac=0;
	


char* json = HisseOku("./doc/hisseler.json");

cJSON *hisse_json =cJSON_Parse(json);


Hisse=cJSON_GetObjectItemCaseSensitive(hisse_json,"Hisseler");

	cJSON_ArrayForEach(Hisseler,Hisse)
	{
		cJSON* sembol=cJSON_GetObjectItemCaseSensitive(Hisseler,"Sembol");
		
		cJSON* ad=cJSON_GetObjectItemCaseSensitive(Hisseler,"Ad");
	
		cJSON* fiyat=cJSON_GetObjectItemCaseSensitive(Hisseler,"Fiyat");
		
	
		hisseDizi[sayac]=HisseOlustur(sembol->valuestring,ad->valuestring,fiyat->valuedouble);//hisse tipinde degiskenler dizide tutuluyor
	
		sayac++;
	}
	
	free(json);
	
}
