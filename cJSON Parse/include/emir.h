#ifndef EMIR_H
#define EMIR_H

#include <stdio.h>
#include <stdlib.h>

struct EMIR{
	char* sembol;
	char* islem;
	double adet;
	
	
	void (*yoket)(struct EMIR*);
};

typedef struct EMIR* Emir;

Emir EmirOlustur(char*,char*,double);

void EmirYoket(Emir);





#endif