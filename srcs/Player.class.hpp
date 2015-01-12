/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:32:00 by svachere          #+#    #+#             */
/*   Updated: 2015/01/11 19:32:07 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "AEntity.class.hpp"


class Player : public AEntity
{
public:
	Player( void );
	Player( std::string & tile );
	Player( Player const & src );
	~Player( void );

	Player &	operator=( Player const & rhs );

	int			getLife( void ) const;

	void		updatePosition( void );
	void		die( void );
	void		checkOffScreen( int winw, int winh );


	static int	count;

protected:
	int			_life;

};



#endif
