#ifndef PORTFOY_H
#define PORTFOY_H

#include <stdio.h>
#include <stdlib.h>

struct PORTFOY{
	char* sembol;
	double maliyet;
	double adet;
	
	
	void (*yoket)(struct PORTFOY*);
};
typedef struct PORTFOY* Portfoy;

Portfoy PortfoyOlustur(char*,double,double);

void PortfoyYoket(Portfoy);





#endif