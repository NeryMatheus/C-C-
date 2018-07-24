#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

//Declaração de structs
typedef struct Administrador {
	char login[10];
	char senha[10];
	int aux;
} Adm;

typedef struct Avaliador {
	char login[10],senha[10],nome[25];
	int tel;
	int aux;
} Av;


typedef struct Teste {
 char rimc[30],status[15];
 float salt_imp,corrida,natacao,mediabf,mediasis,mediacor,mediant;	
 float barrafixa;
}Ts;

typedef struct Aluno {
 char nome[10],matricula[10];
 int idade,sexo;
 float altura,peso,media,imc;	
 Ts teste;
 
} Al;

typedef struct Barra_Fixa{
float barra_fixa[6];
int aux;	
}Br;

typedef struct Natacao{
    float natacaom[6];
	float natacaof[6];	
}Nt;

typedef struct Salto_Horizontal{
  float salt_hm[6];
  float salt_hf[6];	
}Sh;

typedef struct Corrida{
  float corridam[6];
  float corridaf[6];
	
}Cr;
 
//Declaração de Procedimentos  
void Login();
void Menu_Adm();
void Menu_Avaliador();
void Menu_Aluno();
void Cadastrar_Aluno();
void Listar_Aluno();
void Alterar_Aluno();
void Entrar_Adm();
void Cadastrar_Avaliador();
void Listar_Avaliador();
void Alterar_Avaliador();
void Excluir_Avaliador();
void Sub_Avaliador();
void Sub_Aluno();
void Excluir_Aluno();
void Tabela();
void Relatorios();
void Alterar_Tabela();
void Relatorios();

//Declaração de ponteiros
FILE *pca;
FILE *padm;
FILE *pcav;
FILE *ptsh;
FILE *ptbr;
FILE *ptcr;
FILE *ptnt;

main(){
	Login();
system("pause");
}

void Login(){
	system("color 0c");
	system("cls");             
	printf("\t\t\t\t\t\t\t\t");
	system("time/t");
	printf("\t\t\t\t\t\t\t\t");
	system("date/t");
	system("Title TAF");
	setlocale(LC_ALL,"portuguese");
	
	char loginpesq[10],senhapesq[10],login[10],senha[10];
	int op2=0;
	int aux=0,aux2=0,aux4=0;
	Adm adm;
	Av  dav; 
	Al da; 
    Br br;
	Nt nt;
    Cr cr;
	Sh sh;
	
	ptbr=fopen("Dadobr.txt","ab+");
	rewind(ptbr);
	fread(&br,sizeof(Br),1,ptbr); 
	aux4=br.aux;
	fclose(ptbr);
	
	if(aux4!=1){
		Tabela();
	}	 
	 
	strcpy(login,"adm");
	strcpy(senha,"master");
	
	padm=fopen("Adm.txt","ab+");
	rewind(padm);
	fread(&adm,sizeof(Adm),1,padm);
	aux=adm.aux;
	fclose(padm);

    printf("\n\tLOGIN: ");
    fflush(stdin);
    gets(loginpesq);
    printf("\n\tSENHA: ");
    fflush(stdin);
    gets(senhapesq);
	system("cls");
	
	pcav=fopen("Dadoav.txt","ab+");
	
	if(strlen(loginpesq)>0 && strlen(senhapesq)>0){
	rewind(pcav);
	while(!feof(pcav)){
	fread(&dav,sizeof(Av),1,pcav);
		if(!feof(pcav)){
		if(strcmp(strlwr(loginpesq),strlwr(dav.login))==0 && strcmp(strlwr(senhapesq),strlwr(dav.senha))==0){	
			
			Menu_Avaliador();
			fclose(pcav);	
		}
		}
	}

		pca=fopen("Dadoaluno.txt","ab+");
		rewind(pca);
		while(!feof(pca)){
		fread(&da,sizeof(Al),1,pca);
		if(!feof(pca)){
		if(strcmp(strlwr(loginpesq),strlwr(da.nome))==0 && strcmp(strlwr(senhapesq),strlwr(da.matricula))==0){
		do{
			system("Title MENU ALUNO");
	        printf("\n\t1-DESEMPENHO DO TAF\n\t0-SAIR\n\t");
	        scanf("%i",&op2);
			if(op2==1){
    			system("cls");	
        		printf("\n-------------------------");
				printf("\n\tNOME: %s",da.nome);
				printf("\n\tIDADE: %i",da.idade);
				printf("\n\tSEXO: %i",da.sexo);
				printf("\n\tMATRÍCULA: %s",da.matricula);
				printf("\n\tALTURA: %.2f",da.altura);
				printf("\n\tPESO: %.2f\n",da.peso);
				printf("\n\t\t\t\tTESTE DO ALUNO\n\t");
				printf("\n\tBARRA FIXA: %i",da.teste.barrafixa);
				printf("\n\tSALTO DE IMPULSÃO HORIZONTAL: %.2fm",da.teste.salt_imp);
				printf("\n\tCORRIDA: %.2fm",da.teste.corrida);
				printf("\n\tNATAÇÃO: %.2fseg",da.teste.natacao);
				printf("\n\tPONTUAÇÃO DAS AVALIAÇÕES: %.2f",da.media);
				printf("\n\tSTATUS DO IMC: %s",da.teste.rimc);
				printf("\n\tSTATUS DO ALUNO: %s",da.teste.status);
				printf("\n-------------------------\n\n");	
				system("pause");
				system("cls");
				fclose(pca);
             }else {
             	Login();
			 }
        }while(op2!=0);
		}//fim if condição
		}//fim if feof
		}//fim if while
		
		if(aux!=1){
			if(strcmp(strlwr(loginpesq),strlwr(login))==0 && strcmp(strlwr(senhapesq),strlwr(senha))==0){
				padm=fopen("Adm.txt","ab+");
				system("cls");
				printf("\n\tDIGITE NOVA SENHA E LOGIN PARA ENTRAR:\n");
				printf("\n\tNOVO LOGIN: ");
				fflush(stdin);
				gets(adm.login);
				printf("\n\tNOVA SENHA: ");
				fflush(stdin);
				gets(adm.senha);
				adm.aux=1;
				fwrite(&adm,sizeof(Adm),1,padm);
		        fclose(padm);
		        system("cls");
				Menu_Adm();
			}else{
				printf("\n\tACESSO INVÁLIDO!\n\n");
				system("pause");
			}
		 }else{
			if(strlen(loginpesq)>0 && strlen(senhapesq)>0 ){
			padm=fopen("Adm.txt","ab+");
			if(strcmp(strlwr(loginpesq),strlwr(adm.login))==0 && strcmp(strlwr(senhapesq),strlwr(adm.senha))==0){
				Menu_Adm();
			}else{
			printf("\n\tACESSO INVÁLIDO!");
			system("pause");
			system("cls");
			Login();
			}
			}//fim do segundo strlen
			fclose(padm);
			fclose(pcav);
		} //else do aux	
		}else{
			printf("\n\tDIGITE LOGIN E SENHA PARA ENTRAR!\n");
			system("pause");
			system("cls");
	}//fim do strlen
     Login();
} //fim do void

void Menu_Adm(){	
	Adm adm;
	
	system("cls");             
	printf("\t\t\t\t\t\t\t\t");
	system("time/t");
	printf("\t\t\t\t\t\t\t\t");
	system("date/t");
	
	int op,op2;
	system("Title ADMINISTRADOR");
	setlocale(LC_ALL,"portuguese");
	
	do{
	printf("\n\n\t1-AVALIADOR");
	printf("\n\t2-ALTERAR LOGIN E SENHA");
	printf("\n\t3-TABELAS");
	printf("\n\t4-RELATÓRIOS");
	printf("\n\t0-SAIR\n\t");
	scanf("%i",&op);
	switch(op){
		case 1:
			Sub_Avaliador();
		 	break;
		case 2:
			padm=fopen("Adm.txt","rb");
			system("cls");
			printf("\n\tDIGITE O NOVO LOGIN:");
			fflush(stdin);
			gets(adm.login);
			printf("\n\tDIGITE A NOVA SENHA:");
			fflush(stdin);
			gets(adm.senha);
			adm.aux=1;
			system("cls");
			fwrite(&adm,sizeof(Adm),1,padm);
			fclose(padm);
			Menu_Adm();
			break;
	    case 3:
		    Alterar_Tabela();
			break;
		case 4:
			Relatorios();
			break;
		case 0:
			system("cls");
			Login();
			break;
		default:
		printf("\n\tOPÇÃO INVÁLIDA!");
		system("pause");
		system("cls");		
	}
	}while(op!=0);	
}

