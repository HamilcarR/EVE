#ifndef NEURALOP_H
#define NEURALOP_H
#include <stdlib.h>
#include <stdio.h>



enum LINKAGE {P}; 


typedef struct NEURON{
	float threshold ; 
	float weight ; 
	void* function ; 
	struct NEURON* next ; 
	struct NEURON* prev ; 

	
}NEURON;

typedef struct N_LAYER{
	int neuron_count ;
	NEURON **layer ; 

}N_LAYER;

typedef struct NETWORK{
	int layer_count ; 
	N_LAYER ** layers ; 

}NETWORK;




N_LAYER* create_layer(int count ) ; 
NEURON*  create_neuron() ; 
NETWORK* create_network(int count , N_LAYER** layers_array ,enum LINKAGE link) ; 
void connect_layers(int count , N_LAYER** layers , enum LINKAGE link) ; 














#endif
