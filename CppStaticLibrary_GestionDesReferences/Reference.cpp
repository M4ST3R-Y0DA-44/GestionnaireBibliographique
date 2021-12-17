/**
 * \file   Reference.cpp
 * \brief Ce document contient la definitions du constructeur ainsi que de toutes les methodes de la classe Reference.
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 18 octobre 2021, 14:30
 */
#include <cstdlib>

#include <iostream>
#include <sstream>
#include <string>
#include "Reference.h"
#include "ContratException.h"
#include "validationFormat.h"

using namespace std;
using namespace biblio;


/*constructeur de la classe Reference*/
Reference::Reference (const string& p_auteurs, const string& p_titre, const int p_annee, const string& p_identifiant) : m_auteurs (p_auteurs), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant)
{
  PRECONDITION (util::validerFormatNom (p_auteurs));
  PRECONDITION (p_titre.size () > 0);
  PRECONDITION (p_annee > 0);
  PRECONDITION (util::validerCodeIsbn (p_identifiant) || util::validerCodeIssn (p_identifiant));

  POSTCONDITION (reqAuteur () == p_auteurs);
  POSTCONDITION (reqTitre () == p_titre);
  POSTCONDITION (reqAnnee () == p_annee);
  POSTCONDITION (reqIdentifiant () == p_identifiant);

  INVARIANTS ();
}


/*Methode de lecture de l'attribut m_auteurs*/
const string
Reference::reqAuteur () const
{
  return m_auteurs;
}


/*methode de lecture de l'attribut m_titre*/
const string
Reference::reqTitre () const
{
  return m_titre;
}


/*methode de lecture de l'attribut m_annee*/
const int
Reference::reqAnnee () const
{
  return m_annee;
}


/*methode de lecture de l'identifiant ISSN ou ISBN de la Reference*/
const string
Reference::reqIdentifiant () const
{


  return m_identifiant;
}


/*Methode qui permet la modification de l'attribut annee de publication de la Reference par une annee desirer inserer en argument*/
const void
Reference::asgAnnee (const int &p_annee)
{


  PRECONDITION (p_annee > 0);
  m_annee = p_annee;
  POSTCONDITION (reqAnnee () > 0);
}


/*Methode qui permet d'obtenir toute les attributs de la Reference sous un format deja formater*/
const string
Reference::reqReferenceFormate () const
{


  ostringstream ostream;
  ostream << reqAuteur () << ". "
          << reqTitre () << ".";
  return ostream.str ();
}


/*Methode qui permet la comparaison attribut par attribut entre la Reference sur laquelle on applique la methode et la Reference passer en argument*/
const bool
Reference::estEgal (const Reference& p_reference) const
{


  return m_auteurs == p_reference.m_auteurs &&
          m_titre == p_reference.m_titre &&
          m_annee == p_reference.m_annee &&
          m_identifiant == p_reference.m_identifiant;
}


/*Methode qui verfifie les invariant de la classe Reference*/

void
Reference::verifieInvariant () const
{
  INVARIANT (util::validerFormatNom (reqAuteur ()));
  INVARIANT (reqTitre ().size () > 0);
  INVARIANT (reqAnnee () > 0);
  INVARIANT (util::validerCodeIsbn (reqIdentifiant ()) || util::validerCodeIssn (reqIdentifiant ()));
}





