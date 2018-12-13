// Michael Ivanitskiy, Connor Puritz
// Math 463 Fall 2018 Final Project

// puts everything together

#ifndef BRAIN
#define BRAIN

#include <unordered_map>
#include "nets.h"
#include "util/err_util.h"

class brain
{
private:

// array for layers
graph layers [NUM_LAYERS];
// neurons with nonzero voltage
unordered_map < neuron_coord, neuron > active_neurons;
// edges that have been modified
unordered_map < coord_pair, edge > mod_edges;
unordered_map < neuron_coord, edge > add_edges;

public:

brain(vector < string > filenames)
{
	CHK_ERROR_FATAL(filenames.size() != NUM_LAYERS, "wrong number of filenames");
	
	for (uint8_t i = 0; i < NUM_LAYERS; i++)
	{
		layers[i] = graph( i, filenames[i] );
	}
}

void fire(neuron & n)
{
	// if the neuron should fire at this timestep
	if (n.try_fire())
	{
		// every edge specified by graph tensor:

		// loop over layers
		// for every
	}
}


void fire_all_adj(neuron & n, uint8_t layer)
{
	graph & graph_testing = layers[layer];
	neuron_coord coord;
	// for every adjacent neuron in the layer
	// 			   	   graph	adjlst   entry
	// 			   layers[layer].data[ n.c[layer] ]
	for ( uint8_t i = 0; i < graph_testing.size; i++ )
	{
		// access graph_testing 's data at n.c[layer] (the coordinate in the layer)
		// this tells us if the neuron with identical coordinates, but c[layer] set to "i"
		// is connected
		// if nonzero wgt
		if ( !zero_f(graph_testing.data[coord[layer]][i].wgt) )
		{
			// test if edge modified
			neuron_coord coord_test = coord.nrn_crd_replace(layer, i);
			
		}


		if ( layer < NUM_LAYERS - 1 )
		{
			// if not at bottom layer
			// for every adjacent neuron, recurse
			fire_all_adj(n, layer + 1);
		}
	}
}

inline void push_spike_to_neuron(coord_pair p, uint8_t L)
{
	auto iter_test = mod_edges.find(p);

	// spike elt = spike();

	if ( iter_test == mod_edges.end() )
	{
		// if not modified, use actual val
		// TODO: double check arr scubscripts here
		edge_base & e = layers[ L ].data[ p.in[ L ] ][ p.out[ L ] ];
		elt = spike(V_SPIKEAMP * e.wgt, TIME_CURRENT + e.delay)
	}
	else
	{
		// if modified, use whatever was found
		iter_test->second. 
	}
}



// TODO: unoredered map for neurons?


};

#endif