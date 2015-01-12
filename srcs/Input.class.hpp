// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Input.class.hpp for rush00                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2013/09/25 08:56:14 by apergens          #+#    #+#             //
/*   Updated: 2015/01/10 19:06:11 by svachere         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef INPUT_CLASS_HPP
# define INPUT_CLASS_HPP
# include <ncurses.h>
# include <iostream>

# define INPUT_P1	1
# define INPUT_P2	2
# define INPUT_NULL	-1

class Input
{

public:

	Input( void );
	Input( int up, int down, int left, int right, int enter );
	Input( int up, int down, int left, int right, int enter, int up2, int down2, int left2, int right2, int enter2 );
	Input( Input const & src );
	~Input( void );

	Input &				operator=( Input const & rhs );

	void				_construct( void );
	void				_construct( int up, int down, int left, int right, int enter );
	void				_construct( int up, int down, int left, int right, int enter, int up2, int down2, int left2, int right2, int enter2 );

	int					getKey( int player );
	int					getKeyP1( void ) const;
	int					getKeyP2( void ) const;

	void				setP1KeyUp( int key );
	void				setP1KeyDown( int key );
	void				setP1KeyLeft( int key );
	void				setP1KeyRight( int key );
	void				setP1KeyEnter( int key );

	void				setP2KeyUp( int key );
	void				setP2KeyDown( int key );
	void				setP2KeyLeft( int key );
	void				setP2KeyRight( int key );
	void				setP2KeyEnter( int key );

	void				flush( void );

private:

	int					_keyP1;
	int					_keyP2;

	int					_keyP1Up;
	int					_keyP1Down;
	int					_keyP1Left;
	int					_keyP1Right;
	int					_keyP1Enter;

	int					_keyP2Up;
	int					_keyP2Down;
	int					_keyP2Left;
	int					_keyP2Right;
	int					_keyP2Enter;

	void				_setKey( void );

};

#endif // *************************************************** INPUT_CLASS_HPP //
