/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cursor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:38:09 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/02 14:20:37 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.hpp"
Cursor::Cursor(WINDOW *window) : win(window), x(0), y(0){
	printf("Constructor cursor\n");
}

Cursor::~Cursor(){
	printf("Destructor cursor\n");
}

void Cursor::gotoXY(){
	wmove(this->win, this->x, this->y);
}

void Cursor::setXY(int x, int y){
	if (~x)
		this->x = x;
	if (~y)
		this->y = y;
}
