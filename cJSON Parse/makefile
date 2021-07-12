derelcalistir:derle calistir
derle:
	gcc -I "./include" -o ./lib/banka.o -c ./src/banka.c 
	gcc -I "./include" -o ./lib/emir.o -c ./src/emir.c 
	gcc -I "./include" -o ./lib/hisse.o -c ./src/hisse.c 
	gcc -I "./include" -o ./lib/portfoy.o -c ./src/portfoy.c 
	gcc -I "./include" -o ./lib/main.o -c ./src/main.c 
	gcc -I "./include" -o ./lib/cJSON.o -c ./src/cJSON.c 
	gcc -I "./include" -o ./lib/hisseOkuParcala.o -c ./src/hisseOkuParcala.c 
	gcc -I "./include" -o ./lib/portfoyOkuParcala.o -c ./src/portfoyOkuParcala.c 	
	gcc -I "./include" -o ./lib/emirOkuParcala.o -c ./src/emirOkuParcala.c 
	gcc -I "./include" -o ./bin/program ./lib/banka.o ./lib/emir.o ./lib/hisse.o ./lib/portfoy.o ./lib/main.o ./lib/cJSON.o ./lib/hisseOkuParcala.o ./lib/portfoyOkuParcala.o ./lib/emirOkuParcala.o   
calistir:
	./bin/program