#ifndef NEURALOP_H
#define NEURALOP_H
#include <stdlib.h>
#include <stdio.h>



typedef struct NEURON; 
typedef struct N_LAYER; 
typedef struct NETWORK; 




typedef struct NEURON{
	float threshold ; 
	float weight ; 
	/*function pointer*/
	void* function ; 
	/* NULL terminated arrays , that point to the neurons of the next and previous layer , connected to the current neuron*/
	struct NEURON** next; 
	struct NEURON** prev;


	
}NEURON;

typedef struct N_LAYER{
	int neuron_count ;
	NEURON **neurons ; 

}N_LAYER;

typedef struct NETWORK{
	int layer_count ; 
	N_LAYER ** layers ; 

}NETWORK;




N_LAYER* create_layer(int count ) ; 
NEURON*  create_neuron() ; 
NETWORK* create_network(int count , N_LAYER** layers_array ) ; 
void connect_layers_perceptron(NETWORK* network ) ; 














#endif
