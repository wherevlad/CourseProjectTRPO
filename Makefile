MTO = ./build/test/main_test.o
DTO = ./build/test/deposit_test.o
VTO = ./build/test/validation_test.o

all: hello test


hello: build/src/main.o
	mkdir -p bin
	g++ build/src/main.o -o bin/sfml-app
	./bin/sfml-app

test: $(MTO) $(DTO) $(VTO)
	gcc $(MTO) $(DTO) $(VTO) -o ./bin/deposit-calc_test -lm
	./bin/deposit-calc_test


build/src/main.o: src/main.cpp
	mkdir -p build/src
	g++ -c src/main.cpp -o build/src/main.o

$(MTO): ./test/main.c
	mkdir -p build/test
	gcc -Wall -c test/main.c -o $(MTO)

$(DTO): ./test/deposit_test.c
	gcc -Wall -c test/deposit_test.c -o $(DTO)

$(VTO): ./test/validation_test.c
	gcc -Wall -c test/validation_test.c -o $(VTO)


clean:
	rm ./build/src/*.o
	rm ./build/test/*.o
	rm ./bin/deposit-calc_test
	rm ./bin/sfml-app