void Menu_Avaliador(){
	
	int op,op2;
	system("cls");


    system("cls");             
	printf("\t\t\t\t\t\t\t\t");
	system("time/t");
	printf("\t\t\t\t\t\t\t\t");
	system("date/t");   
   
    system("Title AVALIADOR");
	setlocale(LC_ALL,"portuguese");
	
	printf("\n\n\t1-REALIZAR TESTE\n");
	printf("\n\t2-ALUNOS\n");
	printf("\n\t0-SAIR\n\t");
	scanf("%i",&op);
	switch(op){
		case 1:
			Cadastrar_Aluno();
			break;
		case 2:
			Sub_Aluno();
		    break;	
		case 0:
			Login();
			break;
		default:
			system("cls");
			printf("\n\tOPÇÃO INVÁLIDA!");
			system("pause");
			system("cls");
			Menu_Avaliador();
			break;
	}
	system("pause");
}

void Menu_Aluno(){
	int op;
	Al da;
	
	
	system("cls");             
    printf("\t\t\t\t\t\t\t\t");
    system("time/t");
    printf("\t\t\t\t\t\t\t\t");
    system("date/t");
	
	
	system("Title MENU ALUNO");
	printf("\n\t1-DESEMPENHO DO TAF\n");
	if(op==1){	
		printf("\n-------------------------");
		printf("\n\tNOME: %s",da.nome);
		printf("\n\tIDADE: %i",da.idade);
		printf("\n\tSEXO: %i",da.sexo);
		printf("\n\tMATRÍCULA: %s",da.matricula);
		printf("\n\tALTURA: %.2f",da.altura);
		printf("\n\tPESO: %.2f\n",da.peso);
		printf("\n\t\t\t\tTESTE DO ALUNO\n\t");
		printf("\n\tBARRA FIXA: %.2f",da.teste.barrafixa);
		printf("\n\tSALTO DE IMPULSÃO HORIZONTAL: %.2fm",da.teste.salt_imp);
		printf("\n\tCORRIDA: %.2fm",da.teste.corrida);
		printf("\n\tNATAÇÃO: %.2fseg",da.teste.natacao);
		printf("\n\tPontuação das Avaliações: %.2f",da.media);
		printf("\n\tEstatus do IMC: %s",da.teste.rimc);
		printf("\n\tEstatus do Aluno: %s",da.teste.status);
		printf("\n-------------------------\n\n");	
	}
	system("pause");	
}

void Cadastrar_Aluno(){
	
	Al da;
	Br br;
	Nt nt;
	Cr cr;
	Sh sh;
	
	system("cls");
	system("Title REALIZAR TESTE");
	setlocale(LC_ALL,"portuguese");
	
	pca=fopen("Dadoaluno.txt","ab+");
	
	printf("\n\tNOME: ");
	fflush(stdin);
	gets(da.nome);
	printf("\n\tIDADE: ");
	scanf("%i",&da.idade);
	printf("\n\tSEXO [1-Masculino/2-Feminino]: ");
	scanf("%i",&da.sexo);
	printf("\n\tMATRICULA: ");
	fflush(stdin);
	gets(da.matricula);
	printf("\n\tALTURA: ");
	scanf("%f",&da.altura);
	printf("\n\tPESO: ");
	scanf("%f",&da.peso);
	da.imc = da.peso/(da.altura*da.altura);
	if(da.imc<18.5){
		strcpy(da.teste.rimc,"ABAIXO DO PESO!");
	}else if(da.imc<=24.9){
		strcpy(da.teste.rimc,"PESO IDEAL!");
	}else if(da.imc<=29.9){
		strcpy(da.teste.rimc,"LEVEMENTE ACIMA DO PESO!");
	}else if(da.imc<=34.9){
		strcpy(da.teste.rimc,"OBESIDADE GRA 1!");
	}else if(da.imc<=39.9){
		strcpy(da.teste.rimc,"OBESIDADE GRAU 2!");
	}else if(da.imc>40){
		strcpy(da.teste.rimc,"OBESIDADE GRAU 3!");
	}
	
	ptbr=fopen("Dadobr.txt","ab+");
	rewind(ptbr);
	fwrite(&br,sizeof(Br),1,ptbr);
	system("cls");
	printf("\n\tTESTE DO ALUNO: %s",da.nome);
	fflush(stdin);
	printf("\n\n\t BARA FIXA(quantidade): ");
	fflush(stdin);
	scanf("%f",&da.teste.barrafixa);
	if(da.teste.barrafixa<3){
		da.teste.mediabf=0;
	}else if(da.teste.barrafixa==br.barra_fixa[0]){
		da.teste.mediabf=da.teste.mediabf+2;
	}else if(da.teste.barrafixa<=br.barra_fixa[1]){
		da.teste.mediabf=da.teste.mediabf+3;
	}else if(da.teste.barrafixa<=br.barra_fixa[2]){
		da.teste.mediabf=da.teste.mediabf+4;
	}else if(da.teste.barrafixa<=br.barra_fixa[3]){
		da.teste.mediabf=da.teste.mediabf+5;
	}else if(da.teste.barrafixa<=br.barra_fixa[4]){
		da.teste.mediabf=da.teste.mediabf+6;
	}else if(da.teste.barrafixa>br.barra_fixa[5]){
		da.teste.mediabf=da.teste.mediabf+6;
	}
	fclose(ptbr);
	
	ptsh=fopen("Dadosh.txt","ab+");
	rewind(ptsh);
	fwrite(&sh,sizeof(Sh),1,ptsh);
	
	printf("\n\tSALTO HORIZONTAL(metros): ");
	scanf("%f",&da.teste.salt_imp);
	if(da.sexo==1){
		if(da.teste.salt_imp<sh.salt_hm[0]){
			da.teste.mediasis=0;
		}else if(da.teste.salt_imp<=sh.salt_hm[1]){
			da.teste.mediasis=2;
		}else if(da.teste.salt_imp<=sh.salt_hm[2]){
			da.teste.mediasis=3;
		}else if(da.teste.salt_imp<=sh.salt_hm[3]){
			da.teste.mediasis=4;
		}else if(da.teste.salt_imp<=sh.salt_hm[4]){
			da.teste.mediasis=5;
		}else if(da.teste.salt_imp>sh.salt_hm[4]){
			da.teste.mediasis=6;
		}
		}else{
		if(da.teste.salt_imp<sh.salt_hf[0]){
			da.teste.mediasis=0;
		}else if(da.teste.salt_imp<=sh.salt_hf[1]){
			da.teste.mediasis=2;
		}else if(da.teste.salt_imp<=sh.salt_hf[2]){
			da.teste.mediasis=3;
		}else if(da.teste.salt_imp<=sh.salt_hf[3]){
			da.teste.mediasis=4;
		}else if(da.teste.salt_imp<=sh.salt_hf[4]){
			da.teste.mediasis=5;
		}else if(da.teste.salt_imp>sh.salt_hf[4]){
			da.teste.mediasis=6;
		}
	}
	fclose(ptsh);
	
	ptcr=fopen("Dadocr.txt","ab+");
	rewind(ptcr);
	fwrite(&cr,sizeof(Cr),1,ptcr);
	
	printf("\n\tDISTÂNCIA DA CORRIDA(metros): ");
	scanf("%f",&da.teste.corrida);
	if(da.sexo==1){
		if(da.teste.corrida<cr.corridam[0]){
			da.teste.mediacor=0;
		}else if(da.teste.corrida<cr.corridam[1]){
			da.teste.mediacor=2;
		}else if(da.teste.corrida<cr.corridam[2]){
			da.teste.mediacor=3;
		}else if(da.teste.corrida<cr.corridam[3]){
			da.teste.mediacor=4;
		}else if(da.teste.corrida<cr.corridam[4]){
			da.teste.mediacor=5;
		}else if(da.teste.corrida>cr.corridam[4]){
			da.teste.mediacor=6;
		}		
	} else {
		if(da.teste.corrida<cr.corridaf[0]){
			da.teste.mediacor=2;
		}else if(da.teste.corrida<=cr.corridaf[1]){
			da.teste.mediacor=3;
		}else if(da.teste.corrida<=cr.corridaf[2]){
			da.teste.mediacor=4;
		}else if(da.teste.corrida<=cr.corridaf[3]){
			da.teste.mediacor=5;
		}else if(da.teste.corrida<cr.corridaf[4]){
			da.teste.mediacor=6;
		}else if(da.teste.corrida>cr.corridaf[4]){
			da.teste.mediacor=6;
		}
		}
	fclose(ptcr);
	
	ptnt=fopen("Dadont.txt","ab+");
	rewind(ptnt);
	fwrite(&nt,sizeof(Nt),1,ptnt);
	
	printf("\n\tNATAÇÃO EM 50m(segundos): ");
	scanf("%f",&da.teste.natacao);
	if(da.sexo==1){
		if(da.teste.natacao<=nt.natacaom[0]){
			da.teste.mediant=6;
		}else if(da.teste.natacao<=nt.natacaom[1]){
			da.teste.mediant=5;
		}else if(da.teste.natacao<=nt.natacaom[2]){
			da.teste.mediant=3;
		}else if(da.teste.natacao<=nt.natacaom[3]){
			da.teste.mediant=2;
		}else if(da.teste.natacao>nt.natacaom[4]){
			da.teste.mediant=0;
		}		
	} else {
		if(da.teste.natacao<nt.natacaof[0]){
			da.teste.mediant=6;
		}else if(da.teste.natacao<=nt.natacaof[1]){
			da.teste.mediant=5;
		}else if(da.teste.natacao<=nt.natacaof[2]){
			da.teste.mediant=4;
		}else if(da.teste.natacao<=nt.natacaof[3]){
			da.teste.mediant=3;
		}else if(da.teste.natacao<=nt.natacaof[4]){
			da.teste.mediant=2;
		}else if(da.teste.natacao>nt.natacaof[4]){
			da.teste.mediant=0;
		}		
	}
	fclose(ptnt);
	
	da.media=(da.teste.mediabf+da.teste.mediacor+da.teste.mediant+da.teste.mediasis)/4;
	if(da.media<2){
	strcpy(da.teste.status,"REPROVADO!");
	}else{
		strcpy(da.teste.status,"APROVADO!");
	}
	
	system("cls");
	printf("\n\tTESTE REALIZADO COM SUCESSO!\n\n");
	system("pause");
	system("cls");
	fwrite(&da,sizeof(Al),1,pca);	
	fclose(pca);	
	system("cls");
	Menu_Avaliador();
}

