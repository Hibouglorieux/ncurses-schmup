/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADisplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nallani@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 23:11:27 by nathan            #+#    #+#             */
/*   Updated: 2019/10/03 00:28:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ADISPLAY_CLASS_H
# define ADISPLAY_CLASS_H

class Manager;
#include <ncurses.h>

class ADisplay {
public:
	ADisplay(int y, int x, WINDOW* win, Manager & );
	ADisplay( ADisplay const & );
	virtual ~ADisplay(void);
	ADisplay &	operator=( ADisplay const & );
	virtual void	update( void ) = 0; // fait de la classe une classe abstraite, les enfants doivent definir update
	void	display( int y, int x );
	void	beDestroyed( void );
protected:
	int _y;
	int _x;
	WINDOW* _win;
	Manager & _manager;

	virtual void	erase( void ) const;
	virtual void	draw( void ) const = 0;
};

#endif
