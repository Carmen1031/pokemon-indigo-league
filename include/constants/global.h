#ifndef GUARD_CONSTANTS_GLOBAL_H
#define GUARD_CONSTANTS_GLOBAL_H

#define POKEMON_SLOTS_NUMBER 412

#define ITEM_NAME_LENGTH 14
#define POKEMON_NAME_LENGTH 10
#define OT_NAME_LENGTH 7

#define VERSION_SAPPHIRE    1
#define VERSION_RUBY        2
#define VERSION_EMERALD     3
#define VERSION_FIRE_RED    4
#define VERSION_LEAF_GREEN  5

#define LANGUAGE_JAPANESE   1
#define LANGUAGE_ENGLISH    2
#define LANGUAGE_FRENCH     3
#define LANGUAGE_ITALIAN    4
#define LANGUAGE_GERMAN     5
    // 6 goes unused but the theory is it was meant to be Korean
#define LANGUAGE_SPANISH    7

#ifdef ENGLISH
#define GAME_LANGUAGE (LANGUAGE_ENGLISH)
#endif

#define PC_ITEMS_COUNT      30
#define BAG_ITEMS_COUNT     42
#define BAG_KEYITEMS_COUNT  30
#define BAG_POKEBALLS_COUNT 13
#define BAG_TMHM_COUNT      58
#define BAG_BERRIES_COUNT   43

#define QUEST_LOG_SCENE_COUNT 4

#define MALE   0
#define FEMALE 1
#define GENDER_COUNT 2

#define OPTIONS_BUTTON_MODE_HELP         0
#define OPTIONS_BUTTON_MODE_LR           1
#define OPTIONS_BUTTON_MODE_L_EQUALS_A   2

#define OPTIONS_TEXT_SPEED_SLOW  0
#define OPTIONS_TEXT_SPEED_MID   1
#define OPTIONS_TEXT_SPEED_FAST  2

#define OPTIONS_SOUND_MONO    0
#define OPTIONS_SOUND_STEREO  1

#define OPTIONS_BATTLE_STYLE_SHIFT  0
#define OPTIONS_BATTLE_STYLE_SET    1

#define POCKET_ITEMS        1
#define POCKET_KEY_ITEMS    2
#define POCKET_POKE_BALLS   3
#define POCKET_TM_CASE      4
#define POCKET_BERRY_POUCH  5

#define NUM_BAG_POCKETS 5

#define MAX_MON_MOVES 4

#define PARTY_SIZE 6
#define MULTI_PARTY_SIZE (PARTY_SIZE / 2)

#define DIR_NONE        0
#define DIR_SOUTH       1
#define DIR_NORTH       2
#define DIR_WEST        3
#define DIR_EAST        4

#endif //GUARD_CONSTANTS_GLOBAL_H
