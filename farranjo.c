#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100000

typedef struct {
    int finicial;   //forca inicial 
    int ffinal;     //forca final
    int indice;     //indice do jogador
} tipoitem;

typedef int TApontador;

typedef struct {
    tipoitem item[MAX];
    TApontador inicio, fim;
} tipofila;

void Inicia(tipofila *f){
    f->inicio = 0;
    f->fim = 0;
}

//inicializa a fila
int fvazia(tipofila *f){
    if(f->inicio == f->fim){
        return 0;
    }else{
        return 1;
    }
}

//insere novo item no final da fila
int inserir(tipofila *f, tipoitem x){
    if(f->inicio == (f->fim + 1)){
        return 0;
    }else{
    f->item[f->fim] = x;
    f->fim = (f->fim + 1);
    return 1;
    }
}

//retira ultimo item da fila, retorna o item
tipoitem retirar(tipofila *f){
    if(f->inicio == f->fim){
        exit(1);
    }else{
    tipoitem x = f->item[f->inicio];
    f->inicio = (f->inicio + 1);
    return x;
    }
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
