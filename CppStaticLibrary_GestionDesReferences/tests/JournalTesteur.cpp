/**
 * \file   JournalTesteur.cpp
 * \brief fichier qui contient les test de la classe Journal
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 20 novembre 2021, 02:36
 */

#include <stdlib.h>
#include <iostream>
#include "Journal.h"
#include "ContratException.h"
#include <gtest/gtest.h>
#include <string>

using namespace biblio;

/*
 * Simple C++ Test Suite
 */


/** \brief test du constructeur de la classe Journal
 *      cas valide:
 *          Creation dune Reference de type Journal valide
 *
 *      cas invalide:
 *          creation d'une Reference de type Journal avec un nom de journal invalide (vide)
 *          creation d'une Reference de type Journal avec un volume invalide (negatif)
 *          creation d'une Reference de type Journal avec un numero invalide (negatif)
 *          creation d'une Reference de type Journal avec une page invalide (vide)
 *          creation d'une Reference de type Journal avec une page invalide (negatif)
 *          creation d'une Reference de type Journal avec un nom auteur invalide (vide)
 *          creation d'une Reference de type Journal avec un nom auteur invalide (chiffre)
 *          creation d'une Reference de type Journal avec un titre invalide (vide)
 *          creation d'une Reference de type Journal avec un annee invalide (vide)
 *          creation d'une Reference de type Journal avec un annee invalide (negative)
 *          creation d'une Reference de type Journal avec un numero d'identifiant de format invalide
 *          creation d'une Reference de type Journal avec un numero d'identifiant de format ISBN
 -*/


TEST (Journal, ConstructeurToutParametreValide)
{
  Journal testeur = Journal ("nom du journal", 3, 12, 54, "yannick munger", "le singe curieux", 2004, "ISSN 2202-1752");
  EXPECT_EQ ("nom du journal", testeur.reqNom ());
  EXPECT_EQ (3, testeur.reqVolume ());
  EXPECT_EQ (12, testeur.reqNumero ());
  EXPECT_EQ (54, testeur.reqPage ());
  EXPECT_EQ ("yannick munger", testeur.reqAuteur ());
  EXPECT_EQ ("le singe curieux", testeur.reqTitre ());
  EXPECT_EQ (2004, testeur.reqAnnee ());
  EXPECT_EQ ("ISSN 2202-1752", testeur.reqIdentifiant ());
}


/*constructeur nom de journal invalide (vide)*/
TEST (Journal, NomInvalideVide)
{
  ASSERT_THROW (Journal ("", 3, 12, 54, "yannick munger", "le singe curieux", 2004, "ISSN 2202-1752"), PreconditionException);
}


/*constructeur volume du Journal invalide (negatif)*/
TEST (Journal, VolumeInvalide)
{
  ASSERT_THROW (Journal ("nom du journal", -2 , 12, 54, "yannick munger", "le singe curieux", 2004, "ISSN 2202-1752"), PreconditionException);
}


/*constructeur numero du journal invalide (negatif)*/
TEST (Journal, NumeroInvalide)
{
  ASSERT_THROW (Journal ("nom du journal", 3, -12, 54, "yannick munger", "le singe curieux", 2004, "ISSN 2202-1752"), PreconditionException);
}


/*constructeur page du journal invalide (negatif)*/
TEST (Journal, PageInvalide)
{
  ASSERT_THROW (Journal ("nom du journal", 3, 12, -54, "yannick munger", "le singe curieux", 2004, "ISSN 2202-1752"), PreconditionException);
}


/*constructeur nom auteur invalide (vide)*/
TEST (Journal, AuteurInvalideVide)
{
  ASSERT_THROW (Journal ("nom du journal", 3, 12, 54, "", "le singe curieux", 2004, "ISSN 2202-1752"), PreconditionException);
}


/*constructeur nom auteur invalide (chiffre)*/
TEST (Journal, AuteurInvalideChiffre)
{
  ASSERT_THROW (Journal ("nom du journal", 3, 12, 54, "yann4ick", "le singe curieux", 2004, "ISSN 2202-1752"), PreconditionException);
}


/*constructeur titre invalide (vide)*/
TEST (Journal, TitreInvalideVide)
{
  ASSERT_THROW (Journal ("nom du journal", 3, 12, 54, "yannick munger", "", 2004, "ISSN 2202-1752"), PreconditionException);
}


/*constructeur annee invalide (vide)*/
TEST (Journal, AnneeInvalideVide)
{
  ASSERT_THROW (Journal ("nom du journal", 3, 12, 54, "yannick munger", "le singe curieux", NULL, "ISSN 2202-1752"), PreconditionException);
}


/*constructeur annee invalide (negatif)*/
TEST (Journal, AnneeInvalideNegatif)
{
  ASSERT_THROW (Journal ("nom du journal", 3, 12, 54, "yannick munger", "le singe curieux", -2004, "ISSN 2202-1752"), PreconditionException);
}


/*constructeur identifiant invalide (mauvais format)*/
TEST (Journal, IdentifiantFormatInvalide)
{
  ASSERT_THROW (Journal ("nom du journal", 3, 12, 54, "yannick munger", "le singe curieux", 2004, "ISSN2202-1752"), PreconditionException);
}


/*constructeur identifiant invalide (code ISBN)*/
TEST (Journal, IdentifiantIsbn)
{
  ASSERT_THROW (Journal ("nom du journal", 3, 12, 54, "yannick munger", "le singe curieux", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}

/** \class JournalTest
 * \brief classe qui permet de tester les methodes de lectures de la classe Journal sur un objet Journal creer*/
class JournalTest : public ::testing::Test
{

public:


  JournalTest () :
  f_journalTest ("nom du journal", 3, 12, 54, "yannick munger", "le singe curieux", 2004, "ISSN 2202-1752") { }
  ;

  Journal f_journalTest;
} ;


/** \brief test de la methode reqNom
 * cas valide: creation Journal valide connue et test de la lecture du Nom de journal
 * cas invalide: aucun trouve
 */
TEST_F (JournalTest, reqNom)
{
  ASSERT_EQ ("nom du journal", f_journalTest.reqNom ());
}


/** \brief test de la methode reqVolume
 * cas valide: creation Journal valide connue et test de la lecture du Volume de journal
 * cas invalide: aucun trouve
 */
TEST_F (JournalTest, reqVolume)
{
  ASSERT_EQ (3, f_journalTest.reqVolume ());
}


/** \brief test de la methode reqNumero
 * cas valide: creation Journal valide connue et test de la lecture du Numero de journal
 * cas invalide: aucun trouve
 */
TEST_F (JournalTest, reqNumero)
{
  ASSERT_EQ (12, f_journalTest.reqNumero ());
}


/** \brief test de la methode reqPage
 * cas valide: creation Journal valide connue et test de la lecture de la page du journal
 * cas invalide: aucun trouve
 */
TEST_F (JournalTest, reqPage)
{
  ASSERT_EQ (54, f_journalTest.reqPage ());
}


/** \brief test de la methode reqReferenceFormate
 * cas valide: creation Journal valide connue et test de la lecture de la Reference formate du journal
 * cas invalide: aucun trouve
 */
TEST_F (JournalTest, reqReferenceformate)
{
  ASSERT_EQ ("yannick munger. le singe curieux. nom du journal, vol. 3, no. 12, pp. 54, 2004. ISSN 2202-1752.", f_journalTest.reqReferenceFormate ());
}
