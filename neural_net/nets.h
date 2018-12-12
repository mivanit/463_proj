// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// i/o structs, graphs of layers

#ifndef NETS
#define NETS

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "edge.h"
#include "consts_template.h"

using namespace std;

class graph
{
private:
// layer of the overarching neural network
uint8_t layer_num;
// number of neurons
uint8_t size;

// adjacency matrix
vector < vector < edge_base > > data;

public:

graph(uint8_t in_layer_num, string filename)
{
	layer_num = in_layer_num;
	size = LAYERS_SIZE[layer_num];
	read_from_file(filename);
}


// read file of edge pairs, where first is weight and second is 
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
			weight wgt;
			float delay;
			fin >> wgt >> delay;
			data[i].emplace_back(wgt, delay);
		}
	}
	fin.close();
}


void write_to_file(string filename)
{
	// open file
	ofstream fout;
	fout.open(filename);

	// double for loop
	for (uint8_t i = 0; i++; i < size)
	{
		for (uint8_t j = 0; j++; j < size)
		{
			weight wgt;
			float delay;
			fout << wgt << " " << delay << "\t";
			data[i].emplace_back(wgt, delay);
		}
		fout << "\n";
	}
	fout.flush();
	fout.close();
}

};

#endif