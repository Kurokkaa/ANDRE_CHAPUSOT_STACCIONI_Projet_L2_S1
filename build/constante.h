#ifndef constante_h
#define constante_h

    #define SCREEN_WIDTH 1280
    #define SCREEN_HEIGHT 720
    #define LINES 40
    #define COLUMNS 21
    #define CELL_HEIGHT 18
    #define CELL_WIDTH 64
    #define CHARA_SPEED 6
    #define AIR_CHARA_SPEED 4
    #define HEIGHT_PER_FRAME 9
    #define NB_MAPS 3
    #define KNOCKBACK_SPEED 6
    #define BUFFER_SIZE 60
    #define NB_COMBOS 3
    #define RANDOM_SPAWN_CHANCE 200
    #define MAX_LIFE 300
    #define MAX_SPECIAL 300
    #define DMG_DURATION 5
    #define BROKEN_GUARD_STUN 150
    #define MAX_GUARD 150
    #define DISTANCE_MAX 1280
    #define BLACK_HOLE_STRENGH 4
    #define NB_ANIM 22
    #define MAX_SIZE_COMBO 10
    #define ENDGAME_TIMER 3
    #define BERSERK_DMG 3
    #define SPECIAL_START 0
    #define GROWSBACK_HITBOX 40
    #define GROWSBACK_KNOCKBACK 200

    enum game_state{combat, main_menu, pause, options, selection_perso, selection_map, endgame, selection_IA};
    enum character_state{idle, walk, jump, crouch, fall, backwards, flight, flight_control, fall_control, landing, knockback, lpunch , kickstate,hpunch,stun,fireball,gravityball, winner , looser };
    enum game_map{city_night, forest, japan};
    enum combos_inputs{up, down, left, right, kick, light_p, heavy_p, special};
    enum bonus_type{health_bonus, damage_bonus, special_bonus};
    enum son{music, selector};

#endif