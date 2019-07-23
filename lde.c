#include "lde.h"
#include <stdio.h>
#include <stdlib.h>

nde *novoNo (int chave){
	nde *novo = (nde *) malloc (sizeof (nde));
	if (!novo){
		printf("Erro.\n");
		return NULL;
	}	
	novo->chave = chave;
	novo->prox = NULL;
	novo->ant = NULL;	
	return novo;
}

nde *insereInicio (nde *Lista, nde *novo){
	if (!Lista) return novo;
	novo->prox = Lista;
	Lista->ant = novo;
	return novo;
}

nde *insereFim (nde *Lista, nde *novo){
	if (!Lista) return novo;
	nde *aux = Lista;
	while (aux->prox) aux = aux->prox;
	aux->prox = novo;
	novo->ant = aux;
	return Lista;
}

nde *insereOrd (nde *Lista, nde *novo){
	if (!Lista) return novo;
	nde *aux = Lista;
	while (aux->prox != NULL  && aux->chave < novo->chave) aux = aux->prox;
	if (aux->chave < novo->chave){
		novo->ant = aux;
		aux->prox = novo;
		return Lista;	
	}
	if (!aux->ant){
		novo->prox = aux;
		aux->ant = novo;
		return novo; 
	}
	novo->ant = aux->ant;
	novo->prox = aux;
	aux->ant = novo;
	novo->ant->prox = novo;
	return Lista;	
}

nde *buscaNo (nde *Lista, int chave){
	nde *aux = Lista;
	while (aux != NULL && aux->chave != chave) aux = aux->prox;
	if (aux) return aux;
	return NULL;
}

void imprimeNo (nde *no){
	nde *aux = no;
	printf ("%d ", aux->chave);
}

void imprimeLista (nde *Lista){
	nde *aux = Lista;
	while (aux){
		printf ("%d ", aux->chave);
		aux = aux->prox;	
	}
	printf ("\n");	
}

nde *removeNo (nde *Lista, int chave){
	nde *aux = buscaNo (Lista,chave);
	if (aux){
		if (aux->ant) aux->ant->prox = aux->prox;
		else Lista = aux->prox;
		if (aux->prox) aux->prox->ant = aux->ant;
		free(aux);
	}
	return Lista;
}

nde *desalocaLista (nde *Lista){
	nde *aux = Lista;
	while (aux){
		Lista = aux->prox;
		free(aux);
		aux=Lista;
	}
	return NULL;
}
