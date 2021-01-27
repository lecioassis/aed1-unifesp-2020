#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

typedef struct{
    int finicial;   //forca inicial
    int ffinal;     //forca final
    int indice;     //indice do jogador
}tipoitem;

typedef struct struccel *apontador;

typedef struct struccel{
    tipoitem item;
    apontador prox;
} tipocelula;

typedef struct {
    apontador inicio, fim;
    int tam;
} tipofila;

//inicializa a fila
void Inicia(tipofila *f){   
    f->inicio = NULL;
    f->fim = f->inicio;
    f->tam == 0;
}

//retorna tamanho da fila
int tamanho(tipofila *f){
    return (f->tam);
}

//checa se a fila esta vazia
int vazia(tipofila *f){
    if(f->inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

//insere novo item na fila
int inserir(tipofila *f, tipoitem x){   
    apontador pNovo;
    pNovo = (apontador) malloc(sizeof(tipocelula));
    pNovo->item = x;
    pNovo->prox = NULL;
    if(vazia(f)){
        f->inicio = pNovo;
    }else{
        f->fim->prox = pNovo;
    }
    f->fim = pNovo;
    f->tam++;
    return 1;
}

//retira primeiro item da fila, retorna o item
tipoitem retirar(tipofila *f){ 
    apontador paux;
    tipoitem x;
    if(vazia(f)){
        exit(1);
    }
    paux = f->inicio;
    f->inicio = paux->prox;
    x = paux->item;
    free(paux);
    f->tam--;
    return x;  
}

//recupera k forca do jogador
int recuperar(tipoitem vround,int K){   
    if(vround.finicial >= (vround.ffinal + K)){
        return (vround.ffinal+K);
    }else{
        return (vround.finicial);
    }
}

//descobre o vencedor, faz o calculo da sua forca resultante apos o descanso, retorna vencedor tipoitem
tipoitem lutar(tipofila *f, int K){     
    tipoitem aux1, aux2, vround;
    aux1 = retirar(f);
    aux2 = retirar(f);
    if(aux1.ffinal > aux2.ffinal){
        vround = aux1;
        vround.ffinal = aux1.ffinal - aux2.ffinal;
    }else if(aux1.ffinal < aux2.ffinal){
        vround = aux2;
        vround.ffinal = aux2.ffinal - aux1.ffinal;
    }else if(aux1.ffinal == aux2.ffinal){
        if(aux1.indice < aux2.indice){
            vround = aux1;
            vround.ffinal = 0;
        }else{
            vround = aux2;
            vround.ffinal = 0;
        }    
    }
    vround.ffinal = recuperar(vround, K);
    inserir(f, vround);
    return vround;
}

int main(){
    //declaracao de variaveis, scanf de N, inicializacao da fila
    int N, K, i, aux;
    scanf("%i %i", &N, &K);
    int participantes = pow(2, N);
    tipofila torneio;
    tipoitem iaux, vround, vtorneio;
    Inicia(&torneio);
    //scanf da forca dos participantes
    for(i = 1; i <= participantes; i++){
        scanf("%i", &aux);
        iaux.finicial = iaux.ffinal = aux;
        iaux.indice = i;
        inserir(&torneio, iaux);
    }
    //execucao do torneio
    for(i = 1; i < participantes; i++){
        vtorneio = lutar(&torneio, K);
    }
    //printf do indice do vencedor
    printf("%i", vtorneio.indice);
    return 0;
}
