#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Pilha{
	int topo;
	double *elemento;
};

// Cria pilha alocando memoria com capacidade para receber c elementos
void criar_pilha(struct Pilha *p, int c){
	p->topo = -1;
	p->elemento = (double*)malloc(c*sizeof(double));
}

// Verifica o caractere recebido
int verifica_valor(char carac){
	if(carac != ' ' && carac != '+' && carac != '-' && carac != '*' && carac != '/'){
		return 1;
	}
	else{
		return 0;
	}
}

// Pega o elemento do topo da pilha
double desempilhar(struct Pilha *p){
	double aux = p->elemento[p->topo];
	p->topo--;
	return aux;
}

// Empilha novo elemento
void empilhar(struct Pilha *p, double v){
	p->topo++;
	p->elemento[p->topo] = v;
}

// Retorna ultimo elemento --> Apenas para debug 
double ultimo(struct Pilha *p){
	return p->elemento[p->topo];
}

int main(){

	struct Pilha minha_pilha;
	double valor, num1, num2;
	int capacidade = 400;
	
	criar_pilha(&minha_pilha,capacidade);
	
	int tamanho = 10;
	int i = 0;
	char caractere;
	
	caractere = fgetc(stdin);
	
	while(caractere != EOF){
		if(caractere == ' ' || caractere == '\n'){
			caractere = fgetc(stdin);
		}
		else if(caractere == '+' || caractere == '-' || caractere == '*' || caractere == '/'){
			num1 = desempilhar(&minha_pilha);
			num2 = desempilhar(&minha_pilha);
			switch(caractere){
				case '+':
					valor = num1 + num2;
					break;
				case '-':
					valor = num2 - num1;
					break;
				case '*':
					valor = num1*num2;
					break;
				case '/':
					valor = (double)num2/num1;
					break;
			}
			empilhar(&minha_pilha,(double)valor);
			//printf("Valores %f e %f desempilhados\n",num1,num2);
			//printf("Valor novo da operacao entre %f %c %f = %f\n", num1,caractere,num2,valor);
			caractere = fgetc(stdin);
		}
		else{
			i = 0;
			char *v = (char *)malloc(sizeof(char)*tamanho);
			while(verifica_valor(caractere) == 1){
				*(v+i) = caractere;
				i++;
				caractere = fgetc(stdin);
			}
			// conversao da certo, mas nao quando ha pontos, usar atof
			//valor = strtol(v,NULL,10);
			valor = atof(v);
			empilhar(&minha_pilha,valor);
			//esta empilhando
			//printf("valor empilhado = %f\n",ultimo(&minha_pilha));
			//printf("valor convertido = %.2f\n",valor);
			//printf("valor digitado = %s\n",v);
		}
	}
	num1 = desempilhar(&minha_pilha);
	printf("Resultado: %.6f\n",num1);

	return 0;

}
