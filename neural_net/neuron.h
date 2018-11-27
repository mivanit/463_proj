// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// file with neuron class stuff

#ifndef NEURON
#define NEURON

#include "consts_template.h"

using namespace std;

// custom type of "neuron_coord" as a size_t array of length NUM_LAYERS
typedef uint8_t neuron_coord [NUM_LAYERS];

// voltage type
typedef uint8_t voltage;

// timestamp type
typedef uint16_t time;

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
// stores time voltage hits, voltage, and coordinate
time t;
voltage v;	
neuron_coord c;
};


#endif