#include "filler.h"

static	char	no_enemy_piece(int x, int y, t_player *player, int debug_fd, char pieceat)
{
	char	found_valid_piece;

	found_valid_piece = (player->plateau_piece[y][x] == '.' ||
			player->plateau_piece[y][x] == player->piece_small ||
			player->plateau_piece[y][x] == player->piece_large);
	found_valid_piece = (!found_valid_piece) ? (pieceat == '.') : found_valid_piece;
	return (found_valid_piece);
}

static	char	piece_overlap(int x, int y, t_player *player, int debug_fd, char pieceat)
{
	return ((player->plateau_piece[y][x] == player->piece_small ||
				player->plateau_piece[y][x] == player->piece_large) && pieceat == '*');
}

int				return_overlap(t_player *player, t_point *pp, int debug_fd)
{
	int		x;
	int		y;
	int		overlap;

	x = -1;
	y = -1;
	overlap = 0;
	while (++y < player->piece_height && ((y + pp->y) < player->p_height) &&
				((y + pp->y) > 0) && overlap < 2)
	{
		while (++x < player->piece_width && ((x + pp->x) >= 0) && ((x + pp->x) < player->p_width) &&
				((x + pp->x) >= 0) && no_enemy_piece(x + pp->x, y + pp->y, player, debug_fd, player->piece_piece[y][x]) &&
				overlap < 2)
		{
			if (piece_overlap(x + pp->x, y + pp->y, player, debug_fd, player->piece_piece[y][x]) &&
					overlap < 2)
				overlap++;
		}
		if (x != player->piece_width)
			overlap = 2;
		x = -1;
	}
	return (overlap);
}

void			fix_temp_point(t_point *ps, t_player *player, t_point *pp, int start_x)
{
	if (ps->x < player->piece_width)
	{
		ps->x++;
		if (player->second_priority == RIGHT)
			pp->x--;
		else
			pp->x++;
	}
	else
	{
		ps->x = 0;
		ps->y++;
		pp->x = start_x;
		if (player->priority == DOWN)
			pp->y -= 1;
		else
			pp->y += 1;
	}
}

char			place_piece_right_up(t_player *player, t_point *pp, int debug_fd)
{
	t_point	ps;
	int		overlap;
	int		start_x;

	start_x = pp->x;
	ps.x = 0;
	ps.y = 0;
	overlap = 0;
	while (ps.y < player->piece_height && overlap != 1)
	{
		if ((overlap = return_overlap(player, pp, debug_fd)) != 1)
		{
			overlap = 0;
			fix_temp_point(&ps, player, pp, start_x);
		}
	}
	if (overlap == 1)
		return (((pp->y + player->piece_true_height) <= player->p_height) &&
				(pp->x + player->piece_width) <= player->p_width);
	return (FALSE);
}