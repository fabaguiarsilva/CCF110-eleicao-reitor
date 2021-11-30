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
    
    printf("Qual o voto do eleitor 2?\n");
    scanf("%d",&votoEleitor2);
    
    printf("Qual o voto do eleitor 3?\n");
    scanf("%d",&votoEleitor3);
    
    printf("Qual o voto do eleitor 4?\n");
    scanf("%d",&votoEleitor4);
    
    printf("Qual o voto do eleitor 5?\n");
    scanf("%d",&votoEleitor5);
    
    printf("O eleitor 1 votou em: %d\n",votoEleitor1);
    printf("O eleitor 2 votou em: %d\n",votoEleitor2);
    printf("O eleitor 3 votou em: %d\n",votoEleitor3);
    printf("O eleitor 4 votou em: %d\n",votoEleitor4);
    printf("O eleitor 5 votou em: %d\n",votoEleitor5);
    
    
    printf("\n\nFavor calcular o resultado manualmente!");
    
    return (EXIT_SUCCESS);
}

