/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:33:11 by svachere          #+#    #+#             */
/*   Updated: 2015/01/11 19:43:46 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <libc.h>

# include "AEntity.class.hpp"
# include "Display.class.hpp"
# include "Input.class.hpp"
# include "Player.class.hpp"
# include "Enemy.class.hpp"
# include "Missile.class.hpp"
# include "Hud.class.hpp"

# define ENTITIES_MAX		200
# define ENEMY_MAX			100
# define POP_ENEMY_CLOCK	10

class Game {
public:
	Game( void );
	Game( Game const & src );
	~Game( void );

	Game & operator=( Game const & rhs);

	int			getWinx() const;
	int			getWiny() const;
	Display *	getDisplay() const;
	Player	*	getPlayer() const;
	AEntity **	getEntities() const;

	void		loop( void );
	void		updateSate( void );
	void		print( void );
	void		pushEntity( AEntity * entity );
	bool		checkOffScreen( AEntity & entity );
	void		checkCollision( int i );
	void		checkDead( AEntity ** entity );
	void		checkFire( AEntity & entity );

private:
	int				_clock;
	AEntity **		_entities;
	int				_winx;
	int				_winy;
	Display *		_display;
	Player *		_player;
	Input *			_input;
	bool			_gameover;

};

#endif
