/* 
 * File:   main.c
 * Author: fabriciosilva
 *
 * Created on November 24, 2021, 12:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"
#include "eleitor.h"

#define FLAG_TESTE 0

int main() {
    int nCandidatos;
    int nEleitores;
    
    //armazena a lista de candidatos
    candidato* listaCandidatos;

    //armazena os eleitores (alunos, professores, etc)
    eleitor* listaEleitores;
    
    if(FLAG_TESTE){
        nCandidatos = 3;
        nEleitores = 5;
    }else{
        printf("Digite a quantidade de candidatos: ");
        scanf("%d",&nCandidatos);
        printf("Digite a quantidade de eleitores: ");
        scanf("%d",&nEleitores);        
    }
            
    listaCandidatos = malloc(nCandidatos * sizeof(candidato));
        
    int nVotosNulos = 0;
        
    //Lê os os candidatos
    for(int i=0; i<nCandidatos; i++){
        listaCandidatos[i].votos = 0;
        if(FLAG_TESTE){
            listaCandidatos[i].numero = (i+1);
            char snum[5];
            sprintf(snum, "%d", (i+1));
            strcpy(listaCandidatos[i].nome,snum);
        }else{
            printf("Digite o número do candidato: %d\n",(i+1));
            scanf("%d",&listaCandidatos[i].numero);
            
            printf("Digite o nome do candidado: %d\n",(i+1));
            //scanf("%s",nomesCandidatos[i);
            fflush(stdin);            
            gets(listaCandidatos[i].nome);
            
            printf("Digite o dia do nascimento do candidato %d\n",(i+1));
            scanf("%d",&listaCandidatos[i].dataNascimento.dia);
            
            printf("Digite o mês do nascimento do candidato %d\n",(i+1));
            scanf("%d",&listaCandidatos[i].dataNascimento.mes);

            printf("Digite o ano do nascimento do candidato %d\n",(i+1));
            scanf("%d",&listaCandidatos[i].dataNascimento.ano);
            
            
        }
    }
    
    printf("Digite:\n");
    for(int i=0; i<nCandidatos; i++){                        
        printf("%d para votar no candidato %s\n",
                listaCandidatos[i].numero,
                listaCandidatos[i].nome);
    }
    printf("*************************\n\n");
    
    listaEleitores = malloc(nEleitores * sizeof(eleitor));
    //Lê as matrículas dos eleitores
    for(int i=0; i<nEleitores; i++){
        if(FLAG_TESTE){
            listaEleitores[i].matricula = (i+1);
            char snum[5];
            sprintf(snum, "%d", (i+1));
            strcpy(listaEleitores[i].departamento,snum);
            
        }else{
            printf("Digite a matrícula do eleitor %d\n",(i+1));
            scanf("%d",&listaEleitores[i].matricula);
            
            printf("Digite o departamento do eleitor: %d\n",(i+1));
            fflush(stdin);            
            gets(listaEleitores[i].departamento);            
        }
    }
   
    
    int voto;
    
    for(int i=0; i<nEleitores; i++){
        printf("Digite o voto do eleitor com matricula %d"
                " do %s\n",
                listaEleitores[i].matricula,
                listaEleitores[i].departamento);
        scanf("%d",&voto);
        
        int nulo = 1;
        for(int j=0; j<nCandidatos; j++){            
            if(listaCandidatos[j].numero == voto){
                listaCandidatos[j].votos++;
                nulo = 0;
                break;
            }
        }
        if(nulo == 1){
            nVotosNulos++;
        }        
    }
    
    
    for(int i=0; i<nCandidatos; i++){
        printf("O Candidato %s (%d) teve %d votos\n",
                listaCandidatos[i].nome,
                listaCandidatos[i].numero,
                listaCandidatos[i].votos);
    }
    
    printf("Votos nulos: %d\n",nVotosNulos);
    

    int indiceVencedor = 0;
    int empate = 0;
    
    for(int i=1; i<nCandidatos; i++){
        if(listaCandidatos[i].votos > 
                    listaCandidatos[indiceVencedor].votos){
            indiceVencedor = i;
            empate = 0;
        }else if(listaCandidatos[i].votos == 
                                listaCandidatos[indiceVencedor].votos){
            empate = 1;
        }
    }
    
    
    if(empate == 0){
        printf("O vencedor é o candidato %s (%d) com %d votos\n",
                listaCandidatos[indiceVencedor].nome,
                listaCandidatos[indiceVencedor].numero,
                listaCandidatos[indiceVencedor].votos);
        
        printf("A data de nascimento do vencedor é: %d/%d/%d\n",
                listaCandidatos[indiceVencedor].dataNascimento.dia,
                listaCandidatos[indiceVencedor].dataNascimento.mes,
                listaCandidatos[indiceVencedor].dataNascimento.ano);
        
    }else{
        printf("Empate! O que fazer??\n");
    }
    
        
    return (EXIT_SUCCESS);
}

