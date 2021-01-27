#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct pilha{
  	float A[MAX];
  	int topo;
}Pilha;
  
Pilha* init(Pilha *p){
  	p -> topo = 1;
  	return p;
}
  
void push(Pilha *p, float i){
  	if(p -> topo == MAX-1){
  		exit(1);
	}else{
	    p -> topo++;
	    p -> A[p -> topo] = i;
    }
}
  
float pop(Pilha *p){
  	float n;
  	if(p->topo == -1){
  		exit(1);
	  }
	    else{
	    n = p -> A[p -> topo];
	    p -> topo--;
	    return n;
	}	
}

int main(){
	float A[MAX];
	int tam, i; 
  	float aux1, aux2, result, num, fresult, n;
  	char conta[70];
  	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
  	init(p);
  	scanf("%s", &conta);
  	tam = strlen(conta);
  	for(i=0; i<tam; i++){
  		switch (conta[i]){
  			case '+':
  				aux1 = pop(p);
  				aux2 = pop(p);
  				result = aux2 + aux1;
  				push(p, result);
  				break;
  			case '-':
  				aux1 = pop(p);
  				aux2 = pop(p);
  				result = aux2 - aux1;
  				push(p, result);
  				break;
  			case '*':
  				aux1 = pop(p);
  				aux2 = pop(p);
  				result = aux2 * aux1;
  				push(p, result);
  				break;
  			case '/':
  				aux1 = pop(p);
  				aux2 = pop(p);
  				result = aux2 / aux1;
  				push(p, result);
  				break;
  			default :
  				scanf("%f", &num);
  				push(p, num);
  				break;
		}
	}
	fresult = pop(p);
	printf("%f", fresult);
	return 0;
}
