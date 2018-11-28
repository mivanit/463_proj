// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// i/o structs, graphs of layers

#ifndef NETS
#define NETS

#include "consts_template.h"

class graph
{

uint8_t layer_num;
uint8_t size;

weight * data;

graph(uint8_t in_layer_num)
{
	layer_num = in_layer_num;
	size = LAYERS_SIZE[layer_num];

	data = component_graphs_raw[layer_num];
}

};

















#endif