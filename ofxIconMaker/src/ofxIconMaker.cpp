#include "ofxIconMaker.h"

string root_url = "https://storage.googleapis.com/material-icons/external-assets/v4/icons/zip/";
string icon_dir_str = "google_icons";
vector<ofFile> allfiles;

struct memToStreamBuf : std::streambuf
{
	memToStreamBuf(char* start, char* end)
	{
		this->setg(start, start, end);
	}
};


ofxIconMaker::ofxIconMaker()
{
}


ofxIconMaker::~ofxIconMaker()
{
}


void ofxIconMaker::GetAllPngFilesUnderDir(ofDirectory dir)
{
	for (ofFile file : dir)
	{
		if (file.isFile() == true )
		{
			if (file.getExtension() == "png")
			{
				allfiles.push_back(file);
			}
		}
		else {
			GetAllPngFilesUnderDir(ofDirectory(file));
		}
	}
}

void ofxIconMaker::GetPlatformAndType(TYPE type, string &platform, string &size_type)
{
	switch (type)
	{
	case TYPE::_1x:
		size_type = "";
		platform = "ios";
		; break;
	case TYPE::_2x:
		size_type = "_2x";
		platform = "ios";
		; break;
	case TYPE::_3x:
		size_type = "_3x";
		platform = "ios";
		; break;
	case TYPE::hd:
		size_type = "hdpi";
		platform = "android";
		; break;
	case TYPE::md:
		size_type = "mdpi";
		platform = "android";
		; break;
	case TYPE::xhd:
		size_type = "xhdpi";
		platform = "android";
		; break;
	case TYPE::xxhd:
		size_type = "xxhdpi";
		platform = "android";
		; break;
	case TYPE::xxxhd:
		size_type = "xxxhdpi";
		platform = "android";
		; break;
	}
}

ofImage* ofxIconMaker::GetIcon(string icon_id , COLOR color , DPI dpi , TYPE type)
{
	allfiles.clear();
	string color_str;
	string dpi_str;

	if (color == COLOR::BLACK)
		color_str = "black";
	else
		color_str = "white";

	switch (dpi)
	{
	case DPI::_18dp: dpi_str = "18dp";
		; break;
	case DPI::_24dp: dpi_str = "24dp";
		; break;
	case DPI::_36dp: dpi_str = "36dp";
		; break;
	case DPI::_48dp: dpi_str = "48dp";
		; break;
	defalut : dpi_str = "48dp";
		; break;
	}

	stringstream ss;
	ss << icon_id << "_" << color_str << "_" << dpi_str;
	string icon_def = ss.str();

	//
	//check existFile file
	//

	bool isExistsFile = false;
	string platform_str = "";
	string size_type_str = "";
	GetPlatformAndType(type , platform_str , size_type_str);
	string icon_type_dir = ofFilePath::join(ofFilePath::join(ofFilePath::join(ofFilePath::join(ofFilePath::getCurrentExeDir(), "data"), icon_dir_str), icon_def), platform_str);
	string icon_file = "";
	
	
	if (platform_str == "ios")
	{
		ss = stringstream();
		ss << icon_id << "_" << color_str << ".imageset";
		string icon_ios_icon_dir = ofFilePath::join(icon_type_dir, ss.str());

		ss = stringstream();
		ss << icon_id << "_" << color_str << size_type_str << ".png";
		icon_file = ofFilePath::join(icon_ios_icon_dir, ss.str());

		if (ofFile(icon_file).exists() == false)
		{
			ofDirectory dir(icon_type_dir);
			if (dir.exists() == true)
			{
				GetAllPngFilesUnderDir(dir);
				for (ofFile file : allfiles)
				{
					if (type == TYPE::_1x)
					{
						icon_file = allfiles[0].path();
						break;
					}
					else if (file.getFileName().rfind(size_type_str) != string::npos )
					{
						icon_file = file.path();
						break;
					}
				}
			}
		}
	}
	else if (platform_str == "android")
	{
		ss = stringstream();
		ss << "drawable-" << size_type_str ;
		string icon_android_dir = ss.str();

		ss = stringstream();
		ss << icon_id << "_" << color_str << "_" << dpi_str << ".png";
		icon_file = ofFilePath::join(ofFilePath::join(icon_type_dir, icon_android_dir), ss.str());
	}


	isExistsFile = ofFile(icon_file).exists();
	cout << icon_file << endl;
	cout << isExistsFile << endl;

	//cout << ofFilePath::join( ofFilePath::getCurrentExeDir() , "data") << endl;

	if (isExistsFile == false)
	{
		ss = stringstream();
		ss << root_url << icon_def << ".zip";
		ofHttpResponse resp = ofLoadURL(ss.str());
		char* icon_data = resp.data.getData();
		memToStreamBuf buf(icon_data, icon_data + resp.data.size());
		Poco::Zip::Decompress unzip(istream(&buf), ofFilePath::join(ofFilePath::getCurrentExeDir(), "data/" + icon_dir_str));

		try {
			unzip.decompressAllFiles();
			cout <<"download complete : " << isExistsFile << endl;
			cout << "recursion" << endl;
			return GetIcon(icon_id, color, dpi, type);
		}
		catch (...)
		{
			cout << "[ERROR] ofxIconMaker extraction error" << endl;
			isExistsFile = false;
		}
	}

	if (isExistsFile == true)
	{
		cout << "new " << endl;
		return new ofImage(ofFile(icon_file));
	}
	else {
		return nullptr;
	}
}
