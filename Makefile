MTO = ./build/test/main_test.o
DTO = ./build/test/deposit_test.o

all: test hello


hello: build/src/main.o
	mkdir -p bin
	gcc build/src/main.o -o bin/app
	./bin/app

test: $(MTO) $(DTO) 
	gcc $(MTO) $(DTO) -o ./bin/deposit-calc_test -lm
	./bin/deposit-calc_test


build/src/main.o: src/main.c
	mkdir -p build/src
	gcc -c src/main.c -o build/src/main.o

$(MTO): ./test/main.c
	mkdir -p build/test
	gcc -Wall -c test/main.c -o $(MTO)

$(DTO): ./test/deposit_test.c
	gcc -Wall -c test/deposit_test.c -o $(DTO)



clean:
	rm -f ./build/src/*.o
	rm -f ./build/test/*.o
	rm -f ./bin/deposit-calc_test
	rm -f ./bin/app
