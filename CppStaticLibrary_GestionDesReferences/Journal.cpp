/**
 * \file   Journal.cpp
 * \brief Ce document contient la definitions du constructeur ainsi que de toutes les methodes de la classe Journal.
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 19 Novembre 2021, 21:30
 */


#include "Journal.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace biblio;


/*constructeur de la classe Journal*/
Journal::Journal (const string& p_nom, const int p_volume, const int p_numero, const int p_page, const string& p_auteur, const string& p_titre, const int p_annee, const string& p_identifiant) : Reference (p_auteur, p_titre, p_annee, p_identifiant), m_nom (p_nom), m_volume (p_volume), m_numero (p_numero), m_page (p_page)
{

  PRECONDITION (p_nom.size () > 0);
  PRECONDITION (p_volume > 0);
  PRECONDITION (p_numero > 0);
  PRECONDITION (p_page > 0);
  PRECONDITION (util::validerFormatNom (p_auteur));
  PRECONDITION (p_titre.size () > 0);
  PRECONDITION (p_annee > 0);
  PRECONDITION (util::validerCodeIssn (p_identifiant));

  POSTCONDITION (reqNom () == p_nom);
  POSTCONDITION (reqVolume () == p_volume);
  POSTCONDITION (reqNumero () == p_numero);
  POSTCONDITION (reqPage () == p_page);
  POSTCONDITION (reqAuteur () == p_auteur);
  POSTCONDITION (reqTitre () == p_titre);
  POSTCONDITION (reqAnnee () == p_annee);
  POSTCONDITION (reqIdentifiant () == p_identifiant);

  INVARIANTS ();
}


/*methode de lecture de l'attribut m_nom*/
const string
Journal::reqNom () const
{
  return m_nom;
}


/*methode de lecture de l'attribut m_volume*/
const int
Journal::reqVolume () const
{
  return m_volume;
}


/*methode de lecture de l'attribut m_numero*/
const int
Journal::reqNumero ()const
{
  return m_numero;
}


/*methode de lecture de l'attribut m_page*/
const int
Journal::reqPage ()const
{
  return m_page;
}


/*methode qui retourne un string formate de la reference*/
const string
Journal::reqReferenceFormate ()const
{
  ostringstream ostream;
  ostream << reqAuteur () << ". "
          << reqTitre () << ". "
          << reqNom () << ", vol. "
          << reqVolume () << ", no. "
          << reqNumero () << ", pp. "
          << reqPage () << ", "
          << reqAnnee () << ". "
          << reqIdentifiant () << ".";
  return ostream.str ();
}


/*methode de clonage de la reference*/
Reference*
Journal::clone () const
{
  return new Journal (*this);
}


/*methode de verification de invariant*/
void
Journal::verifieInvariant () const
{
  INVARIANT (reqNom ().size () > 0);
  INVARIANT (reqVolume () > 0);
  INVARIANT (reqNumero () > 0);
  INVARIANT (reqPage () > 0);
  INVARIANT (util::validerFormatNom (reqAuteur ()));
  INVARIANT (reqTitre ().size () > 0);
  INVARIANT (reqAnnee () > 0);
  INVARIANT (util::validerCodeIssn (reqIdentifiant ()));
}

