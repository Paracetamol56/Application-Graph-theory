//Copyright 2010-2013 Benjamin ALBOUY-KISSI
/*
    This file is part of LibGraph.

    LibGraph is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    LibGraph is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with LibGraph. If not, see <http://www.gnu.org/licenses/>.
*/

//Documentation de la page principale
/*!
 * \mainpage
 * \tableofcontents
 * \section Intrp Introduction
 * \subsection Pres Présentation
 * LibGraph 2 est une bibliothèque graphique simplifiée. Elle permet par un jeu de fonctionnalités d'afficher une fenêtre graphique et d'y afficher différentes formes. 
 * \image html mainpage.png "Capture d'écran d'un logiciel entièrement développé à l'aide de LibGraph 2"
 * \subsection Levels Niveaux d'utilisation
 * La bibliothèque s'adapte au niveau d'expérience de l'utilisateur selon 5 niveaux (Cliquez sur l'une des descriptions pour accéder à la documentation du niveau) :
 * \li \b NIVEAU \b 0 : \e Novice        : <A HREF="../../doc-0/html/index.html">Aucun pointeur, aucun objet, pas de passage par référence, seulement des appels de fonctions</A>
 * \li \b NIVEAU \b 1 : \e Débutant      : <A HREF="../../doc-1/html/index.html">Des passages par références, pas de pointeurs, pas d'objet</A>
 * \li \b NIVEAU \b 2 : \e Intermédiaire : <A HREF="../../doc-2/html/index.html">Des passages par références, des pointeurs, pas d'objet</A>
 * \li \b NIVEAU \b 3 : \e Avancé        : <A HREF="../../doc-3/html/index.html">Quelques objets</A>
 * \li \b NIVEAU \b 4 : \e Expert        : <A HREF="../../doc-4/html/index.html">(niveau par défaut) Tout objet</A>
 *
 * \ifnot AIDEPOURUNNIVEAU
 *  \section install Installation
 *  Quelque soit le niveau d'expérience choisi, l'installation de la bibliothèque suit toujours la même procédure : 
 *  \subsection projectcreation Création du projet Visual Studio 2010
 *  Créez un nouveau projet Visual Studio 2010 de type \b Visual \b C++ / \b Projet \b vide :
 *  \image html create-project-vs2010.png
 *  \subsection filecopy Copie des fichiers
 *  \li Copier les répertoires \c lib et \c inc dans le répertoire de votre projet (à côté du fichier \c *.vcxproj) :
 *  \image html install-1.png
 *  \li Copier les fichiers \c lib\\Release\\LibGraph2.dll et \c lib\\Debug\\LibGraph2.dll respectivement dans les répertoires \c Release et \c Debug  de votre solution :
 *  \image html install-2.png "Répertoires Release et Debug cibles"
 *  \subsection projectsetup Configuration du projet
 *  \li Ajoutez un fichier source avec le code d'exemple (Les codes d'exemples sont disponibles dans les fichiers d'aides des niveaux spécifiques).
 *  \li Ouvrir les propriétés du projet (Dans Visual Studio 2010, faites un clic droit sur le projet puis Propriétés)
 *  \li Choisissez \b "Toutes les configurations" dans la liste déroulante \b "Configuration :" puis dans la page \b "C/C++" / \b "Général", spécifiez \c "$(ProjectDir)inc;%(AdditionalIncludeDirectories)" dans le champ \b "Autres répertoires Include"
 *  \image html projet-properties-vs2010-1.png
 *  \li Dans la page \b "Editeur de liens" / \b "Général", spécifiez \c "$(ProjectDir)lib\$(Configuration);%(AdditionalLibraryDirectories)" dans le champ \b "Répertoires de bibliothèques supplémentaires" :
 *  \image html projet-properties-vs2010-2.png
 *  \li Dans la page \b "Editeur de liens" / \b "entrée", ajoutez \c "LibGraph2.lib" au champ \b "Dépendances supplémentaires" :
 *  \image html projet-properties-vs2010-3.png
 *  \li Validez, compilez, exécutez.
 * \else
 *  \section install Installation
 *  La procédure d'installation est décrite dans le <A HREF="../../doc/html/index.html">fichier d'aide global</A>.
 * \endif
 *
 * \cond AIDEPOURUNNIVEAU
 * \section sample Exemple d'utilisation
 * \if NIVEAU0
 *  \attention Cette documentation concerne le niveau 0
 *
 *  Pour utiliser ce niveau, incluez le fichier par la syntaxe suivante :
 *  \code
 * #define LIBGRAPH2_LEVEL 0   //Définition du niveau d'expérience
 * #include <LibGraph2.h>      //Inclusion du fichier d'en-tête de la bibliothèque
 * using namespace LibGraph2;  //Importation de l'espace de nom de la bibliothèque
 *  \endcode
 *  
 *  Voici la structure classique d'une application basée sur LibGraph 2 de Niveau 0 :
 *  \code
 * #include <Windows.h>
 * #include <tchar.h>
 * #define LIBGRAPH2_LEVEL 0
 * #include <LibGraph2.h>
 * using namespace LibGraph2;
 *
 * int APIENTRY _tWinMain(HINSTANCE hInstance,
 *                      HINSTANCE hPrevInstance,
 *                      LPTSTR    lpCmdLine,
 *                      int       nCmdShow)
 * {
 *   UNREFERENCED_PARAMETER(hPrevInstance);
 *   UNREFERENCED_PARAMETER(lpCmdLine);
 *
 *   //Affiche la fenêtre graphique avec une taille par défaut
 *   show();
 *
 *   //Boucle principale d'événements
 *   while(waitForEvent())
 *   {
 *     switch(getLastEventType())  //En fonction du type du dernier événement
 *     {
 *     case evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
 *       //Utiliser éventuellement les fonctions beginPaint() / endPaint() pour activer le backbuffer
 *       beginPaint();
 *         //Utiliser ici les fonctions de dessins
 *       endPaint();
 *       break;
 *
 *     case evtKeyDown:  //Enfoncement d'une touche
 *       switch(getLastEventKeyCode()) //En fonction de la touche enfoncée
 *       {
 *       case 'A':
 *         break;
 *       }
 *       break;
 *
 *     case evtMouseMove:  //Déplacement de la souris
 *       {
 *         int x = getLastEventMouseX(); //Position x de la souris
 *         int y = getLastEventMouseY(); //Position y de la souris
 *       }
 *       break;
 *     }
 *   }
 *   //Libération de la mémoire liée à LibGraph 2
 *   ReleaseLibGraph2();
 *   return 0;
 * }
 *  \endcode
 * \endif
 * \if NIVEAU1
 *  \attention Cette documentation concerne le niveau 1
 *
 *  Pour utiliser ce niveau, incluez le fichier par la syntaxe suivante :
 *  \code
 * #define LIBGRAPH2_LEVEL 1   //Définition du niveau d'expérience
 * #include <LibGraph2.h>      //Inclusion du fichier d'en-tête de la bibliothèque
 * using namespace LibGraph2;  //Importation de l'espace de nom de la bibliothèque
 *  \endcode
 *  
 *  Voici la structure classique d'une application basée sur LibGraph 2 de Niveau 1 :
 *  \code
 * #include <Windows.h>
 * #include <tchar.h>
 * #define LIBGRAPH2_LEVEL 1
 * #include <LibGraph2.h>
 * using namespace LibGraph2;
 *
 * int APIENTRY _tWinMain(HINSTANCE hInstance,
 *                      HINSTANCE hPrevInstance,
 *                      LPTSTR    lpCmdLine,
 *                      int       nCmdShow)
 * {
 *   UNREFERENCED_PARAMETER(hPrevInstance);
 *   UNREFERENCED_PARAMETER(lpCmdLine);
 *
 *   evt_type tEvt;  //Type de l'événement reçu
 *   int nVkCode;    //Code de la touche si événement clavier
 *   int nMouseX;    //Position x de la souris si événement souris
 *   int nMouseY;    //Position y de la souris si événement souris
 *
 *   //Affiche la fenêtre graphique avec une taille par défaut
 *   show();
 *
 *   //Boucle principale d'événements
 *   while(waitForEvent(tEvt, nVkCode, nMouseX, nMouseY))
 *   {
 *     switch(tEvt)  //En fonction du type du dernier événement
 *     {
 *     case evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
 *       //Utiliser éventuellement les fonctions beginPaint() / endPaint() pour activer le backbuffer
 *       beginPaint();
 *         //Utiliser ici les fonctions de dessins
 *       endPaint();
 *       break;
 *
 *     case evtKeyDown:  //Enfoncement d'une touche
 *       switch(nVkCode) //En fonction de la touche enfoncée
 *       {
 *       case 'A':
 *         break;
 *       }
 *       break;
 *
 *     case evtMouseMove:  //Déplacement de la souris
 *       //Position de la souris dans les variables nMouseX et nMouseY
 *       break;
 *     }
 *   }
 *   //Libération de la mémoire liée à LibGraph 2
 *   ReleaseLibGraph2();
 *   return 0;
 * }
 *  \endcode
 * \endif
 * \if NIVEAU2
 *  \attention Cette documentation concerne le niveau 2
 *
 *  Pour utiliser ce niveau, incluez le fichier par la syntaxe suivante :
 *  \code
 * #define LIBGRAPH2_LEVEL 2   //Définition du niveau d'expérience
 * #include <LibGraph2.h>      //Inclusion du fichier d'en-tête de la bibliothèque
 * using namespace LibGraph2;  //Importation de l'espace de nom de la bibliothèque
 *  \endcode
 *  
 *  Voici la structure classique d'une application basée sur LibGraph 2 de Niveau 2 :
 *  \code
 * #include <Windows.h>
 * #include <tchar.h>
 * #define LIBGRAPH2_LEVEL 2
 * #include <LibGraph2.h>
 * using namespace LibGraph2;
 *
 * int APIENTRY _tWinMain(HINSTANCE hInstance,
 *                      HINSTANCE hPrevInstance,
 *                      LPTSTR    lpCmdLine,
 *                      int       nCmdShow)
 * {
 *   UNREFERENCED_PARAMETER(hPrevInstance);
 *   UNREFERENCED_PARAMETER(lpCmdLine);
 *
 *   evt_type tEvt;  //Type de l'événement reçu
 *   int nVkCode;    //Code de la touche si événement clavier
 *   int nMouseX;    //Position x de la souris si événement souris
 *   int nMouseY;    //Position y de la souris si événement souris
 *
 *   //Affiche la fenêtre graphique avec une taille par défaut
 *   show();
 *
 *   //Boucle principale d'événements
 *   while(waitForEvent(tEvt, nVkCode, nMouseX, nMouseY))
 *   {
 *     switch(tEvt)  //En fonction du type du dernier événement
 *     {
 *     case evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
 *       //Utiliser éventuellement les fonctions beginPaint() / endPaint() pour activer le backbuffer
 *       beginPaint();
 *         //Utiliser ici les fonctions de dessins
 *       endPaint();
 *       break;
 *
 *     case evtKeyDown:  //Enfoncement d'une touche
 *       switch(nVkCode) //En fonction de la touche enfoncée
 *       {
 *       case 'A':
 *         break;
 *       }
 *       break;
 *
 *     case evtMouseMove:  //Déplacement de la souris
 *       //Position de la souris dans les variables nMouseX et nMouseY
 *       break;
 *     }
 *   }
 *   //Libération de la mémoire liée à LibGraph 2
 *   ReleaseLibGraph2();
 *   return 0;
 * }
 *  \endcode
 * \endif
 * \if NIVEAU3
 *  \attention Cette documentation concerne le niveau 3
 *
 *  Pour utiliser ce niveau, incluez le fichier par la syntaxe suivante :
 *  \code
 * #define LIBGRAPH2_LEVEL 3   //Définition du niveau d'expérience
 * #include <LibGraph2.h>      //Inclusion du fichier d'en-tête de la bibliothèque
 * using namespace LibGraph2;  //Importation de l'espace de nom de la bibliothèque
 *  \endcode
 *  
 *  Voici la structure classique d'une application basée sur LibGraph 2 de Niveau 3 :
 *  \code
 * #include <Windows.h>
 * #include <tchar.h>
 * #define LIBGRAPH2_LEVEL 3
 * #include <LibGraph2.h>
 * using namespace LibGraph2;
 *
 * int APIENTRY _tWinMain(HINSTANCE hInstance,
 *                      HINSTANCE hPrevInstance,
 *                      LPTSTR    lpCmdLine,
 *                      int       nCmdShow)
 * {
 *   UNREFERENCED_PARAMETER(hPrevInstance);
 *   UNREFERENCED_PARAMETER(lpCmdLine);
 *
 *   //Récupération de l'objet principal de LibGraph 2
 *   ILibGraph2* libgraph = GetLibGraph2();
 *   //Affiche la fenêtre graphique avec une taille par défaut
 *   libgraph->show();
 *   evt e;  //Evénement LibGraph 2
 *
 *   //Boucle principale d'événements
 *   while(libgraph->waitForEvent(e))
 *   {
 *     switch(e.type)  //En fonction du type d'événement
 *     {
 *     case evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
 *       //Utiliser éventuellement les fonctions libgraph->beginPaint() / libgraph->endPaint() pour activer le backbuffer
 *       libgraph->beginPaint();
 *         //Utiliser ici les fonctions de dessins
 *       libgraph->endPaint();
 *       break;
 *
 *     case evtKeyDown:  //Enfoncement d'une touche
 *       switch(e.vkKeyCode) //En fonction de la touche enfoncée
 *       {
 *       case 'A':
 *         break;
 *       }
 *       break;
 *
 *     case evtMouseMove:  //Déplacement de la souris
 *       //Position de la souris dans les variables e.x et e.y
 *       break;
 *     }
 *   }
 *
 *   //Libération de l'objet principal de LibGraph 2
 *   ReleaseLibGraph2();
 *   return 0;
 * }
 *  \endcode
 * \endif
 * \if NIVEAU4
 *  \attention Cette documentation concerne le niveau 4
 *
 *  Pour utiliser ce niveau, incluez le fichier par la syntaxe suivante :
 *  \code
 * #define LIBGRAPH2_LEVEL 4   //Définition du niveau d'expérience
 * //Note : la définition du niveau 4 est optionnelle car il s'agit du niveau par défaut
 * #include <LibGraph2.h>      //Inclusion du fichier d'en-tête de la bibliothèque
 *  using namespace LibGraph2;  //Importation de l'espace de nom de la bibliothèque
 *  \endcode
 *  
 *  Voici la structure classique d'une application basée sur LibGraph 2 de Niveau 4 :
 *  \code
 * #include <Windows.h>
 * #include <tchar.h>
 * #include <LibGraph2.h>
 * using namespace LibGraph2;
 *
 * int APIENTRY _tWinMain(HINSTANCE hInstance,
 *                      HINSTANCE hPrevInstance,
 *                      LPTSTR    lpCmdLine,
 *                      int       nCmdShow)
 * {
 *   UNREFERENCED_PARAMETER(hPrevInstance);
 *   UNREFERENCED_PARAMETER(lpCmdLine);
 *
 *   //Récupération de l'objet principal de LibGraph 2
 *   ILibGraph2* libgraph = GetLibGraph2();
 *   //Affiche la fenêtre graphique avec une taille par défaut
 *   libgraph->show();
 *   evt e;  //Evénement LibGraph 2
 *
 *   //Boucle principale d'événements
 *   while(libgraph->waitForEvent(e))
 *   {
 *     switch(e.type)  //En fonction du type d'événement
 *     {
 *     case evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
 *       //Utiliser éventuellement les fonctions libgraph->beginPaint() / libgraph->endPaint() pour activer le backbuffer
 *       libgraph->beginPaint();
 *         //Utiliser ici les fonctions de dessins
 *       libgraph->endPaint();
 *       break;
 *
 *     case evtKeyDown:  //Enfoncement d'une touche
 *       switch(e.vkKeyCode) //En fonction de la touche enfoncée
 *       {
 *       case 'A':
 *         break;
 *       }
 *       break;
 *
 *     case evtMouseMove:  //Déplacement de la souris
 *       //Position de la souris dans les variables e.x et e.y
 *       break;
 *     }
 *   }
 *
 *   //Libération de l'objet principal de LibGraph 2
 *   ReleaseLibGraph2();
 *   return 0;
 * }
 *  \endcode
 * \endif
 *
 *
 */

