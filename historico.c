#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DISP.h"

void Cria_Historico(){
	printf("criando documento....\n");
    char nome[15];
    strcpy(nome,RAatual);
    strcat(nome,".txt");
    FILE *fp = fopen(nome,"w");
    fprintf(fp,"Facultade de Tecnologia - UNICAMP \n\n");
    fprintf(fp,"Relatório de matricula \n\n");
	fclose(fp);


	FILE *alun = fopen("Alunos.txt","r");
    while(!feof(alun)){
        char linha[100];
        fgets(linha,99,alun);
		linha[strlen(linha)-1]='\0';
		//printf("linha %s - ra %s\n",linha,RAatual);
        if(strcmp(linha,RAatual)==0){           
			fp = fopen(nome,"a");
			fgets(linha,99,alun);
            fprintf(fp,"Nome: %s",linha);
            fprintf(fp,"RA: %s \n",RAatual);
			fclose(fp);
        }
    }
	
    fclose(alun);
	
    //usando o FILE dos alunos para calcular o cr
    alun = fopen("matricula.txt","r");
    float CR=0;
    float verifica=0,Cred=0,Parcial=0,Parcial2=0;

    while(!feof(alun)){
        char linha[100];
        char *token;
        
		fgets(linha,99,alun);
		token=strtok(linha,",");
	
        for(int a=0;a<5;a++){
            //procurar as coisas no matricula
			
			if(token== NULL)
				break;
            if((a == 0)&&(strcmp(token,RAatual)==0)){
                verifica = 1;
            }
            if ((a == 1)&&(verifica == 1)){
                //procurar no vetor de disciplinas
                for(int b=0;b<31;b++){
                    if(strcmp(token,DISP.p[b]->codigo)){
                        Cred = DISP.p[b]->creditos;
                        Parcial += DISP.p[b]->creditos;
                    }
                }
            }
            if ((a == 3)&&(verifica == 1)){
                Parcial2 += Cred*strtof(token,NULL);
				
            }
            token = strtok(NULL,",");
        }
        verifica = 0;
    }
	fclose(alun);
    CR = Parcial2/Parcial;
	fp = fopen(nome,"a");
    fprintf(fp,"Coeficiente de Rendimento: %1.2f \n",CR);
    fprintf(fp,"\nDisciplina   Nota   Presenca(%c)	Situaçao\n",37);
    fclose(fp);


	alun = fopen("matricula.txt","r");
    float nota=0,pres=0;
    verifica=0;//reuso

    while(!feof(alun)){
        char linha[100];
        char *token;
        
		fgets(linha,99,alun);
		token=strtok(linha,",");
		//printf("%s\n",token);
        for(int a=0;a<5;a++){
            //procurar as coisas no matricula
			
			if(token== NULL)
				break;
            if((a == 0)&&(strcmp(token,RAatual)==0)){
				
                verifica = 1;
            }
            if ((a == 1)&&(verifica == 1)){
                //Apenas Printa a disciplina
				fp = fopen(nome,"a");
                fprintf(fp,"%s       ",token);
				fclose(fp);
            }
			if ((a == 3)&&(verifica == 1)){
				fp = fopen(nome,"a");
                nota = strtof(token,NULL);
				fprintf(fp,"%.2f	",nota);
				fclose(fp);
            }
            if ((a == 4)&&(verifica == 1)){
				fp = fopen(nome,"a");
                pres = strtof(token,NULL);
				fprintf(fp,"%.2f	",pres);
				fclose(fp);
            }

            token = strtok(NULL,",");

        }
		fp = fopen(nome,"a");

		if((pres!=0)&&(nota!=0)){
			if((nota<5)&&(pres<75)){
				fprintf(fp,"Reprovado por nota e falta\n");		
			}
			else if(nota<5){
					fprintf(fp,"Reprovado por nota\n");
				}else if(pres<75){
						fprintf(fp,"Reprovado por falta\n");
					}else{
							fprintf(fp,"aprovado\n");
						}
		}
		fclose(fp);
        verifica = 0;
		nota = 0;
		pres = 0;

    }
	fclose(alun);
}
