#include <math.h>
#include <SDL/SDL.h>
#include <time.h>
#define altura   20
#define largura  10
#define quadrado 23
#define LARGURA  230
#define ALTURA   460
#define BPP      0

#define BLUE     1
#define ORANGE   2
#define CIAN     3
#define PURPLE   4
#define GREEN    5
#define RED      6
#define YELLOW   7

SDL_Surface *tela, *blue, *orange, *cian, *purple, *green, *red, *yellow, *gray;
int velocidade = 5;
char mapa[altura][largura];


int nao_existe_peca() /* verifica se existe algum valor acima de 8 na matriz */
{
    int i, j;
    for(i = 0; i < 20; i++)
        for(j = 0; j < 10; j++)
            if(mapa[i][j]/8 == 1)
                return 0;
    return 1;
}
void poe_peca() /* sorteia uma peca e poe */
{
    int ale;
    ale = rand()%7;
    if(ale == 0) /* blue */
    {
    	if(!(mapa[0][4] == 0 && mapa[1][4] == 0 && mapa[1][5] == 0 && mapa[1][6] == 0))
    		return ;
        mapa[0][4] = BLUE+8;
        mapa[1][4] = BLUE+8;
        mapa[1][5] = BLUE+8;
        mapa[1][6] = BLUE+8;    
    }
    else if(ale == 1) /* orange */
    {
    	if(!(mapa[0][6] == 0 && mapa[1][6] == 0 && mapa[1][5] == 0 && mapa[1][4] == 0))
    		return ;
        mapa[0][6] = ORANGE+8;
        mapa[1][6] = ORANGE+8;
        mapa[1][5] = ORANGE+8;
        mapa[1][4] = ORANGE+8;
    }
    else if(ale == 2)
    {
    	if(!(mapa[0][3] == 0 && mapa[0][4] == 0 && mapa[0][5] == 0 && mapa[0][6] == 0))
    		return ;
        mapa[0][3] = CIAN+8;
        mapa[0][4] = CIAN+8;
        mapa[0][5] = CIAN+8;
        mapa[0][6] = CIAN+8;
    }
    else if(ale == 3)
    {
    	if(!(mapa[0][4] == 0 && mapa[1][3] == 0 && mapa[1][4] == 0 && mapa[1][5] == 0))
    		return ;
        mapa[0][4] = PURPLE+8;
        mapa[1][3] = PURPLE+8;
        mapa[1][4] = PURPLE+8;
        mapa[1][5] = PURPLE+8;
    }
    else if(ale == 4)
    {
    	if(!(mapa[1][4] == 0 && mapa[1][5] == 0 && mapa[0][5] == 0 && mapa[0][6] == 0))
    		return ;
        mapa[1][4] = GREEN+8;
        mapa[1][5] = GREEN+8;
        mapa[0][5] = GREEN+8;
        mapa[0][6] = GREEN+8;
    }
    else if(ale == 5)
    {
    	if(!(mapa[0][4] == 0 && mapa[0][5] == 0 && mapa[1][5] == 0 && mapa[1][6] == 0))
    		return ;
        mapa[0][4] = RED+8;
        mapa[0][5] = RED+8;
        mapa[1][5] = RED+8;
        mapa[1][6] = RED+8;
    }
    else if(ale == 6)
    {
    	if(!(mapa[0][4] == 0 && mapa[0][5] == 0 && mapa[1][4] == 0 && mapa[1][5] == 0))
    		return ;
        mapa[0][4] = YELLOW+8;
        mapa[0][5] = YELLOW+8;
        mapa[1][4] = YELLOW+8;
        mapa[1][5] = YELLOW+8;
    }
}

