#ifndef MARCFILE_H
#define MARCFILE_H

#include <string>
#include <fstream>
#include "record.h"

class MarcFile {
private:
		std::string content;
		std::string filePath;

		void _getContent();

public:
		MarcFile(std::string filePath);

		Record next();

		bool isValid();
};

#endif
