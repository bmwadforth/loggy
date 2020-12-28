#include "../include/core.h"
#include <utility>

Loggy::JsonWriter::JsonWriter(Loggy::Types::OPERATING_SYSTEM system) : _operatingSystem(system), _timeGenesis(time(nullptr)), _buffer(new char[2096]) {}

void Loggy::JsonWriter::Write(char data, unsigned long rawData) {

}

Loggy::JsonWriter::~JsonWriter() {
    delete[] _buffer;
}



Loggy::Core::Core() {

}