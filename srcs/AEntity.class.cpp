/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:43:55 by svachere          #+#    #+#             */
/*   Updated: 2015/01/11 21:19:47 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.class.hpp"

int	AEntity::count = 0;
int	AEntity::score = 0;

AEntity::AEntity( void ) : _tile( "?" )
{
	AEntity::count += 1;
	return ;
}

AEntity::AEntity( std::string tile ) : _tile( tile )
{
	AEntity::count += 1;
	int			i		= 0;
	int			sx		= 1;
	int			sy		= 0;
	char const	*cTile	= tile.c_str();

	while ( ++i && cTile[ i - 1 ] )
	{
		if ( cTile[ i - 1 ] == '\n' && cTile[ i ] == '\0' )
			break ;

		if ( cTile[ i - 1 ] == '\n' )
		{
			++sy;
			sx = ( i > sx ) ? i : sx;
		}
	}

	this->_sx = ( i > sx ) ? i : sx;
	this->_sy = sy;

	return ;
}

AEntity::AEntity( AEntity const & src )
{
	*this = src;

	return ;
}


AEntity::~AEntity( void )
{
	AEntity::count -= 1;
	return ;
}

AEntity &	AEntity::operator=( AEntity  const & rhs )
{
	_tile = rhs.getTile();
	_x = rhs.getX();
	_y = rhs.getY();
	_vx = rhs.getVX();
	_vy = rhs.getVY();
	_hp = rhs.getHP();

	return (*this);
}

std::string 	AEntity::getTile( void ) const {return _tile;}
int				AEntity::getX( void ) const {return ( int ) _x;}
int				AEntity::getY( void ) const {return ( int ) _y;}
int				AEntity::getVX( void ) const {return _vx;}
int				AEntity::getVY( void ) const {return _vy;}
int				AEntity::getHP( void ) const {return _hp;}
int				AEntity::getSX( void ) const {return _sx;}
int				AEntity::getSY( void ) const {return _sy;}
bool			AEntity::getHostile( void ) const {return _hostile;}
void			AEntity::setHostile( bool hostile ) {_hostile = hostile ;}

void	AEntity::move( int x, int y )
{
	_x = x;
	_y = y;

	return ;
}
void	AEntity::moveRel( int x, int y )
{
	_x += x;
	_y += y;

	return ;
}
void	AEntity::takeDamage( int damage )
{
	_hp -= damage;

	if (_hp <= 0)
		this->die();

	return ;
}
bool	AEntity::checkCollision( AEntity & entity )
{
	return ( this->getX() == entity.getX() && this->getY() == entity.getY() );
}

void	AEntity::tileOrigine( int & x, int & y )
{
	if ( this->_sx > 1 )
		x -= this->_sx / 2;

	if ( this->_sy > 1 )
		y -= this->_sy / 2;

	return ;
}

void	AEntity::die( void )
{
	_hp = 0;
}

bool	AEntity::checkFire( int & x, int & y )
{
	x = 0;
	y = 0;
	return false;
}
