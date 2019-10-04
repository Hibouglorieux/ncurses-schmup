/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nallani@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 02:56:40 by nathan            #+#    #+#             */
/*   Updated: 2019/10/04 04:51:06 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(int y, int x, WINDOW* win, Manager & manager, int y_dir, int x_dir, int dmg) : ADisplay(y, x, win, manager){ 
	this->_y_dir = y_dir;
	this->_x_dir = x_dir;
	this->_dmg = dmg;
}

Projectile::Projectile( Projectile const & copy ) : ADisplay(copy) {
	this->_y_dir = copy._y_dir;
	this->_x_dir = copy._y_dir;
	this->_dmg = copy._dmg;
}

Projectile::~Projectile( void ) { }

/*Projectile &		Projectile::operator=( Projectile const & copy ){
	this->_y = copy._y;
	this->_x = copy._x;
	this->_win = copy._win;
	this->_y_dir = copy._y_dir;
	this->_x_dir = copy._y_dir;
	this->_dmg = copy._dmg;

	return ( *this );
}*/

void			Projectile::update( void ){
	wmove(this->_win, 0, 0);
	this->display( this->_y + this->_y_dir, this->_x + this->_x_dir);
}

void			Projectile::draw( void ) const{
	wmove(this->_win, this->_y, this->_x);
	wattron(this->_win, COLOR_PAIR(3));
	wprintw(this->_win, "x");
	wattroff(this->_win, COLOR_PAIR(3));
}
