#include "Component.h"

#ifndef SRC_PLUGBOARD_H_
#define SRC_PLUGBOARD_H_

class Plugboard: public Component {
public:
	Plugboard(const char *filepath);
	int getMapping(int index);
	int getInvMapping(int index);
	bool rotate();
};

#endif /* SRC_PLUGBOARD_H_ */
