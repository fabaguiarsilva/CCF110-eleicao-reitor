/* 
 * File:   main.c
 * Author: fabriciosilva
 *
 * Created on November 24, 2021, 12:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAG_TESTE 1

int main() {
    int nCandidatos;
    int nEleitores;
    
    //armazena o número de cada candidato
    int* numerosCandidatos;
    
    //armazena os votos de cada candidato, com
    //um mapeamento 1 para 1 do índice do vetor
    //numerosCandidatos
    int *votosCandidatos;

    //armazena as matrítulas dos eleitores (alunos, professores, etc)
    int* matriculasEleitores;

    
    
    if(FLAG_TESTE){
        nCandidatos = 3;
        nEleitores = 5;
    }else{
        printf("Digite a quantidade de candidatos: ");
        scanf("%d",&nCandidatos);
        printf("Digite a quantidade de eleitores: ");
        scanf("%d",&nEleitores);        
    }
        
    //armazena o nome de cada candidato, um por linha
    char nomesCandidatos[nCandidatos][30];    
    
    numerosCandidatos = malloc(nCandidatos * sizeof(int));
    
    
    votosCandidatos = malloc(nCandidatos * sizeof(int));
    for(int i=0; i<nCandidatos; i++){
        votosCandidatos[i] = 0;
    }
    
    int nVotosNulos = 0;
        
    //Lê os números dos candidatos
    for(int i=0; i<nCandidatos; i++){
        if(FLAG_TESTE){
            numerosCandidatos[i] = (i+1);
            char snum[5];
            sprintf(snum, "%d", (i+1));
            strcpy(nomesCandidatos[i],snum);
        }else{
            printf("Digite o número do candidato: %d\n",(i+1));
            scanf("%d",&numerosCandidatos[i]);
            
            printf("Digite o nome do candidado: %d\n",(i+1));
            //scanf("%s",nomesCandidatos[i);
            fflush(stdin);            
            gets(nomesCandidatos[i]);
        }
    }
    
    printf("Digite:\n");
    for(int i=0; i<nCandidatos; i++){                        
        printf("%d para votar no candidato %s\n",
                numerosCandidatos[i],nomesCandidatos[i]);
    }
    printf("*************************\n\n");
    
    matriculasEleitores = malloc(nEleitores * sizeof(int));
    //Lê as matrículas dos eleitores
    for(int i=0; i<nEleitores; i++){
        if(FLAG_TESTE){
            matriculasEleitores[i] = (i+1);
        }else{
            printf("Digite a matrícula do eleitor %d\n",(i+1));
            scanf("%d",&matriculasEleitores[i]);
        }
    }
   
    
    int voto;
    
    for(int i=0; i<nEleitores; i++){
        printf("Digite o voto do eleitor com matricula %d\n",
                matriculasEleitores[i]);
        scanf("%d",&voto);
        
        int nulo = 1;
        for(int j=0; j<nCandidatos; j++){            
            if(numerosCandidatos[j] == voto){
                votosCandidatos[j]++;
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
                nomesCandidatos[i],
                numerosCandidatos[i],
                votosCandidatos[i]);
    }
    
    printf("Votos nulos: %d\n",nVotosNulos);
    

    int indiceVencedor = 0;
    int empate = 0;
    
    for(int i=1; i<nCandidatos; i++){
        if(votosCandidatos[i] > votosCandidatos[indiceVencedor]){
            indiceVencedor = i;
            empate = 0;
        }else if(votosCandidatos[i] == 
                                votosCandidatos[indiceVencedor]){
            empate = 1;
        }
    }
    
    
    if(empate == 0){
        printf("O vencedor é o candidato %s (%d) com %d votos\n",
                nomesCandidatos[indiceVencedor],
                numerosCandidatos[indiceVencedor],
                votosCandidatos[indiceVencedor]);
    }else{
        printf("Empate! O que fazer??\n");
    }
    
        
    return (EXIT_SUCCESS);
}

