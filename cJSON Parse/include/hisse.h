#ifndef HISSE_H
#define HISSE_H

#include <stdio.h>
#include <stdlib.h>

struct HISSE{
	char* sembol;
	char* ad;
	double fiyat;
	
	
	
	void (*yoket)(struct HISSE*);
};
typedef struct HISSE* Hisse;

Hisse HisseOlustur(char*,char*,double);



void HisseYoket(Hisse);





#endif