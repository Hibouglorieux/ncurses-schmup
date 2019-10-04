/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nallani@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 03:07:32 by nathan            #+#    #+#             */
/*   Updated: 2019/10/04 04:42:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H
#include "Projectile.hpp"
#include "Manager.hpp"

class Weapon {
public:
	Weapon( void );
	//Weapon( int y, int x, WINDOW* win, Manager & manager );
	Weapon( Weapon const & );
	~Weapon(void);
	Weapon &	operator=( Weapon const & );
	void		shoot(Manager & manager, WINDOW* win, int y, int x);
private:
	short	_lvl;
};

#endif
