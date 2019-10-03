/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Manager.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 23:52:13 by nathan            #+#    #+#             */
/*   Updated: 2019/10/03 19:15:37 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MANAGER_CLASS_H
# define MANAGER_CLASS_H

#include "Player.hpp"
#include "ft_retro.hpp"
# define MAX_NB_DISPLAYABLE 100


class Manager {
	public:
		Manager( class Player*);
		//Manager( Manager const & ); only one
		~Manager(void);
		//Manager &	operator=( Manager const & ); only one
		void		destroy( ADisplay* );
		void		add( ADisplay* ); // a revoir
		void		update( void );
		void		clear( void ); // call on end of each frame to clean
		class Player	*player;
	private:
		int			_nb_displayable;
		ADisplay* _displayable[MAX_NB_DISPLAYABLE];
		int			_nb_clears;
		ADisplay*	_clears[MAX_NB_DISPLAYABLE];
};

#endif
