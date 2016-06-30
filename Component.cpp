#include "Component.h"

Component::Component(const char *filepath) {
	loadConfig(filepath);
}

void Component::loadConfig(const char *filepath) {
	std::ifstream file(filepath);
	if (file.fail()) {
		perror("Unable to open file!");
		errno = ENOENT;
		exit(1);
	}
	int i;
	file >> std::ws;
	while (file >> i) {
		Component::mapping.push_back(i);
		file >> std::ws;
	}
	file.close();
}
