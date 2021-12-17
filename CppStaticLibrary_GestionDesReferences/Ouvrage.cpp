/**
 * \file   Ouvrage.cpp
 * \brief Ce document contient la definitions du constructeur ainsi que de toutes les methodes de la classe Ouvrage.
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 19 Novembre 2021, 14:30
 */


#include "Ouvrage.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <string>
#include <iostream>
#include <sstream>



using namespace std;
using namespace biblio;


/*constructeur de la classe Ouvrage*/
Ouvrage::Ouvrage (const string& p_editeur, const string& p_ville, const string& p_auteur, const string& p_titre, const int p_annee, const string& p_identifiant) : Reference (p_auteur, p_titre, p_annee, p_identifiant), m_editeur (p_editeur), m_ville (p_ville)
{
  PRECONDITION (util::validerFormatNom (p_editeur));
  PRECONDITION (util::validerFormatNom (p_ville));
  PRECONDITION (util::validerFormatNom (p_auteur));
  PRECONDITION (p_titre.size () > 0);
  PRECONDITION (p_annee > 0);
  PRECONDITION (util::validerCodeIsbn (p_identifiant));

  POSTCONDITION (reqEditeur () == p_editeur);
  POSTCONDITION (reqVille () == p_ville);
  POSTCONDITION (reqAuteur () == p_auteur);
  POSTCONDITION (reqTitre () == p_titre);
  POSTCONDITION (reqAnnee () == p_annee);
  POSTCONDITION (reqIdentifiant () == p_identifiant);

  INVARIANTS ();
}


/*methode de lecture de l'attribut m_editeur*/
const string
Ouvrage::reqEditeur ()const
{
  return m_editeur;
}


/*methode de lecture de l'attribut m_ville*/
const string
Ouvrage::reqVille ()const
{
  return m_ville;
}


/*methode de recuperation d'un string formater de la reference*/
const string
Ouvrage::reqReferenceFormate () const
{
  ostringstream ostream;
  ostream << reqAuteur () << ". "
          << reqTitre () << ". "
          << reqVille () << " : "
          << reqEditeur () << ", "
          << reqAnnee () << ". "
          << reqIdentifiant () << ".";
  return ostream.str ();

}


/*methode de clonage de la reference*/
Reference*
Ouvrage::clone () const
{
  return new Ouvrage (*this);
}


/*methode de verification des invariants de la classe Ouvrage*/
void
Ouvrage::verifieInvariant () const
{
  INVARIANT (util::validerFormatNom (reqEditeur ()));
  INVARIANT (util::validerFormatNom (reqVille ()));
  INVARIANT (util::validerFormatNom (reqAuteur ()));
  INVARIANT (reqTitre ().size () > 0);
  INVARIANT (reqAnnee () > 0);
  INVARIANT (util::validerCodeIsbn (reqIdentifiant ()));
}

