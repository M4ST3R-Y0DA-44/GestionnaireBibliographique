/**
 * \file  BibliographieTesteur.cpp
 * \brief fichier qui contient les Test de la classe Bibliographie
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 23 novembre 2021, 02:38
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "ContratException.h"
#include "Reference.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "Bibliographie.h"
#include "ReferenceException.h"

using namespace biblio;
/*
 * Simple C++ Test Suite
 */


/** \brief test du constructeur de la classe Bibliographie
 *      cas valide:
 *                  Tout parametre valide
 *
 *
 *      cas invalide:
 *                  parametre de nom invalide (vide)
 *
 -*/
TEST (Bibliographie, ConstructeurParametreValide)
{

  Bibliographie testeur = Bibliographie ("attributNomBiblio");
  EXPECT_EQ ("attributNomBiblio", testeur.reqNomDesBiblio ());
}


/*constructeur avec parametre vide*/
TEST (Bibliographie, ConstructeurParametreInvalideVide)
{
  ASSERT_THROW (Bibliographie (""), PreconditionException);
}

/** \class BibliographieTest
 * \brief classe qui permet de faire des test sur les methode de lecture de la classe Bibliographie
 */
class BibliographieTest : public ::testing::Test
{

public:


  BibliographieTest () :
  f_biblioTesteur ("bibliographie de test") { };

  Bibliographie f_biblioTesteur;
} ;


/**\brief test de la methode de lecture de l'attriobut m_nomDesBiblio*/
TEST_F (BibliographieTest, reqNomDesBiblio)
{
  EXPECT_EQ (f_biblioTesteur.reqNomDesBiblio (), "bibliographie de test");
}


/** \brief test de la methode ajouterReference
 * cas valide: parametre Ouvrage valide
 *             parametre Journal Valide
 *             Ajout d'une Reference avec le meme ISSN mais de valeur differente
 * cas invalide: parametre Ouvrage editeur invalide (vide)
 *               parametre Ouvrage editeur invalide (chiffre)
 *               parametre Ouvrage ville invalide (vide)
 *               parametre Ouvrage ville invalide (chiffre)
 *               parametre Ouvrage titre invalide (vide)
 *               parametre Ouvrage annee invalide (vide)
 *               parametre Ouvrage annee invalide (negative)
 *               parametre Ouvrage ISBN invalide
 *               parametre Journal titre invalide (vide)
 *               parametre Journal volume invalide (vide)
 *               parametre Journal volume invalide (negative)
 *               parametre Journal numero invalide (vide)
 *               parametre Journal numero invalide (negative)
 *               pramatere Journal page invalide (vide)
 *               parametre Journal page invalide (numero)
 *               parametre Journal auteur invalide (vide)
 *               parametre JournaL auteur invalide (negative)
 *               parametre Journal titre invalide (vide)
 *               parametre Journal annee invalide (vide)
 *               parametre Journal annee invalide (negative)
 *               parametre Journal ISSN invalide
 *               parametre reference valide mais deja presente dans la Bibliographie
 */


/*Ouvrage valide*/
TEST_F (BibliographieTest, ajouterReferenceParametreOuvrageValide)
{
  f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3"));
  EXPECT_EQ (f_biblioTesteur.reqBibliographieFormate (), "[1] yannick. titre. ville : editeur, 2004. ISBN 978-0-387-77591-3.\n");
}


/*Journal Valide*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalValide)
{
  f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, 4, 12, "yannick", "titre", 2004, "ISSN 2202-1752"));
  EXPECT_EQ (f_biblioTesteur.reqBibliographieFormate (), "[1] yannick. titre. le journal des medecins, vol. 3, no. 4, pp. 12, 2004. ISSN 2202-1752.\n");
}


/*Ajout d'une Reference avec le meme code ISSN que deja present mais information differente*/
TEST_F (BibliographieTest, ajouterReferenceCodeIdentifqueInformationDifferente)
{
  f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3"));
  f_biblioTesteur.ajouterReference (Ouvrage ("la maison edition", "laval", "aurelie", "les ours en vie", 2004, "ISBN 978-0-387-77591-3"));
  EXPECT_EQ (f_biblioTesteur.reqBibliographieFormate (), "[1] yannick. titre. ville : editeur, 2004. ISBN 978-0-387-77591-3.\n[2] aurelie. les ours en vie. laval : la maison edition, 2004. ISBN 978-0-387-77591-3.\n");
}


/*Ouvrage invalide (editeur vide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreOuvrageInvalideEditeurVide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Ouvrage ("", "ville", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3")), PreconditionException);
}


/*Ouvrage invalide (editeur avec chiffre)*/
TEST_F (BibliographieTest, ajouterReferenceParametreOuvrageInvalideEditeurChiffre)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Ouvrage ("edi4teur", "ville", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3")), PreconditionException);
}


/*Ouvrage invalide (ville vide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreOuvrageInvalideVilleVide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3")), PreconditionException);
}


/*Ouvrage invalide (ville avec chiffre))*/
TEST_F (BibliographieTest, ajouterReferenceParametreOuvrageInvalideVilleChiffre)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "vi4le", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3")), PreconditionException);
}


/*Ouvrage invalide (auteur vide))*/
TEST_F (BibliographieTest, ajouterReferenceParametreOuvrageInvalideauteurVide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "", "titre", 2004, "ISBN 978-0-387-77591-3")), PreconditionException);
}


