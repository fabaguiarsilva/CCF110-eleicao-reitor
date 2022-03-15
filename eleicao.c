#include "eleicao.h"

void ler_quantidade_candidatos(){
    if(FLAG_TESTE){
        nCandidatos = 3;
    }else{
        printf("Digite a quantidade de candidatos: ");
        scanf("%d",&nCandidatos);
    }    
}

candidato ler_candidato(int count){
    candidato novoCandidato;
    novoCandidato.votos = 0;
    if(FLAG_TESTE){
        novoCandidato.numero = (count+1);
        char snum[5];
        sprintf(snum, "%d", (count+1));
        strcpy(novoCandidato.nome,snum);
    }else{
        printf("Digite o número do candidato: %d\n",(count+1));
        scanf("%d",&novoCandidato.numero);
            
        printf("Digite o nome do candidado: %d\n",(count+1));
        //scanf("%s",nomesCandidatos[i);
        fflush(stdin);            
        gets(novoCandidato.nome);                        
    }
    return novoCandidato;       
}

void ler_candidatos(){
    
    ler_quantidade_candidatos();
    
    listaCandidatos = malloc(nCandidatos * sizeof(candidato));
    
    //Lê os os candidatos
    for(int i=0; i<nCandidatos; i++){
        listaCandidatos[i] = ler_candidato(i);        
    }    
}


void ler_quantidade_eleitores(){
    if(FLAG_TESTE){
        nEleitores = 5;
    }else{
        printf("Digite a quantidade de eleitores: ");
        scanf("%d",&nEleitores);        
    }    
}

eleitor ler_eleitor(int count){
    eleitor novoEleitor;
    if(FLAG_TESTE){
        novoEleitor.matricula = (count+1);
        char snum[5];
        sprintf(snum, "%d", (count+1));
        strcpy(novoEleitor.departamento,snum);
    }else{
        printf("Digite a matrícula do eleitor %d\n",(count+1));
        scanf("%d",&novoEleitor.matricula);           
        printf("Digite o departamento do eleitor: %d\n",(count+1));
        fflush(stdin);            
        gets(novoEleitor.departamento);            
    }
    return novoEleitor;    
}

void ler_eleitores(){
    
    ler_quantidade_eleitores();
    
    listaEleitores = malloc(nEleitores * sizeof(eleitor));
    //Lê as matrículas dos eleitores
    for(int i=0; i<nEleitores; i++){
        listaEleitores[i] = ler_eleitor(i);
    }    
}

void listar_candidatos(){
    printf("Digite:\n");
    for(int i=0; i<nCandidatos; i++){                        
        printf("%d para votar no candidato %s\n",
                listaCandidatos[i].numero,
                listaCandidatos[i].nome);
    }
    printf("*************************\n\n");
}

int ler_voto_eleitor(int count){
    int v;
    printf("Digite o voto do eleitor com matricula %d"
            " do %s\n",
            listaEleitores[count].matricula,
            listaEleitores[count].departamento);
    scanf("%d",&v);
    return v;
}

int verifica_candidato(int voto){
    for(int j=0; j<nCandidatos; j++){            
        if(listaCandidatos[j].numero == voto){
            listaCandidatos[j].votos++;
            return 1;//achei o candidato
        }
    }
    return -1;//não achei
}

void iniciar_votacao(){
    nVotosNulos=0;
    int voto;
    
    for(int i=0; i<nEleitores; i++){
        voto = ler_voto_eleitor(i);
        
        if(verifica_candidato(voto) == -1){        
            nVotosNulos++;
        }        
    }
}

void imprimir_votos(){
    for(int i=0; i<nCandidatos; i++){
        printf("O Candidato %s (%d) teve %d votos\n",
                listaCandidatos[i].nome,
                listaCandidatos[i].numero,
                listaCandidatos[i].votos);
    }
    
    printf("Votos nulos: %d\n",nVotosNulos);
}

void apurar_eleicao(){
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
    }else{
        printf("Empate! O que fazer??\n");
    }  
}