void opera_mapa()
{
    int i, j, k;
    char colidiu = 0;
    /* verifica se o proximo movimento há colisao */
    for(j = 0; j < largura; j++)
        if(mapa[altura-1][j]/8 == 1)
            colidiu = 1;
    for(i = altura-2; i >= 0; i--)
        for(j = 0; j < largura; j++)
            if(mapa[i][j]/8 == 1 && mapa[i+1][j] != 0 && mapa[i+1][j] < 8)
                colidiu = 1;

    for(i = altura-1; i > 0; i--)
    {
    	if(mapa[i][0] == -1)
    	{
    		for(k = i-1; k>=0; k--)
    			for(j = 0; j < largura; j++)
    				mapa[k+1][j] = mapa[k][j];
    		for(j = 0; j < largura; j++)
    			mapa[0][j] = 0;
    	}

    }
    /* move caso não colida*/
    if(!colidiu)
    {
        for(i = altura-2; i >= 0; i--)
            for(j = 0; j < largura; j++)
                if(mapa[i][j]/8 == 1)
                {
                    mapa[i+1][j] = mapa[i][j];
                    mapa[i][j] = 0;
                }
    }
    else
    {
        /* como colidiu, transforma todos os 2 em 1 */
        for(i = 0; i < 20; i++)
            for(j = 0; j < 10; j++)
                if(mapa[i][j]/8 == 1)
                    mapa[i][j] %= 8;
        /* verifica se e necessario eliminar linha */
        for(i = altura-1; i >= 0; i--)
        {
            colidiu = 0;
            for(j = 0; j < largura; j++)
                if(mapa[i][j] == 0)
                    colidiu = 1;
            if(!colidiu)
                for(j = 0; j < largura; j++)
                	mapa[i][j] = -1;
        }
    }
    
}

void controla_fps ( int tempo_inicial )
{
    int fps = 400/velocidade; /* converte 60 FPS para milissegundos */
    int tempo_agora = SDL_GetTicks() - tempo_inicial;
    velocidade = 5;
    if(tempo_agora < fps)
        SDL_Delay(fps - tempo_agora);
}

/* Funcao de inicializacao */
int carrega_imagens (  )
{
    /* Carrega as Imagens */
    blue = SDL_LoadBMP("Imagens/blue.bmp");
    if (blue == NULL)
    {
        printf("Não carregou blue.bmp\n");
        return 0;
    }

    red = SDL_LoadBMP("Imagens/red.bmp");
    if (red == NULL)
    {
        printf("Não carregou red.bmp\n");
        return 0;
    }

    cian = SDL_LoadBMP("Imagens/cian.bmp");
    if (cian == NULL)
    {
        printf("Não carregou cian.bmp\n");
        return 0;
    }

    purple = SDL_LoadBMP("Imagens/purple.bmp");
    if (purple == NULL)
    {
        printf("Não carregou purple.bmp\n");
        return 0;
    }

    orange = SDL_LoadBMP("Imagens/orange.bmp");
    if (orange == NULL)
    {
        printf("Não carregou orange.bmp\n");
        return 0;
    }

    green = SDL_LoadBMP("Imagens/green.bmp");
    if (green == NULL)
    {
        printf("Não carregou green.bmp\n");
        return 0;
    }

    yellow = SDL_LoadBMP("Imagens/yellow.bmp");
    if (yellow == NULL)
    {
        printf("Não carregou yellow.bmp\n");
        return 0;
    }

    gray = SDL_LoadBMP("Imagens/gray.bmp");
    if (gray == NULL)
    {
        printf("Não carregou gray.bmp\n");
        return 0;
    }

    return 1;
}

void desenha_mapa (  )
{
    SDL_Rect destino;
    int i, j;

    for (i = 0; i < altura; i++)
    {
        destino.y = i * quadrado;
        for (j = 0; j < largura; j++)
        {
            destino.x = j * quadrado;
            if (mapa[i][j]%8 == BLUE)
            {
                SDL_BlitSurface(blue, NULL, tela, &destino);
            }
            else if (mapa[i][j]%8 == RED)
            {
                /* pegue a imagem grama completa(NULL) e jogue na tela em destino */
                SDL_BlitSurface(red, NULL, tela, &destino);
            }
            else if (mapa[i][j]%8 == GREEN)
            {
                /* pegue a imagem final completa(NULL) e jogue na tela em destino */
                SDL_BlitSurface(green, NULL, tela, &destino);
            }
            else if (mapa[i][j]%8 == YELLOW)
            {
                /* pegue a imagem final completa(NULL) e jogue na tela em destino */
                SDL_BlitSurface(yellow, NULL, tela, &destino);
            }
            else if (mapa[i][j]%8 == PURPLE)
            {
                /* pegue a imagem grama completa(NULL) e jogue na tela em destino */
                SDL_BlitSurface(purple, NULL, tela, &destino);
            }
            else if (mapa[i][j]%8 == CIAN)
            {
                /* pegue a imagem final completa(NULL) e jogue na tela em destino */
                SDL_BlitSurface(cian, NULL, tela, &destino);
            }
            else if (mapa[i][j]%8 == ORANGE)
            {
                /* pegue a imagem final completa(NULL) e jogue na tela em destino */
                SDL_BlitSurface(orange, NULL, tela, &destino);
            }
            else if (mapa[i][j] == -1)
            {
            	SDL_BlitSurface(gray, NULL, tela, &destino);
            }
        }
    }
}

