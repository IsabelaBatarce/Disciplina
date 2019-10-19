#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Disciplina{
	char codigo[5];
	char nome[150];
	int creditos;
}Disciplina;
typedef struct Disciplinas{
    Disciplina *p[100];
    int top;
}Disciplinas;
void ConsultaDisciplina(char cod[5]){
	FILE * fp = fopen("teste.txt", "r");
	Disciplinas carrega;//declarar isso como global no main ou .h
	//for(int i=0;i<30;i++){
		Disciplina * aux = (Disciplina *)malloc(sizeof(Disciplina));
		fscanf(fp,"%s,%s,%d\n",aux->codigo,aux->nome,&aux->creditos);	
		printf("%s/ %s/ %d\n", aux->codigo,aux->nome,&aux->creditos);
		//fscanf(fp,"%s,",aux->nome);
		//fscanf(fp,"%d\n",&aux->creditos);
		//carrega.p[i]=aux;
	//}
	fclose(fp);
	
	
	for(int i=0;i<31;i++){
//		printf("%s\n", carrega.p[5]);
		//if(strcmp (cod,carrega.p[i]->codigo) == 0){
			//printf("Nome da siciplina: %s\n",carrega.p[i]->nome);
		//}	
	}
}
 int main (){
	char busca[100];	
	printf("Digite o codigo da disciplina: ");
	scanf("%s", &busca);
	ConsultaDisciplina(busca);
return 0;
}
