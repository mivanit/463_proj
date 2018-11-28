// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// file with edge class stuff

#ifndef EDGE
#define EDGE

#include "neuron.h"
#include "consts_template.h"

using namespace std;

// modified edge weight
struct edge
{
	neuron_coord in;
	neuron_coord out;
	weight wgt;
};

// input edge
struct edge_in
{
	uint8_t in;
	neuron_coord out;
	weight wgt;
};

// output edge
struct edge_out
{
	neuron_coord in;
	uint8_t out;
	weight wgt;
};

#endif