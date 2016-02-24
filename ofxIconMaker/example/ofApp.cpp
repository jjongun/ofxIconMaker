#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup()
{
	stringstream ss;
	ss << " === Example === " << endl;
	ss << endl;
	ss << " press key '1' " << endl;
	ss << "		- icon_id : ic_3d_rotation" << endl;
	ss << "		- color : white " << endl;
	ss << "		- dpi : 24dp" << endl;
	ss << "		- type : xxxhd" << endl;
	ss << endl;
	ss << " press key '2' " << endl;
	ss << "		- icon_id : ic_book" << endl;
	ss << "		- color : black " << endl;
	ss << "		- dpi : 36dp" << endl;
	ss << "		- type : _2x" << endl;
	ss << endl;
	ss << " press key '3' " << endl;
	ss << "		- icon_id : ic_video_call" << endl;
	ss << "		- color : black " << endl;
	ss << "		- dpi : 48dp" << endl;
	ss << "		- type : _3x" << endl;

	description = ss.str();


	ss = stringstream();
	ss << "=== How to using this ===" << endl;
	ss << endl;
	ss << "1) open any webbrowser " << endl;
	ss << "2) go to https://design.google.com/icons/" << endl;
	ss << "3) click any icon" << endl;
	ss << "4) Look at webbrowser url text" << endl;
	ss << "5) Select text after '#' and Copy to clipboard." << endl;
	ss << "	ex) https://design.google.com/icons/#ic_copyright -> 'ic_copyright'" << endl;
	ss << "6) Using api : ofxIconMaker::GetIcon([icon_id] , select COLOR , select DPI , select type)" << endl;
	ss << endl;
	ss << "Almost auto compilation api options.  " << endl;
	ss << "And It will download cache to directory [data/google_icons], so fast load from local file if you same call again." << endl;
	ss << endl;
	ss << "video tutorial : https://youtu.be/2Myg8-8VGlE" << endl;

	how_to_str = ss.str();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(ofColor::brown);
	ofDrawBitmapString(description, 30, 30);
	ofDrawBitmapString(how_to_str, 30, ofGetHeight()*.5f + 30);

	if (code_ex_str != "")
	{
		ofSetColor(ofColor::blue);
		stringstream ss;
		ss << "code example : " << endl;
		ss << " " << code_ex_str << endl;
		ofDrawBitmapString(ss.str(), 30, ofGetHeight() - 50);
	}
	
	if (iconImage != nullptr)
	{
		float center_x = ofGetWidth() * .5f - iconImage->getWidth() * .5f;
		float center_y = ofGetHeight() * .5f - iconImage->getHeight() * .5f;
		ofSetColor(ofColor::white);
		iconImage->draw(center_x, center_y);
	}
}


void ofApp::changeIconImage(string icon_id, ofxIconMaker::COLOR color, ofxIconMaker::DPI dpi, ofxIconMaker::TYPE type)
{
	if (iconImage != nullptr)
	{
		delete iconImage;
		iconImage = nullptr;
	}

	iconImage = ofxIconMaker::GetIcon(icon_id, color, dpi, type);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (key == '1')
	{
		changeIconImage("ic_3d_rotation", ofxIconMaker::COLOR::WHITE, ofxIconMaker::DPI::_24dp, ofxIconMaker::TYPE::xxxhd);
		code_ex_str = "changeIconImage(\"ic_3d_rotation\", ofxIconMaker::COLOR::WHITE, ofxIconMaker::DPI::_24dp, ofxIconMaker::TYPE::xxxhd);";
	}

	if (key == '2')
	{
		changeIconImage("ic_book", ofxIconMaker::COLOR::BLACK, ofxIconMaker::DPI::_24dp, ofxIconMaker::TYPE::_2x);
		code_ex_str = "changeIconImage(\"ic_book\", ofxIconMaker::COLOR::BLACK, ofxIconMaker::DPI::_24dp, ofxIconMaker::TYPE::_2x);";
	}

	if (key == '3')
	{
		changeIconImage("ic_video_call", ofxIconMaker::COLOR::BLACK, ofxIconMaker::DPI::_48dp, ofxIconMaker::TYPE::_3x);
		code_ex_str = "changeIconImage(\"ic_video_call\", ofxIconMaker::COLOR::BLACK, ofxIconMaker::DPI::_48dp, ofxIconMaker::TYPE::_3x);";
	}

	if (key == '4')
	{
		changeIconImage("ic_chat_bubble", ofxIconMaker::COLOR::WHITE, ofxIconMaker::DPI::_48dp, ofxIconMaker::TYPE::_1x);
	}
}
