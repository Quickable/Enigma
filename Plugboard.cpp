#include "Plugboard.h"

Plugboard::Plugboard(const char *filepath) :
		Component(filepath) {
}

int Plugboard::getMapping(int index) {
	int mapping = index;
	for (int i = 0; i < Plugboard::mapping.size(); i++) {
		if (Plugboard::mapping[i] == index) {
			if (i % 2 == 1) {
				mapping = Plugboard::mapping[i - 1];
			} else {
				mapping = Plugboard::mapping[i + 1];
			}
		}
	}
	return mapping;
}

int Plugboard::getInvMapping(int index) {
	return -1;
}

bool Plugboard::rotate() {
	return false;
}
