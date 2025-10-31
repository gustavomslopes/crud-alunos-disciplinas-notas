//PARTICIPANTES
//GUSTAVO MEDEIROS SCHEIDEGGER LOPES e FILIPPO LIMEIRA TOLOMEI

#include <stdio.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>

#define TFA 20
#define TFD 20

struct TpAluno
{
	char Nome[20], RA[13];
};

struct TpDisciplina
{
	int CodDisc;
	char Disciplina[30];
};

struct TpAlunoDisciplina
{
	char RA[13];
	int CodDisc;
	float Nota;
};

struct StReprov
{
	TpAluno Aluno;
};

struct StLetra
{
	TpAluno Aluno;
};

struct StTermo
{
	TpDisciplina Disciplina;
};

struct StDiscMG
{
	TpDisciplina Disciplina;
};

void debug (TpAlunoDisciplina Geral[], TpAluno Alunos[], TpDisciplina Disciplinas[], int &TLA, int &TLD, int &TLN)
{
	strcpy(Alunos[0].RA, "26.09.1045-1");    strcpy(Alunos[0].Nome, "Bertalia");
    strcpy(Alunos[1].RA, "10.09.1055-3");    strcpy(Alunos[1].Nome, "Creusa");
    strcpy(Alunos[2].RA, "26.09.2012-1");    strcpy(Alunos[2].Nome, "Florisbela");
    strcpy(Alunos[3].RA, "10.09.3052-6");    strcpy(Alunos[3].Nome, "Jurema");
    strcpy(Alunos[4].RA, "26.09.3444-8");    strcpy(Alunos[4].Nome, "Petronio");

    Disciplinas[0].CodDisc = 100;    strcpy(Disciplinas[0].Disciplina, "ATP I");
    Disciplinas[1].CodDisc = 105;    strcpy(Disciplinas[1].Disciplina, "ATP II");
    Disciplinas[2].CodDisc = 120;    strcpy(Disciplinas[2].Disciplina, "Estrutura de Dados I");
    Disciplinas[3].CodDisc = 150;    strcpy(Disciplinas[3].Disciplina, "Pesquisa e Ordenacao");
    Disciplinas[4].CodDisc = 210;    strcpy(Disciplinas[4].Disciplina, "Ferramentas I");
    Disciplinas[5].CodDisc = 230;    strcpy(Disciplinas[5].Disciplina, "Estatistica");
    Disciplinas[6].CodDisc = 240;    strcpy(Disciplinas[6].Disciplina, "Matematica Discreta");

    strcpy(Geral[0].RA, "26.09.1045-1");    Geral[0].CodDisc = 120;    Geral[0].Nota = 8.0;
    strcpy(Geral[1].RA, "26.09.1045-1");    Geral[1].CodDisc = 210;    Geral[1].Nota = 4.5;
    strcpy(Geral[2].RA, "26.09.1045-1");    Geral[2].CodDisc = 230;    Geral[2].Nota = 6.5;
    strcpy(Geral[3].RA, "10.09.1055-3");    Geral[3].CodDisc = 150;    Geral[3].Nota = 5.0;
    strcpy(Geral[4].RA, "10.09.1055-3");    Geral[4].CodDisc = 240;    Geral[4].Nota = 4.5;
    strcpy(Geral[5].RA, "26.09.2012-1");    Geral[5].CodDisc = 100;    Geral[5].Nota = 7.0;
    strcpy(Geral[6].RA, "26.09.2012-1");    Geral[6].CodDisc = 210;    Geral[6].Nota = 6.0;
    strcpy(Geral[7].RA, "26.09.2012-1");    Geral[7].CodDisc = 230;    Geral[7].Nota = 9.0;

    TLA = 5;
    TLD = 7;
    TLN = 8;

}

