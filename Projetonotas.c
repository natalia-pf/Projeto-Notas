#include <stdio.h>
#include <string.h>
#include <ctype.h>
//INTEGRANTES DO GRUPO: NATÁLIA E LEONARDO

//FUNÇÕES       
void cadastrar_aluno(void); //FUNÇÃO MENU 1-1     
void cadastrar_nota(void); //FUNÇÃO MENU 1-2
void acesso_anos(void); //FUNÇÃO MENU 2      
void turmas(void); //FUNÇÃO TURMAS 61, 62, 63, 71,..., 91, 92, 93
void media_das_turmas(void); //FUNÇÃO PARA CALCULAR A MEDIA DAS TURMAS

//VARIÁVEIS GLOBAIS
float notas_turmas[12];//NOTA DE TODOS ALUNOS DE CADA TURMA 
int Turmas[12], Quantidade_de_alunos[12];//QUANTIDADE DE ALUNOS POR TURMA
int quantidade_de_alunos;//QUANTIDADE DE ALUNOS NO GERAL

//STRUCT GLOBAL
struct alunos{ //ALUNOS
  char nome[30];
  int turma, codigo, check;
  float nota[3], media;
} aluno[999];

int main(void) { //INICIO
  int opcao=10;//opcao=10 PARA ENTRAR NO WHILE
  turmas();
  
  printf("\nBEM VINDO, USUÁRIO!\n");

  while(opcao>=0){
    printf("\n** MENU **\n\n1 - Cadastros\n2 - Lista dos anos (6º ao 9º)\n0 - Fechar programa\n\nEscolha a opcao desejada: ");
    scanf("%d", &opcao);
      if(opcao==0)//ENCERRA O PROGRAMA
        break;

    switch(opcao){
      case 1: //CADASTROS
        printf("\n* OPÇÕES DE CADASTRO*\n\n1 - Cadastrar aluno\n2 - Cadastrar nota\n0 - Voltar\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
          case 1: //CADASTRAR ALUNO
            cadastrar_aluno();
            break;
          case 2: //CADASTRAR NOTA
            cadastrar_nota();
            break;
          case 0: //VOLTAR
            break;
          default: //CASO A opcao SEJA INVÁLIDA
            printf("opcao inválida!");
        }
        break;
      case 2: //LISTA DOS ANOS
        media_das_turmas();
        acesso_anos();
        break;

      default: //CASO A opcao SEJA INVÁLIDA
        printf("opcao inválida");
    }
  }
}

void cadastrar_aluno(void){
  char cadastrardnv[3]="SIM"; //INICIA O WHILE

  while(toupper(cadastrardnv[0])=='S' && toupper(cadastrardnv[1])=='I' && toupper(cadastrardnv[2])=='M'){
    printf("\nCódigo do aluno: %d", quantidade_de_alunos+1);
    aluno[quantidade_de_alunos].codigo=quantidade_de_alunos+1; //+1 PARA O CODIGO DO ALUNO COMEÇAR EM 1 E NÃO 0
    printf("\nNome: ");
    getchar();
    scanf("%[^\n]s", aluno[quantidade_de_alunos].nome);
    printf("Turma: ");
    scanf("%d", &aluno[quantidade_de_alunos].turma);
    for(int i=0; aluno[quantidade_de_alunos].turma>=Turmas[i]; i++){
      if(aluno[quantidade_de_alunos].turma==Turmas[i])
        Quantidade_de_alunos[i]++;//SOMA +1 PARA O VETOR CORRESPONDENTE A TURMA
    }
    quantidade_de_alunos++;
    printf("Deseja cadastrar outro aluno? ");
    scanf("%s", cadastrardnv); //SE FOR SIM O WHILE REPETE
  }
}

void cadastrar_nota(void){
  char cadastrardnv[3]="SIM"; //PARA ENTRAR NO WHILE
  int i=0;
  float nota;
  while(toupper(cadastrardnv[0])=='S' && toupper(cadastrardnv[1])=='I' && toupper(cadastrardnv[2])=='M'){
    printf("\nInsira o código do aluno: ");
    scanf("%d", &aluno[i].codigo);
    for (int qnt_notas=0; qnt_notas<3; qnt_notas++){ //REPETIÇÃO PARA CADASTRAR AS 3 NOTAS DE UMA VEZ
      if (aluno[aluno[i].codigo-1].nota[qnt_notas]==0){ //SE A NOTA EM QUESTÃO FOR NULA, PERMITE Q CADASTRE. O -1 SERVE PARA IGUALAR O CÓDIGO DO ALUNO COM O INDICE DO VETOR VARIAVEL
        printf("Insira a nota para cadastro: ");
        scanf("%f", &aluno[i].nota[qnt_notas]);
      } //CADASTRA E VERIFICA A PROXIMA NOTA
      if(aluno[i].nota[2]!=0){ //NOTA[2] É A TERCEIRA NOTA, SE ELA JÁ ESTIVER PREENCHIDA N SE PODE MAIS CADASTRAR NOTA
        printf("Todas as notas desse aluno já foram cadastradas.\n");
        break;
      }
    }
    aluno[i].media=(aluno[i].nota[0]+aluno[i].nota[1]+aluno[i].nota[2])/3; //CALCULA A MEDIA INDIVIDUAL 
    printf("Deseja cadastrar outra nota? "); 
    scanf("%s", cadastrardnv); //SE FOR SIM O WHILE REPETE
    i++;
  }
}

