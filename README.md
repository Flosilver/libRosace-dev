# libRosace - README

**Auteurs**: [Flosilver](https://github.com/Flosilver) & [Mieppe](https://github.com/Mieppe)
______

## Introduction

Cette librairie static C++ est née en 2020 à l'occasion d'un stage pour un projet de plateforme de jeux vidéos.
LibRosace est donc destinée à aider la programmation, en C++, de jeux vidéos en réseaux à 4 joueurs maximum. La libraire les nommes __North__, __East__, __South__ and __West__. Ces noms représentent simplement leurs positionement autour de la plateforme de jeux. Cette librairie pourra donc servir de base de construction pour des jeux réseaux à 4 joueurs nécessitant de la fiabilit et de la rapidité grâce au protocol ENet.
**IMPORTANT:** Cette librairie nécessite ENet déjà présent sur la machine pour l'installé.
______

## Installation

* Cloner le [git du projet](https://github.com/Flosilver/libRosace-dev) dans un répertoire de votre ordinateur. 
* Une fois dans votre répertoire d'installation, un petit `"make"` dans le terminal suffit.
* La désinstallation est également possible avec la commande `"uninstall"`.
______

## Fonctionnement

LibRosace possède son propre namespace:
> rsc

Impératif pour utiliser les classes de la librairie.
Pour include la librairie à votre code, écrivez:

`#include <Rosace.hpp>` en en-tête de votre programme.
LibRosace propose plusieurs classes C++ qui aident à la création d'un jeu:

### 1. `Vector2` et `Vector3`

Ils facilitent la manipulation 2D et 3D de tout ce que vous souhaitez. Ils sont codés avec un `template` et peuvent donc être tous les deux utilisés avec de `int`, des `float`, des `double` et sans doute toute autre classe qui dispose de tous les `operator` implémentés dans ces classes.
Sont aussi proposés, des vecteurs de base (int, float, unsigned_int): `Vect2i`, `Vect2f`, `Vect2u` (respectivement pour les Vector3)

### 2. `Deck` & `Card`

Une classe de simple carte est disponible, elle possède unique une valeur pouvant représenter une valeur, un numéro de carte ou tout audre indication qu'une crate peux posséder. Pour ajouter des éléments, il suffit d'hériter de cette classe pour 
Le `Deck` quand à lui possède une pile de cartes, cad une list de pointeurs `Card`. Ainsi toute classe héritant de `Card` pourra être ajouté au Deck.

**ATTENTION**: il s'agit de `shared_ptr`, comme ce sont des pointeurs, pour utiliser les méthodes propres de vos classes héritées, il faudra caster les cartes de la pile du `Deck` avec la méthode dédiée des shared_ptr: `dynamic_pointer_cast`.

### 3. `Player`

Cette classe possède un entier représentant sa place autour de la plateforme de jeux: North, East, South et West. Il possède également une variable booléenne permettant de savoir si le joueur est connecté, les méthodes `login` & `logout` vont de pair avec cet attribut.
Tout nouveau type de joueur peut être créé à partir de cette qui ne concentre que le strict minimum.

### 4. `Pawn` & `IMovable`

Un pion tout ce qu'il y a de plus simple! Souvent attribué à une classe dérivant de `Player` pouvant représenté le joueur sur un plateau, il peut également servir de représentation pour tout élément sur le terrain de jeux. Cette classe implémente l'interface `IMovable` qui impose un déplacement possible pour toute classe classe l'implémentant.

### 5. `Game`

La classe la plus importante, elle contient l'essentiel de la programmation réseau *ENet*: l'initialisation du serveur built-in, une méthode permettant de séléctionner le port du serveur, l'envoie de message réseaux aux différents joueurs ainsi que la reception d'evenement réseaux.

**IMPORTANT**: Cette classe est abstraite et doit impérativement implémenter la méthode `handleIncommingMessage` qui regroupera l'ensemble des règles du jeux et la signification des messages serveurs reçus et envoyés. A noté également que `Game` ce sert de la notion d'état pour gérer le fonctionnement du jeux (ex: "connexion", "jeu", "fin"). Cette notion n'est pas impérative mais fortement recommandée pour l'organisation de votre jeux.