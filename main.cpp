#include <iostream>
#include <vector>

#include "CsoundSession.hpp"
//#include "DataGenerator.hpp"

int main(int argc, char **argv){
	string csdName = "";
	if(argc > 1) csdName = argv[1];

	//CDataGenerator data;
	//std::vector<double> soundWave;
	//std::string fname = "24cell.txt";
	//soundWave = data.PWaveFromCosetTable(fname); 

	//bool waveFile = data.BWriteWaveValsToFile(soundWave);
	//if(waveFile){
	//	std::cout << "File written" << '\n';
	//	return 0;
	//} else {
 	//	std::cout << "File not written" << '\n';
	//	return 1;
	//}
		
	//std::cout << "Size of soundWave vector = " << soundWave.size() << '\n';
	//if(soundWave.size() > 0){
	
	//	for(int i = 0; i < soundWave.size(); i++){
	//		std::cout << soundWave[i] << " ";
	//		int endLine = i % 4;
	//		if(!endLine){
	//			std::cout << '\n';
	//		}
	//	}
	//} else {
	//	std::cout << "No data in soundWave" << '\n';
	//	return 1;
	//}

	//return 0;
	CsoundSession *session = new CsoundSession(csdName);
	session->mainLoop();
}
