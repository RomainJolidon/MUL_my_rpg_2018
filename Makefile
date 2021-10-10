##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_world main Makefile
##

SRC =   src/setup_game/main.c  							\
		src/setup_game/create_dialog.c					\
		src/setup_game/str_to_array.c					\
		src/setup_game/menu.c 							\
		src/setup_game/option.c 						\
		src/setup_game/pause.c 							\
		src/setup_game/control.c 						\
		src/setup_game/fill_struct.c					\
		src/setup_game/preparator.c						\
		src/setup_game/is_file_valid.c					\
		src/setup_game/my_memset.c						\
		src/setup_game/create_quest.c					\
		src/setup_game/setup_text.c						\
		src/setup_game/action_buttons.c					\
		src/setup_game/create_button.c 					\
		src/setup_game/sorter.c							\
		src/setup_game/get_file_data.c					\
		src/setup_game/texture/get_map.c				\
		src/setup_game/texture/connect_texture.c		\
		src/setup_game/texture/get_decor.c				\
		src/setup_game/texture/get_texture_from_file.c	\
		src/setup_game/texture/connect_texture_side.c	\
		src/setup_game/texture/check_assets.c			\
		src/setup_game/texture/parallax.c				\
		src/setup_game/save_and_load/load_save.c		\
		src/setup_game/save_and_load/save_game.c		\
		src/setup_game/memory/free_game.c				\
		src/setup_game/memory/free_scenes.c				\
		src/setup_game/memory/free_elements.c			\
		src/setup_game/memory/free_interaction.c		\
		src/setup_game/memory/free_map.c				\
		src/graphics_function/camera.c					\
		src/graphics_function/anime_world.c				\
		src/graphics_function/display_dialogs.c			\
		src/graphics_function/display_scenes.c			\
		src/graphics_function/click_button.c			\
		src/graphics_function/sprite_modifiers.c		\
        src/graphics_function/display_window.c			\
		src/graphics_function/draw_button.c 			\
		src/graphics_function/display_graphics.c		\
		src/graphics_function/ambiance.c				\
		src/graphics_function/display_dynamic.c			\
		src/player/move_player.c						\
		src/player/adjust_player_position.c				\
		src/player/setup_inventory.c					\
		src/player/player.c								\
		src/player/create_players.c						\
		src/player/target_player.c						\
		src/player/destroy_player.c						\
		src/player/init_rectangleshape.c				\
		src/player/power.c								\
		src/player/set_character_direction.c			\
		src/player/free_characters.c					\
		src/villagers/setup_dialog.c					\
		src/villagers/move_villagers.c					\
		src/villagers/talk_to_villager.c				\
		src/villagers/adjust_villager_position.c		\
		src/villagers/generate_dialog.c					\
		src/villagers/get_villagers.c					\
		src/story/setup_story.c							\
		src/story/display_story.c						\
		src/story/setup_quest.c							\
		src/story/follow_story.c						\
		src/fight/start_battle.c						\
		src/fight/load_fight_elements.c					\
		src/fight/display_fight.c						\
		src/fight/prepare_fight.c						\
		src/fight/prepare_button.c						\
		src/fight/prepare_text.c						\
		src/fight/manage_fight.c						\
		src/fight/prepare_target.c 						\
		src/fight/action.c								\
		src/fight/death.c 								\
		src/fight/prepare_heal.c 						\
		src/fight/function_fight/destroy_fight.c		\
		src/fight/function_fight/find_next_player.c		\
		src/fight/function_fight/function_target.c 		\
		src/fight/function_fight/target_ally.c			\
		src/fight/abilities/hit.c 						\
		src/fight/abilities/damage.c 					\
		src/fight/abilities/heal.c 						\
		src/fight/abilities/attack.c					\
		src/fight/abilities/fire.c						\
		src/fight/abilities/blizzard.c					\
		src/fight/event_fight.c							\
		src/enemies/init_enemies.c						\
		src/enemies/enemy_attack.c 						\
		src/enemies/random_enemy.c						\
		src/inventory/object_actions.c					\
		src/inventory/init_inv.c						\
		src/inventory/destroy_inv.c						\
		src/inventory/add_object.c						\
		src/inventory/get_inv_info.c					\
		src/inventory/update_inv.c						\
		src/effects/cursor.c							\
		src/effects/actions_effect.c					\
		src/effects/display_particle.c					\
		src/effects/particle.c							\
		src/effects/particle_effect.c					\
		src/effects/display_cursor.c					\
		src/effects/init_particle_value.c				\
		src/effects/transition.c						\
		src/fight/check_allies_dead.c

OBJ =		$(SRC:.c=.o)

NAME = 		my_rpg

CFLAGS =	-Wall -Wextra -Wshadow -I include/ -I lib/my

CC = gcc

LDFLAGS =	-lmy -L lib/my -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all:	$NAME

$NAME:	$(OBJ)
	make -C lib/my
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)
	make clean -C lib/my

fclean:	clean
	rm -rf $(NAME)
	make fclean -C lib/my

re:	fclean all

debug:	CFLAGS += -g
debug:	re
