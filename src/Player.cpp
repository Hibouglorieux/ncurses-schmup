/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:43:09 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/03 19:32:12 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"


Player::Player(int y, int x, WINDOW* win, Manager & manager) : ADisplay(y, x, win, manager){
	this->_ammo = 100;
	this->_lives = 3;
	this->_y = y;
	this->_x = x;
}

Player::~Player( void ) {}

void			Player::update( void ){
	//wmove(this->_win, 0, 0);
	//if (this->_y < HEIGHT - 5)
	this->display(this->_y, this->_x);
	// add a counter and make it attack for example
}

void			Player::shoot( void ){
	//wmove(this->_win, 0, 0);
	this->display(this->_y, this->_x );
}

void			Player::draw( void ) const{
	wmove(this->_win, this->_y, this->_x);
	wattron(this->_win, COLOR_PAIR(PLAYER_COLOR));
	wprintw(this->_win, " _/\\_");
	wmove(this->_win, this->_y + 1, this->_x);
	wprintw(this->_win, "_/==\\_");
	wattroff(this->_win, COLOR_PAIR(PLAYER_COLOR));
	dprintf(debug(), "pos: {%d, %d}\n", this->_y, this->_x);
}

void			Player::moveRight( void ){
	dprintf(debug(), "move right\n");

	this->_x++;
}

void			Player::moveLeft( void ){
	this->_x--;
}

void			Player::moveUp( void ){
	this->_y--;
}

void			Player::moveDown( void ){
	this->_y++;
}

/*
** _ /\_
** _/==\_
*/
