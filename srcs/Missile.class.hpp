/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:40:58 by svachere          #+#    #+#             */
/*   Updated: 2015/01/11 16:42:20 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_CLASS_H
# define MISSILE_CLASS_H
# include "AEntity.class.hpp"

class Missile : public AEntity
{

public:

	Missile( int x, int y, bool hostile );
	Missile( Missile const & src );
	~Missile();

	Missile &	operator=( Missile const rhs );

	void		updatePosition( void );


	static int	count;
	static int	countHostile;
	static int	countNHostile;

private:

	Missile( void );

};

#endif
