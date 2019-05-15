#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	drawPerlText();
}

void ofApp::drawPerlGraph()
{
	ofBackground(10, 255, 255);
	ofSetColor(0, 0, 0);
	for (int x = 0; x < 1000; x++) {
		float t = x * 0.01;
		float y = ofNoise(t-200);
		ofLine(x, 1000, x, 1000 - y * 1000);
	}
	ofNoFill();
	ofRect(0, 0, 1000, 1000);
}

void ofApp::drawPerlPts()
{
	ofBackground(0, 255, 255);

	ofSetColor(0, 0, 0);
	float time = ofGetElapsedTimef();
	for (int i = 0; i < 1000; i++) {
		float ampX = ofGetWidth();
		float ampY = ofGetHeight();
		float speed = 0.1;
		float posX0 = i * 104.3 + 14.6;
		float posY0 = i * 53.3 + 35.2;

		//Get x and y using Perlin noise
		float x = ampX * ofNoise(time * speed + posX0);
		float y = ampY * ofNoise(time * speed + posY0);
		ofCircle(x, y, 10);
	}
}

void ofApp::drawPerlText()
{
	ofBackground(255, 255, 255);
	float time = ofGetElapsedTimef();

	float scaleX = 0.007;
	float scaleY = 0.008;
	float posX0 = 480.2;
	float posY0 = 30;
	for (int y = 0; y < 500; y++) {
		for (int x = 0; x < 500; x++) {
			float value = ofNoise( x*scaleX+posX0, y*scaleY+posY0, time*0.1 + 445.6 );	
			ofSetColor(value * 255, value * 255, value * 255);
			ofRect(x, y, 1, 1);
		}
	}
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
