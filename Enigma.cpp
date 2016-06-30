#include "Enigma.h"

static const int ASCII_A = 65;
static const int ASCII_Z = 90;

Enigma::Enigma(char **filepaths, int numComp) {
	output = new std::string();
	refl = new Reflector();

	const char *pb = ".pb";
	checkConfigFiles(filepaths, numComp - 1, pb);

	Component *p = new Plugboard(filepaths[numComp - 1]);
	components.push_back(p);

	const char *rot = ".rot";
	for (int i = 1; i < numComp - 1; i++) {
		checkConfigFiles(filepaths, i, rot);
		Component *r = new Rotor(filepaths[i]);
		components.push_back(r);
	}
}

void Enigma::checkConfigFiles(char **filepaths, int argNum, const char *ext) {
	const char *fileName = filepaths[argNum];
	if (strstr(fileName, ext) == NULL) {
		errno = EINVAL;
		perror("Invalid config file type");
		exit(1);
	}
}

int Enigma::readInputAndProcess() {
	std::cin >> std::ws;
	while (!std::cin.eof()) {
		std::cin >> std::ws;
		char cur;
		std::cin >> cur;
		std::cin >> std::ws;

		int ascii = cur;

		if (ascii >= ASCII_A && ascii <= ASCII_Z) {
			encodeChar(cur);
		} else {
			errno = EINVAL;
			perror("Invalid character");
			exit(1);
		}
	}
	return 0;
}

void Enigma::encodeChar(char ch) {
	int c = ch;
	c -= ASCII_A;
	c = components[0]->getMapping(c);
	for (int i = 1; i < components.size(); i++) {
		c = components[i]->getMapping(c);
	}
	c = refl->getMapping(c);
	for (int i = components.size() - 1; i > 0; i--) {
		c = components[i]->getInvMapping(c);
	}
	if (components.size() > 1) {
		rotateRotors(1);
	}
	c = components[0]->getMapping(c);
	c += ASCII_A;
	char out = c;
	*output += out;
}

void Enigma::rotateRotors(int position) {
	bool completeRot = components[position]->rotate();
	if (completeRot && (position + 1 < components.size())) {
		rotateRotors(position + 1);
	}
}

std::string* Enigma::getOutput() {
	return output;
}

Enigma::~Enigma() {
	for (int i = 0; i < components.size(); i++) {
		delete (components[i]);
	}
	delete output;
	delete refl;
}
