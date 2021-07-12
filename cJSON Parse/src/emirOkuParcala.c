#include "emir.h"
#include "emirOkuParcala.h"
#include "cJSON.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dosyadan okuma islemi 
char* EmirOku(char* yol){
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
//emirleri iceren json dosyasindaki eleman sayisini buluyor
int elemanSayisi_Emir()
{
	int sayac=0;
	cJSON* Emir=NULL;
	cJSON* Emirler=NULL;
	
	char* json = EmirOku("./doc/emirler.json");
	cJSON *emir_json =cJSON_Parse(json);
	Emir=cJSON_GetObjectItemCaseSensitive(emir_json,"Emirler");
	
	cJSON_ArrayForEach(Emirler,Emir)
	{
		sayac++;
	}
	free(json);
	return sayac;
}
//json dosyasini elemanlarına gore parcalama islemi yapiliyor
void Json_parcala_emir(Emir* emirDizi)
{
	cJSON* Emir=NULL;
	cJSON* Emirler=NULL;
	cJSON* Sembol=NULL;
	cJSON* Islem=NULL;
	cJSON* Adet=NULL;
	int sayac=0;

char* json = EmirOku("./doc/emirler.json");

cJSON *emir_json =cJSON_Parse(json);


Emir=cJSON_GetObjectItemCaseSensitive(emir_json,"Emirler");

	cJSON_ArrayForEach(Emirler,Emir)
	{
		cJSON* sembol=cJSON_GetObjectItemCaseSensitive(Emirler,"Sembol");
	
		cJSON* islem=cJSON_GetObjectItemCaseSensitive(Emirler,"Islem");
		
		cJSON* adet=cJSON_GetObjectItemCaseSensitive(Emirler,"Adet");
		
	
		emirDizi[sayac]=EmirOlustur(sembol->valuestring,islem->valuestring,adet->valuedouble);//emir tipinde degiskenler dizide tutuluyor
		sayac++;
	}
	
	free(json);
	

}