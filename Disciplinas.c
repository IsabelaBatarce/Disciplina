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

void cadastroAluno(){
	Aluno *aux;
	Alunos *x;
	
	printf("Digite o RA do Aluno:\n");
	fgets(aux->ra,10,stdin);
	printf("Digite o nome do Aluno:\n");
	fgets(aux->nome,1000,stdin);
	printf("Digite o login:\n");
	fgets(aux->login,1000,stdin);
	printf("Digite a senha\n");
	fgets(aux->senha,1000,stdin);
	x->a[x->top]=*aux;//*=content of
	x->top = x->top+1;	
	FILE *fp;
	fp=fopen("Alunos.txt","a");
	fprintf(fp,"%s",aux->ra);
	fprintf(fp,"%s",aux->nome);
	fprintf(fp,"%s",aux->login);
	fprintf(fp,"%s",aux->senha);
	fclose(fp);
}

Alunos* NewAlunos(){
	Alunos * aux = (Alunos *)malloc(sizeof(Alunos));
	aux->top=0;
	return aux;
}
//rever a logica
Aluno* NewAluno(){
	Aluno * aux = (Aluno *)malloc(sizeof(Aluno));
	return aux;
}
int loginAluno(){
	Aluno *a;
	Alunos *x;
	char login[1000];
	char senha[1000];
	int i,retorno,aux,cont=0;
	while(cont==0){

		
		printf("Usuário:\n");
		fgets(login,1000,stdin);
		printf("Senha:\n");
		fgets(senha,1000,stdin);
		FILE *fp;
		fp = fopen("Alunos.txt","r");
		for(i=0;i<x->top;i++){
			fscanf(fp,"%s", x->a[i].ra);		
			fscanf(fp,"%s", x->a[i].nome);
			fscanf(fp,"%s", x->a[i].login);	
			fscanf(fp,"%s", x->a[i].senha);	
		}
		fclose(fp);
		for(i=0;i<x->top;i++){
			retorno = strcmp(login, x->a[i].login);
			aux = strcmp(login, x->a[i].senha);
			if((retorno && aux) == 0){
				cont++;
				break;		
			}
		}

		if(cont==0){
			printf("Login inválido tente novamente\n");
			return 1;
		}
		else{
			return 0;
		}
	}
}
