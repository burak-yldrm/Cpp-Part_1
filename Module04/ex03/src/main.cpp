#include <iostream>
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
		tmp = src->createMateria("cure");
	me->equip(tmp);
		tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(0, *me);
	me->unequip(0);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(1, *me);
	me->unequip(1);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
		tmp = src->createMateria("cure");
	me->equip(tmp);
		tmp = src->createMateria("cure");
	me->equip(tmp);
		tmp = src->createMateria("cure");
	me->equip(tmp);
		tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
