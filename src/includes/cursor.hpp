/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:37:35 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/02 14:47:53 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_HPP
# define CURSOR_HPP
# include <ncurses.h>
# include <sstream>
# include <unistd.h>
# include <fcntl.h>
class Cursor {
	public:
		Cursor(WINDOW *window);
		~Cursor(void);
		//Cursor &	operator=( Cursor const & );
		void setXY(int x, int y);
		void gotoXY();
	private:
		WINDOW *win;
		int x, y;
};

#endif
