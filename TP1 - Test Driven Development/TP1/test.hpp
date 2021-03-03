/*!
 * \file  "Test.h"
 *
 * \brief D‚claration des fonctions du framework de test. 
 *
 * \author Benjamin ALBOUY-KISSI
 * \date 2009-2015
 * \version 1.1
 */
#pragma once

#include <iostream>
#include <Windows.h>

//Macro d'aides pour ce fichier
#define HELP_VERIF_IMP(symbole) \
  __if_not_exists(symbole) { \
    nNbFailedTests++; \
    std::cout<<"Test ligne "<<__LINE__<<" : "; \
    std::cout<<colored("Echec - Le symbole \"" #symbole "\" n'est pas impl‚ment‚.", FOREGROUND_RED | FOREGROUND_INTENSITY)<<std::endl; \
    colored("", g_wDefaultColor); \
  } \

/*!
 * \brief Affiche une notification au cours des tests
 * 
 * \param text
 * Texte … afficher dans la notification.
 * 
 * Affiche la notification "text" en cyan brillant dans la console … l'aide de l'objet \c cout. 
 *
 */
#define NOTICE(text) \
  colored("", FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); \
  std::cout<<text; \
  colored("", g_wDefaultColor);

/*!
 * \brief Macro de v‚rification de pr‚requis d'impl‚mentation
 *
 * \param symbole
 * Symbole dont l'impl‚mentation est requise.
 *
 * \param operation
 * Op‚ration … r‚aliser.
 *
 * V‚rifie que le "symbole" soit impl‚ment‚ puis, si oui, r‚alise l'op‚ration demand‚e.
 *
 * \see BEGIN_TESTS | END_TESTS | TEST_IMP(symbole)
 */
#define VERIF_IMP_1(symbole, operation) \
  HELP_VERIF_IMP(symbole) \
  __if_exists(symbole){ operation; } \
  colored("", g_wDefaultColor);

/*!
 * \brief Macro de v‚rification de pr‚requis d'impl‚mentation
 *
 * \param symbole1
 * Symbole dont l'impl‚mentation est requise.
 *
 * \param symbole2
 * Symbole dont l'impl‚mentation est requise.
 *
 * \param operation
 * Op‚ration … r‚aliser.
 *
 * V‚rifie que les "symbole1" et "symbole2" soient impl‚ment‚s puis, si oui, r‚alise l'op‚ration demand‚e.
 *
 * \see BEGIN_TESTS | END_TESTS | TEST_IMP(symbole)
 */
#define VERIF_IMP_2(symbole1, symbole2, operation) \
  HELP_VERIF_IMP(symbole1) \
  HELP_VERIF_IMP(symbole2) \
  __if_exists(symbole1){ \
    __if_exists(symbole2){ \
      operation; \
    } \
  } \
  colored("", g_wDefaultColor);

/*!
 * \brief Macro de v‚rification de pr‚requis d'impl‚mentation
 *
 * \param symbole1
 * Symbole dont l'impl‚mentation est requise.
 *
 * \param symbole2
 * Symbole dont l'impl‚mentation est requise.
 *
 * \param symbole3
 * Symbole dont l'impl‚mentation est requise.
 *
 * \param operation
 * Op‚ration … r‚aliser.
 *
 * V‚rifie que les "symbole1", "symbole2" et "symbole3" soient impl‚ment‚s puis, si oui, r‚alise l'op‚ration demand‚e.
 *
 * \see BEGIN_TESTS | END_TESTS | TEST_IMP(symbole)
 */
#define VERIF_IMP_3(symbole1, symbole2, symbole3, operation) \
  HELP_VERIF_IMP(symbole1) \
  HELP_VERIF_IMP(symbole2) \
  HELP_VERIF_IMP(symbole3) \
  __if_exists(symbole1){ \
    __if_exists(symbole2){ \
      __if_exists(symbole3){ \
        operation; \
      } \
    } \
  } \
  colored("", g_wDefaultColor);

/*!
 * \brief Macro de v‚rification d'impl‚mentation d'un symbole
 * 
 * \param symbole
 * Symbole dont la pr‚sence doit ˆtre v‚rifi‚e.
 * 
 * Teste que le "symbole" est bien d‚fini. En cas d'‚chec, incr‚mente la variable 
 * \c nNbFailedTests, en cas de succŠs, incr‚mente la variable \c nNbSucceededTests.
 *
 * \remark
 * Les variables \c nNbSucceededTests et \c nNbFailedTests sont d‚clar‚es et initialis‚es par la 
 * macro BEGIN_TESTS. La macro TEST ne peut ˆtre utilis‚e qu'entre les macros BEGIN_TESTS et 
 * END_TESTS.
 *
 * \see BEGIN_TESTS | END_TESTS | VERIF_IMP_1(symbole, operation)
 */
#define TEST_IMP(symbole) \
  std::cout<<"Test ligne "<<__LINE__<<" : "; \
  __if_exists(symbole) { std::cout<<(nNbSucceededTests++, colored("Ok", FOREGROUND_GREEN | FOREGROUND_INTENSITY)); } \
  __if_not_exists(symbole) { std::cout<<(nNbFailedTests++, colored("Echec", FOREGROUND_RED | FOREGROUND_INTENSITY)); } \
  std::cout<<colored(" : V‚rification de l'impl‚mentation du symbole " #symbole, g_wDefaultColor)<<std::endl; 

/*!
 * \brief Macro de test
 * 
 * \param text
 * Texte d'explication du test. Est affich‚ en d‚but de ligne de test.
 * 
 * \param operation
 * Op‚ration … tester.
 * 
 * \param resultat
 * R‚sultat attendu de l'op‚ration.
 *
 * Teste que l'"operation" obtient bien le bon "resultat". En cas d'‚chec, incr‚mente la variable 
 * \c nNbFailedTests, en cas de succŠs, incr‚mente la variable \c nNbSucceededTests.
 *
 * \remark
 * Les variables \c nNbSucceededTests et \c nNbFailedTests sont d‚clar‚es et initialis‚es par la 
 * macro BEGIN_TESTS. La macro TEST ne peut ˆtre utilis‚e qu'entre les macros BEGIN_TESTS et 
 * END_TESTS.
 *
 * \see BEGIN_TESTS | END_TESTS
 */
#define TEST(text, operation, resultat) \
{\
  std::cout<<"Test ligne "<<__LINE__<<" : "; \
  std::cout<<(((operation) == resultat) ? (nNbSucceededTests++, colored("Ok", FOREGROUND_GREEN | FOREGROUND_INTENSITY)) : (nNbFailedTests++, colored("Echec", FOREGROUND_RED | FOREGROUND_INTENSITY))); \
  std::cout<<colored(" : ", g_wDefaultColor)<<text<<" : "<<"Teste que \"" #operation "\" soit ‚gal … \"" #resultat "\""<<std::endl; \
}

/*!
 * \brief Macro de test avec v‚rification de pr‚requis d'impl‚mentation
 * 
 * \param symbole1
 * Symbole dont l'impl‚mentation est requise.
 * 
 * \param text
 * Texte d'explication du test. Est affich‚ en d‚but de ligne de test.
 * 
 * \param operation
 * Op‚ration … tester.
 * 
 * \param resultat
 * R‚sultat attendu de l'op‚ration.
 *
 * Teste que le "symbole" est impl‚ment‚ puis applique le test demand‚ … l'aide de la macro TEST(text, operation, resultat)
 *
 * \see BEGIN_TESTS | END_TESTS | TEST(text, operation, resultat)
 */
#define TEST_VERIF_IMP_1(symbole1, text, operation, resultat) \
{\
  HELP_VERIF_IMP(symbole1) \
  __if_exists(symbole1){ TEST(text,operation,resultat) } \
  colored("", g_wDefaultColor); \
}

/*!
 * \brief Macro de test avec v‚rification de pr‚requis d'impl‚mentation
 * 
 * \param symbole1
 * Symbole dont l'impl‚mentation est requise.
 * \param symbole2
 * Symbole dont l'impl‚mentation est requise.
 * 
 * \param text
 * Texte d'explication du test. Est affich‚ en d‚but de ligne de test.
 * 
 * \param operation
 * Op‚ration … tester.
 * 
 * \param resultat
 * R‚sultat attendu de l'op‚ration.
 *
 * Teste que les symboles sont impl‚ment‚s puis applique le test demand‚ … l'aide de la macro TEST(text, operation, resultat)
 *
 * \see BEGIN_TESTS | END_TESTS | TEST(text, operation, resultat)
 */
#define TEST_VERIF_IMP_2(symbole1, symbole2, text, operation, resultat) \
{\
  HELP_VERIF_IMP(symbole1) \
  HELP_VERIF_IMP(symbole2) \
  __if_exists(symbole1){ \
    __if_exists(symbole2){ \
      TEST(text,operation,resultat) \
    } \
  } \
  colored("", g_wDefaultColor); \
}

/*!
 * \brief Macro de test avec v‚rification de pr‚requis d'impl‚mentation
 * 
 * \param symbole1
 * Symbole dont l'impl‚mentation est requise.
 * \param symbole2
 * Symbole dont l'impl‚mentation est requise.
 * \param symbole3
 * Symbole dont l'impl‚mentation est requise.
 * 
 * \param text
 * Texte d'explication du test. Est affich‚ en d‚but de ligne de test.
 * 
 * \param operation
 * Op‚ration … tester.
 * 
 * \param resultat
 * R‚sultat attendu de l'op‚ration.
 *
 * Teste que les symboles sont impl‚ment‚s puis applique le test demand‚ … l'aide de la macro TEST(text, operation, resultat)
 *
 * \see BEGIN_TESTS | END_TESTS | TEST(text, operation, resultat)
 */
#define TEST_VERIF_IMP_3(symbole1, symbole2, symbole3, text, operation, resultat) \
{\
  HELP_VERIF_IMP(symbole1) \
  HELP_VERIF_IMP(symbole2) \
  HELP_VERIF_IMP(symbole3) \
  __if_exists(symbole1){ \
    __if_exists(symbole2){ \
      __if_exists(symbole3){ \
        TEST(text,operation,resultat) \
      } \
    } \
  } \
  colored("", g_wDefaultColor); \
}

/*!
 * \brief Macro de construction d'objet avec v‚rification de pr‚requis d'impl‚mentation
 *
 * \param classname
 * Nom de la classe … instancier.
 *
 * \param objname
 * Nom de l'objet instanci‚.
 *
 * V‚rifie que la classe \c classname est impl‚ment‚e puis l'instancie par l'objet \c objname.
 *
 * \see BEGIN_TESTS | END_TESTS | TEST(text, operation, resultat)
 */
#define CONSTRUCT_VERIF_IMP(classname, objname) \
  HELP_VERIF_IMP(classname) \
  __if_exists(classname) { classname objname ; }

/*!
 * \brief Macro de destruction d'objet point‚ avec v‚rification de pr‚requis d'impl‚mentation
 *
 * \param ptrname
 * Nom du pointeur … supprimer.
 *
 * V‚rifie que la variable \c ptrname existe puis la d‚truit … l'aide de l'op‚rateur \c delete.
 *
 * \see BEGIN_TESTS | END_TESTS | TEST(text, operation, resultat)
 */
#define DELETE_VERIF_IMP(ptrname) \
  HELP_VERIF_IMP(ptrname) \
  __if_exists(ptrname) { delete ptrname ; }

/*!
 * \def BEGIN_TESTS
 * \brief D‚marrage des tests
 * 
 * Doit ˆtre utilis‚e avant de commencer les tests … l'aide de la macro \c TEST .
 *
 * \see TEST | END_TESTS
 */
#ifdef _DEBUG
#define BEGIN_TESTS \
  { \
    _CrtMemState mem1, mem2, memdiff; \
    _CrtMemCheckpoint(&mem1); \
    { \
      int nNbFailedTests = 0; \
      int nNbSucceededTests = 0; \
      try {
#else
#define BEGIN_TESTS \
  { \
    int nNbFailedTests = 0; \
    int nNbSucceededTests = 0; \
    try { 
#endif //def _DEBUG

/*!
 * \def END_TESTS
 * \brief Termine les tests
 * 
 * Doit ˆtre utilis‚e … la fin de la liste de tests. La macro affiche un r‚capitulatif sur le nombre de tests effectu‚s et le nombre de tests ‚chou‚s.
 *
 * \remark 
 * En mode DEBUG, cette macro v‚rifie qu'il n'y a pas eu de fuites m‚moire depuis l'utilisation de BEGIN_TESTS. 
 *
 * \see TEST | BEGIN_TESTS
 */
#ifdef _DEBUG
#define END_TESTS \
      } catch(...) { \
        nNbFailedTests++; \
        std::cout<<std::endl<<colored("Une exception non g‚r‚e a ‚t‚ rencontr‚e", FOREGROUND_RED | FOREGROUND_INTENSITY)<<std::endl; \
        colored("", g_wDefaultColor); \
      } \
      std::cout<<std::endl; \
      std::cout<<"Nombre de tests r‚alis‚s : "<<nNbSucceededTests+nNbFailedTests<<std::endl; \
      std::cout<<colored("Nombre de tests ‚chou‚s : ", (nNbFailedTests > 0 ? FOREGROUND_RED | FOREGROUND_INTENSITY : FOREGROUND_GREEN | FOREGROUND_INTENSITY))<<nNbFailedTests<<std::endl; \
    } \
    _CrtMemCheckpoint(&mem2); \
    if(_CrtMemDifference(&memdiff, &mem1, &mem2)) \
    { \
      _CrtMemDumpAllObjectsSince(&mem1); \
      std::cout<<colored("Des fuites m‚moires ont ‚t‚ d‚tect‚es, v‚rifiez vos allocations et d‚sallocations !", \
        FOREGROUND_RED | FOREGROUND_INTENSITY)<<std::endl; \
    } \
    else \
      std::cout<<colored("Aucune fuite m‚moire d‚tect‚e.", FOREGROUND_GREEN | FOREGROUND_INTENSITY)<<std::endl; \
    colored("", g_wDefaultColor); \
  }
#else
#define END_TESTS \
    } catch(...) { \
      nNbFailedTests++; \
      std::cout<<std::endl<<colored("Une exception non g‚r‚e a ‚t‚ rencontr‚e", FOREGROUND_RED | FOREGROUND_INTENSITY)<<std::endl; \
      colored("", g_wDefaultColor); \
    } \
    std::cout<<std::endl; \
    std::cout<<"Nombre de tests r‚alis‚s : "<<nNbSucceededTests+nNbFailedTests<<std::endl; \
    std::cout<<colored("Nombre de tests ‚chou‚s : ", (nNbFailedTests > 0 ? FOREGROUND_RED | FOREGROUND_INTENSITY : FOREGROUND_GREEN | FOREGROUND_INTENSITY))<<nNbFailedTests<<std::endl; \
  } \
  std::cout<<colored("D‚tection des fuites m‚moires impossible en mode Release.", FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY)<<std::endl; \
  colored("", g_wDefaultColor);
#endif //def _DEBUG

/*!
 * \brief
 * D‚finit la couleur du texte de la console.
 * 
 * \param text
 * Texte … colorer.
 * 
 * \param color
 * Couleur du texte.
 * 
 * \returns
 * Write description of return value here.
 * 
 * D‚finit la couleur du texte de la console … l'aide du paramŠtre \c color. 
 * Le paramŠtre \c text est directement retourn‚.
 * 
 * \remarks
 * Le paramŠtre \c text est ignor‚ par la fonction et est directement retourn‚.
 * 
 */
const char* colored(const char* text, WORD color);

/*!
 * \brief
 * R‚cupŠre la couleur du texte de la console.
 * 
 * \returns
 * La couleur du texte de la console.
 * 
 */
WORD GetDefaultColor();

/*!
 * \brief
 * La couleur par d‚faut du texte.
 */
extern const WORD g_wDefaultColor;

