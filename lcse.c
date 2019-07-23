#include "lcse.h"
#include <stdio.h>
#include <stdlib.h>

ncse *novoNo (int chave){
	ncse *novo = (ncse *) malloc (sizeof (ncse));
	if (!novo){
		printf ("Erro.\n");
		return NULL;
	}
	novo->chave = chave;
	novo->prox = novo;
	return novo;
}

ncse *insereInicio (ncse *Lista, ncse *novo){
	ncse *aux = Lista;
	if (!Lista){
		novo->prox = novo;
		return novo;	
	}
	while (aux->prox != Lista) aux = aux->prox;
	novo->prox = Lista;	
	aux->prox = novo;
	return novo;
}

ncse *insereFim (ncse *Lista, ncse *novo){
	ncse *aux = Lista;
	if (!Lista){
		novo->prox = novo;
		return novo;
	}
	while (aux->prox != Lista) aux = aux->prox;
	novo->prox = Lista;
	aux->prox = novo;
	return Lista;
}

ncse *insereOrd (ncse *Lista, ncse *novo){
	ncse *aux = Lista;
	ncse *ant = NULL;
	if (!Lista){
		novo->prox = novo;
		return novo;
	}
	do{
		if (aux->chave < novo->chave){
			ant = aux;
			aux = aux->prox;
		}
	}while (aux != Lista && aux->chave < novo->chave);
	novo->prox = aux; 
	if (!ant) Lista = novo;
	ant->prox = novo;
	return Lista;
}

ncse *buscaNo (ncse *Lista, int chave){
	ncse *aux = Lista;
	if (aux){
		do{
			if (aux->chave == chave) return aux;
			aux = aux->prox;
		}while (aux != Lista);
	}
	return NULL;
}

void imprimeNo (ncse *no){
	ncse *aux = no;
	printf ("%d ", aux->chave);
}

void imprimeLista (ncse *Lista){
	ncse *aux = Lista;
	if (aux){
		do{
			printf ("%d ", aux->chave);
			aux = aux->prox;
		}while (aux != Lista);
		printf ("\n");
	}
}

ncse *removeNo (ncse *Lista, int chave){
	ncse *aux = Lista;
	ncse *ant = NULL;
	if (aux){
		do{
			if (aux->chave != chave){
				ant = aux;
				aux = aux->prox;
			}
		}while (aux != Lista && aux->chave != chave);
		if (ant->prox != Lista){
			if (ant) ant->prox = aux->prox;
			else Lista = aux->prox;
			free (aux);
		}
	}
	return Lista;
}

ncse *desalocaLista (ncse *Lista){
	ncse *aux = Lista;
	while (aux){
		Lista = aux->prox;
		free (aux);
		aux = Lista;
	}
	return NULL;
}
