#include <stdio.h>
#include <SDL2/SDL.h> //SDL2
#include <SDL2/SDL_ttf.h> //textos
#include <SDL2/SDL_image.h> //formatos de imagens e texturas
#include <SDL2/SDL_mixer.h> //sons multicanais
#include "include/telainicial.h"
int tela(){
    int i;
    
   SDL_Init(SDL_INIT_VIDEO); //INICIA VIDEO COM SDL 
 SDL_Window *janela=NULL; // CRIA UMA JANELA 
 SDL_Renderer *renderer=NULL;// CRIA UM RENDERER 
 
 janela=  SDL_CreateWindow("janela0",0,0,800,600,SDL_WINDOW_RESIZABLE); //DEFINE A JANELA 
// JANELA CRIADA

// TESTA SE A "janela" FOI realmente CRIADA
 if (janela == NULL) {
        printf("Falha ao iniciar a janela!\n erro: %s\n", SDL_GetError()); //IMPRIME MENSAGEM DE ERRO COM O NUMERO DO ERRO INTERNO DO SDL
       SDL_Quit();
        return 1; //TERMINA O PROGRAMA COM ERRO
   }
// FIM DO TESTE

renderer =  SDL_CreateRenderer( janela, -1, SDL_RENDERER_ACCELERATED); //DEFINE RENDERER

// TESTA SE O "renderer" FOI realmente CRIADo
 if (renderer == NULL) {
        printf("Falha ao iniciar o renderer!\n erro: %s\n", SDL_GetError()); //IMPRIME MENSAGEM DE ERRO COM O NUMERO DO ERRO INTERNO DO SDL
        SDL_DestroyWindow(janela); //ENCERRA A JANELA 
        SDL_Quit();
	return 1; //TERMINA O PROGRAMA COM ERRO
   }
// FIM DO TESTE






// efeito fade out tela branca -> tela preta

SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );// cor de fundo 
 SDL_RenderClear(renderer); //limpa o renderer
SDL_RenderPresent(renderer); //rederiza

SDL_Delay(500);//DA UM TEMPO DE 1 SEGUNDO COM A JANELA 

for(i=255;i>=0;i--){

SDL_SetRenderDrawColor( renderer, i, i, i, 255 );// cor de fundo 
 SDL_RenderClear(renderer); //limpa o renderer
SDL_RenderPresent(renderer); //rederiza

SDL_Delay(10);//DA UM TEMPO DE 1 SEGUNDO COM A JANELA 

}
// fim do efeito
 
 // inicia a sdl_ttf
 if(TTF_Init()==-1) {
    printf("erro TTF_Init: %s\n", TTF_GetError());
    SDL_DestroyRenderer(renderer); //ENCERRA O RENDENRER
    SDL_DestroyWindow(janela); //ENCERRA A JANELA 
	SDL_Quit();
	TTF_Quit();
	return 1;
}

TTF_Font *fonte;
fonte=TTF_OpenFont("../fontes/FFF-Tusj/FFF_Tusj.ttf", 128);
TTF_Font *fontePeq;
fontePeq=TTF_OpenFont("../fontes/Capture-it/Capture_it.ttf", 128);


if(!fonte) {
    printf("erro TTF_OpenFont: %s\n", TTF_GetError());
    // handle error
}


SDL_Color corDoTexto = { 255, 255, 255, 255 };
SDL_Surface* surfaceMessage = TTF_RenderText_Solid(fonte, "GAMBIGAMES    Studios", corDoTexto);


SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

SDL_Rect Message_rect; //create a rect
Message_rect.x = 50;  //controls the rect's x coordinate 
Message_rect.y = 50; // controls the rect's y coordinte
Message_rect.w = 600; // controls the width of the rect
Message_rect.h = 200; // controls the height of the rect

//Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

//Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

 SDL_RenderPresent(renderer);
 
SDL_Delay(500);

SDL_Rect MP_rect; //create a rect
MP_rect.x = 140;  //controls the rect's x coordinate 
MP_rect.y = 290; // controls the rect's y coordinte
MP_rect.w = 150; // controls the width of the rect
MP_rect.h = 50; // controls the height of the rect

if(!fontePeq) {
    printf("erro TTF_OpenFont: %s\n", TTF_GetError());
    // handle error
}
SDL_Surface* texPeq = TTF_RenderText_Solid(fontePeq, "apresenta:", corDoTexto);
SDL_Texture* MP = SDL_CreateTextureFromSurface(renderer,texPeq);

SDL_RenderCopy(renderer, MP, NULL, &MP_rect);
 SDL_RenderPresent(renderer);
 
SDL_Delay(5000);
SDL_Delay(10000);
 SDL_DestroyRenderer(renderer); //ENCERRA O RENDENRER


    SDL_DestroyWindow(janela); //ENCERRA A JANELA 

TTF_CloseFont(fonte);
fonte=NULL; // to be safe..
TTF_Quit();
    
    SDL_Quit();
    
    return 0;
    }
