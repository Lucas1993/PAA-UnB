#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void grandeO(int a, int b, int fn, int P){
	printf("\n");
	printf("Fato: T(n) = %dT(n/%d) + n^%d\n", a,b,fn);
	printf("Suposicao: T(n/%d) <= c(n/%d)^%d\n",b,b,P);
	printf("Precisa provar: T(n)<= cn^%d\n",P);
	printf("T(n) = %dT(n/%d) + n^%d\n", a,b,fn);
	printf("    <= %dc(n/%d)^%d + n^%d\n",a,b,P,fn);

	double aux = a/pow(b,P);
	if(aux == 1){
		printf("     = cn^%d + n^%d\n", P,fn);
		printf("     = cn^%d - ( -n^%d) <--- desejado - residual\n", P,fn);
		printf("    <= cn^%d para nenhuma escolha com c > 0\n",P);
		printf("Impossivel provar\n");
	}
	else if(aux > 1){
		printf("     = %.2f*cn^%d + n^%d\n",aux, P,fn);
		printf("     = cn^%d - (-%.2f*cn^%d - n^%d) <--- desejado - residual\n", P,aux-1.00,P,fn);
		printf("    <= cn^%d para nenhuma escolha com c > 0\n",P);
		printf("Impossivel provar\n");
	}

	else{
		double residuo = 1.00-aux;
		printf("     = c(n^%d)/%.2f + n^%d\n",P,((double)pow(b,P)/a),fn);
		printf("     = cn^%d - (%.2f*cn^%d - n^%d) <--- desejado - residual\n", P,residuo, P,fn);
		if(fn > P){
			printf("    <= cn^%d para nenhuma escolha com c > 0\n",P);
			printf("Impossivel provar\n");
		}
		else if(fn <= P){
			printf("    <= cn^%d <--- desejado\n\n", P);
			printf("Quando %.2fcn^%d - n^%d >= 0\n", residuo, P,fn);
			printf("Se c >= %.2f e n >= 1\n", 1/residuo);
		}
	}
	printf("\n");
}

void grandeOmega(int a, int b, int fn, int P){
	printf("\n");
	printf("Fato: T(n) = %dT(n/%d) + n^%d\n", a,b,fn);
	printf("Suposicao: T(n/%d) >= c(n/%d)^%d\n",b,b,P);
	printf("Precisa provar: T(n) >= cn^%d\n",P);
	printf("T(n) = %dT(n/%d) + n^%d\n", a,b,fn);
	printf("    >= %dc(n/%d)^%d + n^%d\n",a,b,P,fn);

	double aux = a/pow(b,P);
	if(aux == 1){
		printf("     = cn^%d + n^%d\n", P,fn);
		printf("     = cn^%d + n^%d) <--- Desejado + residual\n", P,fn);
		printf("    >= cn^%d <- Desejado\n\n", P);
		printf("Quando n^%d >= 0\n", fn);
		printf("Se n >= 1\n");
	}
	else if(aux > 1){
		printf("     = %.2fcn^%d + n^%d\n",aux, P,fn);
		printf("     = cn^%d + (%.2f*cn^%d + n^%d) <--- desejado + residual\n", P,aux-1.00,P,fn);
		printf("    >= cn^%d <--- Desejado\n",P);
		printf("Quando %.2f*cn^%d + n^%d >= 0\n", aux-1.00,P,fn);
		printf("Se c >= 1 e n >= 1\n");
	}
	else{
		double residuo = 1.00-aux;
		printf("     = c(n^%d)/%.2f + n^%d\n",P,((double)pow(b,P)/a),fn);
		printf("     = cn^%d + (-%.2f*cn^%d + n^%d) <--- desejado + residual\n", P,residuo, P,fn);
		if(fn > P){
			printf("    >= cn^%d <--- desejado\n",P);
			printf("Quando %.2f*cn^%d + n^%d >= 0\n", residuo,P,fn);
			printf("Se c >= %.2f e n >= 1\n", 1/residuo);
		}
		else if(fn <= P){
			printf("    >= cn^%d para nenhuma escolha com c > 0\n",P);
			printf("Impossivel provar\n");
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]){

	int a,b, fn, P;
	char C[100];
	char flag = 0;

	if (argc < 6){
		printf("Passe 5 argumentos: <a> <b> <fn> <P> <C>\n");
		return 1;
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	fn = atoi(argv[3]);
	P = atoi(argv[4]);
	strcpy(C,argv[5]);

	if(strcmp(C,"grandeo") != 0 && strcmp(C,"grandeomega") != 0 && strcmp(C,"teta") != 0){
		printf("Ultimo argumento nao reconhecido, tem que ser: grandeo, grandeomega ou teta\n");
		return 1;
	}

	if((strcmp("grandeo",C) == 0 ) || (strcmp("teta",C) == 0))
		grandeO(a,b,fn,P);

	if((strcmp(C,"grandeomega") == 0 ) || (strcmp(C,"teta") == 0))
		grandeOmega(a,b,fn,P);
	
    return 0;


}
