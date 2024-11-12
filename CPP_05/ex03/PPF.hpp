/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PPF.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:48:39 by afont             #+#    #+#             */
/*   Updated: 2024/09/02 10:22:30 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPF_HPP
# define PPF_HPP

#include "AForm.hpp"

class Bureaucrat;

class PPF : public AForm
{
	private:
		const std::string	_target;
	public:
		PPF(const std::string &target);
		~PPF(void);
		std::string	getTarget(void) const;
		void execute(const Bureaucrat &bureaucrat) const;
};

#endif