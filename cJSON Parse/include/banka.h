#ifndef BANKA_H
#define BANKA_H

#include <stdio.h>
#include <stdlib.h>

#include "hisse.h"
#include "portfoy.h"
#include "emir.h"

struct BANKA{
	
	void (*islemler)(struct BANKA*);
	void (*yoket)(struct BANKA*);
};
typedef struct BANKA* Banka;

Banka BankaOlustur();

void  Islemler(Banka banka);
void BankaYoket(Banka);



#endif