void Listar_Aluno(){
	Al da;
		
	system("cls");
	system("Title Listar");
	setlocale(LC_ALL,"portuguese");	
	pca=fopen("Dadoaluno.txt","rb+");
	rewind(pca);
	while(!feof(pca)){
	fread(&da,sizeof(Al),1,pca);
	if(!feof(pca)){
		printf("\n-------------------------");
		printf("\n\tNOME: %s",da.nome);
		printf("\n\tIDADE: %i",da.idade);
		printf("\n\tMATRÍCULA: %s",da.matricula);
		printf("\n\tALTURA: %.2f",da.altura);
		printf("\n\tPESO: %.2f\n",da.peso);
		printf("\n\t\t\t\tTESTE DO ALUNO\n\t");
		printf("\n\tBARRA FIXA: %.2f",da.teste.barrafixa);
		printf("\n\tSALTO DE IMPULSÃO HORIZONTAL: %.2fm",da.teste.salt_imp);
		printf("\n\tCORRIDA: %.2fm",da.teste.corrida);
		printf("\n\tNATAÇÃO: %.2fseg",da.teste.natacao);
		printf("\n\tPONTUAÇÃO DAS AVALIAÇÕES: %.2f",da.media);
		printf("\n\tSTATUS IMC: %s",da.teste.rimc);
		printf("\n\tSTATUS DO ALUNO: %s",da.teste.status);
		printf("\n-------------------------\n\n");
	}
	}//Fim while
	system("pause");
	fclose(pca);
	Sub_Aluno();
}

