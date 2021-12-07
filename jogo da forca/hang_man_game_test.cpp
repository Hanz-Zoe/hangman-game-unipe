#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXWORD 2048	
#define MAXWORDLENGTH 64
int main ()
{
	 
	srand(time(NULL));
		
	char guesswords[MAXWORD][MAXWORDLENGTH];
	int WordRead = 0;
	
	FILE *pf = fopen("facil.txt", "r");
	if(pf == NULL);
	{
		printf("Falha ao abrir arquivo\n");
	}
	char input[64]; 
 
	while(fgets(input, 63, pf))
	{
		sscanf(input, "%s",guesswords[WordRead]);
		printf("Escaneadas: input: %s , guesswords[%d]: %s\n", input, WordRead, guesswords[WordRead]);
		WordRead++;
	}
	printf("Palavras totais: %d\n");

	fclose(pf);
	// index de palavra aleatória 
	int randomIndex = rand() % WordRead;
	
	int vidasnum = 5;
	int numCorrect = 0;
	int oldCorrect = 0;	
	
	int wordlength = strlen(guesswords[randomIndex]);
	int advinha[8] = {0,0,0,0,0,0,0,0};
	
	int quit = 0;
	 
	
	int loopIndex = 0; 
	
	char usradv[16]; 
	char palavraadv;
	
	printf("guesswords: %s randomIndex: %d tamanhopalavra: %d\n", guesswords[randomIndex], randomIndex, wordlength);
		
		//Loop de jogo
		while (numCorrect < wordlength)
		{
				 
			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					printf("%c",guesswords[randomIndex][loopIndex]);
				}
				else
				{
					printf("-");
				}
				
			
			
			}
			
			
			
			printf("\nJogo da Forca\n");
			
			printf("Corrigido até agora: %d\n",numCorrect);
			printf("  ");
			fgets(usradv, 16, stdin);
			
			if(strncmp(usradv,"quit",4) == 0)
			{
				quit = 1;
				break;
			}
			
			palavraadv = usradv[0];
			printf(">> %c", palavraadv);
		
			oldCorrect = numCorrect; 
			 
			for(loopIndex =0; loopIndex<wordlength; loopIndex++)
			{
				if(advinha[loopIndex] == 1)
				{
					continue;
				}
				if(palavraadv == guesswords[randomIndex][loopIndex])
				{
					advinha[loopIndex] = 1; 
					numCorrect++;	
				}
			
			
			}
			if( oldCorrect == numCorrect)
			{
				vidasnum--;
				printf("\nErrado\n");
				if(vidasnum == 0)
				{
					break; 
				}
			}
			else
			{
				printf("Parabens voce acertou!");
			}
		}//loop while
		
	
	if(quit == 1)
	{
		printf("Usuário desistiu");
	}
	else if(vidasnum == 0)
	{
		printf("\ndesculpe mas você perdeu, a palavra era: %s\n",
		guesswords[randomIndex]);
	}
	else
	{
		printf("Você venceu! =)");
	}
	
	return 0;
}
