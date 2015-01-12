// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Display.class.hpp for rush00                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2013/09/25 08:56:14 by apergens          #+#    #+#             //
//   Updated: 2015/01/05 10:48:35 by apergens         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DISPLAY_CLASS_HPP
# define DISPLAY_CLASS_HPP

# include <ncurses.h>

# include "AEntity.class.hpp"
# include "Hud.class.hpp"

class Display
{

public:

	Display( void );
	Display( int width, int height );
	Display( Display const & src );
	~Display( void );

	Display &	operator=( Display const & rhs );

	int			getH( void ) const;
	int			getW( void ) const;

	void		print( AEntity const & entity );
	void		clear( void );
	void		flush( void );

	Hud			*hud;

private:

	int			_h;
	int			_w;

	void		_new( int width, int height );

};

#endif // ************************************************* DISPLAY_CLASS_HPP //
