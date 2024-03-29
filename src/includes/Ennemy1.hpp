/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemy1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 23:38:45 by nathan            #+#    #+#             */
/*   Updated: 2019/10/03 18:38:05 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENNEMY1_CLASS_H
# define ENNEMY1_CLASS_H

#include "ADisplay.hpp"
#include "ft_retro.hpp"
class Manager;

class Ennemy1 : public ADisplay{
	public:
		Ennemy1(int y, int x, WINDOW* win, Manager & );
		Ennemy1( Ennemy1 const & );
		~Ennemy1(void);
		Ennemy1 &	operator=( Ennemy1 const & );
		void	update( void );
	private:
		void	draw( void ) const;
};

#endif
