#include <iostream>
#include "Descriptors.h"
#include "Floor.h"
#include "Table.h"

using namespace Laba4;

int main() {
    Table table;
    table.generate_random();
    std::cout << table;
    return 0;
}
