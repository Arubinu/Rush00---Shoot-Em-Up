/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:56:58 by svachere          #+#    #+#             */
/*   Updated: 2015/01/11 19:32:10 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

int		Player::count	= 0;

Player::Player( void ) : AEntity( ">" )
{
	_x = 5;
	_y = 5;
	_hp = 1;
	_life = 3;
	_hostile = false;
	Player::count += 1;
}

Player::Player( std::string & tile ) : AEntity( tile )
{
	_x = 5;
	_y = 5;
	_hp = 1;
	_life = 3;
	_hostile = false;
	Player::count += 1;
}

Player::Player( Player const & src ) : AEntity( src )
{
	*this = src;
}

Player::~Player( void ) 
{
	Player::count -= 1;
}

Player &	Player::operator=( Player const & rhs )
{
	AEntity::operator=( rhs );
	_life = rhs.getLife();
	return *this;
}

int		Player::getLife( void ) const {return _life;}

void	Player::updatePosition( void ) {}

void	Player::die( void )
{
	_life -= 1;
	if ( _life > 0 )
	{
		_x = 5;
		_y = 5;
		_hp = 1;
	}
}

void	Player::checkOffScreen( int winw, int winh )
{
	if ( _x < 0 )
		_x = 0;
	else if ( _x >= winw )
		_x = winw - 1;
	if ( _y < 0 )
		_y = 0;
	else if ( _y >= winh )
	   _y = winh - 1;	
}
