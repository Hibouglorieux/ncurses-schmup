/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Powerup.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nallani@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 04:58:38 by nathan            #+#    #+#             */
/*   Updated: 2019/10/04 04:59:03 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POWERUP_CLASS_H
# define POWERUP_CLASS_H

class Powerup : public ADisplay{
public:
	Powerup( void );
	Powerup( Powerup const & );
	~Powerup(void);
	Powerup &	operator=( Powerup const & );
private:
};

#endif
