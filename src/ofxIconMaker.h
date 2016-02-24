#pragma once
#include "ofImage.h"
#include "ofURLFileLoader.h"
#include <iostream>
#include <Poco\Zip\Decompress.h>

class ofxIconMaker
{
private :
	static void GetAllPngFilesUnderDir(ofDirectory dir);
public:

	enum COLOR {BLACK , WHITE};
	enum DPI {_18dp , _24dp , _36dp , _48dp};
	enum TYPE {_1x , _2x , _3x , hd , md , xhd , xxhd , xxxhd};

	ofxIconMaker();
	~ofxIconMaker();

	static void GetPlatformAndType(TYPE str , string &platform , string &size_type);
	static ofImage* GetIcon(string icon_id, COLOR color, DPI dpi, TYPE type);
};

