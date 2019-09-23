#pragma once
#include <string>
#include <vector>
using namespace std;

struct Pixel
{


	unsigned char red;
	unsigned char green;
	unsigned char blue;

	int size;
	void SetVolume(int value);
	
	void ReadFile(const char *filename, Pixel &pixel, vector<Pixel> &pixels);
	void WriteFile(const char *filename, vector<Pixel> &pixels);
	void Multiply(vector<Pixel> &pixels, vector<Pixel> &pixels2);
	void Subtract(vector<Pixel> &pixels, vector<Pixel> &pixels2);
	void Screen(vector<Pixel> &pixels, vector<Pixel> &pixels2);
	void Overlay(vector<Pixel> &pixels, vector<Pixel> &pixels2);
	void AddGreen(vector<Pixel> &pixels);
	void ScaleRedandBlue(vector<Pixel> &pixels);
	void LoadB(vector<Pixel> &pixels);
	void LoadG(vector<Pixel> &pixels);
	void LoadR(vector<Pixel> &pixels);
	void Combine(vector<Pixel> &bluePixels, vector<Pixel> &greenPixels, vector<Pixel> &redPixels);
	void Flip(vector<Pixel> &pixels, vector<Pixel> pixels2);
	bool operator==(const Pixel& rhs) const;

};	