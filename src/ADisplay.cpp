/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADisplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nallani@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 23:11:32 by nathan            #+#    #+#             */
/*   Updated: 2019/10/04 04:51:10 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ADisplay.hpp"
#include "ft_retro.hpp"

ADisplay::ADisplay( int y, int x, WINDOW* win, Manager & manager ) : _y(y), _x(x), _win(win), _manager(manager){
	this->_destroyed = false;
}

ADisplay::ADisplay( ADisplay const & copy ) : _y(copy._y), _x(copy._x), _win(copy._win), _manager(copy._manager) {
	this->_destroyed = false;
}

ADisplay::~ADisplay( void ) {}

ADisplay & ADisplay::operator=( ADisplay const & copy){
	this->_y = copy._y;
	this->_x = copy._x;
	this->_win = copy._win;
	this->_destroyed = copy._destroyed;

	return ( *this );
}

void		ADisplay::display( int new_y, int new_x ) {
	if (new_y > HEIGHT || new_y < 0 || new_x > WIDTH || new_x < 0) {
		this->beDestroyed();
		return ;
	}

	this->erase();
	this->_y = new_y;
	this->_x = new_x;
	//wmove(this->_win, this->_y, this->_x); to remove
	this->draw();
}

void		ADisplay::beDestroyed( void ){
	if (this->_destroyed)
		return ;
	this->_destroyed = true;
	this->erase();
	this->_manager.destroy(this);
}

void		ADisplay::erase( void ) const {
	wmove(this->_win, this->_y, this->_x);
	wprintw(this->_win, " ");	
}
