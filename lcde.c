#include "lcde.h"
#include <stdio.h>
#include <stdlib.h>

ncde *novoNo (int chave){
	ncde *novo = (ncde *) malloc (sizeof (ncde));
	if (!novo){
		printf("Erro.\n");
		return NULL;
	}	
	novo->chave = chave;
	novo->prox = novo;
	novo->ant = novo;	
	return novo;
}

ncde *insereInicio (ncde *Lista, ncde *novo){
	ncde *aux = Lista;
	if (!Lista){
		novo->prox = novo;
		novo->ant = novo;
		return novo;	
	}
	novo->prox = aux;
	novo->ant = aux->ant;
	aux->ant = novo;
	novo->ant->prox = novo;
	return novo;
}

ncde *insereFim (ncde *Lista, ncde *novo){
	ncde *aux = Lista;
	if (!Lista){
		novo->prox = novo;
		novo->ant = novo;
		return novo;	
	}
	novo->prox = aux;
	novo->ant = aux->ant;
	aux->ant = novo;
	novo->ant->prox = novo;
	return Lista;
}

ncde *insereOrd (ncde *Lista, ncde *novo){
	if (!Lista) return novo;
	ncde *aux = Lista;
	while (aux->prox != Lista  && aux->chave < novo->chave) aux = aux->prox;
	if (aux->chave < novo->chave){
		novo->ant = aux;
		novo->prox = aux->prox;
		aux->prox->ant = novo;
		aux->prox = novo;
		return Lista;
	}
	if (aux == Lista){
		novo->prox = aux;
		novo->ant = aux->ant;
		aux->ant->prox = novo;
		novo->prox->ant = novo;
		return novo;
	}
	novo->prox = aux;
	novo->ant = aux->ant;
	aux->ant->prox = novo;
	novo->prox->ant = novo;
	return Lista;
}

ncde *buscaNo (ncde *Lista, int chave){
	ncde *aux = Lista;
	if (aux){
		do{
			if (aux->chave == chave) return aux;
			aux = aux->prox;
		}while (aux != Lista);
	}
	return NULL;
}

void imprimeNo (ncde *no){
	ncde *aux = no;
	printf ("%d ", aux->chave);
}

void imprimeLista (ncde *Lista){
	ncde *aux = Lista;
	if (aux){
		do{
			printf ("%d ", aux->chave);
			aux = aux->prox;
		}while (aux != Lista);
		printf ("\n");
	}
}

ncde *removeNo (ncde *Lista, int chave){
	ncde *aux = Lista;
	if (aux){
		do{
			if (aux->chave != chave){
				aux = aux->prox;
			}
		}while (aux != Lista && aux->chave != chave);
		if (aux->chave == chave){
			if (aux == Lista){
				Lista = aux->prox;
				aux->prox->ant = aux->ant;
			}
			else{
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
			}
			free (aux);
		}
	}
	return Lista;
}

ncde *desalocaLista (ncde *Lista){
	ncde *aux = Lista;
	while (aux){
		Lista = aux->prox;
		free (aux);
		aux = Lista;
	}
	return NULL;
}
