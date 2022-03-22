
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"
#include "eleitor.h"


#ifndef ELEICAO_H
#define ELEICAO_H

#ifndef FLAG_TESTE
#define FLAG_TESTE 0
#endif

int nCandidatos;

int nVotosNulos;

//armazena a lista de candidatos
candidato* listaCandidatos;

int nEleitores;
    
//armazena os eleitores (alunos, professores, etc)
eleitor* listaEleitores;

void ler_quantidade_candidatos();

candidato ler_candidato(int count);

void ler_candidatos();

void ler_candidatos_arquivo();

candidato ler_candidato_linha(char linha[]);

void ler_quantidade_eleitores();

eleitor ler_eleitor(int count);

void ler_eleitores();

void listar_candidatos();

int ler_voto_eleitor(int count);

int verifica_candidato(int voto);

void iniciar_votacao();

void imprimir_votos();

void salvar_votos_arquivo();

void apurar_eleicao();


#endif /* ELEICAO_H */