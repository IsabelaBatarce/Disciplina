#include <stdio.h>





tem que achar um jeito de poder fazer login com outro user a n ser o primeiro
	
	if(loginAluno(x)==0){
	while(escolha !=0){
		printf("**** MENU ****\n0 - SAIR \n");
		printf("1 - Buscar disciplina \n");
		printf("2 - Cadastrar aluno \n");
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
			default:{
				fflush(stdin);
				if(escolha > 2)		
					printf("****Opcao Invalida****\n");
				
			}
				
		}
	}
	}else{
		printf("login invalido");
	}
		
	
return 0;
}
