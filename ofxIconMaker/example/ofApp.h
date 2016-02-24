#pragma once

#include "ofMain.h"
#include "ofxIconMaker.h"

class ofApp : public ofBaseApp{

	public:
		
		string description;
		string code_ex_str;
		string how_to_str;
		ofImage* iconImage;


		void setup();
		void update();
		void draw();

		void changeIconImage(string icon_id , ofxIconMaker::COLOR color , ofxIconMaker::DPI dpi , ofxIconMaker::TYPE type);
		void keyReleased(int key);
		
};
