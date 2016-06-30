enigma: Main.o Component.o Enigma.o Rotor.o Plugboard.o Reflector.o
	g++ Main.o Component.o Enigma.o Rotor.o Plugboard.o Reflector.o -o enigma

Main.o: Main.cpp Enigma.h Component.h Rotor.h Plugboard.h Reflector.h
	g++ -c Main.cpp Enigma.h Component.h Rotor.h Plugboard.h Reflector.h

Enigma.o: Enigma.cpp Enigma.h Rotor.h Reflector.h Plugboard.h Component.h
	g++ -c Enigma.cpp Enigma.h Rotor.h Reflector.h Plugboard.h Component.h

Rotor.o: Rotor.cpp Rotor.h Component.h
	g++ -c Rotor.cpp Rotor.h Component.h
	
Reflector.o: Reflector.cpp Reflector.h
	g++ -c Reflector.cpp Reflector.h
	
Plugboard.o: Plugboard.cpp Plugboard.h Component.h
	g++ -c Plugboard.cpp Plugboard.h Component.h
	
Component.o: Component.cpp Component.h
	g++ -c Component.cpp Component.h

clean:
	rm -rf enigma *.o

.PHONY: clean
