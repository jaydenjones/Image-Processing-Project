#pragma once
using namespace std;
struct Header
{


	char  idLength;
	char  colorMapType;
	char  dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char  colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char  bitsPerPixel;
	char  imageDescriptor;
	int size;
	

	void ReadFile(const char *filename, Header &header);
	void WriteFile(const char *filename, Header &header);

	int GetVolume();
	void Print();


};