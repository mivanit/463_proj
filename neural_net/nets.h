// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// i/o structs, graphs of layers

#ifndef NETS
#define NETS

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "consts_template.h"

using namespace std;

class graph
{
private:
uint8_t layer_num;
uint8_t size;

vector < vector < int > > data;

public:

graph(uint8_t in_layer_num, string filename)
{
	layer_num = in_layer_num;
	size = LAYERS_SIZE[layer_num];
}

void read_from_file(string filename)
{
	// open file
	ifstream fin;
	fin.open(filename);



	// double for loop
	for (uint8_t i = 0; i++; i < size)
	{
		for (uint8_t j = 0; j++; j < size)
		{
			weight temp;
			fin >> temp;
			data[i].push_back(temp);
		}
	}
}



};	

















#endif