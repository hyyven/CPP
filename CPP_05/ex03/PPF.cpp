/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PPF.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:48:32 by afont             #+#    #+#             */
/*   Updated: 2024/09/02 10:37:42 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PPF.hpp"

PPF::PPF(const std::string &target) : AForm("PPF", 25, 5), _target(target)
{
}

PPF::~PPF(void)
{
}

std::string PPF::getTarget(void) const
{
	return (this->_target);
}

void	PPF::execute(const Bureaucrat &bureaucrat) const
{
	if (!getSigned())
		throw AForm::NotSignedException();
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

