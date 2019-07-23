#include "lse.h"
#include <stdio.h>
#include <stdlib.h>
	
nse *novoNo (int chave){
	nse *novo = (nse *) malloc (sizeof (nse));
	if (!novo){
		printf ("Erro.\n");
		return NULL;
	}
	novo->chave = chave;
	novo->prox = NULL;
	return novo;
}
	
nse *insereInicio (nse *Lista, nse *novo){
	novo->prox = Lista;
	return novo;
}

nse *insereFim (nse *Lista, nse *novo){
	nse *aux = Lista;	
	if (!aux) return novo;
	while (aux->prox) aux = aux->prox;
	aux->prox = novo;
	return Lista;
}

nse *insereOrd (nse *Lista, nse *novo){
	nse *aux = Lista;
	nse *ant = NULL;
	while (aux != NULL && aux->chave < novo->chave){
		ant =  aux;
		aux = aux->prox;
	}
	novo->prox=aux;
	if (!ant) Lista = novo;
	else ant->prox = novo;
	return Lista;
}

nse *buscaNo (nse *Lista, int chave){
	nse *aux = Lista;
	while (aux != NULL && aux->chave != chave) aux = aux->prox;
	if (aux) return aux;
	return NULL;
}

void imprimeNo (nse *no){
	nse *aux = no;
	printf ("%d ", aux->chave);
}

void imprimeLista (nse *Lista){
	nse *aux = Lista;
	while (aux){
		printf ("%d ", aux->chave);
		aux = aux->prox;

	}
	printf ("\n");
}

nse *removeNo (nse *Lista, int chave){
	nse *aux = Lista;
	nse *ant = NULL;
	while (aux != NULL && aux->chave != chave){
		ant = aux;
		aux = aux->prox;
	}
	if (aux){
		if (ant) ant->prox = aux->prox;
		else Lista = aux->prox;
		free (aux);
	}
	return Lista;
}

nse *desalocaLista (nse *Lista){
	nse *aux = Lista;
	while (aux){
		Lista = aux->prox;
		free (aux);
		aux = Lista;
	}
	return NULL;
}
