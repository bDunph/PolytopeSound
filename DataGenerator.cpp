#include "DataGenerator.hpp"

#include <iostream>
#include <fstream>

double CDataGenerator::DMap(double lowIn, double highIn, double lowOut, double highOut, double inputVal){
	double outputVal;
	return outputVal = lowOut + ((highOut - lowOut) / (highIn - lowIn)) * (inputVal - lowIn);
}

std::vector<double> CDataGenerator::PWaveFromCosetTable(std::string& fileName){

	std::string cosetNum;
	int a, A, b, B, c, C, d, D;
	int tempVals[4];
	double sampleValues[4];
	std::vector<double> cosetValsPerRow;
	//std::vector<double> colA;
	//std::vector<double> colB;
	//std::vector<double> colC;
	//std::vector<double> colD;
	std::ifstream file_(fileName);
	file_.ignore(48, '\n');
	if(file_.is_open()){
		while(file_){
			file_ >> cosetNum >> a >> A >> b >> B >> c >> C >> d >> D;
			//std::cout << cosetNum << " " << a << " " << b << " " << c << " " << d << '\n';	
			tempVals[0] = a;
			tempVals[1] = b;
			tempVals[2] = c;
			tempVals[3] = d;
			//fill vector sequentially - row by row
			for(int i = 0; i < 4; i++){
				sampleValues[i] = DMap(0.0, 1152.0, -1.0, 1.0, (double) tempVals[i]);	
				cosetValsPerRow.push_back(sampleValues[i]);
			}
			
			//fill vector sequentially - column by column
			//double aVal = DMap(0.0, 120.0, -1.0, 1.0, (double) tempVals[0]);
			//colA.push_back(aVal);	
			//double bVal = DMap(0.0, 120.0, -1.0, 1.0, (double) tempVals[1]);
			//colB.push_back(bVal);	
			//double cVal = DMap(0.0, 120.0, -1.0, 1.0, (double) tempVals[2]);
			//colC.push_back(cVal);	
			//double dVal = DMap(0.0, 120.0, -1.0, 1.0, (double) tempVals[3]);
			//colD.push_back(dVal);	
		}
		file_.close();
	} else {
		std::cout << "File is not open" << '\n';
		cosetValsPerRow.push_back(0.0);
		return cosetValsPerRow;
		//colA.push_back(0.0);
		//return colA;
	}
	
	//colA.insert(colA.end(), colB.begin(), colB.end());
	//colA.insert(colA.end(), colC.begin(), colC.end());
	//colA.insert(colA.end(), colD.begin(), colD.end());
 	
	//return colA;
	return cosetValsPerRow;
}

bool CDataGenerator::BWriteWaveValsToFile(std::vector<double> inputVector){

	std::ofstream outFile;
	outFile.open("24cellWaveTableNoZeroPadAdjMap.txt");
	if(outFile.is_open()){
		for(int i = 0; i < inputVector.size(); i++){
			outFile << inputVector[i] << '\n';
		}
		// temporary hack to make 5cell.txt filesize power of two (1024)
		//for(int i = 0; i < 56; i++){
		//	outFile << 0 << '\n';
		//}
		// temporary hack to make 8cell.txt filesize power of two (4096)
		//for(int i = 0; i < 1016; i++){
		//	outFile << 0 << '\n';
		//}	
		// temporary hack to make 24cell.txt filesize power of two (16384)
		//for(int i = 0; i < 7160; i++){
		//	outFile << 0 << '\n';
		//}
		
		// fill file with values in reverse order to complete one cycle of wave
		for(int i = inputVector.size(); i > 0 ; i--){
			outFile << inputVector[i] << '\n';
		}
		outFile.close();
		return true;
	} else {
		std::cout << "Error: output file not written" << '\n';
		return false;
	}
}
