
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