void Alterar_Aluno(){
	char nomepesq[10];
	int aux1=0,esc3=0,i=0,op1=0;
	Al da;
	
	system("cls");
	system("Title Alterar");
	setlocale(LC_ALL,"portuguese");
	pca=fopen("Dadoaluno.txt","rb+");
	printf("\n\tDIGITE O NOME DO ALUNO: ");
	fflush(stdin);
	gets(nomepesq);
	system("cls");
	while(!feof(pca)){
		fread(&da,sizeof(Al),1,pca);
		if(!feof(pca)){
			if(strcmp(strlwr(nomepesq),strlwr(da.nome))==0){
	         aux1=1;
				system("Title ALTERAR DADOS DO ALUNO");
				
				printf("\n\t1-NOME: %s",da.nome);
				printf("\n\t2-IDADE: %i",da.idade);
				printf("\n\t4-MATRICULA: %s",da.matricula);
				printf("\n\t5-ALTURA: %.2f",da.altura);
				printf("\n\t6-PESO: %.2f\n",da.peso);
				printf("\n\t\t\t\tTESTE DO ALUNO\n\t");
				printf("\n\t7-BARRA FIXA: %.2f",da.teste.barrafixa);
				printf("\n\t8-SALTO DE IMPULSÃO HORIZONTAL: %.2f",da.teste.salt_imp);
				printf("\n\t9-CORRIDA: %.2f",da.teste.corrida);
				printf("\n\t10-NATAÇÃO: %.2f\n",da.teste.natacao);
				printf("\n\t11-ALTERAR TUDO\n");
				
				printf("\n\tDIGITE O DADO A SER ALTERADO: ");
				scanf("%i",&esc3);
				system("cls");
					
				switch(esc3){
					
				case 1:
					printf("\n\tDADO ESCOLHIDO: NOME\n");
					printf("\n\tDIGITE O NOVO NOME: ");
					fflush(stdin);
					gets(da.nome);
					aux1=1;
				    break;
				case 2:
					printf("\n\tDADO ESCOLHIDO: IDADE\n");
					printf("\n\t DIGITE A NOVA IDADE: ");
					scanf("%i",&da.idade);
					aux1=1;	
				break;
				case 3:
					printf("\n\tDADO ESCOLHIDO: SEXO\n");
					printf("\n\tDIGITE O NOVO SEXO: ");
					scanf("%i",&da.sexo);
					aux1=1;
				    break;
			    case 4:
					printf("\n\tDADO ESCOLHIDO: MATRICULA\n");
					printf("\n\tDIGITE A NOVA MATRICULA: ");
					fflush(stdin);
					gets(da.matricula);
					aux1=1;
			        break;
				case 5:
					printf("\n\tDADO ESCOLHIDO: ALTURA\n");
					printf("\n\tDIGITE A NOVA ALTURA: ");
					scanf("%f",&da.altura);
					da.imc = da.peso/(da.altura*da.altura);
					if(da.imc<18.5){
					strcpy(da.teste.rimc,"ABAIXO DO PESO!");
					}else if(da.imc<=24.9){
					strcpy(da.teste.rimc,"PESO IDEAL!");
					}else if(da.imc<=29.9){
					strcpy(da.teste.rimc,"LEVEMENTE ACIMA DO PESO!");
					}else if(da.imc<=34.9){
					strcpy(da.teste.rimc,"OBESIDADE GRA 1!");
					}else if(da.imc<=39.9){
					strcpy(da.teste.rimc,"OBESIDADE GRAU 2!");
					}else if(da.imc>40){
					strcpy(da.teste.rimc,"OBESIDADE GRAU 3!");
					}
					aux1=1;
				    break;
				case 6:
					printf("\n\tDADO ESCOLHIDO: PESO\n");
					printf("\n\tDIGITE O NOVO PESO: ");
					scanf("%f",&da.peso);
					da.imc = da.peso/(da.altura*da.altura);
					if(da.imc<18.5){
					strcpy(da.teste.rimc,"ABAIXO DO PESO!");
					}else if(da.imc<=24.9){
					strcpy(da.teste.rimc,"PESO IDEAL!");
					}else if(da.imc<=29.9){
					strcpy(da.teste.rimc,"LEVEMENTE ACIMA DO PESO!");
					}else if(da.imc<=34.9){
					strcpy(da.teste.rimc,"OBESIDADE GRA 1!");
					}else if(da.imc<=39.9){
					strcpy(da.teste.rimc,"OBESIDADE GRAU 2!");
					}else if(da.imc>40){
					strcpy(da.teste.rimc,"OBESIDADE GRAU 3!");
					}
					aux1=1;
				    break;
				    
				case 7:
					printf("\n\tDADO ESCOLHIDO: BARRA FIXA\n");
					printf("\n\tDIGITE O NOVO VALOR: ");
					scanf("%f",&da.teste.barrafixa);
					if(da.teste.barrafixa<3){
						da.teste.mediabf=0;
					}else if(da.teste.barrafixa==3){
						da.teste.mediabf=da.teste.mediabf+2;
					}else if(da.teste.barrafixa<=6){
						da.teste.mediabf=da.teste.mediabf+3;
					}else if(da.teste.barrafixa<=9){
						da.teste.mediabf=da.teste.mediabf+4;
					}else if(da.teste.barrafixa<=12){
						da.teste.mediabf=da.teste.mediabf+5;
					}else if(da.teste.barrafixa<=15){
						da.teste.mediabf=da.teste.mediabf+6;
					}else if(da.teste.barrafixa>15){
						da.teste.mediabf=da.teste.mediabf+6;
					}
					aux1=1;
				    break;
				    
				case 8:
					printf("\n\tDADO ESCOLHIDO: SALTO DE IMPULSÃO HORIZONTAL\n");
					printf("\n\tDIGITE O NOVO VALOR: ");
					scanf("%f",&da.teste.salt_imp);
					if(da.sexo==1){
						if(da.teste.salt_imp<2.14){
							da.teste.mediasis=0;
						}else if(da.teste.salt_imp<=2.22){
							da.teste.mediasis=2;
						}else if(da.teste.salt_imp<=2.30){
							da.teste.mediasis=3;
						}else if(da.teste.salt_imp<=2.38){
							da.teste.mediasis=4;
						}else if(da.teste.salt_imp<=2.45){
							da.teste.mediasis=5;
						}else if(da.teste.salt_imp>2.45){
							da.teste.mediasis=6;
						}
					}else{
						if(da.teste.salt_imp<1.66){
							da.teste.mediasis=0;
						}else if(da.teste.salt_imp<=1.74){
							da.teste.mediasis=2;
						}else if(da.teste.salt_imp<=1.82){
							da.teste.mediasis=3;
						}else if(da.teste.salt_imp<=1.90){
							da.teste.mediasis=4;
						}else if(da.teste.salt_imp<=1.97){
							da.teste.mediasis=5;
						}else if(da.teste.salt_imp>1.97){
							da.teste.mediasis=6;
						}
					}
					aux1=1;
				    break;
				
				case 9:
					printf("\n\tDADO ESCOLHIDO: CORRIDA\n");
					printf("\n\tDIGITE O NOVO VALOR: ");
					scanf("%f",&da.teste.corrida);
					if(da.sexo==1){
						if(da.teste.corrida<2.350){
							da.teste.mediacor=0;
						}else if(da.teste.corrida<2.440){
							da.teste.mediacor=2;
						}else if(da.teste.corrida<2.530){
							da.teste.mediacor=3;
						}else if(da.teste.corrida<2.620){
							da.teste.mediacor=4;
						}else if(da.teste.corrida<2.710){
							da.teste.mediacor=5;
						}else if(da.teste.corrida>2.700){
							da.teste.mediacor=6;
						}		
					}else {
						if(da.teste.corrida<2.020){
							da.teste.mediacor=2;
						}else if(da.teste.corrida<=2.100){
							da.teste.mediacor=3;
						}else if(da.teste.corrida<=2.180){
							da.teste.mediacor=4;
						}else if(da.teste.corrida<=2.260){
							da.teste.mediacor=5;
						}else if(da.teste.corrida<2.340){
							da.teste.mediacor=6;
						}else if(da.teste.corrida>2.340){
							da.teste.mediacor=6;
						}
					}
					aux1=1;
				    break;
				    
				case 10:
					printf("\n\tDADO ESCOLHIDO: NATAÇÃO\n");
					printf("\n\tDIGITE O NOVO VALOR: ");
					scanf("%f",&da.teste.natacao);
					if(da.sexo==1){
						if(da.teste.natacao<=29){
							da.teste.mediant=6;
						}else if(da.teste.natacao<=32){
							da.teste.mediant=5;
						}else if(da.teste.natacao<=35){
							da.teste.mediant=3;
						}else if(da.teste.natacao<=42){
							da.teste.mediant=2;
						}else if(da.teste.natacao>42){
							da.teste.mediant=0;
						}		
					}else{
						if(da.teste.natacao<35){
							da.teste.mediant=6;
						}else if(da.teste.natacao<=39){
							da.teste.mediant=5;
						}else if(da.teste.natacao<=43){
							da.teste.mediant=4;
						}else if(da.teste.natacao<=47){
							da.teste.mediant=3;
						}else if(da.teste.natacao<=52){
							da.teste.mediant=2;
						}else if(da.teste.natacao>52){
							da.teste.mediant=0;
						}		
						}
					aux1=1;
				    break;
				    
				case 11:
					printf("Dado Escolhido: Alterar todos\n");
					printf("\n\tDIGITE O NOVO NOME: ");
					fflush(stdin);
					gets(da.nome);
					printf("\n\tDIGITE A NOVA IDADE: ");
					scanf("%i",&da.idade);
					printf("\n\tDIGITE O NOVO SEXO: ");
					scanf("%i",&da.sexo);
					printf("\n\tDIGITE A NOVA MATRICULA: ");
					fflush(stdin);
					gets(da.matricula);
					printf("\n\tDIGITE A NOVA ALTURA: ");
					scanf("%f",&da.altura);
					printf("\n\tDIGITE O NOVO PESO: ");
					scanf("%f",&da.peso);
					
				    printf("\n\t\t\t\tTESTE DO ALUNO\n\t");
					printf("\n\tDIGITE O NOVO VALOR DA BARRA FIXA: ");
					scanf("%f",&da.teste.barrafixa);
					if(da.teste.barrafixa<3){
						da.teste.mediabf=0;
					}else if(da.teste.barrafixa==3){
						da.teste.mediabf=da.teste.mediabf+2;
					}else if(da.teste.barrafixa<=6){
						da.teste.mediabf=da.teste.mediabf+3;
					}else if(da.teste.barrafixa<=9){
						da.teste.mediabf=da.teste.mediabf+4;
					}else if(da.teste.barrafixa<=12){
						da.teste.mediabf=da.teste.mediabf+5;
					}else if(da.teste.barrafixa<=15){
						da.teste.mediabf=da.teste.mediabf+6;
					}else if(da.teste.barrafixa>15){
						da.teste.mediabf=da.teste.mediabf+6;
					}
					
					printf("\n\tDIGITE O NOVO VALOR DO SALTO HORIZONTAL: ");
					scanf("%f",&da.teste.salt_imp);
					if(da.sexo==1){
						if(da.teste.salt_imp<2.14){
							da.teste.mediasis=0;
						}else if(da.teste.salt_imp<=2.22){
							da.teste.mediasis=2;
						}else if(da.teste.salt_imp<=2.30){
							da.teste.mediasis=3;
						}else if(da.teste.salt_imp<=2.38){
							da.teste.mediasis=4;
						}else if(da.teste.salt_imp<=2.45){
							da.teste.mediasis=5;
						}else if(da.teste.salt_imp>2.45){
							da.teste.mediasis=6;
						}
					}else{
						if(da.teste.salt_imp<1.66){
							da.teste.mediasis=0;
						}else if(da.teste.salt_imp<=1.74){
							da.teste.mediasis=2;
						}else if(da.teste.salt_imp<=1.82){
							da.teste.mediasis=3;
						}else if(da.teste.salt_imp<=1.90){
							da.teste.mediasis=4;
						}else if(da.teste.salt_imp<=1.97){
							da.teste.mediasis=5;
						}else if(da.teste.salt_imp>1.97){
							da.teste.mediasis=6;
						}
					}
					
					printf("\n\tDIGITE O NOVO VALOR DA CORRIDA: ");
					scanf("%f",&da.teste.corrida);
					if(da.sexo==1){
						if(da.teste.corrida<2.350){
							da.teste.mediacor=0;
						}else if(da.teste.corrida<2.440){
							da.teste.mediacor=2;
						}else if(da.teste.corrida<2.530){
							da.teste.mediacor=3;
						}else if(da.teste.corrida<2.620){
							da.teste.mediacor=4;
						}else if(da.teste.corrida<2.710){
							da.teste.mediacor=5;
						}else if(da.teste.corrida>2.700){
							da.teste.mediacor=6;
						}		
					}else {
						if(da.teste.corrida<2.020){
							da.teste.mediacor=2;
						}else if(da.teste.corrida<=2.100){
							da.teste.mediacor=3;
						}else if(da.teste.corrida<=2.180){
							da.teste.mediacor=4;
						}else if(da.teste.corrida<=2.260){
							da.teste.mediacor=5;
						}else if(da.teste.corrida<2.340){
							da.teste.mediacor=6;
						}else if(da.teste.corrida>2.340){
							da.teste.mediacor=6;
						}
					}
					
					printf("\n\tDIGITE O NOVO VALOR DA NATAÇÃO: ");
					scanf("%f",&da.teste.natacao);
					if(da.sexo==1){
						if(da.teste.natacao<=29){
							da.teste.mediant=6;
						}else if(da.teste.natacao<=32){
							da.teste.mediant=5;
						}else if(da.teste.natacao<=35){
							da.teste.mediant=3;
						}else if(da.teste.natacao<=42){
							da.teste.mediant=2;
						}else if(da.teste.natacao>42){
							da.teste.mediant=0;
						}		
					}else{
						if(da.teste.natacao<35){
							da.teste.mediant=6;
						}else if(da.teste.natacao<=39){
							da.teste.mediant=5;
						}else if(da.teste.natacao<=43){
							da.teste.mediant=4;
						}else if(da.teste.natacao<=47){
							da.teste.mediant=3;
						}else if(da.teste.natacao<=52){
							da.teste.mediant=2;
						}else if(da.teste.natacao>52){
							da.teste.mediant=0;
						}		
						}
					da.imc = da.peso/(da.altura*da.altura);
					aux1=1;
                    break;	
	
					default:
						printf("\n\tOPÇÃO INVÁLIDA!\n\n");
				     break;
	             }
				
					if(aux1==1){
					system("cls");
					printf("\n\tALTERADO COM SUCESSO!.\n\n");
					system("pause");
				     }
			    fseek(pca,i*sizeof(Al),SEEK_SET);
			    da.media=(da.teste.mediabf+da.teste.mediasis+da.teste.mediacor+da.teste.mediant)/4;
			    if(da.media<2){
					strcpy(da.teste.status,"REPROVADO!");
				}else {
					strcpy(da.teste.status,"APROVADO!");
				}
				fwrite(&da,sizeof(Al),1,pca);
				break;
				}	
				i++;	
		} //if fof	  
	}//fim while
	
	    if(aux1==0)   {
			system("cls");
			printf("\n\tCADASTRO NÃO ENCONTRADO!!\n\n");
			system("pause");
			system("cls");
			Menu_Avaliador();
			}
			
			system("cls");
	 		printf("\n\tDESEJA CONTINUAR ALTERANDO?\n\t[1-Sim/0-Não]: \n\t");
	 		scanf("%i",&op1);
	 		system("cls");
		if(op1==1){
		system("cls");
		fclose(pca);
		Alterar_Aluno();
	 }
	fclose(pca);
	Sub_Aluno();
}//fim void alterar