/*!
 * \file LibGraph2.h
 * 
 * \author Benjamin ALBOUY-KISSI
 * \version 2.0
 * \date 2012
 * \copyright GNU Public License
 *
 * \brief Fichier d'inclusion principal
 *
 * Incluez ce fichier pour bénéficier des fonctionnalités de la bibliothèque LibGraph 2.
 *
 * Cette bibliothèque propose 5 niveaux d'utilisation en fonction des compétences de l'utilisateur
 * \li \b NIVEAU \b 0 : \e Novice : Aucun pointeur, aucun objet, pas de passage par référence, seulement des appels de fonctions
 * \li \b NIVEAU \b 1 : \e Débutant : Des passages par références, pas de pointeurs, pas d'objet
 * \li \b NIVEAU \b 2 : \e Intermédiaire : Des passages par références, des pointeurs, pas d'objet
 * \li \b NIVEAU \b 3 : \e Avancé : Quelques objets
 * \li \b NIVEAU \b 4 : \e Expert : (niveau par défaut) Tout objet
 *
 * \if NIVEAU0
 *  \attention Cette documentation concerne le niveau 0
 *
 *  Pour utiliser ce niveau, incluez le fichier par la syntaxe suivante :
 *  \code
 *  #define LIBGRAPH2_LEVEL 0
 *  #include <LibGraph2.h>
 *  \endcode
 * \endif
 * \if NIVEAU1
 *  \attention Cette documentation concerne le niveau 1
 *
 *  Pour utiliser ce niveau, incluez le fichier par la syntaxe suivante :
 *  \code
 *  #define LIBGRAPH2_LEVEL 1
 *  #include <LibGraph2.h>
 *  \endcode
 * \endif
 * \if NIVEAU2
 *  \attention Cette documentation concerne le niveau 2
 *
 *  Pour utiliser ce niveau, incluez le fichier par la syntaxe suivante :
 *  \code
 *  #define LIBGRAPH2_LEVEL 2
 *  #include <LibGraph2.h>
 *  \endcode
 * \endif
 * \if NIVEAU3
 *  \attention Cette documentation concerne le niveau 3
 *
 *  Pour utiliser ce niveau, incluez le fichier par la syntaxe suivante :
 *  \code
 *  #define LIBGRAPH2_LEVEL 3
 *  #include <LibGraph2.h>
 *  \endcode
 * \endif
 * \if NIVEAU4
 *  \attention Cette documentation concerne le niveau 4
 *
 *  Pour utiliser ce niveau, incluez le fichier par la syntaxe suivante :
 *  \code
 *  #define LIBGRAPH2_LEVEL 4
 *  #include <LibGraph2.h>
 *  \endcode
 * \endif
 */
#pragma once
// Le bloc ifdef suivant est la façon standard de créer des macros qui facilitent l'exportation 
// à partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compilés avec le symbole BEAUH_EXPORTS
// défini sur la ligne de commande. Ce symbole ne doit pas être défini dans les projets
// qui utilisent cette DLL. De cette manière, les autres projets dont les fichiers sources comprennent ce fichier considèrent les fonctions 
// BEAUH_API comme étant importées à partir d'une DLL, tandis que cette DLL considère les symboles
// définis avec cette macro comme étant exportés
#ifdef LIBGRAPH2_EXPORTS
#define LIBGRAPH2_API __declspec(dllexport)
#define LIBGRAPH2_LEVEL 4
#else
#define LIBGRAPH2_API __declspec(dllimport)
#endif

#pragma warning(push)
#pragma warning(disable : 4996)

//définition des niveaux de LibGraph
/* 
  NIVEAU | Description
    0      Novice : Aucun pointeur, aucun objet, pas de passage par référence, seulement des appels de fonctions
    1      Débutant : Des passages par références, pas de pointeurs, pas d'objet
    2      Intermédiaire : Des passages par références, des pointeurs, pas d'objet
    3      Avancé : Quelques objets
    4      Expert : Tout objet
*/
#ifndef LIBGRAPH2_LEVEL
#define LIBGRAPH2_LEVEL 4
#endif
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>
#include <tchar.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

//Définition des groupes de documentation
//Groupes de niveaux supérieurs
/*!\defgroup FonctGraph Fonctionnalités graphiques
 * \brief Contient toutes les fonctionnalités permettant de dessiner
 */
  /*!\defgroup DrawingManagement Gestion de l'affichage
   * \brief Contient toutes les fonctionnalités gérant l'optimisation de l'affichage
   *
   * Ces fonctions permettent de gérer l'affichage graphique et son optimisation
   * \ingroup FonctGraph
   */
  /*!\defgroup Drawing Fonctionnalités d'affichage
   * \brief Contient toutes les fonctionnalités permettant d'afficher des informations
   * \ingroup FonctGraph
   */
    /*!\defgroup DrawingProperties Définition des attributs d'affichage
     * \brief Contient toutes les fonctionnalités spécifier les attibuts de dessins (crayon, pinceau, police de caractères)
     *
     * Ces fonctions permettent de définir les attributs de dessin. Pour dessiner, LibGraph 2 fonctionne
     * un peu comme un dessinateur qui possède des crayons pour dessiner ses formes et des pinceaux pour les
     * remplir. Le dessinateur choisit son crayon (setPen()) et son pinceau (setSolidBrush() ou 
     * setTextureBrush()) puis trace une forme à l'aide de ces deux instruments (les fonctions de dessin de
     * formes et de textes).
     * \ingroup Drawing
     */
    /*!\defgroup DrawingShapes Fonctionnalités de dessin de formes 
     * \brief Contient toutes les fonctionnalités pour dessiner des formes (arc, rectangle, ...)
     *
     * Ces fonctions permettent de dessiner dans la fenêtre graphique. Pour dessiner, LibGraph 2 fonctionne
     * un peu comme un dessinateur qui possède des crayons pour dessiner ses formes et des pinceaux pour les
     * remplir. Le dessinateur choisit son crayon (setPen()) et son pinceau (setSolidBrush() ou 
     * setTextureBrush()) puis trace une forme à l'aide de ces deux instruments (les fonctions de dessin de
     * formes et de textes).
     * \ingroup Drawing
     */
    /*!\defgroup DrawingBitmap Fonctionnalités de dessin de pixels et d'images
     * \brief Contient toutes les fonctionnalités pour dessiner pixels et des images
     *
     * Ces fonctions permettent de dessiner des pixels et des images dans la fenêtre graphique.
     * \ingroup Drawing
     */
#if LIBGRAPH2_LEVEL>=3
    /*!\defgroup DrawingText Fonctionnalités d'affichage de texte
     * \brief Contient toutes les fonctionnalités afficher du texte
     *
     * Ces fonctions permettent d'afficher du texte dans la fenêtre graphique. La police peut être choisie 
     * parmi toutes les polices installées dans le système d'exploitation. Le texte est affiché en utilisant
     * le pinceau, il peut donc être texturé.
     * \image html text-texture.png "Exemple de texte texturé"
     * \ingroup Drawing
     */
#endif

//!\defgroup WndMgmt Gestion des fenêtres
  /*!\defgroup EventManagement Gestion des événements
   * \brief Contient toutes les fonctionnalités de gestion des événements systèmes
   * 
   * Ces fonctions permettent de gérer les événements systèmes sur une fenêtre graphique
   * \ingroup WndMgmt
   */
  /*!\defgroup WndManagement Gestion des fenêtres graphiques
   * \brief Contient toutes les fonctionnalités de gestion des fenêtres graphiques
   *
   * Ces fonctions permettent de manipuler la fenêtre graphique.
   * \ingroup WndMgmt
   */
  /*!\defgroup ConManagement Gestion de la console
   * \brief Contient toutes les fonctionnalités de gestion de la console
   *
   * Ces fonctions permettent de manipuler la console.
   * \ingroup WndMgmt
   */
#if LIBGRAPH2_LEVEL>=1
  /*!\defgroup DialogManagement Boîtes de dialogues
   * \brief Contient toutes les fonctionnalités de gestion des boîtes de dialogues
   *
   * Ces fonctions permettent d'afficher des boîtes de dialogues afin d'interagir avec l'utilisateur de façon ergonomique.
   * \ingroup WndMgmt
   */
#endif
#if LIBGRAPH2_LEVEL>=3
/*!\defgroup Tools Fonctionnalités utilitaires
 * \brief Contient des classes et fonctions rendant la vie plus facile
 */
#endif

/*!
 * \brief
 * Espace de nommage de LibGraph 2.
 */
namespace LibGraph2
{
  /*!
   * \brief 
   * Type de variable pour les couleurs.
   * 
   * Ce type de données permet de stocker une couleur selon le mode RVB avec
   * gestion de la transparence. 
   * Utilisez la fonction MakeARGB() pour créer des couleurs.
   * 
   * \remarks
   * Il s'agit d'un entier non signé sur 32 bits (unsigned long).
   * 
   * \see
   * Section : \ref DrawingProperties \n
   * Fonctions : MakeARGB(), GetA(), GetR(), GetG(), GetB()
   * \ingroup DrawingProperties
   */
  typedef DWORD ARGB;

  /*!
   * \brief
   * Type d'événement.
   * \see
   * Section : \ref EventManagement
   * \ingroup EventManagement
   */
  enum evt_type {
    //!\brief Enfoncement du bouton de la souris
    evtMouseDown,
    //!\brief Relachement du bouton de la souris
    evtMouseUp,
    //!\brief Déplacement de la souris
    evtMouseMove,
    //!\brief Enfoncement d'une touche du clavier
    evtKeyDown,
    //!\brief Relachement d'une touche du clavier
    evtKeyUp,
    //!\brief Raffraichissement de toute la fenêtre
    evtRefresh,
    //!\brief Modification de la taille de la fenêtre
    evtSize,
    //!\brief Fermeture de la fenêtre
    evtClose,
  };

  /*!
   * \brief
   * Style de trait.
   * \see
   * Section : \ref DrawingProperties
   * \ingroup DrawingProperties
   */
  enum pen_DashStyles {
    //!\brief Trait plein
    Solid,
    //!\brief Pointillés : tiret
    Dash,
    //!\brief Pointillés : point
    Dot,
    //!\brief Pointillés : tiret point
    DashDot,
    //!\brief Pointillés : tiret point point
    DashDotDot
  };

