#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <vector>
#include "field.h"

class Record {
private:
    std::string rawData;

    std::vector<Field> fields();

public:
    Record();

    std::string getRawData() { return rawData; }

    void setRawData(std::string rawData) { this->rawData = rawData; }
};

#endif
