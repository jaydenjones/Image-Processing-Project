#include "Header.h"
#include <fstream>
#include <iostream>
using namespace std;


void Header::ReadFile(const char *filename, Header &header)
{
	ifstream file(filename, ios_base::binary);

	istream& seekg(streampos pos);
	istream& seekg(streamoff off, ios_base::seekdir way);


	file.read(&idLength, sizeof(idLength));
	file.read(&colorMapType, sizeof(colorMapType));
	file.read(&dataTypeCode, sizeof(dataTypeCode));
	file.read((char *)&colorMapOrigin, sizeof(colorMapOrigin));
	file.read((char *)&colorMapLength, sizeof(colorMapLength));
	file.read(&colorMapDepth, sizeof(colorMapDepth));
	file.read((char *)&header.xOrigin, sizeof(xOrigin));
	file.read((char *)&header.yOrigin, sizeof(yOrigin));
	file.read((char *)&header.width, sizeof(width));
	file.read((char *)&header.height, sizeof(height));
	file.read(&bitsPerPixel, sizeof(bitsPerPixel));
	file.read(&imageDescriptor, sizeof(imageDescriptor));

	size = height * width;
}


int Header::GetVolume() {


	return size;
}



//void Header::WriteFile(const char *filename, Header &header) {
//
//
//	ofstream file(filename, ios_base::binary);
//
//	
//		file.write((char *)&idLength, sizeof(idLength));
//		
//		cout << (int)idLength << endl;
//
//		file.write((char *)&colorMapType, sizeof(colorMapType));
//		cout << (int)colorMapType << endl;
//
//		file.write((char *)&dataTypeCode, sizeof(dataTypeCode));
//		cout << (int)dataTypeCode << endl;
//
//		file.write((char *)&colorMapOrigin, sizeof(colorMapOrigin));
//		cout << (int)colorMapOrigin << endl;
//
//		file.write((char *)&colorMapLength, sizeof(colorMapLength));
//		cout << (int)colorMapLength << endl;
//
//		file.write((char *)&colorMapDepth, sizeof(colorMapDepth));
//		cout << (int)colorMapDepth << endl;
//
//		file.write((char *)&xOrigin, sizeof(xOrigin));
//		cout << (int)xOrigin << endl;
//
//		file.write((char *)&yOrigin, sizeof(yOrigin));
//		cout << (int)yOrigin << endl;
//
//		file.write((char *)&width, sizeof(width));
//		cout << (int)width << endl;
//
//		file.write((char *)&height, sizeof(height));
//		cout << (int)height << endl;
//
//		file.write((char *)&bitsPerPixel, sizeof(bitsPerPixel));
//		cout << (int)bitsPerPixel << endl;
//		
//		file.write((char *)&imageDescriptor, sizeof(imageDescriptor));
//		cout << (int)imageDescriptor << endl;
//
//
//
//}
