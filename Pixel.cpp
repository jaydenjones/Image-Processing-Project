#include "Header.h"
#include "Pixel.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




void Pixel::ReadFile(const char *filename, Pixel &pixel, vector<Pixel> &pixels) 
{

	ifstream file(filename, ios_base::binary);

	istream& seekg(streampos pos);
	istream& seekg(streamoff off, ios_base::seekdir way);

	file.seekg(18);


	for (unsigned int i = 0; i < size; i++)
	{

		file.read((char*)&pixel.blue, sizeof(pixel.blue));
		file.read((char*)&pixel.green, sizeof(pixel.green));
		file.read((char*)&pixel.red, sizeof(pixel.red));

		pixels.push_back(pixel);

	}



}
//
//void Pixel::WriteFile(const char *filename, vector<Pixel> &pixels) {
//
//
//
//
//	ofstream file(filename, ios_base::binary);
//
//	for (unsigned int i = 0; i < 10; i++)
//	{
//		
//		file.write((char *)&pixels[i].blue, 1);
//		file.write((char *)&pixels[i].green, 1);
//		file.write((char *)&pixels[i].red, 1);
//			   
//
//	}
//
//
//}


void Pixel::SetVolume(int value)
{

	size = value;

}


void Pixel::Multiply(vector<Pixel> &pixels, vector<Pixel> &pixels2)
{
	
	for (unsigned int i = 0; i < pixels.size(); i++)
	{


		int newBlue = ((float)((float)pixels[i].blue / (float)255) * (float)((float)pixels2[i].blue / (float)255)) * 255 + 0.5;
		int newGreen = ((float)((float)pixels[i].green / (float)255) * (float)((float)pixels2[i].green / (float)255)) * 255 + 0.5;
		int newRed = ((float)((float)pixels[i].red / (float)255) * (float)((float)pixels2[i].red / (float)255)) * 255 + 0.5;

		pixels2[i].blue = newBlue;
		pixels2[i].green = newGreen;
		pixels2[i].red = newRed;


	}

}


void Pixel::Subtract(vector<Pixel> &pixels, vector<Pixel> &pixels2)
{
	for (unsigned int i = 0; i < pixels.size(); i++)
	{

		int newBlue = pixels[i].blue - pixels2[i].blue;

		if (newBlue > 255) {

			newBlue = 255;
		}
		if (newBlue < 0) {


			newBlue = 0;
		}

		int newGreen = pixels[i].green - pixels2[i].green;


		if (newGreen > 255) { //255?

			newGreen = 255;

		}
		if (newGreen < 0) {


			newGreen = 0;
		}

		int newRed = pixels[i].red - pixels2[i].red;

		if (newRed > 255) {

			newRed = 255;
		}
		if (newRed < 0) {


			newRed = 0;
		}

		pixels2[i].blue = (unsigned char)newBlue;
		pixels2[i].green = (unsigned char)newGreen;
		pixels2[i].red = (unsigned char)newRed;


	}


}

void Pixel::Screen(vector<Pixel> &pixels, vector<Pixel> &pixels2)
{

	for (unsigned int i = 0; i < pixels.size(); i++)
	{

		int newBlue = (1 - ((float) (1 - ((float)pixels[i].blue / (float)255)) * (float)(1 - ((float)pixels2[i].blue / (float)255)))) * 255 + 0.5;
		int newGreen = (1 - ((float)(1 - ((float)pixels[i].green / (float)255)) * (float)(1- ((float)pixels2[i].green / (float)255)))) * 255 + 0.5;
		int newRed = (1 - ((float)(1 - ((float)pixels[i].red / (float)255)) * (float)(1 - ((float)pixels2[i].red / (float)255)))) * 255 + 0.5;
		pixels2[i].blue = newBlue;
		pixels2[i].green = newGreen;
		pixels2[i].red = newRed;


	}

}

