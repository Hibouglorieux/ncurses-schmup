/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Manager.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nallani@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 23:52:07 by nathan            #+#    #+#             */
/*   Updated: 2019/10/03 00:40:51 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Manager.hpp"

Manager::Manager( void ) {
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
}

void		Manager::add( ADisplay* display ) {
	this->_displayable[this->_nb_displayable] = display;
	this->_nb_displayable++;
}