  /*!
   * \brief
   * Epaisseur de la police.
   * \see
   * Section : \ref DrawingProperties
   * \ingroup DrawingProperties
   */
  enum font_styles {
    //!\brief Normal
    FontStyleRegular      = 0,
    //!\brief Gras
    FontStyleBold         = 1,
    //!\brief Italique
    FontStyleItalic       = 2,
    //!\brief Gras Italique
    FontStyleBoldItalic   = 3
  };

#if LIBGRAPH2_LEVEL>=1
  /*!
   * \brief
   * Types de boutons.
   * \see
   * Section : \ref DialogManagement
   * \ingroup DialogManagement
   */
  enum msgbtn_types {
    //!\brief Boutons "Abandonner Recommencer Ignorer" \image html btn-abort-retry-ignore.png
    MsgBtnAbortRetryIgnore     = 0x2L,
    //!\brief Boutons "Annuler Réessayer Continuer" \image html btn-cancel-try-continue.png
    MsgBtnCancelTryContinue  = 0x6L,
    //!\brief Bouton "Ok" \image html btn-ok.png
    MsgBtnOK                   = 0x0L,
    //!\brief Boutons "Ok Annuler" \image html btn-ok-cancel.png
    MsgBtnOKCancel             = 0x1L,
    //!\brief Boutons "Recommencer Annuler" \image html btn-retry-cancel.png
    MsgBtnRetryCancel          = 0x5L,
    //!\brief Boutons "Oui Non" \image html btn-yes-no.png
    MsgBtnYesNo                = 0x4L,
    //!\brief Boutons "Oui Non Annuler" \image html btn-yes-no-cancel.png
    MsgBtnYesNoCancel          = 0x3L
  };

  /*!
   * \brief
   * Types d'icones.
   * \see
   * Section : \ref DialogManagement
   * \ingroup DialogManagement
   */
  enum msgicon_types {
    //!\brief Aucune icone \image html icn-none.png
    MsgIcnNone        = 0x00L,
    //!\brief Icone STOP \image html icn-stop.png
    MsgIcnStop        = 0x10L,
    //!\brief Icone QUESTION \image html icn-question.png
    MsgIcnQuestion    = 0x20L,
    //!\brief Icone EXCLAMATION \image html icn-exclamation.png
    MsgIcnExclamation = 0x30L,
    //!\brief Icone INFORMATION \image html icn-information.png
    MsgIcnInformation = 0x40L
  };

  /*!
   * \brief
   * Choix du bouton par défaut.
   * \see
   * Section : \ref DialogManagement
   * \ingroup DialogManagement
   */
  enum msgdefbtn_vals {
    //!\brief Premier bouton
    MsgDefBtn1 = 0x000L,
    //!\brief Deuxième bouton
    MsgDefBtn2 = 0x100L,
    //!\brief Troisième bouton
    MsgDefBtn3 = 0x200L,
    //!\brief Quatrième bouton
    MsgDefBtn4 = 0x300L
  };

  /*!
   * \brief
   * Réponse d'une boîte de dialogue.
   * \see
   * Section : \ref DialogManagement
   * \ingroup DialogManagement
   */
  enum msgbtn_answer{
    //!\brief La boîte de dialogue n'a pas pu s'afficher
    MsgAnsError     = 0,
    //!\brief L'utilisateur a cliqué sur le bouton "Ok"
    MsgAnsOk        = 1,
    //!\brief L'utilisateur a cliqué sur le bouton "Annuler"
    MsgAnsCancel    = 2,
    //!\brief L'utilisateur a cliqué sur le bouton "Abandonner"
    MsgAnsAbort     = 3,
    //!\brief L'utilisateur a cliqué sur le bouton "Recommencer"
    MsgAnsRetry     = 4,
    //!\brief L'utilisateur a cliqué sur le bouton "Ignorer"
    MsgAnsIgnore    = 5,
    //!\brief L'utilisateur a cliqué sur le bouton "Oui"
    MsgAnsYes       = 6,
    //!\brief L'utilisateur a cliqué sur le bouton "Non"
    MsgAnsNo        = 7,
    //!\brief L'utilisateur a cliqué sur le bouton "Réessayer"
    MsgAnsTryagain  = 10,
    //!\brief L'utilisateur a cliqué sur le bouton "Continuer"
    MsgAnsContinue  = 11
  };
#endif

#if LIBGRAPH2_LEVEL >= 3 || defined(LIBGRAPH2_EXPORTS)
  /*!
   * \brief
   * Structure représentant un événement.
   * 
   * Cette structure est utilisée par la fonction ILibGraph2_Com::waitForEvent() 
   * pour récupérer les informations sur le dernier événement.
   * 
   * \see
   * Section : \ref EventManagement \n
   * Fonction : ILibGraph2_Com::waitForEvent()
   * \ingroup EventManagement
   */
  struct evt{
    //!\brief Type de l'événement
    evt_type type;
    //!\brief Position x de la souris, valide uniquement si événement de type souris
    unsigned int x;
    //!\brief Position y de la souris, valide uniquement si événement de type souris
    unsigned int y;
    /*!\brief Code de touche clavier, valide uniquement si événement de type clavier
     *
     * Pour les touches Alphanumériques, le code de touche correspond au code du caractère
     * majuscule de la touche. Par exemple, la touche "a" correspond au code 'A'.\n
     * Pour les touches spéciales (Majuscule, Control, Echap, etc...), le code de touche corresponds
     * aux valeurs de touches virtuelles du SDK de Windows. Se référer à l'aide en ligne de
     * MSDN pour le listing de ces valeurs : http://msdn.microsoft.com/en-us/library/dd375731.aspx
     */
    unsigned int vkKeyCode;
  };

  /*!
   * \brief
   * Classe utilitaire de gestion des chaines de caractères.
   * 
   * L'utilisation de cette classe est transparente car elle comporte les fonctions de convertion
   * depuis et vers les chaines de caratères de type char* ou wchar*.\n
   * Son utilité principale est de rendre transparent les problèmes de conversion Unicode.
   * 
   * \remarks
   * Les fonctions nécessitant des CString en entrée peuvent donc accepter automatiquement des 
   * chaines de caractères de type char* ou wchar*.
   *
   * \see
   * Section : \ref Tools
   * \ingroup Tools
   */
  class CString 
  {
  private:
    std::wstring m_str;
    void ConvertFromChar(const char* pCharText)
    {
      auto nCharLen = strlen(pCharText);
      auto nLen = std::mbstowcs(NULL, pCharText, nCharLen+1);
      wchar_t* pText = new wchar_t[nLen+1];
      std::mbstowcs(pText, pCharText, nCharLen+1);
      m_str = pText;
      delete[] pText;
    }
  public:
    /*!
     * \brief
     * Constructeur par défaut.
     * 
     * Initialise la chaîne de caractères à une chaîne vide.
     * 
     * \see
     * Classe : CString
     */
    CString(){}
    /*!
     * \brief
     * Constructeur depuis une chaine de caractères STL Unicode.
     * 
     * Initialise la chaîne de caractères par copie de la chaîne de caractères STL Unicode.
     * 
     * \param [in] str Chaine de caractères à copier
     *
     * \see
     * Classe : CString
     */
    CString(const std::wstring& str) : m_str(str){}
    /*!
     * \brief
     * Constructeur depuis une chaine de caractères STL ANSI.
     * 
     * Initialise la chaîne de caractères par conversion de la chaîne de caractères STL ANSI.
     * 
     * \param [in] str Chaine de caractères à copier
     *
     * \see
     * Classe : CString
     */
    CString(const std::string& str) {ConvertFromChar(str.c_str());}
    /*!
     * \brief
     * Constructeur depuis une chaine de caractères Unicode.
     * 
     * Initialise la chaîne de caractères par copie de la chaîne de caractères Unicode.
     * 
     * \param [in] str Chaine de caractères à copier
     *
     * \see
     * Classe : CString
     */
    CString(const wchar_t* str) : m_str(str){}
    /*!
     * \brief
     * Constructeur depuis une chaine de caractères ANSI.
     * 
     * Initialise la chaîne de caractères par conversion de la chaîne de caractères ANSI.
     * 
     * \param [in] str Chaine de caractères à copier
     *
     * \see
     * Classe : CString
     */
    CString(const char* str) {ConvertFromChar(str);}
    /*!
     * \brief
     * Operateur de conversion en chaîne de caractères STL Unicode.
     * 
     * \returns
     * Une copie de la chaîne de caractère STL Unicode.
     *
     * Cet opérateur convertit la chaîne CString en une chaine std::wstring. Cela permet d'utiliser 
     * la classe CString en lieu et place d'une chaine std::wstring, pour un accès en lecture.
     * 
     * \see
     * Classe : CString
     */
    operator std::wstring() const {return m_str;}
    /*!
     * \brief
     * Operateur de conversion en chaîne de caractères STL Unicode (par référence).
     * 
     * \returns
     * Une référence vers la chaîne de caractère STL Unicode.
     *
     * Cet opérateur convertit la chaîne CString en une chaine std::wstring. Cela permet d'utiliser 
     * la classe CString en lieu et place d'une chaine std::wstring, pour un accès en lecture / écriture.
     * 
     * \see
     * Classe : CString
     */
    operator std::wstring&() {return m_str;}
    /*!
     * \brief
     * Opérateur de déréférencement.
     * 
     * \returns
     * Déréférence l'objet CString comme un objet STL wstring (inclus en lui). Permet de rendre 
     * transparent l'objet CString de façon à être utilisé comme un wstring.
     *
     * \see
     * Classe : CString
     */
    std::wstring *operator->() {return &m_str;}
    /*!
     * \brief
     * Opérateur de déréférencement.
     * 
     * \returns
     * Déréférence l'objet CString comme un objet STL wstring (inclus en lui). Permet de rendre 
     * transparent l'objet CString de façon à être utilisé comme un wstring.
     *
     * \see
     * Classe : CString
     */
    const std::wstring *operator->()const {return &m_str;}
  };

  /*!
   * \brief
   * Classe utilitaire de gestion d'un point.
   * 
   * Regroupe en une seule entité les 2 coordonnées d'un point.
   * 
   * \see
   * Section : \ref Tools
   * \ingroup Tools
   */
  class CPoint
  {
  public:
    /*!
     * \brief
     * Constructeur.
     * 
     * \param [in] x Abscisse
     * \param [in] y Ordonnée
     * 
     * Constructeur
     * 
     * \see
     * Classe : CPoint
     */
    explicit CPoint(float x=0, float y=0):m_fX(x), m_fY(y){}
    /*!\brief Abscisse
     * \see Classe : CPoint
     */
    float m_fX;
    /*!\brief Ordonnée
     * \see Classe : CPoint
     */
    float m_fY;

    /*!
     * \brief
     * Déplacement du point.
     * 
     * \param [in] p Point contenant les coordonnées du vecteur de déplacement.
     * 
     * \returns Une référence vers l'objet courant.
     *
     * \see Classe : CPoint
     */
    CPoint& operator+=(const CPoint& p) {m_fX += p.m_fX; m_fY += p.m_fY; return *this;}

    /*!
     * \brief
     * Calcule la position du point déplacé.
     * 
     * \param [in] p Point contenant les coordonnées du vecteur de déplacement.
     * 
     * \returns Le point contenant les nouvelles coordonnées.
     *
     * \see Classe : CPoint
     */
    CPoint operator+(const CPoint& p) const {return CPoint(*this)+=p;}
  };

  /*!
   * \brief
   * Classe utilitaire de gestion d'une taille.
   * 
   * Regroupe en une seule entité les 2 coordonnées d'une taille (largeur et hauteur).
   * 
   * \see
   * Section : \ref Tools
   * \ingroup Tools
   */
  class CSize
  {
  public:
    /*!
     * \brief
     * Constructeur.
     * 
     * \param [in] width  Largeur
     * \param [in] height Hauteur
     * 
     * Constructeur.
     * 
     * \see
     * Classe : CSize
     */
    explicit CSize(float width=0, float height=0):m_fWidth(width), m_fHeight(height){}
    /*!\brief Largeur
     * \see Classe : CSize
     */
    float m_fWidth;
    /*!\brief Hauteur
     * \see Classe : CSize
     */
    float m_fHeight;
  };

  /*!
   * \brief
   * Classe utilitaire de gestion d'un rectangle.
   * 
   * Regroupe en une seule entité le coin supérieur gauche du rectangle ainsi que sa taille.
   * 
   * \see
   * Classes : CPoint, CSize \n
   * Section : \ref Tools
   * \ingroup Tools
   */
  class CRectangle
  {
  public:
    /*!
     * \brief
     * Constructeur.
     * 
     * \param [in] ptTopLeft Coin supérieur gauche du rectangle
     * \param [in] szSize    Taille du rectangle
     * 
     * Constructeur.
     * 
     * \see
     * Classes : CPoint, CSize, CRectangle
     */
    CRectangle(const CPoint& ptTopLeft = CPoint(), const CSize& szSize = CSize()):m_ptTopLeft(ptTopLeft),m_szSize(szSize){}
    /*!\brief Coin supérieur gauche du rectangle.
     * \see Classes : CPoint, CRectangle
     */
    CPoint m_ptTopLeft;
    /*!\brief Taille du rectangle.
     * \see Classes : CSize, CRectangle
     */
    CSize m_szSize;
  };

//Redéfinition de la classe pour le niveau Avancé
#if LIBGRAPH2_LEVEL == 3
/*!
 * \class LibGraph2::ILibGraph2 LibGraph2.h "LibGraph2.h"
 * \brief
 * Classe principale de LibGraph 2.
 *
 * Cette classe regroupe toutes les fonctionnalités communes d'une fenêtre graphique LibGraph 2. Elle est un alias de la classe
 * ILibGraph2_Adv et permet de résoudre les problèmes de portabilité entre les niveaux Avancé et Expert.
 *
 * \see
 * Classe : ILibGraph2_Adv
 */
#define ILibGraph2 ILibGraph2_Adv
#else
//Redéfinition de la classe pour le niveau Expert
/*!
 * \class LibGraph2::ILibGraph2 LibGraph2.h "LibGraph2.h"
 * \brief
 * Classe principale de LibGraph 2.
 *
 * Cette classe regroupe toutes les fonctionnalités communes d'une fenêtre graphique LibGraph 2. Elle est un alias de la classe
 * ILibGraph2_Exp et permet de résoudre les problèmes de portabilité entre les niveaux Avancé et Expert.
 *
 * \see
 * Classe : ILibGraph2_Exp
 */
#define ILibGraph2 ILibGraph2_Exp
#endif

