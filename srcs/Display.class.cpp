// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Display.class.cpp for rush00                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2013/09/25 08:56:14 by apergens          #+#    #+#             //
/*   Updated: 2015/01/11 11:30:24 by svachere         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Display.class.hpp"

/*
 * Constructors
 */

Display::Display( void )
{
	this->_new( -1, -1 );

	return ;
}

Display::Display( int width, int height )
{
	this->_new( width, height );

	return ;
}

Display::Display( Display const & src )
{
	*this = src;

	return ;
}

/*
 * Destructor
 */

Display::~Display( void )
{
	if ( hud != NULL )
		delete hud;

	endwin();

	return ;
}

/*
 * Getter Members
 */

int			Display::getH( void ) const
{
	if ( this->hud != NULL )
		return ( this->_h - this->hud->getH() );

	return ( this->_h );
}

int			Display::getW( void ) const
{
	return ( this->_w );
}

/*
 * Other Members
 */

void		Display::_new( int width, int height )
{
	initscr();

	raw();
	cbreak();
	keypad( stdscr, true );
	nodelay( stdscr, true );

	noecho();
	nonl();
	curs_set(0);

	if ( width <= 0 || height <= 0 )
		getmaxyx( stdscr, height, width );

	this->_h = height;
	this->_w = width;

	//init_pair( 1, COLOR_RED, COLOR_GREEN );
	//bkgd( A_NORMAL | COLOR_PAIR(1) | ' ' );

	this->hud = new Hud( 5 );

	return ;
}

void		Display::print( AEntity const & entity )
{
	mvprintw( entity.getY(), entity.getX(), entity.getTile().c_str());
	move( 0, 0 );

	return ;
}

void		Display::clear( void )
{
	erase();
}

void		Display::flush( void )
{
	this->hud->print();
	refresh();

	return ;
}

/*
 * Operators
 */

Display &		Display::operator=( Display const & rhs )
{
	this->_h = rhs.getH();
	this->_w = rhs.getW();

	this->hud = rhs.hud;

	return ( *this );
}

// ************************************************************************** //