void imprime()
{
    int i, j;
    for(i = 0; i < altura; i++)
    {
        for(j = 0; j < largura; j++)
            printf("%d ", mapa[i][j]);
        printf("|\n");
    }
    for(j = 0; j < largura; j++)
        printf("--");
}

void rotaciona()
{
    int i, j, achou = 0;
    for(i = 0; i < altura && !achou; i++)
        for(j = 0; j < largura && !achou; j++)
            if(mapa[i][j]/8 == 1)
            {
                achou = 1;
            }
    i--;
    j--;
    if(mapa[i][j]-8 == CIAN)
    {
        /* PARA O CASO EM QUE ESTA DEITADO */
        if(mapa[i][j+1]-8 == CIAN)
        {
        	j+=1;
            if(j+2 < largura && j>0 && i > 0 && i+2 < altura)
                if(mapa[i-1][j] == 0 && mapa[i+1][j] == 0 && mapa[i+2][j] == 0)
                {
                    mapa[i][j-1] = 0;
                    mapa[i][j+1] = 0;
                    mapa[i][j+2] = 0;
                    mapa[i-1][j] = CIAN+8;
                    mapa[i+1][j] = CIAN+8;
                    mapa[i+2][j] = CIAN+8;
                }
        }
        else
        {
        	i+=1;
        	if(j+2 < largura && j>0 && i > 0 && i+2 < altura)
        		if(mapa[i][j-1] == 0 && mapa[i][j+1] == 0 && mapa[i][j+2] == 0)
        		{
					mapa[i][j-1] = CIAN+8;
					mapa[i][j+1] = CIAN+8;
					mapa[i][j+2] = CIAN+8;
					mapa[i-1][j] = 0;
					mapa[i+1][j] = 0;
					mapa[i+2][j] = 0;
        		}
        }
    }   
    else if(mapa[i][j]-8 == GREEN)
    {
    	if(mapa[i][j+1]-8 == GREEN)
    	{
    		if(i > 0)
    			if(mapa[i-1][j] == 0 && mapa[i+1][j+1] == 0)
    			{
    				mapa[i+1][j-1] = 0;
    				mapa[i+1][j] = 0;
    				mapa[i-1][j] = GREEN + 8;
    				mapa[i+1][j+1] = GREEN+8;
    			}
    	}
    	else
    	{
    		i+=1;
    		if(j > 0)
    		{
    			if(mapa[i+1][j-1] == 0 && mapa[i+1][j] == 0)
    			{
    				mapa[i-1][j] = 0;
    				mapa[i+1][j+1] = 0;
    				mapa[i+1][j-1] = GREEN + 8;
    				mapa[i+1][j] = GREEN + 8;
    			}
    		}
    	}
    } 
    else if(mapa[i][j]-8 == RED)
    {
    	if(mapa[i][j+1]-8 == RED)
    	{
    		if(i > 0)
    			if(mapa[i+1][j] == 0 && mapa[i-1][j+1] == 0)
    			{
    				mapa[i+1][j+1] = 0;
    				mapa[i+1][j+2] = 0;
    				mapa[i+1][j] = RED + 8;
    				mapa[i-1][j+1] = RED + 8;
    			}
    	}
    	else
    	{
    		i+=1;
    		j-=1;
    		if(j > 0)
    		{
    			if(mapa[i+1][j+1] == 0 && mapa[i+1][j+2] == 0)
    			{
    				mapa[i+1][j+1] = RED + 8;
    				mapa[i+1][j+2] = RED + 8;
    				mapa[i+1][j] = 0;
    				mapa[i-1][j+1] = 0;
    			}
    		}
    	}
    }
    else if(mapa[i][j]-8 == BLUE)
    {
		if(mapa[i+1][j]-8 == BLUE && mapa[i+1][j+1]-8 == BLUE && i+2 < altura)
		{
			if(mapa[i][j+1] == 0 && mapa[i+2][j] == 0) /* Se e possivel rotacionar entrando no caso */
			{
				mapa[i+1][j+1] = 0;
				mapa[i+1][j+2] = 0;
				mapa[i][j+1] = BLUE + 8;
				mapa[i+2][j] = BLUE + 8;
			}
		}
		else if(mapa[i+1][j]-8 == BLUE && mapa[i][j+1]-8 == BLUE && j+1 < largura && j > 0)
		{
			if(mapa[i+1][j+1] == 0 && mapa[i][j-1] == 0)
			{
				mapa[i+1][j] = 0;
				mapa[i+2][j] = 0;
				mapa[i+1][j+1] = BLUE + 8;
				mapa[i][j-1] = BLUE + 8;
			}
		}
		else if(mapa[i][j+2]-8 == BLUE && j+2 < largura)
		{
			j++;
			if(mapa[i+1][j] == 0 && mapa[i-1][j+1] == 0)
			{
				mapa[i][j-1] = 0;
				mapa[i][j] = 0;
				mapa[i+1][j] = BLUE + 8;
				mapa[i-1][j+1] = BLUE + 8;
			}
		}
		else if(j+1 < largura)
		{
			i++;
			j--;
			if(mapa[i+1][j+2] == 0 && mapa[i][j] == 0)
			{
				mapa[i][j+1] = 0;
				mapa[i-1][j+1] = 0;
				mapa[i][j] = BLUE + 8;
				mapa[i+1][j+2] = BLUE + 8;
			}
		}
    }
    else if(mapa[i][j]-8 == ORANGE)
    {
    	
    	if(mapa[i+1][j]-8 == ORANGE && mapa[i+1][j-1]-8 == ORANGE && i+2 < altura)
		{
			if(mapa[i][j-1] == 0 && mapa[i+2][j] == 0)
			{
				mapa[i+1][j-1] = 0;
				mapa[i+1][j-2] = 0;
				mapa[i][j-1] = ORANGE + 8;
				mapa[i+2][j] = ORANGE + 8;
			}
		}
		
		else if(mapa[i][j+1]-8 == ORANGE && mapa[i+1][j+1]-8 == ORANGE && j+2 < largura && j > 0)
		{
			if(mapa[i+1][j] == 0 && mapa[i][j+2] == 0)
			{
				mapa[i+1][j+1] = 0;
				mapa[i+2][j+1] = 0;
				mapa[i+1][j] = ORANGE + 8;
				mapa[i][j+2] = ORANGE + 8;
			}
		}
		
		else if(mapa[i][j+2]-8 == ORANGE && i > 0 && j+2 < largura)
		{
			if(mapa[i+1][j+1] == 0 && mapa[i-1][j] == 0)
			{
				mapa[i][j+2] = 0;
				mapa[i][j+1] = 0;
				mapa[i+1][j+1] = ORANGE + 8;
				mapa[i-1][j] = ORANGE + 8;
			}
		}
		else if(j > 0)
		{
			i++;
			if(mapa[i][j+1] == 0 && mapa[i+1][j-1] == 0)
			{
				mapa[i][j] = 0;
				mapa[i-1][j] = 0;
				mapa[i][j+1] = ORANGE + 8;
				mapa[i+1][j-1] = ORANGE + 8;
			}
		}
    }
    else if(mapa[i][j]-8 == PURPLE)
    {

    	if(j + 2 < largura && i+2 < altura && mapa[i][j+1]-8 == PURPLE) 
    	{
    		if(mapa[i+1][j+2] == 0 && mapa[i+2][j+1] == 0)
    		{
    			
    			mapa[i][j] = 0;
    			mapa[i][j+2] = 0;
    			mapa[i+1][j+2] = PURPLE + 8;
    			mapa[i+2][j+1] = PURPLE + 8; 
    		}
    	}
        else if(j+1 < largura && i+1 < altura && j > 0 && mapa[i+1][j-1]-8 == PURPLE && mapa[i+1][j+1]-8 == PURPLE)
        {
        	if(mapa[i+2][j] == 0)
        	{
        		mapa[i+1][j+1] = 0;
        		mapa[i+2][j] = PURPLE + 8;
        	}
        }
        else if(j > 0 && j+1 < largura && mapa[i][j-1] == 0 && mapa[i][j+1] == 0 && i+2 < altura && mapa[i+1][j-1]-8 == PURPLE)
        {
        	mapa[i][j-1] = PURPLE + 8;
        	mapa[i][j+1] = PURPLE + 8;
        	mapa[i+1][j-1] = 0;
        	mapa[i+2][j] = 0;
        }
        else
        {
        	/* 
					 *        *
					**   ->  ***
					 *

			*/
        	if(mapa[i+1][j-1] == 0 && i+2 < altura && j+1 < largura)
        	{
	        	mapa[i+2][j] = 0;
	        	mapa[i+1][j-1] = PURPLE + 8;
	        }
        }
    }
    else if(mapa[i][j]-8 == YELLOW)
    {
        /* FAZ NADA */
    }
}

