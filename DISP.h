//parte do aluno
typedef struct Aluno{
	char ra[1000];
	char nome[1000];
	char senha[1000];
	char login[1000];

}Aluno;

typedef struct Alunos{
	Aluno *a;
	int top;
}Alunos;



void cadastroAluno();
int loginAluno();

//parte das disciplinas
typedef struct Disciplina{
	char codigo[6];
	char nome[150];
	int creditos;
}Disciplina;

typedef struct Disciplinas{
    Disciplina *p[100];
    int top;
}Disciplinas;

void ConsultaDisciplina(char cod[5]);

Disciplinas DISP;