void Cadastrar_Avaliador(){
	int op=0;
	
	Av dav;
	
	system("cls");
	system("Title Cadastro de Avaliador");
	setlocale(LC_ALL,"portuguese");
	pcav=fopen("Dadoav.txt","ab+");
	do{
	system("cls");
	printf("\n\tNOME: ");
	fflush(stdin);
	gets(dav.nome);
	printf("\n\tLOGIN: ");
	fflush(stdin);
	gets(dav.login);
	printf("\n\tSENHA: ");
	fflush(stdin);
	gets(dav.senha);
	printf("\n\tTELEFONE: ");
	scanf("%i",&dav.tel);
	fwrite(&dav,sizeof(Av),1,pcav);
	printf("\n\tDESEJA CONTINUAR CADASTRANDO AVALIADOR? \n\t[1-Sim/0-Não]: \n\t");
	scanf("%i",&op);
	system("cls");
	}while(op!=0);
	fclose(pcav);
	Sub_Avaliador();
}//fim void cadastro av

void Listar_Avaliador(){
	
	char nomepesq[25];
	int aux=0,op=0;
	Av dav;
	
	system("cls");
	system("Title LISTAR AVALIADOR");
	setlocale(LC_ALL,"portuguese");
	pcav=fopen("Dadoav.txt","rb");
	
	rewind(pcav);
	while(!feof(pcav)){
	fread(&dav,sizeof(Av),1,pcav);
	if(!feof(pcav)){
	    printf("---------------");
		printf("\n\tNOME: %s\n",dav.nome);
		printf("\n\tLOGIN: %s\n",dav.login);
		printf("\n\tSENHA: %s\n",dav.senha);
		printf("\n\tTELEFONE: %i\n\n",dav.tel);
		printf("---------------");
		aux++;

	}//fim if feof
	}//fim while
	system("pause");
	if(aux==0){
		system("cls");
		printf("\n\t\t\tCADASTRO NÃO ENCONTRADO!\n\n");
		system("pause");
	}
		fclose(pcav);
		Sub_Avaliador();
}//fim void pesquisar avaliador

void Alterar_Avaliador(){
	char nome[25];
	int esc=0,aux=0,i=0,op1=0;
	
	Av dav;
	
	system("cls");
	system("Title Alterar Avaliador");
	setlocale(LC_ALL,"portuguese");
	pcav=fopen("Dadoav.txt","rb+");
	printf("\n\tNOME PARA ALTERAR: ");
	fflush(stdin);
	gets(nome);
	
	while(!feof(pcav)){
	fread(&dav,sizeof(Av),1,pcav);
	if(!feof(pcav)){
	if(strcmp(strupr(nome),strupr(dav.nome))==0){
		system("cls");
		system("Title Alterando...");
		aux==1;
		printf("\n\tQUAL ITEM DESEJA ALTERAR?\n");
		printf("\n\t1-NOME: %s\n",dav.nome);
		printf("\n\t2-LOGIN: %s\n",dav.login);
		printf("\n\t3-SENHA: %s\n",dav.senha);
		printf("\n\t4-TELEFONE: %i\n",dav.tel);
		printf("\n\t5-ALTERAR TUDO:\n\t ");
		scanf("%i",&esc);
		system("cls");
		
	switch(esc){
	case 1:{
		printf("\n\tNOME: %s\n",dav.nome);
		printf("\n\tDIGITE O NOVO NOME: ");
		fflush(stdin);
		gets(dav.nome);
		aux=1;
		system("cls");
		break;
	}
	case 2:{
		printf("\n\tLOGIN: %s\n",dav.login);
		printf("\n\tDIGITE O NOVO LOGIN: ");
		fflush(stdin);
		gets(dav.login);
		aux=1;
		system("cls");
		break;
	}
	case 3:{
		printf("\n\tSENHA: %s\n",dav.senha);
		printf("\n\tDIGITE NOVA SENHA: ");
		fflush(stdin);
		gets(dav.senha);
		aux=1;
		system("cls");
		break;
	}
	case 4:{
		printf("\n\tTELEFONE: %i\n",dav.tel);
		printf("\n\tDIGITE NOVO TELEFONE: ");
		scanf("%i",&dav.tel);
		aux=1;
		system("cls");
		break;
	}
	case 5:{
		printf("\t\tALTERAR TODOS\n\n");
		printf("\n\tNOME: ");
		fflush(stdin);
		gets(dav.nome);
		printf("\n\tLOGIN: ");
		fflush(stdin);
		gets(dav.login);
		printf("\n\tSENHA: ");
		fflush(stdin);
		gets(dav.senha);
		printf("\n\tTELEFONE: ");
		scanf("%i",&dav.tel);
		aux=1;
		system("cls");
		break;
	}
	default:{
		printf("\n\tOPÇÃO INVÁLIDA!\n\n");
		system("pause");
		system("cls");
		break;
	}
	}//fim switch
	
	if(aux==1){
		printf("\n\tALTERADO COM SUCESSO!\n\n");
		system("pause");
		system("cls");

	}//fim if aux
	fseek(pcav,i*sizeof(Av),SEEK_SET);
	fwrite(&dav,sizeof(Av),1,pcav);
	break;
	}//fim if condição
	i++;
	}//fim if feof
	}//fim while
	if(aux==0){
	system("cls");
	printf("\n\tCADASTRO NÃO ENCONTRADO\n\n");
	system("pause");	
	}
	 system("cls");
	 printf("\n\tDESEJA CONTINUAR ALTERANDO?\n\t[1-Sim/0-Não]: \n\t");
	 scanf("%i",&op1);
	 system("cls");
	 if(op1==1){
	 	system("cls");
		Alterar_Avaliador();
	 }
		fclose(pcav);
		Sub_Avaliador();
}

void Excluir_Avaliador(){
	char nome[25];
	int i=0,aux=0;
	Av dav, *Vetav;
	
	system("cls");
	system("Title Excluir Avaliador");
	setlocale(LC_ALL,"portuguese");
	Vetav = (Av *)malloc (500*sizeof(Av));
	pcav=fopen("Dadoav.txt","rb+");
	printf("\n\tDIGITE O NOME QUE DESEJA EXCLUIR: ");
	fflush(stdin);
	gets(nome);
	rewind(pcav);
	
	while(!feof(pcav)){
	fread(&dav,sizeof(Av),1,pcav);
	if(!feof(pcav)){
	if(strcmp(strupr(nome),strupr(dav.nome))==0){
		system("cls");
		printf("\n\tAVALIADOR EXCLUIDO COM SUCESSO!\n");
		system("pause");
		system("cls");
		aux=1;
	}else{
		strcpy(Vetav[i].nome,dav.nome);
		strcpy(Vetav[i].login,dav.login);
		strcpy(Vetav[i].senha,dav.senha);
		Vetav[i].tel=dav.tel;
	i++;
	}//fim if condição
	}//fim if feof
	}//fim while
	fclose(pcav);
	pcav=fopen("dadoav.txt","wb");
	fwrite(Vetav,sizeof(Av),i,pcav);
	fclose(pcav);
	free(Vetav);
	if(aux==0){
		system("cls");
		printf("\n\tUSUÁRIO NÃO ENCONTRADO!\n\n");
		system("pause");
		system("cls");
	}
	Menu_Adm();
}//fim excluir avaliador

void Sub_Avaliador(){
       	 
		int op2;
	
		system("Title GERENCIAR AVALIADORES");
		setlocale(LC_ALL,"portuguese");
		
		system("cls");	
        printf("\n\n\n\t1-CADASTRAR AVALIADOR");
	    printf("\n\t2-LISTAR AVALIADORES");
	    printf("\n\t3-ALTERAR DADOS DO AVALIADOR");
	    printf("\n\t4-EXCLUIR AVALIADOR");
	    printf("\n\t5-VOLTAR AO MENU DO ADM\n\t");
		scanf("%i",&op2);
		system("cls");
			switch(op2){
				case 1:
					Cadastrar_Avaliador();
					break;
				case 2:
					Listar_Avaliador();
					break;
				case 3:
					Alterar_Avaliador();
					break;
				case 4:
					Excluir_Avaliador();
					break;
				case 5:
					Menu_Adm();
					break;
				default:
				system("cls");	
				printf("\n\tOPÇÃO INVÁLIDA!");
				system("pause");
				system("cls");	
			}
}

