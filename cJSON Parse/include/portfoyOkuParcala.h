#ifndef PORTFOYOKUPARCALA_H
#define PORTFOYOKUPARCALA_H

#include "portfoy.h"
#include <stdio.h>
#include <stdlib.h>

char*PortfoyOku(char* yol); //dosyadan okuyor
void  Json_parcala_portfoy(Portfoy* portfoyDizi);       //jsonu parcaliyor
int elemanSayisi_Portfoy();

#endif