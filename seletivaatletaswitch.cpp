#include <stdio.h>
#include <stdlib.h>

main () {
	int op,anonasc,idade;
	char nome[20];
	
	do {
	printf ("\t\t\tSeletiva de Atletas\n");
	printf ("\t1-Cadastrar atleta\n");
	printf ("\t2-Categoria\n");
	printf ("\t0-Sair\n");
	scanf ("%d",&op);
	system ("cls");
	
	switch (op){
	case 1:
	printf ("\t\tCadastrar atleta\n");
	printf ("Nome do atleta: ");
	fflush (stdin);
	gets (nome);
	printf ("Ano de Nascimento do Atleta: ");
	scanf ("%d",&anonasc);
	system ("cls");
	     break;	
	
	case 2:
	printf ("\t\tCategoria\n");
	idade = 2016 - anonasc;
	if (idade == 10 or idade <= 14){
			printf ("Infantil");
	}
	else if (idade == 15 or idade <= 16){
		printf ("Juvenil");
	}
	else if (idade == 17 or idade <= 20){
			printf ("Jr. Senior");
	}
	else {
		printf ("Categoria Invalida");
    }
        break;
        
    case 0:
    	exit (0);
    }   
	} while (op != 0);
	
	system ("pause");
}
