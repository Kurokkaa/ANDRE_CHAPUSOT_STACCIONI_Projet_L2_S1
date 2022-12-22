#ifndef graphics_h
#define graphics_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "../structure/structure.h"
#include "../data/data.h"
#include "../constante.h"


void init_texture(SDL_Renderer *renderer, sprite_perso *perso);
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_perso* sprite);
void play_animations(SDL_Renderer *renderer, sprite_perso* sprite, int chara_state);
void refresh_graphics(SDL_Renderer *renderer, jeu *world);
void apply_textures(SDL_Texture * texture, SDL_Renderer *renderer, int x , int y);
void display_map(SDL_Renderer* renderer,jeu* world);
void display_dynamic_texture(SDL_Renderer* renderer, char** map_struct, SDL_Texture* texture);
void display_life(SDL_Renderer* renderer, jeu* world);

#endif