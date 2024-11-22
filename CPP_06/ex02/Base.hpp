/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:38:20 by afont             #+#    #+#             */
/*   Updated: 2024/11/21 13:21:20 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

class	Base
{
	public:
		virtual ~Base(void);
};

class	A : public Base
{
};

class	B : public Base
{
};

class	C : public Base
{
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);