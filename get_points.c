/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:09:39 by zphakath          #+#    #+#             */
/*   Updated: 2018/04/22 13:09:41 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void get_all_enemy_pieces(int debug_fd, t_player *player)
{
    int		y;
    int		x;
    char	piece_found;
    
    //Check right
    // ft_putendl_fd("Right", debug_fd);
    x = player->enemy.right.x;
    y = 0;
    piece_found = TRUE;
    while (++x < player->p_width && piece_found)
    {
        while (++y < player->p_height)
        {
            piece_found = (player->plateau_piece[y][x] != '.' &&
                          player->plateau_piece[y][x] != player->piece_small &&
                          player->plateau_piece[y][x] != player->piece_large);
            if (piece_found)
            {
                player->enemy.right.x = x;
                player->enemy.right.y = y;
                break;
            }
        }
        if (piece_found)
            x = player->enemy.right.x;
        y = 0;
    }
    
    //Check Left
    // ft_putendl_fd("Left", debug_fd);
    x = player->enemy.left.x;
    y = 0;
    piece_found = TRUE;
    while (--x > 0 && piece_found)
    {
        while (++y < player->p_height)
        {
            piece_found = (player->plateau_piece[y][x] != '.' &&
                          player->plateau_piece[y][x] != player->piece_small &&
                          player->plateau_piece[y][x] != player->piece_large);
            if (piece_found)
            {
                player->enemy.left.x = x;
                player->enemy.left.y = y;
                break;
            }
        }
        if (piece_found)
            x = player->enemy.left.x;
        y = 0;
    }
    
    //Check Top
    // ft_putendl_fd("Top", debug_fd);
    y = player->enemy.top.y;
    x = -1;
    piece_found = TRUE;
    while (--y > 0 && piece_found)
    {
        while (++x < player->p_width)
        {
            piece_found = (player->plateau_piece[y][x] != '.' &&
                          player->plateau_piece[y][x] != player->piece_small &&
                          player->plateau_piece[y][x] != player->piece_large);
            if (piece_found)
            {
                player->enemy.top.x = x;
                player->enemy.top.y = y;
                break ;
            }
        }
        if (piece_found)
            y = player->enemy.top.y;
        x = -1;
    }
    
    //Check bottom
    // ft_putendl_fd("Bottom", debug_fd);
    y = player->enemy.bottom.y;
    x = -1;
    piece_found = TRUE;
    while (++y < player->p_height && piece_found)
    {
        while (++x < player->p_width)
        {
            piece_found = (player->plateau_piece[y][x] != '.' &&
                          player->plateau_piece[y][x] != player->piece_small &&
                          player->plateau_piece[y][x] != player->piece_large);
            if (piece_found)
            {
                player->enemy.bottom.x = x;
                player->enemy.bottom.y = y;
                break ;
            }
        }
        if (piece_found)
            y = player->enemy.bottom.y;
        x = -1;
    }

    // ft_putendl_fd("SUMMARY (ENEMY)", debug_fd);
    // ft_putstr_fd("Top : ", debug_fd);
    // ft_putnbr_fd(player->enemy.top.y, debug_fd);
    // ft_putchar_fd(' ', debug_fd);
    // ft_putnbr_fd(player->enemy.top.x, debug_fd);
    // ft_putchar_fd('\n', debug_fd);
    // ft_putstr_fd("Right : ", debug_fd);
    // ft_putnbr_fd(player->enemy.right.y, debug_fd);
    // ft_putchar_fd(' ', debug_fd);
    // ft_putnbr_fd(player->enemy.right.x, debug_fd);
    // ft_putchar_fd('\n', debug_fd);
    // ft_putstr_fd("LEFT : ", debug_fd);
    // ft_putnbr_fd(player->enemy.left.y, debug_fd);
    // ft_putchar_fd(' ', debug_fd);
    // ft_putnbr_fd(player->enemy.left.x, debug_fd);
    // ft_putchar_fd('\n', debug_fd);
    // ft_putstr_fd("Bottom : ", debug_fd);
    // ft_putnbr_fd(player->enemy.bottom.y, debug_fd);
    // ft_putchar_fd(' ', debug_fd);
    // ft_putnbr_fd(player->enemy.bottom.x, debug_fd);
    // ft_putchar_fd('\n', debug_fd);
}

void get_player_pieces(int debug_fd, t_player *player)
{
    int		y;
    int		x;
    char	piece_found;
    
    //Check right
    // ft_putendl_fd("Right", debug_fd);
    x = player->decision.right.x;
    y = 0;
    piece_found = TRUE;
    while (++x < player->p_width && piece_found)
    {
        while (++y < player->p_height)
        {
            piece_found = player->plateau_piece[y][x] == player->piece_small ||
            player->plateau_piece[y][x] == player->piece_large;
            if (piece_found)
            {
                player->decision.right.x = x;
                player->decision.right.y = y;
                break;
            }
        }
        if (piece_found)
            x = player->decision.right.x;
        y = 0;
    }
    
    //Check Left
    // ft_putendl_fd("Left", debug_fd);
    x = player->decision.left.x;
    y = 0;
    piece_found = TRUE;
    while (--x > 0 && piece_found)
    {
        while (++y < player->p_height)
        {
            piece_found = player->plateau_piece[y][x] == player->piece_small ||
            player->plateau_piece[y][x] == player->piece_large;
            if (piece_found)
            {
                player->decision.left.x = x;
                player->decision.left.y = y;
                break;
            }
        }
        if (piece_found)
            x = player->decision.left.x;
        y = 0;
    }
    
    //Check Top
    // ft_putendl_fd("Top", debug_fd);
    y = player->decision.top.y;
    x = -1;
    piece_found = TRUE;
    while (--y > 0 && piece_found)
    {
        while (++x < player->p_width)
        {
            piece_found = player->plateau_piece[y][x] == player->piece_small ||
            player->plateau_piece[y][x] == player->piece_large;
            if (piece_found)
            {
                player->decision.top.x = x;
                player->decision.top.y = y;
                break ;
            }
        }
        if (piece_found)
            y = player->decision.top.y;
        x = -1;
    }
    
    //Check bottom
    // ft_putendl_fd("Bottom", debug_fd);
    y = player->decision.bottom.y;
    x = -1;
    piece_found = TRUE;
    while (++y < player->p_height && piece_found)
    {
        while (++x < player->p_width)
        {
            piece_found = player->plateau_piece[y][x] == player->piece_small ||
            player->plateau_piece[y][x] == player->piece_large;
            if (piece_found)
            {
                player->decision.bottom.x = x;
                player->decision.bottom.y = y;
                break ;
            }
        }
        if (piece_found)
            y = player->decision.bottom.y;
        x = -1;
    }
    // ft_putendl_fd("SUMMARY (PLAYER)", debug_fd);
    // ft_putstr_fd("Top : ", debug_fd);
    // ft_putnbr_fd(player->decision.top.y, debug_fd);
    // ft_putchar_fd(' ', debug_fd);
    // ft_putnbr_fd(player->decision.top.x, debug_fd);
    // ft_putchar_fd('\n', debug_fd);
    // ft_putstr_fd("Right : ", debug_fd);
    // ft_putnbr_fd(player->decision.right.y, debug_fd);
    // ft_putchar_fd(' ', debug_fd);
    // ft_putnbr_fd(player->decision.right.x, debug_fd);
    // ft_putchar_fd('\n', debug_fd);
    // ft_putstr_fd("LEFT : ", debug_fd);
    // ft_putnbr_fd(player->decision.left.y, debug_fd);
    // ft_putchar_fd(' ', debug_fd);
    // ft_putnbr_fd(player->decision.left.x, debug_fd);
    // ft_putchar_fd('\n', debug_fd);
    // ft_putstr_fd("Bottom : ", debug_fd);
    // ft_putnbr_fd(player->decision.bottom.y, debug_fd);
    // ft_putchar_fd(' ', debug_fd);
    // ft_putnbr_fd(player->decision.bottom.x, debug_fd);
    // ft_putchar_fd('\n', debug_fd);
}
