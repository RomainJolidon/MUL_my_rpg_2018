/*
** EPITECH PROJECT, 2019
** generate_dialog.c
** File description:
** generate villagers dialog
*/

#include "rpg.h"

void generate_dialog_start_end(game_t *game)
{
    setup_quest(game->villagers[0], 6);
    create_quest(game->villagers[0], "Hello Hero!");
    create_quest(game->villagers[0], \
"I am happy to welcome you to my village.");
    create_quest(game->villagers[0], "The king sent you to help us \
to kill the monsters.");
    create_quest(game->villagers[0], "They are more and more in the forest.");
    create_quest(game->villagers[0], "I trust you !");
    create_quest(game->villagers[0], "Good luck !!!");
    setup_quest(game->villagers[3], 4);
    create_quest(game->villagers[3], "Thank you for helping us, Hero !");
    create_quest(game->villagers[3], "Here, to thank you");
    create_quest(game->villagers[3], "Come back when you want !");
    create_quest(game->villagers[3], "You will always be welcome");
    add_goal(game->villagers[3], GIFT, 'g');
}

void generate_dialog_fight(game_t *game)
{
    setup_quest(game->villagers[5], 8);
    create_quest(game->villagers[5], "Hi Hero ! I'm glad to see you here !");
    create_quest(game->villagers[5], "This is our lake, it is the pride of \
the village.");
    create_quest(game->villagers[5], "Only here you can find golden fish.");
    create_quest(game->villagers[5], "... (roar)");
    create_quest(game->villagers[5], "What is this noise ?");
    create_quest(game->villagers[5], "Oh no ! monsters attack the \
fish of the lake!");
    create_quest(game->villagers[5], "Please protect them !");
    create_quest(game->villagers[5], "I will give you a gold coin \
in exchange.");
    add_goal(game->villagers[5], GOLD, 'f');
}

void generate_dialog(game_t *game)
{
    generate_dialog_start_end(game);
    generate_dialog_fight(game);
    setup_quest(game->villagers[1], 5);
    setup_quest(game->villagers[2], 6);
    create_quest(game->villagers[2], "Huh! Who are you ?");
    create_quest(game->villagers[2], "Do you think I'm preparing \
something bad ?");
    create_quest(game->villagers[2], "I do not like people like you,");
    create_quest(game->villagers[2], "you will never know that I capture \
monsters for my book !");
    create_quest(game->villagers[2], "Thin, I revealed my secret.");
    create_quest(game->villagers[2], "Die !");
    add_goal(game->villagers[2], BAD_BOOK, 'f');
    create_quest(game->villagers[1], "Hello Hero, can I ask for your help ?");
    create_quest(game->villagers[1], "I saw a strange, one-eyed man...");
    create_quest(game->villagers[1], "...capturing monsters in the forest.");
    create_quest(game->villagers[1], "He does not prepare anything good.");
    create_quest(game->villagers[1], "Please stop it !");
}