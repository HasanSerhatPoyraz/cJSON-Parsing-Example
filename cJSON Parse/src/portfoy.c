#include "portfoy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Portfoy PortfoyOlustur(char* sembol ,double maliyet ,double adet )
{
	Portfoy this;
	this=(Portfoy)malloc(sizeof(struct PORTFOY));
	
	this->sembol=sembol;
	this->maliyet=maliyet;
	this->adet=adet;
	
	
	this->yoket=&PortfoyYoket;
	
	return this;
}


void PortfoyYoket(Portfoy this)
{
	if(this==NULL) return;
	free(this);
}
