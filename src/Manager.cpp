/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Manager.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 23:52:07 by nathan            #+#    #+#             */
/*   Updated: 2019/10/04 04:51:36 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Manager.hpp"

Manager::Manager( Player* p ) : player(p){
	for ( int i = 0; i < MAX_NB_DISPLAYABLE; i++){
		this->_clears[i] = NULL;
		this->_displayable[i] = NULL;
	}
	this->_nb_displayable = 0;
	this->_nb_clears = 0;
}

Manager::~Manager( void ) {
	for (int i = 0; i < this->_nb_displayable; i++) {
		if ( this->_displayable[i] != NULL )
			delete this->_displayable[i];
	}
	//delete this->player;
}

void		Manager::clear( void ) {
	for ( int j = 0; j < this->_nb_clears; j++){
		for ( int i = 0; i < this->_nb_displayable; i++ ){
			if ( this->_displayable[i] == this->_clears[j] ){
				delete this->_displayable[i];
				this->_nb_displayable--;
				this->_displayable[i] = this->_displayable[this->_nb_displayable];
				this->_displayable[this->_nb_displayable] = NULL;
				break;
			}
		}
		this->_clears[j] = NULL;
	}
	this->_nb_clears = 0;
}

void		Manager::destroy( ADisplay* display ) {
	this->_clears[this->_nb_clears] = display;
	this->_nb_clears++;
}

void		Manager::update( void ){
	for ( int i = 0; i < this->_nb_displayable; i++ ){
		this->_displayable[i]->update();
	}
	this->player->update();
}

void		Manager::add( ADisplay* display ) {
	this->_displayable[this->_nb_displayable] = display;
	this->_nb_displayable++;
}
