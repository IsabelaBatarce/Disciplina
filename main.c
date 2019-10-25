#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DISP.h"


int main (){
	char busca[100];
	int escolha=1;

	if(loginAluno()==0){
	while(escolha !=0){
		switch(escolha){
			case 1:{
				printf("Digite o codigo da disciplina: ");
				scanf("%s", busca);
				ConsultaDisciplina(busca);
				break;
			}
			case 2:{
				printf("OUTRA opçao ");
				
				break;
			}
			default:{
				fflush(stdin);
				if(escolha > 2)		
					printf("****Opcao Invalida****\n");
				
			}
				
		}
	}
	}else{
		printf("login invalido")
	}
		
	
return 0;
}
