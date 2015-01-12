// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Hud.class.hpp for rush00                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2013/09/25 08:56:14 by apergens          #+#    #+#             //
//   Updated: 2015/01/05 10:48:35 by apergens         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUD_CLASS_HPP
# define HUD_CLASS_HPP

# include <ncurses.h>
# include <iostream>
# include <sstream>
# include <ctime>

class Hud
{

public:

	Hud( int height );
	Hud( Hud const & src );
	~Hud( void );

	Hud &		operator=( Hud const & rhs );

	int			getH( void ) const;

	void		setH( int height );

	void		pause( void );
	void		replay( void );
	void		print( void );

	int			life;
	int			score;
	int			enemyNumber;
	int			enemyDestroy;

private:

	Hud( void );

	int			_height;
	int			_time;
	int			_pause;

};

#endif // ***************************************************** HUD_CLASS_HPP //
