#include "Header.h"
#include "Pixel.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


void WriteFile(const char *filename, Header &header, vector<Pixel> &pixels) {


	ofstream file(filename, ios_base::binary);


	file.write((char *)&header.idLength, sizeof(header.idLength));

	file.write((char *)&header, sizeof(header.colorMapType));

	file.write((char *)&header.dataTypeCode, sizeof(header.dataTypeCode));

	file.write((char *)&header.colorMapOrigin, sizeof(header.colorMapOrigin));

	file.write((char *)&header.colorMapLength, sizeof(header.colorMapLength));

	file.write((char *)&header.colorMapDepth, sizeof(header.colorMapDepth));

	file.write((char *)&header.xOrigin, sizeof(header.xOrigin));

	file.write((char *)&header.yOrigin, sizeof(header.yOrigin));

	file.write((char *)&header.width, sizeof(header.width));

	file.write((char *)&header.height, sizeof(header.height));

	file.write((char *)&header.bitsPerPixel, sizeof(header.bitsPerPixel));

	file.write((char *)&header.imageDescriptor, sizeof(header.imageDescriptor));



	for (unsigned int i = 0; i < pixels.size(); i++)
	{

		file.write((char *)&pixels[i].blue, 1);
		file.write((char *)&pixels[i].green, 1);
		file.write((char *)&pixels[i].red, 1);


	}



}

int main()
{
	
	Header header;
	Pixel pixel;
	vector<Pixel> pixelsArray;
	vector<Pixel> pixelsArray2;
	vector<Pixel> pixelsArray3;
	vector<Pixel> pixelsArray4;


/*=====Task 1 ======*/

	string file = "input/layer1.tga"; //fix this later
	header.ReadFile(file.c_str(), header);
	pixel.SetVolume(header.GetVolume());
	pixel.ReadFile(file.c_str(), pixel, pixelsArray);


	file = "input/pattern1.tga";
	header.ReadFile(file.c_str(), header);
	pixel.SetVolume(header.GetVolume());
	pixel.ReadFile(file.c_str(), pixel, pixelsArray2);


	string newFile = "output/part1.tga";

			pixel.Multiply(pixelsArray, pixelsArray2);
	
			WriteFile(newFile.c_str(), header, pixelsArray2);
	
	
			file = "examples/EXAMPLE_part1.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray3);
	
			cout << "Test 1: ";
	
			for (unsigned int i = 0; i < pixelsArray.size(); i++)
			{
	
				pixelsArray2[i] == pixelsArray3[i];
	
				if (i == pixelsArray.size() - 1)
				{
					cout << "Passed!" << endl;
	
				}
			
			}
	
		
	pixelsArray.clear();
	pixelsArray2.clear();
	pixelsArray3.clear();

		
	
/*=====Task 2 ======*/
	
			file = "input/car.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray);
	
	
			file = "input/layer2.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
	
			newFile = "output/part2.tga";
	
			pixel.Subtract(pixelsArray, pixelsArray2);
	
			WriteFile(newFile.c_str(), header, pixelsArray2);
	
			file = "examples/EXAMPLE_part2.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray3);
	
			cout << "Test 2: ";
	
			for (unsigned int i = 0; i < pixelsArray.size(); i++)
			{
	
				pixelsArray2[i] == pixelsArray3[i];
	
				if (i == pixelsArray.size() - 1)
				{
					cout << "Passed!" << endl;
	
				}
	
			}
	
	
			pixelsArray.clear();
			pixelsArray2.clear();
			pixelsArray3.clear();
	
			
	
	
		
	
/*=====Task 3 ======*/
	
			file = "input/layer1.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray);
	
	
			file = "input/pattern2.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
	
			
			newFile = "input/part3.tga";
	
			pixel.Multiply(pixelsArray, pixelsArray2);
	
			WriteFile(newFile.c_str(), header, pixelsArray2);
	
			pixelsArray.clear();
			pixelsArray2.clear();
	
			file = "input/text.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray);
	
			file = "input/part3.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
			pixel.Screen(pixelsArray, pixelsArray2);
	
			newFile = "output/part3.tga";
	
			WriteFile(newFile.c_str(), header, pixelsArray2);
	
	
			file = "examples/EXAMPLE_part3.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray3);
	
			cout << "Test 3: ";
	
			for (unsigned int i = 0; i < pixelsArray.size(); i++)
			{
	
				pixelsArray2[i] == pixelsArray3[i];
	
				if (i == pixelsArray.size() - 1)
				{
					cout << "Passed!" << endl;
	
				}
	
			}
	
	
			pixelsArray.clear();
			pixelsArray2.clear();
			pixelsArray3.clear();
			
/*=====Task 4 ======*/
	
	
			file = "input/layer2.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray);
	
	
			file = "input/circles.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
	
	
			newFile = "input/part4.tga";
	
			pixel.Multiply(pixelsArray, pixelsArray2);
	
			WriteFile(newFile.c_str(), header, pixelsArray2);
	
			pixelsArray.clear();
			pixelsArray2.clear();
	
			file = "input/part4.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray);
	
			file = "input/pattern2.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
			pixel.Subtract(pixelsArray, pixelsArray2);
	
			newFile = "output/part4.tga";
	
			WriteFile(newFile.c_str(), header, pixelsArray2);
	
	
	
			file = "examples/EXAMPLE_part4.tga";
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray3);
	
			cout << "Test 4: ";
	
			for (unsigned int i = 0; i < pixelsArray.size(); i++)
			{
	
				pixelsArray2[i] == pixelsArray3[i];
	
				if (i == pixelsArray.size() - 1)
				{
					cout << "Passed!" << endl;
	
				}
	
			}
	
	
			pixelsArray.clear();
			pixelsArray2.clear();
			pixelsArray3.clear();
	
	
		
		 