void Pixel::Overlay(vector<Pixel> &pixels, vector<Pixel> &pixels2)
{

	for (unsigned int i = 0; i < pixels.size(); i++)
	{

		
		int newBlue = 0;
		float smallBlue = (float)(((float)pixels2[i].blue / (float)255));

		if (smallBlue <= 0.5)
		{
			newBlue = (2 * (float)((float)pixels[i].blue / (float)255) * (float)((float)pixels2[i].blue / (float)255)) * 255 + 0.5;

		}
		else
		{

			newBlue = (1 - (2 * ((float)(1 - ((float)pixels[i].blue / (float)255)) * (float)(1 - ((float)pixels2[i].blue / (float)255))))) * 255 + 0.5;
			
		}

		
		int newGreen = 0;
		float smallGreen = (float)(((float)pixels2[i].green / (float)255));

		if (smallGreen <= 0.5)
		{
			newGreen = (2 * (float)((float)pixels[i].green / (float)255) * (float)((float)pixels2[i].green / (float)255)) * 255 + 0.5;

		}
		else
		{

			newGreen = (1 - (2 * ((float)(1 - ((float)pixels[i].green / (float)255)) * (float)(1 - ((float)pixels2[i].green / (float)255))))) * 255 + 0.5;

		}

		int newRed = 0;
		float smallRed = (float)(((float)pixels2[i].red / (float)255));


		if (smallRed <= 0.5)
		{
			newRed = (2 * (float)((float)pixels[i].red / (float)255) * (float)((float)pixels2[i].red / (float)255)) * 255 + 0.5;

		}

		else
		{

			newRed = (1 - (2 * ((float)(1 - ((float)pixels[i].red / (float)255)) * (float)(1 - ((float)pixels2[i].red / (float)255))))) * 255 + 0.5;

		}


		pixels2[i].blue = newBlue;
		pixels2[i].green = newGreen;
		pixels2[i].red = newRed;


	}

}

void Pixel::AddGreen(vector<Pixel> &pixels)
{

	for (unsigned int i = 0; i < pixels.size(); i++)
	{

		
		int newGreen = pixels[i].green + 200;


		if (newGreen > 255) { //255?

			newGreen = 255;

		}
		if (newGreen < 0) {


			newGreen = 0;
		}


		pixels[i].green = (unsigned char)newGreen;


	}

}

void Pixel::ScaleRedandBlue(vector<Pixel> &pixels)
{

	for (unsigned int i = 0; i < pixels.size(); i++)
	{

		int newBlue = (0 * (float)((float)pixels[i].blue / (float)255)) * 255 + 0.5;
		int newRed = (4 * (float)((float)pixels[i].red / (float)255)) * 255 + 0.5;
		if (newRed > 255) {

			newRed = 255;

		}

		pixels[i].blue = newBlue;
		pixels[i].red = newRed;


	}

}

void Pixel::LoadB(vector<Pixel> &pixels)
{

	for (unsigned int i = 0; i < pixels.size(); i++)
	{


		pixels[i].green = pixels[i].blue;
		pixels[i].red = pixels[i].blue;


	}

}


void Pixel::LoadG(vector<Pixel> &pixels)
{

	for (unsigned int i = 0; i < pixels.size(); i++)
	{


		pixels[i].blue = pixels[i].green;
		pixels[i].red = pixels[i].green;


	}

}

void Pixel::LoadR(vector<Pixel> &pixels)
{

	for (unsigned int i = 0; i < pixels.size(); i++)
	{


		pixels[i].blue = pixels[i].red;
		pixels[i].green = pixels[i].red;


	}



}

void Pixel::Combine(vector<Pixel> &bluePixels, vector<Pixel> &greenPixels ,vector<Pixel> &redPixels)
{

	for (unsigned int i = 0; i < bluePixels.size(); i++)
	{

		redPixels[i].blue = bluePixels[i].blue;
		redPixels[i].green = greenPixels[i].green;


	}

}

void Pixel::Flip(vector<Pixel> &pixels, vector<Pixel> pixels2) 
{


	pixels.clear();

	for (unsigned int i = pixels2.size() - 1; i >= 0; i--)
	{

			pixels.push_back(pixels2[i]);


			if (i == 0) {

				return;
			}

	}

}

bool Pixel::operator==(const Pixel& rhs) const
{

		int i = 0;

		if ((int)blue != (int)rhs.blue)
		{	
			cout << "Failed!" << endl;
			return false;

		}
		if ((int)green != (int)rhs.green)
		{
			cout << "Failed!" << endl;
			return false;
		}

		if ((int)red != (int)rhs.red)
		{
			cout << "Failed!" << endl;
			return false;
		}

	
	return true;
}

