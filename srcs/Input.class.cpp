// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Input.class.cpp for rush00                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2013/09/25 08:56:14 by apergens          #+#    #+#             //
/*   Updated: 2015/01/11 17:50:26 by svachere         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "Input.class.hpp"

/*
 * Constructors
 */

Input::Input( void )
{
	this->_construct();

	return ;
}

Input::Input( int up, int down, int left, int right, int enter )
{
	this->_construct( up, down, left, right, enter );

	return ;
}

Input::Input( int up, int down, int left, int right, int enter, int up2, int down2, int left2, int right2, int enter2 )
{
	this->_construct( up, down, left, right, enter, up2, down2, left2, right2, enter2 );

	return ;
}

Input::Input( Input const & src )
{
	*this = src;

	return ;
}

/*
 * Destructor
 */

Input::~Input( void )
{
	return ;
}

/*
 * Getter Members
 */

int			Input::getKeyP1( void ) const
{
	return ( this->_keyP1 );
}

int			Input::getKeyP2( void ) const
{
	return ( this->_keyP2 );
}

/*
 * Setter Members
 */

void		Input::setP1KeyUp( int key )
{
	this->_keyP1Up = key ? key : this->_keyP1Up;

	return ;
}

void		Input::setP1KeyDown( int key )
{
	this->_keyP1Down = key ? key : this->_keyP1Down;

	return ;
}

void		Input::setP1KeyLeft( int key )
{
	this->_keyP1Left = key ? key : this->_keyP1Left;

	return ;
}

void		Input::setP1KeyRight( int key )
{
	this->_keyP1Right = key ? key : this->_keyP1Right;

	return ;
}

void		Input::setP1KeyEnter( int key )
{
	this->_keyP1Enter = key ? key : this->_keyP1Enter;

	return ;
}

void		Input::setP2KeyUp( int key )
{
	this->_keyP2Up = key ? key : this->_keyP2Up;

	return ;
}

void		Input::setP2KeyDown( int key )
{
	this->_keyP2Down = key ? key : this->_keyP2Down;

	return ;
}

void		Input::setP2KeyLeft( int key )
{
	this->_keyP2Left = key ? key : this->_keyP2Left;

	return ;
}

void		Input::setP2KeyRight( int key )
{
	this->_keyP2Right = key ? key : this->_keyP2Right;

	return ;
}

void		Input::setP2KeyEnter( int key )
{
	this->_keyP2Enter = key ? key : this->_keyP2Enter;

	return ;
}

void		Input::_setKey( void )
{
	int		_key;


	while ( ( _key = getch( ) ) != ERR && ( this->_keyP1 == INPUT_NULL || this->_keyP2 == INPUT_NULL ) )
	{
		if ( this->_keyP1 == INPUT_NULL )
		{
			this->_keyP1 = ( _key == this->_keyP1Up )		? KEY_UP	: this->_keyP1;
			this->_keyP1 = ( _key == this->_keyP1Down )		? KEY_DOWN	: this->_keyP1;
			this->_keyP1 = ( _key == this->_keyP1Left )		? KEY_LEFT	: this->_keyP1;
			this->_keyP1 = ( _key == this->_keyP1Right )	? KEY_RIGHT	: this->_keyP1;
			this->_keyP1 = ( _key == this->_keyP1Enter )	? KEY_ENTER	: this->_keyP1;
		}

		if ( this->_keyP2 == INPUT_NULL )
		{
			this->_keyP2 = ( _key == this->_keyP2Up )		? KEY_UP	: this->_keyP2;
			this->_keyP2 = ( _key == this->_keyP2Down )		? KEY_DOWN	: this->_keyP2;
			this->_keyP2 = ( _key == this->_keyP2Left )		? KEY_LEFT	: this->_keyP2;
			this->_keyP2 = ( _key == this->_keyP2Right )	? KEY_RIGHT	: this->_keyP2;
			this->_keyP2 = ( _key == this->_keyP2Enter )	? KEY_ENTER	: this->_keyP2;
		}

	}

	flushinp();
	return ;
}

/*
 * Other Members
 */

void		Input::_construct( void )
{
	this->_construct( KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, 32, 119, 115, 97, 100, 32 );
}

void		Input::_construct( int up, int down, int left, int right, int enter )
{
	this->_construct( up, down, left, right, enter, 119, 115, 97, 100, 32 );

	return ;
}

void		Input::_construct( int up, int down, int left, int right, int enter, int up2, int down2, int left2, int right2, int enter2 )
{
	this->_keyP1 = INPUT_NULL;
	this->_keyP2 = INPUT_NULL;

	this->_keyP1Up = up;
	this->_keyP1Down = down;
	this->_keyP1Left = left;
	this->_keyP1Right = right;
	this->_keyP1Enter = enter;

	this->_keyP2Up = up2;
	this->_keyP2Down = down2;
	this->_keyP2Left = left2;
	this->_keyP2Right = right2;
	this->_keyP2Enter = enter2;

	//nodelay( this->_win, true );
	//timeout( 0 );
	//cbreak();
	//keypad( stdscr, true );

	return ;
}

int			Input::getKey( int player )
{
	this->_setKey();

	if ( player == INPUT_P1 )
		return ( this->_keyP1 );
	else if ( player == INPUT_P2 )
		return ( this->_keyP2 );

	return ( INPUT_NULL );
}

void		Input::flush( void )
{
	this->_keyP1 = this->_keyP2 = INPUT_NULL;

	return ;
}

/*
 * Operators
 */

Input &		Input::operator=( Input const & rhs )
{
	this->_keyP1 = rhs.getKeyP1();
	this->_keyP2 = rhs.getKeyP2();

	return ( *this );
}

// ************************************************************************** //
