#ifndef CSOUNDSESSION_HPP
#define CSOUNDSESSION_HPP

#include <string>

#include <csound.hpp>
#include <csPerfThread.hpp>

using namespace std;

class CsoundSession : public Csound{

	string m_csd;
	CsoundPerformanceThread *m_pt;

public:

	CsoundSession(string const &csdFileName) : Csound() {
	m_pt = NULL;
	m_csd = "";
	if(!csdFileName.empty()){
		m_csd = csdFileName;
		startThread();
	}
};
	void startThread();
	void resetSession(string const &csdFileName);
	void stopPerformance();
	void mainLoop();

};

#endif
