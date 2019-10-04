/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:37:33 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/04 04:22:34 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENNEMY1_CLASS_H
# define ENNEMY1_CLASS_H

#include "ADisplay.hpp"
#include <ncurses.h>
#include "Manager.hpp"

class Manager;

class Projectile : public ADisplay{
	public:
		Projectile(int y, int x, WINDOW* win, Manager &, int y_dir, int x_dir, int dmg=1 );
		Projectile( Projectile const & );
		~Projectile(void);
		//Projectile &	operator=( Ennemy1 const & );
		void	update( void );
	private:
		char 	_y_dir;
		char	_x_dir;
		unsigned char	_colo;
		unsigned char	_dmg;
		void	draw( void ) const;
};

#endif