void Moldura(int x1, int y1, int x2, int y2, int cortexto, int corfundo)
{
	int i;
	textcolor(cortexto);
	textbackground(corfundo);
	gotoxy(x1,y1);
	printf("%c",201);
	gotoxy(x2,y1);
	printf("%c",187);
	gotoxy(x1,y2);
	printf("%c",200);
	gotoxy(x2,y2);
	printf("%c",188);
	for(i=x1+1; i<x2; i++)
	{
		gotoxy(i,y1);
		printf("%c",205);
		gotoxy(i,y2);
		printf("%c",205);
	}	
	for(i=y1+1; i<y2; i++)
	{
		gotoxy(x1,i);
		printf("%c",186);
		gotoxy(x2,i);
		printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}

void Interface(void)
{
	clrscr();
	Moldura(1,1,80,25,1,0);
	Moldura(2,2,79,4,3,0);
	Moldura(36,5,79,24,2,0);
	Moldura(2,5,35,24,5,0);
	gotoxy(23,3);
	printf("### Trabalho de ATP II ###");
	
}

void Interface2(void)
{
	clrscr();
	Moldura(1,1,80,25,1,0);
	Moldura(2,2,79,4,3,0);
	Moldura(2,5,79,7,2,0);
	gotoxy(23,3);
	printf("### Trabalho de ATP II ###");
	
}

char MenuInicial(void) 
{
	Interface();
	gotoxy(9,6);
	printf("### MENU INICIAL ###");
	gotoxy(4,8);
	printf("[A] Manutencao Completa");
	gotoxy(4,9);
	printf("[B] Gerar Relatorios");
	gotoxy(4, 10);
	printf("[ESC] Finalizar");
	gotoxy(4,12);
	printf("Opcao desejada: ");
	return toupper(getche());
}

char MenuManutencao(void)
{
	Interface();
	gotoxy(6,6);
	printf("### MENU MANUTENCAO ###");
	gotoxy(4,8);
	printf("[A] Cadastrar");
	gotoxy(4,9);
	printf("[B] Excluir");
	gotoxy(4, 10);
	printf("[C] Alterar");
	gotoxy(4,11);
	printf("[D] Consultar");
	gotoxy(4,12);
	printf("[ESC] Voltar");
	gotoxy(4,14);
	printf("Opcao desejada: ");
	return toupper(getche());
}

char MenuAlunoDisciplinaNota (void)
{
	Interface();
	gotoxy(6,6);
	printf("### MENU MANUTENCAO ###");
	gotoxy(4,8);
	printf("[A] Aluno");
	gotoxy(4,9);
	printf("[B] Disciplina");
	gotoxy(4, 10);
	printf("[C] Nota");
	gotoxy(4,11);
	printf("[ESC] Voltar");
	gotoxy(4,13);
	printf("Opcao desejada: ");
	return toupper(getche());
}

char MenuRelatorios(void)
{
	Interface();
	gotoxy(6,6);
	printf("### MENU RELATORIOS ###");
	gotoxy(4,8);
	printf("[A] Alunos Reprovados 2+ disc");
	gotoxy(4,9);
	printf("[B] Alunos por Letra");
	gotoxy(4, 10);
	printf("[C] Disciplinas por Termo");
	gotoxy(4,11);
	printf("[D] Disciplinas com MG < 6.0");
	gotoxy(4,12);
	printf("[E] Todos os Alunos");
	gotoxy(4,13);
	printf("[ESC] Voltar");
	gotoxy(4,15);
	printf("Opcao desejada: ");
	return toupper(getche());
}

void LerString(char string[], char texto[])
{
	printf("%s: ", texto);
	fflush(stdin);
	gets(string);
}

void LerInt(int &num, char texto[])
{
	printf("%s: ", texto);
	scanf("%d", &num);
}

void LerFloat(float &num, char texto[])
{
	printf("%s: ", texto);
	scanf("%f", &num);
}

void LerChar(char &Letra, char texto[])
{
	printf("%s: ", texto);
	Letra = toupper(getche());
}

void Limpeza(int x1, int y1, int x2, int y2)
{
	for(int linha=y1;linha<y2;linha++)
	{
		for(int col=x1;col<x2;col++)
		{
			gotoxy(col,linha);
			printf(" ");
		}
	}
}

void VerifCodDisc (int x, int y, int &CodDisc)
{
	while(CodDisc<0)
	{
		gotoxy(x,y);
		printf("         ");
		gotoxy(x,y);
		scanf("%d", &CodDisc);
	}
}

void VerifNota (int x, int y, float &Nota)
{
	while(Nota<0 || Nota>10)
	{
		gotoxy(46,9);
		printf("     ");
		gotoxy(46,9);
		scanf("%f", &Nota);
	}
}

void VerifString(int x, int y, char String[])
{
	while(strcmp(String, "\0")==0)
	{
		gotoxy(x,y);
		fflush(stdin);
		gets(String);
	}
}

bool BuscaGeral (TpAlunoDisciplina Geral[], int TL, char RA[], int CodDisc, int &pos)
{
	pos=0;
	while(pos<TL && (strcmp(Geral[pos].RA, RA) != 0 || Geral[pos].CodDisc != CodDisc))
		pos++;
	
	return pos<TL;
}

bool BuscaCodDisc (TpDisciplina Disciplinas[], int TL, int CodDisc, int &pos)
{
	pos=0;
	while(pos<TL && Disciplinas[pos].CodDisc != CodDisc)
		pos++;
	
	return pos<TL;
}

bool BuscaRA (TpAluno Alunos[], int TL, char RA[], int &pos)
{
	pos=0;
	while(pos<TL && stricmp(Alunos[pos].RA, RA) != 0)
		pos++;
	
	return pos<TL;
}

bool BuscaRAGeral (TpAlunoDisciplina Geral[], int TL, char RA[])
{
    int pos=0;
    while(pos<TL && (strcmp(Geral[pos].RA, RA) != 0))
        pos++;

    return pos<TL;
}

bool BuscaCodDiscNota (StDiscMG Notas[], int TL, int CodDisc, int &pos)
{
	pos=0;
	while(pos<TL && Notas[pos].Disciplina.CodDisc != CodDisc)
		pos++;
	
	return pos<TL;
}

bool CadastroAluno (char Nome[], char RA[], TpAluno Alunos[], int &TL, int pos)
{
	if(!BuscaRA(Alunos, TL, RA, pos))
	{
		strcpy(Alunos[TL].RA, RA);
		strcpy(Alunos[TL].Nome, Nome);
		TL++;
		return true;
	}	
	
	return false;
}

void ExclusaoAluno (char RA[], TpAluno Alunos[], TpAlunoDisciplina Geral[], int &TLA, int &TLN, int pos)
{
	for(int i=0; i<TLN; i++)
		if(strcmp(Geral[i].RA, RA)==0)
		{
			for(int j=i; j<TLN-1; j++)
			{
				strcpy(Geral[i].RA, Geral[i+1].RA);
				Geral[i].CodDisc = Geral[i+1].CodDisc;
				Geral[i].Nota = Geral[i+1].Nota;
			}
			TLN--;
		}
	for(int i=pos; i<TLA-1; i++)
	{
		strcpy(Alunos[i].RA, Alunos[i+1].RA);
		strcpy(Alunos[i].Nome, Alunos[i+1].Nome);
	}
	TLA--;
}

void ExclusaoDisc(int CodDisc, TpDisciplina Disciplinas[], TpAlunoDisciplina Geral[], int &TLD, int &TLN, int pos)
{
	for(int i=0; i<TLN; i++)
		if(Geral[i].CodDisc==CodDisc)
		{
			for(int j=i; j<TLN-1; j++)
			{
				strcpy(Geral[i].RA, Geral[i+1].RA);
				Geral[i].CodDisc = Geral[i+1].CodDisc;
				Geral[i].Nota = Geral[i+1].Nota;
			}
			TLN--;
		}
	for(int i=pos; i<TLD-1; i++)
	{
		strcpy(Disciplinas[i].Disciplina,Disciplinas[i+1].Disciplina);
		Disciplinas[i].CodDisc = Disciplinas[i+1].CodDisc;
	}
	TLD--;
}

void ExclusaoNota (char RA[], int CodDisc, TpAlunoDisciplina Geral[], int &TLN, int pos)
{
	for(int i=pos; i<TLN-1; i++)
	{
		strcpy(Geral[i].RA, Geral[i+1].RA);
		Geral[i].CodDisc = Geral[i+1].CodDisc;
		Geral[i].Nota = Geral[i+1].Nota;
	}
	TLN--;
}



bool CadastroDisciplina (char Disciplina[], int CodDisc, TpDisciplina Disciplinas[], int &TL, int pos)
{
	if(!BuscaCodDisc(Disciplinas, TL, CodDisc, pos))
	{
		Disciplinas[TL].CodDisc = CodDisc;
		strcpy(Disciplinas[TL].Disciplina, Disciplina);
		TL++;
		return true;
	}
	
	return false;
}


bool CadastroNota (char RA[], int CodDisc, float Nota, TpAlunoDisciplina Geral[], int &TL)
{
	int pos;
	if(!BuscaGeral(Geral, TL, RA, CodDisc, pos))
	{
		pos=0;
		while(pos<TL && Geral[pos].RA != RA)
			pos++;
		if(pos<TL)
		{
			for(int i=TL; i>pos; i--)
			{
				strcpy(Geral[i].RA, Geral[i-1].RA);
				Geral[i].CodDisc = Geral[i-1].CodDisc;
				Geral[i].Nota = Geral[i-1].Nota;
			}
			strcpy(Geral[pos].RA, RA);
			Geral[pos].CodDisc = CodDisc;
			Geral[pos].Nota = Nota;
			TL++;
		}
		else
		{
			strcpy(Geral[pos].RA, RA);
			Geral[pos].CodDisc = CodDisc;
			Geral[pos].Nota = Nota;
			TL++;
		}
		return true;
	}
	
	return false;
}


void AlteracaoAluno(TpAluno Alunos[], TpAlunoDisciplina Geral[], char RA[], char Nome[], int TLN, int pos)
{
	for(int i=0; i<TLN; i++)
		if(strcmp(Geral[i].RA, Alunos[pos].RA) == 0)
			strcpy(Geral[i].RA, RA);
		
	strcpy(Alunos[pos].Nome, Nome);
	strcpy(Alunos[pos].RA, RA);
	
}

void AlteracaoDisc(TpDisciplina Disciplinas[], TpAlunoDisciplina Geral[], int CodDisc, char Disciplina[], int TLN, int pos)
{
	for(int i=0; i<TLN; i++)
		if(Geral[i].CodDisc == Disciplinas[pos].CodDisc)
			Geral[i].CodDisc = CodDisc;
			
	Disciplinas[pos].CodDisc = CodDisc;
	strcpy(Disciplinas[pos].Disciplina, Disciplina);
}

void AlteracaoNota(TpAlunoDisciplina Geral[], char RA[], int CodDisc, float Nota, int pos)
{
	strcpy(Geral[pos].RA, RA);
	Geral[pos].CodDisc = CodDisc;
	Geral[pos].Nota = Nota;	
}

void AvancarVoltar(void)
{
	gotoxy(3,6);
	printf("[A] Voltar");
	gotoxy(68,6);
	printf("[D] Avancar");
}

void ExisteRA (TpAluno Alunos[], int TL, char RA[], int &pos)
{
	while(!BuscaRA(Alunos, TL, RA, pos))
	{
		gotoxy(40,8);
		printf("Aluno nao encontrado!");
		gotoxy(44,7);
		printf("       ");
		gotoxy(44,7);
		gets(RA);
		VerifString(44, 7, RA);
	}
}

void ExisteCodDisc (TpDisciplina Disciplinas[], int TL, int &CodDisc, int &pos)
{
	while(!BuscaCodDisc(Disciplinas, TL, CodDisc, pos))
	{
		gotoxy(40,8);
		printf("Disciplina nao encontrada!");
		gotoxy(50,7);
		printf("       ");
		gotoxy(50,7);
		scanf("%d", &CodDisc);
		VerifCodDisc(50,7,CodDisc);
	}
}

void ExisteCodDisc2 (TpDisciplina Disciplinas[], int TL, int &CodDisc, int &pos)
{
	while(!BuscaCodDisc(Disciplinas, TL, CodDisc, pos))
	{
		gotoxy(40,9);
		printf("Disciplina nao encontrada!");
		gotoxy(50,8);
		printf("       ");
		gotoxy(50,8);
		scanf("%d", &CodDisc);
		VerifCodDisc(50,8,CodDisc);
	}
}

void ExisteNota (TpAlunoDisciplina Geral[], int TL, char RA[], int &CodDisc, int &pos)
{
	while(!BuscaGeral(Geral, TL, RA, CodDisc, pos))
	{
		gotoxy(40,9);
		printf("Nota nao encontrada!");
		gotoxy(44,7);
		printf("       ");
		gotoxy(44,7);
		gets(RA);
		VerifString(44, 7, RA);
		gotoxy(50,8);
		printf("       ");
		gotoxy(50,8);
		scanf("%d", &CodDisc);
		VerifCodDisc(50,8,CodDisc);
	}
}

void Rel2Rec(TpAlunoDisciplina Geral[], int TLN, int TLA, TpAluno Alunos[])
{
	int ContRep, i=0, pos, flag, TLR=0, j, ContF, ContI;
	char AuxRA[13], opcao;
	StReprov AlunosRec[TFA];
	
	while(i<TLN)
	{
		strcpy(AuxRA, Geral[i].RA);
		ContRep=0; 
		flag=0;
		while(strcmp(AuxRA, Geral[i].RA) == 0)
		{
			
			if(Geral[i].Nota<6)
				ContRep++;
				
			if(ContRep>=2 && flag==0)
			{
				BuscaRA(Alunos, TLA, AuxRA, pos);
					
				strcpy(AlunosRec[TLR].Aluno.Nome, Alunos[pos].Nome);
				strcpy(AlunosRec[TLR].Aluno.RA, Alunos[pos].RA);
				flag=1;
				TLR++;
			}
			i++;
		}
	}
	
	if(TLR>9)
	{
		ContF=9;		
	}
	else
	{
		ContF=TLR;
	}
	ContI=0;
	Limpeza(2,8,80,25);
	do
	{
		for(int y=8, j=ContI; y<=24 && j<ContF ; y+=2, j++)
		{
			gotoxy(23,y);
			printf("Nome: %s\tRA: %s", AlunosRec[j].Aluno.Nome, AlunosRec[j].Aluno.RA);	
		}	
		if(TLR>9)
		{
			opcao = toupper(getch());
			if(opcao == 'A')
			{
				if(ContI-9 >= 0){
					ContF = ContI;
					ContI-=9;
					Limpeza(2,8,80,25);	
				}			
			}
			if(opcao == 'D')
			{
				if(ContF < TLR)
				{
					ContF = ContF+9;
					if(ContF>TLR)
						ContF-=ContF-TLR;
					ContI+=9;
					Limpeza(2,8,80,25);
				}
			}
		}
		
	}while(opcao != 27 && TLR>9);
}


void RelAlunoLetra(TpAluno Alunos[], int TLA, char Letra)
{
	char opcao;
	int TLL=0, ContF, ContI, j;
	StLetra Letras[TFA];
	
	gotoxy(25,6);
	printf("Alunos pela Letra: %c", Letra);
	
	for(int i=0; i<TLA; i++)
	{
		if(Alunos[i].Nome[0] == Letra)
		{
			Letras[TLL].Aluno = Alunos[i];
			TLL++;
		}
	}
	
	
	if(TLL>9)
	{
		ContF=9;		
	}
	else
	{
		ContF=TLL;
	}
	ContI=0;
	Limpeza(2,8,80,25);
	if(TLL==0)
	{
		gotoxy(25,8);
		printf("Nada Encontrado!");
	}
	do
	{
		for(int y=8, j=ContI; y<=24 && j<ContF ; y+=2, j++)
		{
			gotoxy(23,y);
			printf("Nome: %s\tRA: %s", Letras[j].Aluno.Nome, Letras[j].Aluno.RA);	
		}	
		if(TLL>9)
		{
			opcao = toupper(getch());
			if(opcao == 'A')
			{
				if(ContI-9 >= 0){
					ContF = ContI;
					ContI-=9;
					Limpeza(2,8,80,25);	
				}			
			}
			if(opcao == 'D')
			{
				if(ContF < TLL)
				{
					ContF = ContF+9;
					if(ContF>TLL)
						ContF-=ContF-TLL;
					ContI+=9;
					Limpeza(2,8,80,25);
				}
				
			}
		}
		
	}while(opcao != 27 && TLL > 9);
}

void RelTermoDisc(TpDisciplina Disciplinas[], int TLD, char TermoDisc[])
{
	StTermo Termo[TFD];
	int TLT=0, cont, ContF, ContI, j, flag;
	char opcao;

	
	for(int i=0, x=0; i<TLD; i++)
	{	
		j=0;
		x=0;
		
		flag=0;
		while(j<strlen(Disciplinas[i].Disciplina))
		{
			cont=0;
			while(toupper(Disciplinas[i].Disciplina[j]) == toupper(TermoDisc[x]))
			{
				j++;
				x++;
				cont++;
			}
			if(cont == strlen(TermoDisc) && flag==0)
			{
				Termo[TLT].Disciplina = Disciplinas[i];
				TLT++;
				flag=1;
			}
			j++;	
		}
	}
	
	if(TLT>9)
	{
		ContF=9;		
	}
	else
	{
		ContF=TLT;
	}
	ContI=0;
	Limpeza(2,8,80,25);
	if(TLT==0)
	{
		gotoxy(25,8);
		printf("Nada Encontrado!");
	}
	do
	{
		for(int y=8, j=ContI; y<=24 && j<ContF ; y+=2, j++)
		{
			gotoxy(20,y);
			printf("Disciplina: %s\tCodDisc: %d", Termo[j].Disciplina.Disciplina, Termo[j].Disciplina.CodDisc);	
		}	
		if(TLT>9)
		{
			opcao = toupper(getch());
			if(opcao == 'A')
			{
				if(ContI-9 >= 0){
					ContF = ContI;
					ContI-=9;
					Limpeza(2,8,80,25);	

				}				
			}
			if(opcao == 'D')
			{
				if(ContF<TLT)
				{
					ContF = ContF+9;
					if(ContF>TLT)
						ContF-=ContF-TLT;
					ContI+=9;
					Limpeza(2,8,80,25);
				}
				
			}
		}
		
	}while(opcao != 27 && TLT > 9);	

	
}

void RelMediaGeral (TpAlunoDisciplina Geral[], int TLN, TpDisciplina Disciplinas[], int TLD)
{
	int Cont, AuxCodDisc, TLDMG=0, pos, ContF, ContI;
	float Soma;
	char opcao;
	StDiscMG Notas[TFD];
	
	
	for(int i=0;i<TLN;i++)
	{
		AuxCodDisc = Geral[i].CodDisc;
		Cont=0;
		Soma=0;
		for(int j=0;j<TLN;j++)
		{
			if(Geral[j].CodDisc == AuxCodDisc)
			{
				Cont++;
				Soma+=Geral[j].Nota;
			}
		}
		if(Soma/Cont < 6)
		{
			if(!BuscaCodDiscNota(Notas, TLDMG, AuxCodDisc, pos))
			{
				BuscaCodDisc(Disciplinas, TLD, AuxCodDisc, pos);
				Notas[TLDMG].Disciplina.CodDisc = AuxCodDisc;
				strcpy(Notas[TLDMG].Disciplina.Disciplina, Disciplinas[pos].Disciplina);
				TLDMG++;
			}
		}
	}
	
	
	if(TLDMG>9)
	{
		ContF=9;		
	}
	else
	{
		ContF=TLDMG;
	}
	ContI=0;
	Limpeza(2,8,80,25);
	do
	{
		for(int y=8, j=ContI; y<=24 && j<ContF ; y+=2, j++)
		{
			gotoxy(20,y);
			printf("Disciplina: %s\tCodDisc: %d", Notas[j].Disciplina.Disciplina, Notas[j].Disciplina.CodDisc);	
		}	
		if(TLDMG>9)
		{
			opcao = toupper(getch());
			if(opcao == 'A')
			{
				if(ContI-9 >= 0){
					ContF = ContI;
					ContI-=9;
					Limpeza(2,8,80,25);	

				}				
			}
			if(opcao == 'D')
			{
				if(ContF<TLDMG)
				{
					ContF = ContF+9;
					if(ContF>TLDMG)
						ContF-=ContF-TLDMG;
					ContI+=9;
					Limpeza(2,8,80,25);
				}
				
			}
		}
		
	}while(opcao != 27 && TLDMG > 9);
	
}

void RelTodosAlunos (TpDisciplina Disciplinas[], int TLD, TpAluno Alunos[], int TLA, TpAlunoDisciplina Geral[], int TLN)
{
    int i=0, pos, j, y;
    char opcao, Situacao[10];

    do
    {
        if (i<TLA && BuscaRAGeral(Geral, TLN, Alunos[i].RA))
        {
            Limpeza(2, 8, 80, 25);
            y = 10;
            gotoxy(3, y);
            printf("RA: %s\tNome: %s", Alunos[i].RA, Alunos[i].Nome);
            y+=2;

            for (j=0; j < TLN; j++)
            {
                if (strcmp(Alunos[i].RA, Geral[j].RA) == 0)
                {
                    BuscaCodDisc(Disciplinas, TLD, Geral[j].CodDisc, pos);
                    if (Geral[j].Nota >= 6)
                        strcpy(Situacao, "Aprovado");
                    else
                        strcpy(Situacao, "Reprovado");

                    gotoxy(3, y);
                    printf("Disciplina: %d - %s  Nota: %.1f  Situacao: %s", Geral[j].CodDisc, Disciplinas[pos].Disciplina, Geral[j].Nota, Situacao);
                    y++;
                }
            }
        }

        opcao = toupper(getch());

        if (opcao == 'A') 
        {
            int anterior = i-1;
            while (anterior >= 0 && !BuscaRAGeral(Geral, TLN, Alunos[anterior].RA))
                anterior--;

            if (anterior >= 0) 
                i = anterior;
        }

        if (opcao == 'D')
        {
            int proximo = i+1;
            while (proximo < TLA && !BuscaRAGeral(Geral, TLN, Alunos[proximo].RA))
                proximo++;

            if (proximo < TLA)
                i = proximo;
        }

    } while (opcao != 27 && i >= 0 && i < TLA);
}

int main (void)
{	
	int TLA=0, TLD=0, TLN=0, AuxCodDisc, pos;
	float AuxNota;
	char opcao, opcao2, opcao3, AuxNome[20], AuxRA[13], AuxDisc[30], Letra, TermoDisc[30];
	TpAluno Alunos[TFA];
	TpDisciplina Disciplinas[TFD];
	TpAlunoDisciplina Geral[TFA*TFD];
	debug(Geral, Alunos, Disciplinas, TLA, TLD, TLN);
	do 
	{	
		opcao = MenuInicial();
		switch (opcao)
		{
			case 'A':	do
						{
							opcao2 = MenuManutencao();
							switch(opcao2)
							{
								case 'A':	do
											{
												opcao3 = MenuAlunoDisciplinaNota();
												switch(opcao3)
												{
													case 'A':	gotoxy(47,6);
																printf("*** Cadastro Aluno ***");
																gotoxy(40,7);
																LerString(AuxNome, "Nome");
																VerifString(46, 7, AuxNome);
																gotoxy(40,8);
																LerString(AuxRA, "RA");
																VerifString(44, 8, AuxRA);
																gotoxy(40,9);
																if(CadastroAluno(AuxNome, AuxRA, Alunos, TLA, pos))
																	printf("Cadastro Concluido!");
																else
																	printf("Aluno ja Cadastrado!");
																getch();
																break;
														
													case 'B':	gotoxy(47,6);
																printf("*** Cadastro Disciplina ***");
																gotoxy(40,7);
																LerString(AuxDisc, "Disciplina");
																VerifString(52, 7, AuxDisc);
																gotoxy(40,8);
																LerInt(AuxCodDisc, "Cod Disc");
																VerifCodDisc(50,8,AuxCodDisc);
																gotoxy(40,9);
																if(CadastroDisciplina(AuxDisc, AuxCodDisc, Disciplinas, TLD, pos))
																	printf("Cadastro Concluido!");
																else
																	printf("Disciplina ja Cadastrada!");
																getch();
																break;
																
													case 'C':	gotoxy(47,6);
																printf("*** Cadastro Nota ***");
																gotoxy(40,7);
																LerString(AuxRA, "RA");
																VerifString(44, 7, AuxRA);
																ExisteRA(Alunos, TLA, AuxRA, pos);
																gotoxy(40,8);
																printf("                               ");
																gotoxy(40,8);
																LerInt(AuxCodDisc, "Cod Disc");
																VerifCodDisc(50,8,AuxCodDisc);
																ExisteCodDisc2(Disciplinas, TLD, AuxCodDisc, pos);
																gotoxy(40,9);
																printf("                               ");
																gotoxy(40,9);
																LerFloat(AuxNota, "Nota");
																VerifNota(46,9,AuxNota);
																gotoxy(40,10);
																if(CadastroNota(AuxRA, AuxCodDisc, AuxNota, Geral, TLN))
																	printf("Cadastro Concluido!");
																else
																	printf("Nota ja Cadastrada!");
																getch();
																break;
												}
											}while(opcao3 != 27);
											break;
											
								case 'B':	do
											{
												opcao3 = MenuAlunoDisciplinaNota();
												switch(opcao3)
												{
													case 'A':	gotoxy(47,6);
																printf("*** Exclusao Aluno ***");
																if(TLA==0)
																{
																	gotoxy(40,7);
																	printf("Nao ha alunos cadastrados!");
																}
																else
																{
																	gotoxy(40,7);
																	LerString(AuxRA, "RA");
																	VerifString(44, 7, AuxRA);
																	ExisteRA(Alunos, TLA, AuxRA, pos);
																	ExclusaoAluno(AuxRA, Alunos, Geral, TLA, TLN, pos);
																	gotoxy(50,8);
																	printf("                            ");
																	gotoxy(40,8);
																	printf("Exclusao Concluida!");
																}
																getch();
																break;
														
													case 'B':	gotoxy(47,6);
																printf("*** Exclusao Disciplina ***");
																if(TLD==0)
																{
																	gotoxy(40,7);
																	printf("Nao ha Disciplinas cadastradas!");
																}
																else
																{
																	gotoxy(40,7);
																	LerInt(AuxCodDisc, "Cod Disc");
																	VerifCodDisc(50,7,AuxCodDisc);
																	ExisteCodDisc(Disciplinas, TLD, AuxCodDisc, pos);
																	ExclusaoDisc(AuxCodDisc, Disciplinas, Geral, TLD, TLN, pos);
																	gotoxy(50,8);
																	printf("                            ");
																	gotoxy(40,8);
																	printf("Exclusao Concluida!");
																}	
																getch();
																break;
																
													case 'C':	gotoxy(47,6);
																printf("*** Exclusao Nota ***");
																if(TLN==0)
																{
																	gotoxy(40,7);
																	printf("Nao ha Notas Cadastradas!");
																}
																else
																{
																	gotoxy(40,7);
																	LerString(AuxRA, "RA");
																	VerifString(44, 7, AuxRA);
																	gotoxy(40,8);
																	LerInt(AuxCodDisc, "Cod Disc");
																	VerifCodDisc(50,7,AuxCodDisc);
																	ExisteNota(Geral, TLN, AuxRA, AuxCodDisc, pos);
																	ExclusaoNota(AuxRA, AuxCodDisc, Geral, TLN, pos);
																	gotoxy(50,9);
																	printf("                          ");
																	gotoxy(40,9);
																	printf("Exclusao Concluida!");
																}
																getch();
																break;
												}
											}while(opcao3 != 27);
											break;
											
								case 'C':	do
											{
												opcao3 = MenuAlunoDisciplinaNota();
												switch(opcao3)
												{
													case 'A':	gotoxy(47,6);
																printf("*** Editar Aluno ***");
																if(TLA==0)
																{
																	gotoxy(40,7);
																	printf("Nao ha Alunos Cadastrados!");
																}
																else
																{
																	gotoxy(40,7);
																	LerString(AuxRA, "RA");
																	VerifString(44, 7, AuxRA);
																	ExisteRA(Alunos, TLA, AuxRA, pos);
																	gotoxy(47,6);
																	printf("                               ");
																	gotoxy(45,6);
																	printf("*** Editar Aluno: %s ***", Alunos[pos].RA);
																	gotoxy(40,8);
																	printf("                               ");
																	gotoxy(40,7);
																	LerString(AuxNome, "Nome");
																	VerifString(46, 7, AuxNome);
																	gotoxy(40,8);
																	LerString(AuxRA, "RA");
																	VerifString(44, 8, AuxRA);
																	AlteracaoAluno(Alunos, Geral, AuxRA, AuxNome, TLN, pos);
																	gotoxy(40,9);
																	printf("Alteracao Concluida!");
																}
																getch();
																break;
														
													case 'B':	gotoxy(47,6);
																printf("*** Editar Disciplina ***");
																if(TLD==0)
																{
																	gotoxy(40,7);
																	printf("Nao ha Disciplinas Cadastradas!");
																}
																else
																{
																	gotoxy(40,7);
																	LerInt(AuxCodDisc, "Cod Disc");
																	VerifCodDisc(50,7,AuxCodDisc);
																	ExisteCodDisc(Disciplinas, TLD, AuxCodDisc, pos);
																	gotoxy(47,6);
																	printf("                               ");
																	gotoxy(42,6);
																	printf("*** Editar Disciplina: %d ***", Disciplinas[pos].CodDisc);
																	gotoxy(40,8);
																	printf("                               ");
																	gotoxy(40,7);
																	LerString(AuxDisc, "Disciplina");
																	VerifString(52, 7, AuxDisc);
																	gotoxy(40,8);
																	LerInt(AuxCodDisc, "Cod Disc");
																	VerifCodDisc(50,8,AuxCodDisc);
																	AlteracaoDisc(Disciplinas, Geral, AuxCodDisc, AuxDisc, TLN, pos);
																	gotoxy(40,9);
																	printf("Alteracao Concluida!");
																}
																getch();
																break;
													case 'C':	gotoxy(47,6);
																printf("*** Editar Nota ***");
																if(TLN==0)
																{
																	gotoxy(40,7);
																	printf("Nao ha Notas Cadastradas!");
																}
																else
																{
																	int auxpos;
																	gotoxy(40,7);
																	LerString(AuxRA, "RA");
																	VerifString(44, 7, AuxRA);
																	ExisteRA(Alunos, TLA, AuxRA, pos);
																	gotoxy(40,8);
																	printf("                               ");
																	gotoxy(40,8);
																	LerInt(AuxCodDisc, "Cod Disc");
																	VerifCodDisc(50,8,AuxCodDisc);
																	ExisteCodDisc2(Disciplinas, TLD, AuxCodDisc, pos);
																	gotoxy(40,9);
																	printf("                      ");
																	ExisteNota(Geral, TLN, AuxRA, AuxCodDisc, pos);
																	gotoxy(47,6);
																	printf("                     ");
																	gotoxy(39,6);
																	printf("*** Editar Nota: %s/%d ***", Geral[pos].RA, Geral[pos].CodDisc);
																	gotoxy(40,7);
																	printf("                               ");
																	gotoxy(40,8);
																	printf("                               ");
																	gotoxy(40,7);
																	LerString(AuxRA, "RA");
																	VerifString(44, 8, AuxRA);
																	ExisteRA(Alunos, TLA, AuxRA, auxpos);
																	gotoxy(40,8);
																	printf("                               ");
																	gotoxy(40,8);
																	LerInt(AuxCodDisc, "Cod Disc");
																	VerifCodDisc(50,8,AuxCodDisc);
																	ExisteCodDisc2(Disciplinas, TLD, AuxCodDisc, auxpos);
																	gotoxy(40,9);
																	printf("                               ");
																	gotoxy(40,9);
																	LerFloat(AuxNota, "Nota");
																	VerifNota(46,9,AuxNota);
																	AlteracaoNota(Geral, AuxRA, AuxCodDisc, AuxNota, pos);
																	gotoxy(40,10);
																	printf("Alteracao Concluida!");
																}
																getch();
																break;
												}
											}while(opcao3 != 27);
											break;
											
								case 'D':	do
											{
												opcao3 = MenuAlunoDisciplinaNota();
												switch(opcao3)
												{
													case 'A':	gotoxy(47,6);
																printf("*** Consulta Aluno ***");
																if(TLA==0)
																{
																	gotoxy(40,7);
																	printf("Nao ha Alunos Cadastrados!");
																}
																else
																{
																	gotoxy(40,7);
																	LerString(AuxRA, "RA");
																	VerifString(44, 7, AuxRA);
																	ExisteRA(Alunos, TLA, AuxRA, pos);
																	gotoxy(40,8);
																	printf("                               ");
																	gotoxy(47,6);
																	printf("                        ");
																	gotoxy(47,6);
																	printf("*** Dados RA: %s ***", Alunos[pos].RA);
																	gotoxy(40,7);
																	printf("                               ");
																	gotoxy(40,7);
																	printf("Nome: %s", Alunos[pos].Nome);
																	gotoxy(40,8);
																	printf("RA: %s", Alunos[pos].RA);
																	gotoxy(40,9);
																	printf("Consulta Concluida!");
																}
																getch();
																break;
														
													case 'B':	gotoxy(47,6);
																printf("*** Consulta Disciplina ***");
																if(TLD==0)
																{
																	gotoxy(40,7);
																	printf("Nao ha Disciplinas Cadastradas!");
																}
																else
																{
																	gotoxy(40,7);
																	LerInt(AuxCodDisc, "Cod Disc");
																	VerifCodDisc(50,7,AuxCodDisc);
																	ExisteCodDisc(Disciplinas, TLD, AuxCodDisc, pos);
																	gotoxy(40,8);
																	printf("                               ");
																	gotoxy(47,6);
																	printf("                             ");
																	gotoxy(45,6);
																	printf("*** Dados CodDisc: %d ***", Disciplinas[pos].CodDisc);
																	gotoxy(40,7);
																	printf("                               ");
																	gotoxy(40,7);
																	printf("Disciplina: %s", Disciplinas[pos].Disciplina);
																	gotoxy(40,8);
																	printf("CodDisc: %d", Disciplinas[pos].CodDisc);
																	gotoxy(40,9);
																	printf("Consulta Concluida!");
																}
																getch();
																break;
													case 'C':	gotoxy(47,6);
																printf("*** Consulta Nota ***");
																if(TLD==0)
																{
																	gotoxy(40,7);
																	printf("Nao ha Notas Cadastradas!");
																}
																else
																{
																	gotoxy(40,7);
																	LerString(AuxRA, "RA");
																	VerifString(44, 7, AuxRA);
																	gotoxy(40,8);
																	LerInt(AuxCodDisc, "Cod Disc");
																	VerifCodDisc(50,7,AuxCodDisc);
																	ExisteNota(Geral, TLN, AuxRA, AuxCodDisc, pos);
																	gotoxy(40,7);
																	printf("                               ");
																	gotoxy(40,8);
																	printf("                               ");
																	gotoxy(40,9);
																	printf("                               ");
																	gotoxy(47,6);
																	printf("                          ");
																	gotoxy(45,6);
																	printf("*** Dados Nota: %s/%d ***", Geral[pos].RA, Geral[pos].CodDisc);
																	gotoxy(40,7);
																	printf("RA: %s", Geral[pos].RA);
																	gotoxy(40,8);
																	printf("Cod Disc: %d", Geral[pos].CodDisc);
																	gotoxy(40,9);
																	printf("Nota: %.1f", Geral[pos].Nota);
																	gotoxy(40,10);
																	printf("Consulta Concluida!");
																}
																getch();
																break;
												}
											}while(opcao3 != 27);
							}
						}while(opcao2 != 27);
						break;
					
			case 'B':	do
						{
							Limpeza(2,8,80,25);
							opcao2 = MenuRelatorios();
							switch(opcao2)
							{
								case 'A': 	Interface2();
											gotoxy(25,6);
											printf("Alunos Reprovados 2+ disc");
											AvancarVoltar();
											Rel2Rec(Geral, TLN, TLA, Alunos);
											getch();
											break;
											
								case 'B': 	Interface2();
											AvancarVoltar();
											Limpeza(2,8,80,25);
											gotoxy(25,8);
											LerChar(Letra, "Digite uma letra");
											RelAlunoLetra(Alunos, TLA, Letra);
											
											getch();
											break;
											
											
								case 'C':	Interface2();
											gotoxy(25,6);
											printf("Disciplinas por Termo");
											AvancarVoltar();
											Limpeza(2,8,80,25);
											gotoxy(25,8);
											LerString(TermoDisc, "Digite um termo");
											RelTermoDisc(Disciplinas, TLD, TermoDisc);
											getch();
											break;
											
											
								case 'D':	Interface2();
											gotoxy(25,6);
											printf("Disciplinas com MG < 6.0");
											AvancarVoltar();
											Limpeza(2,8,80,25);
											RelMediaGeral(Geral, TLN, Disciplinas, TLD);
											
											getch();
											break;
								
								case 'E':	Interface2();
											gotoxy(25,6);
											printf("Todos os Alunos");
											AvancarVoltar();
											Limpeza(2,8,80,25);
											RelTodosAlunos(Disciplinas, TLD, Alunos, TLA, Geral, TLN);
											
											break;
							}
							
						}while(opcao2 != 27);
			
						
						
		}
	}while(opcao != 27);
	
	return 0;
}