  /*!
   * \brief
   * Classe principale de LibGraph 2 pour les niveaux Avancé et Expert.
   * 
   * Cette classe regroupe toutes les fonctionnalités communes aux niveaux Avancé et Expert d'une fenêtre graphique LibGraph 2.
   * 
   * \remarks
   * Cette classe ne peut être utilisée directement. Vous devez utiliser à la place la classe ILibGraph2, qui est un alias 
   * vers la classe correspondate au niveau requis (\if NIVEAU3 ILibGraph2_Adv\endif \if NIVEAU4 ILibGraph2_Exp\endif )
   * 
   * \see
   * Classes : ILibGraph2, \if NIVEAU3 ILibGraph2_Adv\endif \if NIVEAU4 ILibGraph2_Exp\endif
   */
  class ILibGraph2_Com
  {
  public:
    /*!
     * \brief Affiche la fenêtre graphique.
     * 
     * Affiche la fenêtre graphique correspondante à cet objet. La fenêtre peut être affichée en plein écran. Pour quitter 
     * le mode plein écran, il suffit d'appuyer sur la touche "échap".
     *
     * \param [in] szWndSize (optionnel) Définit la taille de la fenêtre.\n
     * Si la taille de la fenêtre est défini (c'est-à-dire autre que 0,0), alors la fenêtre est initialement affichée avec 
     * son espace intérieur de la taille spécifiée. Son système de coordonnées est alors celui spécifié par sa taille. 
     * La fenêtre est librement redimensionable par l'utilisateur, mais dans ce cas, le système de coordonnées reste fixé à
     * celui de départ, ayant pour conséquence de réduire ou agrandir l'image tracée. \n
     * Dans le cas où la taille de la fenêtre n'est pas spécifiée, alors la fenêtre est affichée avec une taille par défaut
     * et le système de coordonnées est directement appliqué sur les pixels. Ainsi, agrandir ou réduire la fenêtre n'aura 
     * pour conséquence que d'agrandir ou de réduire l'espace de travail.
     * \param [in] bFullScreen (optionnel) Affiche la fenêtre en plein écran.\n
     * Si le paramètre vaut \c false (par défaut) alors la fenêtre est affichée à la taille spécifié par le paramètre \c szWndSize.\n
     * Si le paramètre vaut \c true alors la fenêtre est affichée en plein écran. L'appuie sur la touche "Echap" permet de quitter 
     * le mode plein écran.
     *
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Membres : hide(), getSize()
     * \ingroup WndManagement
     */
    virtual void show(const CSize& szWndSize = CSize(), bool bFullScreen=false) =0;
    /*!
     * \brief Masque la fenêtre graphique.
     * 
     * Masque la fenêtre graphique correspondante à cet objet. La fenêtre n'est pas détruite, elle est seulement rendue 
     * invisible. Elle peut être réaffichée en appelant la fonction show().
     *
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Membres : show(), getSize()
     * \ingroup WndManagement
     */
    virtual void hide() =0;
    /*!
     * \brief Récupère la taille de la fenêtre.
     * 
     * Retourne la taille de la fenêtre. Si la fenêtre a été affichée avec un système de coordonnées spécifique (paramètre 
     * \c szWndSize de la fonction show() défini) alors, la taille retournée est toujours la taille spécifiée lors de 
     * l'affichage de la fenêtre. Sinon, il s'agit de la taille de la zone graphique de la fenêtre en pixel.
     *
     * \returns Objet de type CSize contenant la taille de la fenêtre.
     *
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Membres : show(), hide()
     * \ingroup WndManagement
     */
    virtual CSize getSize() =0;

    /*!
     * \brief Affiche la console.
     * 
     * Affiche la console et l'active. Le focus de l'utilisateur est lors placé sur la console. Afin d'écrire ou lire 
     * dans la console, vous pouvez utiliser les objets STL cout et cin, comme pour n'importe quel programme. 
     *
     * \remark Lors de la lecture à l'aide de cin, vous devez appeler la fonction std::cin.clear() 
     * avant de pouvoir accéder au flux en lecture.
     *
     * \remark Cette fonction est automatiquement appelée lorsque les objets std::cout ou std::cin sont utilisés pour 
     * accéder aux flux standards.
     *
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Membres : hideConsole()
     * \ingroup ConManagement
     */
    virtual void showConsole() =0;
    /*!
     * \brief Masque la console.
     * 
     * Masque la console.
     * 
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Membres : showConsole()
     * \ingroup ConManagement
     */
    virtual void hideConsole() =0;

    /*!
     * \brief Demande à rafraichir la fenêtre.
     * 
     * Demande à rafraichir la fenêtre. L'événement evtRefresh sera envoyé dès que possible après l'appel de cette fonction.
     * 
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Membres : waitForEvent()
     * \ingroup EventManagement
     */
    virtual void askForRefresh() =0;
    /*!
     * \brief Met le programme en pause jusqu'au prochain événement.
     * 
     * Met le programme en pause jusqu'au prochain événement. Lorsqu'un événement se produit,
     * il est alors retournée dans le paramètre \c e. Cette fonction permet de mettre en place 
     * la boucle d'événement du programme principal selon le code suivant :
     * \code
     *   //Récupération de l'objet principal de LibGraph 2
     *   ILibGraph2* libgraph = GetLibGraph2();
     *   //Affiche la fenêtre graphique avec une taille par défaut
     *   libgraph->show();
     *   evt e;  //Evénement LibGraph 2
     *
     *   //Boucle principale d'événements
     *   while(libgraph->waitForEvent(e))
     *   {
     *     switch(e.type)  //En fonction du type d'événement
     *     {
     *       //Clauses "case" pour traiter les événements
     *     }
     *   }
     * \endcode
     * 
     *
     * \param [out] e Structure événement contenant les informations sur l'événement reçu.
     *
     * \return \c false si la fenêtre a été fermée, \c true dans tous les autres cas.
     * 
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Structure : evt
     * \ingroup EventManagement
     */
    virtual bool waitForEvent(evt& e) =0;

    /*!
     * \brief Active le backbuffer.
     * 
     * L'appel de cette fonction permet d'activer le backbuffer. A partir de cet appel, les fonctions de dessins ne 
     * s'exécuteront plus directement sur la fenêtre mais dans une mémoire tampon (le backbuffer) de même taille que 
     * la fenêtre. L'affichage dans la fenetre sera ensuite réalisé lors de l'appel de la fonction endPaint() qui 
     * copie le contenu du backbuffer dans la fenêtre. Si la fonction endPaint() n'est pas appelée en fin de dessin, 
     * alors rien ne sera affiché à l'écran.\n
     * Le code suivant est un exemple d'affichage utilisant la technique du backbuffer :
     *
     * \code
     *   //Récupération de l'objet principal de LibGraph 2
     *   ILibGraph2* libgraph = GetLibGraph2();
     *   //Affiche la fenêtre graphique avec une taille par défaut
     *   libgraph->show();
     *   evt e;  //Evénement LibGraph 2
     *
     *   //Boucle principale d'événements
     *   while(libgraph->waitForEvent(e))
     *   {
     *     switch(e.type)  //En fonction du type d'événement
     *     {
     *     case evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
     *       libgraph->beginPaint(); //Active le backbuffer
     *         //Utiliser ici les fonctions de dessins
     *       libgraph->endPaint();   //Recopie le contenu du backbuffer dans la fenêtre
     *       break;
     *     //autres événements
     *     }
     *   }
     * \endcode
     * \remark Il est très avantageux d'utiliser cette fonctionnalité qui accélère énormément l'affichage et évite 
     * les effets de scintillement qui peuvent provenir lors d'un affichage direct à l'écran.
     * 
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Membres : endPaint()
     * \ingroup DrawingManagement
     */
    virtual void beginPaint() =0;
    /*!
     * \brief Recopie le contenu du backbuffer dans la fenêtre graphique.
     * 
     * Recopie le contenu du backbuffer dans la fenêtre graphique. Si la fonction beginPaint() n'a pas été appelée 
     * préalablement, la fonction endPaint() n'a aucun effet.
     *
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Membres : beginPaint()
     * \ingroup DrawingManagement
     */
    virtual void endPaint() =0;

    /*!
     * \brief Définit le style du crayon.
     * 
     * Permet de définir la couleur, l'épaisseur et le style du trait qui sera utilisé par les fonctions de dessin.
     *
     * \param [in] color Code couleur du crayon
     * \param [in] fWidth Epaisseur du crayon
     * \param [in] style (optionnel) Style du trait. Trait plein par défaut.
     *
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Types de données : ARGB, pen_DashStyles \n
     * Fonctions utilitaires : MakeARGB(), GetA(), GetR(), GetG(), GetB()
     * \ingroup DrawingProperties
     */
    virtual void setPen(ARGB color, float fWidth, pen_DashStyles style =Solid) =0;
    /*!
     * \brief Définit le style du pinceau par une couleur pleine.
     * 
     * Permet de définir la couleur de remplissage des formes fermées.
     *
     * \param [in] color Code couleur du crayon
     *
     * \see
     * Classe : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Types de données : ARGB \n
     * Fonctions utilitaires : MakeARGB(), GetA(), GetR(), GetG(), GetB()
     * \ingroup DrawingProperties
     */
    virtual void setSolidBrush(ARGB color) =0;
    /*!
     * \brief Définit le style du pinceau par une texture.
     * 
     * Permet de définir le remplissage des formes fermées à l'aide d'une texture.
     * \image html texture.jpg "Image de texture"
     * \image html texture2.png "Forme remplie à l'aide de la texture"
     *
     * \param [in] sFileName Nom du fichier image utilisé pour la texture.
     *
     * \see
     * Classe : CString, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif
     * \ingroup DrawingProperties
     */
    virtual void setTextureBrush(const CString& sFileName) =0;
    /*!
     * \brief Définit la police de caractère pour l'affichage de texte.
     * 
     * Définit la police de caractère pour l'affichage de texte.
     * \image html fonts.png "Exemples de polices utilisées par LibGraph 2, à différentes tailles"
     *
     * \param [in] strFontName  Nom de la police de caractères à utiliser
     * \param [in] fPointSize   Taille en points de la police
     * \param [in] nStyleFlags  Style de la police
     *
     * \see
     * Classes : CString, font_styles, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Fonctions d'affichage de texte : drawString(), getStringDimension()
     * \ingroup DrawingProperties
     */
    virtual void setFont(const CString& strFontName, float fPointSize, font_styles nStyleFlags)=0;

    /*!
     * \brief Dessine une ellipse.
     * 
     * Une ellipse est définie par son rectangle englobant.
     * \image html ellipse.png "Ellipse"
     *
     * \param [in] rectBounds Rectangle englobant de l'ellipse
     *
     * \see
     * Classes : CRectangle, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Fonctions de dessin : setPen(), setSolidBrush(), setTextureBrush()
     * \ingroup DrawingShapes
     */
    virtual void drawEllipse(const CRectangle& rectBounds)=0;
    /*!
     * \brief Dessine un arc d'ellipse.
     * 
     * Un arc d'ellipse est défini par son rectangle englobant, son angle de départ et son angle de balayage.
     * \image html arc.png "Arc d'ellipse"
     *
     * \param [in] rectBounds Rectangle englobant de l'ellipse
     * \param [in] startAngle Angle de départ de l'arc (en degrés)
     * \param [in] sweepAngle Angle de balayage de l'arc (en degrés)
     *
     * \see
     * Classes : CRectangle, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Fonction de dessin : setPen()
     * \ingroup DrawingShapes
     */
    virtual void drawArc(const CRectangle& rectBounds, float startAngle, float sweepAngle) =0;
    /*!
     * \brief Dessine une portion de camembert.
     * 
     * Une portion de camembert est définie par son rectangle englobant, son angle de départ et son angle de balayage.
     * \image html pie.png "Portion de camembert"
     *
     * \param [in] rectBounds Rectangle englobant de l'ellipse
     * \param [in] startAngle Angle de départ de l'arc (en degrés)
     * \param [in] sweepAngle Angle de balayage de l'arc (en degrés)
     *
     * \see
     * Classes : CRectangle, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Fonctions de dessin : setPen(), setSolidBrush(), setTextureBrush()
     * \ingroup DrawingShapes
     */
    virtual void drawPie(const CRectangle& rectBounds, float startAngle, float sweepAngle) =0;
    /*!
     * \brief Dessine un segment.
     * 
     * Un segment est défini par ses deux points extrémités.
     * \image html line.png "Segment de droite"
     *
     * \param [in] ptP1 Extrémité de départ
     * \param [in] ptP2 Extrémité d'arrivée
     *
     * \see
     * Classes : CPoint, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Fonction de dessin : setPen()
     * \ingroup DrawingShapes
     */
    virtual void drawLine(const CPoint& ptP1, const CPoint& ptP2) =0;
    /*!
     * \brief Dessine un rectangle.
     * 
     * Dessine un rectangle.
     * \image html rectangle.png "Rectangle"
     *
     * \param [in] rectBounds Rectangle
     *
     * \see
     * Classes : CRectangle, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Fonctions de dessin : setPen(), setSolidBrush(), setTextureBrush()
     * \ingroup DrawingShapes
     */
    virtual void drawRectangle(const CRectangle& rectBounds)=0;