/*Ouvrage invalide (annee vide))*/
TEST_F (BibliographieTest, ajouterReferenceParametreOuvrageInvalideAnneeVide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", NULL, "ISBN 978-0-387-77591-3")), PreconditionException);
}


/*Ouvrage invalide (annee negative))*/
TEST_F (BibliographieTest, ajouterReferenceParametreOuvrageInvalideAnneeNegative)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", -2004, "ISBN 978-0-387-77591-3")), PreconditionException);
}


/*Ouvrage invalide (ISBN non valide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreOuvrageInvalideIsbn)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", 2004, "ISBN 97-387-77591-3")), PreconditionException);
}


/*Journal invalide (titre vide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideTitrevide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("", 3, 4, 12 , "yannick", "titre", 2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide volume (vide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideVolumeVide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", NULL, 4, 12, "yannick", "titre", 2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide volume (negatif)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideVolumeNegatif)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", -3, 4, 12, "yannick", "titre", 2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide numero (vide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideNumeroVide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, NULL, 12, "yannick", "titre", 2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide numero (negatif)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideNumeroNegatif)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, -4, 12, "yannick", "titre", 2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide page (vide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalidePageVide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, 4, NULL, "yannick", "titre", 2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide page (negatif)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalidePageNegatif)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, 4, -12, "yannick", "titre", 2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide auteur (vide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideAuteurVide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, 4, 12, "", "titre", 2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide auteur (chiffre)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideAuteurchiffre)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, 4, 12, "yan45nick", "titre", 2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide titre (vide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideTitreVide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, 4, 12, "yannick", "", 2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide annee (vide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideAnneeVide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, 4, 12, "yannick", "titre", NULL, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide annee (negatif)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideAnneeNegatif)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, 4, 12, "yannick", "titre", -2004, "ISSN 2202-1752")), PreconditionException);
}


/*Journal invalide ISSN (invalide)*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalInvalideIssnInvalide)
{
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Journal ("le journal des medecins", 3, 4, 12, "yannick", "titre", 2004, "ISSN 22021752")), PreconditionException);
}


/*Ajout d'une Reference valide mais deja presente dans la bibliographie*/
TEST_F (BibliographieTest, ajouterReferenceParametreJournalDouble)
{
  f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3"));
  ASSERT_THROW (f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3")), ReferenceDejaPresenteException);
}


/**\brief test de la methode supprimerReference
 * cas valide: ISBN/ISSN present dans la bibliographie et valide.
 * cas invalide: code ISSN/ISBN de format invalide
 *               code non present dans la bibliographie
 */
TEST_F (BibliographieTest, supprimerReferenceParametreValide)
{
  f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3"));
  f_biblioTesteur.supprimerReference ("ISBN 978-0-387-77591-3");
  EXPECT_EQ (f_biblioTesteur.reqBibliographieFormate (), "");
}


TEST_F (BibliographieTest, supprimerReferenceParametreInvalideFormat)
{
  f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3"));
  ASSERT_THROW (f_biblioTesteur.supprimerReference ("ISSN 2202"), PreconditionException);
}


TEST_F (BibliographieTest, supprimerReferenceParametreInvalideNonPresent)
{
  f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3"));
  ASSERT_THROW (f_biblioTesteur.supprimerReference ("ISSN 2202-1752"), ReferenceAbsenteException);
}


/** \brief test de la methode reqBibliographieFormate*/
TEST_F (BibliographieTest, reqbibliographieFormate)
{
  f_biblioTesteur.ajouterReference (Ouvrage ("editeur", "ville", "yannick", "titre", 2004, "ISBN 978-0-387-77591-3"));
  f_biblioTesteur.ajouterReference (Journal ("le journal", 3, 4, 12, "yannick", "titre", 2004, "ISSN 2202-1752"));

  EXPECT_EQ (f_biblioTesteur.reqBibliographieFormate (), "[1] yannick. titre. ville : editeur, 2004. ISBN 978-0-387-77591-3.\n[2] yannick. titre. le journal, vol. 3, no. 4, pp. 12, 2004. ISSN 2202-1752.\n");
}


/**\brief test de la methode clone*/
TEST_F (BibliographieTest, clone)
{
  f_biblioTesteur.ajouterReference (Journal ("le journal", 3, 4, 12, "yannick", "titre", 2004, "ISSN 2202-1752"));
  Bibliographie* clone = f_biblioTesteur.clone ();
  EXPECT_EQ (clone->reqNomDesBiblio (), "bibliographie de test");
  EXPECT_EQ (clone->reqBibliographieFormate (), "[1] yannick. titre. le journal, vol. 3, no. 4, pp. 12, 2004. ISSN 2202-1752.\n");
}


/**\brief test de la methode operator=*/
TEST_F (BibliographieTest, operateurEgalite)
{
  f_biblioTesteur.ajouterReference (Journal ("le journal", 3, 4, 12, "yannick", "titre", 2004, "ISSN 2202-1752"));
  Bibliographie* BiblioEgale = &f_biblioTesteur;
  EXPECT_EQ (BiblioEgale->reqNomDesBiblio (), "bibliographie de test");
  EXPECT_EQ (BiblioEgale->reqBibliographieFormate (), "[1] yannick. titre. le journal, vol. 3, no. 4, pp. 12, 2004. ISSN 2202-1752.\n");

}

