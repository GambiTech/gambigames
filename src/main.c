/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */



/*
####################          COMENTARIOS GERAIS          ####################

PROGRAMA PRINCIPAL DO JOGO




*/

// INCLUSÃO DE BIBLIOTECAS
#include <stdio.h>    //ENTRADA PADRÃO 
#include <SDL2/SDL.h> //SDL2
#include <SDL2/SDL_ttf.h> //textos
#include <SDL2/SDL_image.h> //formatos de imagens e texturas
#include <SDL2/SDL_mixer.h> //sons multicanais

//FUNÇÃO PRINCIPAL
int main(int argc, char *argv[]){

// CRIA UMA NOVA JANELA
SDL_Init(SDL_INIT_VIDEO); //INICIA VIDEO COM SDL 
 SDL_Window *janela=NULL; // CRIA UMA JANELA 
 SDL_Renderer *renderer=NULL;// CIRA UM RENDERER 
 
 janela=  SDL_CreateWindow("janela0",0,0,800,600,SDL_WINDOW_RESIZABLE); //DEFINE A JANELA 
// JANELA CRIADA

// TESTA SE A "janela" FOI realmente CRIADA
 if (janela == NULL) {
        printf("Falha ao iniciar a janela!\n erro: %s\n", SDL_GetError()); //IMPRIME MENSAGEM DE ERRO COM O NUMERO DO ERRO INTERNO DO SDL
        return 1; //TERMINA O PROGRAMA COM ERRO
   }
// FIM DO TESTE

renderer =  SDL_CreateRenderer( janela, -1, SDL_RENDERER_ACCELERATED); //DEFINE RENDERER

// TESTA SE O "renderer" FOI realmente CRIADo
 if (janela == NULL) {
        printf("Falha ao iniciar o renderer!\n erro: %s\n", SDL_GetError()); //IMPRIME MENSAGEM DE ERRO COM O NUMERO DO ERRO INTERNO DO SDL
        return 1; //TERMINA O PROGRAMA COM ERRO
   }
// FIM DO TESTE


SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );// cor de fundo vermelho
        SDL_RenderClear(renderer); //limpa o renderer

SDL_RenderPresent(renderer);//rederiza

SDL_Delay(1000);  //DA UM TEMPO DE 1 SEGUNDO COM A JANELA 


SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );// cor de fundo verde
        SDL_RenderClear(renderer); //limpa o renderer

SDL_RenderPresent(renderer);//rederiza

SDL_Delay(1000);  //DA UM TEMPO DE 1 SEGUNDO COM A JANELA 


SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );// cor de fundo azul
        SDL_RenderClear(renderer); //limpa o renderer

SDL_RenderPresent(renderer);//rederiza

SDL_Delay(1000);  //DA UM TEMPO DE 1 SEGUNDO COM A JANELA 

    SDL_DestroyWindow(janela); // TERMINA A JANELA 

    
    SDL_Quit(); // ENCERRA O SDL

return 0; // TERMINA O PROGRAMA SEM ERROS

}
