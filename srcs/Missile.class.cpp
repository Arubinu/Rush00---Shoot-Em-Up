/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:40:58 by apergens          #+#    #+#             */
/*   Updated: 2015/01/11 18:47:36 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Missile.class.hpp"

/*
 * Constructors
 */

int		Missile::count			= 0;
int		Missile::countHostile	= 0;
int		Missile::countNHostile	= 0;

Missile::Missile( void ) : AEntity( "-" )
{
	return ;
}

Missile::Missile( int x, int y, bool hostile ) : AEntity( "-" )
{
	this->_x = x;
	this->_y = y;
	this->_hostile = hostile;
	this->_vx = _hostile == true ? -0.7 : 0.7;
	this->_vy = 0;
	this->_hp = 1;

	Missile::count += 1;
	Missile::countHostile += this->_hostile ? 1 : 0;
	Missile::countNHostile += this->_hostile ? 0 : 1;

	return ;
}

Missile::Missile( Missile const & src ) : AEntity( src )
{
	( void ) src;

	return ;
}

/*
 * Destructor
 */

Missile::~Missile( void )
{
	Missile::count -= 1;
	Missile::countHostile -= this->_hostile ? 1 : 0;
	Missile::countNHostile -= this->_hostile ? 0 : 1;

	return ;
}

/*
 * Other Members
 */

void		Missile::updatePosition( void )
{
	this->_x += this->_vx;
	this->_y += this->_vy;

	return ;
}

/*
 * Operators
 */

Missile &	Missile::operator=( Missile const rhs )
{
	( void ) rhs;

	return ( *this );
}
