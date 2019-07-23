#ifndef LCDE_H
#define LCDE_H

typedef struct ncde{
	int chave;
	struct ncde *ant, *prox;
}ncde;

ncde *novoNo (int chave);

ncde *insereInicio (ncde *Lista, ncde *novo);

ncde *insereFim (ncde *Lista, ncde *novo);

ncde *insereOrd (ncde *Lista, ncde *novo);

ncde *buscaNo (ncde *Lista, int chave);

void imprimeNo (ncde *no);

void imprimeLista (ncde *Lista);

ncde *removeNo (ncde *Lista, int chave);

ncde *desalocaLista (ncde *Lista);

#endif
