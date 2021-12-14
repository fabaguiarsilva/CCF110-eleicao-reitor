/* 
 * File:   main.c
 * Author: fabriciosilva
 *
 * Created on November 24, 2021, 12:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAG_TESTE 0

int main() {
    /*
     * Inicialmente, apenas 3 candidatos a reitor
     * e 5 eleitores
     */
    int nCandidatos = 3;
    int nEleitores = 5;
    
    char nomeCandidato1[30];
    char nomeCandidato2[30];
    char nomeCandidato3[30];    
    
    
    int numerosCandidatos[nCandidatos];
    
    int votosCandidatos[nCandidatos];
    for(int i=0; i<nCandidatos; i++){
        votosCandidatos[i] = 0;
    }
    
    int nVotosNulos = 0;
    
    //armazena as matrítulas dos eleitores (alunos, professores, etc)
    int matriculasEleitores[nEleitores];
    
    //Lê os números dos candidatos
    for(int i=0; i<nCandidatos; i++){
        if(FLAG_TESTE){
            numerosCandidatos[i] = (i+1);
        }else{
            printf("Digite o número do candidato: %d\n",(i+1));
            scanf("%d",&numerosCandidatos[i]);
            
            //ATENCAO: só funciona pois tenho certeza que
            //nCandidatos == 3
            printf("Digite o nome do candidado: %d\n",(i+1));
            if(i == 0){
                //scanf("%s",nomeCandidato1);
                fflush(stdin);
                gets(nomeCandidato1);
            }else if(i == 1){
                //scanf("%s",nomeCandidato2);
                //getchar();
                fflush(stdin);
                gets(nomeCandidato2);
            }else if(i == 2){
                //scanf("%s",nomeCandidato3);
                //getchar();
                fflush(stdin);
                gets(nomeCandidato3);
            }            
        }
    }
    
    printf("Digite:\n");
    for(int i=0; i<nCandidatos; i++){
        char nome[30];
        if(i == 0){
            strcpy(nome, nomeCandidato1);
        }else if(i == 1){
            strcpy(nome, nomeCandidato2);
        }else if(i == 2){
            strcpy(nome, nomeCandidato3);
        }
                
        printf("%d para votar no candidato %s\n",
                numerosCandidatos[i],nome);
    }
    printf("*************************\n\n");
    
    
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
        printf("O Candidato %d teve %d votos\n",
                numerosCandidatos[i],votosCandidatos[i]);
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
        printf("O vencedor é o candidato %d com %d votos\n",
                numerosCandidatos[indiceVencedor],
                votosCandidatos[indiceVencedor]);
    }else{
        printf("Empate! O que fazer??\n");
    }
    
        
    return (EXIT_SUCCESS);
}

