/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:37:33 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/03 18:38:36 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENNEMY1_CLASS_H
# define ENNEMY1_CLASS_H

#include "ADisplay.hpp"
#include "ft_retro.hpp"
class Manager;

class Projectile : public ADisplay{
	public:
		Projectile(int y, int x, WINDOW* win, Manager & );
		Projectile( Projectile const & );
		~Projectile(void);
		//Ennemy1 &	operator=( Ennemy1 const & );
		void	update( void );
	private:
		void	draw( void ) const;
};

#endif
