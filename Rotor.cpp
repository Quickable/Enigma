#include "Rotor.h"

static const int ALPHABET_LEN = 26;

Rotor::Rotor(const char *filepath) :
		Component(filepath) {
	Rotor::rotationState = 0;
}

int Rotor::getMapping(int index) {
	int mapping = Component::mapping[(index + Rotor::rotationState)
			% ALPHABET_LEN];
	mapping = (mapping - Rotor::rotationState) % ALPHABET_LEN;
	if (mapping < 0) {
		mapping += ALPHABET_LEN;
	}
	return mapping;
}

int Rotor::getInvMapping(int index) {
	int mapping = -1;
	int target = (index + Rotor::rotationState) % ALPHABET_LEN;
	for (int i = 0; i < ALPHABET_LEN; i++) {
		if (Component::mapping[i] == target) {
			mapping = ((i - Rotor::rotationState)) % ALPHABET_LEN;
			if (mapping < 0) {
				mapping += ALPHABET_LEN;
			}
		}
	}
	return mapping;
}

bool Rotor::rotate() {
	Rotor::rotationState = (Rotor::rotationState + 1) % ALPHABET_LEN;
	if (Rotor::rotationState == 0) {
		return true;
	}
	return false;
}
