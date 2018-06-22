//Davi Ribeiro - 88931 
// Rafael Andrade - 81992 
// William Souza - 76901 
// Pilha encadeada 


#include <stdio.h>
#include <stdlib.h>

struct No{ // cria struct do no //
 int num;
 struct No *prox;
};
typedef struct No no; //definir struct do no//

int tam;  // variavel para guardar tamanho da pilha

//definindo funcoes da pilha//
int menu(void);                     // menu de opcoes 
void inicia(no *Pilha);            // inicializar a pilha
void opcao(no *Pilha, int op);    // testar opcoes 
void exibe(no *Pilha);           // exibir elementos da pilha 
void libera(no *Pilha);         // zerar toda a pilha
void push(no *Pilha);          // empilhar 
no *pop(no *Pilha);           // desempilhar


int main(void) //funcao principal e criacao da pilha//
{
 no *Pilha = (no *) malloc(sizeof(no)); // fazendo alocamento
 if(!Pilha){							// testando para ver se existe espaco na memoria	
  printf("Sem memoria disponivel!\n");  // caso nao seja possivel ele diz que nao tem memoria
  exit(1);								// saindo 
 }else{									// caso contrario
 inicia(Pilha);							// iniciando a pilha
 int opt;								// definindo as opcoes do menu principal do programa	

 do{
  opt=menu();							// menu principal
  opcao(Pilha,opt);						// recebendo o numero da opcao
 }while(opt);							// enquanto nao for 0 continua as opcoes do menu

 free(Pilha);							// libera vetor
 return 0;								// saindo
 }
}

void inicia(no *Pilha) // funcao para iniciar a pilha//
{
 Pilha->prox = NULL;					// vericando se o proximo esta vazia
 tam=0;
}

int menu(void) // funcao da opcoes do menu iniciar//
{
 int opcoes;
 printf("\n");
 printf(" * * * * PILHA ENCADEADA * * * * *\n");
 printf(" *                               *\n");
 printf(" *      Escolha uma opcao:       *\n");
 printf(" *                               *\n");
 printf(" *      -> 1 Empilhar (push)     *\n");
 printf(" *      -> 2 Desempilhar (pop)   *\n");
 printf(" *      -> 3 Zerar Pilha         *\n");
 printf(" *      -> 4 Exibir Pilha        *\n");
 printf(" *      -> 0 Sair                *\n");
 printf(" *                               *\n");
 printf(" * * * * * * * * * * * * * * * * *\n\n");
 printf("  Opcao: "); scanf("%d", &opcoes);
 printf("\n");

 return opcoes;  // retorna o valor da opcao escolhida 
}

void opcao(no *Pilha, int opc) 			// funcao opcoes da pilha//
{
 no *tmp;								// usando um ponteiro tmp para auxiliar
 switch(opc){
  case 1:								// caso 1, empilhando
   push(Pilha);							
   break;

  case 2:								//caso 2, desempilha
   tmp= pop(Pilha);				
   if(tmp != NULL)						//testando se esta vazia
   printf("  Retirado: %3d\n\n", tmp->num);
   break;
      
  case 3:								//caso 3, destruindo a pilha
   libera(Pilha);
   inicia(Pilha);
   break;

  case 4:								//caso 4, printando a pilha
   exibe(Pilha);
   break;
     
  case 0:								//caso 0, liberando a memoria e sai do programa
   libera(Pilha);
   break;	

  default:
   printf("  Comando invalido\n\n");	// digitar valores nao definidos ele retorna valor invalido
 }
}

int vazia(no *Pilha) //checar se a pilha esta vazia//
{
 if(Pilha->prox == NULL) // se esta vazia//
  return 1;
 else
  return 0; // se nao esta vazia//
}

no *aloca() //funcao alocar o no//
{
 no *novo=(no *) malloc(sizeof(no));		//alocando o no
 if(!novo){									// verificando a memoria esta disponivel
  printf("  Sem memoria disponivel!\n");	
  exit(1);									// saindo
 }else{
  printf("  Novo elemento: "); scanf("%d", &novo->num); //caso tenha memoria, digite o valor para a pilha
  return novo;
 } 
}

void exibe(no *Pilha) //funcao para exibir todos os elementos da pilha//
{
 
 if(vazia(Pilha)){					//caso nao tenha valor na pilha
  printf("  Pilha vazia!\n\n");
  return ;							//saindo

 }
 
 no *tmp;  //testar se a pilha está vazia se sim aponta pro novo NÓ,senão,aponta pro primeiro elemento do topo//
 tmp = Pilha->prox;					//ultizando a variavel tmp para auxiliar a pilha
 printf("Pilha:");
 while( tmp != NULL){				// caso seja diferente vazio ele print o valor da pilha
  printf("%5d", tmp->num);
  tmp = tmp->prox;					// variavel tmp auxiliando para o proximo posicao
}


 	
 printf("\n        ");				
 int count;
 for(count=0 ; count < tam ; count++)	// contandor para fazer os prints	
  printf("  ^  ");
 printf("\nPosic:");
 for(count=0 ; count < tam ; count++)	//contandor para fazer os prints
  printf("%5d", count);
  printf("\n");
  printf("\nTopo posic: %d",count-1);  // contador para mostar posicao do topo
printf("\n\n"); 
 }

void libera(no *Pilha) // funcao para liberar o no alocado na memoria//
{
 if(!vazia(Pilha)){			//testando a funcao da pilha
  no *proxno,
     *atual;

  atual = Pilha->prox;		//atualizando a pilha
  while(atual != NULL){		//testando se for diferente vazio
   proxno = atual->prox;	//vai para o proximo no
   free(atual);				// libera
   atual = proxno;			// define o proximo no
  }
 }
}

void push(no *Pilha) //funcao para adicionar um NÓ no topo da pilha//
{
 no *novo=aloca();			//alocando o novo no
 novo->prox = NULL;			//testando se o proximo esta vazio

 if(vazia(Pilha))			//testando se a pilha esta vazia
  Pilha->prox=novo;			//se estiver vai para a proxima posicao
 else{						//caso ao contrario
  no *tmp = Pilha->prox;	// recebendo o valor do proximo

  while(tmp->prox != NULL)	//enquanto for vazio		
   tmp = tmp->prox;			//vai para proxima posicao	

  tmp->prox = novo;			//recebendo uma nova entrada
 }
 tam++;						//incrementando	o tamanho da pilha
}
''

no *pop(no *Pilha) //retirar o ultimo elemento alocado no topo da pilha//
{
 if(Pilha->prox == NULL){					//verificando se a pilha esta vazia
  printf("  Pilha ja esta vazia\n\n");
  return NULL;
 }else{										//caso ao contrario	
  no *ultimo = Pilha->prox,					//definindo o ultima posicao
              *penultimo = Pilha;			//ponteiro para ultimo valor da pilha	

  while(ultimo->prox != NULL){				// caso seja diferente de vazio		
   penultimo = ultimo;						// agora o ultimo recebe posicao penultimo
   ultimo = ultimo->prox;					// o ultimo recebe a posicao do proximo ultimo	
  }

  penultimo->prox = NULL;					// caso seja vazio	
  tam--;									// diminui o tamanho da pilha
  return ultimo;							// retornando o ultimo valor da pilha
 }
}
