//parte do aluno
typedef struct Aluno{
	char ra[100];
	char nome[100];
	char senha[100];
	char login[100];

}Aluno;

typedef struct Alunos{
	Aluno *a[100];
	int top;
}Alunos;

Aluno * newAluno(char *ra, char *nome, char *log, char *sen);
void cadastroAluno(Alunos*x);
int loginAluno(Alunos*x);

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
