#include "filler.h"

int		get_right_piece(t_player *player, int y, int x, int debug_fd)
{
	while ((player->plateau_piece[y][x] == player->piece_small ||
		player->plateau_piece[y][x] == player->piece_large) &&
		x < player->p_width)
	{
		x++;
	}
	return (x - 1);
}

int		get_left_piece(t_player *player, int y, int x, int debug_fd)
{
	while ((player->plateau_piece[y][x] == player->piece_small ||
		player->plateau_piece[y][x] == player->piece_large) &&
		x > 0)
	{
		x--;
	}
	return (x + 1);
}

void	get_precise_up(t_player *player, t_point *point, int debug_fd)
{
	if (player->second_priority == RIGHT)
	{
		player->decision.top.x = get_right_piece(player,
			player->decision.top.y, player->decision.top.x,
			debug_fd);
		point->x = player->decision.top.x;
	}
	else
	{
		player->decision.top.x = get_left_piece(player,
			player->decision.top.y, player->decision.top.x,
			debug_fd);
		point->x = player->decision.top.x;
	}
}

void	get_more_advantage(t_player *player, t_point *point)
{
	if (player->decision.right.x < player->enemy.left.x)
		player->second_priority = RIGHT;
	else
		player->second_priority = LEFT;
	if (player->priority == UP)
		point->y = player->decision.top.y;
	else if (player->priority == DOWN)
		point->y = player->decision.bottom.y;
	if (player->second_priority == RIGHT)
		point->x = player->decision.right.x;
	else if (player->second_priority == LEFT)
		point->x = player->decision.left.x;
	if ((player->decision.bottom.y >= (player->p_height - 1)) &&
		(player->decision.top.y <= 1))
		player->closed = TRUE;
}

void	get_advantage(int debug_fd, t_player *player, t_point *point)
{
	if (player->closed)
		return ;
	if (player->decision.bottom.y < player->enemy.top.y)
	{
		if (player->decision.bottom.y >= (player->p_height - 1))
			player->priority = UP;
		else
			player->priority = DOWN;
		ft_putendl_fd((player->priority == UP) ? "UP" : "DOWN", debug_fd);
	}
	else
	{
		if (player->decision.top.y <= 1)
			player->priority = DOWN;
		else
			player->priority = UP;
	}
	get_more_advantage(player, point);
}