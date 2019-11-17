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

    while(!feof(alun)){
        char linha[100];
        char *token;
        token=strtok(linha,",");
        for(int a=0;a<5;a++){
            //procurar as coisas no matricula
        }
    }

    fclose(fp);
}