    /*!
     * \brief Définit la couleur d'un pixel.
     * 
     * Définit la couleur d'un pixel.
     * \image html pixels.png "Dégradé de couleur généré pixel par pixel"
     *
     * \param [in] ptPos Position du pixel à définir
     * \param [in] color Code couleur du pixel
     *
     * \see
     * Classes : CPoint, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Types de données : ARGB \n
     * Fonctions utilitaires : MakeARGB(), GetA(), GetR(), GetG(), GetB()
     * \ingroup DrawingBitmap
     */
    virtual void setPixel(const CPoint& ptPos, ARGB color)=0;
    /*!
     * \brief Dessine une image bitmap.
     * 
     * Dessine une image bitmap chargée depuis un fichier. Les formats supportés sont JPEG, BMP, PNG,
     * GIF, TIFF et ICO. L'image peut être agrandie ou réduite, et tournée par rapport à son centre ou 
     * son coin supérieur gauche.
     * \image html bitmap.png "Image bitmap dessinée par LibGraph 2"
     *
     * \param [in] sFileName    Nom du fichier image à afficher
     * \param [in] ptPos        Position de l'image. Se réfère au coin supérieur gauche si \c bXYIsCenter 
     *                          vaut false, sinon se réfère au centre de l'image
     * \param [in] dScaleFactor (optionnel) Facteur d'échelle d'affichage de l'image. (1.0 par défaut)
     * \param [in] dAngleDeg    (optionnel) Angle de rotation de l'image en degrés. (0.0 par défaut)
     * \param [in] bXYIsCenter  (optionnel) Spécifie si la position et la rotation se réfèrent au coin 
     *                          supérieur gauche (\c false) ou au centre de l'image (\c true). (\c false 
     *                          par défaut)
     *
     * \see
     * Classes : CString, CPoint, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif
     * \ingroup DrawingBitmap
     */
    virtual void drawBitmap(const CString& sFileName, const CPoint& ptPos, double dScaleFactor = 1.0, double dAngleDeg=0, bool bXYIsCenter=false)=0;
    /*!
     * \brief Dessine une image bitmap.
     * 
     * Dessine une image bitmap chargée depuis un fichier. Les formats supportés sont JPEG, BMP, PNG,
     * GIF, TIFF et ICO. L'image peut être agrandie ou réduite, et tournée. Le point de
     * pivot et d'accroche de l'image peut être défini à la position voulue.
     * \image html bitmap.png "Image bitmap dessinée par LibGraph 2"
     *
     * \param [in] sFileName    Nom du fichier image à afficher
     * \param [in] ptPos        Position de l'image. Se réfère au point de pivot spécifié par \c ptPosPivot
     * \param [in] ptPosPivot   Position du point de pivot dans l'image, le référentiel de coordonnées est 
     *                          le coin supérieur gauche de l'image.
     * \param [in] dScaleFactor Facteur d'échelle d'affichage de l'image.
     * \param [in] dAngleDeg    Angle de rotation de l'image en degrés.
     *
     * \see
     * Classes : CString, CPoint, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif
     * \ingroup DrawingBitmap
     */
    virtual void drawBitmap(const CString& sFileName, const CPoint& ptPos, const CPoint& ptPosPivot, double dScaleFactor, double dAngleDeg) =0;

    /*!
     * \brief Affiche une chaîne de caractères.
     * 
     * Affiche une chaîne de caractère avec la police définie lors du dernier appel de la fonction setFont()
     * en utilisant le pinceau courant.
     * \image html text-texture.png "Exemple de texte texturé"
     * \image html fonts.png "Exemples de polices utilisées par LibGraph 2, à différentes tailles"
     *
     * \param [in] text  Texte à afficher
     * \param [in] ptPos Position du texte. Peut-être affiné grace à la fonction getStringDimension()
     *
     * \see
     * Classes : CString, CPoint, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Fonctions d'affichage de texte : setFont(), getStringDimension() \n
     * Fonctions de dessin : setSolidBrush(), setTextureBrush()
     * \ingroup DrawingText
     */
    virtual void drawString(const CString& text, const CPoint& ptPos)=0;
    /*!
     * \brief Calcule la dimension affichée d'une chaîne de caractères.
     * 
     * Calcule la dimension affichée d'une chaîne de caractères. La dimension est calculée en utilisant
     * la police de caractère courrante.
     *
     * \param [in]  text       Texte à mesurer.
     * \param [in]  ptPos      Position du texte dans la fenêtre graphique.
     * \param [out] rectBounds Rectangle englobant calculé.
     *
     * \see
     * Classes : CString, CPoint, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Fonctions d'affichage de texte : setFont(), drawString()
     * \ingroup DrawingText
     */
    virtual void getStringDimension(const CString& text, const CPoint& ptPos, CRectangle& rectBounds)=0;

    /*!
     * \brief Affiche la boîte de dialogue de sélection de couleur.
     * 
     * Affiche la boîte de dialogue de sélection de couleur.
     * \image html dlg-color.png "Boîte de dialogue de sélection d'une couleur"
     *
     * \param [in, out]  color En entrée, couleur à définir dans la boîte de dialogue. En sortie, couleur 
     *                         sélectionnée dans la boîte de dialogue si l'utilisateur clique sur Ok.
     *
     * \return \c true si l'utilisateur a cliqué sur le bouton Ok, \c false sinon.
     *
     * \see
     * Classes : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Types de données : ARGB \n
     * Fonctions utilitaires : MakeARGB(), GetA(), GetR(), GetG(), GetB()
     * \ingroup DialogManagement
     */
    virtual bool guiGetColor(ARGB& color)=0;
    /*!
     * \brief Affiche la boîte de dialogue de sélection des attributs de traits.
     * 
     * Affiche la boîte de dialogue de sélection des attributs de traits, permettant de choisir la couleur, 
     * l'épaisseur et le style d'un trait.
     * \image html dlg-pen.png "Boîte de dialogue de sélection des attributs de traits"
     *
     * \param [in, out]  color  En entrée, couleur à définir dans la boîte de dialogue. En sortie, couleur 
     *                          sélectionnée dans la boîte de dialogue si l'utilisateur clique sur Ok.
     * \param [in, out]  fWidth En entrée, épaisseur de trait à définir dans la boîte de dialogue. En sortie,  
     *                          épaisseur choisie si l'utilisateur clique sur Ok.
     * \param [in, out]  style  En entrée, style de trait à définir dans la boîte de dialogue. En sortie,  
     *                          style choisi si l'utilisateur clique sur Ok.
     *
     * \return \c true si l'utilisateur a cliqué sur le bouton Ok, \c false sinon.
     *
     * \see
     * Classes : \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Types de données : ARGB, pen_DashStyles \n
     * Fonctions utilitaires : MakeARGB(), GetA(), GetR(), GetG(), GetB()
     * \ingroup DialogManagement
     */
    virtual bool guiGetPenStyle(ARGB& color, float& fWidth, pen_DashStyles& style)=0;
    /*!
     * \brief Affiche la boîte de dialogue d'entrée d'une valeur.
     * 
     * Affiche la boîte de dialogue d'entrée d'une valeur pour la saisie d'une valeur entière. 
     * \image html dlg-value.png "Boîte de dialogue de saisie d'une valeur"
     *
     * \param [in, out] nVal     En entrée, valeur à définir dans la boîte de dialogue. En sortie, valeur 
     *                           entrée dans la boîte de dialogue si l'utilisateur clique sur Ok.
     * \param [in]      strTitle Texte à afficher dans le bandeau de titre de la boîte de dialogue.
     * \param [in]      strLabel Texte à afficher pour inviter l'utilisateur à entrer une valeur.
     *
     * \return \c true si l'utilisateur a cliqué sur le bouton Ok, \c false sinon.
     *
     * \see
     * Classes : CString, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif
     * \ingroup DialogManagement
     */
    virtual bool guiGetValue(int& nVal, const CString& strTitle=L"", const CString& strLabel=L"")=0;
    /*!
     * \brief Affiche la boîte de dialogue d'entrée d'une valeur.
     * 
     * Affiche la boîte de dialogue d'entrée d'une valeur pour la saisie d'une valeur décimale. 
     * \image html dlg-value.png "Boîte de dialogue de saisie d'une valeur"
     *
     * \param [in, out] dVal     En entrée, valeur à définir dans la boîte de dialogue. En sortie, valeur 
     *                           entrée dans la boîte de dialogue si l'utilisateur clique sur Ok.
     * \param [in]      strTitle Texte à afficher dans le bandeau de titre de la boîte de dialogue.
     * \param [in]      strLabel Texte à afficher pour inviter l'utilisateur à entrer une valeur.
     *
     * \return \c true si l'utilisateur a cliqué sur le bouton Ok, \c false sinon.
     *
     * \see
     * Classes : CString, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif
     * \ingroup DialogManagement
     */
    virtual bool guiGetValue(double& dVal, const CString& strTitle=L"", const CString& strLabel=L"")=0;
    /*!
     * \brief Affiche la boîte de dialogue d'entrée d'une valeur.
     * 
     * Affiche la boîte de dialogue d'entrée d'une valeur pour la saisie d'un texte. 
     * \image html dlg-value.png "Boîte de dialogue de saisie d'une valeur"
     *
     * \param [in, out] strVal   En entrée, valeur à définir dans la boîte de dialogue. En sortie, valeur 
     *                           entrée dans la boîte de dialogue si l'utilisateur clique sur Ok.
     * \param [in]      strTitle Texte à afficher dans le bandeau de titre de la boîte de dialogue.
     * \param [in]      strLabel Texte à afficher pour inviter l'utilisateur à entrer une valeur.
     *
     * \return \c true si l'utilisateur a cliqué sur le bouton Ok, \c false sinon.
     *
     * \see
     * Classes : CString, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif
     * \ingroup DialogManagement
     */
    virtual bool guiGetValue(CString& strVal, const CString& strTitle=L"", const CString& strLabel=L"")=0;
    /*!
     * \brief Affiche la boîte de dialogue d'affichage d'un message.
     * 
     * Affiche la boîte de dialogue d'affichage d'un message. 
     * \image html dlg-question.png "Exemple de boîte de dialogue d'affichage de message"
     *
     * \param [in] strTitle Texte à afficher dans le bandeau de titre de la boîte de dialogue.
     * \param [in] strText  Texte à afficher comme message.
     * \param [in] btns     Types de boutons à afficher.
     * \param [in] icon     Type d'icone à afficher.
     * \param [in] defbtn   Choix du bouton par défaut.
     *
     * \return Le code du bouton qui a été cliqué pour fermer la boîte de dialogue.
     *
     * \see
     * Classes : CString, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Tyoes de données : msgbtn_types, msgicon_types, msgdefbtn_vals, msgbtn_answer
     * \ingroup DialogManagement
     */
    virtual msgbtn_answer guiMessageBox(const CString& strTitle=L"", const CString& strText=L"", msgbtn_types btns=MsgBtnOK, msgicon_types icon = MsgIcnNone, msgdefbtn_vals defbtn = MsgDefBtn1)=0;
    /*!
     * \brief Affiche la boîte de dialogue de sélection d'une police de caractère.
     * 
     * Affiche la boîte de dialogue de sélection d'une police de caractère. 
     * \image html dlg-font.png "Boîte de dialogue de sélection d'une police de caractère"
     *
     * \param [in, out] strFontName En entrée, nom de la police de caractère à pré-sélectionner dans la boîte de dialogue.
     *                              En sortie, nom de la police de caractère sélectionnée dans la boite de dialogue 
     *                              si l'utilisateur a cliqué sur Ok.
     * \param [in, out] fPointSize  En entrée, taille de la police de caractère à pré-sélectionner dans la boîte de dialogue.
     *                              En sortie, taille de la police de caractère sélectionnée dans la boite de dialogue 
     *                              si l'utilisateur a cliqué sur Ok.
     * \param [in, out] nStyleFlags En entrée, style de la police de caractère à pré-sélectionner dans la boîte de dialogue.
     *                              En sortie, style de la police de caractère sélectionnée dans la boite de dialogue 
     *                              si l'utilisateur a cliqué sur Ok.
     *
     * \return \c true si l'utilisateur a cliqué sur le bouton Ok, \c false sinon.
     *
     * \see
     * Classes : CString, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Tyoe de données : font_styles
     * \ingroup DialogManagement
     */
    virtual bool guiGetFont(CString& strFontName, float& fPointSize, font_styles& nStyleFlags)=0;
  };
#if LIBGRAPH2_LEVEL == 3 || defined(LIBGRAPH2_EXPORTS)
  // Cette classe est exportée de LibGraph2.dll
  /*!
   * \brief
   * Classe principale de LibGraph 2 pour le niveau Avancé.
   * 
   * Cette classe regroupe toutes les fonctionnalités du niveau Avancé d'une fenêtre graphique LibGraph 2.
   * 
   * \remarks
   * Pour une plus grande portabilité du code entre les niveaux Avancé et Expert, vous pouvez utiliser la classe ILibGraph2, qui est un alias 
   * vers cette classe.
   * 
   * \see
   * Classes : ILibGraph2
   */
  class LIBGRAPH2_API ILibGraph2_Adv : virtual public ILibGraph2_Com
  {
  public:
    //fonctions accessibles uniquement au niveau avancé
    /*!
     * \brief Dessine une ligne brisée ou un polygone.
     * 
     * Dessine une ligne brisée ou un polygone en fonction du paramètre \c bAutoClose.
     * \image html poly.png "Ligne brisée et polygone"
     *
     * \param [in] pPoints    Tableau de points correspondants aux sommets de la forme
     * \param [in] nNbPoints  Nombre de points dans le tableau
     * \param [in] bAutoClose \c true si la forme doit être fermée (et donc remplie par 
     *                        le pinceau courrant), \c false s'il s'agit d'une ligne brisée
     *
     * \see
     * Classes : CPoint, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Fonctions de dessin : setPen(), setSolidBrush(), setTextureBrush()
     * \ingroup DrawingShapes
     */
    virtual void drawPolylines(CPoint* pPoints, int nNbPoints, bool bAutoClose=false)=0;

