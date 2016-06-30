#include <iostream>
#include "Enigma.h"

using namespace std;

int main(int argc, char **argv) {
	Enigma *e = new Enigma(argv, argc);

	if (argc == 1) {
		perror("No config files given!");
		errno = EINVAL;
		exit(1);
	}

	int success = e->readInputAndProcess();
	if (success == 1) {
		errno = EINVAL;
		perror("Error reading input!");
		exit(1);
	}

	cout << *e->getOutput() << endl;
	delete (e);
	return 0;
}
