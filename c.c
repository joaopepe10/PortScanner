/*
		**************************
			CENTRO FEDERAL DE EDUCAÇÃO E TECNOLOGIA DE MINAS GERAIS (CEFET-MG)
		
				TRABALHO FINAL = LABORATORIO DE PROGRAMAÇÃO DE COMPUTADORES
		
			NOMES DOS ALUNOS
			
			BRUNA DA SILVA LORDES;
			LUIZ CARLOS FRANCISCO;
			MATEUS RIBEIRO DE FREITAS;
			VANESSA SALES BASSOTO;
					
						Data de entrega: 27/11/2022
		*************************
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define NUM_LINHAS 10
#define NUM_COLUNAS 11
int TAMANHO = 10;
int tabuleiro[NUM_LINHAS][NUM_COLUNAS],tabuleiro_pc[NUM_LINHAS][NUM_COLUNAS],tabuleiro_pc_visualizar[NUM_LINHAS][NUM_COLUNAS];

typedef enum  // funcao que me possibilita alterar a cor das letras
{
	BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY, 
    LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE
    } COLORS;

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

void textcolor (int color) 
{
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}

// as structs a seguir, elas sao usadas para guardar as informações do posicionamento das embarcações
typedef struct  {
	int linha [4], coluna [4];
}PORTA_AVIOES;
PORTA_AVIOES porta_aviao; // PORTA AVIÃO DO USUARIO

typedef struct{  
	int linha [3], coluna [3];
}SUBMARINO;
SUBMARINO sub; // SUBMARINO DO USUARIO

typedef struct{  
	int linha [2], coluna [2];
}DESTROIER;
DESTROIER dest;// DESTROIER DO USUÁRIO

typedef struct{  
	int linha [1], coluna [1];
}BOTE;
BOTE bote;// BOTE DO USUARIO
// -----------// fim ------------

// as structs a seguir são usadas para guardar a posição aleatoria das embarcações do pc

typedef struct{  
	int linha [4], coluna [4];
}PORTA_AVIOES_PC;
PORTA_AVIOES_PC porta_aviao_pc;

typedef struct{  
	int linha [3], coluna [3];
}SUBMARINO_PC;
SUBMARINO_PC sub_pc;

typedef struct{  
	int linha [2], coluna [2];
}DESTROIER_PC;
DESTROIER_PC dest_pc;

typedef struct{  
	int linha [1], coluna [1];
}BOTE_PC;
BOTE_PC bote_pc;

// --------------- fim ----------------

typedef struct {
	int usuario , pc ;
	char nome [50];
}ACERTOS_OBTIDOS;
ACERTOS_OBTIDOS acertos;

typedef struct {
	int usuario, pc;
}TENTATIVAS_REALIZADAS;
TENTATIVAS_REALIZADAS tentativas;

typedef struct {
	int usuario , pc ;
}TIRO_ERRADO;
TIRO_ERRADO tiro_perdido;

typedef struct {
	int usuario , pc ;
}EMBARCACAO_DESTRUIDA;
EMBARCACAO_DESTRUIDA destruido;


int gerar_mapa(){ // FUNÇÃO USADA PARA O PREENCHIMENTO DOS ESPAÇOS DO TABULEIRO
	
	int i,j;
	char agua = '~';
	
	for (i = 0; i < TAMANHO; i++) {
            for (j = 0; j < TAMANHO; j++) {
            	tabuleiro[i][j] = agua;
                    tabuleiro_pc[i][j] = agua;
                   		tabuleiro_pc_visualizar[i][j] = agua;
                }
            }
    return 1;
}

int mapa_do_jogo(){ // FUNÇÃO USADA PARA A CRIAÇÃO DO TABULEIRO COM AS NUMERAÇÕES
	
	
	int i,j,k;
	
    printf("\n\t ==================================================================================\n\t||\t\t\t\t\t\t\t\t\t\t||\n\t||\t   ");
 
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", i+1);
    }
    printf("\t\t    ");
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", i+1);
    }
  
    printf("\t||\n\t||\t");
    for (i = 0; i < TAMANHO; i++) {
    	
 		if (i < 10) {
 			
            printf("%d |", i+1);
            
        } else {
        	
            printf("%d |", i+1);
            
       		}
   	for (j = 0; j < TAMANHO; j++) {
   		
    	printf("%c",tabuleiro[i][j]);// tabuleiro usuario
        printf("~");
        
		if (j == 9) { 
		
         	printf("|\t\t", i+1);
         	
			if (i < 10) {
				
				printf("%d | ", i+1);
				
     	  } else {
     	  	
         	printf("%d | ", i+1);
         }
         for (k = 0; k < TAMANHO; k++) {
         	
         	printf("%c", tabuleiro_pc_visualizar[i][k]);
         printf("~");
        	}
        }
    }
        printf("|\t||\n\t||\t");
        }
        printf("    JOGADOR = %s\t\t COMPUTADOR\t\t||\n\t||\t\t\t\t\t\t\t\t\t\t||\n\t==================================================================================\n\n",acertos.nome);
        
        getch();
        return 0;
        
		}

int gerar_navios(){
	carregando();
    mapa_do_jogo;
	
	char figuraP = 'P',figuraS = 'S',figuraD = 'D',figuraB = 'B'; // VARIAVEIS USADAS PARA SALVAR AS LETRAS NAS EMBARCAÇÕES
	int i,j,linha,coluna;
	int qtdP = 1; //quantidade porta aviões
	int qtdS = 3; //quantidade submarino
	int qtdD = 3; //quantidade destroier
	int qtdB = 2; //quantidade botes	
	int tamP = 4; //tamanho porta aviões
	int tamS = 3; //tamanho submarino
	int tamD = 2; //tamanho destroier
	int tamB = 1; //tamanho botes
	
	
// INICIO DE ONDE O USUÁRIO COLOCA AS COORDENADAS PARA DIRECIONAR AS EMBARCAÇÕES
	printf("\n\t Agora digite as coordenadas do unico Porta Aviões ");
	for(j = 0; j < qtdP; j++){ // QUANTIDADE DE EMBARCAÇÕES
		printf("\n\t Porta Avioes = N  [%d]",j+1); //ENUMERA A QUANTIDADE DO TIPO DO BARCO EM ORDEM
		for (i = 0; i < tamP; i++) {//ENQUANTO NAO ATINGIR A QUANTIDADE DE EMBARCAÇÃO, A FUNÇÃO NAO PARA
            printf("\n\n\t Digite a linha ..: ");
			scanf("%d", &linha);
			printf("\n\t Digite a coluna .: ");
			scanf("%d",&coluna);
            tabuleiro[linha][coluna] = figuraP;//SALVA A LETRA NA POSIÇÃO DENTRO DA MATRIZ
            porta_aviao.linha[i] = linha; 
            porta_aviao.coluna[i] = coluna;
            printf("\n");
            }
        }
    system("CLS");//LIMPA A TELA
    
    mapa_do_jogo();          
	printf("\n\t Agora digite as coordenadas dos 3 Submarinos ");
	for(j = 0; j < qtdS; j++){// QUANTIDADE DE EMBARCAÇÕES
		printf("\n\t Submarino = N  [%d]",j+1);//ENUMERA A QUANTIDADE DO TIPO DO BARCO EM ORDEM
		for (i = 0; i < tamS; i++) {//ENQUANTO NAO ATINGIR A QUANTIDADE DE EMBARCAÇÃO, A FUNÇÃO NAO PARA
            printf("\n\n\t Digite a linha ..: ");
			scanf("%d", &linha);
			printf("\n\n\t Digite a coluna .: ");
			scanf("%d",&coluna);
            tabuleiro[linha][coluna] = figuraS;//SALVA A LETRA NA POSIÇÃO DENTRO DA MATRIZ
            sub.linha[i] = linha; 
            sub.coluna[i] = coluna;
            printf("\n");
            }
    }
	system("CLS");//LIMPA A TELA
    mapa_do_jogo();      
    printf("\n\t Agora digite as coordenadas dos 3 Destroier ");
	for(j = 0; j < qtdD; j++){// QUANTIDADE DE EMBARCAÇÕES
		printf("\n\t Destroier  = N  [%d]",j+1);//ENUMERA A QUANTIDADE DO TIPO DO BARCO EM ORDEM
		for (i = 0; i < tamD; i++) { //ENQUANTO NAO ATINGIR A QUANTIDADE DE EMBARCAÇÃO, A FUNÇÃO NAO PARA
            printf("\n\n\t Digite a linha ..: ");
			scanf("%d", &linha);
			printf("\n\t Digite a coluna .: ");
			scanf("%d",&coluna);
            tabuleiro[linha][coluna] = figuraD;//SALVA A LETRA NA POSIÇÃO DENTRO DA MATRIZ
            dest.linha[i] = linha; 
            dest.coluna[i] = coluna;
            printf("\n");
            }
        }
    system("CLS");        //LIMPA A TELA
    
    mapa_do_jogo();     
    printf("\n\t Agora digite as coordenadas dos 2 Botes ");
	for(j = 0; j < qtdB; j++){// QUANTIDADE DE EMBARCAÇÕES
		printf("\n\t BOTE  = N  [%d]",j+1);//ENUMERA A QUANTIDADE DO TIPO DO BARCO EM ORDEM
		for (i = 0; i < tamB; i++) {//ENQUANTO NAO ATINGIR A QUANTIDADE DE EMBARCAÇÃO, A FUNÇÃO NAO PARA
            printf("\n\n\t Digite a linha ..: ");
			scanf("%d", &linha);
			printf("\n\t Digite a coluna .: ");
			scanf("%d",&coluna);
            tabuleiro[linha][coluna] = figuraD;//SALVA A LETRA NA POSIÇÃO DENTRO DA MATRIZ
            bote.linha[i] = linha; 
            bote.coluna[i] = coluna;
            printf("\n");
            }
	}
	
	
	system("CLS");//LIMPA A TELA
	
	return 1;
}

int gerar_navios_pc(){
	
	int pc_aleatorio_linha, pc_aleatorio_coluna;
	srand(time(NULL));
	
	pc_aleatorio_linha = rand() % 10;		//GERA A POSIÇÃO DA COLUNA ALEATORIA
	pc_aleatorio_coluna =rand() % 10;		//GERA A POSIÇÃO DA COLUNA ALEATORIA
	
	char figuraP = 'P',figuraS = 'S',figuraD = 'D',figuraB = 'B';
	int i,j,linha = 0,coluna = 0;
	int qtdP = 1; //quantidade porta aviões
	int qtdS = 3; //quantidade submarino
	int qtdD = 3; //quantidade destroier
	int qtdB = 2; //quantidade botes	
	int tamP = 4; //tamanho porta aviões
	int tamS = 3; //tamanho submarino
	int tamD = 2; //tamanho destroier
	int tamB = 1; //tamanho botes
	mapa_do_jogo();						// MOSTRA O MAPA ATUALIZAD		
	
	printf("\n\t Aguarde enquanto o computador gera as coordenadas para o Porta Aviões ");
	Sleep(1500);						// DA UMA LEVE PAUSA NA VISUALIZAÇÃO PARA PROSSEGUIR
	for(j = 0; j < qtdP; j++){
	
		for (i = 0; i < tamP; i++) {
			linha = pc_aleatorio_linha;						//VINCULA A POSIÇÃO ALEATORIA DA LINHA
			coluna = pc_aleatorio_coluna;					// VINCULA A POSIÇÃO ALEATORIA DA COLUNA
            tabuleiro_pc[linha][coluna] = figuraP;			// SALVA NA MATRIZ A POSIÇÃO
            porta_aviao_pc.linha[i] = linha; 				// SALVA NA STRUCT A POSIÇÃO
            porta_aviao_pc.coluna[i] = coluna;
            printf("\n");
            }
        }
    system("CLS");
            
	printf("\n\t Aguarde enquanto o computador gera as coordenadas para os Submarinos ");
	Sleep(1500);
	for(j = 0; j < qtdS; j++){
	
		for (i = 0; i < tamS; i++) {
			linha = pc_aleatorio_linha;
			coluna = pc_aleatorio_coluna;
            tabuleiro_pc[linha][coluna] = figuraS;
            sub_pc.linha[i] = linha; 
            sub_pc.coluna[i] = coluna;
            printf("\n");
            }
    }
	system("CLS");
            
    printf("\n\t Aguarde enquanto o computador gera as coordenadas para os Destroier ");
    Sleep(1500);
	for(j = 0; j < qtdD; j++){
	
		for (i = 0; i < tamD; i++) {
			linha = pc_aleatorio_linha;
			coluna = pc_aleatorio_coluna;
            tabuleiro_pc[linha][coluna] = figuraD;
            dest_pc.linha[i] = linha; 
            dest_pc.coluna[i] = coluna;
            printf("\n");
            }
        }
    system("CLS");        
    
            
    printf("\n\t Aguarde enquanto o computador gera as coordenadas para os Botes ");
    Sleep(1500);
	for(j = 0; j < qtdB; j++){
		
		for (i = 0; i < tamB; i++) {
			linha = pc_aleatorio_linha;
			coluna = pc_aleatorio_coluna;
            tabuleiro_pc[linha][coluna] = figuraD;
            bote_pc.linha[i] = linha; 
            bote_pc.coluna[i] = coluna;
            printf("\n");
            }
	}
	system("CLS");
	
}


int checagem (int tabuleiro[NUM_LINHAS][NUM_COLUNAS],int tabuleiro_pc[NUM_LINHAS][NUM_COLUNAS],char ataque, char errou){ 
			
			// ESSA FUNÇÃO FAZ A VERIFICAÇÃO DE QUANTAS EMBARCAÇÕES FORAM DESTRUIDAS DURANTE O JOGO, ENTRE O USUARIO E O PC	
				
            if (((tabuleiro[porta_aviao.linha[0]][porta_aviao.coluna[0]] == ataque) && (tabuleiro[porta_aviao.linha[1]][porta_aviao.coluna[1]] == ataque) && (tabuleiro[porta_aviao.linha[2]][porta_aviao.coluna[2]] == ataque) && (tabuleiro[porta_aviao.linha[3]][porta_aviao.coluna[3]] == ataque)) ||
                ((tabuleiro[porta_aviao.coluna[0]][porta_aviao.linha[0]] == ataque) && (tabuleiro[porta_aviao.coluna[1]][porta_aviao.linha[1]] == ataque) && (tabuleiro[porta_aviao.coluna[2]][porta_aviao.linha[2]] == ataque) && (tabuleiro[porta_aviao.coluna[3]][porta_aviao.linha[3]] == ataque))) {

                destruido.usuario++;
            }
            if (((tabuleiro_pc[porta_aviao_pc.linha[0]][porta_aviao_pc.coluna[0]] == ataque) && (tabuleiro_pc[porta_aviao_pc.linha[1]][porta_aviao_pc.coluna[1]] == ataque) && (tabuleiro_pc[porta_aviao_pc.linha[2]][porta_aviao_pc.coluna[2]] == ataque) && (tabuleiro_pc[porta_aviao_pc.linha[3]][porta_aviao_pc.coluna[3]] == ataque)) ||
                ((tabuleiro_pc[porta_aviao_pc.coluna[0]][porta_aviao_pc.linha[0]] == ataque) && (tabuleiro_pc[porta_aviao_pc.coluna[1]][porta_aviao_pc.linha[1]] == ataque) && (tabuleiro_pc[porta_aviao_pc.coluna[2]][porta_aviao_pc.linha[2]] == ataque) && (tabuleiro_pc[porta_aviao_pc.coluna[3]][porta_aviao_pc.linha[3]] == ataque)))  {
            
                destruido.pc++;
            }

            if (((tabuleiro[sub.linha[0]][sub.coluna[0]] == ataque) && (tabuleiro[sub.linha[1]][sub.coluna[1]] == ataque) && (tabuleiro[sub.linha[2]][sub.coluna[2]] == ataque)) ||
                ((tabuleiro[sub.coluna[0]][sub.linha[0]] == ataque) && (tabuleiro[sub.coluna[1]][sub.linha[1]] == ataque) && (tabuleiro[sub.coluna[2]][sub.linha[2]] == ataque))) {
                destruido.usuario++;
            }
            
            if (((tabuleiro_pc[sub_pc.linha[0]][sub_pc.coluna[0]] == ataque) &&(tabuleiro_pc[sub_pc.linha[1]][sub_pc.coluna[1]] == ataque) && (tabuleiro_pc[sub_pc.linha[2]][sub_pc.coluna[2]] == ataque)) ||
               ((tabuleiro_pc[sub_pc.coluna[0]][sub_pc.linha[0]] == ataque) && (tabuleiro_pc[sub_pc.coluna[1]][sub_pc.linha[1]] == ataque) && (tabuleiro_pc[sub_pc.coluna[2]][sub_pc.linha[2]] == ataque))) {
                destruido.pc++;
            }

            if (((tabuleiro[dest.linha[0]][dest.coluna[0]] == ataque) && (tabuleiro[dest.linha[1]][dest.coluna[1]] == ataque)) ||
                ((tabuleiro[dest.coluna[0]][dest.linha[0]] == ataque) && (tabuleiro[dest.coluna[1]][dest.linha[1]] == ataque))) {

                destruido.usuario++;
            }
            if (((tabuleiro_pc[dest_pc.linha[0]][dest_pc.coluna[0]] == ataque) && (tabuleiro_pc[dest_pc.linha[1]][dest_pc.coluna[1]] == ataque)) ||
                ((tabuleiro_pc[dest_pc.coluna[0]][dest_pc.linha[0]] == ataque) && (tabuleiro_pc[dest_pc.coluna[1]][dest_pc.linha[1]] == ataque))){
                destruido.pc++;
            }

            if (tabuleiro[bote.linha[0]][bote.coluna[0]] == ataque) {
                destruido.usuario++;
            }
            if (tabuleiro_pc[bote_pc.linha[0]][bote_pc.coluna[0]] == ataque){
                destruido.pc++;
            } 

}

int barquinho(){ //UMA FUNÇÃO PARA DESCONTRAIR NO JOGO
				// É UM BARCO EM MOVIMENTO
	
		
	printf("\r  _ \n||__\n\\___/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400);
	system("CLS");
	printf("\r    _ \n  _||__\n  \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400); 
	system("CLS");
	printf("\r      _ \n    _||__\n    \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400); 
	system("CLS");
	printf("\r        _ \n      _||__\n      \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400); 
	system("CLS");
	printf("\r          _ \n        _||__\n        \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400); 
	system("CLS");
	printf("\r            _ \n          _||__\n          \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400); 
	system("CLS");
	printf("\r              _ \n            _||__\n            \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400);  
	system("CLS");
	printf("\r                _ \n              _||__\n              \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400); 
	system("CLS");
	printf("\r                  _ \n                _||__\n                \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400);
	system("CLS");
	printf("\r                    _ \n                  _||__\n                  \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400);
	system("CLS");
	printf("\r                      _ \n                    _||__\n                    \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400);
	system("CLS");
	printf("\r                        _ \n                      _||__\n                      \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400);
	system("CLS");
	printf("\r                          _ \n                        _||__\n                        \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400);
	system("CLS");
	printf("\r                           _ \n                          _||__\n                          \\____/\n~~~~~~~~~~~~~~\n"); 
	Sleep(400);
	system("CLS");

}

int carregando(){ // FUNÇÃO PARA DESCONTRAIR NO JOGO
				 // APARECE CARREGANDO E UM PONTILHADO NA TELA
	
	system("CLS");
	printf("\r\t\t C ");
	Sleep(100);
	printf("\r\t\t C A ");
	Sleep(100);
	printf("\r\t\t C A R ");
	Sleep(100);
	printf("\r\t\t C A R R ");
	Sleep(100);
	printf("\r\t\t C A R R E ");
	Sleep(100);
	printf("\r\t\t C A R R E G ");
	Sleep(100);
	printf("\r\t\t C A R R E G A ");
	Sleep(100);
	printf("\r\t\t C A R R E G A N ");
	Sleep(100);
	printf("\r\t\t C A R R E G A N D ");
	Sleep(100);
	printf("\r\t\t C A R R E G A N D O ");
	Sleep(100);
	printf("\r\t\t C A R R E G A N D O . ");
	Sleep(100);
	printf("\r\t\t C A R R E G A N D O . . ");
	Sleep(100);
	printf("\r\t\t C A R R E G A N D O . . . ");
	Sleep(100);
	printf("\n\n");
	printf("\r\t\t~~");
	Sleep(100);
	printf("\r\t\t~~~~");
	Sleep(100);
	printf("\r\t\t~~~~");
	Sleep(100);
	printf("\r\t\t~~~~");
	Sleep(100);
	printf("\r\t\t~~~~~~");
	Sleep(100);
	printf("\r\t\t~~~~~~");
	Sleep(100);
	printf("\r\t\t~~~~~~");
	Sleep(100);
	printf("\r\t\t~~~~~~~");
	Sleep(100);
	printf("\r\t\t~~~~~~~~");
	Sleep(100);
	printf("\r\t\t~~~~~~~~~");
	Sleep(100);
	printf("\r\t\t~~~~~~~~~~");
	Sleep(100);
	printf("\r\t\t~~~~~~~~~~~");
	Sleep(100);
	printf("\r\t\t~~~~~~~~~~~~");
	Sleep(100);
	system("CLS");
}

int ataque_usuario(char ataque, char errou){
	
	int chamarAtaqueUsuario(){ // FUNCAO QUE RETORNA A FUNÇAÕ PRINCIPAL
		
		ataque_usuario;
	}
	
	mapa_do_jogo();				//MOSTRA O MAPA
	int usuario_tiro1,usuario_tiro2;

			
	printf("\n\n\t Por favor, de as coordenadas do tiro");
	printf("\n\t Qual linha? : ");
	scanf("%d",&usuario_tiro1);			// SALVA AS COORDENADAS DO TIRO
	
	
	printf("\n\t Qual coluna? : ");
	scanf("%d",&usuario_tiro2);
	
	tentativas.usuario++;				// SALVA AS TENTATIVAS
	
	
	if(tabuleiro_pc[usuario_tiro1][usuario_tiro2]==ataque){			// FAZ A VERIFICAÇÃO SE ACERTOU A EMBARCAÇÃO
		tabuleiro_pc[usuario_tiro1][usuario_tiro2]= errou;
		tabuleiro_pc_visualizar[usuario_tiro1][usuario_tiro2]= errou;
		acertos.usuario++;
		
		printf("\n\t Voce atingiu uma embarcação inimiga nas coordenadas [%d][%d] \n\n\t PARABENSS ",usuario_tiro1,usuario_tiro2);
	}
	else if (tabuleiro_pc[usuario_tiro1][usuario_tiro2]==errou) { // FAZ A VERIFICAÇÃO SE AQUELA POSIÇÃO JÁ FOI ATINGIDA
        tabuleiro_pc[usuario_tiro1][usuario_tiro2]=errou;
        tabuleiro_pc_visualizar[usuario_tiro1][usuario_tiro2] = errou;
        printf("\n\t Voce ja atacou nessa posicao. Escolha outra coordenada.\n\t");
        chamarAtaqueUsuario(); 
   }
   else{
   		tabuleiro_pc[usuario_tiro1][usuario_tiro2] = '-';				// FAZ A VERIFICAÇÃO SE O TIRO FOI PERDIDO
        tabuleiro_pc_visualizar[usuario_tiro1][usuario_tiro2] = '-';
        tiro_perdido.usuario++;
        
   }
	
			
}

int ataque_pc (char ataque, char errou){ 
	
	int chamarAtaquePC(){
		
		ataque_pc;
	}
	tentativas.pc;
	
	int pc_tiro_linha, pc_tiro_coluna;
	srand(time(NULL));
	
	pc_tiro_linha = rand() % 10;
	pc_tiro_coluna =rand() % 10;								// FAZ O SORTEIO ALEATORIO DAS POSIÇÕES DO TIRO
			
	printf("\n\n\t Por favor, aguarde enquanto o pc escolhe a sua jogada ");
		
	printf("\n\t Linha escolhida : %d ",pc_tiro_linha);

	printf("\n\t Coluna escolhida :%d ",pc_tiro_coluna);
	
	tentativas.pc++;
	
	if(tabuleiro[pc_tiro_linha][pc_tiro_coluna]==ataque){
		tabuleiro[pc_tiro_linha][pc_tiro_coluna]= errou;
		acertos.pc++;
		
		printf("\n\t O computador atingiu uma embarcacao sua nas seguintes coordenadas [%d][%d] \n\n\t CUIDADO ",pc_tiro_linha,pc_tiro_coluna);
	}
	else if (tabuleiro[pc_tiro_linha][pc_tiro_coluna]==errou) {
        tabuleiro[pc_tiro_linha][pc_tiro_coluna]=errou;
        chamarAtaquePC();
   }
   else{
   		tabuleiro[pc_tiro_linha][pc_tiro_coluna] = '-';
        tiro_perdido.pc++;
        
   }
	
}

int Tabuleiro_iniciar(int tabuleiro[][NUM_COLUNAS]){
	
	int Tabuleiro_linha, Tabuleiro_coluna;
	
        for(Tabuleiro_linha=0 ; Tabuleiro_linha < 10 ; Tabuleiro_linha++ ){
            for(Tabuleiro_coluna=0 ; Tabuleiro_coluna < 10 ; Tabuleiro_coluna++ ){
			
                tabuleiro[Tabuleiro_linha][Tabuleiro_coluna]=-1;
			}
		}
		
		return 1;
	}
	
int creditos(){						// CREDITOS DA AUTORIA DO PROGRAMA E NOMES DOS INTEGRANTES 
	
	int cont,opcao;
	
	char credito [] = "\n\n\n\t\t ----------------------------------------------\n\t\t ----------------------------------------------\n\n\t\t                     CEFET  \n\t\t     CENTRO FEDERAL DE EDUCACAO E TECNOLOGIA \n\t\t                DE MINAS GERAIS \n\n\t\t             CAMPOS NOVA GAMELEIRA\n\n\t\t ----------------------------------------------\n\t\t ----------------------------------------------\n\n\t\t                   CREDITOS\n\n\t\t             LUIZ CARLOS FRANCISCO\n\n\t\t             BRUNA DA SILVA LORDES\n\t\t         MATEUS RIBEIRO DE FREITAS\n\t\t             VANESSA SALES BASSOTO\n\n\t\t               PROFESSOR JOSEMAR	\n\n\t\t                  TRABALHO FINAL \n\n\t\t----------------------------------------------\n\t\t                [1] - VOLTAR \n\t\t----------------------------------------------\n\n";
	
	for(cont = 0; credito[cont] != '\0'; cont = cont + 1)	{        putchar(credito[cont]);        Sleep(20);    }
	opcao = getch();

    switch(opcao)
    {

    case '1' :
        system("cls");
        main();
        break;

    default :
        system("cls");
        creditos();
        break;
    }	
}
	
int main (){
	
	int resp1,resp2, cont;
	
	char ataque = 'X',errou = '*';
	//FUNÇÕES CHAR PARA DAR O EFEITO DE DIGITANDO NA HORA DE ABRIR O JOGO
	char frase1 [] = "\n\n\n\n\t****************";
	char frase2 [] = "\n\t     SEJA BEM VINDO AO JOGO BATALHA NAVAL";
	char frase3 [] = "\n\t****************";
	char frase4 [] = "\n\n\n\n\n\n\n\n\t    AGUARDE UM INSTANTE, POR FAVOR";
	char frase5 [] = "\n\n\t Qual eh o seu nome? : ";
	char frase6 [] = "\n\n\t  DIGITE A OPCAO DESEJADA PARA PROSSEGUIR ";
	char frase7 [] = "\n\n\t [1] = Iniciar o jogo \n\t [2] - Creditos \n\t [3] - Sair do jogo \n\t = " ;
	char frase8 [] =  "\n\n\t Vamos prosseguir no programa \n\n";
	char frase9 [] = "\n\n\t Neste BATALHA NAVAL, sera um tabuleiro 10x10 e voce ira disputar com o computador \n\n" ;
	char frase10 [] = "\n\n\t Quem destruir todos os navios primeiro,\n\n\n\n\n\n\t\t GANHA \n\n" ;
	char frase11 [] = "\n\n\n\t Jogo terminado. Você acertou todos os navios do Inimigos\n\n\t" ;
	char frase12 [] = "\n\n\n\n\t DIGITE A OPCAO DESEJADA \n\n\n\n\t [1] - VOLTAR AO MENU \n\n\t [2] - CREDITOS \n\n\t [3] - SAIR DO JOGO \n\n\t = " ;
	char frase13 [] = "\n\n\n\n\n\n\n\t\t\t\t OBRIGADO E ATE A PROXIMA \n\n\n\n\n\n" ;
	char frase14 [] = "\n\n\n\n\n\n\n\t DIGITE A OPCAO CORRETA ";
	char frase15 [] = "\n\n\n\t Jogo terminado. Você perdeu para o Inimigos\n\n\t" ;
	/*
	FILE*usuario;
	FILE*computador;
	
	usuario = fopen("arquivo_usuario.txt","r+b");
	computador = fopen("arquivo_computador.txt","r+b"); */
	
	textcolor(LIGHTBLUE); 				// MUDAR A COR DA FONTE
	
	//FUNÇÕES QUE SÃO RESPONSAVEIS POR FAZER A SOLETRAÇÃO DAS FRASES SALVAS EM CHAR
	
	for(cont = 0; frase1[cont] != '\0'; cont = cont + 1)	{        putchar(frase1[cont]);        Sleep(20);    } 	
    for(cont = 0 ; frase2[cont] != '\0'; cont = cont + 1)    {        putchar(frase2[cont]);        Sleep(20);    }
    for(cont = 0; frase3[cont] != '\0'; cont = cont + 1)    {        putchar(frase3[cont]);        Sleep(20);    }
  
    Sleep(2000); system("cls");

	for(cont = 0; frase4[cont] != '\0'; cont = cont + 1)    {        putchar(frase4[cont]);        Sleep(20);    }
	
    Sleep(1000);    system("cls");    
    barquinho();     system("cls");    
	printf("\n\n\n\n\n\n");
	
	for(cont = 0; frase3[cont] != '\0'; cont = cont + 1)    {        putchar(frase3[cont]);        Sleep(20);    }
    for(cont = 0; frase5[cont] != '\0'; cont = cont + 1)    {        putchar(frase5[cont]);        Sleep(20);    }
	
    
    fgets(acertos.nome, 50, stdin);fflush(stdin);
    system("cls"); 
	
	for(cont = 0; frase1[cont] != '\0'; cont = cont + 1)	{        putchar(frase1[cont]);        Sleep(20);    }
	do{
		for(cont = 0; frase6[cont] != '\0'; cont = cont + 1)	{        putchar(frase6[cont]);        Sleep(20);    }
		for(cont = 0; frase7[cont] != '\0'; cont = cont + 1)	{        putchar(frase7[cont]);        Sleep(20);    }
		
	
		scanf("%d",&resp1);
		Sleep(500);
		system("cls"); 
	if ( resp1 == 1){
		
		for(cont = 0; frase8[cont] != '\0'; cont = cont + 1)	{        putchar(frase8[cont]);        Sleep(20);    }
		Sleep(500);
		system("CLS");
		
		for(cont = 0; frase9[cont] != '\0'; cont = cont + 1)	{        putchar(frase9[cont]);        Sleep(20);    }
		Sleep(500);
		system("CLS");
		
		for(cont = 0; frase10[cont] != '\0'; cont = cont + 1)	{        putchar(frase10[cont]);        Sleep(20);    }
		Sleep(1000);
		system("CLS");
		carregando(); system("CLS");
		carregando(); system("CLS");
		carregando(); system("CLS");
		printf("\n\n\t %s seguir, segue os detalhes \n\n",acertos.nome);
		printf("\n\t **************** ");
		printf("\n\t | Tipo de Embarcacao | Tamanho | Quantidade  | ");
		printf("\n\t |*******|***|****| ");
		printf("\n\t | Porta Avioes       | 4 casas |     1       | ");
		printf("\n\t | Submarino          | 3 casas |     3       | ");
		printf("\n\t | Destroier          | 2 casas |     3       | ");
		printf("\n\t | Bote               | 1 casas |     2       | ");
		printf("\n\t **************** \n\n\n");
		system("PAUSE");
		printf("\n");
	
		
		gerar_mapa();
		mapa_do_jogo();
		gerar_navios();
		gerar_navios_pc();
		
		do{
		
			ataque_usuario(ataque,errou);
			ataque_pc(ataque,errou);
			
		} while((acertos.usuario || acertos.pc) == 21);
		
		if(acertos.usuario > acertos.pc){//ganhou
			
			carregando(); system("CLS");
			
			for(cont = 0; frase11[cont] != '\0'; cont = cont + 1)	{        putchar(frase11[cont]);        Sleep(20);    }
    		mapa_do_jogo();
    		Sleep(2500);
    		system("CLS");
    		printf("\n\n\t ASSIM QUE FICOU O PLACAR \n\n\n\t");
    		printf("\n\t SEUS ACERTOS .............: %d",acertos.usuario);
    		printf("\n\t ACERTOS DO PC ............: %d\n\n",acertos.pc);    		
    		printf("\n\t SUAS TENTATIVAS ..........: %d",tentativas.usuario);
    		printf("\n\t TENTATIVAS DO PC .........: %d\n\n",tentativas.pc);
    		printf("\n\t SEUS BARCOS DESTRUIDOS ...: %d",tentativas.usuario);
    		printf("\n\t BARCOS DESTRUIDOS DO PC ..: %d",tentativas.pc);
    		Sleep(2500);
			system("CLS");
		do{
		
			for(cont = 0; frase12[cont] != '\0'; cont = cont + 1)	{        putchar(frase12[cont]);        Sleep(20);    }
			scanf("%d",&resp2);
			
			if(resp2 == 1){
				Sleep(500);
				system("CLS");
				main();
				return 1;
			}
			if(resp2 == 2){
				
				Sleep(500);
				system("CLS");
				creditos();
				return 1;
				
			}
			if(resp2 == 3){
				
				Sleep(500);
				system("CLS");
				for(cont = 0; frase13[cont] != '\0'; cont = cont + 1)	{        putchar(frase13[cont]);        Sleep(20);    }
				Sleep(500);
				system("CLS");
				carregando();
				Sleep(500);
				system("CLS");
				
				return 0;
			}
			else {
				
				Sleep(500);
				system("CLS");
				for(cont = 0; frase14[cont] != '\0'; cont = cont + 1)	{        putchar(frase14[cont]);        Sleep(20);    }
				Sleep(500);
				system("CLS");
			}
			}while((resp2 =! 1) &&(resp2 =! 2) &&(resp2 =! 3) );
		}
		
		else{//perdeu
		
			carregando(); system("CLS");
			
			for(cont = 0; frase15[cont] != '\0'; cont = cont + 1)	{        putchar(frase15[cont]);        Sleep(20);    }
    		mapa_do_jogo();
    		Sleep(2500);
    		system("CLS");
    		printf("\n\n\t ASSIM QUE FICOU O PLACAR \n\n\n\t");
    		printf("\n\t SEUS ACERTOS .............: %d",acertos.usuario);
    		printf("\n\t ACERTOS DO PC ............: %d\n\n",acertos.pc);    		
    		printf("\n\t SUAS TENTATIVAS ..........: %d",tentativas.usuario);
    		printf("\n\t TENTATIVAS DO PC .........: %d\n\n",tentativas.pc);
    		printf("\n\t SEUS BARCOS DESTRUIDOS ...: %d",tentativas.usuario);
    		printf("\n\t BARCOS DESTRUIDOS DO PC ..: %d",tentativas.pc);
    		Sleep(2500);
			system("CLS");
		do{
		
			for(cont = 0; frase12[cont] != '\0'; cont = cont + 1)	{        putchar(frase12[cont]);        Sleep(20);    }
			scanf("%d",&resp2);
			
			if(resp2 == 1){
				Sleep(500);
				system("CLS");
				main();
		
			}
			if(resp2 == 2){
				
				Sleep(500);
				system("CLS");
				creditos();
			
				
			}
			if(resp2 == 3){
				
				Sleep(500);
				system("CLS");
				for(cont = 0; frase13[cont] != '\0'; cont = cont + 1)	{        putchar(frase13[cont]);        Sleep(20);    }
				Sleep(500);
				system("CLS");
				carregando();
				Sleep(500);
				system("CLS");
				
				return 0;
			}
			else {
				
				Sleep(500);
				system("CLS");
				for(cont = 0; frase14[cont] != '\0'; cont = cont + 1)	{        putchar(frase14[cont]);        Sleep(20);    }
				Sleep(500);
				system("CLS");
			}
			}while((resp2 =! 1) &&(resp2 =! 2) &&(resp2 =! 3) );
		}	
			
		

	}
	
	else if( resp1 == 2) {
		
			
				Sleep(500);
				system("CLS");
				creditos();
		
				
	}
	
	else if( resp1 == 3) {
	Sleep(500);
				system("CLS");
				for(cont = 0; frase13[cont] != '\0'; cont = cont + 1)	{        putchar(frase13[cont]);        Sleep(20);    }
				Sleep(500);
				system("CLS");
				carregando();
				Sleep(500);
				system("CLS");
				
				return 0;
	}
	else {
		
		Sleep(500);
				system("CLS");
				for(cont = 0; frase14[cont] != '\0'; cont = cont + 1)	{        putchar(frase14[cont]);        Sleep(20);    }
				Sleep(500);
				system("CLS");
	}
	
	
	}while((resp1 != 1)&&(resp1 != 2));
	
	
}