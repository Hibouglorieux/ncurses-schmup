/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nallani@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 03:07:27 by nathan            #+#    #+#             */
/*   Updated: 2019/10/04 04:11:36 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {
	this->_lvl = 1;
}

Weapon::Weapon( Weapon const & copy ){
	this->_lvl = copy._lvl;
}

Weapon & 		Weapon::operator=(Weapon const & copy){
	this->_lvl = copy._lvl;
	return ( *this );
}

Weapon::~Weapon( void ) { }

void		Weapon::shoot( Manager & manager, WINDOW* win, int y, int x ){
	switch (this->_lvl){
		case 1:
			manager.add(new Projectile(y, x, win, manager, -1, 0));
			break;
		case 2:
			manager.add(new Projectile(y, x, win, manager, -1, 1));
			manager.add(new Projectile(y, x, win, manager, -1, -1));
			manager.add(new Projectile(y, x, win, manager, -1, 0));
			break;
		case 3:
			manager.add(new Projectile(y, x + 1, win, manager, -1, 0));
			manager.add(new Projectile(y, x - 1, win, manager, -1, 0));
			break;
		default:
			break;
	}
}
