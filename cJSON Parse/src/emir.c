#include "emir.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Emir EmirOlustur(char* sembol ,char* islem ,double adet )
{
	Emir this;
	this=(Emir)malloc(sizeof(struct EMIR));
	
	this->sembol=sembol;
	this->islem=islem;
	this->adet=adet;
	
	
	this->yoket=&EmirYoket;
	
	return this;
}


void EmirYoket(Emir this)
{
	if(this==NULL) return;
	free(this);
}