/*=====Task 5 ======*/
	
		
			file = "input/layer1.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray);
	
	
			file = "input/pattern1.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
	
			newFile = "output/part5.tga";
	
			pixel.Overlay(pixelsArray, pixelsArray2);
	
			WriteFile(newFile.c_str(), header, pixelsArray2);
	
	
	
			file = "examples/EXAMPLE_part5.tga";
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray3);
	
			cout << "Test 5: ";
	
			for (unsigned int i = 0; i < pixelsArray.size(); i++)
			{
	
				pixelsArray2[i] == pixelsArray3[i];
	
				if (i == pixelsArray.size() - 1)
				{
					cout << "Passed!" << endl;
	
				}
	
			}
	
	
			pixelsArray.clear();
			pixelsArray2.clear();
			pixelsArray3.clear();
		
	
/*=====Task 6 ======*/
	
			file = "input/car.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray);
	
			newFile = "output/part6.tga";
	
			pixel.AddGreen(pixelsArray);
	
			WriteFile(newFile.c_str(), header, pixelsArray);
	
			file = "examples/EXAMPLE_part6.tga";
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
			cout << "Test 6: ";
	
			for (unsigned int i = 0; i < pixelsArray.size(); i++)
			{
	
				pixelsArray[i] == pixelsArray2[i];
	
				if (i == pixelsArray.size() - 1)
				{
					cout << "Passed!" << endl;
	
				}
	
			}
	
	
			pixelsArray.clear();
			pixelsArray2.clear();
			pixelsArray3.clear();
			
		
/*=====Task 7 ======*/
	
		
			file = "input/car.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray);
	
			newFile = "output/part7.tga";
	
			pixel.ScaleRedandBlue(pixelsArray);
	
			WriteFile(newFile.c_str(), header, pixelsArray);
	
			file = "examples/EXAMPLE_part7.tga";
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
			cout << "Test 7: ";
	
			for (unsigned int i = 0; i < pixelsArray.size(); i++)
			{
	
				pixelsArray[i] == pixelsArray2[i];
	
				if (i == pixelsArray.size() - 1)
				{
					cout << "Passed!" << endl;
	
				}
	
			}
	
	
			pixelsArray.clear();
			pixelsArray2.clear();
			pixelsArray3.clear();
		
	
