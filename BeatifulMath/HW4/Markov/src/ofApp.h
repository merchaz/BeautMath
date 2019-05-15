#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include "ofMain.h"

class ofApp : public ofBaseApp{
	private:
		map<string, vector<string>> wordMap;
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		string randomSatz();
		string increasingWordCount();
		string biggerWordFinder(int pCurrentWordSize, map<string, vector<string>>::iterator& it);
};
