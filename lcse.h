#ifndef LCSE_H
#define LCSE_H

typedef struct ncse{   
	int chave;         
	struct ncse *prox; 
}ncse;

ncse *novoNo (int chave);

ncse *insereInicio (ncse *Lista, ncse *novo);

ncse *insereFim (ncse *Lista, ncse *novo);

ncse *insereOrd (ncse *Lista, ncse *novo);

ncse *buscaNo (ncse *Lista, int chave);

void imprimeNo (ncse *no);

void imprimeLista (ncse *Lista);

ncse *removeNo (ncse *Lista, int chave);

ncse *desalocaLista (ncse *Lista);

#endif
