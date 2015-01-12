/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:56:13 by svachere          #+#    #+#             */
/*   Updated: 2015/01/11 19:06:15 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENEMY_CLASS_H
# define ENEMY_CLASS_H
# include "AEntity.class.hpp"
# define ENEMY_FIRE_CLOCK 100

class AEntity;

class Enemy : public AEntity {
public:
	~Enemy( void );
	Enemy( int x, int y );
	Enemy( Enemy const & src );

	//Enemy &		operator=( Enemy const rhs );

	void		updatePosition( void );
	bool		checkFire(int & x, int & y);

	static int	count;

private:

	Enemy( void );

	int			_clock;

};

#endif
