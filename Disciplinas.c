#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DISP.h"
void ConsultaDisciplina(char cod[6]){
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
	//pre requisitos
	fp = fopen("prerequisitos.txt","r");
	for(int a=0; a<31;a++){
		fgets(linha, 100, fp);
		token = strtok(linha, s);
		int test=0;
		for(int b=0;b<2;b++) {
			if(b==0){
				if(strcmp (token, cod) == 0){
					test=1;
				}
				//printf("tok =%s\ncod = %s\n",token,cod);
			}
			if((b==1)&&(test==1)){
				printf("Pre requisito = %s",token);
				test=0;
			}
			token = strtok(NULL, s);
			
		}
	}
	fclose(fp);
	
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
	x->a[x->top]=aux;
	x->top = x->top+1;	
	FILE *fp;
	fp=fopen("Alunos.txt","a");
	fprintf(fp,"%s",aux->ra);
	fprintf(fp,"%s",aux->nome);
	fprintf(fp,"%s",aux->login);
	fprintf(fp,"%s",aux->senha);
	fclose(fp);
}


//rever a logica
Aluno* newAluno(char *ra, char *nome, char *log, char *sen){
	Aluno * aux = (Aluno *)malloc(sizeof(Aluno));
	strcpy(aux->ra,ra);
	strcpy(aux->nome,nome);
	strcpy(aux->login,log);
	strcpy(aux->senha,sen);
	return aux;
}
int loginAluno(Alunos *x){
	FILE * fp = fopen("Alunos.txt","r");
	char login[100],senha[100];
	printf("***ENTRAR***\n");
	printf("Login:\n");
	fgets(login,1000,stdin);
	printf("Senha:\n");
	fgets(senha,1000,stdin);
	login[strlen(login)-1]='\0';
	senha[strlen(senha)-1]='\0';
	//printf("-%s-",login);
	char ra[10],nome[100],log[100],sen[100];
	for(int i=0;i<x->top;i++){
		fscanf(fp,"%s\n",ra);		
		fscanf(fp,"%s\n",nome);
		fscanf(fp,"%s\n",log);	
		fscanf(fp,"%s\n",sen);
//eu n sei
		x->a[i]=newAluno(ra,nome,log,sen);	
	}
	//printf("-%s -%s -%s -%s\n",login,senha,x->a[0]->login,x->a[0]->senha);
	for(int i=0;i<x->top;i++){
			
		if(strcmp (x->a[0]->login, login) == 0){
			if(strcmp (x->a[0]->senha, senha) == 0){
				return 0;
			}	
		}
	}
	return 1;
} 