void Sub_Aluno(){

            int op20;
            
			system("Title MONITORAR ALUNOS");
	        setlocale(LC_ALL,"portuguese");
			do{
			system("cls");
			printf("\n\n\t1-ALTERAR ALUNO\n");
			printf("\n\t2-LISTAR ALUNOS\n");
			printf("\n\t3-EXCLUIR ALUNO\n\t");
			printf("\n\t0-VOLTAR AO MENU PRINCIPAL\n\t");
			scanf("%i",&op20);
			
			switch(op20){
				case 1:
					Alterar_Aluno();
					break;
				case 2:
					Listar_Aluno();
					break;
				case 3:
					Excluir_Aluno();
				    break;
				case 0:
				    Menu_Avaliador();
				default:{
					system("cls");
					printf("Opção Inválida\n");
					system("pause");
					break;
				}
			}
			}while(op20!=0);

}

	void Excluir_Aluno(){
	char nome[25];
	int i=0,aux=0;
	Al da, *Vetal;
	
	system("cls");
	system("Title EXCLUIR ALUNO");
	setlocale(LC_ALL,"portuguese");
	Vetal = (Al *)malloc (1000*sizeof(Al));
	pca=fopen("Dadoaluno.txt","rb+");
	printf("\n\tDIGITE O NOME QUE DESEJA EXCLUIR: ");
	fflush(stdin);
	gets(nome);
	rewind(pca);
	
	while(!feof(pca)){
	fread(&da,sizeof(Al),1,pca);
	if(!feof(pca)){
	if(strcmp(strupr(nome),strupr(da.nome))==0){
		system("cls");
		printf("\n\t\tALUNO EXCLUIDO\n");
		system("pause");
		aux=1;
	}else{
		strcpy(Vetal[i].nome,da.nome);
		Vetal[i].idade = da.idade;
		strcpy(Vetal[i].matricula,da.matricula);
		Vetal[i].sexo = da.sexo;
		Vetal[i].altura = da.altura;
		Vetal[i].peso = da.peso;
		Vetal[i].media = da.media;
		Vetal[i].teste.barrafixa = da.teste.barrafixa;
		Vetal[i].teste.salt_imp = da.teste.salt_imp;
		Vetal[i].teste.corrida = da.teste.corrida;
		Vetal[i].teste.natacao = da.teste.natacao;
		strcpy(Vetal[i].teste.rimc,da.teste.rimc);
		strcpy(Vetal[i].teste.status,da.teste.status);
	i++;
	}//fim if condição
	}//fim if feof
	}//fim while
	fclose(pca);
	pca=fopen("dadoaluno.txt","wb+");
	fwrite(Vetal,sizeof(Al),i,pca);
	fclose(pca);
	free(Vetal);
	if(aux==0){
		system("cls");
		printf("\n\t\tUSUÁRIO NÃO ENCONTRADO!\n");
		system("pause");
	}
	Sub_Aluno();
}

void Tabela(){
	
	
	Br br;
	Nt nt;
	Cr cr;
	Sh sh;
	
	ptbr=fopen("Dadobr.txt","ab+");
	br.barra_fixa[0]=3;
	br.barra_fixa[1]=6;
	br.barra_fixa[2]=9;
	br.barra_fixa[3]=12;
	br.barra_fixa[4]=15;
	br.aux=1;
	fwrite(&br,sizeof(Br),1,ptbr);
	fclose(ptbr);
	
	ptcr=fopen("Dadocr.txt","ab+");
	cr.corridam[0]=2.350;
	cr.corridam[1]=2.440;
	cr.corridam[2]=2.530;
	cr.corridam[3]=2.620;
	cr.corridam[4]=2.710;
	
	cr.corridaf[0]=2.020;
	cr.corridaf[1]=2.100;
	cr.corridaf[2]=2.180;
	cr.corridaf[3]=2.260;
	cr.corridaf[4]=2.340;
	
	fwrite(&cr,sizeof(Cr),1,ptcr);
	fclose(ptcr);
	
	ptnt=fopen("Dadont.txt","ab+");
	nt.natacaom[0]=29.0;
	nt.natacaom[1]=32.0;
	nt.natacaom[2]=35.0;
    nt.natacaom[3]=38.0;
	nt.natacaom[4]=42.0;
	
	nt.natacaof[0]=35.0;
	nt.natacaof[1]=39.0;
	nt.natacaof[2]=43.0;
	nt.natacaof[3]=47.0;
	nt.natacaof[4]=52.0;
	fwrite(&nt,sizeof(Nt),1,ptnt);
	fclose(ptnt);
	
	ptsh=fopen("Dadosh.txt","ab+");
	sh.salt_hm[0]=2.14;
	sh.salt_hm[1]=2.22;
	sh.salt_hm[2]=2.30;
	sh.salt_hm[3]=2.38;
	sh.salt_hm[4]=2.45;
	
	sh.salt_hf[0]=1.66;
	sh.salt_hf[1]=1.74;
	sh.salt_hf[2]=1.82;
	sh.salt_hf[3]=1.90;
	sh.salt_hf[4]=1.97;
	fwrite(&sh,sizeof(Sh),1,ptsh);
	fclose(ptsh);
	
}

void Relatorios(){
	int op=0,aux=0;
	Al da;

	system("Title RELATÓRIOS");
	setlocale(LC_ALL,"portuguese");
	do{
	system("cls");
	printf("\n---------------------------------------------------\n");
	printf("\n\t1-RELATÓRIO DOS ALUNOS COM IDADE ENTRE 18-28 ANOS\n");
	printf("\n\t2-RELATÓRIO DOS ALUNOS COM IDADE ENTRE 28-38 ANOS\n");
	printf("\n\t3-RELATÓRIO DOS ALUNOS COM IDADE ENTRE 38-MAIS ANOS\n");
	printf("\n\t0-Sair");
	printf("\n---------------------------------------------------\n");
	scanf("%i",&op);
	switch(op){
	case 1:{
		system("cls");
		pca=fopen("Dadoaluno.txt","rb");
		rewind(pca);
		printf("\t\tRELATÓRIO DOS ALUNOS COM IDADE ENTRE 18-28 ANOS");
		printf("\n---------------------------------------------------\n");
		printf("Nome   Estatus do Teste\n");
		while(!feof(pca)){
		fread(&da,sizeof(Al),1,pca);
		if(!feof(pca)){
		if(da.idade>=18 && da.idade<=28){
			printf("%s   %s\n", da.nome,da.teste.status);
            aux=1; 		
		}
		}//fim if feof
		}//fim while
		if(aux==0){
			printf("\n\tNENHUM ALUNO CADASTRADO COM ESSA IDADE!");
		}
		printf("\n---------------------------------------------------\n");
		system("pause");
		system("cls");
		fclose(pca);
		break;
	}
	case 2:{
		system("cls");
		pca=fopen("Dadoaluno.txt","rb");
		rewind(pca);
		printf("\t\tRELATÓRIO DOS ALUNOS COM IDADE ENTRE 28-38 ANOS");
		printf("\n---------------------------------------------------\n");
		printf("Nome   Estatus do Teste\n");
		while(!feof(pca)){
		fread(&da,sizeof(Al),1,pca);
		if(!feof(pca)){
		if(da.idade>=28 && da.idade<=38){
			printf("%s   %s\n", da.nome,da.teste.status);
            aux=1;		
		}
		}//fim if feof
		}//fim while
		if(aux==0){
			printf("\n\tNENHUM ALUNO CADASTRADO COM ESSA IDADE!");
		}
		printf("\n---------------------------------------------------\n");
		system("pause");
		system("cls");
		fclose(pca);
		break;
	}
	case 3:{
		system("cls");
		pca=fopen("Dadoaluno.txt","rb");
		rewind(pca);
		printf("\t\tRELATÓRIO DOS ALUNOS COM IDADE ENTRE 38-MAIS ANOS");
		printf("\n---------------------------------------------------\n");
		printf("Nome   Estatus do Teste\n");
		while(!feof(pca)){
		fread(&da,sizeof(Al),1,pca);
		if(!feof(pca)){
		if(da.idade>38){
			printf("%s   %s\n", da.nome,da.teste.status);
		    aux=1;
		}
		}//fim if feof
		}//fim while
		if(aux==0){
			printf("\n\tNENHUM ALUNO CADASTRADO COM ESSA IDADE!");
		}
		printf("\n---------------------------------------------------\n");
		system("pause");
		system("cls");
		fclose(pca);
		break;
	}
	case 0:{
		system("cls");
		Menu_Adm();
		break;
	}
	default:{
		system("cls");
		printf("Opção Inválida\n");
		system("pause");
		break;
	}
	}
	}while(op!=0);
}//fim void Relatorios
	
