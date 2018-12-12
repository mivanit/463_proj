// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// file with neuron class stuff

#ifndef NEURON
#define NEURON

#include <limits>

#include "input/consts_template.h"

using namespace std;

// custom type of "neuron_coord" as a size_t array of length NUM_LAYERS
typedef uint8_t neuron_coord [NUM_LAYERS];

/*
##    ## ######## ##     ## ########   #######  ##    ##
###   ## ##       ##     ## ##     ## ##     ## ###   ##
####  ## ##       ##     ## ##     ## ##     ## ####  ##
## ## ## ######   ##     ## ########  ##     ## ## ## ##
##  #### ##       ##     ## ##   ##   ##     ## ##  ####
##   ### ##       ##     ## ##    ##  ##     ## ##   ###
##    ## ########  #######  ##     ##  #######  ##    ##
*/

class neuron
{
// stores time voltages hit, voltage, and coordinate
neuron_coord c;
spikeTrain spikes_in;

// FIXME: use heapify for spike train vector
// FIXME: optimize by reading several before calling heapify again?
spikeTrain get_spikes_out()
{
	spikeTrain output;
	// read until current time
	while (spikes_in.top().t < TIME_CURRENT)
	{
		
	}
}



};


#endif