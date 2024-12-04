/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:55:09 by afont             #+#    #+#             */
/*   Updated: 2024/12/02 11:16:23 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	int	i = -1;
	
	while (++i < 4)
		_source[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	int	i = -1;
	
	while (++i < 4)
	{
		if (this->_source[i])
			delete this->_source[i];
		if (other._source[i])
			_source[i] = other._source[i]->clone();
		else
			_source[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void)
{
	int	i = -1;
	
	while (++i < 4)
		if (_source[i])
			delete _source[i];
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i = -1;
	
	while (++i < 4)
	{
		if (!_source[i])
		{
			_source[i] = m;
			return ;
		}
	}
	std::cout << "Can't learn more materia" << std::endl;
}

AMateria	*MateriaSource::getMateria(std::string const &type)
{
	int	i = -1;
	
	while (++i < 4)
		if (_source[i] && _source[i]->getType() == type)
			return (_source[i]);
	return (NULL);
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i = -1;
	
	while (++i < 4)
		if (_source[i] && _source[i]->getType() == type)
			return (_source[i]->clone());
	std::cout << "Materia doesn't exist or isn't learned" << std::endl;
	return (NULL);
}