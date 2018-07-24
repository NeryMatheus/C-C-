#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main(){

int op,op2,matriculaprofessor,matriculaaluno;
char login[10],senha[10],adm[10],admsenha[10];
char nomeprofessor[10],loginprofessor[10],senhaprofessor[10];
char nomealuno[10],loginaluno[10],senhaaluno[10];
float n1,n2,n3,media;
strcpy(adm,"master");
strcpy(admsenha,"mais");
do{

system("cls");
system("color 1b");
system("color 1a");
printf("\t\tSIS AKD\n");
printf("\tLogin:");
printf("\t");
fflush(stdin);
gets(login);
printf("\tSenha:");       
printf("\t");
fflush(stdin);
gets(senha);

if(strcmp(strlwr(login),adm)==0){//comparacao login
 if(strcmp(strlwr(senha),admsenha)==0){//comparacao senha  
   //inicio tela funcionario
   system("cls");
    do{
 printf("\t\t Funcionario\n");
 printf("\t1-Cadastrar\n");       
 printf("\t2-Pesquisar\n");   
 printf("\t0-Sair\n");
 scanf("%i",&op);
 system("cls");
 switch(op){
 case 1:
      //inicio caso 1 cadastrar op
      do{
 system("cls");
 printf("\t\t Cadastro\n");
 printf("\t1-Professor\n");       
 printf("\t2-Aluno\n");   
 printf("\t0-Sair\n");
 scanf("%i",&op2);
 system("cls");
 switch(op2){//switch op2
 case 1:
 system("cls");
 printf("\t1-Cadastro Professor\n");     
 printf("\tNome:\n");     
 fflush(stdin);
 gets(nomeprofessor);     
 printf("\tMatricula:\n");     
 fflush(stdin);
 scanf("%i",&matriculaprofessor);     
 printf("__________________\n");
 printf("Login:\n");
 fflush(stdin);
 gets(loginprofessor);     
 printf("Senha:\n");
 fflush(stdin);
 gets(senhaprofessor);     
 
      break;
 case 2://switch op2
 system("cls");
 printf("\t1-Cadastro Aluno\n");     
 printf("\tNome:\n");     
 fflush(stdin);
 gets(nomealuno);     
 printf("\tMatricula:\n");     
 fflush(stdin);
 scanf("%i",&matriculaaluno);     
 printf("__________________\n");
 printf("Login:\n");
 fflush(stdin);
 gets(loginaluno);     
 printf("Senha:\n");
 fflush(stdin);
 gets(senhaaluno);   
  break;
 case 0://op2
      break;
 default:
 system("cls");        
 printf("Opcao invalida\n");
}
}while(op2!=0);//fiim da opcao cadastrar 
      break;

case 2://op pesquisar
     break;      
case 0://op sair
     break;      
default://do switch op
system("cls");
printf("Opcao invalida\n");      
}
}while(op!=0);

   //fim tela fncionario
   
  }else{//comparacao senha funcionario
  system("cls");
  printf("Senha invalido\n");      
   system("pause");
  }//fim condicao senha adm
  
     
}else if(strcmp(strlwr(login),strlwr(loginprofessor))==0){//comparacao login
        if(strcmp(strlwr(senha),strlwr(senhaprofessor))==0){//comparacao senha
//inicio tela professor
do{
system("cls");
printf("Seja bem vindo,Professor:%s\n",nomeprofessor);
printf("1-Lancar Notas\n");
printf("0-Sair\n");
scanf("%i",&op);
switch(op){
case 1:
printf("Lancamento de notas\n");     
printf("Nota 1:\n");
scanf("%f",&n1);     
printf("Nota 2:\n");
scanf("%f",&n2);     
printf("Nota 3:\n");
scanf("%f",&n3);     
media=(n1+n2+n3)/3;     
     break;
case 0:
     
     break;
default:
printf("Opcao invalida\n");
}//fim switch professor         
}while(op!=0);


//final tela professor

        }else{//comparacao senha
        system("cls");
        printf("Senha invalido\n");      
        system("pause");
        }//fim if senha professor    
      
}else if(strcmp(strupr(login),strupr(loginaluno))==0){//comparacao perfil aluno
      if(strcmp(strupr(senha),strupr(senhaaluno))==0){
      //incio tela aluno     
      do{
system("cls");
printf("Seja bem vindo,Aluno:%s\n",nomealuno);
printf("1-Gerar boletim\n");
printf("0-Sair\n");
scanf("%i",&op);
 switch(op){
 case 1:
printf("\t\tBoletim\n");
printf("\tNome:%s\n",nomealuno);      
printf("\tNota 1:%.2f\n",n1); 
printf("\tNota 2:%.2f\n",n2);
printf("\tNota 3:%.2f\n",n3);     
printf("\tMedia :%.2f\n",media);
system("pause");
      break;
 case 0:
      break;
  default:
  printf("Opcao invalida\n");            
 }///fim switch aluno             
      }while(op!=0);
      
      //fim tela aluno
      }else{
      printf("Senha invalida\n");      
      system("pause");
      }///fim condicao de senha
      
}else{//fim if adm //comparacao login
printf("Login invalido\n");      
system("pause\n");      
}

system("cls");
printf("1-Continua no sistema\n");
printf("0-Sair do sistema\n");
scanf("%i",&op);
if(op==0){
     exit(0);
}
system("cls");
}while(op!=0);       
       
system("pause");       
}
