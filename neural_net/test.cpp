// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

#include <iostream>
#include <string>
#include <vector>

#include "brain.h"

int main()
{
	vector < string > filenames (NUM_LAYERS, "input/basic5n.tsv");
	
	brain testbrain (filenames);

	while (true)
	{
		testbrain.step();
	}



	return 0;
}