void aperta_tecla ( SDL_Event event )
{
    int i, j, colidiu=0;
    switch (event.key.keysym.sym)
    {
        /* Na vertical */
        case SDLK_UP:
            rotaciona();
            break;

        case SDLK_DOWN:
            velocidade = 30;
            break;

            /* Na horizontal */
        case SDLK_LEFT:
            for(i = 0; i < altura; i++)
                if(mapa[i][0]/8 == 1)
                    colidiu = 1;
            if(!colidiu)
            {
                for(i = 0; i < altura; i++)
                    for(j = 1; j < largura; j++)
                        if(mapa[i][j]/8 == 1 && mapa[i][j-1] != 0 && mapa[i][j-1] < 8)
                            colidiu = 1;
                if(!colidiu)
                    for(j = 1; j<largura; j++)
                        for(i = 0; i<altura; i++)
                            if(mapa[i][j]/8 == 1)
                            {
                                mapa[i][j-1] = mapa[i][j];
                                mapa[i][j] = 0;
                            }
            }
            break;

        case SDLK_RIGHT:
            for(i = 0; i < altura; i++)
                if(mapa[i][largura-1]/8 == 1)
                    colidiu = 1;
            if(!colidiu)
            {
                for(i = 0; i < altura; i++)
                    for(j = largura-2; j >= 0; j--)
                        if(mapa[i][j]/8 == 1 && mapa[i][j+1] != 0 && mapa[i][j+1] < 8)
                            colidiu = 1;
                if(!colidiu)
                    for(j = largura-2; j>=0; j--)
                        for(i = 0; i<altura; i++)
                            if(mapa[i][j]/8 == 1)
                            {
                                mapa[i][j+1] = mapa[i][j];
                                mapa[i][j] = 0;
                            }
            }
            break;

        default:
            break;
    }
}

