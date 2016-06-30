#include <vector>
#include <stdio.h>
#include <fstream>
#include <errno.h>
#include <stdlib.h>

#ifndef SRC_COMPONENT_H_
#define SRC_COMPONENT_H_

class Component {
public:
	Component(const char *filepath);
	virtual int getMapping(int index)=0;
	virtual int getInvMapping(int index)=0;
	virtual bool rotate()=0;
protected:
	std::vector<int> mapping;
	void loadConfig(const char *filepath);
};

#endif /* SRC_COMPONENT_H_ */
