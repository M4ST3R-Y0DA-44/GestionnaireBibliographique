/**
 * \file   OuvrageTesteur.cpp
 * \brief fichier qui contient tout les test de la classe Ouvrage
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 20 novembre 2021, 02:35
 */

#include <stdlib.h>
#include <iostream>
#include "Ouvrage.h"
#include "ContratException.h"
#include <gtest/gtest.h>
#include <string>


using namespace biblio;
/*
 * Simple C++ Test Suite
 */


/** \brief test du constructeur de la classe Ouvrage
 *      cas valide:
 *          Creation dune Reference de type Ouvrage valide
 *
 *      cas invalide:
 *          creation d'une reference avec un nom d'editeur invalide (vide)
 *          creation d'une reference avec un nom d'editeur invalide (chiffre)
 *          creation d'une reference avec un nom de ville invalide (vide)
 *          creation d'une reference avec un nom de ville invaslide (chiffre)
 *          creation d'une reference avec un nom auteur invalide (vide)
 *          creation d'une reference avec un nom auteur invalide (chiffre)
 *          creation d'une reference avec un annee invalide (vide)
 *          creation d'une reference avec un annee invalide (negative)
 *          creation d'une reference avec un titre invalide (vide)
 *          creation d'une reference avec un numero d'identifiant de format invalide
 *          creation d'une reference avec un numero d'identifiant de type ISSN
 -*/

TEST (Ouvrage, ConstructeurToutParametreValide)
{
  Ouvrage testeur = Ouvrage ("nom de l'editeur", "montreal", "yannick munger", "le singe curieux", 2004, "ISBN 978-0-387-77591-3");
  EXPECT_EQ ("nom de l'editeur", testeur.reqEditeur ());
  EXPECT_EQ ("montreal", testeur.reqVille ());
  EXPECT_EQ ("yannick munger", testeur.reqAuteur ());
  EXPECT_EQ ("le singe curieux", testeur.reqTitre ());
  EXPECT_EQ (2004, testeur.reqAnnee ());
  EXPECT_EQ ("ISBN 978-0-387-77591-3", testeur.reqIdentifiant ());
}


/*constructeur editeur invalide (vide)*/
TEST (Ouvrage, EditeurInvalideVide)
{
  ASSERT_THROW (Ouvrage ("", "montreal", "yannick munger", "le singe curieux", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/*constructeur editeur invalide (chiffre)*/
TEST (Ouvrage, EditeurInavlideChiffre)
{
  ASSERT_THROW (Ouvrage ("ch123", "montreal", "yannick munger", "le singe curieux", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/*constructeur ville invalide vide*/
TEST (Ouvrage, VilleInvalideVide)
{
  ASSERT_THROW (Ouvrage ("nom de l'editeur", "", "yannick munger", "le singe curieux", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/*constructeur ville invalide vide (chiffre)*/
TEST (Ouvrage, VilleInvalideChiffre)
{
  ASSERT_THROW (Ouvrage ("nom de l'editeur", "montr4eal", "yannick munger", "le singe curieux", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/*constructeur auteur invalide (vide)*/
TEST (Ouvrage, AuteurInvalideVide)
{
  ASSERT_THROW (Ouvrage ("nom de l'editeur", "montreal", "", "le singe curieux", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/*constructeur auteur invalide (chiffre)*/
TEST (Ouvrage, AuteurInvalideChiffre)
{
  ASSERT_THROW (Ouvrage ("nom de l'editeur", "montreal", "yann4ick m3unger", "le singe curieux", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/*constructeur titre invalide (vide)*/
TEST (Ouvrage, TitreInvalideVide)
{
  ASSERT_THROW (Ouvrage ("nom de l'editeur", "montreal", "yannick munger", "", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/*constructeur annee vide*/
TEST (Ouvrage, anneeInvalideVide)
{
  ASSERT_THROW (Ouvrage ("nom de l'editeur", "montreal", "yannick munger", "le singe curieux", NULL, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/*constructeur annee invalide*/
TEST (Ouvrage, anneeInvalideNegative)
{
  ASSERT_THROW (Ouvrage ("nom de l'editeur", "montreal", "yannick munger", "le singe curieux", -20, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/*constructeur ISBN format invalide*/
TEST (Ouvrage, IdentifiantFormatInvalide)
{
  ASSERT_THROW (Ouvrage ("nom de l'editeur", "montreal", "yannick munger", "le singe curieux", 2004, "ISBN 97591-3"), PreconditionException);
}


/*constructeur ISBN invalide car de type ISSN*/
TEST (Ouvrage, IdentifiantTypeIssn)
{
  ASSERT_THROW (Ouvrage ("nom de l'editeur", "montreal", "yannick munger", "le singe curieux", 2004, "ISSN 2202-1752"), PreconditionException);
}

/** \class OuvrageTest
 * \brief classe qui permet de tester les methodes de lectures de la classe Ouvrage sur un objet Ouvrage creer*/
class OuvrageTest : public ::testing::Test
{

public:


  OuvrageTest () :
  f_ouvrageTest ("nom de l'editeur", "montreal", "yannick munger", "le singe curieux", 2004, "ISBN 978-0-387-77591-3") { }
  ;

  Ouvrage f_ouvrageTest;
} ;


/** \brief test de la methode reqEditeur
 * cas valide: creation Ouvrage valide connue et test de la lecture de l'auteur
 * cas invalide: aucun trouve
 */
TEST_F (OuvrageTest, reqEditeur)
{
  ASSERT_EQ ("nom de l'editeur", f_ouvrageTest.reqEditeur ());
}


/** \brief test de la methode reqVille
 * cas valide: creation Ouvrage valide connue et test de la lecture de la ville
 * cas invalide: aucun trouve
 */
TEST_F (OuvrageTest, reqVille)
{
  ASSERT_EQ ("montreal", f_ouvrageTest.reqVille ());
}


/** \brief test de la methode reqReferenceFormate
 * cas valide: creation d'un objet Ouvrage valide connue et test de la lecture de sa Reference sous une format formater
 * cas invalide: aucun trouve
 */
TEST_F (OuvrageTest, reqReferenceFormate)
{
  ASSERT_EQ ("yannick munger. le singe curieux. montreal : nom de l'editeur, 2004. ISBN 978-0-387-77591-3.", f_ouvrageTest.reqReferenceFormate ());
}