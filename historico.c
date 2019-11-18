#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DISP.h"

void Cria_Historico(){
    char nome[15];
    strcpy(nome,RAatual);
    strcat(nome,".txt");
    FILE *fp = fopen(nome,"w");
    FILE *alun = fopen("Alunos","r");
    fprintf(fp,"Facultade de Tecnologia - UNICAMP \n\n");
    fprintf(fp,"Relatório de matricula \n\n");
    while(!feof(alun)){
        char linha[100];
        fgets(linha,99,alun);
        if(strcmp(linha,RAatual)==0){
            fgets(linha,99,alun);
            fprintf(fp,"Nome: %s \n",linha);
            fprintf(fp,"RA: %s \n",RAatual);
        }
    }
    fclose(alun);
    //usando o FILE dos alunos para calcular o cr
    alun = fopen("matricula","r");
    int CR=0;
    int verifica=0,Cred=0,Parcial=0,Parcial2=0;

    while(!feof(alun)){
        char linha[100];
        char *token;
        token=strtok(linha,",");

        fgets(linha,99,alun);

        for(int a=0;a<5;a++){
            //procurar as coisas no matricula
            if((a == 0)&&(strcmp(token,RAatual)==0)){
                verifica =1;
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
    CR = Parcial2/Parcial;
    fprintf(fp,"Coeficiente de Rendimento: %d \n",CR);
    fclose(fp);
}
