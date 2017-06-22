MTO = ./build/test/main_test.o
DTO = ./build/test/deposit_test.o
VTO = ./build/test/validation_test.o

all: hello test


hello: build/src/main.o
	g++ build/src/main.o -o bin/sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./bin/sfml-app

test: $(MTO) $(DTO) $(VTO)
	g++ $(MTO) $(DTO) $(VTO) -o ./bin/deposit-calc_test
	./bin/deposit-calc_test


build/src/main.o: src/main.cpp
	g++ -c src/main.cpp -g -O0 -ltcmalloc -o build/src/main.o

$(MTO): ./test/main.cpp
	g++ -c ./test/main.cpp -o $(MTO)

$(DTO): ./test/deposit_test.cpp
	g++ -c ./test/deposit_test.cpp -o $(DTO)

$(VTO): ./test/validation_test.cpp
	g++ -c ./test/validation_test.cpp -o $(VTO)


clean:
	rm ./build/src/*.o
	rm ./build/test/*.o