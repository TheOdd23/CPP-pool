/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 07:27:51 by anhebert          #+#    #+#             */
/*   Updated: 2022/11/08 12:10:43 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>
#pragma once

class AAnimal
{
public:
    AAnimal();
    AAnimal( std::string type );
    AAnimal( AAnimal const &src );
    virtual ~AAnimal();
    AAnimal &operator=( AAnimal const &src );

    virtual void makeSound() const = 0;
    const std::string &getType() const;
protected:
    std::string type;
};

#endif