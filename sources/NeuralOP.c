#include "../includes/NeuralOP.h"













NEURON* create_neuron(){
	NEURON *neuron = malloc(sizeof(NEURON)); 
	neuron->threshold = 0 ; 
	neuron->weight = 0 ; 
	neuron->function = NULL ; 
	neuron->next = NULL ; 
	neuron->prev = NULL ; 

	return neuron ; 


}



N_LAYER* create_layer(int count){

	N_LAYER* layer = malloc(sizeof(N_LAYER)); 
	layer->neuron_count = count ; 
	layer->layer = malloc(count*sizeof(NEURON)); 
	int i = 0 ; 
	for(i ; i < count ; i++){
		layer->layer[i] = create_neuron() ; 
	}
	return layer ; 

}


void connect_layers(int count , N_LAYER** layers ,enum LINKAGE link){
	if (link == P) {

	}
	

}




NETWORK* create_network(int count , N_LAYER** layer_array ,enum LINKAGE link){
	NETWORK* network = malloc(sizeof(NETWORK)); 
	network->layer_count = count ; 
	network->layers = layer_array ; 
	return network ; 	


}
