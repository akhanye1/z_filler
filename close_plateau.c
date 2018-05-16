#include "filler.h"

static void  find_right(t_player *player, int dir, t_point *point, int debug_fd)
{
    int     y;
    int     x;
    char    piece_found;

    y = point->y;
    x = player->p_width;
    if (player->plateau_piece[y][x] == player->piece_small ||
        player->plateau_piece[y][x] == player->piece_small)
    {
        point->x = -1;
        return ;
    }
    piece_found = FALSE;
    while (x > 0 && ((y < (player->p_height - 1) && dir == UP) ||
        (y > 0 && dir == DOWN)) && !piece_found)
    {
        ft_putnbr_fd(x, debug_fd);
        ft_putchar_fd(' ', debug_fd);
        x--;
        if (x == 0)
        {
            y = (dir == UP) ? y + 1 : y - 1;
            x = 0;
            ft_putchar_fd('\n', debug_fd);
        }
        piece_found = (player->plateau_piece[y][x] == player->piece_small ||
            player->plateau_piece[y][x] == player->piece_large);
    }
    if (piece_found)
    {
        point->y = y;
        point->x = x;
    }
    else
        point->x = -1;
}

static void  find_left(t_player *player, int dir, t_point *point, int debug_fd)
{
    int     y;
    int     x;
    char    piece_found;

    y = point->y;
    x = 0;
    if (player->plateau_piece[y][x] == player->piece_small ||
        player->plateau_piece[y][x] == player->piece_small)
    {
        point->x = -1;
        return ;
    }
    piece_found = FALSE;
    while (x < player->p_width && ((y < (player->p_height - 1) && dir == UP) ||
        (y > 0 && dir == DOWN)) && !piece_found)
    {
        ft_putnbr_fd(x, debug_fd);
        ft_putchar_fd(' ', debug_fd);
        x++;
        if (x == player->p_width)
        {
            y = (dir == UP) ? y + 1 : y - 1;
            x = 0;
            ft_putchar_fd('\n', debug_fd);
        }
        piece_found = (player->plateau_piece[y][x] == player->piece_small ||
            player->plateau_piece[y][x] == player->piece_large);
    }
    ft_putstr_fd("<<", debug_fd);
    if (piece_found)
    {
        point->y = y;
        point->x = x;
    }
    else
        point->x = -1;
}

static char find_piece(t_player *player, t_point *point, int up_down, int left_right, int debug_fd)
{
    ft_putstr_fd("fill : ", debug_fd);
    ft_putendl_fd((left_right == LEFT) ? "LEFT" : "RIGHT", debug_fd);
    if (left_right == LEFT)
        find_left(player, up_down, point, debug_fd);
    else
        find_right(player, up_down, point, debug_fd);
    ft_putstr_fd("X Position : ", debug_fd);
    ft_putnbr_fd(point->x, debug_fd);
    ft_putchar_fd('\n', debug_fd);
    return (point->x != -1);
}

static void find_spot(t_player *player, t_point *point, int up_down, int debug_fd)
{
    int tries;
    int y;
    int check_side;

    tries = 0;
    y = (up_down == UP) ? 0 : player->p_height - 2;
    check_side = player->second_priority;
    while ((tries < 2) && ((y < (player->p_height - 1) && up_down == UP) ||
        (y > 0 && up_down == DOWN)))
    {
        point->y = y;
        ft_putstr_fd("Y : ", debug_fd);
        ft_putnbr_fd(y, debug_fd);
        ft_putchar_fd('\n', debug_fd);
        if (find_piece(player, point, up_down, check_side, debug_fd))
        {
            y = point->y;
            ft_putstr_fd("Attempting to place piece. Y - X : ", debug_fd);
            ft_putnbr_fd(point->y, debug_fd);
            ft_putchar_fd(' ', debug_fd);
            ft_putnbr_fd(point->x, debug_fd);
            ft_putchar_fd('\n', debug_fd);
            if (close_place_piece(player, point, debug_fd))
            {
                print_piece(point->y - 1, point->x);
                return ;
            }
            else
                y = (up_down == UP) ? y + 1 : y - 1;
        }
        else
            ft_putendl_fd("Piece not found", debug_fd);
        if ((y == player->p_height && up_down == UP) ||
            (y == 0 && up_down == DOWN))
        {
            ft_putendl_fd("\n\nCHANGE SIDE\n\n", debug_fd);
            y = (up_down == UP) ? 0 : player->p_height - 2;
            check_side = (check_side == LEFT) ? RIGHT : LEFT;
            player->second_priority = check_side;
            tries++;
        }
    }
    print_piece(0, 0);
}

void    close_plateau(t_player *player, t_point *point, int debug_fd)
{
    ft_putendl_fd("\n**** CLOSING PLATEAU ****", debug_fd);
    if (player->priority == UP)
        find_spot(player, point, UP, debug_fd);
    else if (player->priority == DOWN)
        find_spot(player, point, DOWN, debug_fd);
}