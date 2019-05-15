#include "ofApp.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup() {
	ifstream inFile;
	string lastStr;
	
	map<string, vector<string>>::iterator it;

	inFile.open("data/text.txt");

	if (!inFile) {
		ofLogFatalError() << "Unable to open file";
	}
	string text;
	
	while (inFile >> text) {
		if (!lastStr.empty())
		{
			it = wordMap.find(lastStr);
			if (it != wordMap.end())
			{				
				it->second.push_back(text);
			}
			else {			
				vector <string> list;
				list.push_back(text);
				wordMap.insert(make_pair(lastStr, list));
			}			
		}
		lastStr = text;
	}
	ofLogNotice() << wordMap.size() << endl;
	inFile.close();

	ofstream resultsfile;
	resultsfile.open("resIncreaseWord2.txt");
	for (int i = 0; i < 100; i++)
	{
		//resultsfile << randomSatz() <<endl;
		resultsfile << increasingWordCount() << endl;
	}
	resultsfile.close();
}

string ofApp::randomSatz()
{
	map<string, vector<string>>::iterator it;
	vector<string> nextWords;
	string nextWord = "";
	string satz = "";
	bool toUsed = false;
	unsigned int randomVal = 0;
	int maxCycles = 0;
	it = wordMap.begin();
	int firstRand = ofRandom(30000);
	advance(it, firstRand);
	if (it != wordMap.end())
	{
		satz = (it->first);
		satz.append(" ");
		randomVal = ofRandom(it->second.size());
		while (string::npos == it->second[randomVal].find(".") && maxCycles < 100)
		{
			nextWord = it->second[randomVal];
			satz.append(nextWord + " ");
			it = wordMap.find(nextWord);
			randomVal = ofRandom(it->second.size());
			maxCycles++;			
		}
		satz.append(it->second[randomVal]);
		//ofLogNotice() << satz << endl;
		return satz;
	}
	else {
		ofLogNotice() << "word not found" << endl;
	}
}

string ofApp::increasingWordCount()
{
	map<string, vector<string>>::iterator it;
	vector<string> nextWords;
	string nextWord = "";
	string satz = "";
	bool nextWordPossible = true;
	unsigned int randomVal = 0;
	int maxCycles = 0;
	int currentWordSize = 2;

	it = wordMap.find("an");
	if (it != wordMap.end())
	{
		satz = (it->first);
		satz.append(" ");
		while (nextWordPossible && maxCycles < 10)
		{
			nextWord = biggerWordFinder(currentWordSize, it);
			if (nextWord.compare("-1") == 0)
			{
				nextWordPossible == false;
			}
			else {
				currentWordSize++;
				satz.append(nextWord + " ");
			}
			maxCycles++;
		}
		return satz;
	}
	else {
		ofLogNotice() << "word not found" << endl;
	}
}

string ofApp::biggerWordFinder(int pCurrentWordSize, map<string, vector<string>>::iterator& it)
{
	map<int, string> nextPossibleWords;
	map<int, string>::iterator nextWordsIt;
	for (int i = 0; i < it->second.size(); i++)
	{
		if (it->second[i].size() == pCurrentWordSize + 1)
		{
			nextPossibleWords.insert(make_pair(i, it->second[i]));
		}
	}
	if (nextPossibleWords.size() != 0)
	{
		int randomNext = ofRandom(nextPossibleWords.size());
		nextWordsIt = nextPossibleWords.begin();
		advance(nextWordsIt, randomNext);
		string word = nextWordsIt->second;
		it = wordMap.find(word);
		return word;
	}
	else {
		return string("-1");
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}



//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
