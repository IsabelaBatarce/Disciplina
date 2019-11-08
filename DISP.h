//parte do aluno
typedef struct Aluno{
	char ra[10];
	char nome[100];
	char senha[100];
	char login[100];

}Aluno;

typedef struct Alunos{
	Aluno *a[100];
	int top;
}Alunos;

Aluno * newAluno(char *ra, char *nome, char *log, char *sen);
void cadastroAluno();
int loginAluno(Alunos*x);
char RAatual[10];
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
//matriculas
typedef struct Matricula{
	char semestre[2];
	char disciplina[6];
	char ra[10];
	char nota[4];
	char falta[4];
}Matricula;

typedef struct Matriculas{
    Matricula *m[1000];
    int top;
}Matriculas;


void atualizarNotas();
void CarregaDisp();

void ConsultaDisciplina(char cod[5]);

void Matricular();

Disciplinas DISP;

