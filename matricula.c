#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DISP.h"
void Matricular(){
 
	const char s[2] = ",";
	char *token;
	char linha[100],linha2[100], *sub;
	int semestre = 0,creditos=0,valido=0;
//carregar o arquivo
	FILE *fo;
	fo = fopen("matricula.txt","r");
	if(fo == NULL){
		fo = fopen("matricula.txt","w");
		fclose(fo);	
	}
	fclose(fo);

	
	printf("digite o semestre: ");
	scanf("%d",&semestre);
	printf("Para sair digite XX000\n");
	char matr[10];

	//verificar
	while(strcmp ("XX000", matr) != 0){
		printf("digite a Materia: ");
		scanf("%s",matr);
		//QTD creditos
		for(int a=0; a<31;a++){
			if(strcmp (DISP.p[a]->codigo, matr) == 0){
				creditos+=DISP.p[a]->creditos;
				if(creditos>32){
					creditos-=DISP.p[a]->creditos;
					printf("materia não adicionada\nLimite de creditos excedido\n");
					break;
				}
			}
		}
		FILE*fp = fopen("prerequisitos.txt","r");
		for(int a=0; a<31;a++){
			fgets(linha, 100, fp);
			token = strtok(linha, s);
			int test=0;
			for(int b=0;b<2;b++) {
				if(b==0){
					if(strcmp (token, matr) == 0){
						test=1;
					}
				}
				if((b==1)&&(test==1)){
					strcpy(linha2,token);
					
					linha2[strlen(linha2)-1]='\0';
					test=0;
				}
				token = strtok(NULL, s);
				
			}
		}
		fclose(fp);
		if(strcmp(linha2,"--")==0){
			
			fo = fopen("matricula.txt","a");
			fprintf(fo,"%s,%s,%d,0,0\n",RAatual,matr,semestre);
			fclose(fo);
			strcpy(linha2,"a");//reseta a variavel pra n salvar o XX000
		}
		else{
			
			fo = fopen("matricula.txt","r");
			token = strtok(linha2, "/");
			char vai[100],*auxtok;
			int cont=0;
			while (token != NULL) { 
				
				while(fgets(vai, 100, fo)!= NULL){//vasculha arquivo atras dos prereq
					
					auxtok = strtok(vai, ",");
					for(int b=0;b<3;b++) {
						if(b==0){
							
							if(strcmp (auxtok, RAatual) == 0){
								valido=1;
							}
						}
						if((b==1)&&(valido==1)){
							
							//printf("tok-%s mat-%s\n",auxtok,vai);
							valido = 0;
							//printf("lin2 = %s\n",linha2);
							if(strcmp(auxtok,linha2)==0){
								//printf("hey");
								fo = fopen("matricula.txt","a");
								fprintf(fo,"%s,%s,%d,0,0\n",RAatual,matr,semestre);
								fclose(fo);
								cont=1;
								
							}	
						}
						auxtok = strtok(NULL, ",");	
					}if(cont=1){
						printf("Não possuí os pré-requisitos\n")
					}
					cont =0;					
					
				}
				token = strtok(NULL, "/"); 
			} 
		}
	}
}

/*void atualizarNotas(){
		Matriculas m;
		char res;
		char tete;
		int i;
		FILE*fp = fopen("matricula.txt","r");
		for(i=0;i<3;i++){
			Matricula * aux = (Matricula *)malloc(sizeof(Matricula));
                        fscanf(fp,"%s,",&res);
                        do{
        			strcpy(tete, res);
        			
    			}while(res!=',');
    
                        m.m[i]=aux;
			printf("%s\n",aux->disciplina);
		}
		fclose(fp);

}*/


void atualizarNotas(){
	FILE * fp = fopen("matricula.txt", "r");
	const char s[2] = ",";
	char *token;
	char linha[100];
	Matriculas *m = (Matriculas *)malloc(sizeof(Matriculas));
	m->top=0;

	char ra[10];
	char cod[10];
        char semestre[2];
	char nota[4];
	char falta[4];
	//fgets(linha, 100, fp)!= NULL
	while(fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", ra, cod, semestre,nota,falta) != EOF){
		
		Matricula * aux = (Matricula *)malloc(sizeof(Matricula));
		//fgets(linha, 100, fp);
		/*token = strtok(linha, s);
		for(int b=0;b<3;b++) {

        	if(b==0){
				strcpy(&aux->ra,token);
				
			}
			if(b==1){
				strcpy(aux->disciplina,token);
				printf( "%s\n", aux->disciplina);
			}
			if(b==2){
				strcpy(&aux->semestre,token);
				printf( "%d\n", aux->semestre);
			}
				token = strtok(NULL, s);
   		}*/
		
                strcpy(aux->ra,ra);
              	strcpy(aux->disciplina,cod);
              	strcpy(aux->semestre,semestre);
		strcpy(aux->nota,nota);
		strcpy(aux->falta,falta);
                printf( "%s,%s,%s,%s,%s\n", ra, cod,semestre,nota,falta);
		m->m[m->top++]=aux;
              

	}
	fclose(fp); 
	FILE * fo = fopen("matricula.txt","w");
	char sem[2];
	//procurar disciplinas já cursadas
	printf("digite o semestre desejado: ");
	scanf("%s",sem);
	
	printf("disciplinas cursadas\n ");
	/*for(int a=0;a<m->top;a++){
		if((strcmp(m->m[a]->ra,RAatual)==0)&&(strcmp(m->m[a]->semestre,sem)==0)){
		
		}
	}*/
		//printf("Raaautual:%s\n", RAatual);
 		//printf("Aux:%d\n", aux);
	for(int a=0;a<m->top;a++){
		printf("%s %s\n",m->m[a]->semestre,sem);
		if((strcmp(m->m[a]->ra,RAatual)==0)&&(strcmp(m->m[a]->semestre,sem)==0)){
			printf(" - %s\n",m->m[a]->disciplina);
			printf("digite a nota: ");
		
			scanf("%s",m->m[a]->nota);
			printf("digite a porcentagem de presença : ");
			
			scanf("%s",m->m[a]->falta);
			
		}
	}
		for(int a=0;a<m->top;a++){
		fprintf(fo,"%s,%s,%s,%s,%s\n",m->m[a]->ra,m->m[a]->disciplina,m->m[a]->semestre,m->m[a]->nota,m->m[a]->falta);
		}
	fclose(fo);
	

}
