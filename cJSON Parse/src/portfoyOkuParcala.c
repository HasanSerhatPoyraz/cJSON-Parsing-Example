#include "portfoy.h"
#include "portfoyOkuParcala.h"
#include "cJSON.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dosyadan okuma islemi 
char* PortfoyOku(char* yol){
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
//portfoylari iceren json dosyasindaki eleman sayisini buluyor
int elemanSayisi_Portfoy()
{
	int sayac=0;
	cJSON* Portfoy=NULL;
	cJSON* Portfoylar=NULL;
	
	char* json = PortfoyOku("./doc/Portfoy.json");
	cJSON *portfoy_json =cJSON_Parse(json);
	Portfoy=cJSON_GetObjectItemCaseSensitive(portfoy_json,"Portfoy");

	cJSON_ArrayForEach(Portfoylar,Portfoy)
	{
		sayac++;
	}
	free(json);
	return sayac;
}
//json dosyasini elemanlarına gore parcalama islemi yapiliyor
void Json_parcala_portfoy(Portfoy* portfoyDizi)
{
	

	cJSON* Portfoy=NULL;
	cJSON* Portfoylar=NULL;
	cJSON* Sembol=NULL;
	cJSON* Maliyet=NULL;
	cJSON* Adet=NULL;
	int sayac=0;



char* json = PortfoyOku("./doc/Portfoy.json");

cJSON *portfoy_json =cJSON_Parse(json);


Portfoy=cJSON_GetObjectItemCaseSensitive(portfoy_json,"Portfoy");

	cJSON_ArrayForEach(Portfoylar,Portfoy)
	{
		cJSON* sembol=cJSON_GetObjectItemCaseSensitive(Portfoylar,"Sembol");
		
		cJSON* maliyet=cJSON_GetObjectItemCaseSensitive(Portfoylar,"Maliyet");
	
		cJSON* adet=cJSON_GetObjectItemCaseSensitive(Portfoylar,"Adet");
		
	
		portfoyDizi[sayac]=PortfoyOlustur(sembol->valuestring,maliyet->valuedouble,adet->valuedouble);//portfoy tipinde degiskenler dizide tutuluyor
	
		sayac++;	
	}
	
	free(json);
	
	
}