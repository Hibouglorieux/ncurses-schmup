/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemy1.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 23:38:40 by nathan            #+#    #+#             */
/*   Updated: 2019/10/04 03:54:27 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ennemy1.hpp"

Ennemy1::Ennemy1(int y, int x, WINDOW* win, Manager & manager) : ADisplay(y, x, win, manager){ }

Ennemy1::Ennemy1( Ennemy1 const & copy ) : ADisplay(copy) { }

Ennemy1::~Ennemy1( void ) {}

Ennemy1 &		Ennemy1::operator=( Ennemy1 const & copy ){
	this->_y = copy._y;
	this->_x = copy._x;
	this->_win = copy._win;

	return ( *this );
}

void			Ennemy1::update( void ){
	wmove(this->_win, 0, 0);
	//if (this->_y < HEIGHT - 5)
		this->display( this->_y + 1, this->_x );
	// add a counter and make it attack for example
}

void			Ennemy1::draw( void ) const{
	wmove(this->_win, this->_y, this->_x);
	wattron(this->_win, COLOR_PAIR(ENEMIES_COLOR));
	wprintw(this->_win, "V");
	wattroff(this->_win, COLOR_PAIR(ENEMIES_COLOR));
}
