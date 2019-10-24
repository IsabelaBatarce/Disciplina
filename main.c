#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "aluno.h"
#include "DISP.h"

int main(){
	char busca[100];	
	printf("Digite o codigo da disciplina: ");
	scanf("%s", busca);
	ConsultaDisciplina(busca);
	return 0;
}
