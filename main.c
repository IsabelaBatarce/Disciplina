#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DISP.h"


int main (){
	char busca[100];
	int escolha=1;
	Alunos * x = (Alunos *)malloc(sizeof(Alunos));
	x->top=1;
	
	if(loginAluno(x)==0){
	CarregaDisp();
	while(escolha !=0){
		printf("**** MENU ****\n0 - SAIR \n");
		printf("1 - Buscar disciplina \n");
		printf("2 - Cadastrar aluno \n");
		printf("3 - Matricula em materias \n");
		printf("4 - Atualizar Notas e Faltas \n");
		printf("5 - Imprimir Historico \n");
		scanf("%d",&escolha);	
			
		switch(escolha){
			case 1:{
				printf("***Pesquisar disciplinas*** \n");
				printf("Digite o codigo da disciplina: ");
				scanf("%s", busca);
				ConsultaDisciplina(busca);
				break;
			}
			case 2:{
				printf("***Cadastrar aluno*** \n");
				cadastroAluno(x);
				break;
			}
			case 3:{
				printf("***Realizar matricula*** \n");
				Matricular();
				break;
			}
			case 4:{
				printf("***Notas e Faltas*** \n");
				atualizarNotas();
				break;
			}
			case 5:{
				printf("***Impressão de Historico*** \n");
				Cria_Historico(x);
				break;
			}
			default:{
				fflush(stdin);
				if(escolha > 5)		
					printf("****Opcao Invalida****\n");
				
			}
				
		}
	}
	}else{
		printf("!!login invalido!!\n");
	}
		
	
return 0;
}
