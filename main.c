/* 
 * File:   main.c
 * Author: fabriciosilva
 *
 * Created on November 24, 2021, 12:13 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    /*
     * Inicialmente, apenas 3 candidatos a reitor
     */
    int nVotosCandidato1 = 0;
    int nVotosCandidato2 = 0;
    int nVotosCandidato3 = 0;
    
    /*
     * Inicialmente, apenas 5 eleitores
     */
    int votoEleitor1,votoEleitor2,votoEleitor3,
            votoEleitor4,votoEleitor5;
    
    printf("Digite:\n");
    printf("1 - para votar no candidato 1\n");
    printf("2 - para votar no candidato 2\n");
    printf("3 - para votar no candidato 3\n");
    printf("*************************\n\n");
    
    printf("Qual o voto do eleitor 1?\n");
    scanf("%d",&votoEleitor1);
    if(votoEleitor1 == 1){
        nVotosCandidato1 += 1;
    }else if(votoEleitor1 == 2){
        nVotosCandidato2 += 1;
    }else if(votoEleitor1 == 3){
        nVotosCandidato3 += 1;
    }    
    
    printf("Qual o voto do eleitor 2?\n");
    scanf("%d",&votoEleitor2);
    switch(votoEleitor2){
        case 1:
            nVotosCandidato1 +=1;
            break;
        case 2:
            nVotosCandidato2 +=1;
            break;
        case 3:
            nVotosCandidato3 +=1;
            break;
        default:
            printf("Voto errado!\n");
    }
    
    
    printf("Qual o voto do eleitor 3?\n");
    scanf("%d",&votoEleitor3);
    switch(votoEleitor3){
        case 1:
            nVotosCandidato1 +=1;
            break;
        case 2:
            nVotosCandidato2 +=1;
            break;
        case 3:
            nVotosCandidato3 +=1;
            break;
        default:
            printf("Voto errado!\n");
    }

    
    
    printf("Qual o voto do eleitor 4?\n");
    scanf("%d",&votoEleitor4);
    switch(votoEleitor4){
        case 1:
            nVotosCandidato1 +=1;
            break;
        case 2:
            nVotosCandidato2 +=1;
            break;
        case 3:
            nVotosCandidato3 +=1;
            break;
        default:
            printf("Voto errado!\n");
    }

    
    
    printf("Qual o voto do eleitor 5?\n");
    scanf("%d",&votoEleitor5);
    switch(votoEleitor5){
        case 1:
            nVotosCandidato1 +=1;
            break;
        case 2:
            nVotosCandidato2 +=1;
            break;
        case 3:
            nVotosCandidato3 +=1;
            break;
        default:
            printf("Voto errado!\n");
    }

    printf("Votos Candidato 1: %d\n",nVotosCandidato1);
    printf("Votos Candidato 2: %d\n",nVotosCandidato2);
    printf("Votos Candidato 3: %d\n",nVotosCandidato3);
    
    //Assume inicialmente que Candidato 1 é o vencedor
    int candidatoVencedor = 1;
    int nVotosVencedor = nVotosCandidato1;
    int houveEmpate = 0;
        
    //Verifica se 2 é melhor que o vencedor atual
    if(nVotosCandidato2 > nVotosVencedor){
        candidatoVencedor = 2;
        nVotosVencedor = nVotosCandidato2;
        houveEmpate = 0;
    }else if(nVotosCandidato2 == nVotosVencedor){
        houveEmpate = 1;
    }
    
    //Verifica se 3 é melhor que o vencedor atual
    if(nVotosCandidato3 > nVotosVencedor){
        candidatoVencedor = 3;
        nVotosVencedor = nVotosCandidato3;
        houveEmpate = 0;
    }else if(nVotosCandidato3 == nVotosVencedor){
        houveEmpate = 1;
    }
    
    if(houveEmpate == 0){
        printf("O vencedor é o candidato %d\n",candidatoVencedor);
    }else{
        printf("Empate! O que fazer??\n");
    }
    
        
    return (EXIT_SUCCESS);
}

