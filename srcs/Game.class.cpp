/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:32:56 by svachere          #+#    #+#             */
/*   Updated: 2015/01/11 21:23:55 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"

// CONSTRUCTOR

Game::Game( void ) : _gameover(false)
{
	_display = new Display();
	_player = new Player();
	_input = new Input();
	_entities = new AEntity*[ENTITIES_MAX];
	_entities[0] = _player;
	_clock = 0;
}

Game::Game( Game const & src )
{
	*this = src;
}

Game::~Game( void )
{
	for (int i = 0 ; i < ENTITIES_MAX ; i++)
	{
		if (_entities[i] != NULL)
			delete _entities[i];
	}
	delete _input;
	delete _display;
}

// OPERATORS

Game &	Game::operator=( Game const & rhs)
{
	this->_winx = rhs.getWinx();
	this->_winy = rhs.getWiny();
	this->_display = rhs.getDisplay();
	this->_player = rhs.getPlayer();
	for (int i = 0; i < ENTITIES_MAX; i++)
		this->_entities[0] = rhs.getEntities()[0];
	return (*this);
}

// PUBLIC FUNCTIONS

int				Game::getWinx() const {return _winx;}
int				Game::getWiny() const {return _winy;}
Display *		Game::getDisplay() const {return _display;}
Player	*		Game::getPlayer() const {return _player;}
AEntity	**		Game::getEntities() const {return _entities;}

void	Game::loop( void )
{
	while (!_gameover)
	{
		_clock += 1;
		usleep(10000);
		this->updateSate();
		this->print();
		_input->flush();
	}
}

void	Game::updateSate( void )
{
	int	key = _input->getKey( INPUT_P1 );

	if (key == KEY_UP)
		_player->moveRel(0 , -1);
	if (key == KEY_RIGHT)
		_player->moveRel(1 , 0);
	if (key == KEY_DOWN)
		_player->moveRel(0 , 1);
	if (key == KEY_LEFT)
		_player->moveRel(-1 , 0);
	if (key == KEY_ENTER)
		this->pushEntity(new Missile(_player->getX() + 1, _player->getY(), false));

	_player->checkOffScreen( _display->getW(), _display->getH() );
	if ( ! (_clock % POP_ENEMY_CLOCK ) && Enemy::count < ENEMY_MAX )
		this->pushEntity(new Enemy( _display->getW(), rand() % _display->getH() ) );
	for ( int i = 0 ; i < ENTITIES_MAX ; i++)
	{
		if (_entities[i] != NULL )
		{
			_entities[i]->updatePosition();
			this->checkOffScreen(*_entities[i]);
			this->checkCollision(i);
			this->checkFire(*_entities[i]);
			this->checkDead(&_entities[i]);
		}
	}
	if (_entities[0] == NULL)
		_gameover = true;
}

void	Game::checkCollision( int index )
{
	int	hp1;
	int	hp2;

	for (int i = index + 1; i < ENTITIES_MAX ; i++)
	{
		if ( _entities[i] != NULL
			&& _entities[index]->getHostile() != _entities[i]->getHostile()
			&& _entities[index]->checkCollision( * _entities[i] ) )
		{
			hp1 = _entities[index]->getHP();
			hp2 = _entities[i]->getHP();
			_entities[index]->takeDamage( hp2 );
			_entities[i]->takeDamage( hp1 );
		}
	}
}

void	Game::checkFire( AEntity & entity )
{
	int x;
	int	y;

	if ( entity.checkFire(x, y) )
		this->pushEntity( new Missile(x - 1, y, true) );
}

void	Game::checkDead( AEntity ** entity )
{
	if ( (*entity)->getHP() == 0 )
	{
		delete *entity;
		*entity = NULL;
	}

}

void	Game::pushEntity( AEntity * entity )
{
	for ( int i = 1 ; i < ENTITIES_MAX ; i++)
	{
		if (_entities[i] == NULL)
		{
			_entities[i] = entity;
			break;
		}
	}
}

bool	Game::checkOffScreen( AEntity & entity )
{
	if ( entity.getX() < 0 || entity.getX() >= _display->getW()
		|| entity.getY() < 0 || entity.getY() >= _display->getH() )
	{
		entity.die();
		return true;
	}
	return false;
}

void	Game::print( void )
{
	_display->clear();
	_display->hud->score = AEntity::score;
	_display->hud->enemyNumber = Enemy::count;
	_display->hud->enemyDestroy = AEntity::score / 42;
	_display->hud->life = this->_player->getLife();
	for ( int i = 0 ; i < ENTITIES_MAX ; i++ )
	{
		if ( _entities[i] != NULL )
			_display->print( *_entities[i] );
	}
	_display->flush();
}