/*=====Task 8 ======*/


		file = "input/car.tga"; 
		header.ReadFile(file.c_str(), header);
		pixel.SetVolume(header.GetVolume());
		pixel.ReadFile(file.c_str(), pixel, pixelsArray);

		newFile = "output/part8_b.tga";

		pixel.LoadB(pixelsArray);

		WriteFile(newFile.c_str(), header, pixelsArray);
		
		file = "examples/EXAMPLE_part8_b.tga";
		header.ReadFile(file.c_str(), header);
		pixel.SetVolume(header.GetVolume());
		pixel.ReadFile(file.c_str(), pixel, pixelsArray2);


		cout << "Test 8: ";
		
				for (unsigned int i = 0; i < pixelsArray.size(); i++)
				{
		
					pixelsArray[i] == pixelsArray2[i];
		
					if (i == pixelsArray.size() - 1)
					{
						cout << "Passed!" << endl;
		
					}
		
				}
		
		pixelsArray.clear();
		pixelsArray2.clear();


		file = "input/car.tga";
		header.ReadFile(file.c_str(), header);
		pixel.SetVolume(header.GetVolume());
		pixel.ReadFile(file.c_str(), pixel, pixelsArray);

		newFile = "output/part8_g.tga";

		pixel.LoadG(pixelsArray);

		WriteFile(newFile.c_str(), header, pixelsArray);

		file = "examples/EXAMPLE_part8_g.tga";
		header.ReadFile(file.c_str(), header);
		pixel.SetVolume(header.GetVolume());
		pixel.ReadFile(file.c_str(), pixel, pixelsArray2);\

			cout << "Test 9: ";

		for (unsigned int i = 0; i < pixelsArray.size(); i++)
		{

			pixelsArray[i] == pixelsArray2[i];

			if (i == pixelsArray.size() - 1)
			{
				cout << "Passed!" << endl;

			}

		}

		pixelsArray.clear();
		pixelsArray2.clear();



		file = "input/car.tga";
		header.ReadFile(file.c_str(), header);
		pixel.SetVolume(header.GetVolume());
		pixel.ReadFile(file.c_str(), pixel, pixelsArray);

		newFile = "output/part8_r.tga";

		pixel.LoadR(pixelsArray);

		WriteFile(newFile.c_str(), header, pixelsArray);

		file = "examples/EXAMPLE_part8_r.tga";
		header.ReadFile(file.c_str(), header);
		pixel.SetVolume(header.GetVolume());
		pixel.ReadFile(file.c_str(), pixel, pixelsArray2);

		cout << "Test 10: ";

		for (unsigned int i = 0; i < pixelsArray.size(); i++)
		{

			pixelsArray[i] == pixelsArray2[i];

			if (i == pixelsArray.size() - 1)
			{
				cout << "Passed!" << endl;

			}

		}


		pixelsArray.clear();
		pixelsArray2.clear();

	

/*=====Task 9 ======*/
	
	
		
			file = "input/layer_blue.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray);
	
	
			file = "input/layer_green.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
	
			file = "input/layer_red.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray3);
	
	
			newFile = "input/Combine.tga";
	
			pixel.Combine(pixelsArray, pixelsArray2, pixelsArray3);
	
			newFile = "output/part9.tga";
	
			WriteFile(newFile.c_str(), header, pixelsArray3);
	
			
			pixelsArray.clear();
			pixelsArray2.clear();
	
			file = "examples/EXAMPLE_part9.tga";
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
			cout << "Test 11: ";
	
			for (unsigned int i = 0; i < pixelsArray2.size(); i++)
			{
	
				pixelsArray3[i] == pixelsArray2[i];
	
				if (i == pixelsArray3.size() - 1)
				{
					cout << "Passed!" << endl;
	
				}
	
			}
	
	
			pixelsArray.clear();
			pixelsArray2.clear();
			pixelsArray3.clear();
	
		
	
	
/*=====Task 10======*/
	
	
			file = "input/text2.tga"; 
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray);
	
	
			newFile = "output/part10.tga";
	
			pixel.Flip(pixelsArray, pixelsArray);
	
			WriteFile(newFile.c_str(), header, pixelsArray);
	
			file = "examples/EXAMPLE_part10.tga";
			header.ReadFile(file.c_str(), header);
			pixel.SetVolume(header.GetVolume());
			pixel.ReadFile(file.c_str(), pixel, pixelsArray2);
	
			cout << "Test 12: ";
	
			for (unsigned int i = 0; i < pixelsArray.size(); i++)
			{
	
				pixelsArray[i] == pixelsArray2[i];
	
				if (i == pixelsArray.size() - 1)
				{
					cout << "Passed!" << endl;
	
				}
	
			}
	
	
			pixelsArray.clear();
			pixelsArray2.clear();
			pixelsArray3.clear();
	
	
		
	}
