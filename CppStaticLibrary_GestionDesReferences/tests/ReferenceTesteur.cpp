/*
 * \file   ReferenceTesteur.cpp
 * \author M4ST3R-Y0DA-44
 * \brief Test sur la classe Reference
 *
 * \date Created on 18 novembre 2021, 18:18
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "Reference.h"
#include "ContratException.h"
#include <sstream>

using namespace biblio;

/*
 * Simple C++ Test Suite
 */

/** \class ReferenceTesteur
 * \brief classe qui permet de tester la classe abstraite Reference
 */

class ReferenceTesteur : public Reference
{

public:


  /** \fn ReferenceTesteur (const std::string& p_auteur, const std::string& p_nom, const int p_annee, const std::string& p_identifiant) : Reference (p_auteur, p_nom, p_annee, p_identifiant)
   * \brief Constructeur qui permet de construire un objet de la classe abstraite Reference*/
  ReferenceTesteur (const std::string& p_auteur, const std::string& p_nom, const int p_annee, const std::string& p_identifiant) : Reference (p_auteur, p_nom, p_annee, p_identifiant) { };


  /** \fn const std::string reqReferenceFormate () const*
   * \brief fonction qui permet d'utiliser la fonction reqReferenceFormate de la classe abstraite Reference*/
  const std::string
  reqReferenceFormate () const
  {
    return Reference::reqReferenceFormate ();
  };


  /** \fn const void asgAnnee (const int p_annee)
   * \brief fonction qui permet de tester la fonction asgAnnee de la classe abstraite Reference*/
  const void
  asgAnnee (const int p_annee)
  {
    return Reference::asgAnnee (p_annee);
  };


  Reference*
  clone () const { };
} ;


/** \brief test du constructeur de la classe Reference
 *      cas valide:
 *          Creation du Reference valide
 *
 *      cas invalide:
 *          creation d'une reference avec un nom auteur invalide (vide)
 *          creation d'une reference avec un nom auteur invalide contenant un chiffre
 *          creation d'une reference avec un annee invalide (vide)
 *          creation d'une reference avec un annee invalide negative
 *          creation d'une reference avec un titre invalide (vide)
 *          creation d'une reference avec un numero d'identifiant invalide
 -*/

TEST (Reference, toutParametreValide)
{

  ReferenceTesteur objReferenceTest = ReferenceTesteur ("yannick", "le curieux singe", 2004, "ISBN 978-0-387-77591-3");
  EXPECT_EQ ("yannick", objReferenceTest.reqAuteur ());
  EXPECT_EQ ("le curieux singe", objReferenceTest.reqTitre ());
  EXPECT_EQ (2004, objReferenceTest.reqAnnee ());
  EXPECT_EQ ("ISBN 978-0-387-77591-3", objReferenceTest.reqIdentifiant ());

}


