/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:06:30 by svachere          #+#    #+#             */
/*   Updated: 2015/01/11 21:19:25 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_H
# define AENTITY_H
# include <string>
# include <ctime>

class AEntity
{

public:

	AEntity( std::string tile );
	AEntity( AEntity const & src );
	virtual ~AEntity( void );

	AEntity & operator=( AEntity const & rhs );

	std::string 	getTile( void ) const;
	int				getX( void ) const;
	int				getY( void ) const;
	int				getVX( void ) const;
	int				getVY( void ) const;
	int				getHP( void ) const;
	int				getSX( void ) const;
	int				getSY( void ) const;
	bool			getHostile( void ) const;
	void			setHostile ( bool hostile );

	void			move( int x, int y );
	void			moveRel( int x, int y );
	virtual void	updatePosition( void ) = 0;
	void			takeDamage( int damage );
	bool			checkCollision( AEntity & entity ); // virtual
	void			tileOrigine( int & x, int & y );
	virtual bool	checkFire(int & x, int & y);
	virtual void	die( void );

	static int		count;
	static int		score;

protected:

	bool			_hostile;
	std::string 	_tile;
	float			_x;
	float			_y;
	float			_vx;
	float			_vy;
	int				_hp;
	int				_sx;
	int				_sy;

	AEntity( void );

};

#endif

