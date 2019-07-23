#ifndef LDE_H
#define LDE_H

typedef struct nde{
	int chave;
	struct nde *ant, *prox;
}nde;

nde *novoNo (int chave);

nde *insereInicio (nde *Lista, nde *novo);

nde *insereFim (nde *Lista, nde *novo);

nde *insereOrd (nde *Lista, nde *novo);

nde *buscaNo (nde *Lista, int chave);

void imprimeNo (nde *no);

void imprimeLista (nde *Lista);

nde *removeNo (nde *Lista, int chave);

nde *desalocaLista (nde *Lista);

#endif
