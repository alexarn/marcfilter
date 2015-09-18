#ifndef FIELD_H
#define FIELD_H

#include <string>

class Field {
public:
		std::string zone;

		Field();

		std::string Value();

		bool isControlField();
};

#endif
