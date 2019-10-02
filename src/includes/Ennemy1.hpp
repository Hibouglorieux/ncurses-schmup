/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemy1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nallani@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 23:38:45 by nathan            #+#    #+#             */
/*   Updated: 2019/10/03 00:48:26 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENNEMY1_CLASS_H
# define ENNEMY1_CLASS_H

#include "ADisplay.hpp"
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
