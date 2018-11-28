// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// file with compile-time constants

#include <cstdint>

#ifndef CONSTS
#define CONSTS

// consts

// number of layers limited to 255
const uint8_t NUM_LAYERS = 
;

// number of nodes in any layer limited to 255
// network can thus have up to 255^255 or ~4.653e613 neurons
// 5 layers -> up to ~1.078 trillion (255^5) neurons
const uint8_t LAYERS_SIZE [NUM_LAYERS] = {

};

// input/output size is up to 65535, this can be changed relatively easily
const uint16_t SIZE_INPUT = 5;

 
const uint16_t SIZE_OUTPUT = 5;

// graphs
typedef uint8_t weight;

weight component_graphs_raw [ NUM_LAYERS ] [ LAYERS_SIZE[0] ] [ LAYERS_SIZE[0] ] = {


















};


#endif
