#ifndef LSE_H
#define LSE_H

typedef struct nse{
	int chave;
	struct nse *prox;
}nse;


nse *novoNo (int chave);

nse *insereInicio (nse *Lista, nse *novo);

nse *insereFim (nse *Lista, nse *novo);

nse *insereOrd (nse *Lista, nse *novo);

nse *buscaNo (nse *Lista, int chave);

void imprimeNo (nse *no);

void imprimeLista (nse *Lista);

nse *removeNo (nse *Lista, int chave);

nse *desalocaLista (nse *Lista);

#endif 
