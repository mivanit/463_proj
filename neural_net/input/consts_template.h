// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// file with compile-time constants

#include <cstdint>
#include <queue>
#include <vector>

#ifndef CONSTS
#define CONSTS

// consts

// number of layers limited to 255
const uint8_t NUM_LAYERS = 4;

// number of nodes in any layer limited to 255
// network can thus have up to 255^255 or ~4.653e613 neurons
// 5 layers -> up to ~1.078 trillion (255^5) neurons
uint8_t LAYERS_SIZE [NUM_LAYERS] = {
10,
10,
10,
25
};

// input/output size is up to 65535, this can be changed relatively easily
const uint16_t SIZE_INPUT = 5;
const uint16_t SIZE_OUTPUT = 5;
typedef float weight;
// voltage type
typedef float voltage;
// timestamp type
typedef uint16_t time;

const voltage V_THRESHOLD = 0.0;
const voltage V_SPIKEAMP = 100.0;
const voltage V_RECOVERY = -30.0;

struct spike
{
	voltage v;
	time t;
};

typedef priority_queue < spike > spikeTrain;

time TIME_CURRENT = 0;

#endif