    /*!
     * \brief Affiche la boîte de dialogue de sélection d'un fichier.
     * 
     * Affiche la boîte de dialogue de sélection d'un fichier.
     * \image html dlg-file.png "Boîte de dialgoue de sélection de fichier"
     *
     * \param [in, out] sFileName     En entrée, nom de fichier à pré-sélectionner dans la boîte de dialogue.
     *                                En sortie, nom du fichier sélectionné si l'utilisateur a validé sa saisie.
     * \param [in]      bOpen         \c true s'il s'agit d'ouvrir un fichier, \c false s'il s'agit de l'enregistrer.
     * \param [in]      pstrFileTypes Tableau de chaines de caractères spécifiant les types de fichiers *
     *                                sélectionnables dans la boîte de dialogue. \n
     *                                Chaque chaine doit être de la forme "Nom du filtre|Extensions séparées par des ;"
     *                                Exemple : "Fichiers images (JPEG, PNG, BMP, GIF, TIFF)|*.jpg;*.jpeg;*.png;*.bmp;*.gif;*.tiff"
     *
     * \param [in]      nNbFileTypes  Nombre d'éléments dans le tableau pstrFileTypes.
     *
     * \see
     * Classes : CString, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif
     * \ingroup DialogManagement
     */
    virtual bool guiGetFileName(CString& sFileName, bool bOpen = true, CString* pstrFileTypes = NULL, int nNbFileTypes = 0)=0;

  };
#endif
#if LIBGRAPH2_LEVEL > 3 || defined(LIBGRAPH2_EXPORTS)
  // Cette classe est exportée de LibGraph2.dll
  /*!
   * \brief
   * Classe principale de LibGraph 2 pour le niveau Expert.
   * 
   * Cette classe regroupe toutes les fonctionnalités du niveau Expet d'une fenêtre graphique LibGraph 2.
   * 
   * \remarks
   * Pour une plus grande portabilité du code entre les niveaux Avancé et Expert, vous pouvez utiliser la classe ILibGraph2, qui est un alias 
   * vers cette classe.
   * 
   * \see
   * Classes : ILibGraph2
   */
  class LIBGRAPH2_API ILibGraph2_Exp : virtual public ILibGraph2_Com
  {
  public:
    //fonctions de niveau Expert (inaccessible si niveau avancé)
    /*!
     * \brief Dessine une ligne brisée ou un polygone.
     * 
     * Dessine une ligne brisée ou un polygone en fonction du paramètre \c bAutoClose.
     * \image html poly.png "Ligne brisée et polygone"
     *
     * \param [in] vPoints    Vecteur de points correspondants aux sommets de la forme
     * \param [in] bAutoClose \c true si la forme doit être fermée (et donc remplie par 
     *                        le pinceau courrant), \c false s'il s'agit d'une ligne brisée
     *
     * \see
     * Classes : CPoint, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif \n
     * Fonctions de dessin : setPen(), setSolidBrush(), setTextureBrush()
     * \ingroup DrawingShapes
     */
    virtual void drawPolylines(const std::vector<CPoint>& vPoints, bool bAutoClose=false)=0;

    /*!
     * \brief Affiche la boîte de dialogue de sélection d'un fichier.
     * 
     * Affiche la boîte de dialogue de sélection d'un fichier.
     * \image html dlg-file.png "Boîte de dialgoue de sélection de fichier"
     *
     * \param [in, out] sFileName     En entrée, nom de fichier à pré-sélectionner dans la boîte de dialogue.
     *                                En sortie, nom du fichier sélectionné si l'utilisateur a validé sa saisie.
     * \param [in]      bOpen         \c true s'il s'agit d'ouvrir un fichier, \c false s'il s'agit de l'enregistrer.
     * \param [in]      vstrFileTypes Vecteur de chaines de caractères spécifiant les types de fichiers *
     *                                sélectionnables dans la boîte de dialogue. \n
     *                                Chaque chaine doit être de la forme "Nom du filtre|Extensions séparées par des ;"
     *                                Exemple : "Fichiers images (JPEG, PNG, BMP, GIF, TIFF)|*.jpg;*.jpeg;*.png;*.bmp;*.gif;*.tiff"
     *
     * \see
     * Classes : CString, \if NIVEAU3 ILibGraph2_Adv \endif \if NIVEAU4 ILibGraph2_Exp \endif
     * \ingroup DialogManagement
     */
    virtual bool guiGetFileName(CString& sFileName, bool bOpen = true, const std::vector<CString>& vstrFileTypes = std::vector<CString>())=0;
  };
#endif

#if LIBGRAPH2_LEVEL == 3 || defined(LIBGRAPH2_EXPORTS)
  /*!
    * \brief Récupère un pointeur vers la fenêtre graphique.
    * 
    * Récupère un pointeur vers la seule et unique fenêtre graphique. Pour la simplicité du développement client,
    * LibGraph 2 ne supporte la gestion que d'une seule fenêtre graphique. Il n'est pas possible d'instancier 
    * directement la classe ILibGraph2. Le développeur client est obligé d'appeler cette fonction pour récupérer 
    * un pointeur vers l'unique objet de type ILibGraph2.
    *
    * Peut-être utilisée par le biais de la macro \c GetLibGraph2, permettant ainsi de résoudre les problèmes de 
    * portabilité entre les niveaux Avancé et Expert.
    *
    * \return Un pointeur vers l'unique objet de type ILibGraph2
    *
    * \see
    * Classe : ILibGraph2 \n
    * Fonction : ReleaseLibGraph2()
    * \ingroup WndMgmt
    */
  LIBGRAPH2_API ILibGraph2_Adv* GetLibGraph2Adv(void);
#endif
#if LIBGRAPH2_LEVEL == 4 || defined(LIBGRAPH2_EXPORTS)
  /*!
    * \brief Récupère un pointeur vers la fenêtre graphique.
    * 
    * Récupère un pointeur vers la seule et unique fenêtre graphique. Pour la simplicité du développement client,
    * LibGraph 2 ne supporte la gestion que d'une seule fenêtre graphique. Il n'est pas possible d'instancier 
    * directement la classe ILibGraph2. Le développeur client est obligé d'appeler cette fonction pour récupérer 
    * un pointeur vers l'unique objet de type ILibGraph2.
    *
    * Peut-être utilisée par le biais de la macro \c GetLibGraph2, permettant ainsi de résoudre les problèmes de 
    * portabilité entre les niveaux Avancé et Expert.
    *
    * \return Un pointeur vers l'unique objet de type ILibGraph2
    *
    * \see
    * Classe : ILibGraph2 \n
    * Fonction : ReleaseLibGraph2()
    * \ingroup WndMgmt
    */
  LIBGRAPH2_API ILibGraph2_Exp* GetLibGraph2Exp(void);
#endif
  /*!
    * \brief Récupère un pointeur vers la fenêtre graphique.
    * 
    * Récupère un pointeur vers la seule et unique fenêtre graphique. Pour la simplicité du développement client,
    * LibGraph 2 ne supporte la gestion que d'une seule fenêtre graphique. Il n'est pas possible d'instancier 
    * directement la classe ILibGraph2. Le développeur client est obligé d'appeler cette fonction pour récupérer 
    * un pointeur vers l'unique objet de type ILibGraph2.
    *
    * \return Un pointeur vers l'unique objet de type ILibGraph2
    *
    * \see
    * Classe : ILibGraph2 \n
    * Fonction : ReleaseLibGraph2()
    * \ingroup WndMgmt
    */
#if LIBGRAPH2_LEVEL == 3
#define GetLibGraph2 GetLibGraph2Adv
#else if LIBGRAPH2_LEVEL == 4
#define GetLibGraph2 GetLibGraph2Exp
#endif
#endif
  /*!
    * \brief Libère le pointeur vers la fenêtre graphique.
    * 
    * Libère le pointeur vers la seule et unique fenêtre graphique. 
    *
    * \see
    * Classe : ILibGraph2 \n
    * Fonction : GetLibGraph2()
    * \ingroup WndMgmt
    */
  LIBGRAPH2_API void ReleaseLibGraph2(void);

  /*!
   * \brief Crée une couleur ARGB
   *
   * Fonction utilitaire pour créer un code couleur.
   *
   * \param [in] a Composante Alpha de la couleur (0 = transparent, 255 = opaque)
   * \param [in] r Composante Rouge de la couleur
   * \param [in] g Composante Verte de la couleur
   * \param [in] b Composante Bleue de la couleur
   *
   * \return Le code couleur ainsi généré
   *
   * \sa
   * Section : \ref DrawingProperties \n
   * Type de donnée : ARGB \n
   * Fonctions : GetA(), GetR(), GetG(), GetB()
   * \ingroup DrawingProperties
   */
  LIBGRAPH2_API ARGB MakeARGB(BYTE a, BYTE r, BYTE g, BYTE b);
  /*!
   * \brief Récupère la composante alpha d'une couleur
   *
   * \param [in] c Couleur à analyser
   *
   * \return Le niveau de la composante alpha
   *
   * \sa
   * Section : \ref DrawingProperties \n
   * Type de donnée : ARGB\n
   * Fonctions : MakeARGB(), GetR(), GetG(), GetB()
   * \ingroup DrawingProperties
   */
  LIBGRAPH2_API unsigned char GetA(ARGB c);
  /*!
   * \brief Récupère la composante rouge d'une couleur
   *
   * \param [in] c Couleur à analyser
   *
   * \return Le niveau de la composante rouge
   *
   * \sa
   * Section : \ref DrawingProperties \n
   * Type de donnée : ARGB\n
   * Fonctions : MakeARGB(), GetA(), GetG(), GetB()
   * \ingroup DrawingProperties
   */
  LIBGRAPH2_API unsigned char GetR(ARGB c);
  /*!
   * \brief Récupère la composante verte d'une couleur
   *
   * \param [in] c Couleur à analyser
   *
   * \return Le niveau de la composante verte
   *
   * \sa
   * Section : \ref DrawingProperties \n
   * Type de donnée : ARGB\n
   * Fonctions : MakeARGB(), GetA(), GetR(), GetB()
   * \ingroup DrawingProperties
   */
  LIBGRAPH2_API unsigned char GetG(ARGB c);
  /*!
   * \brief Récupère la composante bleue d'une couleur
   *
   * \param [in] c Couleur à analyser
   *
   * \return Le niveau de la composante bleue
   *
   * \sa
   * Section : \ref DrawingProperties \n
   * Type de donnée : ARGB\n
   * Fonctions : MakeARGB(), GetA(), GetR(), GetG()
   * \ingroup DrawingProperties
   */
  LIBGRAPH2_API unsigned char GetB(ARGB c);

