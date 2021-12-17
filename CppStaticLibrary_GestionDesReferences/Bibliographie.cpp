/**
 * \file   Bibliographie.cpp
 * \brief Ce document contient la definitions du constructeur ainsi que de toutes les methodes de la classe Bibliographie.
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 19 Novembre 2021, 21:30
 */
#include "Bibliographie.h"
#include "ContratException.h"
#include "Reference.h"
#include "ReferenceException.h"
#include "validationFormat.h"
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;
using namespace biblio;


/*constructeur de la classe Bibliographie*/
Bibliographie::Bibliographie (const string& p_nomDesBiblio) : m_nomDesBiblio (p_nomDesBiblio)
{
  PRECONDITION (p_nomDesBiblio.size () > 0);

  POSTCONDITION (m_nomDesBiblio == p_nomDesBiblio);

  INVARIANTS ();
};


/*methode de lecture de l'attribut m_nomDesBiblio*/
const string
Bibliographie::reqNomDesBiblio () const
{
  return m_nomDesBiblio;
};


/*methode qui permet d'ajouter un pointeur de Reference a l'attribut m_vReferences*/
void
Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
{

  if (Bibliographie::referenceEstDejaPresente (p_nouvelleReference) == false)
    {
      m_vReferences.push_back (p_nouvelleReference.clone ());
    }
  else
    {
      throw ReferenceDejaPresenteException ("Cette reference est deja enregistrer dans la Bibliographie.");
    }
  POSTCONDITION (Bibliographie::referenceEstDejaPresente (p_nouvelleReference) == true);
};


/*Methode de supression d'une Reference*/
void
Bibliographie::supprimerReference (const string & p_identifiant)
{
  PRECONDITION (util::validerCodeIssn (p_identifiant) || util::validerCodeIsbn (p_identifiant));
  bool refPresente = false;
  ;
  for (iter = m_vReferences.begin (); iter < m_vReferences.end (); iter++)
    {
      if ((*iter)->reqIdentifiant () == p_identifiant)
        {
          m_vReferences.erase (iter);
          refPresente = true;
        }
    }
  if (!refPresente)
    {
      throw ReferenceAbsenteException ("Le code identifiant suivant ne fait pas partie de la Bibliographie");
    }
}


/*methode qui retourne la lecture de la liste des Reference de la bibliographie*/
const string
Bibliographie::reqBibliographieFormate ()
{
  ostringstream ostream;
  for (iter = m_vReferences.begin (); iter < m_vReferences.end (); iter++)
    {
      ostream << "[" << std::distance (m_vReferences.begin (), iter) + 1 << "] " << (*iter)->reqReferenceFormate () << "\n";
    }
  return ostream.str ();
};


/*methode qui verifie si le numero identifiant (ISBN ou ISSN) est deja present dans le bibligraphie*/
bool
Bibliographie::referenceEstDejaPresente (const Reference & p_reference)
{
  bool refPresente = false;
  for (iter = m_vReferences.begin (); iter < m_vReferences.end (); iter++)
    {
      if (p_reference.estEgal (*(*iter)))
        {
          refPresente = true;
        }
    }
  return refPresente;
};


/*Destructeur de la classe Bibliographie*/
Bibliographie::~Bibliographie ()
{
  for (iter = m_vReferences.begin (); iter < m_vReferences.end (); iter++)
    {
      delete (*iter);
    }
};


/*methode qui clone la bilbiographie*/
Bibliographie *
Bibliographie::clone ()
{
  Bibliographie * clone = new Bibliographie (m_nomDesBiblio);
  for (iter = m_vReferences.begin (); iter < m_vReferences.end (); iter++)
    {
      clone->ajouterReference ((*(*iter)));
    }
  return clone;
};


/*methode de l'operateur d'assignation*/
const Bibliographie* Bibliographie::operator= (Bibliographie & p_biblio)
{
  this->~Bibliographie ();
  INVARIANTS ();
  return p_biblio.clone ();
};


/*methode qui verifie les invariants de la classe Bibliographie*/
void
Bibliographie::verifieInvariant () const
{
  INVARIANT (m_nomDesBiblio.size () > 0);
};
