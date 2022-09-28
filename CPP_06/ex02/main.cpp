/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:22:50 by marine            #+#    #+#             */
/*   Updated: 2022/09/26 19:48:44 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

// class Base {public: virtual ~Base(void) {} };
// class A: public Base {};
// class B: public Base {};
// class C: public Base {};


Base::~Base() {}

/*
	Point nerd: l'aléatoire/hasard n'existe pas réellement en programmation.
	Tout ce qu'on fait c'est le simuler mais il y aura toujours un pattern.
	D'ailleurs, il y a deux types d'algos (on exclut l'aléatoire absolu qui est théorique):
	1) PSEUDO-ALEATOIRE - les PRNGs (pseudorandom number generators): ce sont des algos récursifs qui ont besoin
		d'une seed (start value), avec un pattern suffisamment long pour qu'il ne se voie pas à l'oeil nu
		=> fast + cheap, mais manipulable si on connait la seed sur une séquence donnée (ce que font certains speedrunners)
	2) ALEATOIRE REEL - les TRNGs (True random number generators): au lieu d'utiliser une seed; on utilise 
		ce qu'on appelle l'entropie. Grosso modo, c'est un "bruit" (thermal noise) qui provient du hardware
		(ex: utiliser position de la souris à instant t, ou vitesse de rotation des pales du ventilateur,
		temp du CPU...), qui est vraiment une source externe d'aléatoire qu'on l'a appris à convertir en bits.
		=> beaucoup plus secure, utilisé dans le gambling, militaire, informations sensibles.
		=> mais très lent, et couteux, et pas si reliable que ça 
	Ca nous amène à une nouvelle approche:
	3) les CSPRNGs (Cryptographically-secure pseudorandom number generators): utilise un TRNG pour créer une seed pour PRNG
		=> Exemple: /dev/random

	Pour cet exo, on va rester sur du PRNG.
	Srand() définit le point de départ pour produire une série d’entiers pseudo-aléatoires. En pratique ce sera
	le temps actuel au moment de l'execution du programme (car l'heure change toujours). Il ne doit être appelé qu'une 
	seule fois, au début du programme.

	Rand() 
*/
Base	*generate(void)
{
	Base* nullPtr = NULL;
	
	int	randomResult = (std::rand() % 3) + 1;
	
	std::cout << "Generated an instance of ";
	switch (randomResult)
	{
		case 1:
			std::cout << BLUE << "A" << RESET << std::endl;
			return (new A);
		case 2:
			std::cout << YELLOW << "B" << RESET << std::endl;
			return (new B);
		case 3:
			std::cout << PURPLE << "C" << RESET << std::endl;
			return (new C);
		default:
			return (nullPtr);
	}
}


/*
	Point sur les dynamic casts
	-> permet de convertir les pointeurs et les références aux classes à 
		travers la hiérarchie d’héritage.
	-> fait partie de la fonction Run-Time Type Information (RTTI) qui fournit 
		un moyen d’accéder au type d’un objet au moment de l’exécution plutôt
		qu’au moment de la compilation.
	typiquement utilisé en cas de polymorphisme (d'où la fonction virtuelle de Base)
	SYNTAXE : dynamic_cast < new-type > ( expression )
	If the cast is successful, dynamic_cast returns a value of type new-type. 
	
*/

// pointeur -  renvoie nullptr si cast impossible
void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << BLUE << "A" << RESET << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << YELLOW << "B" << RESET << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << PURPLE << "C" << RESET << std::endl;
	}
}

// reference - throw une erreur bad cast si cast impossible
void	identify(Base &p)
{
	try
	{
		A testA = dynamic_cast<A &>(p);
		std::cout << BLUE << "A" << RESET << std::endl;
		return ;
	}
	catch(std::exception & e) {}
	try
	{
		B testB = dynamic_cast<B &>(p);
		std::cout << YELLOW << "B" << RESET << std::endl;
		return ;
	}
	catch(std::exception & e) {}
	try
	{
		C testC = dynamic_cast<C &>(p);
		std::cout << PURPLE << "C" << RESET << std::endl;
		return ;
	}
	catch(std::exception & e) {}
}

int	main(void)
{
	srand(time(NULL)); // on utilise le temps actuel comme seed 

	std::cout << "#### Generating a random Base-derived class ####" << std::endl;
	Base	*test = generate();
	Base	&ref_test = *test;

	std::cout << std::endl;

	std::cout << "[PTR] - The object pointed by test is : ";
	identify(test);
	std::cout << "[REF] - The object referenced by ref_test is : ";
	identify(ref_test);

	delete test; // cf. generate qui renvoie new Base *A/B/C 

	return (0);
}