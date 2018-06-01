/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 09:45:40 by zphakath          #+#    #+#             */
/*   Updated: 2018/06/01 10:58:15 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

enum { RIGHT, LEFT, UP, DOWN};
enum { FALSE, TRUE };
typedef struct	s_l
{
	char		*line;
	struct s_l	*next;
}				t_line;

typedef struct	s_p
{
	int			y;
	int			x;
}				t_point;

typedef struct	s_d
{
	struct s_p	top;
	struct s_p	right;
	struct s_p	left;
	struct s_p	bottom;
}				t_dcn;

typedef struct	s_player
{
	int			number;
	char		piece_small;
	char		piece_large;
	struct s_l	*plateau;
	struct s_l	*piece_memory;
	int			p_countdown;
	int			piece_countdown;
	int			p_height;
	int			p_width;
	int			piece_height;
	int			piece_width;
	int			piece_true_height;
	int			done_reading;
	char		**plateau_piece;
	char		**piece_piece;
	int			num_played;
	struct s_d	decision;
	struct s_d	enemy;
	char		priority;
	char		second_priority;
	char		closed;
}				t_player;

char			get_player_info(char *line, t_player *player, int debug_fd);
char			get_plateau(char *line, t_player *player, int debug_fd);
char			get_piece(char	*line, t_player *player, int debug_fd);
void			play_piece(t_player *player, int debug_fd);
void			free_memory(t_player *player, int debug_fd);
char			place_piece(t_player *player, t_point *point, int debug_fd);
void			fill_plateau(t_player *player, int debug_fd);
void			fill_piece(t_player *player, int debug_fd);
char			scanforplay(int debug_fd, t_player *player, t_point *point,
					t_point *spoint);
void			get_all_enemy_pieces(int debug_fd, t_player *player);
void			get_player_pieces(int debug_fd, t_player *player);
void			close_plateau(t_player *player, t_point *point, int debug_fd);
void			print_piece(int y, int x);
char			close_place_piece(t_player *player, t_point *point,
					int debug_fd);
void			get_precise_up(t_player *player, t_point *point, int debug_fd);
void			get_advantage(int debug_fd, t_player *player, t_point *point);
int				get_right_piece(t_player *player, int y, int x, int debug_fd);
int				get_left_piece(t_player *player, int y, int x, int debug_fd);
void			get_pieces(int debug_fd, t_player *player);
char			place_piece_right_up(t_player *player, t_point *pp,
					int debug_fd);
int				fix_spot(t_player *player, int *y, int up_down, int tries);
void			check_tries(int tries, t_player *player, int check_side);
void			find_spot(t_player *player, t_point *point, int up_down,
					int debug_fd);
char			find_piece(t_player *player, t_point *point, int up_down,
					int left_right);
char			place_piece_left_up(t_player *player, t_point *pp,
					int debug_fd);
char			place_piece_right_bottom(t_player *pl, t_point *pp,
					int debug_fd);
char			place_piece_left_bottom(t_player *player, t_point *pp,
					int debug_fd);
#endif
