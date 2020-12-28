#include "../include/core.h"
#include <sstream>

Loggy::JsonWriter::JsonWriter(Loggy::Types::OPERATING_SYSTEM system) : _operatingSystem(system), _timeGenesis(time(nullptr)), _buffer("") {
    //TODO: make this temporary
    //_outStream = std::ofstream(R"(RANDOM_TEMP_FILE)", std::ios::ate | std::ios::out);
}

void Loggy::JsonWriter::Write(char data, unsigned long rawData) {
    std::stringstream buffer;
    buffer << data << std::endl;
    _buffer = _buffer + buffer.str();
    //_outStream << data;
}

void Loggy::JsonWriter::Print() {
    std::cout << _buffer << std::endl;
}

Loggy::JsonWriter::~JsonWriter() {
    _outStream.flush();
    _outStream.close();
}