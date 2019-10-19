#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

void cadastroAluno(){
	char ra[10],nome[1000],login[1000],senha[1000];
	printf("Digite o RA do Aluno:\n");
	fgets(ra,10,stdin);
	printf("Digite o nome do Aluno:\n");
	fgets(nome,1000,stdin);
	printf("Digite o login:\n");
	fgets(login,1000,stdin);
	printf("Digite a senha\n");
	fgets(senha,1000,stdin);	
	FILE *fp;
	fp=fopen("Alunos.txt","a");
	fprintf(fp,"%s",&ra);
	fprintf(fp,"%s",&nome);
	fprintf(fp,"%s",&login);
	fprintf(fp,"%s",&senha);
	fclose(fp);

}