/*nom auteur invalide (vide)*/
TEST (Reference, nomAuteurInvalideVide)
{
  ASSERT_THROW (ReferenceTesteur ("", "le curieux singe", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/* nom auteur invalide (chiffre)*/
TEST (Reference, nomAuteurInvalideChiffre)
{
  ASSERT_THROW (ReferenceTesteur ("Charl2y", "Le curieux singe", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/* annee invalide (vide)*/
TEST (Reference, anneeInvalideVide)
{
  ASSERT_THROW (ReferenceTesteur ("yannick", "le curieux singe", NULL, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/* annee invalide (negative)*/
TEST (Reference, anneeInvalideNegative)
{
  ASSERT_THROW (ReferenceTesteur ("yannick", "le curieux singe", -20, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/* titre invalide (vide)*/
TEST (Reference, nomTitreInvalide)
{
  ASSERT_THROW (ReferenceTesteur ("yannick", "", 2004, "ISBN 978-0-387-77591-3"), PreconditionException);
}


/*numero didentifiant invalide*/
TEST (Reference, numIdentifiantInvalide)
{
  ASSERT_THROW (ReferenceTesteur ("yannick", "le curieux singe", 2004, "ISBN 9785555555555"), PreconditionException);
}

/** \class ReferenceTest
 * \brief classe qui permet de tester les methodes de lectures et d'assignation de la classe Reference sur un objet reference creer*/
class ReferenceTest : public ::testing::Test
{

public:


  ReferenceTest () :
  f_referenceTest ("yannick", "le curieux singe", 2004, "ISBN 978-0-387-77591-3") { }
  ;


  ReferenceTesteur f_referenceTest;
} ;


/** \brief test de la methode reqAuteur
 * cas valide: creation Reference valide connue et test de la lecture de l'auteur
 * cas invalide: aucun trouve
 */
TEST_F (ReferenceTest, reqAuteur)
{


  ASSERT_EQ ("yannick", f_referenceTest.reqAuteur ());
}


/** \brief test de la methode reqTitre
 * cas valide: creation Reference valide connue et test de la lecture du titre
 * cas invalide: aucun trouve
 */
TEST_F (ReferenceTest, reqTitre)
{


  ASSERT_EQ ("le curieux singe", f_referenceTest.reqTitre ());
}


/** \brief test de la methode reqAnnee
 * cas valide: creation Reference valide connue et test de la lecture de l'annee
 * cas invalide: aucun trouve
 */
TEST_F (ReferenceTest, reqAnnee)
{


  ASSERT_EQ (2004, f_referenceTest.reqAnnee ());
}


/** \brief test de la methode reqIdentifiant
 * cas valide: creation Reference valide connue et test de la lecture de l'identifiant
 * cas invalide: aucun trouve*/
TEST_F (ReferenceTest, reqIdentifiant)
{


  ASSERT_EQ ("ISBN 978-0-387-77591-3", f_referenceTest.reqIdentifiant ());
}


/** \brief test de la methode asgAnneeValide
 * cas valide: creation Reference valide connue dans le but de modifier l'annee, puis tester la lecture de l'annee
 * cas invalide: remplacement par une annee non valide (vide)
 *               remplacement par une annee non valide (negative)
 */
TEST_F (ReferenceTest, asgAnneeValide)
{

  f_referenceTest.asgAnnee (2011);
  ASSERT_EQ (2011, f_referenceTest.reqAnnee ());
}


/*annee invalide (vide)*/
TEST_F (ReferenceTest, asgAnneeInvalideVide)
{
  ASSERT_THROW (f_referenceTest.asgAnnee (NULL), PreconditionException);
}


/*annee invalide (negative)*/
TEST_F (ReferenceTest, asgAnneeInvalideNegative)
{
  ASSERT_THROW (f_referenceTest.asgAnnee (-2004), PreconditionException);
}


/** \brief test de la methode reqReferenceFormate
 * cas valide: creation Reference valide connue et test de la lecture de la Reference en version formate
 * cas invalide: aucun trouve
 */
TEST_F (ReferenceTest, reqReferenceFormateValide)
{

  ASSERT_EQ ("yannick. le curieux singe.", f_referenceTest.reqReferenceFormate ());
}

/** \class DeuxReferenceTest
 * \brief classe qui permet de tester la methode de comparaison entre deux Reference
 */
class DeuxReferenceTest : public ::testing::Test
{

public:


  DeuxReferenceTest () :
  f_reference1 ("yannick", "le curieux singe", 2004, "ISBN 978-0-387-77591-3"), f_reference2 ("Jean-Simon", "Peche 2020", 2020, "ISBN 978-0-387-77591-3") { }
  ;


  ReferenceTesteur f_reference1;
  ReferenceTesteur f_reference2;
} ;


/** \brief test de la methode estEgal
 * cas valide: comparaison de deux reference identique qui retourne vrai
 *             comparaison de deux reference diff/rente qui retourne faux
 * cas invalide: aucun
 */
TEST_F (DeuxReferenceTest, estEgalValideTrue)
{


  ASSERT_EQ (true, f_reference1.estEgal (f_reference1));
}


/*deux reference differente est egal = false*/
TEST_F (DeuxReferenceTest, estEgaleValideFalse)
{
  ASSERT_EQ (false, f_reference1.estEgal (f_reference2));
}
