#include <iostream>
#include <string>

#include "record.h"
#include "marcfile.h"

using namespace std;

int main(int argc, char *argv[])
{
    string filename = argv[1];
    string filter = argv[2];
    string output = "marc";

    if (argv[3] == "-o") {
        output = argv[4];
    }

    MarcFile file(filename);
    if (!file.isValid()) {
        return 1;
    }

    Record r;
    while (r = file.next()) {
        r.getRawData();
    }

    return 0;
}