void acesso_anos(void){ //FUNÇÃO CASE 2:
  int ano, turma;

  printf("\nENSINO FUNDAMENTAL II\nANOS:\n6º ano\n7º ano\n8º ano\n9º ano\n0 - Voltar\nEscolha o ano desejado: ");
  scanf("%d", &ano);

  switch(ano){ //ESCOLHE O ANO
    case 0: //VOLTAR
      break;
    case 6:
      printf("\n\nLISTA DE TURMAS\n61 = %.1f\n62 = %.1f\n63 = %.1f\n0 - Voltar\nEscolha a turma desejada: ", notas_turmas[0]/Quantidade_de_alunos[0], notas_turmas[1]/Quantidade_de_alunos[1], notas_turmas[2]/Quantidade_de_alunos[2]);//FAZ A MEDIA ENTRE A NOTA DE TODOS ALUNOS DE UMA TURMA E A QUANTIDADE DE ALUNOS NELA
      scanf("%d", &turma);
      break;
    case 7: 
      printf("\n\nLISTA DE TURMAS\n71 = %.1f\n72 = %.1f\n73 = %.1f\n0 - Voltar\nEscolha a turma desejada: ", notas_turmas[3]/Quantidade_de_alunos[3], notas_turmas[4]/Quantidade_de_alunos[4], notas_turmas[5]/Quantidade_de_alunos[5]);//FAZ A MEDIA ENTRE A NOTA DE TODOS ALUNOS DE UMA TURMA E A QUANTIDADE DE ALUNOS NELA
      scanf("%d", &turma);
      break;
    case 8: 
      printf("\n\nLISTA DE TURMAS\n81 = %.1f\n82 = %.1f\n83 = %.1f\n0 - Voltar\nEscolha a turma desejada: ", notas_turmas[6]/Quantidade_de_alunos[6], notas_turmas[7]/Quantidade_de_alunos[7], notas_turmas[8]/Quantidade_de_alunos[8]);//FAZ A MEDIA ENTRE A NOTA DE TODOS ALUNOS DE UMA TURMA E A QUANTIDADE DE ALUNOS NELA
      scanf("%d", &turma);
      break;
    case 9: 
      printf("\n\nLISTA DE TURMAS\n91 = %.1f\n92 = %.1f\n93 = %.1f\n0 - Voltar\nEscolha a turma desejada: ", notas_turmas[9]/Quantidade_de_alunos[9], notas_turmas[10]/Quantidade_de_alunos[10], notas_turmas[11]/Quantidade_de_alunos[11]);//FAZ A MEDIA ENTRE A NOTA DE TODOS ALUNOS DE UMA TURMA E A QUANTIDADE DE ALUNOS NELA
      scanf("%d", &turma);
      break;
    default:
      printf("opcao Inválida!");
      break;
  }
  for (int i=0; i<quantidade_de_alunos; i++){ //MOSTRA A MÉDIA INDIVIDUAL DENTRO DA TURMA ESCOLHIDA
    if(aluno[i].turma==turma && quantidade_de_alunos>0)
      printf("\n%d - %s || %.1f - %.1f - %.1f || %.1f", i+1, aluno[i].nome, aluno[i].nota[0], aluno[i].nota[1], aluno[i].nota[2], aluno[i].media);
  }
  if(quantidade_de_alunos==0 && ano!=0 && turma!=0) //VERIFICAÇÃO
    printf("\nNão há alunos cadastrados na turma\n");
}

void turmas(void){
  int i=0;

  for(int turma=61;turma<=93;turma++){ //INICIA EM 61 PORQUE É A PRIMEIRA TURMA E FINALIZA EM 93 POIS É A ÚLTIMA
    Turmas[i]=turma;
    if (turma==63) //SE CHEGAR EM 64 (TURMA Q N EXISTE, VAI PRO PRÓXIMO ANO)
      turma=70;
    else if (turma==73)
      turma=80;
    else if (turma==83)
      turma=90;
    i++;       
  }
}

void media_das_turmas(void){
  for(int i=0;i<12;i++){ //ALTERA A TURMA, PARA TESTAR TODAS(i)
    for (int j=0;j<quantidade_de_alunos;j++){ //ALTERA OS ALUNOS, PARA TESTAR TODOS EM TODAS AS TURMAS(j)
      if(aluno[j].check!=1){ //VERIFICA SE O ALUNO JÁ FOI ADICIONADO A MEDIA DA TURMA
        if(aluno[j].turma==Turmas[i]){ //SE A TURMA COINCIDIR
          notas_turmas[i]=notas_turmas[i]+(aluno[j].nota[0]+aluno[j].nota[1]+aluno[j].nota[2])/3;//SOMA-SE A NOTA NA MÉDIA DA TURMA
          aluno[j].check=1;//FAZ ESSE ALUNO NAO ENTRAR NOVAMENTE NO IF
        }
      }
    }
  }
}