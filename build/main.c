#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "structure/structure.h"
#include "graphics/graphics.h"
#include "data/data.h"
#include "constante.h"

void init_jeu(jeu *world){
    world->state = combat;
    world->choice = russia;
    world->terminer = false;
    
}
void init_map(jeu* world,SDL_Renderer* renderer){
    switch(world->choice){
        case russia:
            world->map.map_russia.image_fond = load_image("build/map/russia/RussiaMap.png",renderer);
            world->map.map_russia.map_structure = read_file_map("build/map/russia/russia_structure");
            world->map.map_russia.plateformes = load_image("build/map/russia/plateforme.png",renderer);
            break;        
    }
}
void init_perso(SDL_Renderer* renderer, jeu* world, int x, int y, int w, int h, int speed){ //voir moyen pour charger texture spécifique
    world->p1.x = x;
    world->p1.y = y;
    world->p1.w = w;
    world->p1.h = h;
    world->p1.speed = speed;
    init_texture(renderer, &world->p1,world);
}

void init(SDL_Window** window, SDL_Renderer** renderer, jeu* world){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){ // Initialisation de la SDL
        printf("Erreur d'initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
    }

    *window = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
    if( window == NULL){ // En cas d’erreur
        printf("Erreur de la creation d'une fenetre: %s",SDL_GetError());
        SDL_Quit();
    }
    *renderer = SDL_CreateRenderer(*window,-1,SDL_RENDERER_ACCELERATED);
    
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ){
        printf( "Erreur initialisation de SDL_Image: %s\n", IMG_GetError() );
        SDL_Quit();
    }
    init_jeu(world);
    init_perso(*renderer,world,10,400,125,100,20);
    init_map(world,*renderer);
}

void gameplay_inputs(SDL_Event *event, jeu *world){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);;
    while(SDL_PollEvent(event)){
        if(event->type == SDL_QUIT){
            world->terminer == true;
        }     
    }
            //deplacement gauche
        if(keystates[SDL_SCANCODE_A] && !keystates[SDL_SCANCODE_D]){
            world->p1.x -= 10;
        }
        //deplacement droite
        if(!keystates[SDL_SCANCODE_A] && keystates[SDL_SCANCODE_D]){
            world->p1.x += 10;
        }
        //sauts
        if(keystates[SDL_SCANCODE_W]){
            
        }
        //coups
        if(keystates[SDL_SCANCODE_G] && !keystates[SDL_SCANCODE_U] && !keystates[SDL_SCANCODE_Y]){
        }
        //kicks
        if(!keystates[SDLK_g] && keystates[SDLK_u] && !keystates[SDLK_y]){
        }
        //coup spéciaux si la jauge est pleine
        if(keystates[SDLK_y] && keystates[SDLK_g] && keystates[SDLK_u]){

        }
        
}

int main(int argc, char *argv[]){
    SDL_Window* fenetre; // Déclaration de la fenêtre
    SDL_Renderer* renderer;// Déclaration du renderer
    SDL_Event events; //évenement du jeu
    jeu world; //structure principal
    
    init(&fenetre,&renderer,&world);

    refresh_graphics(renderer,&world);
    // Boucle principale
    while(!world.terminer){
        gameplay_inputs(&events, &world);
        //update_données
        refresh_graphics(renderer,&world);
        SDL_Delay(10);
    }

    // Quitter SDL
    SDL_DestroyWindow(fenetre);
    IMG_Quit;
    SDL_Quit();
    return 0;
}