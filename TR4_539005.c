#include "ordvetor.h"

/* Funcao para acessar, por meio do ponteiro, as variaveis da struct para a criaçao do vetor */
VETORORD* VETORD_create(int n, COMP* compara){ 
	VETORORD* vetor = malloc(sizeof(VETORORD));
	vetor->N = n;
	vetor->P = 0;
	vetor->elems = malloc(n * sizeof(void*));
	vetor->comparador = compara;
	return vetor;
}

/* Funcao para adiciomar no vetor */
void VETORD_add(VETORORD* vetor, void* newelem){ 

	/* verifica se ha espaco no vetor para adicionar o novo elemento */
	if(vetor->P < vetor->N){
		int posicao = vetor->P; 

		for(int i = 0; i < vetor->P; i++){

			/* compara se o elemento da posicao i eh maior do que o novo elemento */
			if(vetor->comparador(vetor->elems[i], newelem) == -1){
				posicao = i; // recebe a posiçao do maior elemento
				break;
			}
		}

		for(int i = vetor->P; i > posicao; i--){
			vetor->elems[i] = vetor->elems[i - 1]; // troca a posicao dos elementos para gerar vaga para o novo elemento
		}

		vetor->elems[posicao] = newelem; // adicao do novo elemento na posicao liberada 
		vetor->P++; // aumenta a quantidade de elementos 
	}	
}
/* Funcao para remover */
void* VETORD_remove(VETORORD* vetor){
	void* menor = vetor->elems[0]; 

	for(int i = 0; i < vetor->P - 1; i++){
		vetor->elems[i] = vetor->elems[i + 1]; // exclui o menor elemento, que eh o primeiro do vetor 
	}
	
	vetor->P--; // diminui a quantidade de elementos 

	return menor;
}