  LIBGRAPH2_API std::ostream& operator<<(std::ostream& out, const std::wstring& str);


//Fonctions accessibles uniquement au niveau Novice
#if LIBGRAPH2_LEVEL == 0 || defined(LIBGRAPH2_EXPORTS)
  /*!
   * \brief Met le programme en pause jusqu'au prochain événement.
   * 
   * Met le programme en pause jusqu'au prochain événement. Lorsqu'un événement se produit,
   * il est alors retournée dans le paramètre \c e. Cette fonction permet de mettre en place 
   * la boucle d'événement du programme principal selon le code suivant :
   * \code
   *   show();  //Affiche la fenêtre graphique
   *   while(waitForEvent())
   *   {
   *     switch(getLastEventType())
   *     {
   *       //Clauses "case" pour traiter les événements
   *     }
   *   }
   * \endcode
   * 
   * \return \c false si la fenêtre a été fermée, \c true dans tous les autres cas.
   * 
   * \see
   * Fonctions : getLastEventType(), getLastEventKeyCode(), getLastEventMouseX(), getLastEventMouseY()
   * \ingroup EventManagement
   */
  LIBGRAPH2_API bool waitForEvent();
  /*!
   * \brief Récupère le type du dernier événement reçu
   * 
   * Récupère le type du dernier événement reçu.
   *
   * \return Le type de l'événement.
   * 
   * \see
   * Fonctions : waitForEvent(), getLastEventKeyCode(), getLastEventMouseX(), getLastEventMouseY() \n
   * Type de données : evt_type
   * \ingroup EventManagement
   */
  LIBGRAPH2_API evt_type getLastEventType();
  /*!
   * \brief Récupère le code de touche clavier du dernier événement reçu
   * 
   * Récupère le code de touche clavier du dernier événement reçu.\n
   * Valide uniquement si le dernier événement est un événement clavier.\n
   * Pour les touches Alphanumériques, le code de touche correspond au code du caractère
   * majuscule de la touche. Par exemple, la touche "a" correspond au code 'A'.\n
   * Pour les touches spéciales (Majuscule, Control, Echap, etc...), le code de touche corresponds
   * aux valeurs de touches virtuelles du SDK de Windows. Se référer à l'aide en ligne de
   * MSDN pour le listing de ces valeurs : http://msdn.microsoft.com/en-us/library/dd375731.aspx
   *
   * \return Le code de touche clavier.
   * 
   * \see
   * Fonctions : waitForEvent(), getLastEventType(), getLastEventMouseX(), getLastEventMouseY()
   * \ingroup EventManagement
   */
  LIBGRAPH2_API int getLastEventKeyCode();
  /*!
   * \brief Récupère la position X de la souris lors du dernier événement
   * 
   * Récupère la position X de la souris lors du dernier événement. 
   * Valide uniquement si le dernier événement est un événement souris.
   * 
   * \return La position X de la souris.
   * 
   * \see
   * Fonctions : waitForEvent(), getLastEventType(), getLastEventKeyCode(), getLastEventMouseY()
   * \ingroup EventManagement
   */
  LIBGRAPH2_API int getLastEventMouseX();
  /*!
   * \brief Récupère la position Y de la souris lors du dernier événement
   * 
   * Récupère la position Y de la souris lors du dernier événement. 
   * Valide uniquement si le dernier événement est un événement souris.
   * 
   * \return La position Y de la souris.
   * 
   * \see
   * Fonctions : waitForEvent(), getLastEventType(), getLastEventKeyCode(), getLastEventMouseX()
   * \ingroup EventManagement
   */
  LIBGRAPH2_API int getLastEventMouseY();
#endif

//Fonctions accessibles uniquement au niveau Débutant
#if LIBGRAPH2_LEVEL == 1 || defined(LIBGRAPH2_EXPORTS)
#endif

//Fonctions accessibles uniquement au niveau Intermédiaire
#if LIBGRAPH2_LEVEL == 2 || defined(LIBGRAPH2_EXPORTS)
  /*!
   * \brief Dessine une ligne brisée ou un polygone.
   * 
   * Dessine une ligne brisée ou un polygone en fonction du paramètre \c bAutoClose.
   * \image html poly.png "Ligne brisée et polygone"
   *
   * \param [in] pXs        Tableau des abscisses des points correspondants aux sommets de la forme
   * \param [in] pYs        Tableau des ordonnées des points correspondants aux sommets de la forme
   * \param [in] nNbPoints  Nombre de points dans les tableaux
   * \param [in] bAutoClose \c true si la forme doit être fermée (et donc remplie par 
   *                        le pinceau courrant), \c false s'il s'agit d'une ligne brisée
   *
   * \see
   * Fonctions de dessin : setPen(), setSolidBrush(), setTextureBrush()
   * \ingroup DrawingShapes
   */
  LIBGRAPH2_API void drawPolylines(const float* pXs, const float* pYs, int nNbPoints, bool bAutoClose=false);
#endif

//Fonctions communes aux niveaux Novice et Débutant
#if LIBGRAPH2_LEVEL <= 1 || defined(LIBGRAPH2_EXPORTS)
#endif

//Fonctions communes aux niveaux Novice, Débutant et Intermédiaire
#if LIBGRAPH2_LEVEL <= 2 || defined(LIBGRAPH2_EXPORTS)
  /*!
   * \brief Affiche la fenêtre graphique.
   * 
   * Affiche la fenêtre graphique. La fenêtre peut être affichée en plein écran. Pour quitter 
   * le mode plein écran, il suffit d'appuyer sur la touche "échap".
   *
   * \param [in] fWidth (optionnel) Définit la largeur de la fenêtre.
   * \param [in] fHeight (optionnel) Définit la hauteur de la fenêtre.\n
   * Si la taille de la fenêtre est défini (c'est-à-dire autre que 0,0), alors la fenêtre est initialement affichée avec 
   * son espace intérieur de la taille spécifiée. Son système de coordonnées est alors celui spécifié par sa taille. 
   * La fenêtre est librement redimensionable par l'utilisateur, mais dans ce cas, le système de coordonnées reste fixé à
   * celui de départ, ayant pour conséquence de réduire ou agrandir l'image tracée. \n
   * Dans le cas où la taille de la fenêtre n'est pas spécifiée, alors la fenêtre est affichée avec une taille par défaut
   * et le système de coordonnées est directement appliqué sur les pixels. Ainsi, agrandir ou réduire la fenêtre n'aura 
   * pour conséquence que d'agrandir ou de réduire l'espace de travail.
   * \param [in] bFullScreen (optionnel) Affiche la fenêtre en plein écran.\n
   * Si le paramètre vaut \c false (par défaut) alors la fenêtre est affichée à la taille spécifié par le paramètre \c szWndSize.\n
   * Si le paramètre vaut \c true alors la fenêtre est affichée en plein écran. L'appuie sur la touche "Echap" permet de quitter 
   * le mode plein écran.
   *
   * \see
   * Fonctions : hide(), getWidth(), getHeight()
   * \ingroup WndManagement
   */
  LIBGRAPH2_API void show(float fWidth=0, float fHeight=0, bool bFullScreen=false);
  /*!
   * \brief Masque la fenêtre graphique.
   * 
   * Masque la fenêtre graphique. La fenêtre n'est pas détruite, elle est seulement rendue 
   * invisible. Elle peut être réaffichée en appelant la fonction show().
   *
   * \see
   * Fonctions : show(), getWidth(), getHeight()
   * \ingroup WndManagement
   */
  LIBGRAPH2_API void hide();
  /*!
   * \brief Récupère la largeur de la fenêtre.
   * 
   * Retourne la largeur de la fenêtre. Si la fenêtre a été affichée avec un système de coordonnées spécifique (paramètres  
   * \c fWidth et \c fHeight de la fonction show() définis) alors, la taille retournée est toujours la taille spécifiée lors de 
   * l'affichage de la fenêtre. Sinon, il s'agit de la taille de la zone graphique de la fenêtre en pixel.
   *
   * \returns Largeur de la fenêtre.
   *
   * \see
   * Fonctions : show(), hide()
   * \ingroup WndManagement
   */
  LIBGRAPH2_API float getWidth();
  /*!
   * \brief Récupère la hauteur de la fenêtre.
   * 
   * Retourne la hauteur de la fenêtre. Si la fenêtre a été affichée avec un système de coordonnées spécifique (paramètres  
   * \c fWidth et \c fHeight de la fonction show() définis) alors, la taille retournée est toujours la taille spécifiée lors de 
   * l'affichage de la fenêtre. Sinon, il s'agit de la taille de la zone graphique de la fenêtre en pixel.
   *
   * \returns Hauteur de la fenêtre.
   *
   * \see
   * Fonctions : show(), hide()
   * \ingroup WndManagement
   */
  LIBGRAPH2_API float getHeight();
  /*!
   * \brief Affiche la console.
   * 
   * Affiche la console et l'active. Le focus de l'utilisateur est lors placé sur la console. Afin d'écrire ou lire 
   * dans la console, vous pouvez utiliser les objets STL cout et cin, comme pour n'importe quel programme. 
   *
   * \remark Lors de la lecture à l'aide de cin, vous devez appeler la fonction std::cin.clear() 
   * avant de pouvoir accéder au flux en lecture.
   *
   * \remark Cette fonction est automatiquement appelée lorsque les objets std::cout ou std::cin sont utilisés pour 
   * accéder aux flux standards.
   *
   * \see
   * Fonction : hideConsole()
   * \ingroup ConManagement
   */
  LIBGRAPH2_API void showConsole();
  /*!
   * \brief Masque la console.
   * 
   * Masque la console.
   * 
   * \see
   * Fonction : showConsole()
   * \ingroup ConManagement
   */
  LIBGRAPH2_API void hideConsole();
  /*!
   * \brief Demande à rafraichir la fenêtre.
   * 
   * Demande à rafraichir la fenêtre. L'événement evtRefresh sera envoyé dès que possible après l'appel de cette fonction.
   * 
   * \see
   * Fonction : waitForEvent()
   * \ingroup EventManagement
   */
  LIBGRAPH2_API void askForRefresh();
  /*!
   * \brief Active le backbuffer.
   * 
   * L'appel de cette fonction permet d'activer le backbuffer. A partir de cet appel, les fonctions de dessins ne 
   * s'exécuteront plus directement sur la fenêtre mais dans une mémoire tampon (le backbuffer) de même taille que 
   * la fenêtre. L'affichage dans la fenetre sera ensuite réalisé lors de l'appel de la fonction endPaint() qui 
   * copie le contenu du backbuffer dans la fenêtre. Si la fonction endPaint() n'est pas appelée en fin de dessin, 
   * alors rien ne sera affiché à l'écran.\n
   * Le code suivant est un exemple d'affichage utilisant la technique du backbuffer :
   *
   * \code
   *   switch(type)  //En fonction du type d'événement
   *   {
   *   case evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
   *     beginPaint(); //Active le backbuffer
   *       //Utiliser ici les fonctions de dessins
   *     endPaint();   //Recopie le contenu du backbuffer dans la fenêtre
   *     break;
   *   //autres événements
   *   }
   * \endcode
   * \remark Il est très avantageux d'utiliser cette fonctionnalité qui accélère énormément l'affichage et évite 
   * les effets de scintillement qui peuvent provenir lors d'un affichage direct à l'écran.
   * 
   * \see
   * Fonction : endPaint()
   * \ingroup DrawingManagement
   */
  LIBGRAPH2_API void beginPaint();
  /*!
   * \brief Recopie le contenu du backbuffer dans la fenêtre graphique.
   * 
   * Recopie le contenu du backbuffer dans la fenêtre graphique. Si la fonction beginPaint() n'a pas été appelée 
   * préalablement, la fonction endPaint() n'a aucun effet.
   *
   * \see
   * Fonction : beginPaint()
   * \ingroup DrawingManagement
   */
  LIBGRAPH2_API void endPaint();

  /*!
   * \brief Définit le style du crayon.
   * 
   * Permet de définir la couleur, l'épaisseur et le style du trait qui sera utilisé par les fonctions de dessin.
   *
   * \param [in] color Code couleur du crayon
   * \param [in] fWidth Epaisseur du crayon
   * \param [in] style (optionnel) Style du trait. Trait plein par défaut.
   *
   * \see
   * Types de données : ARGB, pen_DashStyles \n
   * Fonctions utilitaires : MakeARGB(), GetA(), GetR(), GetG(), GetB()
   * \ingroup DrawingProperties
   */
  LIBGRAPH2_API void setPen(ARGB color, float fWidth, pen_DashStyles style =Solid);
  /*!
   * \brief Définit le style du pinceau par une couleur pleine.
   * 
   * Permet de définir la couleur de remplissage des formes fermées.
   *
   * \param [in] color Code couleur du crayon
   *
   * \see
   * Types de données : ARGB \n
   * Fonctions utilitaires : MakeARGB(), GetA(), GetR(), GetG(), GetB()
   * \ingroup DrawingProperties
   */
  LIBGRAPH2_API void setSolidBrush(ARGB color);

