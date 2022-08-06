#include<stdio.h>

void leitura(int vet[6][3], int linhas, int colunas){
	int j, k;
	for(j = 0; j < linhas; j++){
		for(k = 0; k < colunas; k++){
			scanf("%d", &vet[j][k]);
		}
	}
}

void imprime(int vetor[6][3]){
	int j;
	for(j = 0; j < 6; j++){
		printf("Color(%d): [\t%d\t%d\t%d\t]\n",j,vetor[j][0],vetor[j][1],vetor[j][2]);
	}
}

void mistura(int vetor[6][3], int posicoes[3], int matriz[6][3]){
	int p1 = posicoes[0];
	int p2 = posicoes[1];
	int p_resultante = posicoes[2];
	int j,k;

	for(j = 0; j < 6; j++){
		if(j != p_resultante){
			for(k = 0; k < 3; k++){
					matriz[j][k] = vetor[j][k];
			}
		}
		else{
			for(k = 0; k < 3; k++){
				if(vetor[p1][k]+vetor[p2][k]+vetor[j][k] > 510){
					matriz[j][k] = 255;
				}
				else if(vetor[p1][k] + vetor[p2][k] + vetor[j][k] == 510){
					matriz[j][k] = vetor[p1][k]/2 + vetor[p2][k]/2 + vetor[j][k];
				}
				else{
					matriz[j][k] = (vetor[p1][k] + vetor[p2][k])/2 +vetor[j][k];
				}
			}
	}
	}
}

int main(){
	int paleta[6][3], p_final[6][3];
	
	int soma[3];
	scanf("%d %d %d",&soma[0],&soma[1],&soma[2]);

	/*cada cor composta por:
	 * vermelho (R), verde (G), azul(B)
	 * qtdes das tonalidades varia de 0 a 255
	 *
	 * Como rola a mistura:
	 * pega 3 num, os 2 primeiros com a posicao das cores
	 * e por na posicao com o terceiro numero na paleta resultante
	 *
	 * ex: [ 2 3 1]
	 * pega as tonalidades de 2 e 3 e soma, dividindo, entao, por 2
	 * ao fim, soma ao que esta em 1
	*/

	leitura(paleta,6,3);

	mistura(paleta, soma, p_final);

	printf("Start:\n");
	imprime(paleta);
	printf("\n");
	printf("Result:\n");
	imprime(p_final);

	return 0;

}

