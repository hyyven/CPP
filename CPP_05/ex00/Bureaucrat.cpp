/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:21:33 by afont             #+#    #+#             */
/*   Updated: 2024/11/18 10:21:32 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return (o);
}