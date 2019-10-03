/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:43:39 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/03 19:13:04 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "ft_retro.hpp"

class Player : public ADisplay {
	public:
		Player( int y, int x, WINDOW *win, Manager &);
		~Player(void);
		void		update( void );
		void		shoot(void);
		void		moveRight(void);
		void		moveLeft(void);
		void		moveUp(void);
		void		moveDown(void);
	private:
		void		draw(void) const;
		int			_x;
		int			_y;
		int			_ammo;
		int			_lives;
};

#endif
