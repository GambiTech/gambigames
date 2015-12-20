#include <stdio.h>
#include <SDL2/SDL.h> //SDL2
#include <SDL2/SDL_ttf.h> //textos
#include <SDL2/SDL_image.h> //formatos de imagens e texturas
#include <SDL2/SDL_mixer.h> //sons multicanais
#include "include/telainicial.h"

int tela( void* data  ){
    int i;
    
   SDL_Init(SDL_INIT_VIDEO);
    //INICIA VIDEO COM SDL 

      SDL_Init(SDL_INIT_AUDIO);
 
 Mix_Init(MIX_INIT_MP3); //INICIA VIDEO COM SDL 
Mix_Music *gMusic = NULL;

Mix_OpenAudio(22050,AUDIO_S16SYS,2,640);  //Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );

gMusic = Mix_LoadMUS("../sons/Guarani.mp3");

Mix_PlayMusic( gMusic, 1 );
  



 SDL_Window *janela=NULL; // CRIA UMA JANELA 
 SDL_Renderer *renderer=NULL;// CRIA UM RENDERER 
 
 janela=  SDL_CreateWindow("janela0",0,0,800,600,SDL_WINDOW_FULLSCREEN_DESKTOP); //DEFINE A JANELA 
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
 // inicia a sdl_ttf
 if(TTF_Init()==-1) {
    printf("erro TTF_Init: %s\n", TTF_GetError());
    SDL_DestroyRenderer(renderer); //ENCERRA O RENDENRER
    SDL_DestroyWindow(janela); //ENCERRA A JANELA 
	SDL_Quit();
	TTF_Quit();
	return 1;
}
SDL_Color corDoTexto = { 255, 255, 255, 255 };
TTF_Font *gFonte;
gFonte=TTF_OpenFont("../fontes/YO_ELLIPSE_.ttf", 128);



SDL_Surface* sM = TTF_RenderText_Solid(gFonte, "GAMBITECH", corDoTexto);
SDL_Surface* sMM = TTF_RenderText_Solid(gFonte, "incorporations", corDoTexto);
SDL_Texture* tm = SDL_CreateTextureFromSurface(renderer, sM);
SDL_Texture* tmm = SDL_CreateTextureFromSurface(renderer, sMM);

SDL_Rect mR; //create a rect
mR.x = 50;  //controls the rect's x coordinate 
mR.y = 50; // controls the rect's y coordinte
mR.w = 1200; // controls the width of the rect
mR.h = 600; // controls the height of the rect

SDL_Rect mmR; //create a rect
mmR.x = 20;  //controls the rect's x coordinate 
mmR.y = 650; // controls the rect's y coordinte
mmR.w = 1200; // controls the width of the rect
mmR.h = 200; // controls the height of the rect

SDL_RenderCopy(renderer, tm, NULL, &mR);
SDL_RenderCopy(renderer, tmm, NULL, &mmR);

SDL_RenderPresent(renderer);

int j;
SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );// cor de fundo 
 SDL_RenderClear(renderer); //limpa o renderer
SDL_RenderPresent(renderer); //rederiza

SDL_Delay(1500);//DA UM TEMPO DE .5 SEGUNDO COM A JANELA 

for(i=255;i>=0;i--){

SDL_SetRenderDrawColor( renderer, i, i, i, 255 );// cor de fundo 
 SDL_RenderClear(renderer); //limpa o renderer
 SDL_RenderCopy(renderer, tm, NULL, &mR);
SDL_RenderCopy(renderer, tmm, NULL, &mmR);

corDoTexto.r=255-i;
corDoTexto.g=255-i;
corDoTexto.b=255-i;

sM = TTF_RenderText_Solid(gFonte, "GAMBITECH", corDoTexto);
 sMM = TTF_RenderText_Solid(gFonte, "incorporations", corDoTexto);
 tm = SDL_CreateTextureFromSurface(renderer, sM);
tmm = SDL_CreateTextureFromSurface(renderer, sMM);
SDL_RenderPresent(renderer); //rederiza

SDL_Delay(5);//DA UM TEMPO DE .01 SEGUNDO COM A JANELA 

}

corDoTexto.r=255;
corDoTexto.g=255;
corDoTexto.b=255;
// fim do efeito
 SDL_Delay(1500);
 SDL_RenderClear(renderer); //limpa o renderer

TTF_Font *fonte;
fonte=TTF_OpenFont("../fontes/FFF-Tusj/FFF_Tusj.ttf", 128);
TTF_Font *fontePeq;
fontePeq=TTF_OpenFont("../fontes/Capture-it/Capture_it.ttf", 128);


if(!gFonte) {
    printf("erro TTF_OpenFont: %s\n", TTF_GetError());
    // handle error
}

if(!fonte) {
    printf("erro TTF_OpenFont: %s\n", TTF_GetError());
    // handle error
}



SDL_Surface* surfaceMessage = TTF_RenderText_Solid(fonte, "GAMBIGAMES    Studios", corDoTexto);


SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

SDL_Rect Message_rect; //create a rect
Message_rect.x = 50;  //controls the rect's x coordinate 
Message_rect.y = 50; // controls the rect's y coordinte
Message_rect.w = 1200; // controls the width of the rect
Message_rect.h = 400; // controls the height of the rect

//Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

//Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

 SDL_RenderPresent(renderer);
 
SDL_Delay(2000);

SDL_Rect MP_rect; //create a rect
MP_rect.x = 140;  //controls the rect's x coordinate 
MP_rect.y = 490; // controls the rect's y coordinte
MP_rect.w = 600; // controls the width of the rect
MP_rect.h = 100; // controls the height of the rect

if(!fontePeq) {
    printf("erro TTF_OpenFont: %s\n", TTF_GetError());
    // handle error
}
SDL_Surface* texPeq = TTF_RenderText_Solid(fontePeq, "apresenta:", corDoTexto);
SDL_Texture* MP = SDL_CreateTextureFromSurface(renderer,texPeq);

SDL_RenderCopy(renderer, MP, NULL, &MP_rect);
 SDL_RenderPresent(renderer);
 
SDL_Delay(4000);

 SDL_DestroyRenderer(renderer); //ENCERRA O RENDENRER


    SDL_DestroyWindow(janela); //ENCERRA A JANELA 

TTF_CloseFont(fonte);
fonte=NULL; // to be safe..
TTF_Quit();
    
        

Mix_FreeMusic( gMusic );

Mix_Quit();

    SDL_Quit();
    return 0;
    }
