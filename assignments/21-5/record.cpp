#include "record.h"

Record::Record() {}
Record::Record(unsigned int id) { this->id = id; }
bool Record::operator==(const Record& that) { return this->id == that.id; }
void Record::operator=(const Record& that) { this->id = that.id; }
std::string Record::to_str() const { return std::to_string(this->id); }