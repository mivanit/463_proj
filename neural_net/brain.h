// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// puts everything together

#ifndef BRAIN
#define BRAIN

#include "nets.h"
#include "util/err_util.h"

class brain
{
private:

// array for layers
graph data [NUM_LAYERS];

public:

brain(vector < string > filenames)
{
	CHK_ERROR_FATAL(filenames.size() != NUM_LAYERS, "wrong number of filenames");
	
	for (uint8_t i = 0; i < NUM_LAYERS; i++)
	{
		data[i] = graph( i, filenames[i] );
	}
}






#endif