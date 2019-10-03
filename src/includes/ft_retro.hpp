/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 23:13:17 by nathan            #+#    #+#             */
/*   Updated: 2019/10/03 19:19:28 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_H
# define FT_RETRO_H

//class ADisplay;
//class Manager;
//class Ennemy1;

#include <ncurses.h>
#include "keys.hpp"
#include "cursor.hpp"
#include "ADisplay.hpp"
#include "Manager.hpp"
#include "Ennemy1.hpp"
#include "Player.hpp"

#define WIDTH 60
#define HEIGHT 30
#define MIDW (COLS - WIDTH) / 2
#define MIDH (LINES - HEIGHT) / 2
#define ENEMIES_COLOR 1
#define PLAYER_COLOR 2
int		debug(void);
#endif
