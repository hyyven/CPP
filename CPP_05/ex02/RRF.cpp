/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RRF.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:02:50 by afont             #+#    #+#             */
/*   Updated: 2024/09/02 10:17:20 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RRF.hpp"

RRF::RRF(const std::string &target) : AForm("RRF", 72, 45), _target(target)
{
}

RRF::~RRF(void)
{
}

std::string	RRF::getTarget(void) const
{
	return (this->_target);
}

void	RRF::execute(const Bureaucrat &bureaucrat) const
{
	if (!getSigned())
		throw AForm::NotSignedException();
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	static int i;
	if (++i % 2)
		std::cout << getTarget() << " robotomize succeeded" << std::endl;
	else
		std::cout << getTarget() << " robotomize failed" << std::endl;
}