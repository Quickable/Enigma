#include "Component.h"

#ifndef SRC_ROTOR_H_
#define SRC_ROTOR_H_

class Rotor: public Component {
public:
	Rotor(const char *filepath);
	int getMapping(int index);
	int getInvMapping(int index);
	bool rotate();
private:
	int rotationState;
};

#endif /* SRC_ROTOR_H_ */
