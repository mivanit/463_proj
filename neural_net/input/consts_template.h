// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// file with compile-time constants

#include <cstdint>
#include <queue>
#include <vector>

#ifndef CONSTS
#define CONSTS

using namespace std;

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

time TIME_CURRENT = 0;

// resting voltage
const voltage V_REST = 0.0;
// threshold voltage to fire neuron
const voltage V_THRESHOLD = 100.0;
// amplitude of spikes, if threshold crossed
const voltage V_SPIKEAMP = 1000.0;
// voltage the next timestep after firing
const voltage V_RECOVERY = -30.0;
// percentage of voltage remaining after every timestep, if not fired
const voltage V_DECAY = 0.1;

struct spike
{
	spike() : v(0) {}

	spike(voltage in_volt, time in_time)
		: v(in_volt), t(in_time) {}

	voltage v;
	time t;
};

class spike_timesort
{
public:
spike_timesort() {}

// comparator for spikes
inline bool operator() (const spike & lhs, const spike & rhs) const
{
	return (lhs.t < rhs.t);
}

};

typedef priority_queue < spike, vector < spike >, spike_timesort > spikeTrain;

// margin for comparing floats
const float EPSILON = 0.1;

// code for comparing two floats
inline bool compf(float a, float b)
{
    return fabs(a - b) <= EPSILON;
}

inline bool zero_f(float a)
{
	return fabs(a) <= EPSILON;
}




// custom type of "neuron_coord" as a size_t array of length NUM_LAYERS
struct neuron_coord
{
	neuron_coord() {}

	neuron_coord(neuron_coord * input)
	{
		for (uint8_t L = 0; L < NUM_LAYERS; L++)
		{
			data[L] = input->data[L];
		}
	}

	uint8_t data [NUM_LAYERS];

	inline uint8_t operator [] (uint8_t L)
	{
		return data[L];
	}

	// TODO: optimize this
	inline neuron_coord nrn_crd_replace(uint8_t layer, uint8_t value)
	{
		neuron_coord c(this);
		c.data[layer] = value;
		return c;
	}
}


#endif
