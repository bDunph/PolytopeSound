#ifndef DATA_GENERATOR_HPP
#define DATA_GENERATOR_HPP

#include <string>
#include <vector>

class CDataGenerator {

public:
	double DMap(double lowIn, double highIn, double lowOut, double highOut, double inputVal);
	std::vector<double> PWaveFromCosetTable(std::string& fileName);
	bool BWriteWaveValsToFile(std::vector<double> inputVector);
};
#endif
