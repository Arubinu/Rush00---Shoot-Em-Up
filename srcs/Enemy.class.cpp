/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 13:35:23 by svachere          #+#    #+#             */
/*   Updated: 2015/01/11 21:20:32 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

int		Enemy::count	= 0;

Enemy::Enemy( void )
{
	return ;
}

Enemy::Enemy( Enemy const & src ) : AEntity( src )
{
	return ;
}

Enemy::~Enemy( void )
{
	Enemy::count -= 1;
	if ( this->getX() > 0 )
		AEntity::score += 42;

	return ;
}

Enemy::Enemy( int x, int y ) : AEntity( "0" )
{
	this->_x = ( float ) x;
	this->_y = ( float ) y;
	this->_hp = 1;
	this->_vx = -0.4;
	this->_vy = 0;
	this->_hostile = true;
	this->_clock = 0;

	Enemy::count += 1;

	return ;
}

void	Enemy::updatePosition( void )
{
	_x += _vx;
	_y += _vy;
	_clock += 1;
	return ;
}

bool	Enemy::checkFire( int & x, int & y )
{
	if ( (_clock % ENEMY_FIRE_CLOCK) == 0 )
	{
		x = (int) _x;
		y = (int) _y;
		return true;
	}
	return false;
}
