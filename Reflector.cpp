#include "Reflector.h"

static const int ALPHABET_LEN = 26;

Reflector::Reflector() {
}

int Reflector::getMapping(int index) {
	return (index + 13) % ALPHABET_LEN;
}