void Alterar_Tabela(){
   int op,op1;
   Br br;
   Nt nt;
   Cr cr;
   Sh sh;
   
   
   system("cls");
   printf("\n\t1-SALTO DE IMPULSÃO HORIZONTAL");
   printf("\n\t2-CORRIDA");
   printf("\n\t3-NATAÇÃO");   
   printf("\n\t4-BARRA FIXA");
   printf("\n\t5-VOLTAR AO MENU PRINCIPAL\n\t");
   scanf("%i",&op);
       switch(op){
    case 1:
       	    ptsh=fopen("Dadosh.txt","rb+");
            rewind(ptsh);
	        fread(&sh,sizeof(Sh),1,ptsh);
            system("cls");
            printf("\n\t     SALTO DE IMPULSÃO HORIZONTAL");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",sh.salt_hm[0],sh.salt_hf[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",sh.salt_hm[1],sh.salt_hf[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",sh.salt_hm[2],sh.salt_hf[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",sh.salt_hm[3],sh.salt_hf[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",sh.salt_hm[4],sh.salt_hf[4]);
            printf("\n\t|---|-----------|-----------|---------|\n\n");
			system("pause");  
            printf("\n\tDEJESA ALTERAR A TABELA?");
			printf("\n\t1-SIM\n\t0-NÃO\n\t");
			scanf("%i",&op1);
			system("cls");  
			
			
			  if(op1==1){
			  printf("\n\t DESEJA ALTEAR QUAL TABELA?\n\t");
			  printf("\n\t1-MASCULINO\n\t2-FEMININO\n\t3-OS DOIS\n\t0-VOLTAR AO MENU PRINCIPAL\n\t"); 
			  int op5;
			  scanf("%i",&op5);
			  system("cls");
			  switch(op5){
			  case 1:
	
			printf("\n\t     SALTO DE IMPUSLSÃO HORIZONTAL");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",sh.salt_hm[0],sh.salt_hf[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",sh.salt_hm[1],sh.salt_hf[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",sh.salt_hm[2],sh.salt_hf[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",sh.salt_hm[3],sh.salt_hf[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",sh.salt_hm[4],sh.salt_hf[4]);
            printf("\n\t|---|-----------|-----------|---------|\n\n");
			
			
			printf("\n\t| N°| MASCULINO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&sh.salt_hm[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&sh.salt_hm[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&sh.salt_hm[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&sh.salt_hm[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&sh.salt_hm[4]);
			system("cls");  	
			system("cls");  
			
			
			  break;
			  case 2:  	
		
			
			printf("\n\t     SALTO DE IMPUSLSÃO HORIZONTAL");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",sh.salt_hm[0],sh.salt_hf[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",sh.salt_hm[1],sh.salt_hf[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",sh.salt_hm[2],sh.salt_hf[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",sh.salt_hm[3],sh.salt_hf[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",sh.salt_hm[4],sh.salt_hf[4]);
            printf("\n\t|---|-----------|-----------|---------|\n\n");
		
			 	
			  	
			printf("\n\t| N°| FEMININO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&sh.salt_hf[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&sh.salt_hf[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&sh.salt_hf[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&sh.salt_hf[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&sh.salt_hf[4]);
			system("cls");  	
		  	
		  	
			  break;
			  case 3:
			
			printf("\n\t     SALTO DE IMPUSLSÃO HORIZONTAL");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",sh.salt_hm[0],sh.salt_hf[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",sh.salt_hm[1],sh.salt_hf[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",sh.salt_hm[2],sh.salt_hf[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",sh.salt_hm[3],sh.salt_hf[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",sh.salt_hm[4],sh.salt_hf[4]);
            printf("\n\t|---|-----------|-----------|---------|\n\n");
		
			printf("\n\t| N°| MASCULINO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&sh.salt_hm[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&sh.salt_hm[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&sh.salt_hm[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&sh.salt_hm[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&sh.salt_hm[4]);
			system("cls");  	
		
			
	        printf("\n\t     SALTO DE IMPUSLSÃO HORIZONTAL");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",sh.salt_hm[0],sh.salt_hf[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",sh.salt_hm[1],sh.salt_hf[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",sh.salt_hm[2],sh.salt_hf[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",sh.salt_hm[3],sh.salt_hf[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",sh.salt_hm[4],sh.salt_hf[4]);
            printf("\n\t|---|-----------|-----------|---------|\n\n");
					
			printf("\n\t| N°| FEMININO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&sh.salt_hf[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&sh.salt_hf[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&sh.salt_hf[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&sh.salt_hf[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&sh.salt_hf[4]);
			system("cls");  		  	
		    
			
			
			  break;
		      default:
			  printf("\n\tOPÇÃO INVÁLIDA!!\n\t");
			  break;	
			  }
			     		
			
			} else if(op1==0){
			  	Alterar_Tabela;
			  	
			  } else if(op1!=0 && op1!=1){
			printf("\n\tOPÇÃO INVÁLIDA!");
			system("pause");
			system("cls"); 
			Menu_Avaliador(); 
			  }
			fseek(ptsh,0*sizeof(Sh),SEEK_SET);
			fwrite(&sh,sizeof(Sh),1,ptsh);	  	   
       		fclose(ptsh);
			system("cls");  
			 
            break;
    case 2:
		      
			ptcr=fopen("Dadocr.txt","rb+");
	        fread(&cr,sizeof(Cr),1,ptcr);
            rewind(ptcr);
			system("cls");
            printf("\n\t                CORRIDA");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",cr.corridam[0],cr.corridaf[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",cr.corridam[1],cr.corridaf[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",cr.corridam[2],cr.corridaf[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",cr.corridam[3],cr.corridaf[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",cr.corridam[4],cr.corridaf[4]);
            printf("\n\t|---|-----------|-----------|---------|\n");
			  	
			  
		    
			system("pause");  
            printf("\n\tDEJESA ALTERAR A TABELA?");
			printf("\n\t1-SIM\n\t0-NÃO\n\t");
			scanf("%i",&op1);
			  if(op1==1){
			  printf("\n\t DESEJA ALTEAR QUAL TABELA?\n\t");
			  printf("\n\t1-MASCULINO\n\t2-FEMININO\n\t3-OS DOIS\n\t0-VOLTAR AO MENU PRINCIPAL\n\t"); 
			  int op6;
			  scanf("%i",&op6);
			  system("cls");
			  switch(op6){
			  case 1:
		
			
			printf("\n\t                CORRIDA");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",cr.corridam[0],cr.corridaf[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",cr.corridam[1],cr.corridaf[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",cr.corridam[2],cr.corridaf[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",cr.corridam[3],cr.corridaf[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",cr.corridam[4],cr.corridaf[4]);
            printf("\n\t|---|-----------|-----------|---------|\n");
			  	
			printf("\n\t| N°| MASCULINO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&cr.corridam[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&cr.corridam[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&cr.corridam[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&cr.corridam[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&cr.corridam[4]);
			system("cls");
		    
			  	
			  break;
			  case 2:    
			printf("\n\t                CORRIDA");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",cr.corridam[0],cr.corridaf[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",cr.corridam[1],cr.corridaf[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",cr.corridam[2],cr.corridaf[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",cr.corridam[3],cr.corridaf[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",cr.corridam[4],cr.corridaf[4]);
            printf("\n\t|---|-----------|-----------|---------|\n");
			
			printf("\n\t| N°| FEMININO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&cr.corridaf[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&cr.corridaf[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&cr.corridaf[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&cr.corridaf[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&cr.corridaf[4]);  	
			system("cls");  
		    
			  break;
			  case 3:
		  	
			printf("\n\t                CORRIDA");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",cr.corridam[0],cr.corridaf[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",cr.corridam[1],cr.corridaf[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",cr.corridam[2],cr.corridaf[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",cr.corridam[3],cr.corridaf[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",cr.corridam[4],cr.corridaf[4]);
            printf("\n\t|---|-----------|-----------|---------|\n");
			 
			  	
			printf("\n\t| N°| MASCULINO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&cr.corridam[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&cr.corridam[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&cr.corridam[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&cr.corridam[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&cr.corridam[4]);
			system("cls");
			
			printf("\n\t                CORRIDA");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",cr.corridam[0],cr.corridaf[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",cr.corridam[1],cr.corridaf[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",cr.corridam[2],cr.corridaf[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",cr.corridam[3],cr.corridaf[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",cr.corridam[4],cr.corridaf[4]);
            printf("\n\t|---|-----------|-----------|---------|\n");
			
			printf("\n\t| N°| FEMININO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&cr.corridaf[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&cr.corridaf[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&cr.corridaf[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&cr.corridaf[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&cr.corridaf[4]);
			system("cls"); 
  	    	  	
			system("cls");  
		    break;
		      default:
			  printf("\n\tOPÇÃO INVÁLIDA!!\n\t");
			  break;	
			  }
			     		
			
			} else if(op1==0){
			  	Alterar_Tabela;
                system("cls");			
			  } else if(op1!=0 && op1!=1){
			printf("\n\tOPÇÃO INVÁLIDA!");
			system("pause");
			system("cls"); 
			Menu_Avaliador(); 
			  }	  
			fwrite(&cr,sizeof(Cr),1,ptcr);
			fseek(ptcr,0*sizeof(Cr),SEEK_SET);
			fclose(ptcr);  	
			
			break;
    case 3:
		    ptnt=fopen("Dadont.txt","rb+");
            rewind(ptnt);
	        fread(&nt,sizeof(Nt),1,ptnt);
            system("cls");
            printf("\n\t     NATAÇÃO");
            printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",nt.natacaom[0],nt.natacaof[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",nt.natacaom[1],nt.natacaof[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",nt.natacaom[2],nt.natacaof[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",nt.natacaom[3],nt.natacaof[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",nt.natacaom[4],nt.natacaof[4]);
            printf("\n\t|---|-----------|-----------|---------|\n\n");
			system("pause");  
            printf("\n\tDEJESA ALTERAR A TABELA?");
			printf("\n\t1-SIM\n\t0-NÃO\n\t");
			scanf("%i",&op1);
			system("cls");  
			
			
			  if(op1==1){
			  printf("\n\t DESEJA ALTEAR QUAL TABELA?\n\t");
			  printf("\n\t1-MASCULINO\n\t2-FEMININO\n\t3-OS DOIS\n\t0-VOLTAR AO MENU PRINCIPAL\n\t"); 
			  int op5;
			  scanf("%i",&op5);
			  system("cls");
			  switch(op5){
			  case 1:
		
			printf("\n\t     NATAÇÃO");
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",nt.natacaom[0],nt.natacaof[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",nt.natacaom[1],nt.natacaof[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",nt.natacaom[2],nt.natacaof[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",nt.natacaom[3],nt.natacaof[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",nt.natacaom[4],nt.natacaof[4]);
            printf("\n\t|---|-----------|-----------|---------|\n\n");
			
			printf("\n\t| N°| MASCULINO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&nt.natacaom[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&nt.natacaom[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&nt.natacaom[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&nt.natacaom[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&nt.natacaom[4]);
			system("cls");  	
			
			
			  break;
			  case 2:  	
		
			printf("\n\t     NATAÇÃO");
		    printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",nt.natacaom[0],nt.natacaof[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",nt.natacaom[1],nt.natacaof[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",nt.natacaom[2],nt.natacaof[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",nt.natacaom[3],nt.natacaof[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",nt.natacaom[4],nt.natacaof[4]);
            printf("\n\t|---|-----------|-----------|---------|\n\n");
			 	
			  	
			printf("\n\t| N°| FEMININO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&nt.natacaof[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&nt.natacaof[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&nt.natacaof[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&nt.natacaof[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&nt.natacaof[4]);
			system("cls");  	
		  	system("cls");  
			
		  	
			  break;
			  case 3:
			
			printf("\n\t     NATAÇÃO");
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",nt.natacaom[0],nt.natacaof[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",nt.natacaom[1],nt.natacaof[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",nt.natacaom[2],nt.natacaof[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",nt.natacaom[3],nt.natacaof[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",nt.natacaom[4],nt.natacaof[4]);
            printf("\n\t|---|-----------|-----------|---------|\n\n");
			
			
			printf("\n\t| N°| MASCULINO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&nt.natacaom[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&nt.natacaom[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&nt.natacaom[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&nt.natacaom[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&nt.natacaom[4]);
			system("cls");  	
			
		    printf("\n\t     NATAÇÃO");	
	        printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| N°| MASCULINO |  FEMININO | PONTOS  |");
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |    %.2f   |  2,00   |",nt.natacaom[0],nt.natacaof[0]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |    %.2f   |  3,00   |",nt.natacaom[1],nt.natacaof[1]);
       		printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |    %.2f   |  4,00   |",nt.natacaom[2],nt.natacaof[2]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |    %.2f   |  5,00   |",nt.natacaom[3],nt.natacaof[3]);
			printf("\n\t|---|-----------|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |    %.2f   |  6,00   |",nt.natacaom[4],nt.natacaof[4]);
            printf("\n\t|---|-----------|-----------|---------|\n\n");		
			
			printf("\n\t| N°| FEMININO |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&nt.natacaof[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&nt.natacaof[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&nt.natacaof[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&nt.natacaof[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&nt.natacaof[4]);
			system("cls");  	
		  	  
			
	
			  break;
		      default:
			  printf("\n\tOPÇÃO INVÁLIDA!!\n\t");
			  break;	
			  }
			     		
			
			} else if(op1==0){
			  	Alterar_Tabela;
			  	
			  } else if(op1!=0 && op1!=1){
			printf("\n\tOPÇÃO INVÁLIDA!");
			system("pause");
			system("cls"); 
			Menu_Avaliador(); 
			  } 
            fseek(ptnt,0*sizeof(Nt),SEEK_SET);
			fwrite(&nt,sizeof(Nt),1,ptnt);	  	   
       		fclose(ptnt);
			break;   	
    case 4:
    	
    	ptbr=fopen("Dadobr.txt","rb+");
            rewind(ptbr);
	        fread(&br,sizeof(Br),1,ptbr);
            system("cls");
            printf("\n\t        BARRA FIXA");
			printf("\n\t|---|-----------|---------|");
            printf("\n\t| N°| MAS E FEM | PONTOS  |");
       		printf("\n\t|---|-----------|---------|");
			printf("\n\t| 1 |  %.2f     |  2,00   |",br.barra_fixa[0],br.barra_fixa[0]);
       		printf("\n\t|---|-----------|---------|");
			printf("\n\t| 2 |  %.2f     |  3,00   |",br.barra_fixa[1],br.barra_fixa[1]);
       		printf("\n\t|---|-----------|---------|");
			printf("\n\t| 3 |  %.2f     |  4,00   |",br.barra_fixa[2],br.barra_fixa[2]);
			printf("\n\t|---|-----------|---------|");
			printf("\n\t| 4 |  %.2f     |  5,00   |",br.barra_fixa[3],br.barra_fixa[3]);
			printf("\n\t|---|-----------|---------|");
			printf("\n\t| 5 |  %.2f     |  6,00   |",br.barra_fixa[4],br.barra_fixa[4]);
            printf("\n\t|---|-----------|---------|\n\n");
			system("pause");  
            printf("\n\tDEJESA ALTERAR A TABELA?");
			printf("\n\t1-SIM\n\t0-NÃO\n\t");
			scanf("%i",&op1);
			system("cls");  
			
			
			  if(op1==1){
			  printf("\n\t DESEJA ALTEAR QUAL TABELA?\n\t");
			  printf("\n\t1-MASC E FEM\n\t0-VOLTAR AO MENU PRINCIPAL\n\t"); 
			  int op5;
			  scanf("%i",&op5);
			  system("cls");
			  switch(op5){
			  case 1:
		
			
			printf("\n\t        BARRA FIXA");
			printf("\n\t|---|-----------|---------|");
            printf("\n\t| N°| MAS E FEM |  PONTOS  |");
       		printf("\n\t|---|-----------|----------|");
			printf("\n\t| 1 |  %.2f     |   2,00   |",br.barra_fixa[0],br.barra_fixa[0]);
       		printf("\n\t|---|-----------|----------|");
			printf("\n\t| 2 |  %.2f     |   3,00   |",br.barra_fixa[1],br.barra_fixa[1]);
       		printf("\n\t|---|-----------|----------|");
			printf("\n\t| 3 |  %.2f     |   4,00   |",br.barra_fixa[2],br.barra_fixa[2]);
			printf("\n\t|---|-----------|----------|");
			printf("\n\t| 4 |  %.2f     |   5,00   |",br.barra_fixa[3],br.barra_fixa[3]);
			printf("\n\t|---|-----------|----------|");
			printf("\n\t| 5 |  %.2f     |   6,00   |",br.barra_fixa[4],br.barra_fixa[4]);
            printf("\n\t|---|-----------|----------|\n\n");
			
			printf("\n\t| N°| MASC E FEM |");
			printf("\n\t| 1 |     "); 
			scanf("%f",&br.barra_fixa[0]);
			printf("\n\t| 2 |     ");
			scanf("%f",&br.barra_fixa[1]);
			printf("\n\t| 3 |     ");
			scanf("%f",&br.barra_fixa[2]);
			printf("\n\t| 4 |     ");
			scanf("%f",&br.barra_fixa[3]);
			printf("\n\t| 5 |     ");
			scanf("%f",&br.barra_fixa[4]);
			system("cls");  	
			
			
			  break;
			  default:
			  printf("\n\tOPÇÃO INVÁLIDA!!\n\t");
			  break;	
			  }
			     		
			
			} else if(op1==0){
			  	Alterar_Tabela;
			  	
			  } else if(op1!=0 && op1!=1){
			printf("\n\tOPÇÃO INVÁLIDA!");
			system("pause");
			system("cls"); 
			Menu_Avaliador(); 
			  } 
            fseek(ptbr,0*sizeof(Br),SEEK_SET);
			fwrite(&br,sizeof(Br),1,ptbr);	  	   
       		fclose(ptbr);
			break;
    case 5:
		   system("cls");
		    break;	
	   }
}
