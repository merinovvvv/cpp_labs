#ifndef IODATA_H_
#define IODATA_H_
void outToConsole(const std::vector <int>& vec, const std::string& delimeter);
void writeData(const std::vector <int>& list, const std::string& filePath);
void readData(std::vector <int>& list, const std::string& filePath);

#endif // IODATA_H_