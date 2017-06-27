MTO = ./build/test/main_test.o
DTO = ./build/test/deposit_test.o
DO = ./build/src/deposit.o
MO = ./build/src/main.o

all: hello test


hello: $(MO) $(DO)
	mkdir -p bin
	gcc $(MO) $(DO) -o bin/app -lm
	./bin/app


test: $(MTO) $(DTO) 
	gcc $(MTO) $(DTO) $(DO) -o ./bin/deposit-calc_test -lm
	./bin/deposit-calc_test
	
$(MO): src/main.c 
	mkdir -p build/src
	gcc -c src/main.c -o build/src/main.o

$(DO): src/deposit.c
	mkdir -p build/src
	gcc -c src/deposit.c -o build/src/deposit.o

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
