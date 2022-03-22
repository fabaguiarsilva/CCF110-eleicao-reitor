/* 
 * File:   main.c
 * Author: fabriciosilva
 *
 * Created on November 24, 2021, 12:13 PM
 */

#include "eleicao.h"

int main() {
    
    //ler_candidatos();
    ler_candidatos_arquivo();
    
    ler_eleitores();
               
    listar_candidatos();
    
    iniciar_votacao();
        
    //imprimir_votos();
    salvar_votos_arquivo();
    
    apurar_eleicao();
        
    return (EXIT_SUCCESS);
}

