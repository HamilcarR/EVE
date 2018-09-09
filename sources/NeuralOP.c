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
	layer->neurons = malloc(count*sizeof(NEURON*)); 
	int i = 0 ; 
	for(i ; i < count ; i++){
		layer->neurons[i] = create_neuron() ; 
	}
	return layer ; 

}


static void connect_neurons(NEURON* neuron, N_LAYER *layer_next , N_LAYER *layer_prev) {
	int i = 0;
	
	if (layer_next != NULL) {
		if (neuron->next != NULL) {
			free(neuron->next);
			neuron->next = NULL;
		}
		NEURON** next = malloc((layer_next->neuron_count + 1) * sizeof(NEURON*));
		for (i; i < layer_next->neuron_count; i++)
			next[i] = layer_next->neurons[i];
		next[i + 1] = NULL;
		neuron->next = next;
	}

	if (layer_prev != NULL) {
		i = 0;
		if (neuron->prev != NULL) {
			free(neuron->prev);
			neuron->prev = NULL;
		}
		NEURON** prev = malloc((layer_prev->neuron_count + 1) * sizeof(NEURON*));
		for (i; i < layer_prev->neuron_count; i++)
			prev[i] = layer_prev->neurons[i];
		prev[i + 1] = NULL;
		neuron->prev = prev;
	}
	
	
	
	
	
	
	

}




void connect_layers_perceptron(NETWORK* network){
	
	int i = 0, j = 0; 
	for (i; i < network->layer_count; i++) {
		for (j; j < network->layers[i]->neuron_count; j++) {
			NEURON* current = network->layers[i]->neurons[j]; 
			if (i == 0) {
				current->prev = NULL; 
				if (i + 1 < network->layer_count)
					connect_neurons(current, network->layers[i + 1], NULL); 

				else
					current->next = NULL; 
			}
			else if (i == network->layer_count - 1) {
				current->next = NULL; 
				if (i - 1 >= 0) {
					connect_neurons(current, NULL, network->layers[i - 1]);
				}
				else
					current->prev = NULL; 

			}
			else {
				connect_neurons(current, network->layers[i + 1], network->layers[i - 1]); 
			}
		}
	}
	
	

}




NETWORK* create_network(int count , N_LAYER** layer_array ){
	NETWORK* network = malloc(sizeof(NETWORK)); 
	network->layer_count = count ; 
	network->layers = layer_array ; 
	return network ; 	


}
