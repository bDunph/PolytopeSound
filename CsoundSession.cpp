#include "CsoundSession.hpp"

#include <iostream>

void CsoundSession::startThread(){
	if(Compile((char *)m_csd.c_str()) == 0){
		m_pt = new CsoundPerformanceThread(this);
		m_pt->Play();
	}
};

void CsoundSession::resetSession(string const &csdFileName){
	if(!csdFileName.empty()) m_csd = csdFileName;

	if(!m_csd.empty()){
		stopPerformance();
		startThread();
	}
};

void CsoundSession::stopPerformance(){
	if(m_pt){
		if(m_pt->GetStatus() == 0) m_pt->Stop();
		m_pt->Join();
		m_pt = NULL;
	}
	Reset();
};

void CsoundSession::mainLoop(){
	string s;
	bool loop = true;
	while(loop){
		cout << endl << "l)oad csd; e)vent; r)ewind; t)oggle pause; s)top; p)lay; q)uit: ";
		char c = cin.get();
		switch(c) {
			case 'l':
				cout << "Enter the name of csd file:";
				cin >> s;
				resetSession(s);
				break;

			case 'e':
				cout << "Enter a score event:";
				cin.ignore(1000, '\n');
				getline(cin, s);
				m_pt->InputMessage(s.c_str());
				break;

			case 'r':
				RewindScore();
				break;

			case 't':
				if(m_pt) m_pt->TogglePause();
				break;

			case 's':
				stopPerformance();
				break;

			case 'p':
				resetSession("");
				break;

			case 'q':
				if(m_pt){
					m_pt->Stop();
					m_pt->Join();
				}
				loop = false;
				break;

		}
		cout << endl;
	}
};