  /*!
   * \brief Dessine une ellipse.
   * 
   * Une ellipse est définie par son rectangle englobant.
   * \image html ellipse.png "Ellipse"
   *
   * \param [in] x       Abscisse du coin supérieur gauche du rectangle englobant  de l'ellipse
   * \param [in] y       Ordonnée du coin supérieur gauche du rectangle englobant  de l'ellipse
   * \param [in] fWidth  Largeur du rectangle englobant  de l'ellipse
   * \param [in] fHeight Hauteur du rectangle englobant  de l'ellipse
   *
   * \see
   * Fonctions de dessin : setPen(), setSolidBrush()
   * \ingroup DrawingShapes
   */
  LIBGRAPH2_API void drawEllipse(float x, float y, float fWidth, float fHeight);
  /*!
   * \brief Dessine un arc d'ellipse.
   * 
   * Un arc d'ellipse est défini par son rectangle englobant, son angle de départ et son angle de balayage.
   * \image html arc.png "Arc d'ellipse"
   *
   * \param [in] x          Abscisse du coin supérieur gauche du rectangle englobant  de l'ellipse
   * \param [in] y          Ordonnée du coin supérieur gauche du rectangle englobant  de l'ellipse
   * \param [in] fWidth     Largeur du rectangle englobant  de l'ellipse
   * \param [in] fHeight    Hauteur du rectangle englobant  de l'ellipse
   * \param [in] startAngle Angle de départ de l'arc (en degrés)
   * \param [in] sweepAngle Angle de balayage de l'arc (en degrés)
   *
   * \see
   * Fonction de dessin : setPen()
   * \ingroup DrawingShapes
   */
  LIBGRAPH2_API void drawArc(float x, float y, float fWidth, float fHeight, float startAngle, float sweepAngle);
  /*!
   * \brief Dessine une portion de camembert.
   * 
   * Une portion de camembert est définie par son rectangle englobant, son angle de départ et son angle de balayage.
   * \image html pie.png "Portion de camembert"
   *
   * \param [in] x          Abscisse du coin supérieur gauche du rectangle englobant  de l'ellipse
   * \param [in] y          Ordonnée du coin supérieur gauche du rectangle englobant  de l'ellipse
   * \param [in] fWidth     Largeur du rectangle englobant  de l'ellipse
   * \param [in] fHeight    Hauteur du rectangle englobant  de l'ellipse
   * \param [in] startAngle Angle de départ de l'arc (en degrés)
   * \param [in] sweepAngle Angle de balayage de l'arc (en degrés)
   *
   * \see
   * Fonctions de dessin : setPen(), setSolidBrush()
   * \ingroup DrawingShapes
   */
  LIBGRAPH2_API void drawPie(float x, float y, float fWidth, float fHeight, float startAngle, float sweepAngle);
  /*!
   * \brief Dessine un segment.
   * 
   * Un segment est défini par ses deux points extrémités.
   * \image html line.png "Segment de droite"
   *
   * \param [in] x1 Abscisse de l'extrémité de départ
   * \param [in] y1 Ordonnée de l'extrémité de départ
   * \param [in] x2 Abscisse de l'extrémité d'arrivée
   * \param [in] y2 Ordonnée de l'extrémité d'arrivée
   *
   * \see
   * Fonction de dessin : setPen()
   * \ingroup DrawingShapes
   */
  LIBGRAPH2_API void drawLine(float x1, float y1, float x2, float y2);
  /*!
   * \brief Dessine un rectangle.
   * 
   * Dessine un rectangle.
   * \image html rectangle.png "Rectangle"
   *
   * \param [in] x          Abscisse du coin supérieur gauche du rectangle
   * \param [in] y          Ordonnée du coin supérieur gauche du rectangle
   * \param [in] fWidth     Largeur du rectangle
   * \param [in] fHeight    Hauteur du rectangle
   *
   * \see
   * Fonctions de dessin : setPen(), setSolidBrush()
   * \ingroup DrawingShapes
   */
  LIBGRAPH2_API void drawRectangle(float x, float y, float fWidth, float fHeight);

  /*!
   * \brief Définit la couleur d'un pixel.
   * 
   * Définit la couleur d'un pixel.
   * \image html pixels.png "Dégradé de couleur généré pixel par pixel"
   *
   * \param [in] x     Abscisse du pixel
   * \param [in] y     Ordonnée du pixel
   * \param [in] color Code couleur du pixel
   *
   * \see
   * Types de données : ARGB \n
   * Fonctions utilitaires : MakeARGB(), GetA(), GetR(), GetG(), GetB()
   * \ingroup DrawingBitmap
   */
  LIBGRAPH2_API void setPixel(float x, float y, ARGB color);
  /*!
    * \brief Dessine une image bitmap.
    * 
    * Dessine une image bitmap chargée depuis un fichier. Les formats supportés sont JPEG, BMP, PNG,
    * GIF, TIFF et ICO. L'image peut être agrandie ou réduite, et tournée par rapport à son centre ou 
    * son coin supérieur gauche.
    * \image html bitmap.png "Image bitmap dessinée par LibGraph 2"
    *
    * \param [in] sFileName    Nom du fichier image à afficher
    * \param [in] fPosX, fPosY Position de l'image. Se réfère au coin supérieur gauche si \c bXYIsCenter 
    *                          vaut false, sinon se réfère au centre de l'image
    * \param [in] dScaleFactor (optionnel) Facteur d'échelle d'affichage de l'image. (1.0 par défaut)
    * \param [in] dAngleDeg    (optionnel) Angle de rotation de l'image en degrés. (0.0 par défaut)
    * \param [in] bXYIsCenter  (optionnel) Spécifie si la position et la rotation se réfèrent au coin 
    *                          supérieur gauche (\c false) ou au centre de l'image (\c true). (\c false 
    *                          par défaut)
    *
    * \ingroup DrawingBitmap
    */
  LIBGRAPH2_API void drawBitmap(const char* sFileName, float fPosX, float fPosY, double dScaleFactor = 1.0, double dAngleDeg=0, bool bXYIsCenter=false);
  /*!
    * \brief Dessine une image bitmap.
    * 
    * Dessine une image bitmap chargée depuis un fichier. Les formats supportés sont JPEG, BMP, PNG,
    * GIF, TIFF et ICO. L'image peut être agrandie ou réduite, et tournée. Le point de
    * pivot et d'accroche de l'image peut être défini à la position voulue.
    * \image html bitmap.png "Image bitmap dessinée par LibGraph 2"
    *
    * \param [in] sFileName               Nom du fichier image à afficher
    * \param [in] fPosX, fPosY            Position de l'image. Se réfère au point de pivot spécifié par \c ptPosPivot
    * \param [in] fPosPivotX, fPosPivotY  Position du point de pivot dans l'image, le référentiel de coordonnées est 
    *                                     le coin supérieur gauche de l'image.
    * \param [in] dScaleFactor            Facteur d'échelle d'affichage de l'image.
    * \param [in] dAngleDeg               Angle de rotation de l'image en degrés.
    *
    * \ingroup DrawingBitmap
    */
  LIBGRAPH2_API void drawBitmap(const char* sFileName, float fPosX, float fPosY, float fPosPivotX, float fPosPivotY, double dScaleFactor, double dAngleDeg);
#endif

//Fonctions communes aux niveaux Débutant et Intermédiaire
#if (LIBGRAPH2_LEVEL >= 1 && LIBGRAPH2_LEVEL <= 2) || defined(LIBGRAPH2_EXPORTS)
  /*!
   * \brief Met le programme en pause jusqu'au prochain événement.
   * 
   * Met le programme en pause jusqu'au prochain événement. Lorsqu'un événement se produit,
   * il est alors retournée dans le paramètre \c e. Cette fonction permet de mettre en place 
   * la boucle d'événement du programme principal selon le code suivant :
   * \code
   *   //Affiche la fenêtre graphique avec une taille par défaut
   *   show();
   *   evt_type evtType;  //Type d'événement LibGraph 2
   *   int evtKeyCode;    //Code de touche du clavier
   *   int evtMouseX;     //Abscisse de la position de la souris
   *   int evtMouseY;     //Ordonnée de la position de la souris
   *
   *   //Boucle principale d'événements
   *   while(waitForEvent(evtType, evtKeyCode, evtMouseX, evtMouseY))
   *   {
   *     switch(evtType)  //En fonction du type d'événement
   *     {
   *       //Clauses "case" pour traiter les événements
   *       //Si l'événement est un événement clavier, on peut connaitre la touche à l'aide de la variable evtKeyCode
   *       //Si l'événement est un événement souris, on peut connaitre la position de la souris à l'aide des variables evtMouseX et evtMouseY
   *     }
   *   }
   * \endcode
   *
   * \param [out] evtType    Type de l'événement reçu
   * \param [out] evtKeyCode Code de touche clavier de l'événement reçu.\n
   * Valide uniquement si le dernier événement est un événement clavier.\n
   * Pour les touches Alphanumériques, le code de touche correspond au code du caractère
   * majuscule de la touche. Par exemple, la touche "a" correspond au code 'A'.\n
   * Pour les touches spéciales (Majuscule, Control, Echap, etc...), le code de touche corresponds
   * aux valeurs de touches virtuelles du SDK de Windows. Se référer à l'aide en ligne de
   * MSDN pour le listing de ces valeurs : http://msdn.microsoft.com/en-us/library/dd375731.aspx
   * \param [out] evtMouseX  Abscisse de la position de la souris.\n
   * Valide uniquement si le dernier événement est un événement souris.
   * \param [out] evtMouseY  Ordonnée de la position de la souris.\n
   * Valide uniquement si le dernier événement est un événement souris.
   *
   * \return \c false si la fenêtre a été fermée, \c true dans tous les autres cas.
   * 
   * \see
   * Type de donnée : evt_type
   * \ingroup EventManagement
   */
  LIBGRAPH2_API bool waitForEvent(evt_type& evtType, int& evtKeyCode, int& evtMouseX, int& evtMouseY);
  
  /*!
   * \brief Affiche la boîte de dialogue de sélection de couleur.
   * 
   * Affiche la boîte de dialogue de sélection de couleur.
   * \image html dlg-color.png "Boîte de dialogue de sélection d'une couleur"
   *
   * \param [in, out]  color En entrée, couleur à définir dans la boîte de dialogue. En sortie, couleur 
   *                         sélectionnée dans la boîte de dialogue si l'utilisateur clique sur Ok.
   *
   * \return \c true si l'utilisateur a cliqué sur le bouton Ok, \c false sinon.
   *
   * \see
   * Types de données : ARGB \n
   * Fonctions utilitaires : MakeARGB(), GetA(), GetR(), GetG(), GetB()
   * \ingroup DialogManagement
   */
  LIBGRAPH2_API bool guiGetColor(ARGB& color);
  /*!
   * \brief Affiche la boîte de dialogue de sélection des attributs de traits.
   * 
   * Affiche la boîte de dialogue de sélection des attributs de traits, permettant de choisir la couleur, 
   * l'épaisseur et le style d'un trait.
   * \image html dlg-pen.png "Boîte de dialogue de sélection des attributs de traits"
   *
   * \param [in, out]  color  En entrée, couleur à définir dans la boîte de dialogue. En sortie, couleur 
   *                          sélectionnée dans la boîte de dialogue si l'utilisateur clique sur Ok.
   * \param [in, out]  fWidth En entrée, épaisseur de trait à définir dans la boîte de dialogue. En sortie,  
   *                          épaisseur choisie si l'utilisateur clique sur Ok.
   * \param [in, out]  style  En entrée, style de trait à définir dans la boîte de dialogue. En sortie,  
   *                          style choisi si l'utilisateur clique sur Ok.
   *
   * \return \c true si l'utilisateur a cliqué sur le bouton Ok, \c false sinon.
   *
   * \see
   * Types de données : ARGB, pen_DashStyles \n
   * Fonctions utilitaires : MakeARGB(), GetA(), GetR(), GetG(), GetB()
   * \ingroup DialogManagement
   */
  LIBGRAPH2_API bool guiGetPenStyle(ARGB& color, float& fWidth, pen_DashStyles& style);
  /*!
   * \brief Affiche la boîte de dialogue d'entrée d'une valeur.
   * 
   * Affiche la boîte de dialogue d'entrée d'une valeur pour la saisie d'une valeur entière. 
   * \image html dlg-value.png "Boîte de dialogue de saisie d'une valeur"
   *
   * \param [in, out] nVal     En entrée, valeur à définir dans la boîte de dialogue. En sortie, valeur 
   *                           entrée dans la boîte de dialogue si l'utilisateur clique sur Ok.
   * \param [in]      strTitle Texte à afficher dans le bandeau de titre de la boîte de dialogue.
   * \param [in]      strLabel Texte à afficher pour inviter l'utilisateur à entrer une valeur.
   *
   * \return \c true si l'utilisateur a cliqué sur le bouton Ok, \c false sinon.
   *
   * \ingroup DialogManagement
   */
  LIBGRAPH2_API bool guiGetValue(int& nVal, const char* strTitle="", const char* strLabel="");
  /*!
   * \brief Affiche la boîte de dialogue d'entrée d'une valeur.
   * 
   * Affiche la boîte de dialogue d'entrée d'une valeur pour la saisie d'une valeur décimale. 
   * \image html dlg-value.png "Boîte de dialogue de saisie d'une valeur"
   *
   * \param [in, out] dVal     En entrée, valeur à définir dans la boîte de dialogue. En sortie, valeur 
   *                           entrée dans la boîte de dialogue si l'utilisateur clique sur Ok.
   * \param [in]      strTitle Texte à afficher dans le bandeau de titre de la boîte de dialogue.
   * \param [in]      strLabel Texte à afficher pour inviter l'utilisateur à entrer une valeur.
   *
   * \return \c true si l'utilisateur a cliqué sur le bouton Ok, \c false sinon.
   *
   * \ingroup DialogManagement
   */
  LIBGRAPH2_API bool guiGetValue(double& dVal, const char* strTitle="", const char* strLabel="");
  /*!
   * \brief Affiche la boîte de dialogue d'affichage d'un message.
   * 
   * Affiche la boîte de dialogue d'affichage d'un message. 
   * \image html dlg-question.png "Exemple de boîte de dialogue d'affichage de message"
   *
   * \param [in] strTitle Texte à afficher dans le bandeau de titre de la boîte de dialogue.
   * \param [in] strText  Texte à afficher comme message.
   * \param [in] btns     Types de boutons à afficher.
   * \param [in] icon     Type d'icone à afficher.
   * \param [in] defbtn   Choix du bouton par défaut.
   *
   * \return Le code du bouton qui a été cliqué pour fermer la boîte de dialogue.
   *
   * \see
   * Tyoes de données : msgbtn_types, msgicon_types, msgdefbtn_vals, msgbtn_answer
   * \ingroup DialogManagement
   */
  LIBGRAPH2_API msgbtn_answer guiMessageBox(const char* strTitle="", const char* strText="", msgbtn_types btns=MsgBtnOK, msgicon_types icon = MsgIcnNone, msgdefbtn_vals defbtn = MsgDefBtn1);
#endif
}

#pragma warning(pop)

//!\endcond