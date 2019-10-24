#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DISP.h"
void ConsultaDisciplina(char cod[5]){
	FILE * fp = fopen("Disciplinas.txt", "r");
	const char s[2] = ",";
	char *token;
	char linha[100];
	
	for(int a=0; a<31;a++){
		Disciplina * aux = (Disciplina *)malloc(sizeof(Disciplina));
		fgets(linha, 100, fp);
		token = strtok(linha, s);
		for(int b=0;b<3;b++) {
        	if(b==0){
				char sub[6];
				for(int ee=0;ee<5;ee++){
					sub[ee] = token[ee];
				}
				strcpy(aux->codigo,sub);
				//printf( "%s\n", aux->codigo);
			}
    		if(b==1){
				strcpy(aux->nome,token);
				//printf( "%s\n", aux->nome);
			}
			if(b==2){
				aux->creditos= token[0] - 48;
				//printf( "%d\n", aux->creditos);
			}
    		token = strtok(NULL, s);
   		}
		DISP.p[a]=aux;	
	}
	fclose(fp);
	//AGORA SIM VAI PESQUISAR
	for(int a=0; a<31;a++){
		if(strcmp (DISP.p[a]->codigo, cod) == 0)
			printf("nome:%s\ncreditos:%d\n",DISP.p[a]->nome,DISP.p[a]->creditos);
	}
}
