#include "hisse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Hisse HisseOlustur(char* sembol ,char* ad ,double fiyat )
{
	Hisse this;
	this=(Hisse)malloc(sizeof(struct HISSE));
	
	this->sembol=sembol;
	this->ad=ad;
	this->fiyat=fiyat;
	
	
	this->yoket=&HisseYoket;
	
	return this;
}
	


void HisseYoket(Hisse this)
{
	if(this==NULL) return;
	free(this);
}