void limpa_mapa()
{
    int i, j;
    for(i = 0; i < altura; i++)
        for(j = 0; j < largura; j++)
            mapa[i][j] = 0;
       
}

int main(int argc, char **argv)
{

    int tempo_inicial;
    int i;
    int flag;
    SDL_Event evento; /* para os eventos */

    srand((unsigned)time(NULL));

    /*inicializando a SDL e verificando possiveis erros */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Erro: %s\n", SDL_GetError());
        exit(-1);
    }

    /* Carrega as imagens */
    if (carrega_imagens() == 0) /* Se não carregou uma ou outra imagem */
    {
        return 1; /* encerre o programa */
    }

    /* Configura o Video */
    tela = SDL_SetVideoMode(LARGURA, ALTURA, BPP, SDL_SWSURFACE | SDL_ANYFORMAT);
    if(tela == NULL)
    {
        printf("Erro: %s\n", SDL_GetError());
        return 1; /* encerre o programa */
    }

    limpa_mapa();
    

    /* Loop principal */
    flag = 0;
    while (1) /* Enquanto NÃO for verdadeiro o fim */
    {
        
    	for(i = 0; i < 3; i++)
    	{
	        /* Para a funcao controla_fps */
	        tempo_inicial = SDL_GetTicks();
	        if(nao_existe_peca())
	        {
	            poe_peca();
	        }
	        /* Loop de eventos */
	        
	        while(SDL_PollEvent(&evento))
	        {
	            if(evento.type == SDL_QUIT)
	            {
	                /* Finalizando o SDL */
	                SDL_Quit();
	                return 0;
	            }

	            /* move o jogador */
	            if (evento.type == SDL_KEYDOWN)
	            {
	            	flag = 1;
	            }
	            else if (evento.type == SDL_KEYUP)
	            {
	            	flag = 0;
	            }
	            
	        }
	        if(flag)
	        {
		        aperta_tecla(evento);
		        if(evento.key.keysym.sym == SDLK_UP)
		        	flag = 0;
	        }

	        
	        /*imprime();*/
	        
	        /* Pinta a tela inteira de branco antes de desenhar o mapa, esse branco eh o caminho */
	        SDL_FillRect(tela, NULL, SDL_MapRGB(tela->format, 255, 255, 255));
	        /* Desenha o mapa sobre a tela */
	        desenha_mapa();


	        SDL_UpdateRect(tela,0,0,0,0); /* Atualiza a tela inteira */
	        controla_fps(tempo_inicial); /* controla o FPS */
	    }
	    opera_mapa();
    }
    return 0;
}