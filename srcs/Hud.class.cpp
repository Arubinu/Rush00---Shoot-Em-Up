// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Hud.class.cpp for rush00                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2013/09/25 08:56:14 by apergens          #+#    #+#             //
/*   Updated: 2015/01/11 11:30:24 by svachere         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Hud.class.hpp"

/*
 * Constructors
 */

Hud::Hud( void )
{
	return ;
}

Hud::Hud( int height )
{
	this->setH( height );
	this->_pause = 0;
	this->_time = time( NULL );

	this->life = 42;
	this->score = 0;
	this->enemyNumber = 666;
	this->enemyDestroy = -1;

	return ;
}

Hud::Hud( Hud const & src )
{
	*this = src;

	return ;
}

/*
 * Destructor
 */

Hud::~Hud( void )
{
	return ;
}

/*
 * Getter Members
 */

int			Hud::getH( void ) const
{
	return ( this->_height );
}

/*
 * Setter Members
 */

void		Hud::setH( int height )
{
	this->_height = height;

	return;
}

/*
 * Other Members
 */

void		Hud::pause( void )
{
	this->_pause = time( NULL );

	return ;
}

void		Hud::replay( void )
{
	this->_time += this->_pause;

	return ;
}

void		Hud::print( void )
{
	int		i;
	int		l;
	int		width;
	int		height;
	std::stringstream ss;

	getmaxyx( stdscr, height, width );

	for ( i = 0; i < this->getH(); i++ )
	{
		if ( !i || i == ( this->getH() - 1 ) )
		{
			l = -1;
			move( height - ( this->getH() - i ), 0 );
			while ( ++l >= 0 && l < width )
				addch( '#' );
		}
		else
		{
			addch( '#' );

			if ( i == 1 )
			{
				ss << " Lifes : " << this->life;
				printw( ss.str().c_str() );
				ss.str("");

				ss << " Time : " << ( time( NULL ) - this->_time );
				move( height - ( this->getH() - i ), width - ( 3 + ss.str().length() ) );
				printw( ss.str().c_str() );
				ss.str("");
			}

			if ( i == ( this->getH() / 2 ) )
			{
				ss << this->score;
				move( height - ( this->getH() - i ), ( width - ( 4 + ss.str().length() ) ) / 2 );
				printw( ss.str().c_str() );
				ss.str("");
			}

			if ( i == ( this->getH() - 3 ) )
			{
				move( height - ( this->getH() - i ), 1 );
				ss << " Enemies Number : " << this->enemyNumber;
				printw( ss.str().c_str() );
				ss.str("");
			}

			if ( i == ( this->getH() - 2 ) )
			{
				move( height - ( this->getH() - i ), 1 );
				ss << " Enemies Destroy : " << this->enemyDestroy;
				printw( ss.str().c_str() );
				ss.str("");
			}

			move( height - ( this->getH() - i ), width - 1 );
			addch( '#' );
		}
	}

	return ;
}

/*
 * Operators
 */

Hud &		Hud::operator=( Hud const & rhs )
{
	this->_height = rhs.getH();

	return ( *this );
}

// ************************************************************************** //
