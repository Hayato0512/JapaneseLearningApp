all: translate

translate: WordPair.o  Translator.o 
	g++ -Wall -o translate Translator.o WordPair.o 
Translator.o: Translator.cpp
	g++ -Wall -c Translator.cpp
		
WordPair.o: WordPair.h WordPair.cpp
	g++ -Wall -c WordPair.cpp



clean:
	rm -f translate *.o


