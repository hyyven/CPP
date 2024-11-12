/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RRF.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:03:03 by afont             #+#    #+#             */
/*   Updated: 2024/09/02 10:00:20 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRF_HPP
# define RRF_HPP

#include "AForm.hpp"

class Bureaucrat;

class RRF : public AForm
{
	private:
		const std::string	_target;
	public:
		RRF(const std::string &target);
		~RRF(void);
		std::string	getTarget(void) const;
		void execute(const Bureaucrat &bureaucrat) const;
};

#endif