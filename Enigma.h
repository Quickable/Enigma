#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <errno.h>
#include "Component.h"
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

#ifndef ENIGMA_H_
#define ENIGMA_H_

class Enigma {

public:
	Enigma(char **filepaths, int numRotor);
	virtual ~Enigma();
	std::string* getOutput();
	int readInputAndProcess();
private:
	std::string *output;
	std::vector<Component*> components;
	Reflector *refl;
	void rotateRotors(int position);
	void encodeChar(char c);
	void checkConfigFiles(char **filepaths, int argNum, const char *ext);
};

#endif /* ENIGMA_H_ */
