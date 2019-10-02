/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEnnemy.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan </var/mail/nathan>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:49:07 by nathan            #+#    #+#             */
/*   Updated: 2019/09/30 18:49:11 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IENNEMY_CLASS_H
# define IENNEMY_CLASS_H

class IEnnemy {
public:
	IEnnemy( void );
	IEnnemy( IEnnemy const & );
	~IEnnemy(void);
	IEnnemy &	operator=( IEnnemy const & );
private:
};

#endif
